#include "qml-port.h"

#if defined(Q_OS_LINUX)
#include <sys/statfs.h>
#endif
#include <QFileInfo>
#include <QDebug>
#include "setting-help.h"
#include <QDateTime>
#include <QDir>
#include <QTextCodec>
#include <QScriptEngine>
#if defined(Q_OS_WIN)
#include "Windows.h"
#include <time.h>
#elif defined(Q_OS_LINUX)
#include <QProcess>
#include <sys/time.h>
#include <unistd.h>
#include "stdlib.h"
#include <errno.h>
#include <QJsonArray>
#endif

#define MIN_DATE QDate( 1000, 1, 1 )
#define MAX_DATE QDate( 2036, 12, 2 )
#define MIN_DATE_TIME QDateTime( MIN_DATE, QTime( 0, 0, 0 ) )
#define MAX_DATE_TIME QDateTime( MAX_DATE, QTime( 0, 0, 0 ) )

#define MAX_DATE_TIME_EXT QDateTime( QDate( 2036, 12, 31 ), QTime( 23, 59, 59 ) )


QmlPort::QmlPort(QObject *parent) : QObject(parent)
{
    m_strSDPath = QString("/run/media/mmcblk2p1");
#if defined(Q_OS_LINUX)
    mn_video_start_time = 0;
#endif
    m_keyValue_up = KEY_UP;
    m_keyValue_down = KEY_DOWN;
    m_keyValue_left = KEY_LEFT;
    m_keyValue_right = KEY_RIGHT;
    m_keyValue_center = KEY_OK;
    m_keyValue_return = KEY_RETURN;

    init_mode_save_status();

    mp_general_mode = NULL;
    mp_select_taskpack = NULL;
    mb_general_mode = true;
    mp_device_list = NULL;
    QString s_value = SettingHelp::get_key_value( "Task deploy mode" );
    if ( s_value == tr("Deploy by device") ) {//按设备部署
        mn_task_mode = 0;
    } else if ( s_value == tr("Substation deploy by interval") ) {//按设备区展开
        mn_task_mode = 1;
    } else if ( s_value == tr("Line deploy by pole") ) {//按级别分层展开
        mn_task_mode = 2;
    } else if ( s_value == tr("General task package") ) {//通用任务包
        mn_task_mode = 3;
    } else {
        mn_task_mode = 0;
    }
    create_device_tree();
}

QmlPort::~QmlPort()
{
}

void QmlPort::Init_TaskBoxEX()
{
    emit signal_TaskBoxEx_visible();
}

int QmlPort::get_denoice_value( int n_value )
{
    float f_slider = 1.0*n_value*255/359;
    return f_slider;
}

int QmlPort::get_transparent_value( int n_value )
{
    float f_slider = 1.0*n_value*100/402;
    return f_slider;
}

int QmlPort::get_uv_gain( int n_value )
{
    float f_value =  1.0*n_value*100/4095;
    qDebug()<<"qmlport get_uv_gain: "<<f_value;
    return (int)f_value;
}
//获取SD卡有效空间的级别
int QmlPort::has_sd_available_space()
{
    QString s_full_path = m_strSDPath;
    int n_ret, n_avai_space;

    if( s_full_path.isEmpty() ) {
        return 1;
    }
    n_ret = get_storage_info( s_full_path.toLocal8Bit().constData(), &n_avai_space, 3 );
    if( n_ret == 0 && n_avai_space > 5120 ) {
        return 2;
    }
    return 3;
}
//判断是否存在着SD卡
bool QmlPort::is_inserted_sd()
{
#if defined(Q_OS_WIN32)
    QString s_fn = m_strSDPath;
#elif defined(Q_OS_LINUX)
    QString s_fn = m_strSDPath;
#endif
    QFile file( s_fn );
    if( file.exists() ) {
        return true;
    }
    return false;
    //return true;
}

int QmlPort::is_sd_iswritable( )
{

    return 1;
}
//这里对于保存SD有效容量的值被写死成了10000？？？ 这里我选择注释掉强制赋值
int QmlPort::get_storage_info( const char * psz_mount_point, int *np_capacity, int type )
{
#if defined(Q_OS_LINUX)
    typedef long long U64;
    struct statfs statFS; //系统stat的结构体
    U64 usedBytes = 0;
    U64 freeBytes = 0;
    U64 totalBytes = 0;
    U64 endSpace = 0;

    if (statfs(psz_mount_point, &statFS) == -1){   //获取分区的状态
        printf("statfs failed for path->[%s]\n", psz_mount_point);
        return -1;
    }

    totalBytes = (U64)statFS.f_blocks * (U64)statFS.f_frsize; //详细的分区总容量， 以字节为单位
    freeBytes = (U64)statFS.f_bfree * (U64)statFS.f_frsize; //详细的剩余空间容量，以字节为单位
    usedBytes = (U64)(totalBytes - freeBytes); //详细的使用空间容量，以字节为单位

    switch( type )
    {
    case 1:
        endSpace = totalBytes/1024; //以KB为单位的总容量
        break;

    case 2:
        endSpace = usedBytes/1024; //以KB为单位的使用空间
        break;

    case 3:
        endSpace = freeBytes/1024; //以KB为单位的剩余空间
        break;

    default:
        return ( -1 );
    }
    *np_capacity = endSpace; //这个不用说了吧
#endif
    //*np_capacity = 10000;
    return 0;
}
//获取自1970-01-01T00:00:00通用协调时间以来的毫秒数
void QmlPort::get_video_start_time( )
{
#if defined(Q_OS_LINUX)
    mn_video_start_time = QDateTime::currentMSecsSinceEpoch();
#endif
}
//将传递进来的n_video_time转换成（00:00:00或者00:00）格式的时间表示 这里我注销了n_end_time语句
QString QmlPort::get_video_time( int n_video_time )
{
#if defined(Q_OS_LINUX)
//    u_int64_t n_end_time = QDateTime::currentMSecsSinceEpoch();
//    u_int64_t n_interval = n_end_time-mn_video_start_time;
    u_int64_t n_interval = n_video_time;
    u_int64_t n_hour = ( n_interval/1000/3600 );
    u_int64_t n_minute = ( n_interval/1000/60 )%60;
    u_int64_t n_second = ( n_interval/1000 )%60;
    QString s_interval_date_time;
    //设置视频时间的字符串 （1h以上 00:00:00 1s以上 00:00 ）
    if( n_hour != 0 ) {//时间大于1h 按照时:分:秒的格式显示（保证格式为00:00:00）
        s_interval_date_time = QString( "%1:%2:%3" ).arg( n_hour ).arg( n_minute ).arg( n_second );
        if( n_minute<10 ) {
            if( n_second<10 ) {
                s_interval_date_time = QString( "%1:0%2:0%3" ).arg( n_hour ).arg( n_minute ).arg( n_second );
            } else {
                s_interval_date_time = QString( "%1:0%2:%3" ).arg( n_hour ).arg( n_minute ).arg( n_second );
            }
        } else{
            if( n_second<10 ) {
                s_interval_date_time = QString( "%1:%2:0%3" ).arg( n_hour ).arg( n_minute ).arg( n_second );
            } else {
                s_interval_date_time = QString( "%1:%2:%3" ).arg( n_hour ).arg( n_minute ).arg( n_second );
            }
        }
    } else if( n_minute != 0 ) {//时间大于1min 小于1h
        if( n_minute<10 ) {
            if( n_second<10 ) {
                s_interval_date_time = QString( "0%1:0%2" ).arg( n_minute ).arg( n_second );
            } else {
                s_interval_date_time = QString( "0%1:%2" ).arg( n_minute ).arg( n_second );
            }
        } else{
            if( n_second<10 ) {
                s_interval_date_time = QString( "%1:0%2" ).arg( n_minute ).arg( n_second );
            } else {
                s_interval_date_time = QString( "%1:%2" ).arg( n_minute ).arg( n_second );
            }
        }
    } else {
        if( n_second<10 ) {
            s_interval_date_time = QString( "00:0%1" ).arg( n_second );
        } else {
            s_interval_date_time = QString( "00:%1" ).arg( n_second );
        }
    }
    return s_interval_date_time;
#else
    return "";
#endif
}


