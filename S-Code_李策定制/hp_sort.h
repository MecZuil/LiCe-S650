#ifndef HP_SORT_H
#define HP_SORT_H

#include <QObject>
#include <QElapsedTimer>
#include <QThread>
#include <QFile>
#include <QDir>
#include <QHash>
#include <QMutex>
#include <QStringList>
#include <QWaitCondition>
#include <QVector>
#include <QMessageBox>
#include "hpdomainthread.h"

/**
 * @class HpSort
 * @brief 文件排序线程类，用于对SD卡中的图片文件按时间排序
 * 
 * HpSort是一个继承自QThread的线程类，专门用于对SD卡中的图片文件
 * 按照时间戳进行排序，支持动态添加、删除文件，以及SD卡重新插入时的
 * 重新扫描和排序功能。
 */
class HpSort : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent 父对象指针
     */
    explicit HpSort(QObject *parent = nullptr);
    
    /**
     * @brief 析构函数
     */
    ~HpSort() override;
    
    /**
     * @brief 检查排序是否完成
     * @return 排序完成返回true，否则返回false
     */
    bool isSortOver();
    
    /**
     * @brief 启动排序过程
     * 
     * 启动排序线程并触发完整的文件扫描和排序操作
     */
    void startSort();
    
    /**
     * @brief 设置要排序的文件
     * 
     * 调用startSort()方法开始排序过程
     */
    void setFileToSort();
    
    /**
     * @brief 处理SD卡重新插入事件
     * @param sdinsert SD卡是否插入
     * 
     * 当SD卡重新插入时，触发重新扫描和排序
     */
    void sdReinsert(bool sdinsert);
    
    /**
     * @brief 从排序列表中移除文件
     * @param filePath 要移除的文件路径
     */
    void removeFile(QString filePath);
    
    /**
     * @brief 对文件信息进行排序
     * 
     * 扫描SD卡中的图片文件并准备排序
     */
    void gstSortFileInfo();
    
    /**
     * @brief 对新文件进行排序
     * 
     * 对当前所有文件进行排序并更新排序列表
     */
    void hpSortNewFile();
    
    /**
     * @brief 清空排序列表
     * @param isCleanAll 是否清空所有数据
     * 
     * 格式化为清空时，isCleanAll为true；非格式化时也为true
     */
    void clearSortList(bool isCleanAll);//格式化为清空，非格式化为真
    
    /**
     * @brief 获取文件的时间戳
     * @param filePath 文件路径
     * @return 文件的时间戳字符串
     * 
     * 从文件名或文件内容中提取时间戳
     */
    QString getFileTime(QString filePath);
    
    /**
     * @brief 获取SD卡中的文件夹列表
     * @return 文件夹路径列表
     * 
     * 扫描SD卡根目录下的所有文件夹
     */
    QStringList getFileList();
    
    /**
     * @brief 获取排序后的文件列表
     * @return 排序后的文件信息列表
     * 
     * 返回按时间降序排序的文件信息列表
     */
    QFileInfoList getSortFileList();
protected:
    /**
     * @brief 线程运行函数
     * 
     * 线程的主循环，处理排序请求和文件操作
     */
    void run();
signals:

public slots:
    /**
     * @brief 添加新文件到排序列表
     * @param filePath 新文件的路径
     */
    void addNewFile(QString filePath);
private:
    /**
     * @brief 通过递归深度搜索路径directory内的文件并加入filelist
     *
    */
    void getAllFiles(const QString &directory, QStringList &fileList) ;
    /**
     * @brief 处理完整的文件重新扫描
     * 
     * 扫描SD卡中的所有图片文件并准备排序
     */
    void processFullRescan();
    
    /**
     * @brief 处理添加文件操作
     * @param filePaths 要添加的文件路径列表
     */
    void processAddFiles(const QStringList &filePaths);
    
    /**
     * @brief 处理移除文件操作
     * @param filePaths 要移除的文件路径列表
     */
    void processRemoveFiles(const QStringList &filePaths);
    
    /**
     * @brief 线程安全地添加或更新文件信息
     * @param fileInfo 文件信息
     * @param timeStr 时间戳字符串
     */
    void upsertFileLocked(const QFileInfo &fileInfo, const QString &timeStr);

    /**
     * @struct SortItem
     * @brief 排序项结构体，存储文件的排序相关信息
     */
    struct SortItem
    {
        QString filePath;    ///< 文件路径
        QString timeStr;     ///< 时间戳字符串
        qint64 sortKey = 0;  ///< 排序键值
        qint64 tieKey = 0;   ///< 平局键值（时间相同时使用）
        QFileInfo fileInfo;  ///< 文件信息
    };

    QVector<SortItem> m_items;              ///< 排序项列表
    QHash<QString, int> m_indexByPath;      ///< 文件路径到索引的映射
    QFileInfoList m_originFileInfoList;     ///< 原始文件信息列表
    QFileInfoList m_fileInfoList;           ///< 排序后的文件信息列表
    QFileInfoList m_originFilePathList;     ///< 原始文件路径列表
    bool m_isStartSort;                     ///< 是否开始排序
    bool m_isGetFile;                       ///< 是否获取文件
    bool m_isSortOver;                      ///< 排序是否完成
    bool m_isNeedResort;                    ///< 是否需要重新排序
    bool m_firstSort;                       ///< 是否是首次排序
    bool m_initFlag;                        ///< 初始化标志
    bool m_isAdd;                           ///< 是否添加文件
    bool m_isSdinsert;                      ///< SD卡是否插入

    QMutex m_mutex;                         ///< 互斥锁，保证线程安全
    QWaitCondition m_workAvailable;         ///< 等待条件，用于线程同步
    bool m_stopRequested = false;           ///< 是否请求停止线程
    bool m_fullRescanRequested = false;     ///< 是否请求完整重新扫描
    QStringList m_pendingAdds;              ///< 待添加的文件路径列表
    QStringList m_pendingRemoves;           ///< 待移除的文件路径列表
};

#endif // HP_SORT_H
