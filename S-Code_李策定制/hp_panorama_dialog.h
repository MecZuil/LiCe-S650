#ifndef HP_PANORAMA_DIALOG_H
#define HP_PANORAMA_DIALOG_H

#include <QDialog>
#include <QDebug>
#include "hpxmlreader.h"
namespace Ui {
class Hp_Panorama_Dialog;
}

class Hp_Panorama_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Hp_Panorama_Dialog(QWidget *parent = nullptr);
    ~Hp_Panorama_Dialog();
    int signal_type;

    void hp_setDefine_S3x0(bool isSelect);
    void setDialogText(QString text);

private slots:
    void on_pushButton_ok_released();
    void on_pushButton_cancel_released();

signals:
    void signal_panorama_start();
    void signal_update_lcdoff_time(bool isScreenShot);//屏幕背光事件刷新
public slots:
    void slot_panorama_dialog_type(int type);

private:
    Ui::Hp_Panorama_Dialog *ui;
    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
};

#endif // HP_PANORAMA_DIALOG_H
