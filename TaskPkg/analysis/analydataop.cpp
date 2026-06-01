#include "analydataop.h"

AnalydataOP::AnalydataOP(QObject *parent) : QObject(parent)
{
    QDir dir_1(HP_DATA_FILEPATH);
    if(!dir_1.exists())
        dir_1.mkdir(HP_DATA_FILEPATH);

    QDir dir_2(HP_ANALYSIS_FILEPATH);
    if(!dir_2.exists())
        dir_2.mkdir(HP_ANALYSIS_FILEPATH);
}

/**************************************************************************
 * @ description         : 创建并链接数据库
 * @ param - sqlFileName : 数据库文件名
 * @ param - sqlUserName : 用户名 默认root
 * @ param - sqlPassword : 密码 默认root
 * @ return              : null
 **************************************************************************/
void AnalydataOP::Open_AnalySql(QString sqlFileName, QString sqlUserName, QString sqlPassword)
{
    if(QSqlDatabase::contains(HP_ANALYSIS_CONNECT_NAME)) {
        m_database.close();
    }
    m_database = QSqlDatabase::addDatabase("QSQLITE", HP_ANALYSIS_CONNECT_NAME);
    m_database.setDatabaseName(sqlFileName);
    m_database.setUserName(sqlUserName);
    m_database.setPassword(sqlPassword);

    if(m_database.open()) {
        m_sql_query = QSqlQuery(m_database);
        qDebug() << "#### [AnalydataOP] [Open_AnalySql] : Success to open sqlite. . . ";
    } else {
        qDebug() << "#### [AnalydataOP] [Open_AnalySql] : Failed to open sqlite ! ! ! ";
    }
}

/**************************************************************************
 * @ description : 关闭数据库
 * @ param       : null
 * @ return      : null
 **************************************************************************/
void AnalydataOP::Close_AnalySql()
{
    //qDebug() << "#### [AnalydataOP] [Close_AnalySql] RUN . . . ";
    m_database.close();
}

/**************************************************************************
 * @ description         : 删除数据库文件
 * @ param - sqlFileName : 数据库文件名称
 * @ return              : null
 **************************************************************************/
void AnalydataOP::Delete_AnalySql(QString sqlFileName)
{
    //qDebug() << "#### [AnalydataOP] [Delete_AnalySql] : " << sqlFileName;

    QFile file(sqlFileName);
    if(file.exists())
        file.remove();
}

/**************************************************************************
 * @ description       : 创建表格
 * @ param - tableName : 表名
 * @ param - listValue : 元素类型及元素名
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Add_table(QString tableName, QList<QPair<QString, QString>> listValue)
{
    QString strCmd = QString("CREATE TABLE IF NOT EXISTS \"%1\" ").arg(tableName);
    strCmd.append("(");
    for(int i = 0; i < listValue.count(); i++) {
        if(i != 0)
            strCmd.append(", ");
        strCmd.append(QString("%1 %2").arg(listValue.at(i).first.data()).arg(listValue.at(i).second.data()));
    }
    strCmd.append(")");

    m_sql_query.prepare(strCmd);
    m_sql_query.exec();
#if 0
    qDebug() << "#### [AnalydataOP] [Add_table] : " << strCmd;
    m_sql_query.prepare(strCmd);
    if(m_sql_query.exec())
        qDebug() << "#### [AnalydataOP] [Add_table] : Success . . . ";
    else
        qDebug() << "#### [AnalydataOP] [Add_table] : Fail ! ! ! ";
#endif
}

/**************************************************************************
 * @ description        : 查询表名列表
 * @ param - tableNames : 查到的表名
 * @ return             : null
 **************************************************************************/
void AnalydataOP::Query_table(QStringList *tableNames)
{
    *tableNames = m_database.tables();
}

