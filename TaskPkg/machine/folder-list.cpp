#include "folder-list.h"

#include <QDir>
#include <QDebug>
#include <stdio.h>
#if defined(Q_OS_LINUX)
//#include "pox_system.h"
#endif

FolderList::FolderList(QObject *parent)
    : QObject(parent)
    , ms_folder_path( "" )
{
    //read file path
    m_strPath = QString("/run/media/mmcblk2p1");
    ms_folder_path = QString("%1/data/images/").arg(m_strPath);

#if defined(Q_OS_WIN32)
    ms_task_select_path = "D:/data/unzipped/";
#elif defined(Q_OS_LINUX)
    ms_task_select_path = "/mnt/data/unzipped/";
#endif
}

FolderList::~FolderList()
{

}

void FolderList::set_sd_path(QString strPath)
{
    m_strPath = strPath;
    ms_folder_path = QString("%1/data/images/").arg(m_strPath);
}

void FolderList::add_folder_list()
{
    m_list_folder_name.clear();

    //判断路径是否存在
    QDir dir( ms_folder_path );
    if( !dir.exists() )
    {
        qDebug()<<"FolderList::add_folder_list 不存该文件路径";
        return;
    }
    dir.setFilter( QDir::Dirs/*| QDir::Files*/ | QDir::NoSymLinks );
    QFileInfoList list = dir.entryInfoList();

    int n_folder_count = list.count();
    if( n_folder_count <= 0 )
    {
        qDebug()<<"count:"<<n_folder_count;
        return;
    }

//    for(int i=0; i < n_folder_count; ++i ) {
    for(int i = n_folder_count-1; i > 0; --i ) {
        QFileInfo file_info = list.at(i);
        QString str_folder_name = file_info.fileName();
        if( str_folder_name == "." || str_folder_name == ".." ) continue;

        m_list_folder_name.append( str_folder_name );
        //qDebug()<<"FolderList::add_folder_list"<<str_folder_name;
    }
}

int FolderList::get_folder_count()
{
    return m_list_folder_name.count();
}

QString FolderList::get_folder_name( int i )
{
    if( i < 0 ) return "";

    int n_count = get_folder_count();
    if( i >= n_count ) return "";
    return m_list_folder_name[i];
}

int FolderList::get_folder_pos( QString str_folder_name )
{
    int i = 0;
    QList<QString>::iterator it = m_list_folder_name.begin();
    for( ; it != m_list_folder_name.end(); ++it ) {
        ++i;
        if( str_folder_name == *it ) {
            return i;
        }
    }
    return 0;
}

bool FolderList::delete_folder( QString str_folder_name )
{
    qDebug() << "#### [FolderList] [delete_folder] : " << str_folder_name;
    QList<QString>::iterator it = m_list_folder_name.begin();
    for( ; it != m_list_folder_name.end(); ++it ) {
        if( str_folder_name == *it ) {
            QString str_folder_path = ms_folder_path + str_folder_name;

            bool b_suc = delete_dir( str_folder_path );
            if( b_suc ) {
                m_list_folder_name.erase( it );
            }

            return b_suc; // 删除文件夹
        }
    }

    return false;
}

//删除文件夹
bool FolderList::delete_dir( const QString &str_path )
{
    QStringList pathList = str_path.split("/");
    if(pathList.count() == 5)
        emit signal_delete_table_analysis(pathList.at(4));

    if ( str_path.isEmpty() ){
        return false;
    }
    QDir dir( str_path );
    if(!dir.exists()){
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
    QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
    foreach (QFileInfo file, fileList){ //遍历文件信息
        if (file.isFile()){ // 是文件，删除
            file.dir().remove(file.fileName());
        }else{ // 递归删除
            delete_dir( file.absoluteFilePath() );
        }
    }
    return dir.rmpath(dir.absolutePath()); // 删除文件夹
}

void FolderList::get_task_select_list()
{
    m_list_task_select.clear();

    //判断路径是否存在
    qDebug()<<"FolderList::get_task_select_list --------------- "<<ms_task_select_path;
    QDir dir( ms_task_select_path );
    if( !dir.exists() )
    {
        qDebug()<<"FolderList::add_folder_list 不存该文件路径";
        return;
    }
    dir.setFilter( QDir::Dirs/*| QDir::Files*/ | QDir::NoSymLinks );
    QFileInfoList list = dir.entryInfoList();

    int n_folder_count = list.count();
    if( n_folder_count <= 0 )
    {
        qDebug()<<"count:"<<n_folder_count;
        return;
    }
    qDebug()<<"FolderList::get_task_select_list --------------- 11111"<<n_folder_count;
    for(int i=0; i < n_folder_count; ++i ) {
        QFileInfo file_info = list.at(i);
        QString str_folder_name = file_info.fileName();
        if( str_folder_name == "." || str_folder_name == ".." ) continue;

        m_list_task_select.append(str_folder_name);
        qDebug()<<"FolderList::add_folder_list -----------222222"<<str_folder_name;

        QString strDebug;
        QByteArray data = str_folder_name.toLocal8Bit();
        for (int i = 0; i < data.count(); i++) {
            if ((data.at(i)&0xFF) <= 0x0F)
                strDebug.append(QString("0x0%1 ").arg(QString::number(data.at(i)&0xFF, 16).toUpper()));
            else
                strDebug.append(QString("0x%1 ").arg(QString::number(data.at(i)&0xFF, 16).toUpper()));
        }
        //qDebug()<<"FolderList::add_folder_list -----------333333"<<strDebug;
    }
}

int FolderList::get_task_select_count()
{
    qDebug() << "#### [FolderList] [get_task_select_count] : m_list_task_select.count = " << m_list_task_select.count();
    return m_list_task_select.count();
}

QString FolderList::get_task_select_name( int i )
{
    if( i < 0 ) return "";

    int n_count = get_task_select_count();
    if( i >= n_count ) return "";
    return m_list_task_select[i];
}

int FolderList::get_task_select_pos( QString str_task_select_name )
{
    int i = 0;
    QList<QString>::iterator it = m_list_task_select.begin();
    for( ; it != m_list_task_select.end(); ++it ) {
        ++i;
        if( str_task_select_name == *it ) {
            return i;
        }
    }
    return 0;
}

bool FolderList::delete_task_select( QString str_task_select_name )
{
    QString s_pkg_path = "";
#if defined(Q_OS_WIN32)
    s_pkg_path = "D:/data/pkgs/" + str_task_select_name + ".zip";
#elif defined(Q_OS_LINUX)
    s_pkg_path = "/mnt/data/pkgs/" + str_task_select_name + ".zip";
#endif

    QFile::remove(s_pkg_path);

    QList<QString>::iterator it = m_list_task_select.begin();
    for( ; it != m_list_task_select.end(); ++it ) {
        if( str_task_select_name == *it ) {
            QString str_folder_path = ms_task_select_path + str_task_select_name;

            bool b_suc = delete_dir( str_folder_path );
            if( b_suc ) {
                m_list_task_select.erase( it );
            }
#if defined(Q_OS_LINUX)
//            pox_system( "sync" );
#endif
            return b_suc; // 删除文件夹
        }
    }

    return false;
}
