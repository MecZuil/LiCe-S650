#ifndef HP_COMMON_DIALOG_SELECT_H
#define HP_COMMON_DIALOG_SELECT_H

#include <QWidget>

namespace Ui {
class hp_common_dialog_select;
}


class hp_common_dialog_select : public QWidget
{
    Q_OBJECT
public:
    explicit hp_common_dialog_select(QWidget *parent = 0);
    ~hp_common_dialog_select();

    void hp_setDefine5_5(bool isSelect);
    void hp_setBt1Text(QString text);
    void hp_setBt2Text(QString text);
    void hp_setBt3Text(QString text);
    void hp_setLabelText(QString text);
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void hp_signal_bt_click(int select);
public slots:
private slots:
    void on_pushButton_task_clicked(bool checked);

    void on_pushButton_normal_clicked(bool checked);

    void on_pushButton_cancel_clicked(bool checked);

private:
    Ui::hp_common_dialog_select *ui;
};

#endif // HP_COMMON_DIALOG_SELECT_H
