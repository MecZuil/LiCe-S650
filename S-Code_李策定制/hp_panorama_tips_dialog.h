#ifndef HP_PANORAMA_TIPS_DIALOG_H
#define HP_PANORAMA_TIPS_DIALOG_H

#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include "hpxmlreader.h"
#include "hi384_protocol.h"
namespace Ui {
class Hp_Panorama_Tips_Dialog;
}

class Hp_Panorama_Tips_Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_Panorama_Tips_Dialog(QWidget *parent = nullptr);
    ~Hp_Panorama_Tips_Dialog();
    void hp_setDefine5_5(bool isSelect);
    void setDialogText(QString text);//设置文本
    int signal_type;

private slots:
    void on_pushButton_ok_released();
    void on_pushButton_cancel_released();

signals:
    void signal_panorama_start();
    void signal_panorama_stop();
    void signal_update_lcdoff_time(bool isScreenShot);//屏幕背光事件刷新

public slots:
    void slot_panorama_dialog_type(int type);
protected:
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::Hp_Panorama_Tips_Dialog *ui;
    HpXmlReader hpxmlreader;
    QString m_startPanorama;
    void changeEvent(QEvent *e);
};

#endif // HP_PANORAMA_TIPS_DIALOG_H
