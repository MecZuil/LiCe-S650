#ifndef HPMYLABEL_H
#define HPMYLABEL_H

#include  <QLabel>
#include  <QApplication>
#include  <QDebug>
#include  <QFile>
#include  <QPixmap>
#include  <QTransform>
#include  <QPainter>
#include  <QString>
class hpmylabel : public QLabel
{
public:
    hpmylabel(QWidget *parent = nullptr);

    QString temp;
    int number;
   // void trans(int temp);
    void setinded1(QString buf,int num);

protected:
    virtual void paintEvent(QPaintEvent *);
   //  void initPainter(QPainter *painter) const;
};

#endif // HPMYLABEL_H
