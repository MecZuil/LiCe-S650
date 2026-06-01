#ifndef HPHIDE_DIALOG_LO_H
#define HPHIDE_DIALOG_LO_H

#include  <QWidget>
#include  <QTime>
#include  <QtCore>
#include  "hpxmlreader.h"

namespace Ui {
class Hphide_Dialog_LO;
}

class Hphide_Dialog_LO : public QWidget
{
    Q_OBJECT

public:
    explicit Hphide_Dialog_LO(QWidget *parent = 0);
    ~Hphide_Dialog_LO();

    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void on_pushButton_released();
    void slot_handleTimeout();
private:
    Ui::Hphide_Dialog_LO *ui;
    QTimer *timer;

    void time_select(int time);

    HpXmlReader hpxmlreader;
    int state_lo;   //初始状态设置为0，
};

#endif // HPHIDE_DIALOG_LO_H
