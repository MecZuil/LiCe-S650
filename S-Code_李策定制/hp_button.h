#ifndef HP_BUTTON_H
#define HP_BUTTON_H

#include  <QWidget>
#include  <QPainter>
#include  <QImage>
#include  <QPixmap>
#include  <QDebug>

#include  "hi384_protocol.h"


class hp_button : public QWidget
{
    Q_OBJECT
public:
    explicit hp_button(QWidget *parent = 0);

    void set_hp_button_checked_enable(bool flag);

    void set_hp_button_status_image_normal(const QString& str);
    void set_hp_button_status_image_select(const QString& str);
    void set_hp_button_status_image_disable(const QString& str);

    void set_hp_button_status(HP_BUTTON_STATUS status);

    HP_BUTTON_STATUS get_hp_button_status(void);

signals:
    void clicked(HP_BUTTON_STATUS);

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void paintEvent(QPaintEvent *ev);

private:
    bool checked_enable;
    HP_BUTTON_STATUS hp_button_status;

    QString image_normal;
    QString image_select;
    QString image_disable;

};

#endif // HP_BUTTON_H
