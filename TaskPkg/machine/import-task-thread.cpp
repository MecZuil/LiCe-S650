#include "import-task-thread.h"

#include <QDir>
#include <QDebug>
#include <QBuffer>
//#include <QApplication>
//#include "external-disk.h"
//#include "module.h"
//#include "parameter.h"
//#include "pox_system.h"
#include "qdatastream.h"

CImportTaskThread::CImportTaskThread(QStringList &s_list, QString s_file_path, QObject *parent , bool b_taskpack) :
    QThread( parent ), ms_pkg_list( s_list ), ms_import_file_path( s_file_path ), mb_stopped( false )
{
    mb_taskpack = b_taskpack;
    shared_mem.setKey( "yfsoftwareupdate" );
}

CImportTaskThread::~CImportTaskThread()
{
}

void CImportTaskThread::run()
{
//    QString s_usb_path = CExternalDisk::get_exit_disk();
//    if( s_usb_path.isEmpty() ) {
//        return ;
//    }
    QString s_pkg_dst_dir;

    QString s_data_path = "";
#if defined(Q_OS_WIN32)
    s_data_path = "D:/data";
#elif defined(Q_OS_LINUX)
    s_data_path = "/mnt/data";
#endif

    if( mb_taskpack ) {
        //s_pkg_dst_dir = Parameter::get_parameter( QString( "data_path") ) + "/pkgs";
        //s_pkg_dst_dir =  "/mnt/data/pkgs";
        s_pkg_dst_dir = s_data_path + "/pkgs";
    } else {
        s_pkg_dst_dir = s_data_path + "/temp";
        QDir tmp_dir( s_pkg_dst_dir );
        if( tmp_dir.exists() ) {
            tmp_dir.removeRecursively();
        }
    }

    QDir dir( s_pkg_dst_dir );
    if( !dir.exists() ) {
        dir.mkpath( s_pkg_dst_dir );
    }

    for( int i = 0; i < ms_pkg_list.size(); i++ ) {
        QString s_zip_file_name = ms_pkg_list.at( i );
        if( mb_taskpack ) {
//            if( i == 0 ){
//                QDir tmp_dir( s_usb_path );
//                tmp_dir.cdUp();
//                s_usb_path = tmp_dir.absolutePath();
//            }

            QString s_src_pkg_path = ms_import_file_path + "/" + s_zip_file_name;
            if( s_zip_file_name.contains( "/") ) {
                int n_index = s_zip_file_name.indexOf( "/" );
                s_zip_file_name = s_zip_file_name.mid( n_index+1 );
            }
            QString s_dst_pkg_path = s_pkg_dst_dir + "/" + s_zip_file_name;
            if( QFile::exists( s_src_pkg_path ) ) {
                if( QFile::exists( s_dst_pkg_path ) ) {
                    QFile::remove( s_dst_pkg_path );
                }
            }
            if( !QFile::copy( s_src_pkg_path, s_dst_pkg_path ) ) {
                qDebug() << "copy zip file fail!";
            } else {
                emit progress( ( i * PART_NUM_PERTASK + 1 ) * PROGRESS_BAR_LENGTH );

                QString s_unzip_dir = s_zip_file_name.left( s_zip_file_name.lastIndexOf( "." ) );
                QString s_unzip_path = s_data_path + "/unzipped/" + s_unzip_dir;
                unzip_to_disk( s_dst_pkg_path, s_unzip_path );
                //pox_system( "sync" );

                emit Insert_table_analysis(s_unzip_dir);

                emit progress( ( i * PART_NUM_PERTASK + 2 ) * PROGRESS_BAR_LENGTH );

                //QString s_src_outlines_path = s_unzip_path + "/outlines";
                //QString s_dst_outlines_path = Parameter::get_parameter( QString( "data_path") ) + "/outlines";
                //CModule::copy_dir( s_src_outlines_path, s_dst_outlines_path, true );
                //pox_system( "sync" );
            }

            emit progress( ( i * PART_NUM_PERTASK + 3 ) * PROGRESS_BAR_LENGTH );

            emit task_bag_progress_num( QString::number( i + 1 ) + "/" + QString::number( ms_pkg_list.size() ) );

        } else {
//#if 1
//            QDir tmp_dir( s_usb_path );
//            tmp_dir.cdUp();
//            s_usb_path = tmp_dir.absolutePath();
//#endif
//            QString s_src_pkg_path = s_usb_path + "/" + s_zip_file_name;
//            emit progress( 30 );
//            unzip_to_disk( s_src_pkg_path, s_pkg_dst_dir );
//            emit progress( 60 );
//            thread_upgrade_program();
//            emit progress( 100 );
        }

        if( mb_stopped ) return;
    }
}

//void CImportTaskThread::thread_upgrade_program()
//{
//    QString s_usb_dev = CExternalDisk::get_exit_disk();
//    QString s_path = s_usb_dev + "/temp";
//    QDir dir( s_path );
//    qDebug() << s_path;
//    if( s_usb_dev.isEmpty() ) {
//        return ;
//    }

