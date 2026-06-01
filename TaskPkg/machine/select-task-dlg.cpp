#include "select-task-dlg.h"
#include <QDir>
#include <QDebug>
#include "databaseop.h"
#include "setting-help.h"
//#include "registry.h"
#include "qml-port.h"
#include "module.h"
//#include "pox_system.h"
#include "QScriptEngine"
#include "QTextCodec"

//#define UNZIP_HAS_DATA

//#ifdef UNZIP_HAS_DATA
//#define UNZIP_PATH SettingHelp::get_key_value( "data_path" ) //"c:"
//#else
//#define UNZIP_PATH SettingHelp::get_key_value( "data_path" ) + "/data"
//#endif

#if defined(Q_OS_WIN32)
#define UNZIP_PATH "D:/data"
#elif defined(Q_OS_LINUX)
#define UNZIP_PATH "/mnt/data"
#endif

SelectTaskDlg::SelectTaskDlg(bool b_general_mode, int n_task_mode, QObject *parent) :
    QObject(parent)
{
    this->p_port = ( QmlPort* )parent;
    //mn_explore_page = 0;
    mb_general_mode = b_general_mode;
    mp_db = NULL;
    ms_database_fn = "";
    mb_has_db = false;
    mb_restore_last_shoot_task = false;
    mb_restore_last_shoot_pos = false;

    ms_dir = UNZIP_PATH;
    ms_dir += "/pkgs";

    fresh_select_pkg();

    mn_selected_pack_pos = 0;
    //tasklist_sel_changed();
}

void SelectTaskDlg::fresh_select_pkg()
{
    QDir dir( ms_dir );
    QStringList filters;
    filters << "*.zip";
    dir.setNameFilters( filters );//过滤掉非压缩包文件
#ifdef PACKNAME_HAS_ZIP
    m_pack_fn_list = dir.entryList();
#else
    //获取筛选后所有的文件和目录的名称列表
    QStringList s_tmp_list = dir.entryList();
    QString s_tmp = ".zip";
    QString s_dir = UNZIP_PATH;
    for( int i=0; i<s_tmp_list.size(); ++i ) {
        QString s_name = s_tmp_list.at( i );
        QString s_pack_name = s_name.left( s_name.length() - s_tmp.length() );//单纯记录压缩包名字
        QStringList data;
        data.append( s_pack_name );
        data.append( get_pack_firm_ident_code( s_dir + "/unzipped/" + s_pack_name + "/setting.conf") );
        qDebug() << "SelectTaskDlg::SelectTaskDlg " << data;
        if(!m_pack_fn_list.contains(data))
            m_pack_fn_list.append( data );//记录的是压缩包名字和对应的设置文件解码出来的值
    }
#endif

}

QString SelectTaskDlg::get_pack_firm_ident_code( QString ms_taskpack_db_name )
{
    QString s_pkg_path = ms_taskpack_db_name;
    QString s_setting_path  = s_pkg_path.mid( 0, s_pkg_path.lastIndexOf('/') ) + "/setting.conf";
    QFile file( s_setting_path );
    file.open( QIODevice::ReadWrite );
    QByteArray bytes = file.readAll();//Json字符串，QByteArray与QString可转化
    file.close();
    QTextCodec *codec = NULL;
    //进行编码转化
    if( bytes.indexOf("UTF-8", Qt::CaseSensitive )  != 0 ) {
        codec = QTextCodec::codecForName("UTF-8");
    } else {
        codec = QTextCodec::codecForName("gbk");
    }
    QString out_array = codec->toUnicode( bytes.data() );
    QScriptEngine engine;
    //计算给定程序（"value=" + out_array）并返回计算值
    QScriptValue sc = engine.evaluate("value=" + out_array);
    //返回firm_ident_code名称的QScriptValue属性值
    return sc.property("firm_ident_code").toString() ;
}
//对记录所有的压缩包的列表中n_seq位置的代表的压缩包的解码值与firm_code的比较值
int SelectTaskDlg::compont_firm_code( int n_seq, QString firm_code )
{
    if( n_seq < 0 || m_pack_fn_list.isEmpty() ) {
        return 1;
    }
    if( n_seq < m_pack_fn_list.size() ) { //task pack
        if( m_pack_fn_list.at( n_seq ).at( GET_TASK_FIRM ).isEmpty() ) {
            return 1;
        }
        return m_pack_fn_list.at( n_seq ).at( GET_TASK_FIRM ).compare( firm_code );
    } else {
        return 1;
    }
    return 1;
}

