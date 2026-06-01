#ifndef ANALYDATAOP_H
#define ANALYDATAOP_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QFile>
#include <QStringList>
#include <QList>
#include <QPair>

#define HP_DATA_FILEPATH                "/mnt/data/"
#define HP_ANALYSIS_FILEPATH            "/mnt/data/analysis/"
#define HP_ANALYSIS_CONNECT_NAME        "hp_common_analysisdata"

#define SQL_TYPE_INTEGER                "INTEGER"
#define SQL_TYPE_REAL                   "REAL"
#define SQL_TYPE_NUMERIC                "NUMERIC"
#define SQL_TYPE_TEXT                   "TEXT"
#define SQL_TYPE_BLOB                   "BLOB"

#define HP_ANALYSIS_SAVE_COUNT          300
#define HP_ANALYSIS_SHOW_COUNT          200

class AnalydataOP : public QObject
{
    Q_OBJECT
public:
    explicit AnalydataOP(QObject *parent = 0);

    /* 数据库控制 */
    void Open_AnalySql(QString sqlFileName, QString sqlUserName = "root", QString sqlPassword = "root");
    void Close_AnalySql();
    void Delete_AnalySql(QString sqlFileName);

    /* 表格控制 */
    void Add_table(QString tableName, QList<QPair<QString, QString>> listValue);
    void Query_table(QStringList *tableNames);
    void Delete_table(QString tableName);

    /* 行控制 */
    void Insert_info_line(QString tableName, QList<QString> listData);
    void Update_info_line(QString tableName, QPair<QString, QString> where, QList<QPair<QString, QString>> targets);
    void Delete_info_line(QString tableName, QPair<QString, QString> where);
    bool Exist_info_line(QString tableName, QPair<QString, QString> where);

    /* 查询 */
    void Query_info(QString tableName, QList<QList<QPair<QString, QString>>> * values);
    void Query_info_by_rules(QString tableName, QList<QList<QPair<QString, QString>>> * values, QList<QString> where);


signals:

public slots:

private:
    QSqlDatabase m_database;
    QSqlQuery m_sql_query;

protected:

};

#endif // ANALYDATAOP_H
