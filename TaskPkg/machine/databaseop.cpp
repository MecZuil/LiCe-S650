#include "databaseop.h"
#include <QtSql>
#include <QDebug>
#include "config.h"

DatabaseOp::DatabaseOp( QString s_database_name, QString s_user_name, QString s_pass, QObject *parent) :
    QObject(parent)
{
    open_db( s_database_name, s_user_name, s_pass );
}

DatabaseOp::DatabaseOp( QString s_database_name, QObject *parent) : QObject(parent)
{
    open_db( s_database_name, "root", "root" );
}

DatabaseOp::~DatabaseOp()
{
    mb_connected = false;
    QSqlDatabase::removeDatabase( ms_connection_name );
}

bool DatabaseOp::has_table(QString s_table_name)
{
    if( !mb_connected ) {
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QStringList s_table_list = db.tables();
    if( s_table_list.contains( s_table_name ) ) {
        return true;
    } else {
        return false;
    }
}

void DatabaseOp::get_device_area_list(QStringList &s_list)
{
    get_data_by_sql( "select distinct regions.name from hp_common_shoot_sequences, regions where ( regions.id = hp_common_shoot_sequences.region_id) "
                     "group by hp_common_shoot_sequences.region_id"
                     "", "", s_list );
}

void DatabaseOp::get_device_type_list( QStringList &s_list )
{
    get_data_by_sql( "select distinct device_type from hp_common_shoot_sequences order by region_order_num, device_order_num", "", s_list );
}

void DatabaseOp::get_device_type_list_by_area( QStringList &s_area_list, QStringList &s_list )
{
    QString s_sql = "select distinct device_type from regions, hp_common_shoot_sequences where ( regions.id == hp_common_shoot_sequences.region_id ) and ";

    if( s_area_list.isEmpty() ) {
        return;
    }
    for( int i=0; i<s_area_list.size(); ++i ) {
        if( i == 0 ) {
            s_sql += " ( ";
        } else {
            s_sql += " or ";
        }
        s_sql += "regions.name='" + s_area_list.at( i ) + "'";
    }
    s_sql +=" ) ";
    get_data_by_sql( s_sql, "", s_list );
}

void DatabaseOp::get_data_device_type_list_by_vol_name( QStringList &s_voltage_list, QStringList &s_list )
{
    QStringList s_vol_id_list;
    QString s_sql = "select distinct id from voltage_levels";

    if( s_voltage_list.isEmpty() ) {
        return ;
    }
    for( int i=0; i<s_voltage_list.size(); ++i ) {
        if( i == 0 ) {
            s_sql += " where ";
        } else {
            s_sql += " or ";
        }
        s_sql += "name='" + s_voltage_list.at( i ) + "'";
    }
    get_data_by_sql( s_sql, "", s_vol_id_list );
    if( s_vol_id_list.isEmpty() ) {
        return ;
    }
    s_sql = "select distinct device_types.name from device_types,model_styles where device_types.id = model_styles.device_type_id and (";
    for( int i=0; i<s_vol_id_list.size(); ++i ) {
        if( i != 0 ) {
            s_sql += " or ";
        }
        s_sql += "model_styles.voltage_level_id='" + s_vol_id_list.at( i ) + "'";
    }
    s_sql += ")";
    qDebug()<<"DatabaseOp::get_device_area_list ----------------";
    get_data_by_sql( s_sql, "", s_list );
}

void DatabaseOp::get_fault_nature_list( QStringList &s_list )
{qDebug()<<"DatabaseOp::get_device_area_list ----------------";
    get_data_by_sql( "select name from fault_natures order by id", "", s_list );
}

float DatabaseOp::get_data_base_ver()
{
    float f_ret = 0.0;
    QStringList s_list;qDebug()<<"DatabaseOp::get_device_area_list ----------------";
    get_data_by_sql( "select * from settings", "pkg_version", s_list );

    if( s_list.size() > 0 ) {
        QString s_tmp = s_list.at( 0 );
        f_ret = s_tmp.toFloat();
    }
    return f_ret;
}

void DatabaseOp::get_data_by_sql( const QString &s_sql, const QString &s_field_name, QStringList &s_ret_list, int n_index , bool b_allow_empty)
{
    qDebug()<<"DatabaseOp::get_data_by_sql --------------000000"<<ms_connection_name<<"s_field_name"<<s_field_name<<"s_sql"<<s_sql;
    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QSqlQuery query( db );

    if( !mb_connected ) {
        qDebug() << "connect error" << mb_connected;
        return ;
    }
    bool ret = query.exec( s_sql );
    if( !ret ) {
    }
    QString s_tmp;
    QVariant var;

    while( query.next() ) {
        if( s_field_name.isEmpty() ) {
            var = query.value( n_index );
        } else {
            var = query.value( s_field_name );
        }

        if( var.isValid() ) {
            s_tmp = var.toString();
        } else {
            s_tmp = "";
        }
        if( b_allow_empty || !s_tmp.isEmpty() ) {
            s_ret_list << s_tmp;
        }
    }
}

void DatabaseOp::get_outline_id(const QString &s_subtype_id, QString &s_id)
{
    QString s_sql = "select * from outlines where basic_subtype_id='";
    s_sql += s_subtype_id + "'";
    QStringList s_list;
    get_data_by_sql( s_sql, "id", s_list );
    if( s_list.isEmpty() ) {
        s_id = "";
    } else {
        s_id = s_list.at( 0 );
    }
}

void DatabaseOp::get_outline_info(const QString &s_outline_id, QString &s_outline_fn, QString &s_ana )
{
    QString s_sql = "select * from outlines where id='";
    s_sql += s_outline_id + "'";
    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QSqlQuery query( db );

    if( !mb_connected ) {
        return ;
    }

    bool ret = query.exec( s_sql );
    if( !ret ) {
    }
    if( query.next() ) {
        s_outline_fn = query.value( "outline_vector_file_name" ).toString();
        //s_list << s_tmp;
        QString str_ana = query.value( "ana_unit_text" ).toString();
#ifdef SIZE_640X480
        s_ana =  str_ana;
#else
        s_ana = ana_adaptive( str_ana );
#endif
        //s_list << s_tmp;
    }
}

void DatabaseOp::get_v_data_list(const QString &s_sql, const QStringList &s_field_list, QVector<QStringList> &v_list)
{
    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QSqlQuery query( db );
    bool ret = query.exec( s_sql );
    if( !ret ) {
    }

    //QVector<QStringList> v_list;
    QStringList s_ret_list;
    QSqlRecord rec;
    QVariant var;
    QString s_value;

    while( query.next() ) {
        s_ret_list.clear();
        for( int i=0; i<s_field_list.size(); ++i ) {
            rec = query.record();
            if( rec.contains( s_field_list.at(i) ) ) {
                var = query.value( s_field_list.at(i) );
                if( var.isValid() ) {
                    s_value = var.toString();
                    s_ret_list << s_value;
                    continue ;
                }
            }
            s_ret_list << "";
        }
        v_list.push_back( s_ret_list );
    }
    //return v_list;
}

void DatabaseOp::get_all_data_list( const QString &s_sql, QVector<QStringList> &v_list )
{
    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QSqlQuery query( db );
    bool ret = query.exec( s_sql );
    if( !ret ) {
    }
    //QVector<QStringList> v_list;
    QStringList s_ret_list;
    QSqlRecord rec;
    QVariant var;
    QString s_value;

    while( query.next() ) {
        s_ret_list.clear();
        rec = query.record();
        for( int i=0; i<rec.count(); ++i ) {
            var = query.value( i );
            if( var.isValid() ) {
                s_value = var.toString();
                s_ret_list << s_value;
                //qDebug()<<"s_value-------------------222222222222222222222-------------------------------------------"<<s_value;
                continue ;
            } else {
                s_ret_list << "";
            }
        }
        //qDebug()<<"s_value----------------------------1111111111111111----------------------------------";
        v_list.push_back( s_ret_list );
    }
}

void DatabaseOp::GetShootContentList( QVector<QStringList> &AllContentList )
{
    QString s_sql = "select * from hp_common_shoot_sequences ";
    int Index1=0,Index2=0;
    QStringList shootContentList,ContentList;
    QString shootContent,Content;

    QSqlDatabase db = QSqlDatabase::database( ms_connection_name );
    QSqlQuery query( db );
    bool ret = query.exec( s_sql );//设置数据库
    if( !ret ) {
        qDebug()<<"query.exec( s_sql ) is faild !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        return ;
    }
    //qDebug()<<"DatabaseOp::get_shoot_content()-----------------------------------1111111111111111111111111";
    AllContentList.clear();
    while( query.next() ){
        shootContentList << query.value(9).toString();
        //qDebug()<<"id = "<<query.value(0).toInt();
    }
    for( int i=0; i<shootContentList.count(); i++ )
    {
        Index1=0;
        Index2=0;
        shootContent = shootContentList.at(i);
        //qDebug()<<"DatabaseOp::get_shoot_content()---------shootContent----"<< shootContent<<i;
        while( Index2 < shootContent.count()-1 )
        {
            Index1 = shootContent.indexOf(':',Index1);
            Index2 = shootContent.indexOf(';',Index2);
            Content = shootContent.mid(Index1,(++Index2)-(++Index1)-1);
            ContentList<<Content;
            //qDebug()<<"DatabaseOp::get_shoot_content()---------Content----"<< Content;
        }
        AllContentList.push_back( ContentList );
        ContentList.clear();
    }
    //qDebug()<<"DatabaseOp::get_shoot_content()-----------------------------------22222222222222222222222222";
}

bool DatabaseOp::get_db_connected()
{
    return mb_connected;
}

void DatabaseOp::get_rule_info(const QString &s_sql, QVector<QStringList> &vs_list )
{
    QStringList s_field_list;

    s_field_list << "rule_formula_type_value" << "rule_title" << "rule_text" << "fault_nature_id";
    get_v_data_list( s_sql, s_field_list, vs_list );
}

void DatabaseOp::get_outline_rule(const QString &s_sql, QVector<QStringList> &vs_list)
{
    QStringList s_field_list;

    s_field_list << "rule_formula_type_value" << "rule_title" << "rule_text" << "fault_nature_id";
    get_v_data_list( s_sql, s_field_list, vs_list );
}

void DatabaseOp::open_db(QString s_database_name, QString s_user_name, QString s_pass)
{
    ms_connection_name = "hp_common_database";
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE", ms_connection_name );
    //m_db.setHostName("");
    //ms_db_name = s_database_name;
    db.setDatabaseName( s_database_name );
    db.setUserName( s_user_name );
    db.setPassword( s_pass );
    mb_connected = db.open();
}

QString DatabaseOp::ana_adaptive( QString str )
{
    if( str.isEmpty() ) {
        return "";
    }
    QStringList list_ana = str.split( ";-");
    for( int i = 0; i < list_ana.count(); i++ ) {
        if( !list_ana[ i ].isEmpty() ) {
            QString temp = list_ana[ i ].mid( 0, list_ana[ i ].indexOf( ':' ) + 1 );
            QStringList sign_ana = list_ana[ i ].mid( list_ana[ i ].indexOf( ':' ) + 1 ).split( ";" ) ;
            for( int j = 0; j < sign_ana.count(); j++ ) {
                if( !sign_ana[ j ].isEmpty() ) {
                    QStringList point_ana = sign_ana[ j ].split( "," );
                    for( int k = 0; k < point_ana.count(); k++ ) {
                        if( !point_ana[ k ].isEmpty() ) {
                            point_ana[ k ] = QString("%1").arg( point_ana[ k ].toInt() / 2 );
                        }
                    }
                    sign_ana[ j ] = point_ana.join( "," );
                }
            }
            list_ana[ i ] = temp + sign_ana.join( ";" );
        }
    }

    return list_ana.join( ";-" );
}
