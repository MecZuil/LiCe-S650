/* copyright: ms
 * author: ZhouJinWei
 * Function: 实现导航拍摄模式的设备区-设备类型信息列表显示处理
 */
#include "device-list.h"
#include <QDebug>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include <QUrl>
#include "config.h"
#include "databaseop.h"
#include "yfjsonaccess.h"
#include "setting-help.h"
#include <QDateTime>
#include "qml-port.h"
#ifdef Q_OS_LINUX
#include <QProcess>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#endif

#define ENABLE_PERFORMANCE_TESTING
#ifdef ENABLE_PERFORMANCE_TESTING
#include <QTime>
#endif

#define BACKGROUND_COLOR QColor(57,62,66)
#define TITLE_FONT_COLOR QColor(255,0,0) //QColor(153,17,19)
#define LIST_FONT_COLOR QColor(255,255,255)
#define LIST_SELECTED_COLOR QColor(224, 170, 0)
#define LIST_SELECTED_FONT_COLOR QColor(0,0,0)
#define TITLE_INTERVAL 10
#define LINES_INTERVAL 5

#define TITLE_FONT_SIZE 24
#define LIST_FONT_SIZE 18

DeviceList::DeviceList(QObject *parent) :
    QObject(parent)
{
    p_port = ( QmlPort* )parent;
    mn_first_line_pos = 0;
    mn_selected_pos = 0;
    mb_has_setting_table = false;
    mf_database_ver = 0.0;
    mp_db = NULL;
    mn_show_layer = 0;

    ms_fault_nature_list << tr("Normal") << tr("Attention") << tr("General fault");
    ms_fault_nature_list << tr("Important fault") << tr("Serious fault") << tr("Unknown");
    mn_lines = 6;
    mb_child_visible_change = false;
    mb_last_diver_post_down = 0;
}

DeviceList::~DeviceList()
{
}

void DeviceList::set_title( QString s_title , bool )
{
    ms_title = s_title;
}

void DeviceList::set_device_zone_list( QStringList s_device_zone_list, bool b_need_update )
{
    qDebug()<<"DeviceList::set_device_zone_list ----------------------------- ";
    ms_device_zone_list = s_device_zone_list;
    if( b_need_update ) {
        set_list_data();
    }
}

void DeviceList::set_device_type_list( QStringList s_device_type_list, bool b_need_update, bool b_restore_last_shoot_task, bool b_restore_last_shoot_pos )
{
    qDebug()<<"DeviceList::set_device_type_list ----------------------------- ";
    ms_device_type_list = s_device_type_list;
    if( b_need_update ) {
        set_list_data( b_restore_last_shoot_task, b_restore_last_shoot_pos );
    }
}

void DeviceList::set_list_data(bool b_restore_last_shoot_task, bool b_restore_last_shoot_pos)
{
    qDebug()<<"DeviceList::set_list_data ----------------------------- ";
    if( mp_db == NULL )
    {
        mp_db = new DatabaseOp( p_port->get_taskpack_db_name() );
        qDebug()<<"DeviceList::set_list_data --------------p_port->get_taskpack_db_name()--------------- "<<p_port->get_taskpack_db_name();
    }

    if( mp_db == NULL ) { return ; }
    mb_has_setting_table = mp_db->has_table( "settings" );
    if ( mb_has_setting_table ){
        mf_database_ver = mp_db->get_data_base_ver();
    }
    QStringList s_list;
    mp_db->get_fault_nature_list( s_list );
    if( !s_list.empty() ) {
        ms_fault_nature_list = s_list;
    }

    //clear_device_area_info();
    clear_device_type_info();
    mn_has_shooted_list.clear();
    int n_taskpack_mode = get_taskpack_mode();

    mn_selected_pos = 0;

    get_general_task_device_all_info( m_task_tree_list, b_restore_last_shoot_task, b_restore_last_shoot_pos );
    qDebug()<<"DeviceList::set_list_data ----------------------------- 1111111"<<m_task_tree_list.count();

    if( n_taskpack_mode == TASKPACK_MODE_BY_LINE_TOWER ) {
        mn_show_layer = 1;
    } else {
        mn_show_layer = 0;
    }
    mn_first_line_pos = 0;
    ms_selected_volt.clear();
    ms_selected_zone_name.clear();

    if( mp_db ) {
        delete mp_db;
        mp_db = NULL;
    }
    init_tree_for_list();
}

void DeviceList::init_tree_for_list()
{
    mb_send_over = true;
    qDebug() << "DeviceList::init_tree_for_list " << p_port->get_device_tree_expand_way();
    if( p_port->get_device_tree_expand_way() == DEVICE_TREE_EXPAND_BY_LEVEL ) {
        emit level_tree_init();
        next_device_task( false );
    } else {
        emit device_tree_ready();
        next_device_task( false );
    }
}

int DeviceList::get_taskpack_mode()
{
    if( p_port ) {
        return p_port->get_taskpack_mode();
    } else {
        return TASKPACK_MODE_BY_DEVICE;
    }
}

//#ifdef AUTOANALYSE
void DeviceList::add_rule_info( QString s_outline_id, DEVTYPEINFO &dev_type_info,
                                QString device_type_id, QString device_param_id,
                                QList< QStringList> info_ana )
{

    for( int i = 0; i < info_ana.size(); i++ ) {

        QString s_sql = QString( "select rule_formula_type_value, rule_title, rule_formula,rule_text, fault_nature_id from detect_rules, device_types_params_anas where ("
                                 "device_types_params_anas.id = detect_rules.device_types_params_ana_id and device_type_id = '%1' and "
                                 "device_param_id = '%2' and ana_sign = '%3' and ana_type_id = '%4' )" )
                .arg( device_type_id ).arg( device_param_id ).arg( info_ana.at( i ).at( 1 ) ).arg( info_ana.at( i ).at( 0 ) );

        QVector<QStringList> s_list;
        mp_db->get_all_data_list( s_sql, s_list );
        QVector<QStringList>::const_iterator itr = s_list.constBegin();

        while( itr != s_list.constEnd() ) {
            RULEINFO rule_info;
            QStringList s_tmp_list = static_cast<QStringList>( *itr );

            rule_info.ana_other_name = info_ana.at( i ).at( 1 );
            int j = -1;
            rule_info.s_rule = s_tmp_list.at( ++j );
            rule_info.s_rule_title = s_tmp_list.at( ++j );
            rule_info.s_rule_formula = s_tmp_list.at(++j);
            rule_info.s_rule_text = s_tmp_list.at( ++j );
            rule_info.s_rule_text = rule_info.s_rule_text.left( rule_info.s_rule_text.indexOf( "\n" ) );
            QString s_error_type = s_tmp_list.at( ++j );
            if( s_error_type.isEmpty() ) {
                rule_info.n_error_type = 0;
            } else {
                rule_info.n_error_type = s_error_type.toInt();
            }

            dev_type_info.vc_rules.push_back( rule_info );
            ++itr;
        }
    }
    quicksort( dev_type_info.vc_rules, 0, dev_type_info.vc_rules.count() - 1 );
}

void DeviceList::quicksort( QVector<RULEINFO>& vint, int fitst, int end)
{
    int i = fitst,j = end;
    RULEINFO temp;
    if( fitst < end ) {
        temp = vint[ fitst ];
        while( i != j ) {
            while( j>i && vint[j].n_error_type <= temp.n_error_type ) {
                j--;
            }
            vint[i] = vint[ j ];
            while( i < j && vint[ i ].n_error_type >= temp.n_error_type ) {
                i++;
            }
            vint[ j ]=vint[ i ];
        }
        vint[i]=temp;
    }
}
//#endif
void DeviceList::clear_device_type_info()
{
    mmap_device_type_info.clear();
}

