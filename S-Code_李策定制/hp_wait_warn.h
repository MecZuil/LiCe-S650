#ifndef HP_WAIT_WARN_H
#define HP_WAIT_WARN_H

#include  <QWidget>
#include  <QDebug>
#include  "hi384_protocol.h"
#include  "hpxmlreader.h"
namespace Ui {
class Hp_wait_warn;
}

class Hp_wait_warn : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_wait_warn(QWidget *parent = 0);
    ~Hp_wait_warn();

    void hp_setS3X0(bool isS3X0);
private:
    Ui::Hp_wait_warn *ui;
    void changeEvent(QEvent *e);

    HpXmlReader hpxmlreader;
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
};

#endif // HP_WAIT_WARN_H
