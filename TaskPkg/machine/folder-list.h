#ifndef FOLDERLIST_H
#define FOLDERLIST_H

#include <QObject>
#include <QString>
#include <QTextCodec>

class FolderList : public QObject
{
    Q_OBJECT
public:
    explicit FolderList(QObject *parent = 0);
    ~FolderList();
public:
    Q_INVOKABLE void add_folder_list();
    Q_INVOKABLE int get_folder_count();
    Q_INVOKABLE QString get_folder_name( int i );
    Q_INVOKABLE int get_folder_pos( QString str_folder_name );
    Q_INVOKABLE bool delete_folder( QString str_folder_name );

    Q_INVOKABLE void get_task_select_list();
    Q_INVOKABLE int get_task_select_count();
    Q_INVOKABLE QString get_task_select_name( int i );
    Q_INVOKABLE int get_task_select_pos( QString str_task_select_name );
    Q_INVOKABLE bool delete_task_select( QString str_task_select_name );

    void set_sd_path(QString strPath);
private:
    bool delete_dir( const QString &str_path );
private:
    QString ms_folder_path;
    QString ms_task_select_path;
    QList<QString> m_list_folder_name;
    QList<QString> m_list_task_select;

    QString m_strPath;

signals:
    void signal_delete_table_analysis(QString tableName);

};

#endif // FOLDERLIST_H
