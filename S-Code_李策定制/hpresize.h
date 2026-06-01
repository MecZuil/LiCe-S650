#ifndef HPRESIZE_H
#define HPRESIZE_H

#include  <QWidget>

namespace Ui {
class HpResize;
}

class HpResize : public QWidget
{
    Q_OBJECT

public:
    explicit HpResize(QWidget *parent = 0);
    ~HpResize();

    Ui::HpResize *ui;

    void setValue(int v);
    void set_resize35(int resize35);
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_update_lcdoff_time(bool iskey);
private:
    void changeEvent(QEvent *e);
public slots:
    void slider_value_changed(int v);
};

#endif // HPRESIZE_H
