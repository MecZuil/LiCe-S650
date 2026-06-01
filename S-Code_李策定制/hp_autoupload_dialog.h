#ifndef HP_AUTOUPLOAD_DIALOG_H
#define HP_AUTOUPLOAD_DIALOG_H

#include <QWidget>

namespace Ui {
class Hp_Autoupload_Dialog;
}


class Hp_Autoupload_Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_Autoupload_Dialog(QWidget *parent = 0);
    ~Hp_Autoupload_Dialog();

    bool isdownload_dialog;
    Ui::Hp_Autoupload_Dialog *ui;
    void setText(int page,int zon,QString content);
    void setFrame(bool ret);
    void setFrame3Text(QString content);
    void upload_break();
    void down_load(int ret);//作为download界面处理函数
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_StartAutoUpload_once(bool isTask);
    void signal_close();
public slots:
private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_ok_3_clicked();
private:
    void changeEvent(QEvent *e);
};

#endif // HP_AUTOUPLOAD_DIALOG_H
