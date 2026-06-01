#ifndef HP_QSPINBOX_H
#define HP_QSPINBOX_H

#include  <QSpinBox>
#include  <QLineEdit>
#include  <QTimer>
#include  <QMouseEvent>
#include  <QDebug>

class Hp_QSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit Hp_QSpinBox(QWidget *parent = 0);

    void hp_setFont(QFont font);
signals:

public slots:
    void SlotDeSelectLine();

private:
    QLineEdit* MyLineEdit;
public slots:
    void stepTimerThimeout();
private:
    QTimer *stepTimer;
    int mystep;
protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //virtual void keyReleaseEvent(QKeyEvent *event);
     //将输入的文本解读为适当的值
//    virtual int valueFromText(const QString &text) const Q_DECL_OVERRIDE
//    {
//        QRegExp regExp(tr("(\\d+)(\\s*[xx]\\s*\\d+)?"));

//        if (regExp.exactMatch(text)) {
//            return regExp.cap(1).toInt();
//        } else {
//            return 0;
//        }
//    }
    // 根据输入的值返回文本
    virtual QString textFromValue(int value) const Q_DECL_OVERRIDE
    {
        switch(value)
        {
        case 0:
            return "℃";
        case 1:
            return "℉";
        case 2:
            return "K";
        default:
            return " ";
        }
        //            return tr("%1 x %1").arg(value);
    }
};

#endif // HP_QSPINBOX_H
