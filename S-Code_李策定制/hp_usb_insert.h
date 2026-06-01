#ifndef HP_USB_INSERT_H
#define HP_USB_INSERT_H

#include  <QWidget>
#include  <QKeyEvent>
#include  <QMouseEvent>

namespace Ui {
class HP_USB_insert;
}

class HP_USB_insert : public QWidget
{
    Q_OBJECT

public:
    explicit HP_USB_insert(QWidget *parent = 0);
    ~HP_USB_insert();

    void hp_setDefine_S3x0(bool isSelect);
private slots:


private:
    Ui::HP_USB_insert *ui;

protected:

    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
};

#endif // HP_USB_INSERT_H
