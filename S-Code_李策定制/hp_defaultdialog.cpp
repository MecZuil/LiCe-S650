#include  "hp_defaultdialog.h"
#include  "ui_hp_defaultdialog.h"

hp_DefaultDialog::hp_DefaultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hp_DefaultDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    m_isChangeText = false;
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("确定"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("取消"));
    this->setGeometry(160+(640-width())/2,(480-height())/2,width(),height());
}

hp_DefaultDialog::~hp_DefaultDialog()
{
    delete ui;
}
void hp_DefaultDialog::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font11;
        font11.setPointSize(11);

        this->setGeometry(96+(384-220)/2,(272-86)/2,220,86);
        ui->frame->setGeometry(0,0,220,86);
        ui->buttonBox->close();
        ui->label_2->setGeometry(1,1,218,50);
        ui->pushButton_ok->setGeometry(30,60,70,20);
        ui->pushButton_cancel->setGeometry(140,60,70,20);

        ui->label_2->setFont(font11);
        ui->pushButton_ok->setFont(font9);
        ui->pushButton_cancel->setFont(font9);
//        ui->buttonBox->setStyleSheet("");
    }
}
void hp_DefaultDialog::default_button_state()
{
    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            ui->pushButton_ok->setText("确定");
            ui->pushButton_cancel->setText("取消");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("确定");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");
        }
        else if(para.toInt() == 1)
        {
            ui->pushButton_ok->setText("確定");
            ui->pushButton_cancel->setText("取消");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("確定");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");
        }
        else if(para.toInt() == 2)//english
        {
            ui->pushButton_ok->setText("OK");
            ui->pushButton_cancel->setText("Cancel");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("OK");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");
        }
        else if(para.toInt() == 3)//俄语
        {
            ui->pushButton_ok->setText("ОК");
            ui->pushButton_cancel->setText("Отм");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("ОК");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Отм");
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            ui->pushButton_ok->setText("Igen");
            ui->pushButton_cancel->setText("Mégse");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Igen");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Mégse");
        }
        else if(para.toInt() == 5)//西班牙语
        {
            ui->pushButton_ok->setText("OK");
            ui->pushButton_cancel->setText("Cancel");
            ui->buttonBox->button(QDialogButtonBox::Ok)->setText("OK");
            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");
        }
    }
}

void hp_DefaultDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        if(m_isChangeText)
        {
            ui->label_2->setText(tr("采集使能将覆盖原有数据是否开启"));
            ui->pushButton_ok->setText("是");
            ui->pushButton_cancel->setText("否");
        }
        else
        {
            ui->retranslateUi(this);
            default_button_state();
        }
        break;
    default:
        break;
    }
}

void hp_DefaultDialog::keyReleaseEvent(QKeyEvent *ev)
{
    signal_defaultdialog_set_lcd_offed_state();
}

void hp_DefaultDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    close();
    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        signal_close_ble_lie();
        signal_set_default();
    }

}

void hp_DefaultDialog::on_pushButton_ok_clicked()
{
    signal_close_ble_lie();
    signal_set_default();
    close();
}

void hp_DefaultDialog::on_pushButton_cancel_clicked()
{
    close();
}

void hp_DefaultDialog::hp_setTitleText(QString text)
{
    m_isChangeText = true;
    ui->label_2->setText(tr("采集使能将覆盖原有数据是否开启"));
    ui->pushButton_ok->setText("是");
    ui->pushButton_cancel->setText("否");
}
