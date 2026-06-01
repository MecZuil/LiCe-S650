#include "file-list.h"
#include <QDir>
#include <QDebug>

#include "quazip/quazip.h"
#include "quazip/quazipfile.h"

#include "import-task-thread.h"

FileList::FileList(QObject *parent)
    : QObject(parent)
    , ms_folder_path( "/run/media/sd-mmcblk2p1/data/images/" )
    , ms_file_path( "" )
    , mp_import_task_thread( NULL )
{
    m_strPath = QString("/run/media/mmcblk2p1");

#if defined(Q_OS_WIN32)
    ms_import_task_path = "D:";
#elif defined(Q_OS_LINUX)
    ms_import_task_path = QString("%1/").arg(m_strPath);
#endif

    m_import_task_count = 0;
    mn_progress_value = 0;
}

FileList::~FileList()
{

}

void FileList::set_sd_path(QString strPath)
{
    m_strPath = strPath;
    ms_import_task_path = QString("%1/").arg(m_strPath);
}

void FileList::add_file_list( QString str_folder_name )
{
    m_list_file_name.clear();

    ms_file_path = ms_folder_path + str_folder_name + "/";
    QDir dir( ms_file_path );
    if( !dir.exists() ) {
        qDebug()<<"FileList::add_file_list file_path not exists";
        return;
    }

    dir.setFilter( QDir::Files | QDir::NoSymLinks );
    dir.setSorting( QDir::Time );
    QFileInfoList file_list = dir.entryInfoList();

    int n_file_count = file_list.count();
    if( n_file_count <= 0 ) {
        qDebug()<<"count:"<<n_file_count;
        return;
    }

    //qDebug()<<"count:"<<n_file_count<<ms_file_path;
    for( int i = 0; i<n_file_count; ++i ) {
        QFileInfo file_info = file_list.at(i);
        QString str_file_name = file_info.fileName();

        if( str_file_name == "." || str_file_name == ".." ) return;
        m_list_file_name.append( str_file_name );
        //qDebug()<<"FileList::add_file_list"<<str_file_name;
    }

}

int FileList::get_file_count()
{
    return m_list_file_name.count();
}

QString FileList::get_file_path()
{
    return ms_file_path;
}

QString FileList::get_file_name( int i )
{
    if( i < 0 ) return "";

        int n_count = get_file_count();
        if( i >= n_count ) return "";
        return m_list_file_name[i];
}

int FileList::get_file_pos( QString str_file_name )
{
    int n_count = m_list_file_name.count();
    for( int i = 0; i<n_count; ++i ) {
        if( str_file_name == m_list_file_name[i] ) {
            return i;
        }
    }

    return 0;
}

bool FileList::delete_file( QString str_file_name )
{
    QList<QString>::iterator it = m_list_file_name.begin();
    for( ; it != m_list_file_name.end(); ++it ) {
        if( str_file_name == *it ) {
            QString str_folder_path = ms_file_path + str_file_name;

            bool b_suc = delete_dir_file( str_folder_path );
            if( b_suc ) {
                m_list_file_name.erase( it );
            }

            return b_suc; // 删除文件
        }
    }

    return false;
}

QString FileList::get_pre_file_name( QString str_cur_file_name )
{
    //确定该文件不是第一个文件
    int n_count = m_list_file_name.count();
    for( int i =0; i<n_count; ++i ) {
        if( m_list_file_name[i] == str_cur_file_name && i !=0 ) {
            return m_list_file_name[i-1];
        }
    }
    return "";
}

