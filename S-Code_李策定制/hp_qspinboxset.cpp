#include  "hp_qspinboxset.h"

hp_QSpinBoxSet::hp_QSpinBoxSet(QWidget *parent) : QSpinBox(parent)
{
    MyLineEdit=new QLineEdit();
    MyLineEdit->setEnabled(false);
//    MyLineEdit->setFont(QFont("Microsoft YaHei", 17));
    stepTimer = new QTimer(this);//新建定时器
    stepTimer->setInterval(2000);//每2秒触发一次stepTimerThimeout函数

    this->setLineEdit(MyLineEdit);

    connect(MyLineEdit,SIGNAL(selectionChanged()),this,SLOT(SlotDeSelectLine()));
    connect(stepTimer,SIGNAL(timeout()),this,SLOT(stepTimerThimeout()));
    mystep = 1;//不知道为什么这里获取到的singstep为1，设置原始步长
}
void hp_QSpinBoxSet::hp_setFont(QFont font)
{
    MyLineEdit->setFont(font);
}
void hp_QSpinBoxSet::SlotDeSelectLine()
{
    MyLineEdit->deselect();
}
void hp_QSpinBoxSet::mousePressEvent(QMouseEvent *ev)
{
    stepTimer->start();//当手按下时开启定时器
    QSpinBox::mousePressEvent(ev);
}
void hp_QSpinBoxSet::mouseReleaseEvent(QMouseEvent *ev)
{
    stepTimer->stop();//手松开时停止定时器
    this->setSingleStep(mystep);//手松开时设置原始步长
    QSpinBox::mouseReleaseEvent(ev);
}
//void hp_QSpinBoxSet::keyReleaseEvent(QKeyEvent *event)
//{
//    qDebug() << "hp_QSpinBoxSet::keyReleaseEvent";
//}
void hp_QSpinBoxSet::stepTimerThimeout()
{
    if(this->singleStep() < 50)
    {
        this->setSingleStep(this->singleStep()*2);//将原来的步长乘2
    }
}
