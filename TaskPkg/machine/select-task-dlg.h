#ifndef SELECTTASKDLG_H
#define SELECTTASKDLG_H

#include "config.h"
#include <QStringList>
#include <QList>
#include "setting-help.h"

#define GET_TASK_NAME 0
#define GET_TASK_FIRM 1
class QmlPort;
class DatabaseOp;
class SelectTaskDlg : public QObject
{
    Q_OBJECT
public:
    explicit SelectTaskDlg( bool b_general_mode, int n_task_mode, QObject *parent = 0 );
    int get_btns();

    bool get_task_selected( int n_seq );
    QString get_tasklist_text(int n_seq);
    QString get_pack_firm_ident_code( QString ms_taskpack_db_name );
    int compont_firm_code( int i, QString firm_code );
    void set_task(int seq );
    int get_task_number() { return m_pack_fn_list.size(); }
    bool get_btn_enable( QString s_id );
    void set_taskpack_cell_selected( int n_index );
    void set_taskpack_cell_byname(QString s_name);
    QString delete_task_pack(int n_index);
    bool restore_last_shoot_status(bool b_restore_last_shoot_pos , s_task_pack_status_t *p_stauts);


    void select_all_task_type_clicked();
    void select_no_task_type_clicked();
    bool is_task_type_select_all();
    bool is_task_type_selectded();
    int get_task_type_number() { return m_device_type_list.count(); }
    QString get_task_type_text( int seq );
    void set_task_type( int seq );
    bool selected_task_type( int n_seq );

    void select_all_task_zone_clicked();
    void select_no_task_zone_clicked();
    bool is_select_all_task_zone();
    bool is_has_task_zone_click();
    void select_one_task_zone( int n_seq);
    bool has_task_zone_by_seq( int n_seq );
    int get_task_zone_number() { return m_device_zone_list.count(); }
    QString get_task_zone_text( int seq );

    void fresh_select_pkg();

    ~SelectTaskDlg();
signals:
    void regist_is_activate();
public slots:
    void down_btn_pressed_slot();
    void cancel_btn_pressed_slot();
    bool ok_btn_pressed_slot();
    void ok_btn_continue_slot();
    void up_btn_pressed_slot();
    //void timerEvent(QTimerEvent *event);
private:
    //int mn_explore_page;
    bool mb_general_mode;
    bool mb_has_db;
    bool mb_restore_last_shoot_task;
    bool mb_restore_last_shoot_pos;
    QString ms_dir;

    QList < QStringList >m_pack_fn_list;
    QStringList m_device_zone_list;
    QStringList m_device_type_list;// use
    int mn_selected_pack_pos;
    QList<int> mn_selected_device_zone_list;
    QList<int> mn_selected_device_type_list;

    DatabaseOp *mp_db;
    QString ms_database_fn;

    void tasklist_sel_changed();
    QString get_database_file_name( QString s_pack_name );
    QmlPort *p_port;
};

#endif // SELECTTASKDLG_H
