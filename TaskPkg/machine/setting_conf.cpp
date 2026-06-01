#include "setting_conf.h"


Setting_Conf::Setting_Conf(QObject *parent) : QObject(parent)
{

}

/***************************************************************************************************
 * @ name                 : setting_para_write
 * @ description          : setting.conf单参数写入
 * @ param - str_fileName : setting.conf文件名
 *         - str_nodeName : 节点名
 *         - str_value    : 参数
 * @ return               : NULL
 ***************************************************************************************************/
void Setting_Conf::setting_para_write(QString str_fileName, QString str_nodeName, QString str_value)
{
    QFile file(str_fileName);
    if (!file.exists()) {
        qDebug() << str_fileName << "is not exists !!!";
        return;
    }

    YFJsonAccess jsonAccess(str_fileName);
    if (!jsonAccess.set_value(str_nodeName, (QJsonValue)str_value)) {
        qDebug() << "set_value failed !!!";
    }
}

/***************************************************************************************************
 * @ name                 : setting_para_read
 * @ description          : setting.conf单参数读取
 * @ param - str_fileName : setting.conf文件名
 *         - str_nodeName : 节点名
 * @ return               : 参数
 ***************************************************************************************************/
QString Setting_Conf::setting_para_read(QString str_fileName, QString str_nodeName)
{
    QString str_value;
    QJsonValue json_value;

    QFile file(str_fileName);
    if (!file.exists()) {
        qDebug() << str_fileName << "is not exists !!!";
        str_value = QString("ERROR");
        return str_value;
    }

    YFJsonAccess jsonAccess(str_fileName);
    if (!jsonAccess.get_value(str_nodeName, json_value)) {
        qDebug() << "get_value failed !!!";
        str_value = QString("ERROR");
    } else {
        str_value = json_value.toString();
    }

    return str_value;
}

/***************************************************************************************************
 * @ name                 : setting_para_writeAll
 * @ description          : setting.conf参数全部写入
 * @ param - str_fileName : setting.conf文件名
 *         - setting_conf : 参数
 * @ return               : NULL
 ***************************************************************************************************/
void Setting_Conf::setting_para_writeAll(QString str_fileName, setting_conf_t setting_conf)
{
    setting_para_write(str_fileName, SETTING_PKGNAME, setting_conf.pkg_name);
    setting_para_write(str_fileName, SETTING_VERSION, setting_conf.version);
}

/***************************************************************************************************
 * @ name                 : setting_para_readAll
 * @ description          : setting.conf参数全部读取
 * @ param - str_fileName : setting.conf文件名
 * @ return               : 参数
 ***************************************************************************************************/
setting_conf_t Setting_Conf::setting_para_readAll(QString str_fileName)
{
    setting_conf_t setting_conf;

    setting_conf.pkg_name = setting_para_read(str_fileName, SETTING_PKGNAME);
    setting_conf.version  = setting_para_read(str_fileName, SETTING_VERSION);

    return setting_conf;
}

/***************************************************************************************************
 * @ name                 : is_partial_settingConf
 * @ description          : 作业包类型判断
 * @ param - str_fileName : setting.conf文件名
 * @ return               : true->局放
 ***************************************************************************************************/
bool Setting_Conf::is_partial_settingConf(QString str_fileName)
{
    if (setting_para_read(str_fileName, SETTING_PKGNAME) == "Partial") {
        return true;
    } else {
        return false;
    }
}


