QString QmlPort::get_video_file_name()
{
    QString s_image_name = QString("1%1.avi").arg( QDateTime::currentDateTimeUtc().toString("yyyyMMddhhmmss") );
    QString s_sd_dir = m_strSDPath;
    QString s_dest_data_dir = QString("%1/%2").arg(s_sd_dir).arg("data");
    QString s_dest_images_dir = QString("%1/%2").arg(s_sd_dir).arg("data/videos");
    QDir dir;
    QString s_image_time_dir = QString("%1/%2/%3").arg(s_sd_dir).arg("data/videos").arg(QDateTime::currentDateTimeUtc().toString("yyyyMMdd"));
    QString s_dest_img_path = QString("%1/%2").arg(s_image_time_dir).arg(s_image_name);
    //判断SD卡下是否有data文件夹 如果不存在则创建data文件夹
    if( !dir.exists( s_dest_data_dir ) ) {
        if( !dir.mkdir( s_dest_data_dir ) ) {
            qDebug()<<"mkdir data error!";
        }
    }
    //判断SD卡下的data文件夹下是否有videos文件夹 如果不存在则创建videos文件夹
    if( !dir.exists( s_dest_images_dir ) ) {
        if( !dir.mkdir( s_dest_images_dir )  ) {
            qDebug()<<"mkdir images error!";
        }
    }
    //同理判断s_image_time_dir文件夹
    if( !dir.exists( s_image_time_dir ) ) {
        if( !dir.mkdir( s_image_time_dir )  ) {
            qDebug()<<"mkdir images error!";
        }
    }
    //同理判断s_dest_img_path文件
    if( QFile::exists( s_dest_img_path ) ) {
        if( !QFile::remove( s_dest_img_path ) ) {
            qDebug()<<" image file cannot be removed";
        } else {
            qDebug()<<s_dest_img_path<<"removed ok";
        }
    }
    return s_dest_img_path;
}
//设置键值对（融合，value）（紫外，value）容器 value为list（false，false，false）
void QmlPort::init_mode_save_status()
{
    QList<bool> list;
    list<<false<<false<<false;
    modeL_map.insert( "融合", list );
    modeL_map.insert( "紫外", list );
}
//键值对容器插入键值对 value(b_machine_info,b_alarm_status,b_laser_status) 对于插入的键为融合则再重新赋值紫外的值 反之如果为紫外则重新赋值融合的值
void QmlPort::set_mode_save_status( QString s_btn_name, bool b_machine_info, bool b_alarm_status, bool b_laser_status )
{
    QList<bool> list;
    list<<b_machine_info<<b_alarm_status<<b_laser_status;
    modeL_map.insert(s_btn_name, list );
    if( s_btn_name=="融合" ) {
        QList<bool> list_unit = modeL_map.value("紫外");
        list_unit.replace(2, b_laser_status);
        modeL_map["紫外"] = list_unit;
    } else if( s_btn_name=="紫外" ) {
        QList<bool> list_unit = modeL_map.value("融合");
        list_unit.replace(2, b_laser_status);
        modeL_map["融合"] = list_unit;
    }
}
//获取某个键n_index处的值（bool）
bool QmlPort::get_mode_save_status( QString s_btn_name, int n_index )
{
    QList<bool> list = modeL_map.value(s_btn_name);
    if( n_index>=0 && n_index<list.count( ) ) {
        return list.at(n_index);
    }
    return false;
}
//获取模式保存的状态（是否开启了警报 激光等）个数
int QmlPort::get_mode_save_status_count( QString s_btn_name )
{
    QList<bool> list = modeL_map.value(s_btn_name);
    return list.count();
}
//select_task-----------------------
void QmlPort::init_select_taskpack_dlg()
{
    if( mp_select_taskpack == NULL ) {
        qDebug() << "QmlPort::init_select_taskpack_dlg";
        mp_select_taskpack = new SelectTaskDlg( mb_general_mode, mn_task_mode, this );
        connect( mp_select_taskpack, SIGNAL(regist_is_activate() ), this, SIGNAL(regist_is_activate() ) );
    }
}
//select_task-----------------------
void QmlPort::reinit_select_taskpack_dlg()
{
    if( mp_select_taskpack ) {
        delete mp_select_taskpack;
        mp_select_taskpack = NULL;
    }
    init_select_taskpack_dlg();
}
//select_task-----------------------
int QmlPort::get_btns()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_btns();
}
//select_task-----------------------
int QmlPort::get_task_number()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_number();
}
//select_task-----------------------
bool QmlPort::get_task_selected( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_selected( n_seq );
}
//select_task-----------------------
QString QmlPort::get_task_text( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_tasklist_text( n_seq );
}
//select_task-----------------------
int QmlPort::compont_firm_code( int n_seq, QString str )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->compont_firm_code( n_seq, str );
}
//select_task-------------set_task()
void QmlPort::task_clicked( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->set_task( n_seq );
}
//select_task-----------------------
int QmlPort::get_task_type_number()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_type_number();
}
//select_task-------------selected_task_type()
bool QmlPort::get_task_type_selected(int n_seq)
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->selected_task_type( n_seq );
}
//select_task-----------------------
QString QmlPort::get_task_type_text(int n_seq)
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_type_text( n_seq );
}
//select_task-------------set_task_type()
void QmlPort::task_type_clicked(int n_seq)
{
    init_select_taskpack_dlg();
    mp_select_taskpack->set_task_type( n_seq );
}
//select_task-----------------------
void QmlPort::select_all_task_type_clicked()
{
    init_select_taskpack_dlg();
    mp_select_taskpack->select_all_task_type_clicked();
}
//select_task-----------------------
void QmlPort::select_no_task_type_clicked()
{
    init_select_taskpack_dlg();
    mp_select_taskpack->select_no_task_type_clicked();
}
//select_task-----------------------
bool QmlPort::is_task_type_select_all()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->is_task_type_select_all();
}
//select_task-----------------------
bool QmlPort::is_task_type_selectded()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->is_task_type_selectded();
}
//select_task-------------get_task_zone_number()
int QmlPort::get_task_area_number()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_zone_number();
}
//select_task-------------has_task_zone_by_seq()
bool QmlPort::get_task_area_selected( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->has_task_zone_by_seq( n_seq );
}
//select_task-------------get_task_zone_text()
QString QmlPort::get_task_area_text( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->get_task_zone_text( n_seq );
}
//select_task-------------select_one_task_zone()
void QmlPort::task_area_clicked( int n_seq )
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->select_one_task_zone( n_seq );
}
//select_task-------------select_all_task_zone_clicked()
void QmlPort::select_all_task_area_clicked()
{
    init_select_taskpack_dlg();
    mp_select_taskpack->select_all_task_zone_clicked();
}
//select_task-------------select_no_task_zone_clicked()
void QmlPort::select_no_task_area_clicked()
{
    init_select_taskpack_dlg();
    mp_select_taskpack->select_no_task_zone_clicked();
}
//select_task-------------is_select_all_task_zone()
bool QmlPort::is_task_area_select_all()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->is_select_all_task_zone();
}
//select_task-------------is_has_task_zone_click()
bool QmlPort::is_task_area_selectded()
{
    init_select_taskpack_dlg();
    return mp_select_taskpack->is_has_task_zone_click();
}
//select_task-----------------------
void QmlPort::set_taskpack_cell_selected(int n_index)
{
    qDebug() << "QmlPort::set_taskpack_cell_selected" << n_index;
    init_select_taskpack_dlg();
    return mp_select_taskpack->set_taskpack_cell_selected( n_index );
}
//select_task-----------------------
void QmlPort::set_taskpack_cell_byname(QString s_name)
{
    qDebug() << "[QmlPort][set_taskpack_cell_byname] : " << s_name << "\r\n";
    init_select_taskpack_dlg();
    return mp_select_taskpack->set_taskpack_cell_byname( s_name );
}

