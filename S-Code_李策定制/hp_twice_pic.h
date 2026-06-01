#ifndef HP_TWICE_PIC_H
#define HP_TWICE_PIC_H

#include  <QWidget>
#include  <QString>
#include  <string.h>
#include  <QImage>
#include     <QPixmap>
#include     <QDebug>
#include     <QPainter>


namespace Ui {
class HP_Twice_Pic;
}

class HP_Twice_Pic : public QWidget
{
    Q_OBJECT

public:
    explicit HP_Twice_Pic(QWidget *parent = 0);
    ~HP_Twice_Pic();

    void hp_setDefine_S3x0(bool isSelect);
public  slots:
    void slot_pic_kjg_open(QString file);


private:
    Ui::HP_Twice_Pic *ui;
    QString picture;
    QString dateFolderPath;

signals:
    void signal_update_lcdoff_time(bool iskey);
protected:
    virtual void paintEvent(QPaintEvent *ev);

private slots:
    void on_pushButton_return_released();
    void on_pushButton_cut_released();
    void SlotSendDateFolderPath(QString path);
};

#endif // HP_TWICE_PIC_H
