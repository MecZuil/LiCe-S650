#ifndef XMLLIST_H
#define XMLLIST_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <QSet>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include <QStringList>

#include "../hp_statement.h"

class XmlList : public QObject
{
    Q_OBJECT
public:
    explicit XmlList(QObject *parent = 0);
    ~XmlList();

public:
    /* 初始化xml文件列表, 查找SD卡中的XML文件 */
    Q_INVOKABLE int init_xml_list();
    /* 反初始化xml文件列表 */
    Q_INVOKABLE int uinit_xml_list();
    /* 上一页,更新当前页文件列表 */
    Q_INVOKABLE int jump_to_pre_page();
    /* 下一页,更新当前页文件列表 */
    Q_INVOKABLE int jump_to_next_page();

    /* 获取当前页 */
    Q_INVOKABLE int get_current_page();
    /* 获取总页数 */
    Q_INVOKABLE int get_total_page();
    /* 获取当前页文件数 */
    Q_INVOKABLE int get_current_page_xml_count();
    /* 获取总文件数 */
    Q_INVOKABLE int get_total_xml_count();
    /* 获取当前页文件名 */
    Q_INVOKABLE QString get_currentPage_xml_by_index(int index);

    /* 设置当前选择的xml */
    Q_INVOKABLE void set_select_xml_index(int index);
    /* 获取当前选择的xml */
    QString get_select_xml();

    /* 删除当前选择的xml */
    Q_INVOKABLE void del_xml_by_index(int index);

    void set_save_path(QString strPath);

private:
    int m_select_index;         //当前选择xml索引
    int m_current_page;         //当前页
    int m_total_page;           //总页数
    QList<QString> m_xml_list;  //总xml文件列表
    QList<QString> m_page_list; //当前页xml文件列表

    QString m_savePath;

    void delaymsec(int msec);

signals:

public slots:
};

#endif // XMLLIST_H
