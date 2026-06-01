#ifndef HP_WIFI_SEARCH_DIALOG_H
#define HP_WIFI_SEARCH_DIALOG_H

#include <QWidget>
#include <QString>
#include <QEvent>
#include <QTimer>
#include <QKeyEvent>
#include "hpxmlreader.h"
#include "hi384_protocol.h"

namespace Ui {
class Hp_Wifi_search_Dialog;
}

class Hp_Wifi_search_Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_Wifi_search_Dialog(QWidget *parent = 0);
    ~Hp_Wifi_search_Dialog();
    void Set_label_text(QString str);
    void Set_button_text(QString str);
    void Set_label_wait();
    void setDelayClose(int ms);
    void SetControlEnabled(int i,bool ret);
    void SetHideButton(bool ishide);
    bool Iscancel;
    bool IsEmpty;
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_set_cancel();
    void signal_IsEmpty();
public slots:
    void timer_finish();
    void slot_close();
private slots:
    void on_pushButton_ok_clicked();
protected:
    virtual void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::Hp_Wifi_search_Dialog *ui;

    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
};

#endif // HP_WIFI_SEARCH_DIALOG_H