bool QmlPort::delete_task_pack(int n_index)
{
    init_select_taskpack_dlg();
    //返回的是要删除的压缩包名称
    QString s_pack_name = mp_select_taskpack->delete_task_pack( n_index );//删除压缩包 解压包 更新保存压缩包信息的列表
    if( !s_pack_name.isEmpty() ) {//删除的压缩包存在
        delete_task_pack_slot( s_pack_name );
        //清空维护该删除的安装包的信息
        s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
        if( p_status->s_pack_name == s_pack_name ) {
            p_status->n_expand_way = 0;
            p_status->n_shooted_pos_list.clear();
            p_status->n_shoot_pos = 0;
            p_status->s_pack_name = "";
            p_status->s_sel_device_type_list.clear();
            p_status->s_sel_device_zone_list.clear();
            SettingHelp::set_task_pack_status( p_status );
        }
        return true;
    }
    return false;
}
//
int QmlPort::get_restore_shoot_status_flag()
{
    qDebug()<<"QmlPort::get_restore_shoot_status_flag()-----------------------------------------------------1";
    s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
    qDebug()<<"QmlPort::get_restore_shoot_status_flag()-----------------------------------------------------2";
    if( p_status->n_shooted_pos_list.isEmpty() ) { //已拍摄的设备树位置信息是否存在   空返回true
        qDebug()<<"QmlPort::get_restore_shoot_status_flag()-----------------------------------------------------3";
        mn_restore_last_task_status_flag = 0;
    } else {
        qDebug()<<"QmlPort::get_restore_shoot_status_flag()-----------------------------------------------------4";
        mn_restore_last_task_status_flag = 1;
    }
    qDebug()<<"QmlPort::get_restore_shoot_status_flag()-----------------------------------------------------5";
    return mn_restore_last_task_status_flag;
}

bool QmlPort::restore_last_shoot_status( bool b_restore_last_shoot_pos )   //恢复上次拍摄状态
{
    s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
    if( p_status->s_pack_name.isEmpty() ) {
        return false;
    }
    init_select_taskpack_dlg();
    return mp_select_taskpack->restore_last_shoot_status( b_restore_last_shoot_pos, p_status );
}

void QmlPort::delete_task_pack_slot(QString s_pack_fn)
{
    if( !mb_general_mode && ms_taskpack_name == s_pack_fn ) {
        set_task_mode( true );
        clear_dev_list();
#ifdef D_SERIAL
        emit clear_user_list();
#endif
    }
}

void QmlPort::set_task_mode(bool b_general)
{
    mb_general_mode = b_general;
    if( b_general ) {
        emit change_to_general_model();
    }
    emit task_mode_changed();
}

