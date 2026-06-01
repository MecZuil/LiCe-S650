#include "module.h"

#include <QDir>
#include <QVector>

CModule::CModule()
{
}

bool CModule::copy_dir(const QString &s_src_path, const QString &s_dst_path, bool b_cover_file_exist)
{
    QDir sourceDir( s_src_path );
    QDir targetDir( s_dst_path );
    if( !targetDir.exists() ) {
        if( !targetDir.mkdir( targetDir.absolutePath() ) )
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach( QFileInfo fileInfo, fileInfoList ) {
        if( fileInfo.fileName() == "." || fileInfo.fileName() == ".." )
            continue;

        if( b_cover_file_exist && targetDir.exists( fileInfo.fileName() ) ){
            targetDir.remove( fileInfo.fileName() );
        }
        // 进行文件copy
        if( !QFile::copy(fileInfo.filePath(), targetDir.filePath( fileInfo.fileName() ) ) ){
             return false;
        }
    }
    return true;
}

bool CModule::remove_dir( const QString& s_dir_path )
{
    static QVector<QString> vec_dir_names;

    QDir dir;
    QFileInfoList filst;
    QFileInfoList::iterator curFi;

    //初始化
    vec_dir_names.clear();
    if( dir.exists() ) {
        vec_dir_names << s_dir_path;
    } else {
        return true;
    }

    //遍历各级文件夹，并将这些文件夹中的文件删除
    for(int i = 0;i < vec_dir_names.size(); ++i )  {
        dir.setPath( vec_dir_names[i] );
        filst = dir.entryInfoList( QDir::Dirs|QDir::Files
                                 |QDir::Readable|QDir::Writable
                                 |QDir::Hidden|QDir::NoDotAndDotDot
                                 ,QDir::Name );
        if( filst.size() > 0 ) {
            curFi = filst.begin();
            while( curFi != filst.end() ) {
                 //遇到文件夹,则添加至文件夹列表dirs尾部
                if( curFi->isDir() ){
                    vec_dir_names.push_back( curFi->filePath() );
                } else if( curFi->isFile() ){
                    //遇到文件,则删除之
                    if( !dir.remove( curFi->fileName() ) ){
                        return false;
                    }
                }
                curFi++;
            }//end of while
        }
    }

    //删除文件夹
    for( int i = vec_dir_names.size() - 1; i >= 0; --i ) {
        dir.setPath( vec_dir_names[i] );
        if( !dir.rmdir( vec_dir_names[i] ) ) {
            return false;
        }
    }

    return true;
}

