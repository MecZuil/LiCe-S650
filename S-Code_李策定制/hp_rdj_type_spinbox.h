#ifndef HP_RDJ_TYPE_SPINBOX_H
#define HP_RDJ_TYPE_SPINBOX_H

#include  <QSpinBox>

class Hp_Rdj_Type_SpinBox : public QSpinBox
{
public:
    Hp_Rdj_Type_SpinBox(QWidget *parent);

protected:
    virtual QString textFromValue(int value) const Q_DECL_OVERRIDE
    {
        switch(value)
        {
        case 0:
            return tr("之间");
        case 1:
            return tr("之上");
        case 2:
            return tr("之下");
        default:
            return "";
        }
        //            return tr("%1 x %1").arg(value);
    }
private:


};

#endif // HP_RDJ_TYPE_SPINBOX_H