void QmlPort::set_taskpack_db_name( QString s_db_name )
{
    ms_taskpack_db_name = s_db_name;
    if( ms_taskpack_db_name.isEmpty() ) {
        q_version = "1";
    } else {
        QString s_pkg_path = ms_taskpack_db_name;
        QString s_setting_path  = s_pkg_path.mid( 0, s_pkg_path.lastIndexOf('/') ) + "/setting.conf";
        qDebug()<<"QmlPort::set_taskpack_db_name -----------------------"<<s_setting_path;
        QFile file( s_setting_path );
        file.open( QIODevice::ReadWrite );
        QByteArray bytes = file.readAll();//Json字符串，QByteArray与QString可转化
        file.close();
        QTextCodec *codec = NULL;
        if( bytes.indexOf("UTF-8", Qt::CaseSensitive )  != 0 ) {
            codec = QTextCodec::codecForName("UTF-8");
        } else {
            codec = QTextCodec::codecForName("gbk");
        }
        QString out_array = codec->toUnicode( bytes.data() );
        qDebug()<<"QmlPort::set_taskpack_db_name------------------------------out_array   "<<out_array;
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + out_array);
        q_version = sc.property("version").toString();

        SettingHelp::set_province_name( sc.property("firm_ident_code").toString() );
    }
}
//创建任务包列表类 关联信号和信号槽
void QmlPort::create_device_tree()
{
    //清空设备列表
    if( mp_device_list ) {
        delete mp_device_list;
        mp_device_list = NULL;
    }
    mp_device_list = new DeviceList( this );

    //connect( mp_device_list, SIGNAL( common_task_selected(QString, QString) ), this, SIGNAL( common_task_selected(QString, QString) ) );
    //connect( mp_device_list, SIGNAL( common_task_selected(QStringList) ), this, SIGNAL( common_task_selected_list(QStringList) ) );
    connect( mp_device_list, SIGNAL( outline_ana_selected( QStringList, QStringList ) ), this, SIGNAL( outline_ana_selected( QStringList, QStringList ) ) );
    connect( mp_device_list, SIGNAL( device_selected(QString) ), this, SLOT( handle_video_title_changed(QString) ) );
    connect( mp_device_list, SIGNAL( device_save_change()), this, SIGNAL( device_save_change() ) );
    connect( mp_device_list, SIGNAL( device_shoot_ok( int, int ) ), this, SIGNAL( device_shoot_ok( int, int ) ) );
    connect( mp_device_list, SIGNAL( device_save_over_sgl()), this, SIGNAL( device_save_over_sgl() ) );
    connect( mp_device_list, SIGNAL( fold_list_for_path() ), this, SIGNAL( fold_list_for_path() ) );
    connect( mp_device_list, SIGNAL( device_tree_ready() ), this, SIGNAL( device_tree_ready() ) );
    connect( mp_device_list, SIGNAL( level_tree_init() ), this, SIGNAL( level_tree_init() ) );
}

void QmlPort::clear_dev_list()
{
    mp_device_list->clear_select_list();
    set_taskpack_db_name("");
#ifdef D_SERIAL
    load_outline_image( "" );
#endif
    emit clear_tree_list();
    b_has_task_pack = false;
}

/***********************************************************
 * @ description          : 设备树展开方式设置
 * @ param - n_expand_way : 展开方式
 * @ return               : null
 ***********************************************************/
void QmlPort::set_device_tree_expand_way( int n_expand_way )
{
    mn_expand_way = n_expand_way;

    s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
    if( p_status->n_expand_way != n_expand_way ) {  //不相等重新保存
        p_status->n_expand_way = n_expand_way;
        SettingHelp::set_task_pack_status( p_status );
    }
}

QString QmlPort::get_task_version()
{
    if( !mb_general_mode ) {
        return q_version;
    }
    return "1";
}

void QmlPort::set_device_zone_list(QStringList s_dev_zone_list)
{
    qDebug()<<"QmlPort::set_device_zone_list ------------- ";
    ms_dev_zone_list.clear();
    ms_dev_zone_list = s_dev_zone_list;
    b_has_task_pack = true;
    create_device_tree();
    if( mp_device_list ) {
        mp_device_list->set_device_zone_list( s_dev_zone_list );
    }
}

void QmlPort::set_device_type_list(QStringList s_dev_type_list, bool b_restore_last_shoot_task, bool b_restore_last_shoot_pos )
{
    qDebug() << "QmlPort::set_device_type_list";
    ms_dev_type_list.clear();
    ms_dev_type_list = s_dev_type_list;

    if( mp_device_list ) {
        s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
        if( b_restore_last_shoot_task ) {
            mn_expand_way = p_status->n_expand_way;
        } else {
            p_status->s_pack_name = ms_taskpack_name;
            p_status->s_sel_device_type_list.clear();
            p_status->s_sel_device_type_list = s_dev_type_list;
            p_status->s_sel_device_zone_list.clear();
            p_status->s_sel_device_zone_list = ms_dev_zone_list;
            p_status->n_shooted_pos_list.clear();
            p_status->n_shoot_pos = 0;
            SettingHelp::set_task_pack_status( p_status );
        }
        mp_device_list->set_device_type_list( s_dev_type_list, true, b_restore_last_shoot_task, b_restore_last_shoot_pos );
        //emit show_device_tree( true );
    }
}

QString QmlPort::get_mac_serial()
{
    return "";
}

void QmlPort::emit_start_parse_task_pack()
{
    emit start_parse_task_pack_sig();
}
//-----------------------------------------------------------------
#ifdef D_SERIAL
void QmlPort::load_outline_image( QString image_path )
{
    if( outline_str.compare( image_path ) == 0 ) {
        return ;
    } else {
        outline_str = image_path;
    }
    QImage image( image_path );
    QPixmap temp_map( image_path );
    temp_map.setMask( QPixmap::fromImage( image ).createMaskFromColor( QColor( 0, 0, 0) ) );
    img_provider->outline_image = temp_map.toImage();

    QPixmap temp_map_outline( image_path );
    temp_map_outline.setMask( QPixmap::fromImage( image ).createMaskFromColor( QColor( 255, 255, 255), Qt::MaskOutColor ) );

    img_provider->bkoutline_image = temp_map_outline.toImage();
    emit call_qml_refesh_image( image_path );
}
#endif

