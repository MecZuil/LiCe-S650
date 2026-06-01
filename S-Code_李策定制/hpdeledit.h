#ifndef HPDELEDIT_H
#define HPDELEDIT_H

#include  <QWidget>
#include  "hi384_protocol.h"

namespace Ui {
class hpDelEdit;
}

class hpDelEdit : public QWidget
{
    Q_OBJECT

public:
    explicit hpDelEdit(QWidget *parent = 0);
    ~hpDelEdit();
    CS nowselect;

    Ui::hpDelEdit *ui;
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_update_lcdoff_time(bool iskey);
private:

    void changeEvent(QEvent *e);
};

#endif // HPDELEDIT_H