void DeviceList::get_outline_rule(const QString &s_outline_file_name, SOUTLINERULEINFO &outline_rule)
{
    QString s_sql = "select * from outlines,detect_rules where "
                    " outlines.outline_vector_file_name ='";
    s_sql += s_outline_file_name + "'";

    QVector<QStringList> s_list;
    mp_db->get_outline_rule( s_sql, s_list );
    QVector< QStringList >::const_iterator itr = s_list.constBegin();

    while( itr != s_list.constEnd() ) {
        RULEINFO rule_info;
        int i = 0;
        QStringList s_tmp_list = static_cast<QStringList>( *itr );

        rule_info.s_rule = s_tmp_list.at( i++ );
        rule_info.s_rule_title = s_tmp_list.at( i++ );
        rule_info.s_rule_formula = s_tmp_list.at( i++ );
        rule_info.s_rule_text = s_tmp_list.at( i++ );
        QString s_err_type = s_tmp_list.at( i++ );
        if( s_err_type.isEmpty() ) {
            rule_info.n_error_type = 0;
        } else {
            rule_info.n_error_type = s_err_type.toInt();
        }

        outline_rule.rule_vc.push_back( rule_info );

        ++itr;
    }
}

void DeviceList::turn_page( bool is_up ) {
    if( is_up ) {
        if( mn_first_line_pos == 0 ) { return ; }
        if( mn_first_line_pos >= mn_lines ) {
            mn_first_line_pos -= mn_lines;
        } else {
            mn_first_line_pos = 0;
        }
    } else {
        if( mn_first_line_pos + mn_lines >= ms_list.size() ) { return ; }
        mn_first_line_pos += mn_lines;
    }
}

bool DeviceList::can_turn_page( bool is_up ) {
    if( is_up ) {
        if( mn_first_line_pos > 0 ) {
            return true;
        } else {
            return false;
        }
    } else {
        if( mn_first_line_pos + mn_lines >= ms_list.size() ) {
            return false;
        } else {
            return true;
        }
    }
}

QStringList DeviceList::get_fault_nature_list()
{
    return ms_fault_nature_list;
}

bool DeviceList::can_turn_line(bool is_up)
{
    if( is_up ) {
        if( mn_selected_pos > 0 ) { //&& mn_selected_pos <= mb_has_child_list.size()
            for( int i=0; i<mn_selected_pos; ++i ) {
                if( !mb_has_child_list.at( i ) ) {
                    return true;
                }
            }
        }
        return false;
    } else {
        if( mn_selected_pos < ms_list.size()-1 ) {
            for( int i=mn_selected_pos+1; i<ms_list.size(); ++i ) {
                if( !mb_has_child_list.at( i ) ) {
                    return true;
                }
            }

        }
        return false;
    }
}

bool DeviceList::can_turn_back_layer()
{
    int n_taskpack_mode = get_taskpack_mode();
    if( TASKPACK_MODE_BY_SUB_INTERVAL == n_taskpack_mode ) {
        if( mn_show_layer > 0 ) { return true; }
    } else if( TASKPACK_MODE_BY_LINE_TOWER == n_taskpack_mode ) {
        if( mn_show_layer > 1 ) { return true; }
    }
    return false;
}

QString DeviceList::get_ir_image_file_name(bool b_general_mode, bool b_device_info)
{
    QString s_ir_image_file_name = "";
    QString s_version = p_port->get_task_version();
    QString s_time = get_time_str();
    QString s_file_ext = ""; //".irp.jpg";
    int n_taskpack_mode = get_taskpack_mode();
    if( b_general_mode ) {
        s_ir_image_file_name = s_version + s_time + s_file_ext;
        qDebug()<<"get_ir_image_file_name-----------s_ir_image_file_name-------------1111111111111111---------------"<<s_ir_image_file_name;
        return s_ir_image_file_name;
    }

    if( !b_device_info ) {
        s_ir_image_file_name = s_version + s_time + s_file_ext;
        qDebug()<<"get_ir_image_file_name-----------s_ir_image_file_name-------------2222222222222222---------------"<<s_ir_image_file_name;
    }

    if( mn_selected_pos >= m_task_tree_list.size() )  {
        //return s_ir_image_file_name;
    } else {
        int temp_pos = mn_selected_pos;
        //s_ir_image_file_name = s_version + s_time + "-" + all_replace_covert_char( m_task_tree_list.at( temp_pos ).task_info );
        s_ir_image_file_name = s_version + s_time + "-" + m_task_tree_list.at(0).task_name + "-" + all_replace_covert_char( m_task_tree_list.at( temp_pos ).task_info );
        temp_date_name = s_version + s_time;
        qDebug()<<"get_ir_image_file_name-----------s_ir_image_file_name-------------333333333333333---------------"<<s_ir_image_file_name;
    }
    qDebug()<<"get_ir_image_file_name-----------s_ir_image_file_name-------------444444444444444---------------"<<s_ir_image_file_name;
    return s_ir_image_file_name;
}


/************************************************************************************
 * @ description : 查询选择设备
 * @ param       : null
 * @ return      : TASK_TREE_INFO
 ************************************************************************************/
TASK_TREE_INFO DeviceList::get_select_device()
{
    return m_task_tree_list.at( mn_selected_pos );
}

void DeviceList::set_shooted()
{
    if( mn_selected_pos < m_task_tree_list.count() ) {
        bool flag = true;
        int select_post_up = mn_selected_pos;
        int select_post_down = mn_selected_pos;
        if( select_post_up + 1 < m_task_tree_list.count() ) {
            select_post_up ++ ;
            if( m_task_tree_list[ select_post_up ].down_node_number > 0 ) {

            } else {
                flag = false;
            }
        }
        if( flag ) {
            int i = 0;
            while( select_post_down > 0  ) {
                select_post_down--;
                if( m_task_tree_list[ select_post_down ].down_node_number > 0 ) {
                    mb_last_diver_post_down = select_post_down;
                    mb_last_diver_number = i;
                    mb_last_diver_over = true;
                    break;
                } else {
                    if( m_task_tree_list[ select_post_down ].b_shooted == false ) {
                        flag = false;
                        break;
                    } else {
                        i++;
                    }
                }
            }
        }
        m_task_tree_list[ mn_selected_pos ].b_shooted = true; // add by st
        s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
        if( !p_status->n_shooted_pos_list.contains( mn_selected_pos ) ) {
            p_status->n_shooted_pos_list.append( mn_selected_pos );
            SettingHelp::set_task_pack_status( p_status );
        }
        set_task_visible_param();
        emit device_save_change();
    }
}

QString DeviceList::get_version_str()
{
    QString s_version = "";
    QString s_pkg_path = p_port->get_task_general_mode()?"":p_port->get_taskpack_db_name();

    if( s_pkg_path.isEmpty() ) {
        s_version = "1";
        return s_version;
    }
    QString s_setting_path  = s_pkg_path.mid( 0, s_pkg_path.lastIndexOf('/') ) + "/setting.conf";

    YFJsonAccess read_param ( s_setting_path );
    QJsonValue s_value;
    read_param.get_value( "version", s_value);
    return s_value.toString();

}

