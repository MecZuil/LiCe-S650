#ifndef SETTING_CONF_H
#define SETTING_CONF_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QList>
#include <QStringList>

#include "yfjsonaccess.h"

#define SETTING_PKGNAME     "pkg_name"
#define SETTING_VERSION     "version"
#define SETTING_IDENT_CODE  "task_ident_code"

typedef struct {
    QString pkg_name;
    QString version;
} setting_conf_t;

class Setting_Conf : public QObject
{
    Q_OBJECT
public:
    explicit Setting_Conf(QObject *parent = 0);

    /* @ description : setting.conf单参数写入 */
    void setting_para_write(QString str_fileName, QString str_nodeName, QString str_value);
    /* @ description : setting.conf单参数读取 */
    QString setting_para_read(QString str_fileName, QString str_nodeName);

    /* @ description : setting.conf参数全部写入 */
    void setting_para_writeAll(QString str_fileName, setting_conf_t setting_conf);
    /* @ description : setting.conf参数全部读取 */
    setting_conf_t setting_para_readAll(QString str_fileName);

    /* @ description : 作业包类型判断 */
    bool is_partial_settingConf(QString str_fileName);

signals:

public slots:
};

#endif // SETTING_CONF_H
