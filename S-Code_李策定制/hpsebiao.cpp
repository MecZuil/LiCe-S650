#include  "hpsebiao.h"
#include  "ui_hpsebiao.h"

HpSebiao::HpSebiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpSebiao)
{
    ui->setupUi(this);
    ui->buttonGroup->addButton(ui->toolButton_sb13);
    ui->buttonGroup->addButton(ui->toolButton_sb14);
    ui->buttonGroup->addButton(ui->toolButton_sb15);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    setGeometry((640-width())/2+160-30, 300, width(), height() + 40);  //640->右边宽度。640+160=800。 158左边两列图标宽度
    setFixedSize(this->width(), this->height() + 40);
    connect(ui->checkBox_reverse, SIGNAL(clicked(bool)), this, SLOT(on_checkbox_set_reverse(bool)));
    turnSebiao = false;
#if  SEBIAO15_SIZE
    ui->frame_2->setGeometry(0,40,405,133);
    ui->toolButton_sb01->setGeometry(0,  0,65,65);
    ui->toolButton_sb02->setGeometry(68, 0,65,65);
    ui->toolButton_sb03->setGeometry(136,0,65,65);
    ui->toolButton_sb04->setGeometry(204,0,65,65);
    ui->toolButton_sb05->setGeometry(272,0,65,65);
    ui->toolButton_sb06->setGeometry(340,0,65,65);
    ui->toolButton_sb07->setGeometry(408,0,65,65);
    ui->toolButton_sb08->setGeometry(0,  68,65,65);
    ui->toolButton_sb09->setGeometry(68, 68,65,65);
    ui->toolButton_sb10->setGeometry(136,68,65,65);
    ui->toolButton_sb11->setGeometry(204,68,65,65);
    ui->toolButton_sb12->setGeometry(272,68,65,65);
    ui->toolButton_sb13->setGeometry(340,68,65,65);
    ui->toolButton_sb14->setGeometry(408,68,65,65);

#endif
}

HpSebiao::~HpSebiao()
{
    delete ui;
}
void HpSebiao::hp_setDefine_S3x0(bool isSelect)
{
    qDebug() << "HpSebiao::hp_setDefine_S3x0 == > " << isSelect;
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);
        this->move((384 - this->width()) / 2 + 96,170);
        ui->label->setFont(font10);
    }else{
        this->move((640 - this->width()) / 2 + 160,300);
    }

}

void HpSebiao::mouseReleaseEvent(QMouseEvent *event)
{
    signal_update_lcdoff_time(true);
}

