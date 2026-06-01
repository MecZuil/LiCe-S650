#ifndef HP_TEXT_INPUT_H
#define HP_TEXT_INPUT_H

#include  <QWidget>
#include  "frminput.h"
#include  "frmnum.h"
#include  "hi384_protocol.h"
#include  "hpxmlreader.h"

namespace Ui {
class Hp_Text_Input;
}


class Hp_Text_Input : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Text_Input(QWidget *parent = 0);
    ~Hp_Text_Input();
    QString getText();
    void setText(QString str);
    void setpage();
    void setpage2(QString name);
    void setbtnTaskVisble(bool visble);
    void setShowPrefix(bool isShow);
    void hp_setDefine_S3x0(bool isSelect);
    bool isPreview;//用于标识是否为预览界面的输入窗口
signals:
    void sync_text();
    //void signal_Set_wifi_text(QString);
    void signal_update_lcdoff_time(bool iskey);
    void signal_frminput_init();

    void signal_frminput_set_lcd_offed_state();
    void signalTask();
private slots:

    void on_lineEdit_textChanged(const QString &arg1);

    void on_toolButton_back_released();
    void slot_Task();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_lineEdit_selectionChanged();

    void slot_list_widget_vertical_value_change(int value);
private:
    Ui::Hp_Text_Input *ui;

//    frmInput *pfi;
    QString text;
    QString prefixText;
    QString mainText;
    QString Currenttext;
//    QString frontText;
//    QString lastText;
    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);

protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_TEXT_INPUT_H
