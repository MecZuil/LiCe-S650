#ifndef HPSETTING_ADJUST_H
#define HPSETTING_ADJUST_H

#include  <QWidget>

namespace Ui {
class HpSetting_adjust;
}

class HpSetting_adjust : public QWidget
{
    Q_OBJECT

public:
    explicit HpSetting_adjust(QWidget *parent = 0);
    ~HpSetting_adjust();

signals:
    void signal_dangwei_jingtou_adjust(bool state);

private slots:
    void on_pushButton_ok_released();

    void on_pushButton_cancel_released();

private:
    Ui::HpSetting_adjust *ui;
};

#endif // HPSETTING_ADJUST_H
