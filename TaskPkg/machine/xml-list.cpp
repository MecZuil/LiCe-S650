#include "xml-list.h"

XmlList::XmlList(QObject *parent) : QObject(parent)
{
    m_select_index = -1;
    m_current_page = 1;
    m_total_page = 1;

    m_page_list.clear();
    m_xml_list.clear();

    m_savePath = QString("/run/media/mmcblk2p1/");
}

XmlList::~XmlList()
{
}

void XmlList::set_save_path(QString strPath)
{
    m_savePath = QString("%1/").arg(strPath);
}

/*****************************************************************************
 * @ name        : init_xml_list
 * @ description : XML文件列表初始化
 * @ param       : NULL
 * @ return      : 文件数量
 *****************************************************************************/
int XmlList::init_xml_list()
{
    m_page_list.clear();
    m_xml_list.clear();

    QString strFileDir = m_savePath;
    QDir dir(strFileDir);
    if (!dir.exists()) {
        qDebug() << "init_xml_list : dir is not exist";
        return 0;
    }

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setSorting(QDir::Time);
    QFileInfoList file_list = dir.entryInfoList();

    int file_count = file_list.count();
    if (file_count <= 0) {
        qDebug() << "init_xml_list : count = " << file_count;
        return 0;
    }

    for (int i = 0; i < file_count; i++) {
        QFileInfo file_info = file_list.at(i);
        QString strFileName = file_info.fileName();

        if (strFileName.contains(QString(".xml")))
            m_xml_list.append(strFileName);
    }

    if (m_xml_list.count() > 0) {
        m_select_index = -1;
        m_current_page = 1;
        m_total_page = m_xml_list.count() / 5 + (m_xml_list.count()%5 > 0 ? 1 : 0);
    }

    if (m_xml_list.count() < 5) {
        for (int i = 0; i < m_xml_list.count(); i++)
            m_page_list.append(m_xml_list.at(i));
    } else {
        for (int i = 0; i < 5; i++)
            m_page_list.append(m_xml_list.at(i));
    }

    return m_xml_list.count();
}

int XmlList::uinit_xml_list()
{
    m_current_page = 1;
    m_total_page = 1;
    m_select_index = -1;
    m_xml_list.clear();
    m_page_list.clear();

    return 0;
}

/*****************************************************************************
 * @ name        : jump_to_pre_page
 * @ description : 跳转至上一页
 * @ param       : NULL
 * @ return      : 当前页
 *****************************************************************************/
int XmlList::jump_to_pre_page()
{
    if (m_current_page <= 1)
        return m_current_page;

    m_current_page--;

    int start_index = 5*(m_current_page-1) > 0 ? 5*(m_current_page-1) : 0;
    int end_index   = 5*(m_current_page-1)+5 < m_xml_list.count() ? 5*(m_current_page-1)+5 : m_xml_list.count();

    qDebug() << m_current_page << " - " << m_total_page << " - " << start_index << " - " << end_index;

    m_page_list.clear();
    for (int i = start_index; i < end_index; i++)
        m_page_list.append(m_xml_list.at(i));

    return m_current_page;
}

/*****************************************************************************
 * @ name        : jump_to_next_page
 * @ description : 跳转至下一页
 * @ param       : NULL
 * @ return      : 当前页
 *****************************************************************************/
int XmlList::jump_to_next_page()
{
    if (m_current_page >= m_total_page)
        return m_current_page;

    m_current_page++;

    int start_index = 5*(m_current_page-1) > 0 ? 5*(m_current_page-1) : 0;
    int end_index   = 5*(m_current_page-1)+5 < m_xml_list.count() ? 5*(m_current_page-1)+5 : m_xml_list.count();

    qDebug() << m_current_page << " - " << m_total_page << " - " << start_index << " - " << end_index;

    m_page_list.clear();
    for (int i = start_index; i < end_index; i++)
        m_page_list.append(m_xml_list.at(i));

    return m_current_page;
}

/*****************************************************************************
 * @ name        : get_current_page
 * @ description : 获取当前页
 * @ param       : NULL
 * @ return      : 当前页
 *****************************************************************************/
int XmlList::get_current_page()
{
    return m_current_page;
}

/*****************************************************************************
 * @ name        : get_total_page
 * @ description : 获取总页数
 * @ param       : NULL
 * @ return      : 总页数
 *****************************************************************************/
int XmlList::get_total_page()
{
    return m_total_page;
}

/*****************************************************************************
 * @ name          : get_currentPage_xml_by_index
 * @ description   : 根据索引获取当前页文件名
 * @ param - index : 索引
 * @ return        : 文件名
 *****************************************************************************/
QString XmlList::get_currentPage_xml_by_index(int index)
{
    QString str_ret = QString("");

    if (index >= m_page_list.count())
        return str_ret;

    str_ret = m_page_list.at(index);

    return str_ret;
}

/*****************************************************************************
 * @ name        : get_current_page_xml_count
 * @ description : 获取当前页文件数
 * @ param       : NULL
 * @ return      : 当前页文件数
 *****************************************************************************/
int XmlList::get_current_page_xml_count()
{
    return m_page_list.count();
}

/*****************************************************************************
 * @ name        : get_total_xml_count
 * @ description : 获取总文件数
 * @ param       : NULL
 * @ return      : 总文件数
 *****************************************************************************/
int XmlList::get_total_xml_count()
{
    return m_xml_list.count();
}

void XmlList::set_select_xml_index(int index)
{
    if (m_select_index < m_xml_list.count())
        m_select_index = index;
}

QString XmlList::get_select_xml()
{
    if (m_select_index >= 0 && m_select_index < m_xml_list.count()) {
        return m_xml_list.at(m_select_index);
    } else {
        return QString("");
    }
}


void XmlList::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void XmlList::del_xml_by_index(int index)
{
    if (index < m_xml_list.count()) {
        QFile file(QString("%1%2").arg(m_savePath).arg(m_xml_list.at(index)));
        if (file.remove()) {
            qDebug() << QString("%1%2").arg(m_savePath).arg(m_xml_list.at(index)) << "remove successed .";
        } else {
            qDebug() << QString("%1%2").arg(m_savePath).arg(m_xml_list.at(index)) << "remove failed !!!";
        }

        m_xml_list.removeAt(index);
        if (m_select_index == index) {
            m_select_index = -1;
        } else if (m_select_index > index) {
            m_select_index--;
        }
        m_total_page = m_xml_list.count() / 5 + (m_xml_list.count()%5 > 0 ? 1 : 0);
        if (m_current_page > m_total_page) {
            m_current_page = m_total_page;
        }

        int start_index = 5*(m_current_page-1) > 0 ? 5*(m_current_page-1) : 0;
        int end_index   = 5*(m_current_page-1)+5 < m_xml_list.count() ? 5*(m_current_page-1)+5 : m_xml_list.count();

        qDebug() << m_current_page << " - " << m_total_page << " - " << start_index << " - " << end_index;

        m_page_list.clear();
        for (int i = start_index; i < end_index; i++)
            m_page_list.append(m_xml_list.at(i));
    } else {
        qDebug() << "index:" << index << "is bigger than" << m_xml_list.count();
    }
}





















