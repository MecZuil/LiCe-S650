#include "change-model.h"
#include "config.h"
#include <QDebug>

ChangeModel::ChangeModel(QObject *parent) :
    QObject(parent)
{
}


bool ChangeModel::is_show_anas_and_outline()
{
#ifdef D_SERIAL
    return true;
#endif
    return false;
}

bool ChangeModel::is_show_task_btn() 
{
#ifdef C_SERIAL
    return false;
#elif defined V_SERIAL
    return false;
#endif
    return true;
}

int ChangeModel::set_btn_extra_width()
{
#ifdef C_SERIAL
    return 66;
#elif defined V_SERIAL
    return 66;
#endif
    return 0;
}

int ChangeModel::file_tab_extra_width()
{
#ifdef C_SERIAL
    return 27;
#elif defined V_SERIAL
    return 27;
#endif
    return 0;
}

QString ChangeModel::param_page_item_number()
{
    //#ifdef C_SERIAL
    //    return "1.";
    //#elif defined V_SERIAL
    //    return "2.";
    //#endif
    return "1.";
}

QString ChangeModel::about_model_number()
{
#if defined( SIZE_640X480 )
#if   defined ( C_SERIAL )
    return "C600";
#elif defined ( V_SERIAL )
    return "V600";
#elif defined ( A_SERIAL )
    return "A600";
#elif defined ( D_SERIAL )
    return "D600";
#elif defined ( CAVD_SERIAL )
    return "ACV600";
#elif defined ( CAVD_SERIAL_S )
    return "ACV600";
#endif
#elif defined( SIZE_320X240 )
#if   defined ( C_SERIAL )
    return "C300";
#elif defined ( V_SERIAL )
    return "V310";
#elif defined ( A_SERIAL )
    return "A300";
#elif defined ( D_SERIAL )
    return "D300";
#elif defined ( CAVD_SERIAL )
    return "ACV600";
#elif defined ( CAVD_SERIAL_S )
    return "ACV600";
#endif
#endif
    return "";
}

QString ChangeModel::analyse_page_item_number()
{
    return "3.";
}

QString ChangeModel::system_page_item_number()
{
    return "4.";
}

bool ChangeModel::is_show_add_activation_item()
{//shan chu   #elif defined
#ifdef C_SERIAL
    return false;
#elif defined V_SERIAL
    return false;
#elif defined A_SERIAL
    return false;
#else
    return true;
#endif
}

bool ChangeModel::is_show_replace_item()
{
#ifdef CAVD_SERIAL_S
    return true;
#endif
#ifdef CAVD_SERIAL
    return true;
#endif
    return false;
}

bool ChangeModel::is_show_all_item()
{
#ifdef CAVD_SERIAL_S
    return true;
#else
    return false;
#endif
}

bool ChangeModel::is_show_task_expand_item( int index )
{
    if( ( index == 17 || index == 25 ) && about_a381_number() ) return false;
    if( index == 7 || index == 15 || index == 16 || index == 18 || index == 21
            || index == 23 || ( index == 24 && !is_real_show_device_name() ) )
        return false;
#ifdef C_SERIAL
    //    if( index == 16 )
    //        return false;
#elif defined V_SERIAL
    if( index == 16 )
        return false;
#elif defined CAVD_SERIAL
    if( index >= 26 && index <= 32  )
        return false;
#endif
    return true;
}

int ChangeModel::param_item_number_with_hidden_task_expand( int index )
{
    int number = 0;
#ifdef A381_SOFT
    number = 1;
#endif
    if( index > 7 && index < 15 )
        return index - 1;
    else if( index == 17 )
        return index - 3 - number;
    else if( index == 19 || index == 20 )
        return index - 4 - number;
    else if( index == 22 )
        return index - 5 - number;
    else if( index == 23 )
        return index - 5 - number;
    else if( index == 24 || index == 25 || index == 26  ) {
        if( is_real_show_device_name( ))
            return index - 6 - number;
        else
            return index - 5 - number;
    }
    return index;
}

bool ChangeModel::is_show_device_tree()
{
#ifndef V_SERIAL
    return true;
#endif
    return false;
}

bool ChangeModel::is_show_record_btn()
{
#ifndef V_SERIAL
    return false;
#endif
    if( !SettingHelp::get_show_type() )
    {
        return false;
    }
    return true;
}

QString ChangeModel::get_record_start_image()
{
    return QML_IMG_RES_PATH + QString("record_start.bmp");
}

QString ChangeModel::get_record_stop_image()
{
    return QML_IMG_RES_PATH + QString("record_stop.bmp");
}

bool ChangeModel::is_640x480_size()
{
    return true;
#ifdef SIZE_640X480
    return true;
#elif defined SIZE_320X240
    return false;
#endif

}

int ChangeModel::get_ir_width()
{
    return is_640x480_size() ? 640 : 320;
}

int ChangeModel::get_ir_height()
{
    return is_640x480_size() ? 480 : 240;
}

bool ChangeModel::is_real_show_device_name()
{
#ifdef A_SERIAL
    return true;
#elif defined D_SERIAL
    return true;
#else
    return false;
#endif
}

bool ChangeModel::has_wifi_function()
{
#ifdef WIFI_FUN
    return true;
#else
    return false;
#endif
}

bool ChangeModel::has_upload_function()
{
    if( has_wifi_function() ) {
        return true;
    }
    return false;
}

bool ChangeModel::has_4g_function()
{
#ifdef FOURTHG_FUN
    return true;
#else
    return false;
#endif
}
bool ChangeModel::has_gps_function()
{
#ifdef GPS_FUN
    return true;
#else
    return false;
#endif
}

bool ChangeModel::about_a381_number()
{
#ifdef A381_SOFT
    return true;
#endif
    return false;
}

bool ChangeModel::has_define_color_function()
{
#ifdef DEFINE_COLOR
    return true;
#endif
    return false;
}

bool ChangeModel::has_xf_soft_function()
{
#ifdef XF_SOFT
    return true;
#endif
    return false;
}

bool ChangeModel::is_easy_version()
{
#ifdef EASY_VER
    return true;
#endif
    return false;
}
bool ChangeModel::is_light_resolation()
{
#ifdef LIGHT_RESOLATION
    return true;
#endif
    return false;
}

bool ChangeModel::has_record_function()
{
#ifdef RECORD_FUN
    return true;
#endif
    return false;
}
bool ChangeModel::has_auto_fouce_function()
{
#ifdef AUTO_FOCUS
    return true;
#endif
    return false;
}

bool ChangeModel::has_remark_function()
{
#ifdef REMARK_FUN
    return true;
#endif
    return false;
}
bool ChangeModel::has_inter_function()
{
#ifdef INTERNATION_FUN
    return true;
#endif
    return false;
}

int ChangeModel::get_word_title_size()
{
    return has_inter_function() ? ( is_640x480_size() ? 23 : 16 ) : ( is_640x480_size() ? 25 : 18 );
}

int ChangeModel::get_word_body_size()
{
    return has_inter_function() ? ( is_640x480_size() ? 20 : 12 ) : ( is_640x480_size() ? 22 : 15 );
}

int ChangeModel::get_word_small_body_size()
{
    return has_inter_function() ? ( is_640x480_size() ? 18 : 12 ) : ( is_640x480_size() ? 18 : 12 );
}