void QmlPort::regist_success_slot()
{
    qDebug()<<"QmlPort::regist_success_slot ----------------------- \r\n\r\n";
    if( mp_select_taskpack ) {
        qDebug() << "QmlPort::regist_success_slot";
        mp_select_taskpack->ok_btn_continue_slot();
    }
    //emit signal_reset_dlg();

    emit task_loaded();
}

void QmlPort::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void QmlPort::regist_fail_slot()
{
    if( mp_select_taskpack ) {
        mp_select_taskpack->cancel_btn_pressed_slot();
    }
}
//mp_device_list-----------------------
int QmlPort::get_task_child_level( int index )
{
    if( mp_device_list ) {
        return mp_device_list->get_task_child_level( index );
    }
    return 0;
}
//mp_device_list-----------------------
int QmlPort::get_task_child_leve_data_id( int index )
{
    if( mp_device_list ) {
        return mp_device_list->get_task_child_leve_data_id( index );
    }
    return 0;
}
//mp_device_list-----------------------
QString QmlPort::get_up_level_name( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_up_level_name( number );
    }
    return "";
}
//mp_device_list-----------------------
int QmlPort::get_up_level_index( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_up_level_index( number );
    }
    return 0;
}
//mp_device_list-----------------------
QString QmlPort::get_up_level_unflod( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_up_level_unflod( number );
    }
    return "";
}
//mp_device_list-----------------------
QString QmlPort::get_down_level_name( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_down_level_name( number );
    }
    return "";
}
//mp_device_list-----------------------
QString QmlPort::get_cur_level_name( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_cur_level_name( number );
    }
    return "";
}
//mp_device_list-----------------------
int QmlPort::get_down_level_index( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_down_level_index( number );
    }
    return 0;
}
//mp_device_list-----------------------
int QmlPort::get_cur_level_index( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_cur_level_index( number );
    }
    return 0;
}
//mp_device_list-----------------------
QString QmlPort::get_down_level_unflod( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_down_level_unflod( number );
    }
    return "";
}
//mp_device_list-----------------------
int QmlPort::get_back_level_index( int number )
{
    if( mp_device_list ) {
        return mp_device_list->get_back_level_index( number );
    }
    return -1;
}
//mp_device_list-----------------------
QString QmlPort::get_back_level_unflod( int number )
{

    if( mp_device_list ) {
        return mp_device_list->get_back_level_unflod( number );
    }
    return "";
}
//mp_device_list-----------------------
bool QmlPort::get_task_select_info(int n_index)
{
    return mp_device_list->get_task_select_info( n_index );
}
//mp_device_list-----------------------
bool QmlPort::get_task_select_info( int index, int n_index )
{
    return mp_device_list->get_task_select_info( index, n_index );
}
//mp_device_list-----------------------
bool QmlPort::tree_had_shoot()
{
    return mp_device_list->tree_had_shoot();
}
//mp_device_list-----------------------
int QmlPort::tree_node_clicked( int n_indx )
{
    return mp_device_list->tree_node_clicked( n_indx );
}
//mp_device_list-----------------------
QString QmlPort::get_task_tree_list_str( int i )
{
    return mp_device_list->get_task_tree_list_str( i );
}
//mp_device_list-----------------------
int QmlPort::get_task_tree_list_node_number( int i )
{
    return mp_device_list->get_task_tree_list_node_number( i );
}
//mp_device_list-----------------------
int QmlPort::get_task_tree_list_count()
{
    return mp_device_list->get_task_tree_list_count();
}
//mp_device_list-----------------------
QString QmlPort::get_task_tree_list_path( int i  )
{
    return mp_device_list->get_task_tree_list_path( i );
}
//mp_device_list-----------------------
int QmlPort::get_task_tree_list_node_level( int i )
{
    return mp_device_list->get_task_tree_list_node_level( i );
}
//mp_device_list-----------------------
bool QmlPort::get_task_tree_list_node_shoot( int i )
{
    return mp_device_list->get_task_tree_list_node_shoot( i );
}
//mp_device_list-------------get_select_pos()
int QmlPort::get_task_select_pos()
{
    return mp_device_list->get_select_pos();
}
//mp_device_list-----------------------
QString QmlPort::get_task_pos_path( int pos )
{
    return mp_device_list->get_task_pos_path( pos );
}
//mp_device_list-----------------------
bool QmlPort::get_task_pos_is_saved( int pos )
{
    return mp_device_list->get_task_pos_is_saved( pos );
}
//mp_device_list-----------------------
bool QmlPort::get_task_tree_node_visible(int n_index)
{
    return mp_device_list->get_task_tree_node_visible( n_index );
}
//mp_device_list-----------------------
bool QmlPort::get_task_tree_node_child_visible(int n_index)
{
    return mp_device_list->get_task_tree_node_child_visible( n_index );
}
//mp_device_list-----------------------
bool QmlPort::get_child_has_shoot( int n_index )
{
    return mp_device_list->get_child_has_shoot( n_index );
}
//mp_device_list-----------------------
bool QmlPort::get_child_visible_change()
{
    return mp_device_list->get_child_visible_change();
}
//mp_device_list-----------------------
QString QmlPort::get_child_visible_change_path()
{
    return mp_device_list->get_child_visible_change_path();
}
//mp_device_list-----------------------
bool QmlPort::is_same_voltage_level( QString path, int currect_level_number )
{
    return mp_device_list->is_same_voltage_level( path, currect_level_number );
}
//mp_device_list-----------------------
bool QmlPort::has_path_father( QString path, int curr )
{
    return mp_device_list->has_path_father( path, curr );
}
//mp_device_list-----------------------
int QmlPort::get_click_child_num()
{
    return mp_device_list->get_click_child_num();
}

void QmlPort::handle_video_title_changed(QString s_title )
{
    int n_size = s_title.size();
    if ( n_size <= 24  ) {
        emit video_title_changed( s_title );
    } else {
        QString short_title = s_title.mid( n_size-26 ); //s_title.replace( 0, n_size - 26, "" );
        int n_index = short_title.indexOf( QRegExp("[-]") ) ;
        if( n_index != -1 ) {
            short_title = short_title.mid( n_index+1 );
        }
        emit  video_title_changed( short_title );
    }
}