#define MIN_DATE QDate( 1000, 1, 1 )
#define MAX_DATE QDate( 2037, 1, 1 )
#define MIN_DATE_TIME QDateTime( MIN_DATE, QTime( 0, 0, 0 ) )
#define MAX_DATE_TIME QDateTime( MAX_DATE, QTime( 0, 0, 0 ) )
QString DeviceList::get_time_str()
{
    QDateTime tm = QDateTime::currentDateTime();

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


/*****************************************************************
 * @ description : 设备选择，发送信号，改变设备及相关数据
 * @ param       : null
 * @ return      : null
 *****************************************************************/
void DeviceList::emit_device_selected()
{
    /* 设备索引判断 */
    if( mn_selected_pos < 0 || mn_selected_pos >= m_task_tree_list.size() ) {
    }
    else {
        QStringList s_outline_fn_list, s_ana_list;
        DEVTYPEINFO default_info;
        QString s_outline_id = m_task_tree_list.at( mn_selected_pos ).basic_subtypes_id;
        //qDebug()<<"DeviceList::emit_device_selected ----------------------111111111"<<s_outline_id<<m_task_tree_list.count();

        default_info.s_outline_file_name = "";
        default_info.s_ana_text = "";
        DEVTYPEINFO info = mmap_device_type_info.value( s_outline_id, default_info );
        if( !info.s_outline_file_name.isEmpty() ) {
            //qDebug()<<"DeviceList::emit_device_selected ----------------------2222222222"<<info.s_outline_file_name;
            s_outline_fn_list << info.s_outline_file_name;
        }
        if( !info.s_ana_text.isEmpty() ) {
            //qDebug()<<"DeviceList::emit_device_selected ----------------------3333333333"<<info.s_ana_text;
            //qDebug()<<"DeviceList::emit_device_selected ----------------------4444444444"<<info.vc_rules.count();
            /*for(int w = 0; w <info.vc_rules.count(); w++)
            {
            qDebug()<<"DeviceList::emit_device_selected -------------555555555555"<<"n_error_type: "<<info.vc_rules.at(w).n_error_type
                    <<"ana_other_name: "<<info.vc_rules.at(w).ana_other_name
                    <<"s_rule: "<<info.vc_rules.at(w).s_rule
                    <<"s_rule_title: "<<info.vc_rules.at(w).s_rule_title
                    <<"s_rule_formula: "<<info.vc_rules.at(w).s_rule_formula
                    <<"s_rule_text: "<<info.vc_rules.at(w).s_rule_text<<"\n";
            }*/
            s_ana_list << info.s_ana_text;
        }

#if 0
        for(int i = 0; i < s_outline_fn_list.count(); i++) {
            qDebug() << "\r\n############ s_outline_fn_list = " << s_outline_fn_list.at(i);
        }
        for(int j = 0; j < s_ana_list.count(); j++) {
            qDebug() << "\r\n############ s_ana_list = " << s_ana_list.at(j);
        }
#endif

        emit outline_ana_selected( s_outline_fn_list, s_ana_list );
        return ;
    }
}


/*************************************************************************
 * @ description : 获取当前选择的设备信息
 * @ param       : null
 * @ return      : 设备信息
 *************************************************************************/
DEVTYPEINFO DeviceList::get_curDevInfo()
{
    DEVTYPEINFO temp_info;
    if(mn_selected_pos >= 0 && mn_selected_pos < m_task_tree_list.size()) {
        QString key = m_task_tree_list.at( mn_selected_pos ).basic_subtypes_id;
        DEVTYPEINFO default_info;
        temp_info = mmap_device_type_info.value( key, default_info );
    }
    return temp_info;
}

//task_info:<变电站电压等级>-<变电站名>-<设备区电压等级>-<设备区名>-<设备电压等级>-<设备备注>-<设备类型>-<设备型号>-<相别>-<部位>
void DeviceList::get_general_task_device_all_info(QList<TASK_TREE_INFO> &s_info_list, bool b_restore_last_shoot_task, bool b_restore_last_shoot_pos )
{
    qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- ";
#ifdef ENABLE_PERFORMANCE_TESTING
    QTime time;
    time.start();
#endif
    s_info_list.clear();
    clear_device_type_info();
    int sencond_number = 0;
    QString s_sql, s_order_sql;
    unsigned int n_count = 1;
    s_task_pack_status_t *p_status = NULL;

    if( b_restore_last_shoot_task ) {
        p_status = SettingHelp::get_task_pack_status();
        if( b_restore_last_shoot_pos ) {
            mn_selected_pos = p_status->n_shoot_pos;
        } else {
            p_status->n_shooted_pos_list.clear();
            SettingHelp::set_task_pack_status( p_status );
        }
    }

    //get device area voltage grade
    QVector<QStringList> s_v_zone_vol_grade_list;

    for( int j = 0; j < ms_device_type_list.size() / 100 + 1; j++ ) {
        s_sql = "select distinct region_id, name from hp_common_shoot_sequences, regions where ( (regions.id = hp_common_shoot_sequences.region_id ) and ("; //device_area_name,
        QString s_base_sql = "";
        for( int i = j * 100; i < ms_device_type_list.size() && ( i < (j + 1) * 100 ) ; ++i ) {
            s_base_sql += "device_type='" + ms_device_type_list.at(i) + "'";
            if( i < ms_device_type_list.size() - 1 && (i % 100 != 99) ) {
                s_base_sql += " or ";
            }
        }
        s_base_sql += " ) and (";
        for( int i = 0; i < ms_device_zone_list.size(); ++ i ) {
            s_base_sql += "regions.name='" + ms_device_zone_list.at(i) + "'";
            if( i < ms_device_zone_list.size() - 1 ) {
                s_base_sql += " or ";
            }
        }
        s_base_sql += ") )";
        s_sql += s_base_sql;
        mp_db->get_all_data_list( s_sql, s_v_zone_vol_grade_list );
    }
    for( int i = 0; i < s_v_zone_vol_grade_list.count() - 1; i++ ) {
        if( s_v_zone_vol_grade_list.at( i ).at( 0 ).toInt() == s_v_zone_vol_grade_list.at( i + 1 ).at( 0 ).toInt() ) {
            s_v_zone_vol_grade_list.remove( i );
            i--;
        }
    }

    QString path = "0";
    QString IntervalVolLevel;
    TASK_TREE_INFO info, device_info;

    info.b_shooted = false;
    info.task_info = "";
    info.basic_subtypes_id = "";
    info.b_visible = true;
    info.b_child_visible = true;

    device_info.down_node_number = 0;
    device_info.task_level = 4;
    device_info.b_visible = true;
    device_info.b_child_visible = true;

    QString temp_list_first = path;
    int first_level = 0;
    int first_father_id = 0;
    QString first_vol_name = "";
    int father_id;


    qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 111111111"<<s_v_zone_vol_grade_list.size();
    for( int i = 0; i < s_v_zone_vol_grade_list.size(); ++i ) {//二级分组树设置
        bool must_add_first = false;
        //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 00000000"<<s_v_zone_vol_grade_list.at( i ).at( 0 ).toInt();
        if( get_regions_name( s_v_zone_vol_grade_list.at( i ).at( 0 ).toInt(), first_father_id, first_vol_name ) ) {
            must_add_first = true;
        }
        if( must_add_first ) {
            QString father_str;
            get_regions_name( first_father_id, father_id, father_str );
            qDebug()<<"DeviceList::get_general_task_device_all_info   father_id----------------vvvvvvvvvvvvvvvvvvvvvvvvvvvvv"<<father_id;
            info.task_level = 1;
            info.task_name = father_str;
            IntervalVolLevel = father_str;
            info.path_list = path + QString("/%1").arg( first_level++ );
            //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 22222222"<<info.path_list;
            int count = 0;
            find_node_number_by_father_id( count, s_v_zone_vol_grade_list );
            info.down_node_number = count;
            temp_list_first = info.path_list;
            ++n_count;
            s_info_list.append( info );

            qDebug()<<"DeviceList::get_general_task_device_all_info   info.task_name----------------eeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"<<info.task_name;
            qDebug()<<"DeviceList::get_general_task_device_all_info   info.down_node_number----------------ffffffffffffffffffffffffffffff"<<info.down_node_number;
        }

        info.task_level = 2;
        info.task_name = s_v_zone_vol_grade_list.at( i ).at( 1 );
        info.path_list = temp_list_first + QString("/%1").arg( i );
        //qDebug()<<"DeviceList::get_general_task_device_all_info   info.task_name----------------dddddddddddddddddddddddddddd"<<info.task_name;
        //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 3333333"<<info.path_list<<ms_device_type_list.size() / 100 + 1;
        QVector<QStringList> device_type_list;
        for( int j = 0; j < ms_device_type_list.size() / 100 + 1; j++ ) {
            s_sql = "select distinct device_type from hp_common_shoot_sequences where ("; //device_area_name,
            QString s_base_sql = "";
            for( int m = j * 100; m < ms_device_type_list.size() && ( m < (j + 1) * 100 ) ; ++m ) {
                s_base_sql += "device_type='" + ms_device_type_list.at( m ) + "'";
                if( m < ms_device_type_list.size() - 1 && (m % 100 != 99) ) {
                    s_base_sql += " or ";
                } else {
                    s_base_sql += ") ";
                }
            }
            s_sql += s_base_sql;
            s_sql += " and region_id='" + s_v_zone_vol_grade_list[ i ][ 0 ] + "'";
            mp_db->get_all_data_list( s_sql, device_type_list );
        }
        //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 44444444"<<device_type_list.count() - 1;
        for( int i = 0; i < device_type_list.count() - 1; i++ ) {
            if( device_type_list.at( i ).at( 0 ).compare( device_type_list.at( i + 1 ).at( 0 ) ) == 0 ) {
                device_type_list.remove( i );
                i--;
            }
        }

        QString temp_list_i = info.path_list;
        info.down_node_number = device_type_list.count();
        ++n_count;
        s_info_list.append( info );
        //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 55555555"<<device_type_list.count();
        for( int k = 0; k < device_type_list.count(); ++k ) {//三级分组
            info.task_level = 3;
            info.task_name = device_type_list.at( k ).at( 0 );
            info.path_list = temp_list_i + QString("/%1").arg( k );
            //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 666666"<<info.path_list;
            s_sql = "select device_name, device_comment, phasic,serial_no , part_position, device_type_id, model_style_id, part_position_id, device_param_id, device_param, content from hp_common_shoot_sequences where (device_type='" + device_type_list.at( k ).at( 0 ) + "'";
            s_sql += " and region_id='" + s_v_zone_vol_grade_list.at( i ).at( 0 ) + "')";//serial_no  model_style
            QVector<QStringList> s_v_device_list;
            mp_db->get_all_data_list( s_sql, s_v_device_list );
            info.down_node_number = s_v_device_list.size();
            ++n_count;
            s_info_list.append( info );

            QString temp_list_k = info.path_list;
            //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 77777777"<<s_v_device_list.count();
            for( int m = 0; m < s_v_device_list.count(); ++m ) {//4级分组设置
                QStringList s_device_list = s_v_device_list.at( m );
                //qDebug()<<"DeviceList::get_general_task_device_all_info   s_device_list----------------aaaaaaaaaaaaaaaaaaaa"<<s_device_list.count();
                //qDebug()<<"DeviceList::get_general_task_device_all_info   device_type----------------bbbbbbbbbbbbbbbbbb"<<device_type_list.at( k ).at( 0 );
                device_info.basic_subtypes_id = "";
                QVector<QStringList> outline_list;
                task_get_ana_unit_text( s_device_list.at( 6 ), s_device_list.at( 7 ), outline_list );
                if( outline_list.isEmpty() ) {
                    //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- BBBBBBBBBB"<<outline_list.isEmpty();
                } else {
                    device_info.basic_subtypes_id = outline_list.at( 0 ).at( 0 );
                    if ( device_info.basic_subtypes_id.isEmpty()
                         || mmap_device_type_info.find( device_info.basic_subtypes_id ) != mmap_device_type_info.end() ) {
                        //qDebug() << "mmap_device_type_info has" << device_info.basic_subtypes_id;
                    } else {
                        DEVTYPEINFO dev_type_info;
                        dev_type_info.s_outline_file_name = outline_list.at( 0 ).at( 2 );//
                        QList< QStringList > info_ana;
                        dev_type_info.s_ana_text = ana_unconde( outline_list.at( 0 ).at( 1 ), info_ana );
                        //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- CCCCCCCCCCC"<<dev_type_info.s_outline_file_name;//<<dev_type_info.s_ana_text;
#ifdef SIZE_320X240
                        dev_type_info.s_ana_text = mp_db->ana_adaptive( dev_type_info.s_ana_text );
#endif
                        add_rule_info( device_info.basic_subtypes_id, dev_type_info, s_device_list.at( 5 ),
                                       s_device_list.at( 8 ), info_ana );
                        mmap_device_type_info.insert( device_info.basic_subtypes_id, dev_type_info );
                        //qDebug() << "device_info add~~~~~~~~~~~~~~" << dev_type_info.s_ana_text << device_info.basic_subtypes_id;
                    }
                }

                device_info.path_list = temp_list_k + QString("/%1").arg( m );

                device_info.local_name = s_device_list.at( 0 ); //device_name
                device_info.device_comment = s_device_list.at( 1 );
                device_info.task_info =
                        replace_covert_char( first_vol_name ) + "-" +//间隔单元名
                        replace_covert_char( s_device_list.at( 9 ) ) + "-" +//设备电压等级
                        replace_covert_char( device_info.local_name ) + "-" +//设备现场名
                        replace_covert_char( device_info.device_comment ) + "-" +//设备注释
                        replace_covert_char( s_device_list.at( 2 ) ) + "-" +//相别
                        replace_covert_char( s_device_list.at( 4 ) ) + "-" +//部位
                        replace_covert_char( s_device_list.at( 3 ) );

                device_info.content = s_device_list.at(10);

                //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 888888888"<<device_info.task_info;
                device_info.task_name = device_info.local_name + device_info.device_comment + s_device_list.at( 2 );
                //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- 999999999"<<device_info.task_name;

                device_info.device_type_id = s_device_list.at( 5 );
                device_info.model_style_id = s_device_list.at( 6 );
                device_info.part_postion_id = s_device_list.at( 7 );
                device_info.device_param_id = s_device_list.at( 8 );
                //qDebug()<<"DeviceList::get_general_task_device_all_info ----------------------------- AAAAAAAAAAA"<<device_info.device_type_id<<device_info.model_style_id<<device_info.part_postion_id <<device_info.device_param_id;

                if( p_status && p_status->n_shooted_pos_list.contains( n_count ) ) {
                    device_info.b_shooted = true;
                } else {
                    device_info.b_shooted = false;
                }
                ++n_count;
                s_info_list.append( device_info );
            }
        }
    }

    int number;
    QString father_str;
    get_regions_name( father_id, number, father_str );
    qDebug()<<"DeviceList::get_general_task_device_all_info   father_id----------------kkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<father_id;
    qDebug()<<"DeviceList::get_general_task_device_all_info   father_str----------------ccccccccccccccccccccccccccc"<<father_str;
    info.task_level = 0;
    info.task_name = father_str;
    int count_number = 0;
    find_node_number_by_father_id( count_number, s_v_zone_vol_grade_list );
    info.down_node_number = count_number;//s_v_zone_vol_grade_list.size();
    info.path_list = "0";
    s_info_list.insert( 0, info );//顶级信息 变电站名

    set_general_task_visible_node( s_info_list ) ;
    GetShootContentList();
//    for( int i = 0; i < s_info_list.count(); i ++ ) {
//        qDebug()  << "task_name:"<< s_info_list.at( i ).task_name
//                  << "task_level:"<< s_info_list.at( i ).task_level
//                  << "down_node_number:" << s_info_list.at( i ).down_node_number
//                  << "path_list:" << s_info_list.at( i ).path_list
//                  << "new_info.basic_subtypes_id" << s_info_list.at( i ).basic_subtypes_id
//                  << "b_child_visible " << s_info_list.at( i ).b_child_visible;
//    }
    for (int i = 0; i < s_info_list.count(); i++) {
        if (s_info_list.at(i).task_level == 1) {
            int count = 0;
            for (int j = i+1; j < s_info_list.count(); j++) {
                if (s_info_list.at(i).task_level == s_info_list.at(j).task_level-1) {
                    count++;
                } else if (s_info_list.at(i).task_level == s_info_list.at(j).task_level) {
                    break;
                }
            }
            TASK_TREE_INFO new_info = s_info_list.at( i );
            new_info.down_node_number = count;
            s_info_list.replace(i, new_info);
        }
    }

#if 0
    for (int i = 0; i < s_info_list.count(); i++) {
        if (s_info_list.at(i).task_level == 0)
            qDebug() << "" << s_info_list.at(i).task_level << ", text :" << s_info_list.at(i).task_name << ", down_node_count :" << s_info_list.at(i).down_node_number;
        else if (s_info_list.at(i).task_level == 1)
            qDebug() << "   " << s_info_list.at(i).task_level << ", text :" << s_info_list.at(i).task_name << ", down_node_count :" << s_info_list.at(i).down_node_number;
        else if (s_info_list.at(i).task_level == 2)
            qDebug() << "      " << s_info_list.at(i).task_level << ", text :" << s_info_list.at(i).task_name << ", down_node_count :" << s_info_list.at(i).down_node_number;
        else if (s_info_list.at(i).task_level == 3)
            qDebug() << "         " << s_info_list.at(i).task_level << ", text :" << s_info_list.at(i).task_name << ", down_node_count :" << s_info_list.at(i).down_node_number;
        else if (s_info_list.at(i).task_level == 4)
            qDebug() << "            " << s_info_list.at(i).task_level << ", text :" << s_info_list.at(i).task_name << ", down_node_count :" << s_info_list.at(i).down_node_number;
    }
#endif
}

QString DeviceList::ana_unconde( QString str, QList< QStringList > &list )
{
    //qDebug() << "#### [DeviceList] [ana_unconde] : str = " << str;

    if( str.isEmpty() ) {
        return "";
    }
    QString ana_out = "";
    QStringList singal_list;
    QStringList str_list = str.split( ";-", QString::SkipEmptyParts );
    for( int i = 0; i < str_list.count(); i++ ) {
        QString signal = "";
        QString signal_str = str_list.at( i );
        int number = signal_str.indexOf( ':' );
        QStringList strlist;
        QString ana_type = signal_str.mid( number + 1, 1 );
        signal = ana_type + signal_str.mid( 0, number ) + signal_str.mid( number + 2 );
        int get_type = 0;
        if( ana_type.compare("P") == 0 ) {
            get_type = 3;
        } else if( ana_type.compare("L") == 0 ) {
            get_type = 2;
        } else if( ana_type.compare("R") == 0 ) {
            get_type = 1;
        }

        strlist.append( QString( "%1" ).arg( get_type ) );
        strlist.append( signal_str.mid( 0, number ) );
        if( list.count() > 0 ) {
            if( strlist.at( 0 ).compare( list.at( list.count() - 1 ).at( 0 ) ) == 0 &&
                    strlist.at( 1 ).compare( list.at( list.count() - 1 ).at( 1 ) ) == 0 ) {
                singal_list.append( signal );
                continue;
            }
        }
        singal_list.append( signal );
        list.append( strlist );
    }
    ana_out = singal_list.join( ";-" ) + ";-";
    return ana_out;
}

void DeviceList::task_get_ana_unit_text( QString model_style_id, QString part_postion_id, QVector<QStringList> &str )
{
    QString s_base_sql = QString("select basic_subtype_id,ana_unit_text, vector_file_path from basic_subtypes"
                                 " left join outlines on basic_subtypes.id = outlines.basic_subtype_id "
                                 "where outlines.model_style_id = '%1' and outlines.part_position_id = '%2'"  ).arg( model_style_id ).arg( part_postion_id );

    mp_db->get_all_data_list( s_base_sql, str );
}

void DeviceList::find_node_number_by_father_id( int &count, QVector<QStringList> str )
{
    QString s_base_sql = QString("select count(*) from regions where (" );
    for( int i = 0; i < str.size(); ++i ) {
        s_base_sql += "id='" + str.at( i ).at( 0 ) + "'";
        if( i < str.size() - 1 ) {
            s_base_sql += " or ";
        }
    }
    s_base_sql += ")";
    //qDebug() << "--> find_node_number_by_father_id cmd : " << s_base_sql;
    QVector<QStringList> str_list;
    mp_db->get_all_data_list( s_base_sql, str_list );
    if( str_list.count() == 1 ) {
        if( str_list.at( 0 ).count() == 1) {
            count = str_list.at( 0 ).at( 0 ).toInt();
        }
    }
}

bool DeviceList::get_regions_name( int number, int &father, QString & regions_str )
{
    int temp = father;
    QString s_sql = QString("select distinct name, parent_id from regions where ( regions.id = %1 )").arg( number );
    QVector<QStringList> str_list;
    mp_db->get_all_data_list( s_sql, str_list );
    if( str_list.count() == 1 ) {
        if( str_list.at( 0 ).count() == 2) {
            regions_str = str_list.at( 0 ).at( 0 );
            father = str_list.at( 0 ).at( 1 ).toInt();
        }
    }
    return ( father != temp );
}


void DeviceList::set_general_task_visible_node(QList<TASK_TREE_INFO> &s_info_list)
{
    for( int i = mn_selected_pos, j = 0; j < m_task_tree_list.count() ; ++j, ++i ) {
        if( i >= m_task_tree_list.count() ) {
            i = i % m_task_tree_list.count();
        }
        if( s_info_list[ i ].down_node_number == 0/* && s_info_list[ i ].b_shooted == false */) {
            mn_selected_pos = i;
            break;
        }
    }

    TASK_TREE_INFO info = s_info_list.at( mn_selected_pos );
    QString s_path = info.path_list;
    QStringList s_list = s_path.split( "/" );

    int n_expand_mode = p_port->get_device_tree_expand_way();

    int n_level1 = -1, n_level2 = -1, n_level3 = -1;
    int n_select_lev1 = s_list.at( 1 ).toInt(), n_select_lev2 = s_list.at( 2 ).toInt(), n_select_lev3 = s_list.at( 3 ).toInt();

    if( n_expand_mode == DEVICE_TREE_EXPAND_BY_AREA ) {
        for( int i=0; i<s_info_list.count(); ++i ) { /*
            if( s_info_list.at( i ).task_level == 1 ) {
                ++n_level1;
                if( n_level1 != n_select_lev1 ) {
                    TASK_TREE_INFO new_info = s_info_list.at( i );
                    new_info.b_child_visible = false;
                    s_info_list.replace( i, new_info );
                }
            }*/
            int n_task_level = s_info_list.at( i ).task_level;
            if( n_task_level == 0 || n_task_level == 1 ) {
                if( n_task_level == 1 ) {
                    ++n_level1;
                    n_level2 = -1;
                    if( n_level1 != n_select_lev1 ) {
                        TASK_TREE_INFO new_info = s_info_list.at( i );
                        new_info.b_child_visible = false;
                        s_info_list.replace( i, new_info );
                    }
                }
                continue;
            } else {
                if( n_task_level == 2) {
                    if(n_task_level == 2) {
                        ++n_level2;
                        n_level3 = -1;
                    }
                    if( !( n_level1 == n_select_lev1 && n_level2 == n_select_lev2 ) ) {
                        TASK_TREE_INFO new_info = s_info_list.at( i );
                        new_info.b_child_visible = false;
                        s_info_list.replace( i, new_info );
                    }
                }
                if( n_task_level == 3 ) {
                    ++n_level3;
                    if( !( n_level1 == n_select_lev1 && n_level2 == n_select_lev2 && n_level3 == n_select_lev3 ) ) {
                        TASK_TREE_INFO new_info = s_info_list.at( i );
                        new_info.b_child_visible = false;
                        s_info_list.replace( i, new_info );
                    }
                }
            }
        }
    } else if( n_expand_mode == DEVICE_TREE_EXPAND_BY_DEVICENAME ){
        for( int i=0; i<s_info_list.count(); ++i ) {
            int n_task_level = s_info_list.at( i ).task_level;

            if( n_task_level == 0 || n_task_level == 1 ) {
                if( n_task_level == 1 ) {
                    ++n_level1;
                    n_level2 = -1;
                    if( n_level1 != n_select_lev1 ) {
                        TASK_TREE_INFO new_info = s_info_list.at( i );
                        new_info.b_child_visible = false;
                        s_info_list.replace( i, new_info );
                    }
                }
                continue;
            } else {
                if( n_task_level == 2 ) {
                    ++n_level2;
                    n_level3 = -1;
                } else if( n_task_level == 3 ) {
                    ++n_level3;
                    if( !( n_level1 == n_select_lev1 && n_level2 == n_select_lev2 && n_level3 == n_select_lev3 ) ) {
                        TASK_TREE_INFO new_info = s_info_list.at( i );
                        new_info.b_child_visible = false;
                        s_info_list.replace( i, new_info );
                    }
                } else {

                }
            }
        }
    } else if( n_expand_mode == DEVICE_TREE_EXPAND_BY_LEVEL ) {
#if 0
        QString str = tr( "Isolating switch" );
        for( int i=0; i<s_info_list.count(); ++i ) {
            int n_task_level = s_info_list.at( i ).task_level;
            if( n_task_level == 3 ) {
                TASK_TREE_INFO new_info = s_info_list.at( i );
                if( new_info.task_name.compare( str ) == 0 )  {
                    new_info.b_child_visible = false;
                    s_info_list.replace( i, new_info );
                }
            }
        }
#endif
    }

}

QVector<SNORMALINFO> DeviceList::get_snormalinfo()
{
    return m_normal_info_vc;
}

QList<TASK_TREE_INFO> DeviceList::get_tree_list_info()
{
    return m_task_tree_list;
}

bool DeviceList::set_task_visible_param() {

    int n_next_selected_pos = mn_selected_pos;

    for( int i = mn_selected_pos + 1, j = 0; j < m_task_tree_list.count() ; ++j, ++i ) {
        if( i >= m_task_tree_list.count() ) {
            i = i % m_task_tree_list.count();
        }

        if( m_task_tree_list[ i ].down_node_number == 0
                /*&& m_task_tree_list[ i ].b_shooted == false */) {
            n_next_selected_pos = i;
            break;
        } else if( m_task_tree_list[ i ].down_node_number == 0  &&  n_next_selected_pos == mn_selected_pos ) {
            n_next_selected_pos = i;
        }
    }

    if( n_next_selected_pos == mn_selected_pos ) {
        mb_child_visible_change = false;
        return false;
    }

    int n_level = m_task_tree_list.at( n_next_selected_pos ).task_level, n_parent_lev = n_level;
    bool b_ret = false;

    for( int i = n_next_selected_pos-1; i>= 0; --i ) {
        int n_prev_level = m_task_tree_list.at( i ).task_level;
        if( n_prev_level == 0 ) {
            break;
        } else {
            if( n_parent_lev == n_prev_level + 1 ) {
                if( !m_task_tree_list.at( i ).b_child_visible ) {
                    TASK_TREE_INFO new_info = m_task_tree_list.at( i );
                    new_info.b_child_visible = true;
                    m_task_tree_list.replace( i, new_info );
                    b_ret = true;
                    ms_child_visible_change_path = new_info.path_list;
                }
                --n_parent_lev;
            }
        }
    }

    mb_child_visible_change = b_ret;
    return b_ret;
}

void DeviceList::next_device_task( bool b_init )
{
    qDebug()<<"DeviceList::next_device_task ----------------------   " << b_init;
    int next_index = -1; //use in shoot ok
    int i = mn_selected_pos;
    if( b_init ) {
        i = mn_selected_pos + 1;
    }
    for( int j = 0; j < m_task_tree_list.count() ; ++j, ++i ) {
        if( i >= m_task_tree_list.count() ) {
            i = i % m_task_tree_list.count();
        }
        if( m_task_tree_list[ i ].down_node_number == 0 ) {
            if( mb_last_diver_over ) {
                mb_last_diver_over = false;
                int temp = mn_selected_pos;
                mn_selected_pos = mn_selected_pos - mb_last_diver_number;
                emit device_shoot_ok( mb_last_diver_post_down, mb_last_diver_number );
                mn_selected_pos = temp;
                //qDebug() << "&&&&&&&emit device_shoot_ok" << mb_last_diver_post_down << mb_last_diver_number;
            } //unflod tree if tree level is shoot over
            mn_selected_pos = i;

            s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
            p_status->n_shoot_pos = i;
            SettingHelp::set_task_pack_status( p_status );
            emit_device_selected();
            emit fold_list_for_path();
            break;
        } else if( next_index == -1 && m_task_tree_list[ i ].down_node_number == 0 && b_init ) {
            next_index = i;
        }
    }
    if( mb_send_over && device_is_save_over() ){
        mb_send_over = false;
        emit device_save_over_sgl();
    }
}

bool DeviceList::device_is_save_over()
{
    for( int j = m_task_tree_list.count() - 1; j > 0; --j ) {
        if( m_task_tree_list[ j ].down_node_number == 0 && m_task_tree_list[ j ].b_shooted == false ) {
            return false;
        }
    }
    return true;
}
//获取点击节点位置函数接口
int DeviceList::get_select_pos()
{
    return mn_selected_pos;
}
//获取节点是否拍摄了的状态---好像和*****get_task_tree_list_node_shoot重复了
bool DeviceList::get_task_pos_is_saved( int n_pos ){
    if( n_pos < 0 || n_pos > m_task_tree_list.length())
        return false;
    return m_task_tree_list[ n_pos ].b_shooted;
}
//*****get_task_tree_list_path
QString DeviceList::get_task_pos_path( int n_pos ){
    if( n_pos < 0 || n_pos > m_task_tree_list.length())
        return "";
    return m_task_tree_list[ n_pos ].path_list;
}


/************************************************************************************
 * @ description : 设备树选择位置设置
 * @ param - pos : 位置
 * @ return      : true-->设置成功  false-->设置失败
 ************************************************************************************/
bool DeviceList::set_select_pos( int pos )
{
    qDebug()<<"DeviceList::set_select_pos ----------- ";
    mn_selected_pos = pos;
    s_task_pack_status_t *p_status = SettingHelp::get_task_pack_status();
    if( p_status->n_shoot_pos != pos /*|| p_port->is_freeze_status()*/ ) {
        p_status->n_shoot_pos = pos;
        SettingHelp::set_task_pack_status( p_status );
        emit_device_selected();
        return true;
    }
    return false;
}

void DeviceList::clear_select_list()
{
    while ( !m_task_tree_list.isEmpty() ) {
        m_task_tree_list.takeFirst();
    }
    m_task_tree_list.clear();
}

QString DeviceList::replace_covert_char(QString str)
{
    return str.replace( "-", "__0" );
}

QString DeviceList::all_replace_covert_char(QString s_text)
{
    //QString s_text = str;

    //s_text.replace( "-", "__0" );
    s_text.replace( "~", "__1" );
    s_text.replace( "`", "__2" );
    s_text.replace( "!", "__3" );
    s_text.replace( "@", "__4" );
    s_text.replace( "#", "__5" );
    s_text.replace( "$", "__6" );
    s_text.replace( "%", "__7" );
    s_text.replace( "^", "__8" );
    s_text.replace( "&", "__9" );
    s_text.replace( "*", "__a" );
    s_text.replace( "(", "__b" );
    s_text.replace( ")", "__c" );
    s_text.replace( "+", "__d" );
    s_text.replace( "=", "__e" );
    s_text.replace( "{", "__f" );
    s_text.replace( "}", "__g" );
    s_text.replace( "[", "__h" );
    s_text.replace( "]", "__i" );
    s_text.replace( "|", "__j" );
    s_text.replace( "\\", "__k" );
    s_text.replace( ":", "__l" );
    s_text.replace( ";", "__m" );
    s_text.replace( "\"", "__n" );
    s_text.replace( "\'", "__o" );
    s_text.replace( "<", "__p" );
    s_text.replace( ">", "__q" );
    s_text.replace( ",", "__r" );
    s_text.replace( ".", "__s" );
    s_text.replace( "?", "__t" );
    s_text.replace( "/", "__u" );
    s_text.replace( " ", "__v" );
    s_text.replace( "__w", "\t" );

    return s_text;
}

TASK_TREE_INFO DeviceList::find_name_by_path( QString str_path, int &number)
{
    for( int i = 0; i < m_task_tree_list.count() ; i++ ) {
        if( m_task_tree_list[ i ].path_list.compare( str_path ) == 0 ) {
            number = i;
            return m_task_tree_list[ i ];
        }
    }

    TASK_TREE_INFO info;

    info.task_name = "";
    number = 0;
    return info;
}

QString DeviceList::get_temp_date_name()
{
    return temp_date_name;
}

bool DeviceList::get_task_tree_node_visible(int n_index)
{
    if( n_index >= 0 && n_index < m_task_tree_list.size() ) {
        return m_task_tree_list.at( n_index ).b_visible;
    }
    return false;
}

bool DeviceList::get_task_tree_node_child_visible(int n_index)
{
    if( n_index >= 0 && n_index < m_task_tree_list.size() - 1 ) {
        if( m_task_tree_list.at( n_index ).down_node_number == 0 ) {
            return false;
        } else {
            return m_task_tree_list.at( n_index ).b_child_visible;
        }
    }
    return false;
}

bool DeviceList::get_child_has_shoot(int n_index)
{
    if( n_index >= 0 && n_index < m_task_tree_list.size() - 1 ) {
        for( int i = n_index; i < m_task_tree_list.count(); i ++ ) {
            if( m_task_tree_list[ i ].path_list.startsWith( m_task_tree_list[ n_index].path_list ) ) {
                if( m_task_tree_list[ i ].b_shooted == false && m_task_tree_list[ i ].down_node_number == 0 ) {
                    return false;
                }
            } else {
                break;
            }
        }
    }
    return true;
}


/************************************************************************************
 * @ description    : 设备树点击响应函数
 * @ param - n_indx : 索引
 * @ return         : flag
 ************************************************************************************/
int DeviceList::tree_node_clicked( int n_indx ) {
    qDebug()<<"DeviceList::tree_node_clicked ------------";
    /* 点击设备索引有效性判断 */
    if( n_indx > 0 && n_indx < m_task_tree_list.size() ) {
        if( m_task_tree_list.at( n_indx ).down_node_number == 0 ) {
            /* 设备树索引设置 */
            set_select_pos( n_indx );
            return 0;
        } else {
            /* 设备树列表状态设置 */
            TASK_TREE_INFO new_info = m_task_tree_list.at( n_indx );
            new_info.b_child_visible = !new_info.b_child_visible;
            m_task_tree_list.replace( n_indx, new_info );

            int list_count = m_task_tree_list.size();
            int i, k = 0;
            int n_click_lev = m_task_tree_list.at( n_indx ).task_level;

            /* 遍历点击位置后的节点 */
            for( i = n_indx+1; i<list_count; ++i ) {
                TASK_TREE_INFO info = m_task_tree_list.at( i );
                if( info.task_level <= n_click_lev ) {
                    break;
                }
                /*must chage*/
                if( !info.b_child_visible && info.down_node_number > 0 ) {
                    if( info.task_level == 3 ) {
                        i = i + info.down_node_number;
                    }else if( info.task_level == 2) {
                        for( int j = i + 1; j < list_count; ++j ) {
                            TASK_TREE_INFO temp = m_task_tree_list.at( j );
                            if( temp.task_level > info.task_level ) {
                                i++;
                            } else {
                                break;
                            }
                        }
                    }
                } else if(info.b_child_visible && info.task_level < 4 && !new_info.b_child_visible) {
                    info.b_child_visible = !info.b_child_visible;
                    m_task_tree_list.replace( i, info );
                }
                if( info.b_visible ) {
                    ++k;
                }
            }

            if( new_info.b_child_visible ) {
                mn_click_child_num = k;
            } else {
                mn_click_child_num = 0 - k;
            }
            return 1;
        }
    }
    return 2;
}


//获取节点名称
QString DeviceList::get_task_tree_list_str( int i )
{
    if( i >= 0 && i < m_task_tree_list.size() ) {
        return m_task_tree_list.at( i ).task_name;
    } else {
        return "";
    }
}

QList<QString> DeviceList::get_info_by_index(int i)
{
    QList<QString> infoList;
    if( i >= 0 && i < m_task_tree_list.size() ) {
#if 0
        qDebug() << "\r\n\r\n\r\n"
                 << "local_name         = " << m_task_tree_list.at(i).local_name << "\r\n"
                 << "task_name          = " << m_task_tree_list.at(i).task_name << "\r\n"
                 << "path_list          = " << m_task_tree_list.at(i).path_list << "\r\n"
                 << "task_info          = " << m_task_tree_list.at(i).task_info << "\r\n"
                 << "device_type_id     = " << m_task_tree_list.at(i).device_type_id << "\r\n"
                 << "model_style_id     = " << m_task_tree_list.at(i).model_style_id << "\r\n"
                 << "part_postion_id    = " << m_task_tree_list.at(i).part_postion_id << "\r\n"
                 << "device_param_id    = " << m_task_tree_list.at(i).device_param_id << "\r\n"
                 << "basic_subtypes_id  = " << m_task_tree_list.at(i).basic_subtypes_id << "\r\n"
                 << "device_comment     = " << m_task_tree_list.at(i).device_comment << "\r\n"
                 << "father_id          = " << m_task_tree_list.at(i).father_id << "\r\n"
                 << "down_node_number   = " << m_task_tree_list.at(i).down_node_number << "\r\n"
                 << "task_level         = " << m_task_tree_list.at(i).task_level
                 << "\r\n\r\n\r\n";
#endif
#if 1
        TASK_TREE_INFO infoPath = m_task_tree_list.at(i);
        if(infoPath.task_level == 0)
            return infoList;
        if(infoPath.task_level == 4) {
            infoList.append(infoPath.task_info);
        } else {
            int index = 1;
            if((i + index) < m_task_tree_list.size()) {
                TASK_TREE_INFO nextPath = m_task_tree_list.at(i + index);
                while(infoPath.task_level != nextPath.task_level) {
                    if(nextPath.task_level == 4)
                        infoList.append(nextPath.task_info);
                    index++;
                    if((i + index) >= m_task_tree_list.size())
                        break;
                    nextPath = m_task_tree_list.at(i + index);
                }
            }
        }
#endif
    }

    return infoList;
}

int DeviceList::get_task_tree_list_node_number( int i )
{
    if( i >= 0 && i < m_task_tree_list.size() ) {
        return m_task_tree_list.at(i).down_node_number;
    } else {
        return 0;
    }
}
//得到节点等级
int DeviceList::get_task_tree_list_node_level( int i )
{
    if( i >= 0 && i < m_task_tree_list.size() ) {
        return m_task_tree_list.at( i ).task_level;
    } else {
        return 0;
    }
}
//获取节点是否拍摄了的状态
bool DeviceList::get_task_tree_list_node_shoot( int i )
{
    if( i >= 0 && i < m_task_tree_list.size() ) {
        return m_task_tree_list.at( i ).b_shooted;
    } else {
        return false;
    }
}
//获取节点数量
int DeviceList::get_task_tree_list_count()
{
    return m_task_tree_list.count();
}

QString DeviceList::get_task_tree_list_path( int i  )
{
    if( i >= 0 && i < m_task_tree_list.size() ) {
        return m_task_tree_list.at( i ).path_list;
    } else {
        return "";
    }
}

bool DeviceList::get_task_select_info( int temp )
{
    if( mn_selected_pos >= 0 && mn_selected_pos < m_task_tree_list.count()
            && temp >= 0 && temp < m_task_tree_list.count() ) {
        if( m_task_tree_list.at( mn_selected_pos ).path_list.startsWith( m_task_tree_list.at( temp ).path_list ) ) {
            return true;
        }
    }
    return false;
}

bool DeviceList::get_task_select_info( int temp, int temp1 )
{
    if( temp1 >= 0 && temp1 < m_task_tree_list.count()
            && temp >= 0 && temp < m_task_tree_list.count() ) {
        if( m_task_tree_list.at( temp1 ).path_list.startsWith( m_task_tree_list.at( temp ).path_list + "/" ) ) {
            return true;
        }
    }
    return false;
}

int DeviceList::get_task_child_level( int i )
{
    chose_list.clear();
    if( i >= 0 && i < m_task_tree_list.size() ) {

        QString str = m_task_tree_list.at( i ).path_list;
        int level = m_task_tree_list.at( i ).task_level;
        int number = 0;
        for( int j = i + 1; j < m_task_tree_list.size(); j++ ) {
            if( m_task_tree_list.at( j ).path_list.startsWith( str )   ) {
                if( m_task_tree_list.at( j ).task_level - level == 1 ||
                        ( m_task_tree_list.at( j ).task_level - level == 2 && m_task_tree_list.at( j ).task_level == 4) ) {
                    chose_list.append( j );
                    number++;
                }
            } else {
                break;
            }
        }
        return number;

    } else {
        return 0;
    }
}

int DeviceList::get_task_child_leve_data_id( int i )
{
    if( i >= 0 && i < chose_list.size() ) {
        return chose_list.at( i );
    } else {
        return -1;
    }
}

QString DeviceList::get_up_level_name( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return "";
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        if( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() - 1 < 0) {
            return "";
        }
        QString temp_str = QString( "%1%2" ).arg( str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() - 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return info.task_name;
        } else {
            return "";
        }
    }
    return "";
}

