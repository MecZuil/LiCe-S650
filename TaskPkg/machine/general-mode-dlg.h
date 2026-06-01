#ifndef GENERALMODEDLG_H
#define GENERALMODEDLG_H

#include <QObject>
#include <QStringList>
#include "config.h"
//#include "ir-view.h"
#include <QImage>
#include <QPixmap>
#include <QMutex>
#include "qtimer.h"
#include "config.h"
//#include "pci-irlib-machine.h"
#include "qwaitcondition.h"
//class IrView;
class SelectTaskDlg;
class QmlPort;
#ifdef V_SERIAL
#include "recordthread.h"
#include "dateoritheard.h"
#endif

#ifndef YHANDLE
#define YHANDLE void *
#endif

class QmlPort;

typedef struct FILE_INFO{
    QString image_name;
    QString url;

    bool b_upload; // bool for upload
    bool b_have_load;         // has upload  false( had ) true( must load )
    FILE_INFO() {
        image_name = "";
        url = "";
        b_upload = false;
        b_have_load = true;
    }
}FILE_INFO;


class GeneralModeDlg : public QObject
{
    Q_OBJECT
public:
    explicit GeneralModeDlg( QString s_dir, QObject *parent = 0 );
    ~GeneralModeDlg();
    bool get_btn_enable( QString s_btn_id );
    bool get_def_info_visible( QStringList s_fault_list );
    QString get_img_file_name();
    QString get_fault_nature( QStringList s_fault_list );
    QString get_def_info( bool b_include_rule_info, QStringList s_fault_list );
    QString get_title_info();
    int get_file_list_size();
    int get_file_number_per_page( );
    void set_explore_path( QString str_path );
    void clear_file_list();
    QString get_img_file_name_by_index( int n_index );
    QString get_img_file_path_by_index( int n_index );
    bool get_upload_by_index( int n_index );
    void set_upload_by_index( int n_index, bool );
    bool get_have_load_by_index( int n_index );

    int get_current_index( );
    void set_current_index( int n_index );
    void thumbnail_page_up();
    void thumbnail_page_down();
    void delete_thumbnail_img( int n_index );
    bool get_page_up_btn_enable_status();
    bool get_page_down_btn_enable_status();
    void set_current_thumbnail_page();
    int get_current_thumbnail_index();

    void delete_show_img( int n_pos );
    int get_file_list_count( QString );
    void copy_file_show_list();

    void show_image_main();
    void copy_string_list( QList< FILE_INFO* > &str, QList< FILE_INFO* > &det );
    void show_main_to_thumbnail();
    static QString replace_covert_char( QString &str );
    void printdir( const char *dir );
#ifdef WIFI_FUN
    void import_to_pool( QStringList &image_name_list, QStringList &device_comment_list);
    void set_all_image();
    void set_no_update_image();
#endif
    QString get_image_ms_dir() { return ms_dir; }
signals:

public slots:
    void update_import_file( QString );
    void first_btn_pressed_slot();
    void prev_btn_pressed_slot();
    void last_btn_pressed_slot();
    void next_btn_pressed_slot();
    void delete_btn_pressed_slot();    
    void btns_click_slot( int n_pos );
    void update_status( int i_pos = 0 );
    int set_prev_image_pos( int n_pos );
    int get_prev_image_pos( );
    int get_current_file_list_count();
private:
    int mn_explore_pos;
    QString ms_dir;
    QList< FILE_INFO* > ms_file_list;
    int mn_main_explore_pos;
    QString ms_main_dir;
    QList< FILE_INFO* > ms_file_main_show_list;
    void *mp_setting_dlg;
    int mn_image_x;
    int mn_image_width;
    bool mb_show_rule_info;
    int mn_thumbnail_page;
    YHANDLE mh_ir_image;
    QString get_part_str( QString s_file, int n_index );
    QString get_rule_info();    
    QmlPort *p_parent;
    YHANDLE image_ir;

    void bubble_sort();
    void selection_sort();
    void insertion_sort();

protected:
};

#endif // GENERALMODEDLG_H