/**************************************************************************
 * @ description       : 删除表
 * @ param - tableName : 表名
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Delete_table(QString tableName)
{
    QString strCmd = QString("DROP TABLE \"%1\"").arg(tableName);
    qDebug() << "#### [AnalydataOP] [Delete_table] : " << strCmd;

    if(m_sql_query.exec(strCmd))
        qDebug() << "#### [AnalydataOP] [Delete_table] : Success . . . ";
    else
        qDebug() << "#### [AnalydataOP] [Delete_table] : Fail ! ! ! ";
}

/**************************************************************************
 * @ description       : 插入数据
 * @ param - tableName : 表名
 * @ param - listData  : 数据
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Insert_info_line(QString tableName, QList<QString> listData)
{
    QString strCmd = QString("INSERT INTO \"%1\" VALUES").arg(tableName);
    strCmd.append("(");
    for(int i = 0; i < listData.count(); i++) {
        if(i != 0)
            strCmd.append(", ");
        strCmd.append(listData.at(i));
    }
    strCmd.append(")");

    m_sql_query.exec(strCmd);
#if 0
    qDebug() << "#### [AnalydataOP] [Insert_info] : " << strCmd;
    if(m_sql_query.exec(strCmd))
        qDebug() << "#### [AnalydataOP] [Insert_info] : Success . . . ";
    else
        qDebug() << "#### [AnalydataOP] [Insert_info] : Fail ! ! ! ";
#endif
}

/**************************************************************************
 * @ description       : 修改数据
 * @ param - tableName : 表名
 * @ param - where     : 位置
 * @ param - targets   : 需要修改的数据
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Update_info_line(QString tableName, QPair<QString, QString> where, QList<QPair<QString, QString>> targets)
{
    QString strCmd = QString("UPDATE \"%1\" SET ").arg(tableName);
    for(int i = 0; i < targets.count(); i++) {
        if(i != 0)
            strCmd.append(", ");
        strCmd.append(QString("%1 = %2").arg(targets.at(i).first).arg(targets.at(i).second));
    }
    strCmd.append(QString(" WHERE %1 = %2").arg(where.first).arg(where.second));
    //qDebug() << "#### [AnalydataOP] [Update_info] : " << strCmd;

#if 1
    if(!m_sql_query.exec(strCmd))
        qDebug() << "#### [AnalydataOP] [Update_info] : Fail ! ! ! ";
#endif
}

/**************************************************************************
 * @ description       : 删除指定行数据
 * @ param - tableName : 表名
 * @ param - where     : 位置
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Delete_info_line(QString tableName, QPair<QString, QString> where)
{
    QString strCmd = QString("DELETE FROM \"%1\" WHERE %2 = %3").arg(tableName).arg(where.first).arg(where.second);
    //qDebug() << "#### [AnalydataOP] [Delete_info_line] : " << strCmd;

    if(m_sql_query.exec(strCmd))
        qDebug() << "#### [AnalydataOP] [Delete_info_line] : Success . . . ";
    else
        qDebug() << "#### [AnalydataOP] [Delete_info_line] : Fail ! ! ! ";
}

/**************************************************************************
 * @ description       : 查询数据
 * @ param - tableName : 表名
 * @ param - values    : 查询结果 列/行/元素
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Query_info(QString tableName, QList<QList<QPair<QString, QString>>> * values)
{
    if(values->count() <= 0)
        return;
    if(values->at(0).count() <= 0)
        return;
    QList<QPair<QString, QString>> temp_pairs = values->at(0);

    QString strCmd = QString("SELECT ");
    for(int i = 0; i < values->at(0).count(); i++) {
        if(i != 0)
            strCmd.append(", ");
        strCmd.append(values->at(0).at(i).first);
    }
    strCmd.append(QString(" FROM \"%1\"").arg(tableName));
    //qDebug() << "#### [AnalydataOP] [Query_info] : " << strCmd;

    if(m_sql_query.exec(strCmd)) {
        //qDebug() << "#### [AnalydataOP] [Query_info] : Success . . . ";
        values->clear();
        while(m_sql_query.next()) {
            QList<QPair<QString, QString>> temp_list;
            for(int i = 0; i < temp_pairs.count(); i++) {
                QPair<QString, QString> temp_pair;
                temp_pair.first = temp_pairs.at(i).first;
                temp_pair.second = m_sql_query.value(i).toString();
                temp_list.append(temp_pair);
            }
            values->append(temp_list);
        }
    } else {
        qDebug() << "#### [AnalydataOP] [Query_info] : Fail ! ! ! ";
    }
}

/**************************************************************************
 * @ description       : 按条件查询数据
 * @ param - tableName : 表名
 * @ param - values    : 查询结果 列/行/元素
 * @ param - where     : 条件
 * @ return            : null
 **************************************************************************/
void AnalydataOP::Query_info_by_rules(QString tableName, QList<QList<QPair<QString, QString>>> * values, QList<QString> where)
{
    if(values->count() <= 0)
        return;
    if(values->at(0).count() <= 0)
        return;
    QList<QPair<QString, QString>> temp_pairs = values->at(0);

    QString strCmd = QString("SELECT ");
    for(int i = 0; i < values->at(0).count(); i++) {
        if(i != 0)
            strCmd.append(", ");
        strCmd.append(values->at(0).at(i).first);
    }
    strCmd.append(QString(" FROM \"%1\" WHERE ").arg(tableName));
    for(int i = 0; i < where.count(); i++) {
        if(i != 0)
            strCmd.append(" AND ");
        strCmd.append(where.at(i));
    }

    //qDebug() << "#### [AnalydataOP] [Query_info_by_rules] : " << strCmd;
    if(m_sql_query.exec(strCmd)) {
        //qDebug() << "#### [AnalydataOP] [Query_info_by_rules] : Success . . . ";
        values->clear();
        while(m_sql_query.next()) {
            QList<QPair<QString, QString>> temp_list;
            for(int i = 0; i < temp_pairs.count(); i++) {
                QPair<QString, QString> temp_pair;
                temp_pair.first = temp_pairs.at(i).first;
                temp_pair.second = m_sql_query.value(i).toString();
                temp_list.append(temp_pair);
            }
            values->append(temp_list);
        }
    } else {
        qDebug() << "#### [AnalydataOP] [Query_info_by_rules] : cmd " << strCmd << " failed ! ! ! ";
    }
}


/**************************************************************************
 * @ description       : 判断表中是否存在某条数据
 * @ param - tableName : 表名
 * @ param - where     : 位置
 * @ return            : true-->存在;  false-->不存在
 **************************************************************************/
bool AnalydataOP::Exist_info_line(QString tableName, QPair<QString, QString> where)
{   
    QString strCmd = QString("SELECT *");
    strCmd.append(QString(" FROM \"%1\" WHERE %2 = %3").arg(tableName).arg(where.first).arg(where.second));
    //qDebug() << "#### [AnalydataOP] [Exist_info_line] : " << strCmd;

    if(m_sql_query.exec(strCmd)) {
        //qDebug() << "#### [AnalydataOP] [Exist_info_line] : Success . . . ";
        while(m_sql_query.next())
            return true;
        return false;
    } else {
        //qDebug() << "#### [AnalydataOP] [Exist_info_line] : Fail ! ! ! ";
        return false;
    }
}





