int DeviceList::get_up_level_index( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1%2" ).arg(str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() - 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return number;
        } else {
            return 0;
        }
    }
    return 0;
}

QString DeviceList::get_up_level_unflod( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1%2" ).arg(str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() - 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return info.path_list;
        } else {
            return 0;
        }
    }
    return 0;
}

QString DeviceList::get_down_level_name( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return "";
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1%2" ).arg(str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() + 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return info.task_name;
        } else {
            return "";
        }
    }
    return "";
}

int DeviceList::get_down_level_index( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1%2" ).arg(str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() + 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return number;
        } else {
            return 0;
        }
    }

    return 0;
}

QString DeviceList::get_cur_level_name( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return "";
    }
    return m_task_tree_list.at( temp ).task_name;
    return "";
}

int DeviceList::get_cur_level_index( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    QStringList list = str.split( '/' );
    if( list.count() == 5 ) {
        list.removeAt( 4 );
        list.removeAt( 3 );
    }
    str = list.join('/');
    int number = 0;
    TASK_TREE_INFO info = find_name_by_path( str, number );
    if( info.task_level == 2 ) {
        return number;
    } else {
        return 0;
    }
    return 0;
}

QString DeviceList::get_down_level_unflod( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1%2" ).arg(str.mid( 0, str.lastIndexOf( '/') + 1 ) ).arg( str.mid( str.lastIndexOf( '/' ) + 1 ).toInt() + 1 );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        if( info.task_level == 2 ) {
            return info.path_list;
        } else {
            return 0;
        }
    }
    return 0;
}

