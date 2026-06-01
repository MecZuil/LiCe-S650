#ifndef ANADATAOP_H
#define ANADATAOP_H

#include <QObject>
#include <QList>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class AnadataOP : public QObject
{
    Q_OBJECT
public:
    explicit AnadataOP(QObject *parent = 0);

    void Open_sqlite();
    void Close_sqlite();

signals:

public slots:

private:
    QSqlDatabase database;

protected:


};

#endif // ANADATAOP_H
