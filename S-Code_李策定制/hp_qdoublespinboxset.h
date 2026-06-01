#ifndef HP_QDOUBLESPINBOXSET_H
#define HP_QDOUBLESPINBOXSET_H

#include  <QDoubleSpinBox>
#include  <QLineEdit>
#include  <QTimer>
#include  <QMouseEvent>
#include  <QDebug>

class hp_QDoubleSpinBoxSet : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit hp_QDoubleSpinBoxSet(QWidget *parent = 0);

    void hp_setFont(QFont font);
signals:
    void signal_mouseRelease();
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
    double mystep;
};

#endif // HP_QDOUBLESPINBOXSET_H
