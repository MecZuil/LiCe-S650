#include "hp_sort.h"

#include <QDateTime>
#include <QMutexLocker>
#include <QRegularExpression>
#include <algorithm>
#include <QMessageBox>

static QString hpSortExtractTimestamp(const QString &text)
{
    static const QRegularExpression re17(QStringLiteral("(\\d{17})"));
    static const QRegularExpression re14(QStringLiteral("(\\d{14})"));
    static const QRegularExpression re12(QStringLiteral("(\\d{12})"));

    QString last17;
    for (auto it = re17.globalMatch(text); it.hasNext(); )
    {
        const QRegularExpressionMatch m = it.next();
        last17 = m.captured(1);
    }
    if (!last17.isEmpty())
        return last17;

    QString last14;
    for (auto it = re14.globalMatch(text); it.hasNext(); )
    {
        const QRegularExpressionMatch m = it.next();
        last14 = m.captured(1);
    }
    if (!last14.isEmpty())
        return last14;

    QString last12;
    for (auto it = re12.globalMatch(text); it.hasNext(); )
    {
        const QRegularExpressionMatch m = it.next();
        last12 = m.captured(1);
    }
    if (!last12.isEmpty())
        return last12;

    return QString();
}

static qint64 hpSortBuildKey(const QString &timeStr, const QFileInfo &fileInfo)
{
    bool ok = false;
    qint64 key = timeStr.toLongLong(&ok);
    if (ok)
        return key;

    return fileInfo.lastModified().toMSecsSinceEpoch();
}

static qint64 hpSortBuildTieKey(const QString &filePath)
{
    static const QRegularExpression reParen(QStringLiteral("\\((\\d+)\\)(?!.*\\(\\d+\\))"));
    const QRegularExpressionMatch m = reParen.match(filePath);
    if (m.hasMatch())
    {
        bool ok = false;
        const qint64 idx = m.captured(1).toLongLong(&ok);
        if (ok && idx >= 0)
            return (1LL << 62) | idx;
    }

    static const QRegularExpression reUnderscore(QStringLiteral("_(\\d+)\\.[^.]+$"));  //匹配_123这种格式
    const QRegularExpressionMatch m2 = reUnderscore.match(filePath);
    if (m2.hasMatch())
    {
        bool ok = false;
        const qint64 idx = m2.captured(1).toLongLong(&ok);
        if (ok && idx >= 0)
            return (1LL << 62) | idx;
    }

    return static_cast<qint64>(static_cast<quint32>(qHash(filePath)));
}