int SelectTaskDlg::get_btns()
{
    if( mb_general_mode ) {
        return 4;
    } else {
        return 5;
    }
}
//获取n_seq的位置是否是当前选择的位置
bool SelectTaskDlg::get_task_selected(int n_seq)
{
    if( m_pack_fn_list.isEmpty() || mn_selected_pack_pos < 0 || mn_selected_pack_pos >= m_pack_fn_list.size() ) {
        return false;
    }
    if( mn_selected_pack_pos == n_seq ) { //task pack
        return true;
    } else {
        return false;
    }
}
//获取n_seq位置的压缩包的名称
QString SelectTaskDlg::get_tasklist_text(int n_seq)
{
    if( n_seq < 0 || m_pack_fn_list.isEmpty() ) {
        return "";
    }
    if( n_seq < m_pack_fn_list.size() ) { //task pack
        return m_pack_fn_list.at( n_seq ).at( GET_TASK_NAME );
    } else {
        return "";
    }
}
//判断n_seq位置的安装包是否被选择过？？？
bool SelectTaskDlg::selected_task_type( int n_seq )
{
    if( mn_selected_device_type_list.contains( n_seq ) ) {
        return true;
    } else {
        return false;
    }
}

QString SelectTaskDlg::get_task_type_text( int n_seq )
{
    if( n_seq < m_device_type_list.size() ) {
        return m_device_type_list.at( n_seq );
    } else {
        return "";
    }
}

void SelectTaskDlg::set_task_type( int n_seq )
{
    if( n_seq >= m_device_type_list.size() ) { return ; }
    if( mn_selected_device_type_list.contains( n_seq ) ) {
        mn_selected_device_type_list.removeOne( n_seq );
    } else {
        mn_selected_device_type_list << n_seq;
    }
}

void SelectTaskDlg::set_task(int n_seq)
{
    if( n_seq >= m_pack_fn_list.size() ) { return ; }
    if( mn_selected_pack_pos == n_seq ) { return; }

    mn_selected_pack_pos = n_seq;
    tasklist_sel_changed();
}

void SelectTaskDlg::select_all_task_type_clicked()
{
    if( mb_has_db && mp_db ) {
        mn_selected_device_type_list.clear();
        for( int i = 0; i < m_device_type_list.size(); i++ ) { //Default: select all
            mn_selected_device_type_list << i;
        }
    }
}

void SelectTaskDlg::select_no_task_type_clicked()
{
    if( mb_has_db && mp_db ) {
        mn_selected_device_type_list.clear();
    }
}

bool SelectTaskDlg::is_task_type_select_all( )
{
    return mn_selected_device_type_list.size() == m_device_type_list.size();
}

bool SelectTaskDlg::is_task_type_selectded()
{
    return mn_selected_device_type_list.isEmpty();
}

void SelectTaskDlg::select_all_task_zone_clicked()
{
    if( mb_has_db && mp_db ) {
        mn_selected_device_zone_list.clear();
        for( int i = 0; i < m_device_zone_list.size(); i++ ) { //Default: select all
            mn_selected_device_zone_list << i;
        }
        m_device_type_list.clear();
        mp_db->get_device_type_list_by_area( m_device_zone_list, m_device_type_list );
        mn_selected_device_type_list.clear();
        for( int i = 0; i < m_device_type_list.size(); i++ ) { //Default: select all
            mn_selected_device_type_list << i;
        }
    }
}

