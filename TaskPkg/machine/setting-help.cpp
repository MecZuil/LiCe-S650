#include "setting-help.h"
#include <QCoreApplication>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

QString SettingHelp::ms_file_name = QCoreApplication::applicationDirPath() + "/setting.conf";
bool SettingHelp::mb_inited = false;
bool SettingHelp::mb_show_ir_video;
bool SettingHelp::mb_save_all_video;
QString SettingHelp::mstr_provice_name;
s_task_pack_status_t SettingHelp::ms_task_pack_status;

SettingHelp::SettingHelp(QObject *parent) : QObject(parent)
{
    //返回包含应用程序可执行文件的目录applicationDirPath
    ms_file_name = QCoreApplication::applicationDirPath() + "/setting.conf";
    checkout_setting_conf( );
}

void SettingHelp::checkout_setting_conf()
{
    QFile file_write( ms_file_name );
    //如果文件已经存在则退出
    if( file_write.exists() ) {
        return;
    }
    QJsonObject json_object;
    json_object.insert( "uv_gain", QString("0") );
    json_object.insert( "brightness_mode", QString("normal brightness") );
    json_object.insert("hdmi_output", QString("yes"));
    json_object.insert("temperature_humid", QString("yes"));

    json_object.insert("task_pack_name", QString(""));
    json_object.insert("sel_device_zone", QString(""));
    json_object.insert("sel_device_type", QString(""));
    json_object.insert("curr_shoot_pos", QString(""));
    json_object.insert("shooted_pos", QString(""));
    QJsonDocument json_doc( json_object );
    if( !file_write.open( QFile::WriteOnly | QFile::Text ) ) {
        return;
    }
    file_write.write( json_doc.toJson() );
    file_write.close();
}

void SettingHelp::set_value( QString s_key, QString s_value )
{
    checkout_setting_conf( );
    QFile file_read( ms_file_name );
    QJsonDocument json_doc = QJsonDocument();
    if( !file_read.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        return;
    }
    QByteArray arr = file_read.readAll();
    file_read.close();
    json_doc = QJsonDocument::fromJson( arr );
    QJsonObject item = json_doc.object();
    item.insert( s_key, s_value );
    QJsonDocument json_doc_write( item );
    QFile file_save( ms_file_name );
    if( !file_save.open( QIODevice::WriteOnly ) ) {
        return;
    }
    file_save.write( json_doc_write.toJson() );
    file_save.close();
}

QString SettingHelp::get_key_value( QString s_key, QString s_default )
{
    checkout_setting_conf( );
    QJsonDocument json_doc = QJsonDocument();
    QFile file_read( ms_file_name );
    if( !file_read.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        return s_default;
    }
    QByteArray arr = file_read.readAll();
    file_read.close();
    QJsonValue js_value;
    json_doc = QJsonDocument::fromJson( arr );
    QJsonObject item = json_doc.object();
    if( item.contains( s_key ) ) {
        js_value = item.value( s_key );
        return js_value.toString();
    } else {
        return s_default;
    }
}

SettingHelp::~SettingHelp()
{

}

s_task_pack_status_t *SettingHelp::get_task_pack_status()
{
    if( !mb_inited ) {
        mb_inited = SettingHelp::init_params();
    }
    return &ms_task_pack_status;
}