QString FileList::get_next_file_name( QString str_cur_file_name )
{
    //确定该文件不是最后一个文件
    int n_count = m_list_file_name.count();
    for( int i =0; i<n_count; ++i ) {
        if( m_list_file_name[i] == str_cur_file_name && i != (n_count-1) ) {
            return m_list_file_name[i+1];
        }
    }
    return "";
}
//最早拍
QString FileList::get_first_file_name()
{
    int n_count = m_list_file_name.count();
    if( n_count > 0 ) return m_list_file_name[0];
    return "";
}
//最近拍
QString FileList::get_last_file_name()
{
    int n_count = m_list_file_name.count();
    if( n_count > 0 ) return m_list_file_name[n_count-1];
    return "";
}
//删除文件
bool FileList::delete_dir_file( const QString &str_file_path )
{
    if ( str_file_path.isEmpty() ){
        return false;
    }

    bool b_suc = false;
    QFile file( str_file_path );
    if ( file.exists() )
    {
        b_suc = file.remove();
        qDebug()<<"FileList::delete_dir_file"<<ms_file_path<<str_file_path<<b_suc;
    }
    return b_suc; // 删除文件
}

void FileList::get_import_task_file_list()
{
    qDebug()<<"FileList::get_import_task_file_list ------------- ";
    m_list_task_file_name.clear();

    QDir dir( ms_import_task_path );
    dir.cdUp();
    dir.cd( ms_import_task_path );
    dir.refresh();
    if( !dir.exists() ) {
        return ;
    }

    QStringList filters;
    int StringStartPos;
    int StringEndPos;
    filters << "*.zip";
    dir.setNameFilters( filters );

    QFileInfoList file_list = dir.entryInfoList();

    int n_file_count = file_list.count();
    qDebug()<<"get_import_task_file_list------count:"<< n_file_count;
    if( n_file_count <= 0 ) {
        return;
    }

    //qDebug()<<"count:"<<n_file_count<<ms_file_path;
    for( int i = 0; i < n_file_count; ++i ) {
        QFileInfo file_info = file_list.at(i);
        QString str_file_name = file_info.fileName();

        if( str_file_name == "." || str_file_name == ".." ) return;
        if( is_task_pack( ms_import_task_path + str_file_name ) )
        {
            StringStartPos = str_file_name.indexOf('?',0);
            StringEndPos = str_file_name.indexOf('-',StringStartPos);
            m_list_task_file_name << str_file_name;
            qDebug()<<"FileList::get_import_task_file_list --------"<<str_file_name<<m_list_task_file_name.count();
            qDebug()<<"FileList::get_import_task_file_list ----StringPos----"<<StringStartPos;
            qDebug()<<"FileList::get_import_task_file_list ----StringPos----"<<StringEndPos;
        }
    }
}

bool FileList::is_task_pack( const QString &s_src_path )
{
    bool b_has_sqlite =false;
    bool b_has_setting = false;

    QuaZip archive( s_src_path );
    if ( archive.open( QuaZip::mdUnzip ) ) {
        for( bool f = archive.goToFirstFile(); f; f = archive.goToNextFile() ) {
            QString filePath = archive.getCurrentFileName();
            //qDebug() << "#### [FileList] [is_task_pack] : file_name = " << filePath << ". . .";
            if( filePath == "hp_electric_task_pkg.db")
                b_has_sqlite = true;
            if( filePath == "setting.conf")
                b_has_setting = true;
        }
    } else {
        qDebug() << "#### [FileList] [is_task_pack] : 压缩包解压失败 ！！！";
    }
    qDebug()<<"FileList::is_task_pack ------------- "<<s_src_path<<b_has_sqlite<<b_has_setting;
    return b_has_setting && b_has_sqlite;
}

int FileList::get_import_task_file_count()
{
    qDebug()<<"FileList::get_import_task_file_count ------------- "<<m_list_task_file_name.count();
    return m_list_task_file_name.count();
}

QString FileList::get_import_task_file_name( int n_index )
{
    if( n_index < 0 ) return "";

    int n_count = get_import_task_file_count();
    if( n_index >= n_count ) return "";
    return m_list_task_file_name[n_index];
}

int FileList::init_find_task_selected_list( int count )
{
    clear_find_task_selected_list();
    for( int i = 0; i < count; i++ ) {
        m_list_import_task_selected.append( false );
    }
    m_import_task_count = count;
    return count;
}

bool FileList::get_find_task_btn_status( int index, int n_current_page, int n_show_rows )
{
    int n_real_index = index  + (n_current_page - 1 ) * n_show_rows;
    qDebug() << "get_find_task_btn_status-------" << index << n_current_page << n_show_rows << n_real_index;
    if( index >= 0 && n_real_index < m_import_task_count ) {
        return m_list_import_task_selected.at( n_real_index );
    }
    return false;
}

