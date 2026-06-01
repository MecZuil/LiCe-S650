#ifndef HP_MULHOM_EDIT_H
#define HP_MULHOM_EDIT_H

#include <QWidget>
#include <QKeyEvent>
#include <QEvent>
#include "hi384_protocol.h"

namespace Ui {
class hp_mulhom_edit;
}

class hp_mulhom_edit : public QWidget
{
    Q_OBJECT
public:
    explicit hp_mulhom_edit(QWidget *parent = 0);
    ~hp_mulhom_edit();

    void mulhom_value_init(int val);
    double max_temp;
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_update_lcdoff_time(bool iskey);
    void hp_mulhom_edit_value_changed(int num);
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
public slots:

    void on_toolButton_back_clicked();
private slots:

//    void on_ScrollBar_mulhom_valueChanged(int arg1);
    void scrollBar_mulhom_mouseRelease();

private:
    Ui::hp_mulhom_edit *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_MULHOM_EDIT_H
