#ifndef DEVICELIST_H
#define DEVICELIST_H

#include "config.h"
#include <QVector>
#include <QMap>
#include <QPair>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include "qobject.h"
class QmlPort;
class DatabaseOp;

typedef struct RULEINFO{
    int n_error_type;
    QString ana_other_name;
    QString s_rule;
    QString s_rule_title;
    QString s_rule_formula;
    QString s_rule_text;
}RULEINFO;
typedef struct DEVTYPEINFO{
    QString s_outline_file_name;
    QString s_ana_text;
    QVector<RULEINFO> vc_rules;
}DEVTYPEINFO;
typedef QPair< QString, DEVTYPEINFO > DEVTYPE_PAIR;

typedef struct{
    QString s_outline_file_name;
    QString s_ana;
    QVector<RULEINFO> rule_vc;
}SOUTLINERULEINFO;
typedef struct{
    QString s_dev_type;
    int n_sel_index;
    QVector<SOUTLINERULEINFO> outline_rule_vc;
}SDEVTYPEINFO;
typedef struct{
    QString s_vol;
    bool b_expand;
    QVector<SDEVTYPEINFO> dev_type_vc;
}SNORMALINFO;

typedef struct {
    QString local_name;
    QString task_name;
    QString path_list;
    QString task_info;

    QString device_type_id;
    QString model_style_id;
    QString part_postion_id;
    QString device_param_id;

    QString basic_subtypes_id;
    QString device_comment;
    int father_id;
    int down_node_number;
    int task_level;
    bool b_shooted;
    bool b_visible;
    bool b_child_visible;
    QString content;
}TASK_TREE_INFO;


class DeviceList : public QObject
{
    Q_OBJECT
public:
    explicit DeviceList(QObject *parent = 0);
    ~DeviceList();
    void set_title( QString s_title, bool b_need_update=false );
    void set_device_zone_list( QStringList s_device_zone_list, bool b_need_update=false );
    void set_device_type_list(QStringList s_device_type_list, bool b_need_update=false , bool b_restore_last_shoot_task=false, bool b_restore_last_shoot_pos=false);
    void turn_page( bool is_up );
    bool can_turn_page( bool is_up );
    QStringList get_fault_nature_list();
    bool can_turn_line( bool is_up );
    bool can_turn_back_layer();
    QString get_ir_image_file_name( bool b_general_mode, bool b_device_info = false );
    void set_shooted();
    void set_list_data( bool b_restore_last_shoot_task=false, bool b_restore_last_shoot_pos=false );

    void init_tree_for_list();
    QVector<SNORMALINFO> get_snormalinfo();
    QList<TASK_TREE_INFO>get_tree_list_info();
    QMap< QString, DEVTYPEINFO > get_map_device_type_info() { return mmap_device_type_info; }
    void next_device_task( bool flag = true );
    int get_select_pos();
    QString get_task_pos_path( int n_pos );
    bool set_select_pos( int );
    bool get_task_pos_is_saved( int pos);
    void clear_select_list();
    QString replace_covert_char(QString str);
    QString all_replace_covert_char(QString s_text);
    TASK_TREE_INFO find_name_by_path( QString str_path, int &i );
    TASK_TREE_INFO get_select_device( );
    QList<QString> get_info_by_index(int i);
    QString get_temp_date_name();

    bool get_task_tree_node_visible(int n_index);
    bool get_task_tree_node_child_visible(int n_index);
    bool get_child_has_shoot(int n_index);
    int tree_node_clicked( int n_indx );
    QString get_task_tree_list_str( int i );
    int get_task_tree_list_node_number( int i );
    int get_task_tree_list_node_level( int i );
    bool get_task_tree_list_node_shoot( int i );
    int get_task_tree_list_count();
    QString get_task_tree_list_path( int i  );
    bool get_child_visible_change() { return mb_child_visible_change; }
    int get_click_child_num() { return mn_click_child_num; }
    QString get_child_visible_change_path() { return ms_child_visible_change_path; }
    bool device_is_save_over();
    void emit_device_selected();
    int get_task_child_level( int );
    bool get_task_select_info( int );
    bool get_task_select_info( int temp, int temp1 );
    int get_task_child_leve_data_id( int i );
    QString get_up_level_name( int );
    int get_up_level_index( int );
    QString get_up_level_unflod( int );

