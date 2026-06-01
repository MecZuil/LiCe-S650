#ifndef HP_DEFAULTDIALOG_H
#define HP_DEFAULTDIALOG_H

#include  <QDialog>
#include  <QAbstractButton>
#include  <QPushButton>
#include  <QDebug>
#include  "hpxmlreader.h"

namespace Ui {
class hp_DefaultDialog;
}

class hp_DefaultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit hp_DefaultDialog(QWidget *parent = 0);
    ~hp_DefaultDialog();

    void default_button_state();
    void hp_setDefine_S3x0(bool isSelect);
    void hp_setTitleText(QString text);
signals:
    void signal_set_default();
    void signal_close_ble_lie();  //发送信号将蓝牙已匹配列表清空
    void signal_defaultdialog_set_lcd_offed_state();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_pushButton_ok_clicked();


    void on_pushButton_cancel_clicked();

private:
    Ui::hp_DefaultDialog *ui;

    bool m_isChangeText;
    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_DEFAULTDIALOG_H