void SelectTaskDlg::select_no_task_zone_clicked()
{
    if(!mb_has_db)
        qDebug() << "#### [SelectTaskDlg] [select_no_task_zone_clicked] : mb_has_db is null";
    if(!mp_db)
        qDebug() << "#### [SelectTaskDlg] [select_no_task_zone_clicked] : mp_db is null";
    if( mb_has_db && mp_db ) {
        mn_selected_device_zone_list.clear();
        m_device_type_list.clear();
        mn_selected_device_type_list.clear();
    }
}

bool SelectTaskDlg::is_select_all_task_zone()
{
    return mn_selected_device_zone_list.count() == m_device_zone_list.count();
}

bool SelectTaskDlg::is_has_task_zone_click()
{
    return !mn_selected_device_zone_list.isEmpty();
}

void SelectTaskDlg::select_one_task_zone( int n_seq)
{

    if( n_seq >= m_device_zone_list.size() ) { return ; }
    if( mn_selected_device_zone_list.contains( n_seq ) ) {
        mn_selected_device_zone_list.removeOne( n_seq );
    } else {
        mn_selected_device_zone_list << n_seq;
    }

    if( mb_has_db && mp_db ) {
        QStringList s_list;
        for( int i=0; i<mn_selected_device_zone_list.size(); i++ ) {
            int n_pos = mn_selected_device_zone_list.at(i);
            if( n_pos >= 0 && n_pos <= m_device_zone_list.size() ) {
                s_list << m_device_zone_list.at( n_pos );
            }
        }

        m_device_type_list.clear();
        mp_db->get_device_type_list_by_area( s_list, m_device_type_list );

        mn_selected_device_type_list.clear();
        for( int i = 0; i < m_device_type_list.size(); i++ ) { //Default: select all
            mn_selected_device_type_list << i;
        }
    }
}

bool SelectTaskDlg::has_task_zone_by_seq( int n_seq )
{
    // qDebug() << mn_selected_device_zone_list << n_seq;
    if( mn_selected_device_zone_list.contains( n_seq ) ) {
        return true;
    } else {
        return false;
    }
}

QString SelectTaskDlg::get_task_zone_text( int n_seq )
{
    if( n_seq < m_device_zone_list.size() ) {
        return m_device_zone_list.at( n_seq );
    } else {
        return "";
    }
}

bool SelectTaskDlg::get_btn_enable(QString )
{
    return false;
}

void SelectTaskDlg::set_taskpack_cell_selected(int n_index)
{
    qDebug() << "SelectTaskDlg::set_taskpack_cell_selected n_index=" << n_index << " m_pack_fn_list.size()=" << m_pack_fn_list.size();
    if( n_index < m_pack_fn_list.size() ) {
        mn_selected_pack_pos = n_index;
        tasklist_sel_changed();
    }
}

void SelectTaskDlg::set_taskpack_cell_byname(QString s_name)
{
    for( int i=0; i<m_pack_fn_list.size(); ++i ) {
        if( s_name.compare( m_pack_fn_list.at( i ).at( 0 ) ) == 0 ) {
            set_taskpack_cell_selected( i );
            return;
        }
    }
    qDebug() << "SelectTaskDlg::set_taskpack_cell_byname error s_name=" << s_name;
}

QString SelectTaskDlg::delete_task_pack(int n_index)
{
    if( n_index < 0 || n_index >= m_pack_fn_list.size() ) {
        return "";
    }
    QString s_dir = UNZIP_PATH;
    QString s_unzip_dir = s_dir + "/unzipped/" + m_pack_fn_list.at( n_index ).at( GET_TASK_NAME );//解压包路径名
    QString s_fn = s_dir + "/pkgs/" + m_pack_fn_list.at( n_index ).at( GET_TASK_NAME ) + ".zip";//压缩包路径名
    QFile *p_file = new QFile( s_fn );
    QString s_pack_name = m_pack_fn_list.at( n_index ).at( GET_TASK_NAME );//压缩包名字
    //emit delete_task_pack_sig( msl_task_pack_text.at(mn_select_pos) );

    p_file->remove();//删除压缩包
    CModule::remove_dir( s_unzip_dir );//删除解压包
    m_pack_fn_list.removeAt( n_index );//更新记录压缩包列表
#ifdef Q_OS_LINUX
    //pox_system( "sync" );
#endif
    delete p_file;
    return s_pack_name;
}

