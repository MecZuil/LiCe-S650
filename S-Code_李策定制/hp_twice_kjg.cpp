#include  "hp_twice_kjg.h"
#include  "ui_hp_twice_kjg.h"
#include  <QLabel>
Hp_Twice_kjg::Hp_Twice_kjg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Twice_kjg)
{
    picture = "";
    m_isMoveView = false;
    m_mousePressPosX = 0;
    m_panoramaStartPosX = 0;
    image = nullptr;
    pixmap = nullptr;
 //   setGeometry(160,20,width(),height());
    setGeometry(5,5,width(),height());
    ui->setupUi(this);
    define_640_512 = false;
    dateFolderPath = "/run/media/mmcblk2p1/DCIM";

}

Hp_Twice_kjg::~Hp_Twice_kjg()
{
    if(image != nullptr)
    {
        delete image;
        image = nullptr;
    }
    if(pixmap != nullptr)
    {
        delete pixmap;
        pixmap = nullptr;
    }
    delete ui;
}
void Hp_Twice_kjg::hp_setDefine_S3x0(bool isSelect)
{
    define_S3X0 = isSelect;
    if(isSelect)
    {
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        ui->frame->setGeometry(0,0,480,230);
        ui->pushButton_close->setGeometry(390,80,61,41);
        ui->scrollArea->setGeometry(50, 15, 280, 200);
        ui->scrollAreaWidgetContents->setGeometry(0, 0, 280, 200);
        ui->label_pic->setGeometry(0, 0, 280, 200);
        ui->frame_2->setGeometry(0,230,480,42);
        ui->label_name->setGeometry(140,0,191,31);

        ui->label_name->setFont(font10);
        ui->pushButton_close->setFont(font10);
    }
}
void Hp_Twice_kjg::slot_pic_kjg_on(QString file)
{
    picture = file;
    ui->label_name->setText(file.split("/").last());
    image = new QImage(picture);
    if(image->isNull())
    {
        delete image;
        image = nullptr;
        image = new QImage(":/res/res/error_waring.png");
        qDebug() <<  picture << "image isNull load Failure";
    }
    pixmap=new QPixmap();
    pixmap->convertFromImage(*image);
    if(pixmap->isNull())
    {
        if(image->isNull())
        {
            qDebug() <<  picture << "image isNull load Failure";
        }
        qDebug() <<  picture << " pixmap isNull load Failure";
    }
    int beginX = 90;
    int beginY = 18;
    int labelHeight = 360;
    int labelWidth = 480;
    int scrollAreaWidth = 480;
    if(define_S3X0)
    {
        beginX = 50;
        beginY = 10;
        labelHeight = 200;
        labelWidth = 266;
        scrollAreaWidth = 266;
    }
    if(file.contains("PAN") && !file.contains("-"))
    {
        m_isMoveView = true;
        double aspectRatio =static_cast<double>(pixmap->height()) / static_cast<double>(pixmap->width());

        labelWidth = labelHeight / aspectRatio;
    }
    if(define_640_512)
    {
        m_isMoveView = true;
        double aspectRatio =static_cast<double>(pixmap->height()) / static_cast<double>(pixmap->width());
        labelWidth = labelHeight / aspectRatio;
    }
    *pixmap = pixmap->scaled(labelWidth, labelHeight, Qt::KeepAspectRatio);

    ui->scrollArea->setGeometry(beginX,beginY,scrollAreaWidth,labelHeight);
    ui->scrollAreaWidgetContents->setGeometry(0, 0, labelWidth, labelHeight);

    if(labelWidth < scrollAreaWidth)
    {
        ui->label_pic->setGeometry((scrollAreaWidth - labelWidth) / 2,0,labelWidth,labelHeight);
    }
    else
    {
        ui->label_pic->setGeometry(0,0,labelWidth,labelHeight);
    }
    qDebug() << ui->scrollArea->geometry();
    qDebug() << ui->label_pic->geometry();
    ui->label_pic->setPixmap(*pixmap);

    this->show();
}
void Hp_Twice_kjg::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
    {
        ui->retranslateUi(this);
        QString para;
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->pushButton_close->setText("关闭");
            }
            else if(para.toInt() == 1)
            {
                ui->pushButton_close->setText("關閉");
            }
            else if(para.toInt() == 2)//english
            {
                ui->pushButton_close->setText("close");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->pushButton_close->setText("закрыть");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->pushButton_close->setText("zárás");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->pushButton_close->setText("Cerrar");
            }
        }
        break;
    }
    default:
        break;
    }
}
void Hp_Twice_kjg::paintEvent(QPaintEvent *ev)
{
    /*
//第一种画图
    QImage img(picture);
    QPainter painter(this);
  //QPixmap pixmapToShow = QPixmap::fromImage( img.scaled(size(), Qt::KeepAspectRatio) );
    QPixmap pixmapToShow = QPixmap::fromImage( img.scaled(480,360, Qt::KeepAspectRatio) );
    painter.drawPixmap(160,30,pixmapToShow);
/*/
/*
    //第二种画图
    QImage img(picture);
    QPixmap pix = QPixmap::fromImage(img);
    QPainter painter(this);
    painter.drawPixmap(160,30,480,360,pix);
//*/
}

void Hp_Twice_kjg::mousePressEvent(QMouseEvent *event)
{
    signal_update_lcdoff_time(false);
    if(!m_isMoveView)
        return;
    qDebug() << "Hp_Panorama::mousePressEvent" << ui->label_pic->x() << event->pos().x();
    m_mousePressPosX = event->pos().x();
    m_panoramaStartPosX = -ui->label_pic->x();
}

void Hp_Twice_kjg::mouseMoveEvent(QMouseEvent *event)
{
    if(!m_isMoveView)
        return;
    int maxWidth = 480;
    if(define_S3X0)
    {
        maxWidth = 280;
    }
    qDebug() << "Hp_Panorama::mouseMoveEvent" << ui->label_pic->x() << event->pos().x();
    int moveLength = -(m_panoramaStartPosX + (m_mousePressPosX - event->pos().x()));
    if(moveLength + ui->label_pic->width() < maxWidth)
        moveLength = maxWidth - ui->label_pic->width();
    if(moveLength > 0)
        moveLength = 0;
    ui->label_pic->setGeometry(moveLength, 0, ui->label_pic->width(), ui->label_pic->height());
}

void Hp_Twice_kjg::mouseDoubleClickEvent(QMouseEvent *event)
{

    if(image != nullptr)
    {
        delete image;
        image = nullptr;
    }
    if(pixmap != nullptr)
    {
        delete pixmap;
        pixmap = nullptr;
    }
    this->close();
}

void Hp_Twice_kjg::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    signal_twicekjg_set_lcd_offed_state();
    if(ev->key() == 16777216)
    {
        if(image != nullptr)
        {
            delete image;
            image = nullptr;
        }
        if(pixmap != nullptr)
        {
            delete pixmap;
            pixmap = nullptr;
        }
        this->close();
    }
}

void Hp_Twice_kjg::on_pushButton_close_released()
{
    signal_update_lcdoff_time(false);
    m_isMoveView = false;

    if(image != nullptr)
    {
        delete image;
        image = nullptr;
    }
    if(pixmap != nullptr)
    {
        delete pixmap;
        pixmap = nullptr;
    }
    this->close();
}

void Hp_Twice_kjg::SlotSendDateFolderPath(QString path)
{
    dateFolderPath = path;
}