static QString hpSortReadCapTimeFast(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return QString("error");

    const qint64 fileSize = file.size();
    if (fileSize < static_cast<qint64>(sizeof(tagnum_t)))
        return QString("error");

    tagnum_t tagNum;
    if (!file.seek(fileSize - static_cast<qint64>(sizeof(tagnum_t))))
        return QString("error");
    if (file.read(reinterpret_cast<char *>(&tagNum), sizeof(tagnum_t)) != static_cast<qint64>(sizeof(tagnum_t)))
        return QString("error");

    if (tagNum.nTag != TAGNUM_TAG && tagNum.nTag != PANORAMA_FILEINFO_TAG)
        return QString("error");

    const int maxTagCount = (tagNum.nTag == PANORAMA_FILEINFO_TAG) ? 2 : 8;
    if (tagNum.num <= 0 || tagNum.num > maxTagCount)
        return QString("error");

    const qint64 tagInfosBytes = static_cast<qint64>(sizeof(taginfo_t)) * tagNum.num;
    const qint64 tagInfosOffset = fileSize - static_cast<qint64>(sizeof(tagnum_t)) - tagInfosBytes;
    if (tagInfosOffset < 0)
        return QString("error");
    if (!file.seek(tagInfosOffset))
        return QString("error");

    QByteArray tagInfosData = file.read(tagInfosBytes);
    if (tagInfosData.size() != tagInfosBytes)
        return QString("error");

    QVector<taginfo_t> tagInfos(tagNum.num);
    memcpy(tagInfos.data(), tagInfosData.constData(), static_cast<size_t>(tagInfosBytes));

    const qint64 headOffset = tagInfos[0].offset;
    if (headOffset < 0 || headOffset + 8 > fileSize)
        return QString("error");

    int nDesLen = 0;
    if (!file.seek(headOffset + 4))
        return QString("error");
    if (file.read(reinterpret_cast<char *>(&nDesLen), 4) != 4)
        return QString("error");

    if (nDesLen <= 0)
        return QString("error");

    const int nLessLen = qMin(nDesLen, static_cast<int>(sizeof(file_info_t)));
    if (headOffset + nLessLen > fileSize)
        return QString("error");
    if (!file.seek(headOffset))
        return QString("error");

    QByteArray headData = file.read(nLessLen);
    if (headData.size() != nLessLen)
        return QString("error");

    image_head_t head;
    memset(reinterpret_cast<char *>(&head), 0, sizeof(image_head_t));
    memcpy(reinterpret_cast<char *>(&head), headData.constData(), static_cast<size_t>(nLessLen));

    const QString capTimeRaw(head.file.CapTime);
    const QString ts = hpSortExtractTimestamp(capTimeRaw);
    if (!ts.isEmpty())
        return ts;
    return capTimeRaw.isEmpty() ? QString("error") : capTimeRaw;

    // const QString capTimeRaw(QString::fromLatin1(head.file.CapTime));
    // const QString ts = hpSortExtractTimestamp(capTimeRaw);
    // if (!ts.isEmpty())
    //     return ts;

    // const QString capTimeTrimmed = capTimeRaw.trimmed();
    // if (capTimeTrimmed.isEmpty())
    //     return QString("error");

    // static const QStringList dateFormats = {
    //     QStringLiteral("yyyy-MM-dd HH:mm:ss"),
    //     QStringLiteral("yyyy/MM/dd HH:mm:ss"),
    //     QStringLiteral("yyyy:MM:dd HH:mm:ss"),
    //     QStringLiteral("yyyy-MM-dd HH:mm"),
    //     QStringLiteral("yyyy/MM/dd HH:mm"),
    //     QStringLiteral("yyyy:MM:dd HH:mm"),
    //     QStringLiteral("yyyyMMddHHmmss"),
    //     QStringLiteral("yyyyMMddHHmm"),
    // };
    // for (const QString &fmt : dateFormats) {
    //     QDateTime dt = QDateTime::fromString(capTimeTrimmed, fmt);
    //     if (dt.isValid()) {
    //         return dt.toString(QStringLiteral("yyyyMMddHHmmss"));
    //     }
    // }

    // return capTimeRaw;

}

HpSort::HpSort(QObject *parent) : QThread(parent)
{
    m_isSdinsert = true;
    m_isSortOver = false;
    m_isNeedResort = true;
    m_firstSort = false;
    m_initFlag = false;
    m_isGetFile = false;
    m_isAdd = false;
    m_isStartSort = false;
    m_originFilePathList.clear();
    m_originFileInfoList.clear();
    m_fileInfoList.clear();
    m_items.clear();
    m_indexByPath.clear();
}

HpSort::~HpSort()
{
    {
        QMutexLocker locker(&m_mutex);
        m_stopRequested = true;
        m_workAvailable.wakeOne();
    }
    wait();
}

void HpSort::startSort()
{
    QMutexLocker locker(&m_mutex);
    if (!m_isStartSort)
    {
        m_isStartSort = true;
        m_isSortOver = false;
        m_isNeedResort = false;
        m_fullRescanRequested = true;
        start();
        m_workAvailable.wakeOne();
        return;
    }

    m_isSortOver = false;
    m_isNeedResort = false;
    m_fullRescanRequested = true;
    m_workAvailable.wakeOne();
}