//    QStringList filters, s_file_list;
//    filters << "*";
//    dir.setNameFilters( filters );
//    s_file_list = dir.entryList();
//    bool b_has_file = false;
//    for( int i=0; i<s_file_list.size(); ++i ) {
//        if( s_file_list.at( i ).compare(".") == 0 || s_file_list.at( i ).compare("..") == 0 ) {
//            continue ;
//        } else {
//            b_has_file = true;
//            break;
//        }
//    }
//    if( !b_has_file ){
//        emit noImportUpgradeProgram();
//        return ;
//    }

//    if( !shared_mem.attach() ) {
//        emit createSharedMemFail();
//        return ;
//    }

//    QBuffer buffer;
//    QString s_text;
//    s_text = QString( "%1%2" ).arg( 1 ).arg( s_path ); //s_machine_serial + "-update"

//    buffer.open( QBuffer::WriteOnly );
//    QDataStream out( &buffer );
//    out << s_text;
//    int n_size = buffer.size();
//    shared_mem.lock();

//    char *to = (char*)shared_mem.data();
//    const char *from = buffer.data().data();
//    memcpy( to, from, qMin( shared_mem.size(), n_size ) );

//    shared_mem.unlock();
//    shared_mem.detach();

//    QApplication::exit( 0 );
//}

QStringList CImportTaskThread::get_unzip_file_name( const QString &s_src_path )
{
    QStringList s_list_zip_file_name;

    QStringList s_list_zip_file_name_temp;
    QuaZip archive;
    archive.setZipName( s_src_path );
    archive.setFileNameCodec( "gbk" );
    b_code = false;
    if ( archive.open( QuaZip::mdUnzip ) ) {
        for( bool f = archive.goToFirstFile(); f; f = archive.goToNextFile() ) {
            QString filePath = archive.getCurrentFileName();
            if( !filePath.endsWith("/") ) {
                s_list_zip_file_name << filePath;
            }
            if( filePath.compare( "setting.conf" ) == 0 ) {
                QuaZipFile zFile( archive.getZipName(), filePath );
                zFile.open( QIODevice::ReadOnly );
                QByteArray ba = zFile.readAll();
                zFile.close();
                QString str = QString::fromLatin1( ba );
                if( str.indexOf( "UTF-8" ) != -1 ) {
                    archive.setFileNameCodec( "UTF-8" );
                    s_list_zip_file_name.clear();
                    b_code = true;
                }
            }
        }
    }
    if( b_code ) {
        for( bool f = archive.goToFirstFile(); f; f = archive.goToNextFile() ) {
            QString filePath = archive.getCurrentFileName();
            if( !filePath.endsWith("/") ) {
                s_list_zip_file_name_temp << filePath;
            }
        }
    }
    archive.close();
    if( b_code)
        return s_list_zip_file_name_temp;
    else
        return s_list_zip_file_name;
}

void CImportTaskThread::unzip_to_disk( const QString& s_src_path, const QString& s_dst_path )
{
    QStringList s_list_file_name = get_unzip_file_name( s_src_path );
    QuaZip archive;
    archive.setZipName( s_src_path );
    if( b_code ) {
        archive.setFileNameCodec( "UTF-8" );
    }
    if ( !archive.open( QuaZip::mdUnzip ) )
        return;
    QString path = s_dst_path;
    if ( !path.endsWith("/") && !s_dst_path.endsWith( "\\" ) )
        path += "/";

    QDir dir( s_dst_path );
    if ( !dir.exists() )
        dir.mkpath( s_dst_path );

    int n_index = 0;

    for( bool f = archive.goToFirstFile(); f && n_index < s_list_file_name.size(); f = archive.goToNextFile() ) {
        QString filePath = archive.getCurrentFileName();
        //        if( !filePath.endsWith("bmp") ) {
        //            continue;
        //        }
        QuaZipFile zFile( archive.getZipName(), filePath );
        zFile.open( QIODevice::ReadOnly );
        QByteArray ba = zFile.readAll();
        zFile.close();

        if ( filePath.endsWith("/") ) {
            dir.mkpath( filePath );
        } else {
            n_index ++;
            QString s_unzip_file_path = path + s_list_file_name.at( n_index - 1 );
            QString s_unzip_file_dir = s_unzip_file_path.left( s_unzip_file_path.lastIndexOf( "/" ) );
            if( !dir.exists( s_unzip_file_dir ) ) {
                dir.mkpath( s_unzip_file_dir );
            }
            QFile dstFile( s_unzip_file_path );
            if ( !dstFile.open( QIODevice::WriteOnly ) ) {
                return;
            }
            dstFile.write( ba );
            dstFile.close();
        }
    }
    archive.close();
}

//void CImportTaskThread::thread_replace_program( QString soft_name )
//{
//    if( !shared_mem.attach() ) {
//        emit createSharedMemFail();
//        return ;
//    }
//    QBuffer buffer;
//    QString s_text;
//    s_text = QString( "%1%2" ).arg( 2 ).arg( soft_name ); //s_machine_serial + "-update"

//    buffer.open( QBuffer::WriteOnly );
//    QDataStream out( &buffer );
//    out << s_text;
//    int n_size = buffer.size();
//    shared_mem.lock();
//    char *to = (char*)shared_mem.data();
//    const char *from = buffer.data().data();
//    memcpy( to, from, qMin( shared_mem.size(), n_size ) );
//    shared_mem.unlock();
//    shared_mem.detach();
//    QApplication::exit( 0 );
//}




















