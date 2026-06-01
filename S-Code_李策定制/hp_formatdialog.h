#ifndef HP_FORMATDIALOG_H
#define HP_FORMATDIALOG_H

#include  <QDialog>
#include  <QAbstractButton>
#include  <QPushButton>
#include  <QDebug>
#include  "hpxmlreader.h"


namespace Ui {
class Hp_FormatDialog;
}

class Hp_FormatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Hp_FormatDialog(QWidget *parent = 0);
    ~Hp_FormatDialog();
    void format_button_state();
    void hp_setDefine_S3x0(bool isSelect);
    void setTextForVideo(QString str);
signals:
    void signal_set_format();

    void signal_sd_formatting();
    void signal_formatdialog_set_lcd_offed_state();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Hp_FormatDialog *ui;

    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_FORMATDIALOG_H
