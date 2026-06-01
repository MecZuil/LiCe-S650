#ifndef HP_DIALOG_H
#define HP_DIALOG_H

#include  <QWidget>
#include  <QTimer>
#include  <QKeyEvent>
#include  <QDebug>
#include  "hi384_protocol.h"
namespace Ui {
class Hp_Dialog;
}

class Hp_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Dialog(QWidget *parent = 0);
    ~Hp_Dialog();
    void setText(QString test);
    void setDelayClose(int msec);
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_set_dialog_close(bool isClose);
public slots:
    void delayClose();
protected:
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::Hp_Dialog *ui;
    bool isDelayClose;
    void changeEvent(QEvent *e);
};

#endif // HP_DIALOG_H
