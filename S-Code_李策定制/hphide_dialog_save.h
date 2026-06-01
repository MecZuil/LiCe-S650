#ifndef HPHIDE_DIALOG_SAVE_H
#define HPHIDE_DIALOG_SAVE_H

#include  <QWidget>
#include  <QTime>
#include  <QtCore>
#include  "hpxmlreader.h"

namespace Ui {
class Hphide_Dialog_SAVE;
}

class Hphide_Dialog_SAVE : public QWidget
{
    Q_OBJECT

public:
    explicit Hphide_Dialog_SAVE(QWidget *parent = 0);
    ~Hphide_Dialog_SAVE();

    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void slot_handleTimeout();
private:
    Ui::Hphide_Dialog_SAVE *ui;
    HpXmlReader hpxmlreader;
        QTimer *timer;
};

#endif // HPHIDE_DIALOG_SAVE_H