int DeviceList::get_back_level_index( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1" ).arg( str.mid( 0, str.lastIndexOf( '/') ) );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        return number;
    }
    return 0;
}

QString DeviceList::get_back_level_unflod( int temp )
{
    if( temp >= m_task_tree_list.count() || temp < 0 ) {
        return 0;
    }
    QString str =  m_task_tree_list.at( temp ).path_list;
    if( str.lastIndexOf( '/') != 0 ) {
        QString temp_str = QString( "%1" ).arg(str.mid( 0, str.lastIndexOf( '/') ) );
        int number = 0;
        TASK_TREE_INFO info = find_name_by_path( temp_str, number );
        return info.path_list;
    }
    return 0;
}

bool DeviceList::has_path_father( QString path, int curr )
{
    if( curr >= m_task_tree_list.count() || curr < 0 ) {
        return false;
    }
    QString str = m_task_tree_list.at( get_cur_level_index( curr ) ).path_list;
    if( m_task_tree_list.at( curr ).task_level == 2 ) {
        if( path.startsWith( str ) ) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
    return false;
}

bool DeviceList::is_same_voltage_level( QString path, int curr )
{
    if( curr >= m_task_tree_list.count() || curr < 0 ) {
        return false;
    }
    QString str = m_task_tree_list.at( get_cur_level_index( curr ) ).path_list;
    QStringList path_list = path.split( '/' );
    QStringList str_list = str.split( '/' );
    if( path_list.count() >= 2 && str_list.count() >= 2 ) {
        if( path_list.at( 0 ).compare( str_list.at( 0 )) == 0 &&
                path_list.at( 1 ).compare( str_list.at( 1 )) == 0 ) {
            return true;
        }
    }
    return false;
}

bool DeviceList::tree_had_shoot()
{
    for( int i = 0; i < m_task_tree_list.count(); ++i ) {
        if( m_task_tree_list.at( i ).b_shooted == true ) {
            return true;
        }
    }
    return false;
}
//ShootContentList 0:设备电压等级 1:设备类型 2:设备现场名 3:设备现场名备注 4:相别 5:设备型号 6:部位角度
void DeviceList::GetShootContentList()
{
    if( mp_db == NULL )
        mp_db = new DatabaseOp( p_port->get_taskpack_db_name() );
    mp_db->GetShootContentList(ShootContentVector);
}
//得到拍摄内容设置
QStringList DeviceList::GetShootContent(int i)
{
    return ShootContentVector.at(i);
}


bool DeviceList::is_head_pos(QString text)
{
    for(int index = 0; index < m_task_tree_list.count(); index++) {
        TASK_TREE_INFO tmp_tree_info = m_task_tree_list.at(index);
        if(tmp_tree_info.task_name == text) {
            if(index == 0) {
                return true;
            }
            TASK_TREE_INFO last_tree_info = m_task_tree_list.at(index - 1);
            if(last_tree_info.task_level == tmp_tree_info.task_level)
                return false;
            else
                return true;
        }
    }
    return false;
}

bool DeviceList::is_tail_pos(QString text)
{
    for(int index = 0; index < m_task_tree_list.count(); index++) {
        TASK_TREE_INFO tmp_tree_info = m_task_tree_list.at(index);
        if(tmp_tree_info.task_name == text) {
            if(index == (m_task_tree_list.count() - 1)) {
                return true;
            }
            TASK_TREE_INFO next_tree_info = m_task_tree_list.at(index + 1);
            if(next_tree_info.task_level == tmp_tree_info.task_level)
                return false;
            else
                return true;
        }
    }
    return false;
}


/***************************************************************
 * @ description   : 获取当前项之前有多少已收起的项
 * @ param - index : 当前项
 * @ return        : 收起的项数量
 ***************************************************************/
int DeviceList::get_packup_count(int index)
{
    int count = 0;
    for(int i = 0; i < index; i++) {
        if(!m_task_tree_list.at(i).b_child_visible) {
            int temp_i = i;
            for(int j = i + 1; j < index; j++) {
                if(m_task_tree_list.at(temp_i).task_level < m_task_tree_list.at(j).task_level) {
                    i++;
                    count++;
                } else {
                    break;
                }
            }
        }
    }

    return count;
}


/***************************************************************
 * @ description   : 获取下一项索引
 * @ param - index : 当前项
 * @ return        : 下一项
 ***************************************************************/
int DeviceList::get_next_index(int index)
{
#if 1
    int temp_index = index + 1;
    for(int i = 0; i < m_task_tree_list.at(index + 1).task_level - 1; i++) {
        for(int j = temp_index - 1; j >= 0; j--) {
            if(m_task_tree_list.at(j).task_level < m_task_tree_list.at(temp_index).task_level) {
                if(! m_task_tree_list.at(j).b_child_visible)
                    temp_index = j;
                break;
            }
        }
    }

    if(temp_index < index + 1) {
        for(int i = temp_index + 1; i < m_task_tree_list.count(); i++) {
            if(m_task_tree_list.at(i).task_level <= m_task_tree_list.at(temp_index).task_level)
                return i;
        }
    }

    return temp_index;
#endif
}


/***************************************************************
 * @ description   : 获取上一项索引
 * @ param - index : 当前项
 * @ return        : 上一项
 ***************************************************************/
int DeviceList::get_pre_index(int index)
{
    int temp_index = index - 1;
    int temp_index_2 = temp_index;
    for(int i = 0; i < m_task_tree_list.at(index - 1).task_level - 1; i++) {
        for(int j = temp_index_2 - 1; j >= 0; j--) {
            if (m_task_tree_list.at(j).task_level < m_task_tree_list.at(temp_index_2).task_level) {
                if(! m_task_tree_list.at(j).b_child_visible)
                    temp_index = j;
                temp_index_2 = j;
                break;
            }
        }
    }

    return temp_index;
}


/*****************************************************************
 * @ description   : 获取父节点索引
 * @ param - index : 子节点索引
 * @ return        : 父节点索引
 *****************************************************************/
int DeviceList::get_father_index(int index)
{
    int ret = index;
    if(index < 0 || index >= m_task_tree_list.count())
        return ret;
    if(m_task_tree_list.at(index).task_level < 2)
        return ret;

    for(int i = index - 1; i >= 0; i--) {
        if(m_task_tree_list.at(i).task_level < m_task_tree_list.at(index).task_level)
            return i;
    }
}























