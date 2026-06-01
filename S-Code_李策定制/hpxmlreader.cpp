#include  "hpxmlreader.h"

HpXmlReader::HpXmlReader()
{
    errorRead = false;
    isSysInit = false;
    XmlInit("sys.xml");
}
bool HpXmlReader::XmlInit(QString sXmlFilePath)
{
    if(sXmlFilePath != "sys.xml")//目前qt只涉及到sys.xml,所以只管这个就行
    {
        return false;
    }
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << ">>>> >>> >> HpXmlReader::readXml OPen Error == > " << sXmlFilePath;
        return false;//打开失败
    }


    if (!domDocument_Sys.setContent(&file, true)) {
        file.close();
        qDebug() << ">>>> >>> >> HpXmlReader::readXml setContent Error == > " << sXmlFilePath;
        isSysInit = false;
        return false;//读取失败
    }
    isSysInit = true;

    file.close();
    return true;
}
QString HpXmlReader::XmlInit_read(QString sXmlFilePath,QString f_name,QString attr)
{
    if(sXmlFilePath != "sys.xml")
    {
        return NULL;
    }

    if(!isSysInit)//若没有被初始化过
    {
        if(!XmlInit(sXmlFilePath))//则进行初始化
        {
            return NULL;
        }
    }

    errorRead = false;

    QDomElement root;
    root = domDocument_Sys.documentElement();

    QDomNode node=root.firstChild();//会不会有改变的风险，就是文件内容改变了，但是这里读取的还是原来的？？？

    int i = 0;

    while(!node.isNull())
    {
        if(node.nodeName() == f_name)
        {
            return node.toElement().attribute(attr);
        }

        node=node.nextSibling();
        i++;
    }
    errorRead = true;
    qDebug() << ">>>> >>> >> HpXmlReader::readXml can't find Error == > " << f_name << " ; " << attr;
    return NULL;//未找到结点
}
QString HpXmlReader::readXml(QString sXmlFilePath,QString f_name,QString attr)
{
    errorRead = false;
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << ">>>> >>> >> HpXmlReader::readXml OPen Error == > " << f_name << " ; " << attr;
        errorRead = true;
        return NULL;
    }

    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true)) {
        file.close();
        qDebug() << ">>>> >>> >> HpXmlReader::readXml setContent Error == > " << f_name << " ; " << attr;
        errorRead = true;
        return NULL;
    }

    if(!isSysInit)//若sys没有初始化，则进行初始化
    {
        if(sXmlFilePath == "sys.xml")
        {
            if (!domDocument_Sys.setContent(&file, true))
            {
                isSysInit = false;
            }else{
                isSysInit = true;
            }
        }
    }

    QDomElement root=domDocument.documentElement();

    QDomNode node=root.firstChild();

    int i = 0;

    while(!node.isNull())
    {
        if(node.nodeName() == f_name)
        {
            file.close();
            return node.toElement().attribute(attr);
        }

        node=node.nextSibling();
        i++;
    }
    file.close();
    errorRead = true;
    qDebug() << ">>>> >>> >> HpXmlReader::readXml can't find Error == > " << f_name << " ; " << attr;
    return NULL;
}

bool HpXmlReader::CheckFileNormal(QString sXmlFilePath,QString f_name,QString attr)
{
    errorRead = false;
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << ">>>> >>> >> HpXmlReader::CheckFileNormal OPen Error == > " << f_name << " ; ";
        errorRead = true;
        return false;
    }

    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true)) {
        file.close();
        qDebug() << ">>>> >>> >> HpXmlReader::CheckFileNormal setContent Error == > " << f_name << " ; ";
        errorRead = true;
        return false;
    }

    file.close();
    return true;

}

bool HpXmlReader::writeXml(QString sXmlFilePath,QString f_name,QString attr,QString value)
{
    errorRead = false;
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << ">>>> >>> >> HpXmlReader::writeXml OPen Error == > " << f_name << " ; " << value;
        errorRead = true;
        return false;
    }

    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true)) {
        file.close();
        qDebug() << ">>>> >>> >> HpXmlReader::writeXml setContent Error == > " << f_name << " ; " << value;
        errorRead = true;
        return false;
    }
    QDomElement root=domDocument.documentElement();
    QDomNodeList nodeList = root.elementsByTagName(f_name);
    if(nodeList.isEmpty())
    {
        QDomElement newElementNode = domDocument.createElement(f_name);
        newElementNode.setAttribute(attr, value);
        root.appendChild(newElementNode);
    }
    else
    {
        QDomElement element = nodeList.at(0).toElement();
        element.setAttribute(attr, value);
    }

    file.close();
//    QDomElement root=domDocument.documentElement();

    QFile outputFile(sXmlFilePath);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开输出文件";
        return false;
    }


    // 将修改后的XML内容写入输出文件
    QTextStream out(&outputFile);
    domDocument.save(out, 4); // 使用缩进格式保存XML文件

    outputFile.flush();
#ifdef Q_OS_LINUX
        int fd = outputFile.handle();
    if (fd >= 0) {
        ::fsync(fd);
    }
    else{
        qDebug() << __LINE__ << __func__ << " fsync Error, fd == > " << fd;
    }
#endif

    outputFile.close();



    qDebug() << "add" << f_name <<"success";
    return true;

}

