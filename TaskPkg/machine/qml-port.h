#ifndef QMLPORT_H
#define QMLPORT_H

#include <QObject>
#include <QMap>
#include <QTime>
#include <QTimer>
#include <QDir>

#include "formula.h"
#include "select-task-dlg.h"
#include "device-list.h"
#include "hi384_protocol.h"

#define TASKPACK_MODE_BY_DEVICE 0
#define TASKPACK_MODE_BY_SUB_INTERVAL 1
#define TASKPACK_MODE_BY_LINE_TOWER 2
//class Registry;
class GeneralModeDlg;
class DeviceList;
//class FileWatcher;
//class WifiServer;
typedef enum {
    DEVICE_TREE_EXPAND_BY_LEVEL = 0,
    DEVICE_TREE_EXPAND_BY_AREA = 1,
    DEVICE_TREE_EXPAND_BY_DEVICENAME = 2
}device_tree_expand_way_e;

class QmlPort : public QObject
{
    Q_OBJECT
public:
    explicit QmlPort(QObject *parent = 0);
    ~QmlPort();
    Q_INVOKABLE int get_storage_info( const char * psz_mount_point, int *np_capacity, int type );
    Q_INVOKABLE int has_sd_available_space( );
    Q_INVOKABLE int is_sd_iswritable( );
    Q_INVOKABLE bool is_inserted_sd( );
    Q_INVOKABLE int get_uv_gain(int n_value );
    Q_INVOKABLE QString get_video_time(int n_video_time);
    Q_INVOKABLE void get_video_start_time( );
    Q_INVOKABLE QString get_video_file_name();
    Q_INVOKABLE int get_denoice_value( int n_value );
    Q_INVOKABLE int get_transparent_value( int n_value );

    Q_INVOKABLE void set_mode_save_status(QString s_btn_name, bool b_machine_info, bool b_alarm_status , bool b_laser_status);
    Q_INVOKABLE bool get_mode_save_status( QString s_btn_name, int n_index );
    Q_INVOKABLE int get_mode_save_status_count( QString s_btn_name );
    Q_INVOKABLE void init_mode_save_status();

    Q_INVOKABLE int get_keyValue_from_up();
    Q_INVOKABLE int get_keyValue_from_down();
    Q_INVOKABLE int get_keyValue_from_left();
    Q_INVOKABLE int get_keyValue_from_right();
    Q_INVOKABLE int get_keyValue_from_center();
    Q_INVOKABLE int get_keyValue_from_return();

    //task package
    void init_select_taskpack_dlg();
    Q_INVOKABLE void reinit_select_taskpack_dlg();
    Q_INVOKABLE int get_btns();

    Q_INVOKABLE int get_task_number();
    Q_INVOKABLE bool get_task_selected( int n_seq );
    Q_INVOKABLE QString get_task_text( int n_seq );
    Q_INVOKABLE int compont_firm_code( int n_seq, QString str );
    Q_INVOKABLE void task_clicked( int n_seq );

    Q_INVOKABLE int get_task_type_number();
    Q_INVOKABLE bool get_task_type_selected( int n_seq );
    Q_INVOKABLE QString get_task_type_text( int n_seq );
    Q_INVOKABLE void task_type_clicked( int n_seq );
    Q_INVOKABLE void select_all_task_type_clicked();
    Q_INVOKABLE void select_no_task_type_clicked();
    Q_INVOKABLE bool is_task_type_select_all();
    Q_INVOKABLE bool is_task_type_selectded();

    Q_INVOKABLE int get_task_area_number();
    Q_INVOKABLE bool get_task_area_selected( int n_seq );
    Q_INVOKABLE QString get_task_area_text( int n_seq );
    Q_INVOKABLE void task_area_clicked( int n_seq );
    Q_INVOKABLE void select_all_task_area_clicked();
    Q_INVOKABLE void select_no_task_area_clicked();
    Q_INVOKABLE bool is_task_area_select_all();
    Q_INVOKABLE bool is_task_area_selectded();

    Q_INVOKABLE void set_taskpack_cell_selected( int n_index );
    Q_INVOKABLE void set_taskpack_cell_byname( QString s_name );
    Q_INVOKABLE bool delete_task_pack( int n_index );
    Q_INVOKABLE bool restore_last_shoot_status(bool b_restore_last_shoot_pos);
    Q_INVOKABLE int get_restore_shoot_status_flag();
    Q_INVOKABLE int get_restore_last_shoot_status_flag() { return mn_restore_last_task_status_flag; }
    Q_INVOKABLE void set_restore_last_shoot_status_flag( int n_flag ) { mn_restore_last_task_status_flag = n_flag; }

