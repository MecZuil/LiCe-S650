#ifndef HP_TWICE_KJG_H
#define HP_TWICE_KJG_H

#include  <QWidget>
#include  <QString>
#include  <string.h>
#include  <QImage>
#include     <QPixmap>
#include     <QDebug>
#include     <QPainter>
#include   <QTimer>
#include  <QMouseEvent>
#include  <QKeyEvent>

#include  <QListView>
#include  <QTreeWidget>
#include  <QListWidgetItem>
#include "hpxmlreader.h"

namespace Ui {
class Hp_Twice_kjg;
}

class Hp_Twice_kjg : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Twice_kjg(QWidget *parent = 0);
    ~Hp_Twice_kjg();

    void hp_setDefine_S3x0(bool isSelect);
    bool define_640_512;
    bool define_S3X0;
public  slots:
    void slot_pic_kjg_on(QString file);

private:
    Ui::Hp_Twice_kjg *ui;
    QString picture;
    QImage *image;
    QPixmap *pixmap;
    bool m_isMoveView;
    int m_mousePressPosX;//
    int m_panoramaStartPosX;
    HpXmlReader hpxmlreader;
    void changeEvent(QEvent *e);
    QString dateFolderPath;
signals:
    void signal_update_lcdoff_time(bool iskey);
    void signal_twicekjg_set_lcd_offed_state();
protected:
    virtual void paintEvent(QPaintEvent *ev);
    virtual void mousePressEvent(QMouseEvent* event);      //单击
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent * event);
    virtual void keyReleaseEvent(QKeyEvent *ev);
private slots:
        void SlotSendDateFolderPath(QString path);
    void on_pushButton_close_released();
};

#endif // HP_TWICE_KJG_H
