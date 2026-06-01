#include  "hp_qdoublespinboxset.h"

hp_QDoubleSpinBoxSet::hp_QDoubleSpinBoxSet(QWidget *parent) : QDoubleSpinBox(parent)
{
    MyLineEdit=new QLineEdit();
    MyLineEdit->setEnabled(false);
//    MyLineEdit->setFont(QFont("Microsoft YaHei", 17));
    this->setLineEdit(MyLineEdit);
    stepTimer = new QTimer(this);
    stepTimer->setInterval(2000);

    connect(MyLineEdit,SIGNAL(selectionChanged()),this,SLOT(SlotDeSelectLine()));
    connect(stepTimer,SIGNAL(timeout()),this,SLOT(stepTimerThimeout()));
    mystep = 0.1;//不知道为什么这里获取到的singstep为1
}
void hp_QDoubleSpinBoxSet::hp_setFont(QFont font)
{
    MyLineEdit->setFont(font);
}
void hp_QDoubleSpinBoxSet::SlotDeSelectLine()
{
    MyLineEdit->deselect();
}
void hp_QDoubleSpinBoxSet::mousePressEvent(QMouseEvent *ev)
{
    stepTimer->start();
    QDoubleSpinBox::mousePressEvent(ev);
}
void hp_QDoubleSpinBoxSet::mouseReleaseEvent(QMouseEvent *ev)
{
    stepTimer->stop();
    this->setSingleStep(mystep);
    signal_mouseRelease();
    QDoubleSpinBox::mouseReleaseEvent(ev);
}
//void hp_QDoubleSpinBoxSet::keyReleaseEvent(QKeyEvent *event)
//{
//    qDebug() << "hp_QDoubleSpinBoxSet::keyReleaseEvent";
//}
void hp_QDoubleSpinBoxSet::stepTimerThimeout()
{
    if(this->singleStep() < 100)
    {
        this->setSingleStep(this->singleStep()*2);
    }
}

