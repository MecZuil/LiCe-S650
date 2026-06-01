#ifndef CREATETHREAD_H
#define CREATETHREAD_H

#include <QObject>
#include <QThread>
#include <QMap>

#include "analydataop.h"

#define ANALYSIS_FILE_NAME      "/mnt/data/analysis/hp_analysis_data.db"

typedef struct{
    int id;
    QString name;
    QString type;
    int x;
    int y;
    int x_p;
    int y_p;
    float maxTemp;
    float minTemp;
    float aveTemp;
}PART_INFO;

typedef struct{
    QString date;
    QString deviceInfo;
    int count;
    PART_INFO partInfo[20];
}ANALYSIS_INFO;

class createThread : public QThread
{
    Q_OBJECT
public:
    explicit createThread(QObject *parent = 0);
    ~createThread();

    void Remove_sqlFile();
    void create_analysis_db();

    void Open_analysis_db();
    void Close_analysis_db();

    void Insert_table_analysis_db(QString tableName);
    void Delete_table_analysis_db(QString tableName);

    void Insert_line_analysis_db(QString tableName, QList<QString> listData);
    void Delete_line_analysis_db(QString tabName, QPair<QString, QString> where);
    bool Exist_line_analysis_db(QString tableName, QPair<QString, QString> where);

    void Get_unit_change(QString unitChange);

    void Set_current_dbName(QString dbName);

    void Init_MapDevices(QString fileName);
    void Init_MapFlags();
    void Set_capturt_flag(QString deviceInfo);
    QMap<QString, int> Get_MapDevices() { return m_mapDevices; }
    QMap<QString, int> Get_MapPkgs() { return m_mapPkgs; }

    void Get_historyData(QString pkgName, QString deviceInfo);

    Q_INVOKABLE int get_unit_count() { return m_units.count(); }
    Q_INVOKABLE QString get_unit_name(int index);

    Q_INVOKABLE int get_historyData_count() { return map_analysisInfo.count(); }
    Q_INVOKABLE float get_maxTemp();
    Q_INVOKABLE float get_minTemp();
    Q_INVOKABLE float get_temp_by_index(int deviceIndex, int partIndex);

    Q_INVOKABLE void reset_current_index(int index);
    Q_INVOKABLE void pre_current_index();
    Q_INVOKABLE void next_current_index();
    Q_INVOKABLE bool get_pre_btn_status();
    Q_INVOKABLE bool get_next_btn_status();
    Q_INVOKABLE int get_current_index() { return m_index; }
    Q_INVOKABLE int exist_history_by_info(QList<QString> infoList);
    Q_INVOKABLE void reset_capture_flag();
    Q_INVOKABLE void reset_capture_flag_by_index(QString deviceInfo);

    QString replace_covert_char(QString strName);

    int get_currentdb_flag(QList<QPair<QString, QString>> &value);

    void set_sd_path(QString strPath);

signals:

public slots:

protected:
    void run();

private:
    AnalydataOP m_ana_op;

    QStringList m_units;

    QString m_strPath;

    int m_index;

    QString m_current_dbName;

    QMap<QString, int> m_mapDevices;
    QMap<QString, int> m_mapPkgs;
    QMap<int, ANALYSIS_INFO> map_analysisInfo;

    void Delete_extra_data_db(QString pkgName, int deviceId);

};

#endif // CREATETHREAD_H