void FileList::set_find_task_btn_status( int index,int n_current_page, int n_show_rows, bool status )
{
    qDebug() << "#### [FileList] [set_find_task_btn_status] : " << index << status;
    if( index < 0 ) return;
    int n_real_index = index  + (n_current_page - 1 ) * n_show_rows;
    if( n_real_index < m_import_task_count ) {
        m_list_import_task_selected[ n_real_index ] = status;
        if( status ) {
            m_list_import_task_index << n_real_index;
        } else {
            if( m_list_import_task_index.contains( n_real_index ) ) {
                m_list_import_task_index.remove( n_real_index );
            }
        }
    }
}


bool FileList::has_select_import_task()
{
    if( !m_list_import_task_index.isEmpty() ) {
        return true;
    }
    return false;
}

void FileList::clear_find_task_selected_list( )
{
    //if( !m_list_import_task_selected.isEmpty() )
    m_list_import_task_selected.clear();
    m_list_import_task_index.clear();
    ms_list_all_import_task.clear();
}

void FileList::get_all_import_task_file()
{
    ms_list_all_import_task.clear();
    foreach( const int n_index, m_list_import_task_index ) {
        ms_list_all_import_task << m_list_task_file_name[n_index];
    }

//    for( int i = 0; i < m_list_import_task_index.size(); ++i ) {
//        int n_index = m_list_import_task_index[i];
//        ms_list_all_import_task << m_list_task_file_name[n_index];
//    }
    //return ms_list_all_import_task;
}

QString FileList::get_import_task_file( int n_index )
{
    if( n_index >= 0 && n_index < ms_list_all_import_task.size() ) {
        return ms_list_all_import_task[n_index];
    }
    return "";
}

QString FileList::get_task_progress_num()
{
    qDebug()<<"FileList::get_task_progress_num-------------------------------"<<"0/" + QString::number( m_list_import_task_index.size() );
    return "0/" + QString::number( m_list_import_task_index.size() );
}

int FileList::get_progress_max_value()
{
    return m_list_import_task_index.size() * PROGRESS_BAR_LENGTH *PART_NUM_PERTASK;
}

void FileList::import_task()
{
    get_all_import_task_file();
qDebug()<<"FileList::import_task --------------------- 00000";
    if( ms_list_all_import_task.isEmpty() ) return;
qDebug()<<"FileList::import_task --------------------- 11111";
    if( mp_import_task_thread != NULL ) {
        delete mp_import_task_thread ;
        mp_import_task_thread = NULL;
    }
qDebug()<<"FileList::import_task --------------------- 22222";
    mp_import_task_thread = new CImportTaskThread( ms_list_all_import_task, ms_import_task_path, this, true );
    connect( mp_import_task_thread, SIGNAL( progress(int) ), this, SLOT( set_progress_value(int) ) );
    connect( mp_import_task_thread, SIGNAL( finished() ), this, SLOT( finished() ) );
    //connect( mp_import_task_thread, SIGNAL( noImportUpgradeProgram() ), this, SIGNAL( noImportUpgradeProgram() ) );
    //connect( mp_import_task_thread, SIGNAL( createSharedMemFail() ), this, SIGNAL( createSharedMemFail() ) );
    connect( mp_import_task_thread, SIGNAL( task_bag_progress_num( QString ) ), this, SIGNAL( task_bag_progress_num( QString ) ) );
    connect(mp_import_task_thread, SIGNAL(Insert_table_analysis(QString)), this, SLOT(slot_insert_table_analysis(QString)));

    mp_import_task_thread->start();
}

void FileList::set_progress_value(int n_value)
{
    mn_progress_value = n_value;
    emit changeValue( mn_progress_value );
}

void FileList::finished()
{
    ms_list_all_import_task.clear();
    emit importFinished();
}

void FileList::slot_insert_table_analysis(QString tableName)
{
    emit signale_insert_table_analysis(tableName);
}
