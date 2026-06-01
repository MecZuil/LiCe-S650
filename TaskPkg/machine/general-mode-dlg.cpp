/* copyright: ms
 * author: ZhouJinWei
 * Function: 实现普通模式界面功能
 */
#include "general-mode-dlg.h"
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QtAlgorithms>
#include <algorithm>
//#include "pox_system.h"
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "QTextCodec"
#include "qml-port.h"
#include "qscriptengine.h"

#define DEVICE_AREA_NAME_INDEX 4
#define DEVICE_NAME_INDEX 6
#define PHYSIC_INDEX 9
#define DEFINFO_BAR_LINE_HEIGHT 54

#ifdef SIZE_640X480
static const int n_thumbnail_number_in_per_page = 10;
#else
static const int n_thumbnail_number_in_per_page = 8;
#endif

bool GeneralModeDlg::get_btn_enable( QString s_btn_id)
{
    if( s_btn_id == "back_btn" ) {
        return true;
    }

    if( ms_file_main_show_list.isEmpty() ) {
        return false;
    } else {
        if( s_btn_id == "delete_btn" ) {
            return true;
        } else if( ms_file_main_show_list.size() == 1 ) {
            return false;
        } else if( mn_main_explore_pos == 0 ) {
            if( s_btn_id == "last_btn" || s_btn_id == "next_btn" ) {
                return true;
            } else {
                return false;
            }
        } else if( mn_main_explore_pos == ms_file_main_show_list.size()-1 ) {
            if( s_btn_id == "first_btn" || s_btn_id == "prev_btn" ) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}

bool GeneralModeDlg::get_def_info_visible(QStringList s_fault_list)
{
    if( ms_file_list.isEmpty() ) {
        return false;
    }

    QString s_info = get_def_info( mb_show_rule_info, s_fault_list );
    if( s_info.isEmpty() ) {
        return false;
    }
    return true;
}

QString GeneralModeDlg::get_img_file_name()
{
    if( mn_main_explore_pos >= 0 && mn_main_explore_pos < ms_file_main_show_list.size() ) {
        return ( ms_main_dir + ms_file_main_show_list.at( mn_main_explore_pos )->image_name );
    } else {
        return "";
    }
}

void GeneralModeDlg::printdir( const char *dir )
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if( ( dp = opendir( dir ) ) == NULL ) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while( ( entry = readdir(dp) ) != NULL ) {
#ifdef Q_OS_LINUX
        lstat(entry->d_name,&statbuf);
#endif
        if(S_ISDIR(statbuf.st_mode)) {
            continue;
        }
        else {
            QString filename = entry->d_name;
            if( filename.endsWith(".vi.jpg") || filename.endsWith( "irp.jpg" ) ) {
                FILE_INFO *temp = new FILE_INFO();
                temp->image_name = filename;
                temp->url = QString( dir );
                ms_file_list.append( temp );
            }
        }
    }
    chdir("..");
    closedir(dp);
}

void GeneralModeDlg::update_status( int i_pos )
{
    //QStringList filters;
    //filters << "*.vi.jpg" << "*.irp.jpg";
    //dir.setNameFilters( filters);
    //ms_file_list = dir.entryList( QDir::NoFilter, QDir::Reversed );
    printdir( ms_dir.toStdString().c_str() );
    insertion_sort();
    if( ms_file_list.size() > 0 ) {
        for( int k = 0; k < ms_file_list.size() - 1; k++ ) {
            QString s_pre_file = ms_file_list.at( k )->image_name;
            QString s_file = ms_file_list.at( k + 1 )->image_name;
            s_pre_file = s_pre_file.mid( 0, s_pre_file.indexOf('.') );
            s_file = s_file.mid( 0, s_file.indexOf('.') );
            if( s_pre_file.compare( s_file ) == 0 ) {
                ms_file_list.swap( k, k+1 );
            }
        }
        //        for( int k = 0; k < ms_file_list.size() / 2; k++ ) {
        //            ms_file_list.swap( k, ms_file_list.size() - k - 1);
        //        }

        mn_thumbnail_page = 1;
        if( mn_explore_pos < ms_file_list.size() )
            mn_explore_pos = i_pos;
        else {
            mn_explore_pos = ms_file_list.size() -1;
        }
    } else {
        mn_thumbnail_page = 0;
        mn_explore_pos = -1;
    }
    mb_show_rule_info = false;

#ifdef WIFI_FUN
    QStringList str_list;
    str_list = p_parent->get_back_date( ms_dir );
    for( int j = 0; j < ms_file_list.count(); j++ ) {
        for( int i = 0; i < str_list.count(); i++ ) {
            if( str_list.at( i ).compare( ms_file_list.at( j )->image_name ) == 0 ) {
                ms_file_list.at( j )->b_have_load = false;
            }
        }
    }
#endif
}

void GeneralModeDlg::update_import_file(QString str )
{
    qDebug() << str;
    for( int j = 0; j < ms_file_list.count(); j++ ) {
        if( ms_file_list.at( j )->image_name.compare( str ) == 0 ) {
            ms_file_list.at( j )->b_have_load = true;
        }
    }
}


GeneralModeDlg::GeneralModeDlg(QString s_dir, QObject *parent) :
    mn_explore_pos( 0 ),
    mn_thumbnail_page ( 0 )
{
    image_ir = NULL;
    p_parent = ( QmlPort * )parent;
    ms_dir = s_dir + "/";
}

GeneralModeDlg::~GeneralModeDlg()
{
    if( image_ir != NULL ) {
        //yf_ir_image_ex1_uninit( image_ir );
        image_ir = NULL;
    }
    while( !ms_file_list.isEmpty() ) {
        delete ms_file_list.takeFirst();
    }
    while( !ms_file_main_show_list.isEmpty() ) {
        delete ms_file_main_show_list.takeFirst();
    }
}

void GeneralModeDlg::first_btn_pressed_slot() {
    if( mn_main_explore_pos > 0 ) {
        mn_main_explore_pos = 0;
    }
}

void GeneralModeDlg::prev_btn_pressed_slot() {
    if( mn_main_explore_pos == -1 ) { return ; }

    if( mn_main_explore_pos > 0 ) {
        mn_main_explore_pos--;
    }
}

void GeneralModeDlg::last_btn_pressed_slot() {
    if( mn_main_explore_pos == -1 ) { return ; }

    if( mn_main_explore_pos != ms_file_main_show_list.size() - 1 ) {
        mn_main_explore_pos = ms_file_main_show_list.size()-1;
    }
}

void GeneralModeDlg::next_btn_pressed_slot() {
    if( mn_main_explore_pos == -1 ) { return ; }

    if( mn_main_explore_pos < ms_file_main_show_list.size() - 1 ) {
        mn_main_explore_pos++;
    }
}

void GeneralModeDlg::delete_btn_pressed_slot() {
    if( ms_file_main_show_list.size() < 1 ) { return ; }
}

void GeneralModeDlg::btns_click_slot( int n_pos ) {
    if( n_pos == 0 ) { //Delete the selected file
        if( mn_main_explore_pos < ms_file_main_show_list.size() && mn_main_explore_pos >= 0 ) {
            QFile file( ms_main_dir + ms_file_main_show_list.at( mn_main_explore_pos )->image_name );
            if( file.remove() ) {
                ms_file_main_show_list.removeAt( mn_main_explore_pos );
#ifdef Q_OS_LINUX
//                pox_system("sync");
#endif
                if( mn_main_explore_pos == ms_file_main_show_list.size() ) {   mn_main_explore_pos--; }
            }
        }
        update_status( mn_main_explore_pos );
    }
}

QString GeneralModeDlg::get_title_info()
{
    if( ms_file_list.isEmpty() || mn_explore_pos < 0 || mn_explore_pos >= ms_file_list.size() ) {
        return "0/0";
    }
    QString s_file = ms_file_list.at( mn_explore_pos )->image_name;
    QString s_tip_text;
    if ( s_file.contains( tr("Unamed device") ) ) { //&& 0 == ( ( MainFrame* )theApp.GetMainWnd() )->get_task_mode()
        s_tip_text = s_file.left( s_file.indexOf(".") );
        s_tip_text = s_tip_text.right( s_tip_text.length() - s_tip_text.indexOf("-") - 1 );
        s_tip_text.replace( '-', ':' );
    } else {
        QString s_part = get_part_str( s_file, DEVICE_AREA_NAME_INDEX );
        if ( !s_part.isEmpty() ){
            s_tip_text = s_tip_text + s_part + "-";
            s_tip_text = s_tip_text + get_part_str( s_file, DEVICE_NAME_INDEX ) + "-";
            s_tip_text = s_tip_text + get_part_str( s_file, PHYSIC_INDEX );
        } else {
            s_tip_text = s_file.left( s_file.indexOf( "." ) );
        }
    }

    if ( ms_dir.contains( tr("General Mode") ) ) {
        s_tip_text = s_file.left( s_file.indexOf(".") );
        s_tip_text = tr("General Mode:") + s_tip_text;
    }

    s_tip_text += "(";

    QString s_tmp;
    s_tmp.setNum( mn_explore_pos + 1 );
    s_tip_text += s_tmp + "/";
    s_tmp.setNum( ms_file_list.size() );
    s_tip_text += s_tmp + ")";

    return s_tip_text;
}

QString GeneralModeDlg::get_def_info( bool b_include_rule_info, QStringList s_fault_list )
{
    QString s_info = "";
    if( b_include_rule_info ) {
        s_info = get_rule_info();
    }

    QString s_fault = get_fault_nature( s_fault_list );

    if( !s_fault.isEmpty() ) {
        if( s_info.isEmpty() ) {
            s_info = s_fault;
        } else {
            s_info = s_fault + "\n\n" + s_info;
        }
    }

    return s_info;
}

QString GeneralModeDlg::get_part_str(QString s_file, int n_index)
{
    QStringList s_list = s_file.split( "-" );
    if( n_index >= 0 && n_index < s_list.size() ) {
        QString s_tmp = s_list.at( n_index );
        return replace_covert_char( s_tmp );
    } else {
        return "";
    }
}

QString GeneralModeDlg::replace_covert_char(QString &str)
{
    QString s_text = str;

    s_text.replace( "__0", "-" );
    s_text.replace( "__1", "~" );
    s_text.replace( "__2", "`" );
    s_text.replace( "__3", "!" );
    s_text.replace( "__4", "@" );
    s_text.replace( "__5", "#" );
    s_text.replace( "__6", "$" );
    s_text.replace( "__7", "%" );
    s_text.replace( "__8", "^" );
    s_text.replace( "__9", "&" );
    s_text.replace( "__a", "*" );
    s_text.replace( "__b", "(" );
    s_text.replace( "__c", ")" );
    s_text.replace( "__d", "+" );
    s_text.replace( "__e", "=" );
    s_text.replace( "__f", "{" );
    s_text.replace( "__g", "}" );
    s_text.replace( "__h", "[" );
    s_text.replace( "__i", "]" );
    s_text.replace( "__j", "|" );
    s_text.replace( "__k", "\\" );
    s_text.replace( "__l", ":" );
    s_text.replace( "__m", ";" );
    s_text.replace( "__n", "\"" );
    s_text.replace( "__o", "\'" );
    s_text.replace( "__p", "<" );
    s_text.replace( "__q", ">" );
    s_text.replace( "__r", "," );
    s_text.replace( "__s", "." );
    s_text.replace( "__t", "?" );
    s_text.replace( "__u", "/" );
    s_text.replace( "__v", " " );
    s_text.replace( "__w", "\t" );

    return s_text;
}

void GeneralModeDlg::bubble_sort()
{
    for( int i = 0; i < ms_file_list.count() - 1; i++ ) {
        for( int j = 0; j < ms_file_list.count() - 1; j++ ) {
            if( ms_file_list.at( j )->image_name.compare( ms_file_list.at( j + 1 )->image_name ) < 0 ) {
                ms_file_list.swap( j, j + 1 );
            }
        }
    }
}

void GeneralModeDlg::selection_sort()
{
    for( int i = 0; i < ms_file_list.count() - 1; i++ ) {
        for( int j = i + 1; j < ms_file_list.count(); j++ ) {
            if( ms_file_list.at( i )->image_name.compare( ms_file_list.at( j )->image_name ) < 0 ) {
                ms_file_list.swap( i, j );
            }
        }
    }
}

void GeneralModeDlg::insertion_sort()
{
    for( int i = 1; i < ms_file_list.count(); i++ ) {
        for( int j = 0; j< i ; j++ ) {
            if( ms_file_list.at( j )->image_name.compare( ms_file_list.at( i )->image_name ) < 0 ) {
                FILE_INFO *temp = ms_file_list[ i ];
                for( int k = i; k > j; k--) {
                    ms_file_list[ k ] = ms_file_list[ k - 1 ];
                }
                ms_file_list[ j ] = temp;
                break;
            }
        }
    }
}

QString GeneralModeDlg::get_rule_info()
{
    std::string stmp;
    QString s_rule_info;
    bool b_ret = false;

    if( b_ret && !stmp.empty() ) {
        QString s_title = QString::fromStdString( stmp );
        s_rule_info = s_title; //s_title = s_title.substr( 1, s_title.length() - 3 );
    }

    if( b_ret && !stmp.empty() ) {
        QString s_formula = QString::fromStdString( stmp );
        s_formula = s_formula.mid( 1, s_formula.length()-3 );
        s_rule_info += "\n" + s_formula;
    }

    if( b_ret && !stmp.empty() ) {
        QString s_text = QString::fromStdString( stmp );
        s_text = s_text.mid( 1, s_text.length()-3 );
        s_rule_info += "\n" + s_text;
    }

    s_rule_info.replace(  "+",  " + " );
    s_rule_info.replace(  "-",  " - " );
    s_rule_info.replace(  "*",  " * " );
    s_rule_info.replace(  "/",  " / " );
    s_rule_info.replace(  ">",  " > " );
    s_rule_info.replace(  "<",  " < " );
    s_rule_info.replace(  "> =",  " >= " );
    s_rule_info.replace(  "< =",  " <= " );
    s_rule_info.replace(  "OR",  " OR " );
    s_rule_info.replace(  "AND",  " AND " );

    if( !s_rule_info.isEmpty() ) {
        int n_index = s_rule_info.indexOf( "\n" );
        if( n_index >= 0 ) {
            QString s_rule = s_rule_info.right( s_rule_info.length() - n_index - 1 );
            n_index = s_rule.indexOf( "\n" );
            if( n_index == - 1 ) {
                s_rule_info += "\n";
            }
        } else {
            s_rule_info += "\n\n";
        }
    }
    return s_rule_info;
}

QString GeneralModeDlg::get_fault_nature( QStringList s_fault_list )
{
    std::string stmp;
    //bool b_ret =
    /*yf_ir_image_ex1_get_text( mh_ir_image, "faulttype", stmp );*/
    QString s_fault_type;
    s_fault_type = QString::fromStdString( stmp );
    if( s_fault_type.isEmpty() ) {
        return "";
    }

    int n_fault = s_fault_type.toInt();

    if( s_fault_list.isEmpty() ) {
        return "";
    }

    if( n_fault >= s_fault_list.size() ) {
        n_fault = s_fault_list.size();
    }
    if( n_fault <= 0 ) {
        n_fault = 1;
    }

    s_fault_type = s_fault_list.at( n_fault - 1 );
    return s_fault_type;
}

void GeneralModeDlg::clear_file_list()
{
    while( !ms_file_list.isEmpty() ) {
        delete ms_file_list.takeFirst();
    }
    while( !ms_file_main_show_list.isEmpty() ) {
        delete ms_file_main_show_list.takeFirst();
    }
    mn_explore_pos = -1;
}

int GeneralModeDlg::get_file_list_size()
{
    return ms_file_list.size();
}

int GeneralModeDlg::get_file_number_per_page( )
{
    if( ms_file_list.size () <= n_thumbnail_number_in_per_page ) {
        return ms_file_list.size ();
    } else {
        if( mn_thumbnail_page <=  ms_file_list.size() / n_thumbnail_number_in_per_page  ) {
            return n_thumbnail_number_in_per_page;
        } else if( mn_thumbnail_page ==  ms_file_list.size() / n_thumbnail_number_in_per_page + 1 ) {
            return ms_file_list.size() % n_thumbnail_number_in_per_page;
        }
    }
    return 0;
}

void GeneralModeDlg::set_explore_path( QString str_path )
{
    clear_file_list();
    ms_dir = str_path + "/";
    update_status();
}

int GeneralModeDlg::set_prev_image_pos( int n_pos )
{
    mn_explore_pos = n_pos;
    return mn_explore_pos;
}

QString GeneralModeDlg::get_img_file_name_by_index( int n_index )
{
    if( n_index >= 0 && n_index < n_thumbnail_number_in_per_page ) {
        int n_file_index = n_index + ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page;
        if( n_file_index < ms_file_list.size() ) {
            return ( ms_file_list.at( n_file_index )->image_name );
        } else {
            return "";
        }
    } else {
        return "";
    }
}

QString GeneralModeDlg::get_img_file_path_by_index( int n_index )
{
    if( n_index >= 0 && n_index < n_thumbnail_number_in_per_page ) {
        int n_file_index = n_index + ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page;
        if( n_file_index < ms_file_list.size() ) {
            return ( ms_dir + ms_file_list.at( n_file_index )->image_name );
        } else {
            return "";
        }
    } else {
        return "";
    }
}

bool GeneralModeDlg::get_upload_by_index( int n_index )
{
    if( n_index >= 0 && n_index < n_thumbnail_number_in_per_page ) {
        int n_file_index = n_index + ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page;
        if( n_file_index < ms_file_list.size() ) {
            return ms_file_list.at( n_file_index )->b_upload ;
        }
    }
    return false;
}

void GeneralModeDlg::set_upload_by_index( int n_index, bool temp )
{
    if( n_index >= 0 && n_index < n_thumbnail_number_in_per_page ) {
        int n_file_index = n_index + ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page;
        if( n_file_index < ms_file_list.size() ) {
            ms_file_list.at( n_file_index )->b_upload  = temp;
        }
    }
}

bool GeneralModeDlg::get_have_load_by_index( int n_index )
{
    if( n_index >= 0 && n_index < n_thumbnail_number_in_per_page ) {
        int n_file_index = n_index + ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page;
        if( n_file_index < ms_file_list.size() ) {
            return ms_file_list.at( n_file_index )->b_have_load ;
        }
    }
    return false;
}

int GeneralModeDlg::get_current_index()
{
    return mn_explore_pos;
}

void GeneralModeDlg::set_current_index(int n_index )
{
    mn_explore_pos = ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page + n_index;
}

void GeneralModeDlg::thumbnail_page_up()
{
    --mn_thumbnail_page;
    if( mn_thumbnail_page < 1 ) {
        mn_thumbnail_page = 1;
    }
}

void GeneralModeDlg::thumbnail_page_down()
{
    if( ms_file_list.size() <= n_thumbnail_number_in_per_page ) {
        mn_thumbnail_page = 1;
        return;
    }
    ++mn_thumbnail_page;
    if( mn_thumbnail_page > ( ms_file_list.size() / n_thumbnail_number_in_per_page  + 1 ) ) {
        mn_thumbnail_page = ms_file_list.size() / n_thumbnail_number_in_per_page  + 1;
    }
}

void GeneralModeDlg::delete_thumbnail_img( int n_index ) {
    int n_pos = ( mn_thumbnail_page - 1 ) * n_thumbnail_number_in_per_page + n_index;
    if( n_pos < ms_file_list.size() && n_pos >= 0 ) {
        QFile file( ms_dir + ms_file_list.at( n_pos )->image_name );
        if( file.remove() ) {
            ms_file_list.removeAt( n_pos );
#ifdef Q_OS_LINUX
//            pox_system( "sync" );
#endif
        }

        if( n_pos == ms_file_list.size() ) {
            mn_explore_pos--;
        }
    }
}

void GeneralModeDlg::delete_show_img( int n_pos ) {
    if( n_pos < ms_file_main_show_list.size() && n_pos >= 0 ) {
        QFile file( ms_main_dir + ms_file_main_show_list.at( n_pos )->image_name );
        if( file.remove() ) {
            ms_file_main_show_list.removeAt( n_pos );
#ifdef Q_OS_LINUX
//            pox_system( "sync" );
#endif
        }
        if( n_pos == ms_file_main_show_list.size() ) {
            mn_main_explore_pos--;
        }
    }
}

bool GeneralModeDlg::get_page_up_btn_enable_status()
{
    if( mn_thumbnail_page <= 1 ) {
        return false;
    }
    return true;
}

bool GeneralModeDlg::get_page_down_btn_enable_status()
{
    if( ms_file_list.size() <= n_thumbnail_number_in_per_page ) {
        return false;
    }

    if( 0 == ms_file_list.size() % n_thumbnail_number_in_per_page ) {
        if( mn_thumbnail_page == ms_file_list.size() / n_thumbnail_number_in_per_page ) {
            return false;
        }
    } else {
        if( mn_thumbnail_page == ms_file_list.size() / n_thumbnail_number_in_per_page  + 1 ) {
            return false;
        }
    }
    return true;
}

void GeneralModeDlg::set_current_thumbnail_page()
{
    if( mn_explore_pos < n_thumbnail_number_in_per_page ) {
        mn_thumbnail_page = 1;
    } else {
        mn_thumbnail_page = mn_explore_pos / n_thumbnail_number_in_per_page  + 1;
    }
}

int GeneralModeDlg::get_current_thumbnail_index()
{
    return mn_explore_pos % n_thumbnail_number_in_per_page;
}

int GeneralModeDlg::get_prev_image_pos( )
{
    return mn_main_explore_pos;
}

int GeneralModeDlg::get_current_file_list_count()
{
    if( !ms_file_list.isEmpty() ) {
        return ms_file_list.count();
    }
    else
        return -1;
}
int GeneralModeDlg::get_file_list_count( QString str )
{
    int i;
    for( i = 0; i < ms_file_list.count(); i++ ) {
        if( str.mid( str.lastIndexOf('/') + 1 ).compare( ms_file_list.at( i )->image_name ) == 0  ) {
            mn_explore_pos =  i ;
            return i;
        }
    }
    return 0;
}

void GeneralModeDlg::copy_string_list( QList< FILE_INFO* > &det, QList< FILE_INFO* > &src )
{
    while( !det.isEmpty() ) {
        delete det.takeFirst();
    }
    for( int i = 0; i < src.size(); i++ ) {
        FILE_INFO *p_struct = new FILE_INFO;
        if( p_struct == NULL ) {
            return ;
        }
        p_struct->image_name = src.at( i )->image_name;
        p_struct->url = src.at( i )->url;
        p_struct->b_upload = src.at( i )->b_upload;
        p_struct->b_have_load = src.at( i )->b_have_load;
        det.append( p_struct );
    }
}

void GeneralModeDlg::copy_file_show_list()
{
    while( !ms_file_main_show_list.isEmpty() ) {
        delete ms_file_main_show_list.takeFirst();
    }
    for( int i = 0; i < ms_file_list.size(); i++ ) {
        ms_file_main_show_list.append( ms_file_list.at( i ) );
    }
}

void GeneralModeDlg::show_image_main()
{
    ms_main_dir = ms_dir;
    mn_main_explore_pos = mn_explore_pos;
    copy_string_list( ms_file_main_show_list, ms_file_list );
}

void GeneralModeDlg::show_main_to_thumbnail()
{
    ms_dir = ms_main_dir;
    mn_explore_pos = mn_main_explore_pos;
    copy_string_list( ms_file_list, ms_file_main_show_list );
    set_current_thumbnail_page();
}
#ifdef WIFI_FUN
void GeneralModeDlg::import_to_pool( QStringList &image_name_list, QStringList &device_comment_list )
{
//    QTextCodec *codec = QTextCodec::codecForName("gbk");
    for( int i = 0; i < ms_file_list.count(); i++ ) {
        if( ms_file_list.at( i )->b_upload == false )
            continue;
//        QString file_name;
//        if( ms_file_list.at( i )->image_name.endsWith( ".vi.jpg" ) ) {
//            file_name = ms_file_list.at( i )->image_name.mid( 0, ms_file_list.at( i )->image_name.lastIndexOf( ".vi.jpg" ) ) + ".irp.jpg" ;
//        } else {
//            file_name = ms_file_list.at( i )->image_name.mid( 0, ms_file_list.at( i )->image_name.lastIndexOf( ".irp.jpg" ) ) + ".irp.jpg" ;
//        }
//        if( image_ir == NULL ) {
//            yf_ir_image_ex1_init( image_ir );
//        }

//        if( image_ir != NULL ) {
//            if( yf_ir_image_ex1_load_file( image_ir, ( ms_file_list.at( i )->url + file_name).toStdString() ) ) {
//                char json[ 1024 ];
//                unsigned int size;
//                yf_ir_image_ex1_get_fast_paras_of_json_format( image_ir, json, size );
//                QByteArray a = QByteArray( json, size );
//                QString str = codec->toUnicode( json, size );

//                QScriptEngine engine;
//                QScriptValue sc = engine.evaluate( "value=" + str
        image_name_list.append( ms_file_list.at( i )->image_name );
//                device_comment_list.append( sc.property("device_comment").toString() );
//            }
//        } else {
//        }
        ms_file_list.at( i )->b_upload = false;
        ms_file_list.at( i )->b_have_load = false;
    }
}

void GeneralModeDlg::set_all_image()
{
    for( int i = 0; i < ms_file_list.count(); i++ ) {
        QString file_name = ms_file_list.at( i )->image_name;
        QString s_name = file_name.mid( file_name.lastIndexOf("/") );

        if( s_name.length() > 26 ) {
            ms_file_list.at( i )->b_upload = true;//add
        } else {
            ms_file_list.at( i )->b_upload = false;
        }
    }
}
void GeneralModeDlg::set_no_update_image()
{
    for( int i = 0; i < ms_file_list.count(); i++ ) {
        QString file_name = ms_file_list.at( i )->image_name;
        QString s_name = file_name.mid( file_name.lastIndexOf("/") );
        if( !ms_file_list.at( i )->b_have_load && s_name.length() > 26 ) {
            ms_file_list.at( i )->b_upload = true;//add
        } else {
            ms_file_list.at( i )->b_upload = false;
        }
    }
}
#endif