void HpSort::run()
{
    for(;;)
    {
        bool doRescan = false;
        QStringList adds;
        QStringList removes;

        {
            QMutexLocker locker(&m_mutex);
            while (!m_stopRequested && !m_fullRescanRequested && m_pendingAdds.isEmpty() && m_pendingRemoves.isEmpty())
            {
                m_workAvailable.wait(&m_mutex);
            }
            if (m_stopRequested)
                return;

            doRescan = m_fullRescanRequested;
            m_fullRescanRequested = false;

            adds = m_pendingAdds;
            m_pendingAdds.clear();

            removes = m_pendingRemoves;
            m_pendingRemoves.clear();
        }

        if (doRescan)
            processFullRescan();

        if (!removes.isEmpty())
            processRemoveFiles(removes);

        if (!adds.isEmpty())
            processAddFiles(adds);

        hpSortNewFile();
    }
}

bool HpSort::isSortOver()
{
    QMutexLocker locker(&m_mutex);
    return m_isSortOver;
}

void HpSort::gstSortFileInfo()
{
    QDir dir;
    QStringList filters;
    filters.append(QString("*.jpg"));
    filters.append(QString("*.bmp"));
    filters.append(QString("*.png"));
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setNameFilters(filters);
    dir.setSorting(QDir::Time);
    QStringList dirlist = getFileList();
    qDebug() << " dirlist" << dirlist;
    m_originFilePathList.clear();
    m_originFileInfoList.clear();
    if(dirlist.count() != 0)
    {
        for(int i = 0; i < dirlist.count(); i++)
        {
            dir.cd(dirlist.at(i));
            m_originFilePathList.append(dir.entryInfoList());
        }
    }
    if(m_originFilePathList.count() == 0)
    {
        m_initFlag = true;
        return;
    }
    for(int i = 0; i < m_originFilePathList.size(); i++)
    {
        QFileInfo fileInfo = m_originFilePathList.at(i);
        if(fileInfo.fileName().contains(".jpg",Qt::CaseInsensitive) ||
                fileInfo.fileName().contains(".bmp",Qt::CaseInsensitive) ||
                fileInfo.fileName().contains(".png",Qt::CaseInsensitive))
        {
            m_originFileInfoList.append(fileInfo);
        }
    }
    m_initFlag = true;
}

void HpSort::sdReinsert(bool sdinsert)
{
    QMutexLocker locker(&m_mutex);
    if (!sdinsert)
    {
        m_isNeedResort = true;
        return;
    }

    if (!m_isStartSort)
    {
        m_isStartSort = true;
        m_isNeedResort = false;
        m_isSortOver = false;
        m_fullRescanRequested = true;
        start();
        m_workAvailable.wakeOne();
        return;
    }

    if (m_isNeedResort)
    {
        m_isNeedResort = false;
        m_isSortOver = false;
        m_fullRescanRequested = true;
        m_workAvailable.wakeOne();
    }
}

void HpSort::setFileToSort()
{
    startSort();
}

QFileInfoList HpSort::getSortFileList()
{
    QFileInfoList fileList;
    {
        QMutexLocker locker(&m_mutex);
        fileList = m_fileInfoList;
    }
    std::reverse(fileList.begin(), fileList.end());
    return fileList;
}

QStringList HpSort::getFileList()
{
    QStringList subDirs;
    QDir dir("/run/media/mmcblk2p1/");
    dir.setSorting(QDir::Name);
    QFileInfoList fileList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QFileInfo fileInfo, fileList) {
        if (fileInfo.isDir()) {
            subDirs.append(fileInfo.filePath());
            qDebug()<<"!________________! filename :"<<fileInfo.filePath();
        }
    }

    for(int i = 0; i < subDirs.size(); i++)
    {
        QString qstr = subDirs.at(i);
        qDebug() << "filepath:" << qstr; // 打印文件路径
        // 原有逻辑...
    }
    return subDirs;
}

//深度搜索QDir目录下文件 没用到暂时
void HpSort::getAllFiles(const QString &directory, QStringList &fileList) {
    QDir dir(directory);
    QFileInfoList infoList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QFileInfo info, infoList) {
        if (info.isDir()) {
            getAllFiles(info.filePath(), fileList);
        } else {
            fileList.append(info.filePath());
        }
    }
}

