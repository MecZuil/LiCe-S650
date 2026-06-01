#ifndef MYLABEL_H
#define MYLABEL_H
#include  <QLabel>
#include  <QApplication>
#include  <QDebug>
#include  <QFile>
#include  <QPixmap>
#include  <QTransform>
#include  <QPainter>

enum MYLABEL_WHO{
    MYLABEL_WHO_COMPASS,//指南针
    MYLABEL_WHO_SCROLL,//四个点
};

class myLabel : public QLabel
{
public:
    myLabel(QWidget *parent = nullptr);

    void setPixmap(const QString& imgPath);
    int index1;
    int index2;
    int angle;
    void trans(int index);
    void setinded1(int index);
    void  settrans(int index);
    void setMyname(MYLABEL_WHO name);
    QPixmap mPix;
    void hp_scroll_setzon(int zon);
public slots:
    void hp_updateScroll(int num);
protected:
    virtual void paintEvent(QPaintEvent *);

private:
    MYLABEL_WHO labelname;
    int scroll_num;//当前第几页
    int scroll_zon;//当前总页数
};

#endif // MYLABEL_H