bool QmlPort::get_task_tree_show( int i )
{
    int temp = 5;
    if( mn_expand_way == DEVICE_TREE_EXPAND_BY_AREA ) {
        temp = 3;
    } else if( mn_expand_way == DEVICE_TREE_EXPAND_BY_DEVICENAME ) {
        temp = 5;
    }

    if( mp_device_list->get_task_tree_list_node_level( i ) == temp )
        return false;
    if( mp_device_list->get_task_tree_list_node_level( i ) == DEVICE_TREE_EXPAND_BY_DEVICENAME )
        return false;
    return true;
}

void QmlPort::change_to_general_model_slot()
{
    init_select_taskpack_dlg();
    set_task_mode( true );
    clear_dev_list();
#ifdef D_SERIAL
    emit clear_user_list();
#endif
}

void QmlPort::tree_turn_next()
{
//    wait_save_thread();
    if( !mb_general_mode ) {
        mp_device_list->set_shooted();
        mp_device_list->next_device_task();
    }
}

QString QmlPort::get_captured_file_name( bool unname )
{
    QString s_drive = m_strSDPath;
    QString s_fn = mp_device_list->get_ir_image_file_name( mb_general_mode || unname  );
    qDebug()<<"get_captured_file_name   s_fn-----------------------------------------"<<s_fn;
    QString s_full_name = s_drive + "/data/image/";
    if( mb_general_mode ) {
        QDateTime tm = QDateTime::currentDateTime();
        if( tm >= MAX_DATE_TIME_EXT ) {
            tm = MAX_DATE_TIME_EXT;
            tm = tm.addSecs( -1 );
        } else if( tm <= MIN_DATE_TIME ) {
            tm = MIN_DATE_TIME;
            tm = tm.addSecs( 1 );
        }

        time_t curtime = (time_t)tm.toTime_t();
        struct tm *cur_tm = localtime( &curtime );
        char buf[32];
        //qDebug()<<"get_captured_file_name--------1111111111111111111111111--------------"<<curtime;
#if defined(Q_OS_WIN32)
        ::sprintf_s( buf, 32, "%d%02d%02d", cur_tm->tm_year + 1900,  cur_tm->tm_mon+1, cur_tm->tm_mday );
#elif defined(Q_OS_LINUX)
        snprintf(buf, 32, "%d%02d%02d", cur_tm->tm_year + 1900,  cur_tm->tm_mon+1, cur_tm->tm_mday );
#endif
        s_full_name += QString::fromUtf8(buf);
        //qDebug()<<"get_captured_file_name--------2222222222222222222222--------------"<<buf;
    } else {
        s_full_name += mp_device_list->all_replace_covert_char( ms_taskpack_name );
        //qDebug()<<"get_captured_file_name--------333333333333333333333333--------------"<<ms_taskpack_name;
        //qDebug()<<"get_captured_file_name--------444444444444444444444444--------------"<<mp_device_list->all_replace_covert_char( ms_taskpack_name );;
    }
    s_full_name += "/" + s_fn;

    return s_full_name;
}

void QmlPort::ir_get_image_name( bool unname )
{
    QString s_fn = get_captured_file_name( unname );
    qDebug()<<"ir_get_image_name    s_fn-----------------------------------------"<<s_fn;
    QString ms_img_fn;
    ms_task_image_fold.clear();
    ms_task_image_name.clear();
    if( !s_fn.isEmpty() /*&& !img.isNull()*/ ) {
        ms_img_fn = s_fn;

        int n_index = ms_img_fn.lastIndexOf( '/' );
        QString s_full_name = ms_img_fn.mid( 0, n_index + 1 );
        QDir dir( s_full_name );
        QStringList file_list = dir.entryList( );
        QString ir_relative_name = ms_img_fn.mid( n_index + 1, ms_img_fn.count() );
        QStringList s_path_split = s_full_name.split("/");
        QString s_task_fold = s_path_split.takeLast();
        while( s_task_fold.isEmpty() ) {
            s_task_fold = s_path_split.takeLast();
        }
        ms_task_image_fold = s_task_fold;
        qDebug() << "QmlPort::ir_get_image_name    4444444444444444444      " << ir_relative_name;
        int i;
        if( file_list.filter( ir_relative_name ).count() != 0 ){
            QStringList test_list = file_list.filter( ir_relative_name );
            i = 1;
            ir_relative_name = ms_img_fn.mid( n_index + 1, ms_img_fn.count() );
            qDebug() << "QmlPort::ir_get_image_name    33333333333333333      " << ir_relative_name;
            ir_relative_name.append( QString( "_" ) + QString( "%1" ).arg( i )  );
            qDebug() << "QmlPort::ir_get_image_name    22222222222222222      " << ir_relative_name;
            while( test_list.filter( ir_relative_name ).count() != 0  ) {
                n_index = ir_relative_name.lastIndexOf( '_' );
                ir_relative_name = ir_relative_name.mid( 0, n_index ) + QString( "_%1" ).arg( ++i );
                qDebug() << "QmlPort::ir_get_image_name    111111111111111      " << ir_relative_name;
            }
        }
        ms_img_fn = s_full_name + ir_relative_name;
        ms_task_image_name = ir_relative_name + ".uv.jpg";
        qDebug() << "QmlPort::ir_get_image_name" << ir_relative_name;
    }
    qDebug() << "QmlPort::ir_get_image_name" << ms_img_fn;
    m_str_image_fn = ms_img_fn; //no "irp.jpg or vi.jpg"
}