bool HpXmlReader::writeXml_more(QString sXmlFilePath, QString f_name, QMap<QString, QString> attrs)
{
    errorRead = false;
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        errorRead = true;
        return false;
    }

    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true)) {
        file.close();
        errorRead = true;
        return false;
    }
    file.close();

    QDomElement root = domDocument.documentElement();
    QDomNodeList nodeList = root.elementsByTagName(f_name);
    QDomElement element;
    if (nodeList.isEmpty()) {
        element = domDocument.createElement(f_name);
        root.appendChild(element);
    } else {
        element = nodeList.at(0).toElement();
    }

    QMapIterator<QString, QString> i(attrs);
    while (i.hasNext()) {
        i.next();
        element.setAttribute(i.key(), i.value());
    }

    QFile outputFile(sXmlFilePath);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        errorRead = true;
        return false;
    }

    QTextStream out(&outputFile);
    domDocument.save(out, 4);

    outputFile.flush();
#ifdef Q_OS_LINUX
    int fd = outputFile.handle();
    if (fd >= 0) {
        ::fsync(fd);
    }
#endif
    outputFile.close();

    return true;
}

void HpXmlReader::readXml_dg(QDomNode node,QString f_name,QString attr,QStringList & list_dg)//递归查询子节点
{
//    qDebug() << "lzj test readXml_dg == > " << node.nodeName();
    while(!node.isNull())
    {
//        qDebug() << "lzj test reader node == > " << node.nodeName();
        if(node.hasChildNodes())
        {
            QDomNode nodeC=node.firstChild();
            readXml_dg(nodeC,f_name,attr,list_dg);
        }
//        qDebug() << "lzj test reader node 2 == > " << node.nodeName() << " ; " << f_name;
        if(node.nodeName() == f_name)
        {
            list_dg << node.toElement().attribute(attr);
        }

        node=node.nextSibling();
    }
}

QStringList HpXmlReader::readXml_more(QString sXmlFilePath,QString f_name,QString attr)
{
    QStringList list;
    list.clear();
    errorRead = false;
    QFile file(sXmlFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << ">>>> >>> >> HpXmlReader::readXml OPen Error == > " << f_name << " ; " << attr;
        errorRead = true;
        return list;//打开失败
    }

    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true)) {
        file.close();
        qDebug() << ">>>> >>> >> HpXmlReader::readXml setContent Error == > " << f_name << " ; " << attr;
        errorRead = true;
        return list;//读取失败
    }

    QDomElement root=domDocument.documentElement();

    QDomNode node=root.firstChild();

    readXml_dg(node,f_name,attr,list);
    file.close();
    if(list.count() != 0)
    {
//        qDebug() << ">>>> >>> >> HpXmlReader::readXml QStringList == > " << list;
        return list;
    }

    file.close();
    errorRead = true;
    qDebug() << ">>>> >>> >> HpXmlReader::readXml can't find Error == > " << f_name << " ; " << attr;
    return list;//未找到结点
}
//备份文件函数
bool HpXmlReader::backupFile(QString sXmlFilePath)
{
    errorRead = false;
    QFile sourceFile(sXmlFilePath);
    if (!sourceFile.exists()) {
        qDebug() << ">>>> >>> >> HpXmlReader::backupFile File Not Exist == > " << sXmlFilePath;
        errorRead = true;
        return false;
    }
    
    QString backupFilePath = sXmlFilePath + ".bak";
    QFile backupFile(backupFilePath);
    if (backupFile.exists()) {
        if (!backupFile.remove()) {
            qDebug() << ">>>> >>> >> HpXmlReader::backupFile Remove Backup Error == > " << backupFilePath;
            errorRead = true;
            return false;
        }
    }
    
    if (!sourceFile.copy(backupFilePath)) {
        qDebug() << ">>>> >>> >> HpXmlReader::backupFile Copy Error == > " << sXmlFilePath << " to " << backupFilePath;
        errorRead = true;
        return false;
    }
    
    qDebug() << ">>>> >>> >> HpXmlReader::backupFile Success == > " << sXmlFilePath << " to " << backupFilePath;
    return true;
}
//恢复文件函数
bool HpXmlReader::restoreFromBackup(QString sXmlFilePath)
{
    errorRead = false;
    QString backupFilePath = sXmlFilePath + ".bak";
    QFile backupFile(backupFilePath);
    if (!backupFile.exists()) {
        qDebug() << ">>>> >>> >> HpXmlReader::restoreFromBackup Backup File Not Exist == > " << backupFilePath;
        errorRead = true;
        return false;
    }
    
    QFile sourceFile(sXmlFilePath);
    if (sourceFile.exists()) {
        if (!sourceFile.remove()) {
            qDebug() << ">>>> >>> >> HpXmlReader::restoreFromBackup Remove Source Error == > " << sXmlFilePath;
            errorRead = true;
            return false;
        }
    }
    
    if (!backupFile.copy(sXmlFilePath)) {
        qDebug() << ">>>> >>> >> HpXmlReader::restoreFromBackup Copy Error == > " << backupFilePath << " to " << sXmlFilePath;
        errorRead = true;
        return false;
    }
    
    qDebug() << ">>>> >>> >> HpXmlReader::restoreFromBackup Success == > " << backupFilePath << " to " << sXmlFilePath;
    return true;
}
