#ifndef HP_CALBRATION_H
#define HP_CALBRATION_H

#include  <QWidget>
#include  <QKeyEvent>
#include  "hi384_protocol.h"
#include  "hp_file.h"

namespace Ui {
class hp_calbration;
}

class hp_calbration : public QWidget
{
    Q_OBJECT

public:
    explicit hp_calbration(QWidget *parent = nullptr);
    ~hp_calbration();
signals:
    void signal_update_lcdoff_time(bool);
   void signal_pc_sys_mag_calsw_start();
   void signal_pc_sys_mag_calsw_stop();
public slots:
   void slot_pc_sys_mag_calsw_start(unsigned char return_value);
   void slot_pc_sys_mag_calsw_stop(unsigned char return_value);
private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_clicked();
protected:
    void mousePressEvent(QMouseEvent* e);
    virtual void keyReleaseEvent(QKeyEvent *ev);
private:
    Ui::hp_calbration *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_CALBRATION_H