QString QmlPort::get_current_img_name()
{
    if( !mb_general_mode ) {
        qDebug()<<"QmlPort::get_current_img_name--------------------------------11111111111111111111111111";
        return get_task_tree_list_str( get_task_select_pos() );
    }
    ////useless
    if( false ) {
        QString fn;
        QString s_full_name;
        if( SettingHelp::get_show_type() ) {
            fn = get_image_fn() + ".irp.jpg";
        } else {
            fn = get_image_fn() + ".vi.jpg";
        }
        s_full_name = fn.mid( fn.lastIndexOf( '/' ) + 1 );

        if( !mb_general_mode ) {
            QString str_task = get_task_tree_list_path( get_task_select_pos() );
            QString task_full_name = get_task_tree_list_str( get_task_select_pos() );
            qDebug() << "QmlPort::get_current_img_name task_full_name:" << task_full_name;
            while( str_task.lastIndexOf( '/' ) != -1 ) {
                str_task = str_task.mid( 0 , str_task.lastIndexOf( '/' ) );
                task_full_name =  get_name_by_list_path( str_task ) + "-" + task_full_name;
            }
            qDebug()<<"QmlPort::get_current_img_name--------------------------------2222222222222222222222222222";
            return ( mp_device_list->get_temp_date_name() + "-" + task_full_name);
        }
        qDebug()<<"QmlPort::get_current_img_name--------------------------------333333333333333333333333333333";
        return s_full_name;
    } else {
        if( !mb_general_mode ) {
            QString str_task = get_task_tree_list_path( get_task_select_pos() );
            QString task_full_name = get_task_tree_list_str( get_task_select_pos() );
            qDebug() << "QmlPort::get_current_img_name task_full_name:" << task_full_name;
            while( str_task.lastIndexOf( '/' ) != -1 ) {
                str_task = str_task.mid( 0, str_task.lastIndexOf( '/' ) );
                task_full_name =  get_name_by_list_path( str_task ) + "-" + task_full_name;
            }
            qDebug()<<"QmlPort::get_current_img_name--------------------------------4444444444444444444444444444444";
            return task_full_name;
        }
    }
    qDebug()<<"QmlPort::get_current_img_name--------------------------------5555555555555555555555555555555555";
    return QString("");
}

QString QmlPort::get_name_by_list_path( QString str_path )
{
    //TASK_TREE_INFO temp_tree = mp_device_list->find_name_by_path( str_path );
    int number = 0;
    return mp_device_list->find_name_by_path( str_path, number ).task_name;
}

QString QmlPort::get_time_str()
{
    QDateTime tm = QDateTime::currentDateTime();

    //return tm.toString("yyyyMMddhhmmsszzz");

    if( tm >= MAX_DATE_TIME ) {
        tm = MAX_DATE_TIME;
        tm = tm.addSecs( -1 );
    } else if( tm <= MIN_DATE_TIME ) {
        tm = MIN_DATE_TIME;
        tm = tm.addSecs( 1 );
    }

#ifdef Q_OS_LINUX
    time_t tt = (time_t)tm.toTime_t();

    struct timeval tv;
    struct timezone tz;
    gettimeofday( &tv, &tz );
    tv.tv_sec = tt;
    settimeofday( &tv, &tz );
#endif

    time_t curtime = time( NULL );
    struct tm *cur_tm = localtime( &curtime );
    char buf[32];

#if defined(Q_OS_WIN32)
    ::sprintf_s(buf, 32, "%d%02d%02d%02d%02d%02d", cur_tm->tm_year + 1900,  cur_tm->tm_mon+1, cur_tm->tm_mday,
                cur_tm->tm_hour, cur_tm->tm_min, cur_tm->tm_sec);

#elif defined(Q_OS_LINUX)
    snprintf(buf, 32, "%d%02d%02d%02d%02d%02d", cur_tm->tm_year + 1900,  cur_tm->tm_mon+1, cur_tm->tm_mday,
             cur_tm->tm_hour, cur_tm->tm_min, cur_tm->tm_sec);

#endif

    return QString::fromUtf8(buf);
}


//保存最近点击的具体拍摄的照片名称
void QmlPort::setCurrentImgName()
{
    qDebug()<<"QmlPort::SetCurrentImgName()--------mp_device_list->get_select_device().task_info------------"<<mp_device_list->get_select_device().task_info;
    //时间设置应该是在拍摄的时候设置而不是点击项的时候设置
    //CurrentImageName = SubstationLevel+"-"+mp_device_list->get_tree_list_info().at(0).task_name+"-"+mp_device_list->get_select_device().task_info;
    //CurrentImageName = mp_device_list->all_replace_covert_char( mp_device_list->get_select_device().task_info );
}
//获取当前的拍摄照片的名称
QString QmlPort::GetCurrentImgName()
{
    QString ShootTime;

    ShootTime=get_time_str();
    qDebug()<<"QmlPort::SetCurrentImgName()--------ShootTime------------"<<ShootTime;
    CurrentImageName = ShootTime + "-" + mp_device_list->all_replace_covert_char( mp_device_list->get_select_device().task_info );

    qDebug()<<"QmlPort::GetCurrentImgName()----------------CurrentImageName--------------------"<<CurrentImageName;
    return CurrentImageName;
}

void QmlPort::GetShootContent()
{
    //mp_device_list->get_shoot_content();
}


bool QmlPort::is_head_pos(QString text)
{
    return mp_device_list->is_head_pos(text);
}

bool QmlPort::is_tail_pos(QString text)
{
    return mp_device_list->is_tail_pos(text);
}


int QmlPort::get_packup_count(int index)
{
    return mp_device_list->get_packup_count(index);
}


int QmlPort::get_next_index(int index)
{
    mp_device_list->get_next_index(index);
}

int QmlPort::get_pre_index(int index)
{
    mp_device_list->get_pre_index(index);
}

int QmlPort::get_father_index(int index)
{
    mp_device_list->get_father_index(index);
}

void QmlPort::slot_cap_start()
{
    qDebug() << "#### [QmlPort] [slot_cap_start] : running ------------------->";
    emit signal_cap_start();
}

void QmlPort::slot_cap_stop()
{
    qDebug() << "#### [QmlPort] [slot_cap_stop] : running ------------------->";
    emit signal_cap_stop();
}

void QmlPort::fresh_select_pkg()
{
    init_select_taskpack_dlg();
    mp_select_taskpack->fresh_select_pkg();
}

void QmlPort::debug_time_start()
{
    debug_start = QTime::currentTime();
}

void QmlPort::debug_time_end(int index)
{
    debug_end = QTime::currentTime();
    int num = debug_end.msecsTo(debug_start);
}


void QmlPort::enable_TreeView(bool enable)
{
    if(enable)
        emit signal_cap_stop();
    else
        emit signal_cap_start();
}



