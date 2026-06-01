#ifndef HP_BLE_DIALOG_H
#define HP_BLE_DIALOG_H

#include  <QWidget>
#include  "hpxmlreader.h"

namespace Ui {
class Hp_Ble_Dialog;
}

class Hp_Ble_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Ble_Dialog(QWidget *parent = 0);
    ~Hp_Ble_Dialog();

    int signal_type;

    void hp_setDefine_S3x0(bool isSelect);
    void setDialogText(QString text);
    void setSingleButton();
private slots:


    void on_pushButton_ok_released();

    void on_pushButton_cancel_released();

signals:

    void signal_ble_match_delete(int signal_type);

public slots:

    void slot_ble_dialog_type(int type);
private:
    Ui::Hp_Ble_Dialog *ui;
    bool isS3x0;
    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
};

#endif // HP_BLE_DIALOG_H
