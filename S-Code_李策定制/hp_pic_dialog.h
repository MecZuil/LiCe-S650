#ifndef HP_PIC_DIALOG_H
#define HP_PIC_DIALOG_H

#include  <QWidget>
#include  <QTime>
#include  <QtCore>
#include  "hpxmlreader.h"
namespace Ui {
class Hp_Pic_Dialog;
}

class Hp_Pic_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Pic_Dialog(QWidget *parent = 0);
    ~Hp_Pic_Dialog();
     void time_select(int time);

     void hp_setDefine_S3x0(bool isSelect);
private slots:
    void on_pushButton_exit_released();
    void slot_handleTimeout();

private:
    Ui::Hp_Pic_Dialog *ui;
    QTimer *timer;
    HpXmlReader hpxmlreader;
     void changeEvent(QEvent *e);



};

#endif // HP_PIC_DIALOG_H
