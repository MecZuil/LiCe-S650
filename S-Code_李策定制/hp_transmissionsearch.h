#ifndef HP_TRANSMISSIONSEARCH_H
#define HP_TRANSMISSIONSEARCH_H

#include <QWidget>
#include <QMap>
#include <QDebug>
#include <QString>

namespace Ui {
class Hp_TransmissionSearch;
}

class Hp_TransmissionSearch : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_TransmissionSearch(QWidget *parent = nullptr);
    ~Hp_TransmissionSearch();
    void hp_setDefine_S3x0(bool isS3X0);
    QString m_currMacAddr;
public slots:
    void slot_set_transmission_addr(QString addr);

    void slot_get_ble_msg(QString addrs);

signals:
    void signal_link_transmission(QString addr);

    void signal_start_get_xml();

    void signal_get_ble_msg();
private slots:
    void on_listWidget_2_currentRowChanged(int currentRow);

    void on_pushButton_3_clicked();

    void on_toolButton_back_clicked();

    void on_pushButton_getXml_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::Hp_TransmissionSearch *ui;
    QMap<QString, QString> m_bleNameMacAddr;
};

#endif // HP_TRANSMISSIONSEARCH_H
