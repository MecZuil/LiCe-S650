#ifndef HPXMLREADER_H
#define HPXMLREADER_H

#include  <QtXml>
#include  <QFile>
#include <unistd.h>
#include <fcntl.h>

class HpXmlReader
{
public:
    HpXmlReader();
    bool errorRead;

    QDomDocument domDocument_Sys;//因为初始化时的参数有时候会读取失败，比如设置里面的按钮个数，所以加一个函数，使之读取一次就行
    bool isSysInit;//标识是否已经初始化完成

    bool XmlInit(QString sXmlFilePath);
    QString XmlInit_read(QString sXmlFilePath,QString f_name,QString attr);//读取初始化配置

    QString readXml(QString sXmlFilePath,QString f_name,QString attr);
    bool writeXml(QString sXmlFilePath,QString f_name,QString attr,QString value);
    bool writeXml_more(QString sXmlFilePath, QString f_name, QMap<QString, QString> attrs);
    QStringList readXml_more(QString sXmlFilePath,QString f_name,QString attr);
    void readXml_dg(QDomNode node,QString f_name,QString attr,QStringList & list_dg);//递归查询子节点
    bool CheckFileNormal(QString sXmlFilePath,QString f_name,QString attr);//查询文件是否正常
    bool backupFile(QString sXmlFilePath); // 备份文件
    bool restoreFromBackup(QString sXmlFilePath); // 用备份文件替换原文件
};

#endif // HPXMLREADER_H
