#include  "hp_handfution.h"
#include  "ui_hp_handfution.h"

Hp_HandFution::Hp_HandFution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_HandFution)
{
    ui->setupUi(this);

    list.append("1m");
    list.append("2m");
    list.append("3m");
    list.append(">4m");

    current_row = 0;
    update_ui();
}

Hp_HandFution::~Hp_HandFution()
{
    delete ui;
}
void Hp_HandFution::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font12;
        font12.setPointSize(12);

        this->resize(44,128);
        ui->label->setGeometry(2,54,40,20);
        ui->toolButton_down->setGeometry(2,86,40,40);
        ui->toolButton_up->setGeometry(2,2,40,40);

        ui->label->setFont(font12);
    }
}
bool Hp_HandFution::set_current_index(int index)
{
    if(index < list.count() && index >= 0)
    {
        current_row = index;
        update_ui();
        return true;
    }
    return false;
}

void Hp_HandFution::update_ui()
{
    ui->label->setText(list.at(current_row));
    if(current_row == 0)
    {
        ui->toolButton_down->setEnabled(false);
        ui->toolButton_up->setEnabled(true);
    }
    else if(current_row == (list.count()-1))
    {
        ui->toolButton_down->setEnabled(true);
        ui->toolButton_up->setEnabled(false);
    }
    else
    {
        ui->toolButton_down->setEnabled(true);
        ui->toolButton_up->setEnabled(true);
    }
}



void Hp_HandFution::on_toolButton_up_released()
{
    current_row++;
    update_ui();
    current_index_changed(current_row);
}


void Hp_HandFution::on_toolButton_down_released()
{
    current_row--;
    update_ui();
    current_index_changed(current_row);
}

void Hp_HandFution::slot_pc_sys_set_handfusion(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_handfusion:%02x",return_value);
}