    void delete_task_pack_slot( QString s_pack_fn );
    void set_task_mode( bool b_general );
    void set_taskpack_db_name( QString s_db_name );
    int set_screenSize(int id);

    //device tree expand way
    Q_INVOKABLE QString get_taskpack_db_name() { return ms_taskpack_db_name; }
    Q_INVOKABLE int get_device_tree_expand_way() { return mn_expand_way; }
    Q_INVOKABLE QString get_mac_serial();
    /* 设备树展开方式设置 */
    Q_INVOKABLE void set_device_tree_expand_way( int n_expand_way );
    int get_taskpack_mode() { return mn_task_mode; }
    QString get_task_version();
    Q_INVOKABLE bool get_task_general_mode() { return mb_general_mode; }
    void set_taskpack_name( QString s_taskpack_name ) { ms_taskpack_name = s_taskpack_name; }
    void set_device_zone_list( QStringList s_dev_zone_list );
    void set_device_type_list( QStringList s_dev_type_list, bool b_restore_last_shoot_task = false, bool b_restore_last_shoot_pos = false );
    Q_INVOKABLE void emit_start_parse_task_pack();
    Q_INVOKABLE int get_click_child_num();
    Q_INVOKABLE void tree_turn_next();

    //device tree
    Q_INVOKABLE int tree_node_clicked( int n_indx );
    Q_INVOKABLE QString get_current_img_name();

    Q_INVOKABLE QString get_task_tree_list_str( int i );
    Q_INVOKABLE int get_task_tree_list_node_number( int i );
    Q_INVOKABLE int get_task_tree_list_count();
    Q_INVOKABLE QString get_task_tree_list_path( int i );
    Q_INVOKABLE int get_task_tree_list_node_level( int i );
    Q_INVOKABLE bool get_task_tree_list_node_shoot(int i);
    Q_INVOKABLE bool get_task_tree_show( int i );
    Q_INVOKABLE int get_task_select_pos();
    Q_INVOKABLE QString get_task_pos_path( int pos );
//    Q_INVOKABLE void set_task_select_pos( int pos);
    Q_INVOKABLE bool get_task_pos_is_saved( int pos);
    Q_INVOKABLE bool get_task_tree_node_visible( int n_index );
    Q_INVOKABLE bool get_task_tree_node_child_visible( int n_index );
    Q_INVOKABLE bool get_child_has_shoot( int n_index );
    Q_INVOKABLE bool get_child_visible_change();
    Q_INVOKABLE QString get_child_visible_change_path();

    void create_device_tree();
    void clear_dev_list();

    //device tree expand way
    Q_INVOKABLE void change_to_general_model_slot();
    Q_INVOKABLE void ir_get_image_name( bool unname = false );
    Q_INVOKABLE QString get_task_image_fold() { return ms_task_image_fold; }
    Q_INVOKABLE QString get_task_image_name() { return ms_task_image_name; }

    //level tree
    Q_INVOKABLE int get_task_child_level( int );
    Q_INVOKABLE int get_task_child_leve_data_id( int );
    Q_INVOKABLE QString get_up_level_name( int );
    Q_INVOKABLE int get_up_level_index( int );
    Q_INVOKABLE QString get_up_level_unflod( int );
    Q_INVOKABLE QString get_down_level_name( int );
    Q_INVOKABLE int get_down_level_index( int );
    Q_INVOKABLE QString get_cur_level_name( int );
    Q_INVOKABLE int get_cur_level_index( int );
    Q_INVOKABLE QString get_down_level_unflod( int );
    Q_INVOKABLE int get_back_level_index( int );
    Q_INVOKABLE QString get_back_level_unflod( int );
    Q_INVOKABLE bool get_task_select_info( int );
    Q_INVOKABLE bool get_task_select_info( int, int );
    Q_INVOKABLE bool tree_had_shoot();

    Q_INVOKABLE bool is_same_voltage_level( QString path, int currect_level_number );
    Q_INVOKABLE bool has_path_father( QString, int );

#ifdef D_SERIAL
    Q_INVOKABLE void load_outline_image( QString );
#endif

    Q_INVOKABLE QString get_img_qml_res_path() { return QML_IMG_RES_PATH; }

    QString get_captured_file_name( bool unname = false );
    Q_INVOKABLE QString get_image_fn() { return m_str_image_fn; }
    void clear_image_fn() { m_str_image_fn.clear(); }

    Q_INVOKABLE void setCurrentImgName();
    Q_INVOKABLE QString GetCurrentImgName();
    void GetShootContent();

    /* 初始化TaskBoxEx界面使能 */
    void Init_TaskBoxEX();

    Q_INVOKABLE bool is_head_pos(QString text);
    Q_INVOKABLE bool is_tail_pos(QString text);

