#ifndef HP_COMMON_DIALOG_CANCEL_H
#define HP_COMMON_DIALOG_CANCEL_H

#include <QWidget>
#include <QDebug>
#include "hi384_protocol.h"


namespace Ui {
class hp_common_dialog_cancel;
}

class hp_common_dialog_cancel : public QWidget
{
    Q_OBJECT
public:
    explicit hp_common_dialog_cancel(QWidget *parent = 0);
    ~hp_common_dialog_cancel();

    void Set_label_text(QString str);
    void Set_button_text(QString str);
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void hp_signal_on_cancel_clicked();
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
public slots:
private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::hp_common_dialog_cancel *ui;
};

#endif // HP_COMMON_DIALOG_CANCEL_H
