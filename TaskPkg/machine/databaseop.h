#ifndef DATABASEOP_H
#define DATABASEOP_H

#include <QObject>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseOp : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseOp( QString s_database_name, QString s_user_name, QString s_pass, QObject *parent = 0);
    explicit DatabaseOp( QString s_database_name, QObject *parent = 0);
    ~DatabaseOp();
    bool has_table( QString s_table_name );
    void get_device_area_list( QStringList &s_list );
    void get_device_type_list(QStringList &s_list );
    void get_device_type_list_by_area( QStringList &s_area_list, QStringList &s_list );
    void get_voltage_list( QStringList &s_list );
    void get_data_device_type_list(QStringList &s_list);
    void get_data_device_type_list_by_vol_name( QStringList &s_voltage_list, QStringList &s_list );
    void get_fault_nature_list( QStringList &s_list );
    float get_data_base_ver();
    void get_data_by_sql( const QString &s_sql, const QString &s_field_name, QStringList &s_ret_list, int n_index=0, bool b_allow_empty=false );

    void get_rule_info( const QString &s_sql, QVector<QStringList> &vs_list );
    void get_outline_rule( const QString &s_sql, QVector<QStringList> &vs_list );

    void get_outline_id( const QString &s_subtype_id, QString &s_id );
    void get_outline_info(const QString &s_outline_id, QString &s_outline_fn, QString &s_ana);

    void get_v_data_list( const QString &s_sql, const QStringList &s_field_list, QVector<QStringList> &v_list );
    void get_all_data_list( const QString &s_sql, QVector<QStringList> &v_list ); //return all fields data
    bool get_db_connected();
    QString ana_adaptive( QString );
    void GetShootContentList(QVector<QStringList> &AllContentList);
signals:
private:
    bool mb_connected;
    //QSqlDatabase m_db;
    QString ms_connection_name;

    void open_db( QString s_database_name, QString s_user_name, QString s_pass );

public slots:

};

#endif // DATABASEOP_H
