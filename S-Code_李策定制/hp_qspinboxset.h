#ifndef HP_QSPINBOXSET_H
#define HP_QSPINBOXSET_H

#include  <QSpinBox>
#include  <QLineEdit>
#include  <QTimer>
#include  <QMouseEvent>
#include  <QDebug>

class hp_QSpinBoxSet : public QSpinBox
{
    Q_OBJECT
public:
    explicit hp_QSpinBoxSet(QWidget *parent = 0);

    void hp_setFont(QFont font);
protected:

signals:

public slots:
    void SlotDeSelectLine();
    void stepTimerThimeout();
protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //virtual void keyReleaseEvent(QKeyEvent *event);
private:
    QLineEdit* MyLineEdit;
    QTimer *stepTimer;
    int mystep;
};

#endif // HP_QSPINBOXSET_H
