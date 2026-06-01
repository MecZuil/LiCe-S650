#include  "hp_qspinbox.h"

Hp_QSpinBox::Hp_QSpinBox(QWidget *parent) : QSpinBox(parent)
{
    MyLineEdit=new QLineEdit();
    MyLineEdit->setEnabled(false);
//    MyLineEdit->setFont(QFont("Microsoft YaHei", 17));
    this->setLineEdit(MyLineEdit);
    stepTimer = new QTimer(this);
    stepTimer->setInterval(2000);

    connect(MyLineEdit,SIGNAL(selectionChanged()),this,SLOT(SlotDeSelectLine()));
    connect(stepTimer,SIGNAL(timeout()),this,SLOT(stepTimerThimeout()));
    mystep = 1;//不知道为什么这里获取到的singstep为1
}
void Hp_QSpinBox::hp_setFont(QFont font)
{
    MyLineEdit->setFont(font);
}
void Hp_QSpinBox::SlotDeSelectLine()
{
    MyLineEdit->deselect();
}

void Hp_QSpinBox::mousePressEvent(QMouseEvent *ev)
{
    stepTimer->start();
    QSpinBox::mousePressEvent(ev);
}
void Hp_QSpinBox::mouseReleaseEvent(QMouseEvent *ev)
{
    stepTimer->stop();
    this->setSingleStep(mystep);
    QSpinBox::mouseReleaseEvent(ev);
}
//void Hp_QSpinBox::keyReleaseEvent(QKeyEvent *event)
//{
//    qDebug() << "Hp_QSpinBox::keyReleaseEvent";
//}
void Hp_QSpinBox::stepTimerThimeout()
{
    if(this->singleStep() < 50)
    {
        this->setSingleStep(this->singleStep()*2);
    }
}