QString HpSort::getFileTime(QString filePath)
{
    if(filePath.contains("PAN") || filePath.contains("GW") || filePath.contains("-2(") || filePath.contains("-1("))
    {
        const QString ts = hpSortExtractTimestamp(filePath);
        if (!ts.isEmpty())
            return ts;
        return QString("error");
    }

    static const QRegularExpression reTimeNum(QStringLiteral("\\d{12}_\\d+\\.[^.]+$"));  //正则匹配12位时间戳带_的格式,如202605281016_3
    if(reTimeNum.match(filePath).hasMatch())
    {
        const QString ts = hpSortExtractTimestamp(filePath);
        if (!ts.isEmpty())
            return ts;
    }
    return hpSortReadCapTimeFast(filePath);
}

void HpSort::addNewFile(QString filePath)
{
    QMutexLocker locker(&m_mutex);
    if (!m_isStartSort)
    {
        m_isStartSort = true;
        m_isNeedResort = false;
        m_isSortOver = false;
        m_fullRescanRequested = true;
        start();
        m_workAvailable.wakeOne();
        return;
    }

    m_isSortOver = false;
    m_pendingAdds.append(filePath);
    m_workAvailable.wakeOne();
}


void HpSort::removeFile(QString filePath)
{
    qDebug() << __func__ << filePath;
    QMutexLocker locker(&m_mutex);
    m_isSortOver = false;
    m_pendingRemoves.append(filePath);
    m_workAvailable.wakeOne();
}

void HpSort::clearSortList(bool isCleanAll)
{
    QMutexLocker locker(&m_mutex);
    if (isCleanAll)
    {
        m_originFileInfoList.clear();
        m_fileInfoList.clear();
        m_originFilePathList.clear();
        m_items.clear();
        m_indexByPath.clear();
        m_pendingAdds.clear();
        m_pendingRemoves.clear();
        m_firstSort = true;
    }
    m_isSortOver = true;
}

void HpSort::hpSortNewFile()
{
    QVector<SortItem> itemsCopy;
    {
        QMutexLocker locker(&m_mutex);
        itemsCopy = m_items;
    }

    std::stable_sort(itemsCopy.begin(), itemsCopy.end(), [](const HpSort::SortItem &a, const HpSort::SortItem &b) {
        if (a.sortKey != b.sortKey)
            return a.sortKey > b.sortKey;
        if (a.tieKey != b.tieKey)
            return a.tieKey > b.tieKey;
        return a.filePath > b.filePath;
    });

    QFileInfoList sortedFiles;
    sortedFiles.reserve(itemsCopy.size());
    QHash<QString, int> newIndex;
    newIndex.reserve(itemsCopy.size());
    for (int i = 0; i < itemsCopy.size(); ++i)
    {
        newIndex.insert(itemsCopy[i].filePath, i);
        if (!QFile::exists(itemsCopy[i].filePath))
            continue;
        sortedFiles.append(itemsCopy[i].fileInfo);
    }

    {
        QMutexLocker locker(&m_mutex);
        m_items = itemsCopy;
        m_indexByPath = newIndex;
        m_fileInfoList = sortedFiles;
        m_firstSort = true;
        m_isSortOver = true;
        m_isNeedResort = false;
        m_initFlag = true;
    }
}