QList<QString> QmlPort::get_deviceNodes_by_index(int index)
{
    return mp_device_list->get_info_by_index(index);
}

void QmlPort::set_keyValue_to_up(int keyValue)
{
    m_keyValue_up = keyValue;
}

void QmlPort::set_keyValue_to_down(int keyValue)
{
    m_keyValue_down = keyValue;
}

void QmlPort::set_keyValue_to_left(int keyValue)
{
    m_keyValue_left = keyValue;
}

void QmlPort::set_keyValue_to_right(int keyValue)
{
    m_keyValue_right = keyValue;
}

void QmlPort::set_keyValue_to_center(int keyValue)
{
    m_keyValue_center = keyValue;
}

void QmlPort::set_keyValue_to_return(int keyValue)
{
    m_keyValue_return = keyValue;
}

int QmlPort::get_keyValue_from_up()
{
    return m_keyValue_up;
}

int QmlPort::get_keyValue_from_down()
{
    return m_keyValue_down;
}

int QmlPort::get_keyValue_from_left()
{
    return m_keyValue_left;
}

int QmlPort::get_keyValue_from_right()
{
    return m_keyValue_right;
}

int QmlPort::get_keyValue_from_center()
{
    return m_keyValue_center;
}

int QmlPort::get_keyValue_from_return()
{
    return m_keyValue_return;
}

int QmlPort::set_screenSize(int id)
{
    m_screenSize_id = id;
    return m_screenSize_id;
}

int QmlPort::get_screen_listWidth()
{
    switch (m_screenSize_id) {
    case SCREEN_480_272 :
        return 96;
        break;
    case SCREEN_800_480 :
        return 160;
        break;
    case SCREEN_800_480_2 :
        return 200;
        break;
    case SCREEN_853_480 :
        return 215;
        break;
    case SCREEN_1920_1080 :
        return 560;
        break;
    default:
        break;
    }
    return 160;
}

int QmlPort::delete_img_by_index()
{
    qDebug() << "[DEBUG]" << __FUNCTION__ << ":" << "start" ;
    QString strPath = get_cunrrentdb_savepath();
    QString strFile = GetCurrentImgName();
    QStringList listFile = strFile.split("-");
    QString strFlag = listFile.at(listFile.count()-1);

    //qDebug() << "[DEBUG]" << __FUNCTION__ << ": strPath " << strPath;
    //qDebug() << "[DEBUG]" << __FUNCTION__ << ": strFile " << strFile;
    //qDebug() << "[DEBUG]" << __FUNCTION__ << ": strFlag " << strFlag;

    /* 遍历strPath目录下所有文件, 删除与strFile同部位文件 */
    QDir dir(strPath);
    if (!dir.exists()) {
        qDebug() << "dir " << strPath << " is not exist !!!";
        return -1;
    }
    QStringList filters;
    filters << QString("*%1.irp.jpg").arg(strFlag) << QString("*%1.vi.jpg").arg(strFlag);
    QStringList fileInfoList = dir.entryList(filters, QDir::Files | QDir::NoSymLinks);
    qDebug() << "[DEBUG]" << __FUNCTION__ << ": file count " << fileInfoList.count();
    qulonglong shootime = 0;
    int index = 0;
    for (int i = 0; i < fileInfoList.count(); i++) {
        QString strFileName = fileInfoList.at(i);
        qDebug() << "[DEBUG]" << __FUNCTION__ << ": index " << i << ", filename " << strFileName;
        QStringList listFileName = strFileName.split("-");
        QString strShootTime = listFileName.at(0);
        if (strShootTime.toULongLong() > shootime) {
            index = i;
            shootime = strShootTime.toULongLong();
        }
        //QFile::remove(QString("%1/%2").arg(strPath).arg(strFileName));
    }
    if (index < fileInfoList.count()) {
        QFile::remove(QString("%1/%2").arg(strPath).arg(fileInfoList.at(index)));
        emit signal_remove_file(QString("%1/%2").arg(strPath).arg(fileInfoList.at(index)));
    }
    system("sync");
    qDebug() << "[DEBUG]" << __FUNCTION__ << ":" << "end" ;
    return 0;
}

int QmlPort::get_screen_width()
{
    switch (m_screenSize_id) {
    case SCREEN_480_272 :
        return 480;
        break;
    case SCREEN_800_480 :
        return 800;
        break;
    case SCREEN_800_480_2 :
        return 800;
        break;
    case SCREEN_853_480 :
        return 853;
        break;
    case SCREEN_1920_1080 :
        return 1920;
        break;
    default:
        break;
    }
    return 480;
}

int QmlPort::get_screen_height()
{
    switch (m_screenSize_id) {
    case SCREEN_480_272 :
        return 272;
        break;
    case SCREEN_800_480 :
        return 480;
        break;
    case SCREEN_800_480_2 :
        return 480;
        break;
    case SCREEN_853_480 :
        return 480;
        break;
    case SCREEN_1920_1080 :
        return 1080;
        break;
    default:
        break;
    }
    return 272;
}


QString QmlPort::get_cunrrentdb_savepath()
{   
    QString strPath = QString("%1/DCIM").arg(m_strSDPath);

    QString strFileName = QString("/mnt/data/unzipped/%1/path").arg(ms_taskpack_name);
    if (! QFile::exists(strFileName)) {
        QFile w_file;
        w_file.setFileName(strFileName);
        if (w_file.open(QIODevice::WriteOnly)) {
            QString strData = QString("%1/%2_%3").arg(m_strSDPath).arg(ms_taskpack_name).arg(get_time_str());
            QByteArray bData = strData.toUtf8();
            w_file.write(bData.data(), bData.count());
            w_file.close();
        }
    }

    if (QFile::exists(strFileName)) {
        QFile r_file;
        r_file.setFileName(strFileName);
        if (r_file.open(QIODevice::ReadOnly)) {
            char r_data[128] = {0x00};
            if (r_file.read(r_data, sizeof(r_data)) > 0) {
                strPath = QString("%1").arg(r_data);
            }
            r_file.close();
        }
    }

    QDir dir;
    if (!dir.exists(strPath)) {
        dir.mkpath(strPath);
    }

    return strPath;
}

void QmlPort::set_sd_path(QString strPath)
{
    m_strSDPath = strPath;
}