bool SelectTaskDlg::restore_last_shoot_status(bool b_restore_last_shoot_pos, s_task_pack_status_t *p_stauts )
{
    qDebug()<<"SelectTaskDlg::restore_last_shoot_status -----------00000000";
    bool flag = true;
    for( int i = 0; i < m_pack_fn_list.count(); i++ ) {
        if( m_pack_fn_list.at( i ).at( GET_TASK_NAME ).compare( p_stauts->s_pack_name ) == 0 ) {
            flag = false;
            break;
        }
    }
    if( flag ) {
        return false;
    }

    mb_has_db = false;
    int i;
    for( i = 0; i < m_pack_fn_list.size(); ++i ) {
        if( m_pack_fn_list.at( i ).at( GET_TASK_NAME ) == p_stauts->s_pack_name ) {
            mn_selected_pack_pos = i;
            break;
        }
    }
    if( i == m_pack_fn_list.size() ) {
        return false;
    }

    QString s_taskpack_name = m_pack_fn_list.at( mn_selected_pack_pos ).at( GET_TASK_NAME );
    QString s_pack_name = s_taskpack_name;
    QString s_database_fn = get_database_file_name( s_pack_name );

    m_device_zone_list.clear();
    m_device_type_list.clear();
    mn_selected_device_zone_list.clear();
    mn_selected_device_type_list.clear();

    if( s_database_fn.isEmpty() ) {
        return false;
    }

    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
    QString s_full_fn = UNZIP_PATH;
    s_full_fn += "/unzipped/" + s_pack_name + "/" + s_database_fn;
    qDebug()<<"SelectTaskDlg::restore_last_shoot_status ----------- "<<s_full_fn;
    ms_database_fn = s_full_fn;
    mp_db = new DatabaseOp( s_full_fn );
    if( mp_db == NULL ) {
        return false;
    }

    m_device_type_list = p_stauts->s_sel_device_type_list;
    m_device_zone_list = p_stauts->s_sel_device_zone_list;

    for( int i = 0; i < m_device_zone_list.size(); i++ ) { //Default: select all
        mn_selected_device_zone_list << i;
    }
    for( int i = 0; i < m_device_type_list.size(); i++ ) { //Default: select all
        mn_selected_device_type_list << i;
    }
    mb_has_db = true;
    mb_restore_last_shoot_task = true;
    mb_restore_last_shoot_pos = b_restore_last_shoot_pos;
    this->ok_btn_continue_slot();
    return true;
}

SelectTaskDlg::~SelectTaskDlg()
{
    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
}

void SelectTaskDlg::down_btn_pressed_slot() {
}

void SelectTaskDlg::cancel_btn_pressed_slot() {
    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
}

