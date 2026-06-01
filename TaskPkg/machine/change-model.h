#ifndef CHANGEMODEL_H
#define CHANGEMODEL_H

#include <QObject>

#include "setting-help.h"
class ChangeModel : public QObject
{
    Q_OBJECT
public:
    explicit ChangeModel(QObject *parent = 0);

    Q_INVOKABLE bool is_show_anas_and_outline();

    Q_INVOKABLE bool is_show_task_btn();
    Q_INVOKABLE int set_btn_extra_width();
    Q_INVOKABLE int file_tab_extra_width();
    Q_INVOKABLE QString param_page_item_number();
    Q_INVOKABLE QString analyse_page_item_number();
    Q_INVOKABLE QString system_page_item_number();
    Q_INVOKABLE QString about_model_number();
    Q_INVOKABLE bool about_a381_number();
    Q_INVOKABLE bool is_show_add_activation_item();

    Q_INVOKABLE bool is_show_task_expand_item( int index );
    Q_INVOKABLE int param_item_number_with_hidden_task_expand( int index );

    Q_INVOKABLE bool is_show_device_tree();

    Q_INVOKABLE bool is_show_record_btn();
    Q_INVOKABLE QString get_record_start_image();
    Q_INVOKABLE QString get_record_stop_image();

    Q_INVOKABLE bool is_show_replace_item();
    Q_INVOKABLE bool is_show_all_item();

    Q_INVOKABLE bool is_640x480_size();
    Q_INVOKABLE int get_ir_width();
    Q_INVOKABLE int get_ir_height();

    Q_INVOKABLE bool is_real_show_device_name();
    Q_INVOKABLE bool has_wifi_function();
    Q_INVOKABLE bool has_upload_function();
    Q_INVOKABLE bool has_4g_function();
    Q_INVOKABLE bool has_gps_function();
    Q_INVOKABLE bool has_define_color_function();
    Q_INVOKABLE bool has_xf_soft_function();
    Q_INVOKABLE bool is_easy_version();
    Q_INVOKABLE bool is_light_resolation();
    Q_INVOKABLE bool has_record_function();
    Q_INVOKABLE bool has_auto_fouce_function();
    Q_INVOKABLE bool has_remark_function();
    Q_INVOKABLE bool has_inter_function();
    Q_INVOKABLE int get_word_title_size();
    Q_INVOKABLE int get_word_body_size();
    Q_INVOKABLE int get_word_small_body_size();
public slots:

};

#endif // CHANGEMODEL_H
