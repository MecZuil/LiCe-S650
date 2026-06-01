#ifndef IMPORTTASKTHREAD_H
#define IMPORTTASKTHREAD_H

#include <QThread>
#include <QStringList>
#include <QList>
#include <QPair>

#include "quazip/quazip.h"
#include "quazip/quazipfile.h"

#include <QSharedMemory>
#define PROGRESS_BAR_LENGTH 100
#define PART_NUM_PERTASK 3

class CImportTaskThread : public QThread
{
    Q_OBJECT
public:
    explicit CImportTaskThread(QStringList &s_list, QString s_file_path, QObject *parent = 0, bool b_taskpack = true );
    ~CImportTaskThread();
    QStringList get_unzip_file_name( const QString& s_src_path );
    void unzip_to_disk( const QString& s_src_path, const QString& s_dst_path );

    //void thread_replace_program( QString soft_name );
signals:
    void progress( int );
    void task_bag_progress_num( QString );
    void noImportUpgradeProgram();
    void createSharedMemFail();

    void Insert_table_analysis(QString tableName);

public slots:
    void stop() { mb_stopped = true; }


private:
    void run();
    QSharedMemory shared_mem;
    //void thread_upgrade_program();
    const QStringList ms_pkg_list;
    QString ms_import_file_path;
    volatile bool mb_stopped;
    bool mb_taskpack;
    bool b_code;
};

#endif // IMPORTTASKTHREAD_H
