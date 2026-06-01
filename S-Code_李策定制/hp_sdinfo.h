#ifndef HP_SDINFO_H
#define HP_SDINFO_H

#include  <QWidget>
#include  <QPainter>
#include  <QImage>
#include  <QDebug>
#include  "hi384_protocol.h"

class Hp_SdInfo : public QWidget
{
    Q_OBJECT
public:
    explicit Hp_SdInfo(QWidget *parent = 0);

    void update_sd_info(sdinfo_t si);
    void update_sd_insert(bool f);
    sdinfo_t sdinfo;
    bool sdinsert;

protected:
  //  virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
private:
    QString image_sd_error;
    QString image_sd_ok;

};

#endif // HP_SDINFO_H
