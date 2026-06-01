#ifndef FILELIST_H
#define FILELIST_H

#include <QObject>
#include <QSet>
#include <QStringList>

class CImportTaskThread;

class FileList : public QObject
{
    Q_OBJECT
public:
    explicit FileList(QObject *parent = 0);
    ~FileList();
public:
    Q_INVOKABLE void add_file_list( QString str_folder_name );
    Q_INVOKABLE int get_file_count();
    Q_INVOKABLE QString get_file_path();
    Q_INVOKABLE QString get_file_name( int i );
    Q_INVOKABLE int get_file_pos( QString str_file_name );
    Q_INVOKABLE bool delete_file( QString str_file_name );

    Q_INVOKABLE QString get_pre_file_name( QString str_cur_file_name );
    Q_INVOKABLE QString get_next_file_name( QString str_cur_file_name );
    Q_INVOKABLE QString get_first_file_name();
    Q_INVOKABLE QString get_last_file_name();

    Q_INVOKABLE void get_import_task_file_list();
    Q_INVOKABLE int get_import_task_file_count();
    Q_INVOKABLE QString get_import_task_file_name( int n_index );

    Q_INVOKABLE int init_find_task_selected_list( int count );
    Q_INVOKABLE bool get_find_task_btn_status( int index, int n_current_page, int n_show_rows );
    Q_INVOKABLE void set_find_task_btn_status( int index,int n_current_page, int n_show_rows, bool status );
    Q_INVOKABLE void clear_find_task_selected_list();

    Q_INVOKABLE void get_all_import_task_file();
    Q_INVOKABLE QString get_import_task_file( int n_index );

    Q_INVOKABLE void import_task();

    Q_INVOKABLE QString get_task_progress_num();
    Q_INVOKABLE int get_progress_max_value();

    Q_INVOKABLE bool has_select_import_task();

    void set_sd_path(QString strPath);

public slots:
    void set_progress_value( int );
    void finished();

    void slot_insert_table_analysis(QString tableName);

signals:
    void changeValue( int n_progress_value );
    void importFinished();
    void task_bag_progress_num( QString s_task_progress_num );

    void signale_insert_table_analysis(QString tableName);

private:
    bool delete_dir_file(const QString &str_file_path);
    bool is_task_pack( const QString &s_src_path );
private:
    QString m_strPath;
    QString ms_folder_path;
    QString ms_file_path;
    QList<QString> m_list_file_name;

    QString ms_import_task_path;
    QList<QString> m_list_task_file_name;

    QList<bool> m_list_import_task_selected;
    int m_import_task_count;

    QSet<int> m_list_import_task_index;

    QStringList ms_list_all_import_task;

    CImportTaskThread *mp_import_task_thread;

    int mn_progress_value;
};

#endif // FILELIST_H
