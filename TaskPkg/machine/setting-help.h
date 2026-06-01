#ifndef SETTINGHELP_H
#define SETTINGHELP_H

#include <QObject>
#include <QCoreApplication>
#include <QStringList>
#include "yfjsonaccess.h"

// 任务包名称、所选择的设备区和设备类型，当前拍摄位置、已拍摄的设备树位置信息、展开方式到配置文件中
typedef struct {
    QString s_pack_name;
    QStringList s_sel_device_zone_list;
    QStringList s_sel_device_type_list;
    int n_shoot_pos;
    QList<int> n_shooted_pos_list;
    int n_expand_way;
} s_task_pack_status_t;

class SettingHelp : public QObject
{
    Q_OBJECT
public:
    explicit SettingHelp(QObject *parent = 0);
    ~SettingHelp();
    Q_INVOKABLE static void checkout_setting_conf( );
    Q_INVOKABLE static void set_value( QString s_key, QString s_value );
    Q_INVOKABLE static QString get_key_value( QString s_key, QString s_default="" );

    //task
    static QString get_province_name() { return mstr_provice_name; }
    static void set_province_name( QString str ) { mstr_provice_name = str; }
    static s_task_pack_status_t* get_task_pack_status();
    static void set_task_pack_status( s_task_pack_status_t *p_status );

    static bool get_show_type() { return false; }
signals:

public slots:
private:
    static bool mb_show_ir_video;
    static bool mb_save_all_video;
    static bool mb_inited;

    static QString ms_file_name;
    static QString mstr_provice_name;
    static s_task_pack_status_t ms_task_pack_status;

    static bool init_params();
    static bool init_task_status_params( YFJsonAccess &json_access );
};

#endif // SETTINGHELP_H
