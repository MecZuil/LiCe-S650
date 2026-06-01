#ifndef HP_AVI_MODE_H
#define HP_AVI_MODE_H

#include  <QWidget>
#include  "hpxmlreader.h"

namespace Ui {
class HP_Avi_mode;
}

class HP_Avi_mode : public QWidget
{
    Q_OBJECT

public:
    explicit HP_Avi_mode(QWidget *parent = 0);
    ~HP_Avi_mode();

    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void on_pushButton_avi_released();

    void on_pushButton_hir_released();

    void on_toolButton_released();

private:
    Ui::HP_Avi_mode *ui;

    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);

signals:
     void signal_core_key_record_avi_mode_start();
     void signal_core_key_record_hir_mode_start();
     void signal_avi_hir_mode(int mode);

};

#endif // HP_AVI_MODE_H
