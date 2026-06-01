#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QTextCodec>
#include "yfjsonaccess.h"
#ifdef unix
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif
YFJsonAccess::YFJsonAccess(QObject *parent) :
    QObject(parent)
{

}

YFJsonAccess::YFJsonAccess( QString s_file_name ){
    ms_file_name = s_file_name;
}

bool YFJsonAccess::get_value( const QString &s_key, QJsonValue &s_value )
{
    qDebug()<<"YFJsonAccess::get_value ------------ "<<ms_file_name;
    QFile file( ms_file_name );
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream stream( &file );
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    QString value = stream.readAll();
    file.close();

    QJsonParseError error;
    m_json_doc = QJsonDocument::fromJson( value.toUtf8(), &error );
    if( !m_json_doc.isEmpty() && error.error == QJsonParseError::NoError ) {
        QJsonObject item = m_json_doc.object();
        if( !item.isEmpty() && item.contains( s_key ) ) {//json type:object
            s_value = item.value( s_key );
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << "parse json file failed:" << error.errorString() << endl;
        return false;
    }
    return true;
}

bool YFJsonAccess::set_value( QString s_key, QJsonValue s_value )
{
    QFile file( ms_file_name );
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream stream( &file );
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    QString value = stream.readAll();
    file.close();

    QJsonParseError error;
    m_json_doc = QJsonDocument::fromJson( value.toUtf8(), &error );
    if( error.error == QJsonParseError::NoError && !m_json_doc.isEmpty() ) {
        QJsonObject item = m_json_doc.object();
        if( !item.isEmpty() && item.contains( s_key ) ) {//json type : object
            item.insert( s_key, s_value );
            m_json_doc.setObject( item );

            value = m_json_doc.toJson( QJsonDocument::Indented );//write to file
            write_json_file( value );
            return true;
        } else {
            qDebug() << "key doesn't exist." << endl;
            return false;
        }
    } else {
        qDebug() << "parse json file failed:" << error.errorString() << endl;
        return false;
    }
    return true;
}

void YFJsonAccess::write_json_file( const QString &s_value ) {
    QFile file( ms_file_name );
    QTextStream out( &file );
    out.setCodec("utf-8");
    if( file.open( QIODevice::WriteOnly ) ) {
        out << s_value;
    }
    file.close();
#ifdef unix
    QByteArray ba = ms_file_name.toLatin1();
    const char * file_name = ba.data();
    int fd = open( file_name, O_WRONLY | O_CREAT | O_APPEND, 0660);//fopen (file1,"rb");
    fsync (fd);
    close (fd);

#endif
}

QString YFJsonAccess::get_json_value( const QJsonValue &js_value ) {
    ms_json_value.clear();
    print_json_value( js_value );
    return ms_json_value;
}

void YFJsonAccess::print_json_value( const QJsonValue &js_value ) {
    if( js_value.isObject() ) {
        QJsonObject object = js_value.toObject();
        QJsonObject::iterator i;
        for( i = object.begin(); i != object.end(); i ++ ) {
            ms_json_value.append( "\"" );
            ms_json_value.append( i.key() );
            ms_json_value.append( "\"");
            ms_json_value.append( ":" );
            if( i.value().isObject() ) {
                ms_json_value.append( "{" );
                print_json_value( i.value().toObject() );
                ms_json_value.append( "}" );
            }
            if( i.value().isString() ) {
                ms_json_value.append( "\"" );
                ms_json_value.append( i.value().toString() );
                ms_json_value.append( "\"" );
                if( i != object.end() - 1 ) {
                    ms_json_value.append( "," );
                }
            }
            if( i.value().isDouble() ) {
                ms_json_value.append( QString::number( i.value().toDouble() ) );
                if( i != object.end() - 1 ) {
                    ms_json_value.append( "," );
                }
            }
        }
    }
}
