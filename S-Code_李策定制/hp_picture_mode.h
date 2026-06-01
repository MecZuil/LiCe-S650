#ifndef HP_PICTURE_MODE_H
#define HP_PICTURE_MODE_H

#include  <QWidget>
#include  "hi384_protocol.h"

namespace Ui {
class hp_picture_mode;
}

class hp_picture_mode : public QWidget
{
    Q_OBJECT

public:
    explicit hp_picture_mode(QWidget *parent = 0);
    ~hp_picture_mode();

    //没啥用的类
signals:
    void signal_temp_row_mode(int mode);//0为温度流 1为原始灰度流
    void signal_wait_warn();
    void signal_un_freeze();

protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);

private slots:
    void on_pushButton_temp_clicked();
    void on_pushButton_row_clicked();
    void on_toolButton_clicked();
    void setTempButton(bool state);
    void setRowButton(bool state);

private:
    Ui::hp_picture_mode *ui;
    bool isTempMode;
};

#endif // HP_PICTURE_MODE_H
