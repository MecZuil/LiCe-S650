#ifndef HP_SIS_CONTENT_H
#define HP_SIS_CONTENT_H

#include  <QWidget>
#include  "hi384_protocol.h"
#include  <QKeyEvent>
#include  <QString>
#include  <QDebug>
#include <QTextCodec>

namespace Ui {
class hp_sis_content;
}

class hp_sis_content : public QWidget
{
    Q_OBJECT

public:
    explicit hp_sis_content(QWidget *parent = 0);
    ~hp_sis_content();
    int signal_type;
    void hp_setDefine_S3x0(bool isSelect);//设置宏定义中是否为5.5寸屏，从配置文件中读取
public slots:
    void slot_set_label_text(unsigned char *data);
private slots:


    void on_pushButton_ok_released();

    void on_pushButton_cancel_released();

signals:
    void signal_on_pushButton_ok_or_cannal(int,QString text);

private:
    Ui::hp_sis_content *ui;
    void changeEvent(QEvent *e);
    QString     m_objectName;


    void setOkButton(bool state);
    void setCannelButton(bool state);

protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_SIS_CONTENT_H