    QString get_down_level_name( int );
    int get_down_level_index( int );
    QString get_cur_level_name( int );
    int get_cur_level_index( int );
    QString get_down_level_unflod( int );
    int get_back_level_index( int );
    QString get_back_level_unflod( int );
    bool has_path_father( QString path, int curr );
    bool is_same_voltage_level( QString, int curr );
    bool tree_had_shoot();
    void GetShootContentList();
    QStringList GetShootContent(int i);

    bool is_head_pos(QString text);
    bool is_tail_pos(QString text);

    /* 获取当前选择的设备信息 */
    DEVTYPEINFO get_curDevInfo();

    int get_packup_count(int index);
    int get_next_index(int index);
    int get_pre_index(int index);
    void set_expand_way(int way);
    int get_father_index(int index);

signals:
    //void common_task_selected( QString, QString );
    //void common_task_selected( QStringList );
    void device_selected( QString );
    void outline_ana_selected( QStringList, QStringList );
    void fold_list_for_path();
    void device_save_over_sgl();
    void device_tree_ready();
    void level_tree_init();
    void device_save_change();
    void device_shoot_ok( int, int );
public slots:
private:
    int mn_first_line_pos;
    int mn_selected_pos;
    int mn_title_height;
    int mn_line_height;
    int mn_lines;
    int mn_show_layer;
    bool mb_last_diver_over;
    int mb_last_diver_post_down;
    int mb_last_diver_number;
    QString ms_title;
    QStringList ms_device_zone_list;
    QStringList ms_device_type_list;
    QStringList ms_list;

    QStringList ms_fault_nature_list; //g_vc_fault_type
    bool mb_has_setting_table;
    float mf_database_ver;
    DatabaseOp *mp_db = NULL;
    //QStringList ms_devie_zone_vollev_list;
    QList<bool> mb_has_child_list;
    QList<int> mn_has_shooted_list;
    QMap< QString, DEVTYPEINFO > mmap_device_type_info;
    QVector<SNORMALINFO> m_normal_info_vc;
    QVector<QString> ms_volt_vc;
    QString ms_selected_volt;
    QString ms_selected_zone_name;
    void get_fault_nature_list_bydb();
    int get_taskpack_mode();

//    #ifdef AUTOANALYSE
    void add_rule_info( QString s_outline_id, DEVTYPEINFO &dev_type_info, QString, QString, QList< QStringList> );
//    #endif
    void clear_device_type_info(); //mmap_device_type_info

    void get_vol_dev_type( const QString& s_id, SNORMALINFO &normal_info );
    void get_dev_sub_types( const QString& s_vol_id, const QString& s_dev_id, SDEVTYPEINFO &dev_info );
    void get_outline_rule( const QString& s_outline_file_name, SOUTLINERULEINFO &outline_rule );
    void quicksort( QVector<RULEINFO>& vint, int fitst, int end);
    QString get_version_str();
    QString get_time_str();
    QString ana_unconde( QString, QList< QStringList> & );
    void task_get_ana_unit_text( QString device_type_id, QString device_param_id, QVector<QStringList> &str );
    void get_general_task_device_all_info( QList<TASK_TREE_INFO> & s_info_list, bool b_restore_last_shoot_task, bool b_restore_last_shoot_pos );
    bool get_regions_name( int number, int &father, QString & regions_str );
    void find_node_number_by_father_id( int &father, QVector<QStringList> );
    void set_general_task_visible_node( QList<TASK_TREE_INFO> &s_info_list );
    bool set_task_visible_param();

    QVector<QStringList> ms_dev_info_list;
    QVector<QStringList> ShootContentVector;
    QStringList ShootContentList;

    QList<TASK_TREE_INFO> m_task_tree_list;
    //QList<TASK_TREE_INFO> m_tmp_task_tree_list;
    QString temp_date_name;

    bool mb_child_visible_change;
    int mn_click_child_num;
    QString ms_child_visible_change_path;
    QmlPort *p_port;
    bool mb_send_over;
    QList< int > chose_list;
};

#endif // DEVICELIST_H