void HpSebiao::set_sebiao(int min,int max,bool isSelect)
{
    ui->toolButton_sb01->close();
    ui->toolButton_sb02->close();
    ui->toolButton_sb03->close();
    ui->toolButton_sb04->close();
    ui->toolButton_sb05->close();
    ui->toolButton_sb06->close();
    ui->toolButton_sb07->close();
    ui->toolButton_sb08->close();
    ui->toolButton_sb09->close();
    ui->toolButton_sb10->close();
    ui->toolButton_sb11->close();
    ui->toolButton_sb12->close();
    ui->toolButton_sb13->close();
    ui->toolButton_sb14->close();
    ui->toolButton_sb15->close();
    ui->toolButton_sb16->close();
    ui->toolButton_sb17->close();

    int minid = min + 1;
    int maxid = max + 1;
//    qDebug() << __LINE__ << " ; " << minid << " ; " << maxid << " ; " << min << " ; " << max;
    if(minid <= 0)
    {
        minid = 1;
    }
    if(maxid > 17)
    {
        maxid = 17;
    }
    if(minid > maxid)
    {
        int ret = minid;
        minid = maxid;
        maxid = ret;
    }
//    int col_num = 65;//横间隔
//    int row_num = 65;//纵间隔
    int colnum = 8;//列数
    int rownum = 1;//行数
    int zon = maxid - minid + 1;//色标总数

    if(zon <= 8)
    {
        colnum = zon;
        rownum = 1;
    }else if(zon <= 10)
    {
        colnum = 5;
        rownum = 2;
    }else if(zon <= 12)
    {
        colnum = 6;
        rownum = 2;
    }else if(zon <= 14)
    {
        colnum = 7;
        rownum = 2;
    }else if(zon <= 16)
    {
        colnum = 8;
        rownum = 2;
    }else if(zon <= 18)
    {
        colnum = 9;
        rownum = 2;
    }
    int nowcol = 0;
    int nowrow = 0;

    int element_width = 65;

    if(isSelect)
    {
        element_width = 38;
    }

    if(turnSebiao)
    {
        ui->frame_2->resize(colnum * element_width, rownum * element_width);
        this->resize(colnum * element_width, rownum * element_width + 40);
        this->setFixedSize(colnum * element_width, rownum * element_width + 40);
        ui->label->setGeometry(0, 0, 81, 41);
        ui->checkBox_reverse->setGeometry(90, 0, 70, 41);
        ui->label->raise();
        ui->checkBox_reverse->raise();
    }
    else
    {
        ui->frame_2->move(0, 0);
        ui->frame_2->resize(colnum * element_width, rownum * element_width);
        this->resize(colnum * element_width, rownum * element_width);
        this->setFixedSize(colnum * element_width, rownum * element_width);
        ui->label->close();
        ui->checkBox_reverse->close();
    }

    if(minid <= 1 && 1 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb01->show();
        ui->toolButton_sb01->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 2 && 2 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb02->show();
        ui->toolButton_sb02->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 3 && 3 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb03->show();
        ui->toolButton_sb03->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 4 && 4 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb04->show();
        ui->toolButton_sb04->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 5 && 5 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb05->show();
        ui->toolButton_sb05->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 6 && 6 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb06->show();
        ui->toolButton_sb06->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 7 && 7 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb07->show();
        ui->toolButton_sb07->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 8 && 8 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb08->show();
        ui->toolButton_sb08->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 9 && 9 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        if(!turnSebiao)
        {
            ui->toolButton_sb09->show();
            ui->toolButton_sb09->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
            nowcol++;
            if(nowcol > colnum - 1)
            {
                nowrow = 1;
                nowcol = 0;
            }
        }
    }

    if(minid <= 10 && 10 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb10->show();
        ui->toolButton_sb10->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }

    if(minid <= 11 && 11 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb11->show();
        ui->toolButton_sb11->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 12 && 12 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb12->show();
        ui->toolButton_sb12->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 13 && 13 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb13->show();
        ui->toolButton_sb13->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 14 && 14 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb14->show();
        ui->toolButton_sb14->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 15 && 15 <= maxid)
    {
//        qDebug() << __LINE__ << " == " << nowcol << " ; " << nowrow;
        ui->toolButton_sb15->show();
        ui->toolButton_sb15->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 16 && 16 <= maxid)
    {
        ui->toolButton_sb16->show();
        ui->toolButton_sb16->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
    if(minid <= 17 && 17 <= maxid)
    {
        ui->toolButton_sb17->show();
        ui->toolButton_sb17->setGeometry(nowcol * element_width,nowrow * element_width,element_width,element_width);
        nowcol++;
        if(nowcol > colnum - 1)
        {
            nowrow = 1;
            nowcol = 0;
        }
    }
}
//void HpSebiao::set_sebiao(bool sebiao15,bool isS3X0)
//{
//    qDebug() << "HpSebiao::set_sebiao == > " << sebiao15 << " ; " << isS3X0;

//    //先触发
//    define_sebiao = sebiao15;
//    if(!isS3X0)
//    {
//        ui->toolButton_sb01->setGeometry(0,0,65,65);
//        ui->toolButton_sb02->setGeometry(68,0,65,65);
//        ui->toolButton_sb03->setGeometry(136,0,65,65);
//        ui->toolButton_sb04->setGeometry(204,0,65,65);
//        ui->toolButton_sb05->setGeometry(272,0,65,65);
//        ui->toolButton_sb06->setGeometry(340,0,65,65);
//        ui->toolButton_sb07->setGeometry(0,68,65,65);
//        ui->toolButton_sb08->setGeometry(68,68,65,65);
//        ui->toolButton_sb09->setGeometry(136,68,65,65);
//        ui->toolButton_sb10->setGeometry(204,68,65,65);
//        ui->toolButton_sb11->setGeometry(272,68,65,65);
//        ui->toolButton_sb12->setGeometry(340,68,65,65);
//        ui->toolButton_sb13->setGeometry(408,0,65,65);
//        ui->toolButton_sb14->setGeometry(476,0,65,65);
//        ui->toolButton_sb15->setGeometry(408,68,65,65);
//    }else{
//        ui->toolButton_sb01->setGeometry(2,2,38,38);
//        ui->toolButton_sb02->setGeometry(42,2,38,38);
//        ui->toolButton_sb03->setGeometry(82,2,38,38);
//        ui->toolButton_sb04->setGeometry(122,2,38,38);
//        ui->toolButton_sb05->setGeometry(162,2,38,38);
//        ui->toolButton_sb06->setGeometry(202,2,38,38);
//        ui->toolButton_sb07->setGeometry(2,42,38,38);
//        ui->toolButton_sb08->setGeometry(42,42,38,38);
//        ui->toolButton_sb09->setGeometry(82,42,38,38);
//        ui->toolButton_sb10->setGeometry(122,42,38,38);
//        ui->toolButton_sb11->setGeometry(162,42,38,38);
//        ui->toolButton_sb12->setGeometry(202,42,38,38);
//        ui->toolButton_sb13->setGeometry(242,2,38,38);
//        ui->toolButton_sb14->setGeometry(282,2,38,38);
//        ui->toolButton_sb15->setGeometry(242,42,38,38);
//    }
//}
bool HpSebiao::set_sebiao(int sb)
{
    sebiao = sb;
    signal_update_lcdoff_time(true);
    switch(sebiao)
    {
    case 0:
        ui->toolButton_sb01->setChecked(true);
        break;
    case 1:
        ui->toolButton_sb02->setChecked(true);
        break;
    case 2:
        ui->toolButton_sb03->setChecked(true);
        break;
    case 3:
        ui->toolButton_sb04->setChecked(true);
        break;
    case 4:
        ui->toolButton_sb05->setChecked(true);
        break;
    case 5:
        ui->toolButton_sb06->setChecked(true);
        break;
    case 6:
        ui->toolButton_sb07->setChecked(true);
        break;
    case 7:
        ui->toolButton_sb08->setChecked(true);
        break;
    case 8:
        ui->toolButton_sb09->setChecked(true);
        break;
    case 9:
        ui->toolButton_sb10->setChecked(true);
        break;
    case 10:
        ui->toolButton_sb11->setChecked(true);
        break;
    case 11:
        ui->toolButton_sb12->setChecked(true);
        break;
    case 12:
        ui->toolButton_sb13->setChecked(true);
        break;
    case 13:
        ui->toolButton_sb14->setChecked(true);
        break;
    case 14:
        ui->toolButton_sb15->setChecked(true);
        break;
    case 15:
        ui->toolButton_sb16->setChecked(true);
        break;
    case 16:
        ui->toolButton_sb17->setChecked(true);
        break;
    default:
        ui->toolButton_sb01->setChecked(true);
        break;
    }

    return true;
}

int HpSebiao::get_sebiao()
{
    return sebiao;
}

void HpSebiao::set_reverse(bool isReverse)
{
    if(isReverse)
    {
        ui->frame_2->move(0, 40);
    }
    else
    {
        ui->frame_2->move(0, 0);
    }
}

void HpSebiao::on_checkbox_set_reverse(bool isChecked)
{
    if(isChecked)
    {
        ui->toolButton_sb01->setStyleSheet("QToolButton {border-image:url(:/res/res/1n.png);} QToolButton:checked{border-image:url(:/res/res/1s.png);}");
        ui->toolButton_sb12->setStyleSheet("QToolButton {border-image:url(:/res/res/2n.png);} QToolButton:checked{border-image:url(:/res/res/2s.png);}");
        ui->toolButton_sb11->setStyleSheet("QToolButton {border-image:url(:/res/res/3n.png);} QToolButton:checked{border-image:url(:/res/res/3s.png);}");
        ui->toolButton_sb10->setStyleSheet("QToolButton {border-image:url(:/res/res/4n.png);} QToolButton:checked{border-image:url(:/res/res/4s.png);}");
        ui->toolButton_sb09->setStyleSheet("QToolButton {border-image:url(:/res/res/5n.png);} QToolButton:checked{border-image:url(:/res/res/5s.png);}");
        ui->toolButton_sb08->setStyleSheet("QToolButton {border-image:url(:/res/res/6n.png);} QToolButton:checked{border-image:url(:/res/res/6s.png);}");
        ui->toolButton_sb07->setStyleSheet("QToolButton {border-image:url(:/res/res/7n.png);} QToolButton:checked{border-image:url(:/res/res/7s.png);}");
        ui->toolButton_sb06->setStyleSheet("QToolButton {border-image:url(:/res/res/8n.png);} QToolButton:checked{border-image:url(:/res/res/8s.png);}");
        ui->toolButton_sb05->setStyleSheet("QToolButton {border-image:url(:/res/res/9n.png);} QToolButton:checked{border-image:url(:/res/res/9s.png);}");
        ui->toolButton_sb04->setStyleSheet("QToolButton {border-image:url(:/res/res/10n.png);} QToolButton:checked{border-image:url(:/res/res/10s.png);}");
        ui->toolButton_sb03->setStyleSheet("QToolButton {border-image:url(:/res/res/11n.png);} QToolButton:checked{border-image:url(:/res/res/11s.png);}");
        ui->toolButton_sb02->setStyleSheet("QToolButton {border-image:url(:/res/res/12n.png);} QToolButton:checked{border-image:url(:/res/res/12s.png);}");
        ui->toolButton_sb13->setStyleSheet("QToolButton {border-image:url(:/res/res/13n.png);} QToolButton:checked{border-image:url(:/res/res/13s.png);}");
        ui->toolButton_sb14->setStyleSheet("QToolButton {border-image:url(:/res/res/14n.png);} QToolButton:checked{border-image:url(:/res/res/14s.png);}");
        ui->toolButton_sb15->setStyleSheet("QToolButton {border-image:url(:/res/res/15n.png);} QToolButton:checked{border-image:url(:/res/res/15s.png);}");
        ui->toolButton_sb16->setStyleSheet("QToolButton {border-image:url(:/res/res/16n.png);} QToolButton:checked{border-image:url(:/res/res/16s.png);}");
        ui->toolButton_sb17->setStyleSheet("QToolButton {border-image:url(:/res/res/17n.png);} QToolButton:checked{border-image:url(:/res/res/17s.png);}");
    }
    else
    {
        ui->toolButton_sb01->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao01_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao01_s.png);}");
        ui->toolButton_sb12->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao02_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao02_s.png);}");
        ui->toolButton_sb11->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao03_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao03_s.png);}");
        ui->toolButton_sb10->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao04_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao04_s.png);}");
        ui->toolButton_sb09->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao05_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao05_s.png);}");
        ui->toolButton_sb08->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao06_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao06_s.png);}");
        ui->toolButton_sb07->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao07_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao07_s.png);}");
        ui->toolButton_sb06->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao08_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao08_s.png);}");
        ui->toolButton_sb05->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao09_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao09_s.png);}");
        ui->toolButton_sb04->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao10_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao10_s.png);}");
        ui->toolButton_sb03->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao11_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao11_s.png);}");
        ui->toolButton_sb02->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao12_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao12_s.png);}");
        ui->toolButton_sb13->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao13_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao13_s.png);}");
        ui->toolButton_sb14->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao14_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao14_s.png);}");
        ui->toolButton_sb15->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao15_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao15_s.png);}");
        ui->toolButton_sb16->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao16_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao16_s.png);}");
        ui->toolButton_sb17->setStyleSheet("QToolButton {border-image:url(:/res/res/sebiao17_n.png);} QToolButton:checked{border-image:url(:/res/res/sebiao17_s.png);}");
    }
    signal_sebiao_set_reverse(isChecked);
}