void HpSort::processFullRescan()
{
    QString timeReport = "【SD卡插入耗时】\n\n";
    struct timeval tv_begin, tv_end;
    long t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    long tt1 = 0, tt2 = 0, tt3 = 0, tt4 = 0;
    gettimeofday(&tv_begin, NULL);
	
    QDir dir;
    QStringList filters;
    filters.append(QString("*.jpg"));
    filters.append(QString("*.bmp"));
    filters.append(QString("*.png"));
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setNameFilters(filters);
    dir.setSorting(QDir::Time);
    const QStringList dirlist = getFileList();

    QFileInfoList originFilePathList;
    if (dirlist.count() != 0)
    {
        for(int i = 0; i < dirlist.count(); i++)
        {
            dir.cd(dirlist.at(i));
            originFilePathList.append(dir.entryInfoList());
        }
    }

	
    gettimeofday(&tv_end, NULL);
    t1 = (tv_end.tv_sec - tv_begin.tv_sec) * 1000 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
    timeReport += QString("1. 获取文件列表: %1 ms\n").arg(t1);
	
    gettimeofday(&tv_begin, NULL);
    QVector<SortItem> items;
    items.reserve(originFilePathList.size());
    QHash<QString, int> index;
    index.reserve(originFilePathList.size());

    for(int i = 0; i < originFilePathList.size(); i++)
    {
        QFileInfo fileInfo = originFilePathList.at(i);
        if(!(fileInfo.fileName().contains(".jpg",Qt::CaseInsensitive) ||
             fileInfo.fileName().contains(".bmp",Qt::CaseInsensitive) ||
             fileInfo.fileName().contains(".png",Qt::CaseInsensitive)))
        {
            continue;
        }

        const QString filePath = fileInfo.filePath();
        const QString timeStr = getFileTime(filePath);
        if (timeStr == "error" || timeStr.contains("error"))
            continue;

        SortItem item;
        item.filePath = filePath;
        item.timeStr = timeStr;
        item.sortKey = hpSortBuildKey(timeStr, fileInfo);
        item.tieKey = hpSortBuildTieKey(filePath);
        item.fileInfo = fileInfo;

        index.insert(filePath, items.size());
        items.append(item);
    }
	
	gettimeofday(&tv_end, NULL);
//    t3 = (tv_end.tv_sec - tv_begin.tv_sec) * 1000 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
//    timeReport += QString("1. 拾取文件: %1 ms\n").arg(t3);
	
//	timeReport += QString("【总耗时】: %1 ms").arg(t1 + t2 + t3 + t4 +
//                                                  tt1 + tt2 + tt3 + tt4);
//    QMessageBox::information(nullptr, "性能测试结果", timeReport);

    {
        QMutexLocker locker(&m_mutex);
        m_originFilePathList = originFilePathList;
        m_items = items;
        m_indexByPath = index;
        m_isSortOver = false;
        m_initFlag = true;
    }
}

void HpSort::processAddFiles(const QStringList &filePaths)
{
    for (const QString &filePath : filePaths)
    {
        const QFileInfo fileInfo(filePath);
        if (!fileInfo.exists())
            continue;

        const QString timeStr = getFileTime(filePath);
        if (timeStr == "error" || timeStr.contains("error"))
            continue;

        QMutexLocker locker(&m_mutex);
        upsertFileLocked(fileInfo, timeStr);
        m_isSortOver = false;
    }
}

void HpSort::processRemoveFiles(const QStringList &filePaths)
{
    QMutexLocker locker(&m_mutex);
    for (const QString &filePath : filePaths)
    {
        const int idx = m_indexByPath.value(filePath, -1);
        if (idx < 0)
            continue;

        const int lastIndex = m_items.size() - 1;
        if (idx != lastIndex)
        {
            m_items[idx] = m_items[lastIndex];
            m_indexByPath[m_items[idx].filePath] = idx;
        }
        m_items.removeLast();
        m_indexByPath.remove(filePath);
    }
    m_isSortOver = false;
}

void HpSort::upsertFileLocked(const QFileInfo &fileInfo, const QString &timeStr)
{
    const QString filePath = fileInfo.filePath();
    const int existingIndex = m_indexByPath.value(filePath, -1);
    if (existingIndex >= 0)
    {
        m_items[existingIndex].timeStr = timeStr;
        m_items[existingIndex].sortKey = hpSortBuildKey(timeStr, fileInfo);
        m_items[existingIndex].tieKey = hpSortBuildTieKey(filePath);
        m_items[existingIndex].fileInfo = fileInfo;
        return;
    }

    SortItem item;
    item.filePath = filePath;
    item.timeStr = timeStr;
    item.sortKey = hpSortBuildKey(timeStr, fileInfo);
    item.tieKey = hpSortBuildTieKey(filePath);
    item.fileInfo = fileInfo;
    m_indexByPath.insert(filePath, m_items.size());
    m_items.append(item);
}