void SettingHelp::set_task_pack_status(s_task_pack_status_t *p_status)
{
    if( p_status == NULL ) return ;

    bool b_ret;
    QString s_pkg_dst_dir = QCoreApplication::applicationDirPath() +"/setting.conf" ;
    YFJsonAccess json_access ( s_pkg_dst_dir );
    b_ret = json_access.set_value( "task_pack_name", (QJsonValue)p_status->s_pack_name );

    QString s_tmp = "";
    for( int i=0; i<p_status->s_sel_device_zone_list.size(); ++i ) {
        s_tmp += p_status->s_sel_device_zone_list.at( i );
        if( i != p_status->s_sel_device_zone_list.size() - 1 ) {
            s_tmp += ";";
        }
    }
    json_access.set_value( "sel_device_zone", (QJsonValue)s_tmp );

    s_tmp = "";
    for( int i=0; i<p_status->s_sel_device_type_list.size(); ++i ) {
        s_tmp += p_status->s_sel_device_type_list.at( i );
        if( i != p_status->s_sel_device_type_list.size() - 1 ) {
            s_tmp += ";";
        }
    }
    json_access.set_value( "sel_device_type", (QJsonValue)s_tmp );

    s_tmp = QString::number( ms_task_pack_status.n_shoot_pos );
    json_access.set_value( "curr_shoot_pos", (QJsonValue)s_tmp );

    s_tmp = "";
    for( int i=0; i<p_status->n_shooted_pos_list.size(); ++i ) {
        s_tmp += QString::number( p_status->n_shooted_pos_list.at( i ) );
        if( i != p_status->n_shooted_pos_list.size() - 1 ) {
            s_tmp += ";";
        }
    }
    json_access.set_value( "shooted_pos", (QJsonValue)s_tmp );

    s_tmp = QString::number( ms_task_pack_status.n_expand_way );
    json_access.set_value( "task_expand_way", (QJsonValue)s_tmp );

    if( b_ret && p_status != &ms_task_pack_status ) {
        ms_task_pack_status.n_expand_way = p_status->n_expand_way;
        ms_task_pack_status.n_shooted_pos_list = p_status->n_shooted_pos_list;
        ms_task_pack_status.n_shoot_pos = p_status->n_shoot_pos;
        ms_task_pack_status.s_pack_name = p_status->s_pack_name;
        ms_task_pack_status.s_sel_device_type_list = p_status->s_sel_device_type_list;
        ms_task_pack_status.s_sel_device_zone_list = p_status->s_sel_device_zone_list;
    }
}

bool SettingHelp::init_params()
{
    QString s_pkg_dst_dir = QCoreApplication::applicationDirPath() +"/setting.conf" ;
    YFJsonAccess read_param ( s_pkg_dst_dir );
//    QJsonValue s_value;
//    read_param.get_value( "show_type", s_value);
//    QString s_show_type = s_value.toString();
//    if( s_show_type == "show_visible" ) {
//        mb_show_ir_video = false;
//    } else {
//        mb_show_ir_video = true;
//    }

//    read_param.get_value( "save_both_infrared_and_visible_light", s_value);
//    QString s_save_type = s_value.toString();
//    if( s_save_type == "yes" ) {
//        mb_save_all_video = true;
//    } else {
//        mb_save_all_video = false;
//    }

#ifdef A381_SOFT
    mb_save_all_video = false;
    mb_show_ir_video = true;
#endif

    init_task_status_params( read_param );
    return true;
}
// 任务包名称、所选择的设备区和设备类型，当前拍摄位置、已拍摄的设备树位置信息、展开方式到配置文件中
/*typedef struct {
    QString s_pack_name;
    QStringList s_sel_device_zone;
    QStringList s_sel_device_type;
    unsigned int n_shoot_pos;
    QList<int> n_shooted_pos;
    int n_expand_way;
} s_task_pack_status_t;
*/
bool SettingHelp::init_task_status_params(YFJsonAccess &json_access)
{
    QJsonValue s_value;
    json_access.get_value( "task_pack_name", s_value);
    ms_task_pack_status.s_pack_name = s_value.toString( "" );

    QString s_tmp;
    json_access.get_value( "sel_device_zone", s_value);
    s_tmp = s_value.toString( "" );
    if( !s_tmp.isEmpty() ) {
        ms_task_pack_status.s_sel_device_zone_list = s_tmp.split( ";" );
    }

    json_access.get_value( "sel_device_type", s_value);
    s_tmp = s_value.toString( "" );
    if( !s_tmp.isEmpty() ) {
        ms_task_pack_status.s_sel_device_type_list = s_tmp.split( ";" );
    }

    json_access.get_value( "curr_shoot_pos", s_value);
    s_tmp = s_value.toString( "" );
    if( !s_tmp.isEmpty() ) {
        ms_task_pack_status.n_shoot_pos = s_tmp.toInt( 0 );
    } else {
        ms_task_pack_status.n_shoot_pos = 0;
    }

    json_access.get_value( "shooted_pos", s_value);
    s_tmp = s_value.toString( "" );
    if( !s_tmp.isEmpty() ) {
        QStringList s_list = s_tmp.split( ";" );
        for( int i=0; i<s_list.size(); ++i ) {
            ms_task_pack_status.n_shooted_pos_list << s_list.at( i ).toInt( 0 );
        }
    }

    json_access.get_value( "task_expand_way", s_value);
    s_tmp = s_value.toString( "" );
    if( !s_tmp.isEmpty() ) {
        ms_task_pack_status.n_expand_way = s_tmp.toInt( 0 );
    } else {
        ms_task_pack_status.n_shoot_pos = 0;
    }
    return true;
}
