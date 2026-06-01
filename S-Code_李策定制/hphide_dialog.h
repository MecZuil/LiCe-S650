#ifndef HPHIDE_DIALOG_H
#define HPHIDE_DIALOG_H

#include  <QWidget>

#include  <QTime>
#include  <QtCore>
#include  "hpxmlreader.h"
namespace Ui {
class Hphide_Dialog;
}

class Hphide_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Hphide_Dialog(QWidget *parent = 0);
    ~Hphide_Dialog();


    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void on_pushButton_released();
    void slot_handleTimeout();

private:
    Ui::Hphide_Dialog *ui;
    QTimer *timer;

    HpXmlReader hpxmlreader;
    void time_select(int time);
};

#endif // HPHIDE_DIALOG_H
