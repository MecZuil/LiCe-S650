#ifndef HPSEBIAO_H
#define HPSEBIAO_H

#include  <QWidget>
#include  <QKeyEvent>
#include  <QEvent>
#include  <QDebug>
#include  "hi384_protocol.h"

namespace Ui {
class HpSebiao;
}

class HpSebiao : public QWidget
{
    Q_OBJECT

public:
    explicit HpSebiao(QWidget *parent = 0);
    ~HpSebiao();

    bool set_sebiao(int sb);
    int get_sebiao();
    void set_reverse(bool isReverse);
    void set_sebiao(int min,int max,bool isSelect);
    void hp_setDefine_S3x0(bool isSelect);
    Ui::HpSebiao *ui;
    bool turnSebiao;
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_sebiao_set_reverse(bool isReverse);
protected:
    void mouseReleaseEvent(QMouseEvent *event);
public slots:
    void on_checkbox_set_reverse(bool isChecked);
private:
    int sebiao;
    bool define_sebiao;
};

#endif // HPSEBIAO_H