    /* 获取当前选择的图片及公式信息 */
    DEVTYPEINFO get_curDevInfo() { return mp_device_list->get_curDevInfo(); }
    /* 获取当前选择的设备 */
    Q_INVOKABLE TASK_TREE_INFO get_curSelInfo() { return mp_device_list->get_select_device(); }
    /* 获取错误列表 */
    QStringList get_fault_nature_list() { return mp_device_list->get_fault_nature_list(); }

    Q_INVOKABLE int get_packup_count(int index);
    Q_INVOKABLE int get_pre_index(int index);
    Q_INVOKABLE int get_next_index(int index);
    Q_INVOKABLE int get_father_index(int index);

    Q_INVOKABLE void fresh_select_pkg();

    Q_INVOKABLE void debug_time_start();
    Q_INVOKABLE void debug_time_end(int index = 0);

    Q_INVOKABLE QList<QString> get_deviceNodes_by_index(int index);

    Q_INVOKABLE int get_screen_width();
    Q_INVOKABLE int get_screen_height();
    Q_INVOKABLE int get_screen_listWidth();

    void enable_TreeView(bool enable);
    void close_expand_dlg() { emit signal_close_expand_dlg(); }
    void back_last_pkg() { emit signal_back_last_pkg(); }
    void init_sel_taskType() { emit signal_init_sel(); }
    void capture_to_tree() {emit signal_capture_to_tree(); }
    void reset_taskType_dlg() { emit signal_reset_dlg(); }
    void reset_tree_flag() {emit signal_reset_flag(); }

    QList<TASK_TREE_INFO> get_tree_listInfo() { return mp_device_list->get_tree_list_info(); }

    Q_INVOKABLE int delete_img_by_index();

public:
    /*void set_registry_handle( Registry * handle ) { registry_handle = handle; }
    Registry *get_registry_handle() { return registry_handle; }
    Registry *registry_handle;*/

    void set_keyValue_to_up(int keyValue);
    void set_keyValue_to_down(int keyValue);
    void set_keyValue_to_left(int keyValue);
    void set_keyValue_to_right(int keyValue);
    void set_keyValue_to_center(int keyValue);
    void set_keyValue_to_return(int keyValue);

    /* 获取当前任务保存目录 */
    QString get_cunrrentdb_savepath();
    /* 设置SD卡路径 */
    void set_sd_path(QString strPath);

signals:
    void signal_capture_to_tree();
    void signal_reset_flag();
    void signal_init_sel();
    void signal_back_last_pkg();
    void signal_close_expand_dlg();
    void signal_TaskBoxEx_visible();
    void regist_is_activate();
    void change_to_general_model();
    void task_mode_changed();
    void clear_tree_list();
    void start_parse_task_pack_sig();
    void task_loaded();
    void outline_ana_selected( QStringList s_outline_fn_list, QStringList s_ana_list );
    void device_save_change();
    void device_shoot_ok( int shoot_id, int path );
    void device_save_over_sgl();
    void fold_list_for_path();
    void device_tree_ready();
    void level_tree_init();
    void video_title_changed( QString s_title );
    void update_sync_sgl();
    void signal_reset_dlg();
    void signal_cap_start();
    void signal_cap_stop();
    void signal_doDump_by_index(int index, bool b_dump);
    void signal_remove_file(QString strFileName);

public slots:
    void regist_success_slot();
    void regist_fail_slot();
    void handle_video_title_changed( QString s_title );
    QString get_name_by_list_path( QString );

    void slot_cap_start();
    void slot_cap_stop();

private:

    int m_screenSize_id;

    int m_keyValue_up;
    int m_keyValue_down;
    int m_keyValue_left;
    int m_keyValue_right;
    int m_keyValue_center;
    int m_keyValue_return;

    QTime debug_start;
    QTime debug_end;

    QString get_time_str();

#if defined(Q_OS_LINUX)
    u_int64_t mn_video_start_time;
#endif
    QMap< QString, QList<bool> > modeL_map;

    GeneralModeDlg *mp_general_mode;
    SelectTaskDlg *mp_select_taskpack;
    DeviceList *mp_device_list;

    int mn_restore_last_task_status_flag;
    bool mb_general_mode;
    int mn_task_mode;
    int mn_expand_way;
    bool b_has_task_pack;
    QString ms_taskpack_db_name;
    QString q_version;
    QString ms_taskpack_name;
    QStringList ms_dev_zone_list;
    QStringList ms_dev_type_list;

    QString m_str_image_fn;
    QString ms_task_image_name;
    QString ms_task_image_fold;
    QString CurrentImageName;

    QString m_strSDPath;

    void delaymsec(int msec);

};

#endif // QMLPORT_H
