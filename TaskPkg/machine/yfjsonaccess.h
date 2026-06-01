#ifndef YFJSONACCESS_H
#define YFJSONACCESS_H

#include <QObject>
#include <QJsonDocument>

class YFJsonAccess : public QObject
{
    Q_OBJECT
public:
    explicit YFJsonAccess(QObject *parent = 0);
    YFJsonAccess( QString s_file_name );
    bool get_value( const QString &s_key, QJsonValue &s_value );
    bool set_value( QString s_key, QJsonValue s_value );
    QString get_json_value( const QJsonValue &js_value );

private:
    QString ms_file_name;
    QJsonDocument m_json_doc;
    QString ms_json_value;

    void write_json_file( const QString &s_value );
    void print_json_value( const QJsonValue &js_value );
signals:

public slots:

};

#endif // YFJSONACCESS_H