void SelectTaskDlg::ok_btn_continue_slot()
{
    qDebug()<<"SelectTaskDlg::ok_btn_continue_slot ------------- ";
    if( m_pack_fn_list.isEmpty() || mn_selected_pack_pos < 0 || mn_selected_pack_pos >= m_pack_fn_list.size()
            || !mb_has_db || mn_selected_device_zone_list.isEmpty() || mn_selected_device_type_list.isEmpty() ) {
        cancel_btn_pressed_slot();
        qDebug()<<"SelectTaskDlg::ok_btn_continue_slot ------------- 22222";
        return ;
    }
    qDebug()<<"SelectTaskDlg::ok_btn_continue_slot ------------- 33333";
    p_port->set_task_mode( false );
    p_port->set_taskpack_db_name( ms_database_fn );

    QString s_taskpack_name = m_pack_fn_list.at( mn_selected_pack_pos ).at( GET_TASK_NAME );
    QString s_pack_name = s_taskpack_name;
qDebug()<<"SelectTaskDlg::ok_btn_continue_slot -------------11111"<<s_pack_name;
    p_port->set_taskpack_name( s_pack_name );

    QStringList s_list;
    for( int i=0; i<mn_selected_device_zone_list.size(); i++ ) {
        int n_pos = mn_selected_device_zone_list.at(i);
        if( n_pos >= 0 && n_pos < m_device_zone_list.size() ) {
            s_list << m_device_zone_list.at( n_pos );
        }
    }
    p_port->set_device_zone_list( s_list );

    s_list.clear();
    for( int i = 0; i < mn_selected_device_type_list.size(); i++ ) {
        int n_pos = mn_selected_device_type_list.at( i );
        if( n_pos >= 0 && n_pos < m_device_type_list.size() ) {
            s_list << m_device_type_list.at( n_pos );
        }
    }
    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
    mb_general_mode = false;
    p_port->set_device_type_list( s_list, mb_restore_last_shoot_task, mb_restore_last_shoot_pos );
    mb_restore_last_shoot_task = false;
}

bool SelectTaskDlg::ok_btn_pressed_slot() {
    if( m_pack_fn_list.isEmpty() || mn_selected_pack_pos < 0 || mn_selected_pack_pos >= m_pack_fn_list.size()
            || !mb_has_db || mn_selected_device_zone_list.isEmpty() || mn_selected_device_type_list.isEmpty() ) {
        cancel_btn_pressed_slot();
        return false;
    }

    emit regist_is_activate();

    return true;
}

void SelectTaskDlg::up_btn_pressed_slot() {
}

void SelectTaskDlg::tasklist_sel_changed()
{
    mb_has_db = false;
    qDebug() << "tasklist_sel_changed 1 ";
    if( mn_selected_pack_pos < 0 || mn_selected_pack_pos >= m_pack_fn_list.size() ) {
        return ;
    }
    qDebug() << "tasklist_sel_changed 2 ";
    QString s_taskpack_name = m_pack_fn_list.at( mn_selected_pack_pos ).at( GET_TASK_NAME );
    QString s_pack_name = s_taskpack_name;
    QString s_database_fn = get_database_file_name( s_pack_name );

    m_device_zone_list.clear();
    m_device_type_list.clear();
    mn_selected_device_zone_list.clear();
    mn_selected_device_type_list.clear();

    if( s_database_fn.isEmpty() ) {
        return ;
    }

    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
    //p_port->set_taskpack_db_name( "" );
    QString s_full_fn = UNZIP_PATH;
    s_full_fn += "/unzipped/" + s_pack_name + "/" + s_database_fn;
    ms_database_fn = s_full_fn;
    mp_db = new DatabaseOp( s_full_fn );
    qDebug()<<"SelectTaskDlg::tasklist_sel_changed ---------------- "<<s_full_fn;
    if( mp_db == NULL ) { return ; }

    mp_db->get_device_area_list( m_device_zone_list );
    mp_db->get_device_type_list( m_device_type_list );


    for( int i = 0; i < m_device_zone_list.size(); i++ ) { //Default: select all
        mn_selected_device_zone_list << i;
    }
    for( int i = 0; i < m_device_type_list.size(); i++ ) { //Default: select all
        mn_selected_device_type_list << i;
    }
    mb_has_db = true;
}

QString SelectTaskDlg::get_database_file_name(QString s_pack_name)
{
    QString s_fn = UNZIP_PATH;
    s_fn += "/unzipped/" + s_pack_name;
    QDir dir( s_fn );

    QStringList filters, s_database_fn_list;
    filters << "*.db";
    dir.setNameFilters( filters );
    s_database_fn_list = dir.entryList();
    if( s_database_fn_list.empty() ) {
        return "";
    } else {
        return s_database_fn_list.at( 0 );
    }
}
