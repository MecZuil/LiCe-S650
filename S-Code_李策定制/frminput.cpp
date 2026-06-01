#include  "frminput.h"
#include  "ui_frminput.h"
#include  "qdesktopwidget.h"

bool g_NumInput;//控制输入法类型的全局变量，true时为数字键盘，false则为全键盘
QStringList allPY;              //所有拼音链表
int currentPY_count;
frmInput *frmInput::_instance = 0;
frmInput::frmInput(QWidget *parent, double gui_scale) :
    QWidget(parent),
    ui(new Ui::frmInput)
{
    ui->setupUi(this);
    //setupUiLocal(this, gui_scale);
    this->InitProperty();
    this->InitForm();
    this->ChangeStyle();
    ui->btnClose->setVisible(true);
    ui->btnTask->setVisible(false);
    isDefine_S3x0 = false;

    ui->labCh7->close();
    ui->labCh8->close();
    ui->labCh9->close();
    //    NumInput = false;
  //  ui->btnz->setStyleSheet("background-color: rgb(0,25,0)");
}

frmInput::~frmInput()
{
    delete ui;
    sqlite3_close(db);
}
void frmInput::setpage()
{

    if(isDefine_S3x0)
    {
        ui->widget_sub->setGeometry(0,60,384,150);
        ui->widgetMain->setGeometry(0,220,384,150);
    }else{
        ui->widget_sub->setGeometry(0,110,640,261);
        ui->widgetMain->setGeometry(0,400,640,261);
    }
    if(!ui->btnDot->isHidden())
        ui->btnDot->hide();
    if(!ui->btnchange_abc->isHidden())
        ui->btnchange_abc->hide();
    if(!ui->btnchange_sym2->isHidden())
        ui->btnchange_sym2->hide();
    if(!ui->btnClose->isHidden())
        ui->btnClose->hide();
    if(!ui->btnSpace_new1->isHidden())
        ui->btnSpace_new1->hide();
    if(!ui->btnNext->isHidden())
        ui->btnNext->hide();
    if(!ui->btnPre->isHidden())
        ui->btnPre->hide();
    if(!ui->lab_Title->isHidden())
        ui->lab_Title->hide();

    if(!isDefine_S3x0)
    {
        ui->btnTask->setGeometry(480,64,124,60);
//        ui->btnTask->setVisible(true);
    }
    ui->btnDelete_new1->setGeometry(ui->btnDot->geometry());
}
void frmInput::setbtnTaskVisble(bool visble)
{
    ui->btnTask->setVisible(visble);
//    if(!visble)//居中显示
//    {
//        int xret = 0;
//        int stp = 0;
//        if(isDefine_S3x0)
//        {
//            stp = 76;
//            xret = 114;
//        }else{
//            stp = 128;
//            xret = 192;
//        }
//        ui->btn0->move(ui->btn00->x() + stp,ui->btn0->y());
//        ui->btn00->move(xret,ui->btn00->y());
//        ui->btn1->move(xret,ui->btn1->y());
//        ui->btn2->move(ui->btn1->x() + stp,ui->btn2->y());
//        ui->btn3->move(ui->btn2->x() + stp,ui->btn3->y());
//        ui->btn4->move(xret,ui->btn4->y());
//        ui->btn5->move(ui->btn4->x() + stp,ui->btn5->y());
//        ui->btn6->move(ui->btn5->x() + stp,ui->btn6->y());
//        ui->btn7->move(xret,ui->btn7->y());
//        ui->btn8->move(ui->btn7->x() + stp,ui->btn8->y());
//        ui->btn9->move(ui->btn8->x() + stp,ui->btn9->y());
//        ui->btnDelete_new1->move(ui->btn9->x() + stp,ui->btnDelete_new1->y());
//    }else{

//    }
}
void frmInput::setpage2(QString name)
{
    if(name == "enum_AUP_SERVER")
    {
        if(isDefine_S3x0)
        {
            ui->widget_sub->setGeometry(0,60,384,150);
            ui->widgetMain->setGeometry(0,220,384,150);
        }else{
            ui->widget_sub->setGeometry(0,110,640,261);
            ui->widgetMain->setGeometry(0,400,640,261);
        }
        if(!ui->btn00->isHidden())
            ui->btn00->hide();
        if(!ui->btnchange_abc->isHidden())
            ui->btnchange_abc->hide();
        if(!ui->btnchange_sym2->isHidden())
            ui->btnchange_sym2->hide();
        if(!ui->btnClose->isHidden())
            ui->btnClose->hide();
        if(!ui->btnSpace_new1->isHidden())
            ui->btnSpace_new1->hide();
        if(!ui->btnNext->isHidden())
            ui->btnNext->hide();
        if(!ui->btnPre->isHidden())
            ui->btnPre->hide();
        if(!ui->lab_Title->isHidden())
            ui->lab_Title->hide();
        if(isDefine_S3x0)
        {
            ui->btnDot->setGeometry(38,114,72,34);
            ui->btnDelete_new1->setGeometry(190,114,72,34);
        }else{
            ui->btnDot->setGeometry(64,192,124,60);
            ui->btnDelete_new1->setGeometry(320,192,124,60);
        }
    }else if(name == "enum_AUP_ftp")
    {
        if(ui->btn00->isHidden())
            ui->btn00->show();
        if(ui->btnchange_abc->isHidden())
            ui->btnchange_abc->show();
        if(ui->btnchange_sym2->isHidden())
            ui->btnchange_sym2->show();
        if(ui->btnClose->isHidden())
            ui->btnClose->show();
        if(ui->btnSpace_new1->isHidden())
            ui->btnSpace_new1->show();
        if(ui->btnNext->isHidden())
            ui->btnNext->show();
        if(ui->btnPre->isHidden())
            ui->btnPre->show();
        if(ui->lab_Title->isHidden())
             ui->lab_Title->show();
        if(isDefine_S3x0)
        {
            ui->btnDot->setGeometry(190,114,72,34);
            ui->btnDelete_new1->setGeometry(266,0,72,34);
        }else{
            ui->btnDot->setGeometry(320,192,124,60);
            ui->btnDelete_new1->setGeometry(448,0,124,60);
        }
    }
}
void frmInput::hp_setDefine_S3x0(bool isSelect)
{
    isDefine_S3x0 = isSelect;
    if(isSelect)
    {
        QFont font12;
        font12.setPointSize(12);

        this->resize(491,574);
        ui->btnOther12->setGeometry(410,230,34,34);
        ui->btnOther14->setGeometry(410,190,34,34);
        ui->btnOther17->setGeometry(410,110,34,34);
        ui->btnOther18->setGeometry(410,270,34,34);
        ui->btnOther21->setGeometry(410,150,34,34);
        ui->pushButton->setGeometry(400,432,41,31);

        ui->widgetMain->setGeometry(0,62,384,150);
        ui->btnDelete->setGeometry(323,76,53,34);
        ui->btnEnter->setGeometry(323,114,53,34);
        ui->btnSpace->setGeometry(147,114,80,34);
        ui->btnOther_new16->setGeometry(231,114,34,34);
        ui->btnType->setGeometry(0,76,53,34);
        ui->btna->setGeometry(19,38,34,34);
        ui->btnb->setGeometry(209,76,34,34);
        ui->btnc->setGeometry(133,76,34,34);
        ui->btnchange_123->setGeometry(0,114,53,34);
        ui->btnOther_new17->setGeometry(57,114,48,34);
        ui->btnOther_new15->setGeometry(109,114,34,34);
        ui->btnchange_sym1->setGeometry(269,114,48,34);
        ui->btnd->setGeometry(95,38,34,34);
        ui->btne->setGeometry(76,0,34,34);
        ui->btnf->setGeometry(133,38,34,34);
        ui->btng->setGeometry(171,38,34,34);
        ui->btnh->setGeometry(209,38,34,34);
        ui->btni->setGeometry(266,0,34,34);
        ui->btnj->setGeometry(247,38,34,34);
        ui->btnk->setGeometry(285,38,34,34);
        ui->btnl->setGeometry(323,38,34,34);
        ui->btnm->setGeometry(285,76,34,34);
        ui->btnn->setGeometry(247,76,34,34);
        ui->btno->setGeometry(304,0,34,34);
        ui->btnp->setGeometry(342,0,34,34);
        ui->btnq->setGeometry(0,0,34,34);
        ui->btnr->setGeometry(114,0,34,34);
        ui->btns->setGeometry(57,38,34,34);
        ui->btnt->setGeometry(152,0,34,34);
        ui->btnu->setGeometry(228,0,34,34);
        ui->btnv->setGeometry(171,76,34,34);
        ui->btnw->setGeometry(38,0,34,34);
        ui->btnx->setGeometry(95,76,34,34);
        ui->btny->setGeometry(190,0,34,34);
        ui->btnz->setGeometry(57,76,34,34);

        ui->widget_sub->setGeometry(0,220,384,150);
        ui->btn0->setGeometry(114,114,72,34);
        ui->btn00->setGeometry(38,114,72,34);
        ui->btn1->setGeometry(38,0,72,34);
        ui->btn2->setGeometry(114,0,72,34);
        ui->btn3->setGeometry(190,0,72,34);
        ui->btn4->setGeometry(38,38,72,34);
        ui->btn5->setGeometry(114,38,72,34);
        ui->btn6->setGeometry(190,38,72,34);
        ui->btn7->setGeometry(38,76,72,34);
        ui->btn8->setGeometry(114,76,72,34);
        ui->btn9->setGeometry(190,76,72,34);
        ui->btnDelete_new1->setGeometry(266,0,72,34);
        ui->btnDot->setGeometry(190,114,72,34);
        ui->btnSpace_new1->setGeometry(266,38,71,34);
        ui->btnchange_abc->setGeometry(266,114,71,34);
        ui->btnchange_sym2->setGeometry(266,76,71,34);

        ui->widget_symbol->setGeometry(0,380,384,150);
        ui->btnDelete_new2->setGeometry(304,0,34,34);
        ui->btnOther1->setGeometry(76,0,34,34);
        ui->btnOther10->setGeometry(304,76,34,34);
        ui->btnOther11->setGeometry(228,38,34,34);
        ui->btnOther13->setGeometry(114,38,34,34);
        ui->btnOther15->setGeometry(304,114,34,34);
        ui->btnOther16->setGeometry(304,38,34,34);
        ui->btnOther19->setGeometry(152,38,34,34);
        ui->btnOther2->setGeometry(114,0,34,34);
        ui->btnOther20->setGeometry(190,38,34,34);
        ui->btnOther3->setGeometry(152,0,34,34);
        ui->btnOther4->setGeometry(190,0,34,34);
        ui->btnOther5->setGeometry(228,0,34,34);
        ui->btnOther6->setGeometry(266,0,34,34);
        ui->btnOther7->setGeometry(76,38,34,34);
        ui->btnOther8->setGeometry(38,38,34,34);
        ui->btnOther9->setGeometry(266,38,34,34);
        ui->btnOther_new1->setGeometry(38,76,34,34);
        ui->btnOther_new10->setGeometry(114,114,34,34);
        ui->btnOther_new11->setGeometry(152,114,34,34);
        ui->btnOther_new12->setGeometry(190,114,34,34);
        ui->btnOther_new13->setGeometry(228,114,34,34);
        ui->btnOther_new14->setGeometry(266,114,34,34);
        ui->btnOther_new2->setGeometry(76,76,34,34);
        ui->btnOther_new3->setGeometry(114,76,34,34);
        ui->btnOther_new4->setGeometry(152,76,34,34);
        ui->btnOther_new5->setGeometry(190,76,34,34);
        ui->btnOther_new6->setGeometry(228,76,34,34);
        ui->btnOther_new7->setGeometry(266,76,34,34);
        ui->btnOther_new8->setGeometry(38,114,34,34);
        ui->btnOther_new9->setGeometry(76,114,34,34);
        ui->btnchange_return->setGeometry(38,0,34,34);


        ui->widgetTop->setGeometry(0,0,384,60);
//        ui->widgetTop->setGeometry(-30,-15,410,80);
        ui->widgetTop->setFixedSize(384,60);
        ui->btnClose->setGeometry(341,2,40,25);
        ui->btnClose->setFixedSize(40,25);
        ui->btnNext->setGeometry(301,2,40,25);
        ui->btnNext->setFixedSize(40,25);
        ui->btnPre->setGeometry(261,2,40,25);
        ui->btnPre->setFixedSize(40,25);
        ui->labPY->setGeometry(50,2,150,25);
        ui->labPY->setFixedSize(150,25);
        ui->lab_Title->setGeometry(0,2,50,25);
        ui->lab_Title->setFixedSize(50,25);
        ui->labCh0->setGeometry(4,30,54,25);
        ui->labCh0->setFixedSize(54,25);
        ui->labCh1->setGeometry(58,30,54,25);
        ui->labCh1->setFixedSize(54,25);
        ui->labCh2->setGeometry(112,30,54,25);
        ui->labCh2->setFixedSize(54,25);
        ui->labCh3->setGeometry(166,30,54,25);
        ui->labCh3->setFixedSize(54,25);
        ui->labCh4->setGeometry(220,30,54,25);
        ui->labCh4->setFixedSize(54,25);
        ui->labCh5->setGeometry(274,30,54,25);
        ui->labCh5->setFixedSize(54,25);
        ui->labCh6->setGeometry(328,30,54,25);
        ui->labCh6->setFixedSize(54,25);
        ui->btnTask->setGeometry(480 / 1.7,64 / 1.7,124 / 1.7,60 / 1.7);
//        ui->labCh7->setGeometry(382,30,1,25);//最后三个不显示
//        ui->labCh7->setFixedSize(1,25);
//        ui->labCh8->setGeometry(383,30,1,25);
//        ui->labCh8->setFixedSize(1,25);
//        ui->labCh9->setGeometry(384,30,1,25);
//        ui->labCh9->setFixedSize(1,25);

//        ui->labCh7->close();
//        ui->labCh8->close();
//        ui->labCh9->close();

//        ui->verticalLayout->setGeometry(QRect(0,0,300,80));

        ui->labCh0->setFont(font12);
        ui->labCh1->setFont(font12);
        ui->labCh2->setFont(font12);
        ui->labCh3->setFont(font12);
        ui->labCh4->setFont(font12);
        ui->labCh5->setFont(font12);
        ui->labCh6->setFont(font12);
//        ui->labCh7->setFont(font12);
//        ui->labCh8->setFont(font12);

        ui->widgetTop->setStyleSheet("font: 12pt '微软雅黑';border-width:0px;background-color: transparent;");

        btnFontSize = 12;           //12
        labFontSize = 12;           //12
        ChangeFont();
    }
}

void frmInput::Init(QString position, QString style, int btnFontSize, int labFontSize)          //输入法面板初始化
{
    this->currentPosition = position;
    this->currentStyle = style;                                                             //当前输入法面板样式
    this->btnFontSize = btnFontSize;                                                //当前输入法面板按钮字体大小
    this->labFontSize = labFontSize;
    this->ChangeStyle();
    this->ChangeFont();
}
//鼠标拖动事件
void frmInput::mouseMoveEvent(QMouseEvent *e)
{
//    if (mousePressed && (e->buttons() && Qt::LeftButton))
 //   {
        //this->move(e->globalPos() - mousePoint);
  //      e->accept();
 //   }
}
//鼠标按下事件
void frmInput::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}
//鼠标松开事件
void frmInput::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void frmInput::InitForm()                       //也是一个初始化
{
    this->mousePressed = false;
   // this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

   // QDesktopWidget w;
   // deskWidth = w.availableGeometry().width();
    //deskHeight = w.availableGeometry().height();
    //frmWidth = this->width();
    //frmHeight = this->height();

    //    QSqlDatabase DbConn;
    //    DbConn = QSqlDatabase::addDatabase("QSQLITE", "py");
    //    DbConn.setDatabaseName(qApp->applicationDirPath() + "/py.db");
    //    DbConn.open();//加载拼音字库


    int nResult = sqlite3_open("py.db",&db);
    if (nResult != SQLITE_OK)
    {
        qDebug()<<"open datadase error ："<<sqlite3_errmsg(db);
    }
    else
    {
        //qDebug()<<"数据库打开成功(open datadase OK)";
    }

    isFirst = true;
    isPress = false;
    timerPress = new QTimer(this);
    connect(timerPress, SIGNAL(timeout()), this, SLOT(reClicked()));

    old_Widget = 0;
    currentWidget = 0;
    currentLineEdit = 0;
    currentTextEdit = 0;
    currentPlain = 0;
    currentBrowser = 0;
    currentEditType = "";

    //如果需要更改输入法面板的显示位置,改变currentPosition这个变量即可
    //control--显示在对应输入框的正下方 bottom--填充显示在底部  center--窗体居中显示
    currentPosition = "";

    //如果需要更改输入法面板的样式,改变currentStyle这个变量即可
    //blue--淡蓝色  dev--dev风格  black--黑色  brown--灰黑色  lightgray--浅灰色  darkgray--深灰色  gray--灰色  silvery--银色
  //  currentStyle = "";     new：
    currentStyle = "black";

    //输入法面板字体大小,如果需要更改面板字体大小,该这里即可
    if(isDefine_S3x0)
    {
        btnFontSize = 12;           //12
        labFontSize = 12;           //12
    }else{
        btnFontSize = 20;           //12
        labFontSize = 20;           //12
    }




    //如果需要更改输入法初始模式,改变currentType这个变量即可
    //min--小写模式  max--大写模式  chinese--中文模式
    currentType = "min";
    changeType(currentType);

    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn)
    {
        connect(b, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    }
    //绑定全局改变焦点信号槽
    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)),
            this, SLOT(focusChanged(QWidget *, QWidget *)));
    //绑定按键事件过滤器
    qApp->installEventFilter(this);
}

//初始化键盘按键（使能）    //设置扩展属性
void frmInput::InitProperty()
{
    ui->btnOther1->setProperty("btnOther", true);
    ui->btnOther2->setProperty("btnOther", true);
    ui->btnOther3->setProperty("btnOther", true);
    ui->btnOther4->setProperty("btnOther", true);
    ui->btnOther5->setProperty("btnOther", true);
    ui->btnOther6->setProperty("btnOther", true);
    ui->btnOther7->setProperty("btnOther", true);
    ui->btnOther8->setProperty("btnOther", true);
    ui->btnOther9->setProperty("btnOther", true);
    ui->btnOther10->setProperty("btnOther", true);
    ui->btnOther11->setProperty("btnOther", true);
    ui->btnOther12->setProperty("btnOther", true);
    ui->btnOther13->setProperty("btnOther", true);
    ui->btnOther14->setProperty("btnOther", true);
    ui->btnOther15->setProperty("btnOther", true);
    ui->btnOther16->setProperty("btnOther", true);
    ui->btnOther17->setProperty("btnOther", true);
    ui->btnOther18->setProperty("btnOther", true);
    ui->btnOther19->setProperty("btnOther", true);
    ui->btnOther20->setProperty("btnOther", true);
    ui->btnOther21->setProperty("btnOther", true);

   //  btnOther_new1
    ui->btnOther_new1->setProperty("btnOther",true);
    ui->btnOther_new2->setProperty("btnOther",true);
    ui->btnOther_new3->setProperty("btnOther",true);
    ui->btnOther_new4->setProperty("btnOther",true);
    ui->btnOther_new5->setProperty("btnOther",true);
    ui->btnOther_new6->setProperty("btnOther",true);
    ui->btnOther_new7->setProperty("btnOther",true);
    ui->btnOther_new8->setProperty("btnOther",true);
    ui->btnOther_new9->setProperty("btnOther",true);
    ui->btnOther_new10->setProperty("btnOther",true);
    ui->btnOther_new11->setProperty("btnOther",true);
    ui->btnOther_new12->setProperty("btnOther",true);
    ui->btnOther_new13->setProperty("btnOther",true);
    ui->btnOther_new14->setProperty("btnOther",true);
    ui->btnOther_new15->setProperty("btnOther",true);
    ui->btnOther_new16->setProperty("btnOther",true);
    ui->btnOther_new17->setProperty("btnOther",true);

    //一个空格，2个删除
    ui->btnDelete_new1->setProperty("btnOther", true);
    ui->btnDelete_new2->setProperty("btnOther", true);
    ui->btnSpace_new1->setProperty("btnOther", true);

    ui->btnDot->setProperty("btnOther", true);
    ui->btnSpace->setProperty("btnOther", true);
    ui->btnEnter->setProperty("btnOther", true);
    ui->btnDelete->setProperty("btnOther", true);

    ui->btn0->setProperty("btnNum", true);
    ui->btn1->setProperty("btnNum", true);
    ui->btn2->setProperty("btnNum", true);
    ui->btn3->setProperty("btnNum", true);
    ui->btn4->setProperty("btnNum", true);
    ui->btn5->setProperty("btnNum", true);
    ui->btn6->setProperty("btnNum", true);
    ui->btn7->setProperty("btnNum", true);
    ui->btn8->setProperty("btnNum", true);
    ui->btn9->setProperty("btnNum", true);
    ui->btn00->setProperty("btnNum", true);

    ui->btna->setProperty("btnLetter", true);
    ui->btnb->setProperty("btnLetter", true);
    ui->btnc->setProperty("btnLetter", true);
    ui->btnd->setProperty("btnLetter", true);
    ui->btne->setProperty("btnLetter", true);
    ui->btnf->setProperty("btnLetter", true);
    ui->btng->setProperty("btnLetter", true);
    ui->btnh->setProperty("btnLetter", true);
    ui->btni->setProperty("btnLetter", true);
    ui->btnj->setProperty("btnLetter", true);
    ui->btnk->setProperty("btnLetter", true);
    ui->btnl->setProperty("btnLetter", true);
    ui->btnm->setProperty("btnLetter", true);
    ui->btnn->setProperty("btnLetter", true);
    ui->btno->setProperty("btnLetter", true);
    ui->btnp->setProperty("btnLetter", true);
    ui->btnq->setProperty("btnLetter", true);
    ui->btnr->setProperty("btnLetter", true);
    ui->btns->setProperty("btnLetter", true);
    ui->btnt->setProperty("btnLetter", true);
    ui->btnu->setProperty("btnLetter", true);
    ui->btnv->setProperty("btnLetter", true);
    ui->btnw->setProperty("btnLetter", true);
    ui->btnx->setProperty("btnLetter", true);
    ui->btny->setProperty("btnLetter", true);
    ui->btnz->setProperty("btnLetter", true);

    labCh.append(ui->labCh0);
    labCh.append(ui->labCh1);
    labCh.append(ui->labCh2);
    labCh.append(ui->labCh3);
    labCh.append(ui->labCh4);
    labCh.append(ui->labCh5);
    labCh.append(ui->labCh6);
//    labCh.append(ui->labCh7);
//    labCh.append(ui->labCh8);
//    labCh.append(ui->labCh9);
    for (int i = 0; i < labCh.count(); i++)
    {
        labCh[i]->installEventFilter(this);
    }
}
//右上角
void frmInput::ShowPanel()
{
//    move(0,0);
//    setFixedSize(320, 120);
//    ui->widgetTop->setMaximumHeight(height()/3);
//    ui->widgetMain->setMinimumHeight(height()*2/3);
    this->setVisible(true);
 //   int width = ui->btn0->width();
//    width = width > 40 ? width : 40;
//    ui->btnPre->setMinimumWidth(width);
//    ui->btnPre->setMaximumWidth(width);
//    ui->btnNext->setMinimumWidth(width);
//    ui->btnNext->setMaximumWidth(width);
//    ui->btnClose->setMinimumWidth(width);
//    ui->btnClose->setMaximumWidth(width);
    //emit sigShowed(this->geometry());
}



//事件过滤器,用于识别鼠标单击汉字标签处获取对应汉字
bool frmInput::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            if (obj == ui->labCh0)
            {
                setChinese(0);
            }
            else if (obj == ui->labCh1)
            {
                setChinese(1);
            }
            else if (obj == ui->labCh2)
            {
                setChinese(2);
            }
            else if (obj == ui->labCh3)
            {
                setChinese(3);
            }
            else if (obj == ui->labCh4)
            {
                setChinese(4);
            }
            else if (obj == ui->labCh5)
            {
                setChinese(5);
            }
            else if (obj == ui->labCh6)
            {
                setChinese(6);
            }
//            else if (obj == ui->labCh7)
//            {
//                setChinese(7);
//            }
//            else if (obj == ui->labCh8)
//            {
//                setChinese(8);
//            }
//            else if (obj == ui->labCh9)
//            {
//                setChinese(9);
//            }
             else if (currentEditType != "" && obj != ui->btnClose)     //当前焦点的控件类型
            {
                QString objName = obj->objectName();
//                if (!obj->property("noinput").toBool() && objName != "frmMainWindow"
//                        && objName != "frmInputWindow" && objName != "qt_edit_menu")
                if (!obj->property("noinput").toBool() && objName == "lineEdit")
                {
                    ShowPanel();          //可以理解为右上角初始化
                }
            }
            btnPress = (QPushButton *)obj;
            if (checkPress())
            {
                isPress = true;
                timerPress->start(500);
            }
            return false;
        }
    }

    else if (event->type() == QEvent::MouseButtonRelease)
    {
        btnPress = (QPushButton *)obj;
        if (checkPress())
        {
            isPress = false;
            timerPress->stop();
        }
        return false;
    }

    else if (event->type() == QEvent::KeyPress)
    {
        //如果输入法窗体不可见,则不需要处理
        if (!isVisible())
        {
            return QWidget::eventFilter(obj, event);
        }

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //Shift切换输入法模式,esc键关闭输入法面板,空格取第一个汉字,退格键删除
        //中文模式下回车键取拼音,中文模式下当没有拼音时可以输入空格
        if (keyEvent->key() == Qt::Key_Space)
        {
            if (ui->labPY->text() != "")
            {
                setChinese(0);
                return true;
            } else
            {
                return false;
            }
        }
        else if(keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
        {
            qDebug()<<"C and V keys are used for photographing and video, which is disabled 00";
            return true;
        }
        else if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
        {
            insertValue(ui->labPY->text());
            ui->labPY->setText("");
            selectChinese();
            return true;
        }
        else if (keyEvent->key() == Qt::Key_Shift)
        {
            ui->btnType->click();
            return true;
        }
        //        else if (keyEvent->key() == Qt::Key_Escape)
        //        {
        //            ui->btnClose->click();
        //            return true;
        //        }
        else if (keyEvent->key() == Qt::Key_Backspace)
        {
            ui->btnDelete->click();
            return true;
        }
        else if (keyEvent->text() == "+" || keyEvent->text() == "=")
        {
            if (ui->labPY->text() != "")
            {
                ui->btnNext->click();
                return true;
            } else
            {
                return false;
            }
        }
        else if (keyEvent->text() == "-" || keyEvent->text() == "_")
        {
            if (ui->labPY->text() != "")
            {
                ui->btnPre->click();
                return true;
            }
            else
            {
                return false;
            }
        } else if (keyEvent->key() == Qt::Key_CapsLock)
        {
            if (currentType != "max")
            {
                currentType = "max";
            } else
            {
                currentType = "min";
            }
            changeType(currentType);
            return true;
        }
        else
        {
            if (currentEditType == "QWidget")
            {
                return false;
            }
            QString key;
            if (currentType == "chinese")
            {
                key = keyEvent->text();
            }
            else if (currentType == "min")
            {
                key = keyEvent->text().toLower();
            }
            else if (currentType == "max")
            {
                key = keyEvent->text().toUpper();
            }
            QList<QPushButton *> btn = this->findChildren<QPushButton *>();
            foreach (QPushButton * b, btn)
            {
                if (b->text() == key)
                {
                    b->click();
                    return true;
                }
            }
        }
        return false;
    }
    return QWidget::eventFilter(obj, event);
}

//只有属于输入法键盘的合法按钮才继续处理
bool frmInput::checkPress()
{
    //只有属于输入法键盘的合法按钮才继续处理
    bool num_ok = btnPress->property("btnNum").toBool();
    bool other_ok = btnPress->property("btnOther").toBool();
    bool letter_ok = btnPress->property("btnLetter").toBool();
    if (num_ok || other_ok || letter_ok)
    {
        return true;
    }
    return false;
}

void frmInput::reClicked()
{
    if (isPress)
    {
        timerPress->setInterval(30);
        btnPress->click();
    }
}

void frmInput::focusChanged(QWidget *oldWidget, QWidget *nowWidget)
{
    if(!g_NumInput)
    {
        old_Widget = oldWidget;
        if (nowWidget != 0 && !this->isAncestorOf(nowWidget))
        {
            //在Qt5和linux系统中(嵌入式linux除外),当输入法面板关闭时,焦点会变成无,然后焦点会再次移到焦点控件处
            //这样导致输入法面板的关闭按钮不起作用,关闭后马上有控件获取焦点又显示.
            //为此,增加判断,当焦点是从有对象转为无对象再转为有对象时不要显示.
            //这里又要多一个判断,万一首个窗体的第一个焦点就是落在可输入的对象中,则要过滤掉
#ifndef __arm__
            if (oldWidget == 0x0 && !isFirst)
            {
                QTimer::singleShot(0, this, SLOT(gotoShadow()));
                return;
            }
#endif

            //如果对应属性noinput为真则不显示
            if (nowWidget->property("noinput").toBool())
            {
                QTimer::singleShot(0, this, SLOT(gotoShadow()));
                return;
            }

            isFirst = false;
            if (nowWidget->inherits("QLineEdit"))
            {
                currentLineEdit = (QLineEdit *)nowWidget;
                currentEditType = "QLineEdit";
                ShowPanel();
            }
            else
            {
                //需要将输入法切换到最初的原始状态--小写,同时将之前的对象指针置为零
                currentWidget = 0;
                currentLineEdit = 0;
                currentTextEdit = 0;
                currentPlain = 0;
                currentBrowser = 0;
                currentEditType = "";
                currentType = "min";
                changeType(currentType);
                this->gotoShadow();
            }
        }
    }
}

//切换输入法
void frmInput::changeType(QString type)
{
    if (type == "max")
    {
        changeLetter(true);
        ui->btnType->setText("AB");
        ui->lab_Title->setText("<AB>");
        ui->btnOther12->setText("/");
        ui->btnOther14->setText(":");
        ui->btnOther17->setText(",");
        ui->btnOther18->setText("\\");
        ui->btnOther21->setText("\"");
    }
    else if (type == "min")
    {
        changeLetter(false);
        ui->btnType->setText("ab");
        ui->lab_Title->setText("<ab>");
        ui->btnOther12->setText("/");
        ui->btnOther14->setText(":");
        ui->btnOther17->setText(",");
        ui->btnOther18->setText("\\");
        ui->btnOther21->setText("\"");
    }
    else
    {
        changeLetter(false);
        ui->btnType->setText("Zh");
        ui->lab_Title->setText("<Zh>");
        ui->btnOther12->setText("。");
        ui->btnOther14->setText("：");
        ui->btnOther17->setText("，");
        ui->btnOther18->setText("；");
        ui->btnOther21->setText("“");
    }
    //每次切换到模式,都要执行清空之前中文模式下的信息
    clearChinese();
    ui->labPY->setText("");
}

void frmInput::changeLetter(bool isUpper)
{
    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn)
    {
        if (b->property("btnLetter").toBool())
        {
            if (isUpper)
            {
                b->setText(b->text().toUpper());
            }
            else
            {
                b->setText(b->text().toLower());
            }
        }
    }
}

void frmInput::selectChinese()
{
    clearChinese();
    QString currentPY = ui->labPY->text();
    QString sql = QString("SELECT word FROM pinyin WHERE pinyin='%1'").arg(currentPY);
    char* errmsg;
    int nResult = sqlite3_exec(db,sql.toLatin1().data(),callback,NULL,&errmsg);
    if (nResult != SQLITE_OK)
    {
        sqlite3_close(db);
        sqlite3_free(errmsg);
        return;
    }
    showChinese();
}

int callback(void* ,int nCount,char** pValue,char** pName)
{
    //逐个将查询到的字词加入汉字队列
    for(int i=0;i<nCount;i++)
    {
        QString result = pValue[i];


        QStringList text = result.split(" ");
        foreach (QString txt, text)
        {
            if (txt.length() > 0)
            {
                allPY.append(txt);
                currentPY_count++;
            }
        }
    }
}

void frmInput::showChinese()
{
    //每个版面最多显示10个汉字
    int count = 0;
    currentPY.clear();
    //10 ->7  lcy
    for (int i = 0; i < labCh.count(); i++) {
        labCh[i]->setText("");
    }

    for (int i = currentPY_index; i < currentPY_count; i++) {
        if (count >= labCh.count()) {
            break;
        }
        QString txt = QString("%1.%2").arg(count).arg(allPY[currentPY_index]);
        currentPY.append(allPY[currentPY_index]);
        labCh[count]->setText(txt);
        count++;
        currentPY_index++;
    }
}

//点击后触发的槽
void frmInput::btn_clicked()
{
    //如果当前焦点控件类型为空,则返回不需要继续处理
    if (currentEditType == "")
    {
        return;
    }

    QPushButton *btn = (QPushButton *)sender();
    QString objectName = btn->objectName();
    if (objectName == "btnType")   //应该是按键名字
    {
        if (currentType == "min")   //当前输入法类型
        {
            currentType = "max";
        }
        else if (currentType == "max")
        {
            currentType = "chinese";
        }
        else if (currentType == "chinese")
        {
            currentType = "min";
        }
        changeType(currentType);    //切换输入法

    } else if ((objectName == "btnDelete" )|| (objectName == "btnDelete_new1" ) ||(objectName == "btnDelete_new2" ) )       //删除按钮
    {
        //如果当前是中文模式,则删除对应拼音,删除完拼音之后再删除对应文本输入框的内容
        if (currentType == "chinese")
        {
            QString txt = ui->labPY->text();
            int len = txt.length();
            if (len > 0)
            {
                ui->labPY->setText(txt.left(len - 1));
                selectChinese();
            }
            else
            {
                deleteValue();
            }
        }
        else
        {
            deleteValue();
        }
    }
    else if (objectName == "btnPre")    //又上角左箭头
    {
/*          lcy
        if (currentPY_index >= 20)
        {
            //每次最多显示10个汉字,所以每次向前的时候索引要减20
            if (currentPY_index % 10 == 0)
            {
                currentPY_index -= 20;
            }
            else
            {
                currentPY_index = currentPY_count - (currentPY_count % 10) - 10;
            }
        }
   */
        if (currentPY_index >= 14)
        {
            //每次最多显示10个汉字,所以每次向前的时候索引要减20
            if (currentPY_index % 7 == 0)
            {
                currentPY_index -= 14;
            }
            else
            {
                currentPY_index = currentPY_count - (currentPY_count % 7) - 7;
            }
        }
        else
        {
            currentPY_index = 0;
        }
        showChinese();
    }
    else if (objectName == "btnNext")   //右上角 右jian'tou箭头
    {
        if (currentPY_index < currentPY_count - 1)
        {
            showChinese();
        }
    }
    else if (objectName == "btnClose")      //右上角 X按钮
    {
        //this->gotoShadow();
        //        old_Widget->setFocus();
        if(isDefine_S3x0)
        {
            ui->widgetMain->setGeometry(0,60,384,150);
            ui->widget_sub->setGeometry(0,220,384,150);
            ui->widget_symbol->setGeometry(0,370,384,150);
        }else{
            ui->widgetMain->setGeometry(0,110,640,261);
            ui->widget_sub->setGeometry(0,400,640,261);
            ui->widget_symbol->setGeometry(0,630,640,261);
        }
        this->setVisible(false);
    }
    else if (objectName == "btnSpace")      //空格按钮
    {
        insertValue(" ");
    }
    else if (objectName == "btnSpace_new1")      //空格按钮_   NEW
    {
        insertValue(" ");
    }
    else if (objectName == "btnEnter")          //Ent按钮
    {
        QWidget *widget;
        widget = 0;
        if (currentEditType == "QLineEdit")
        {
            widget = currentLineEdit;
        }
        else if (currentEditType == "QTextEdit")
        {
            widget = currentTextEdit;
        }
        else if (currentEditType == "QPlainTextEdit")
        {
            widget = currentPlain;
        }
        else if (currentEditType == "QTextBrowser")
        {
            widget = currentBrowser;
        }
        else if (currentEditType == "QWidget")
        {
            widget = currentWidget;
        }

        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
        QApplication::sendEvent(widget, &keyPress);
        this->gotoShadow();
    }
    else if (objectName == "btnchange_123")    //字符输入法 切换为数字输入法         5.24
    {
        if(isDefine_S3x0)
        {
            ui->widget_sub->setGeometry(0,60,384,150);
            ui->widgetMain->setGeometry(0,220,384,150);
        }else{
            ui->widget_sub->setGeometry(0,110,640,261);
            ui->widgetMain->setGeometry(0,400,640,261);
        }
    }
    else if (objectName == "btnchange_sym1")    //字符输入法 切换为符号输入法
    {
        if(isDefine_S3x0)
        {
            ui->widget_symbol->setGeometry(0,60,384,150);
            ui->widgetMain->setGeometry(0,220,384,150);
        }else{
            ui->widget_symbol->setGeometry(0,110,640,261);
            ui->widgetMain->setGeometry(0,400,640,261);
        }
        symbol_state = 1;
    }
    else if (objectName == "btnchange_abc")     //数字输入法 切换为字符输入法
    {
        if(isDefine_S3x0)
        {
            ui->widget_sub->setGeometry(0,220,384,150);
            ui->widgetMain->setGeometry(0,60,384,150);
        }else{
            ui->widget_sub->setGeometry(0,400,640,261);
            ui->widgetMain->setGeometry(0,110,640,261);
        }
    }
    else if (objectName == "btnchange_sym2")    //数字输入法 切换为 符号输入法
    {
        if(isDefine_S3x0)
        {
            ui->widget_symbol->setGeometry(0,60,384,150);
            ui->widget_sub->setGeometry(0,220,384,150);
        }else{
            ui->widget_symbol->setGeometry(0,110,640,261);
            ui->widget_sub->setGeometry(0,400,640,261);
        }
        symbol_state = 2;
    }else if(objectName == "btnTask")
    {
        qDebug() << "--<Task Btn>--";
        signalTask();
    }else if (objectName == "btnchange_return")  //符号输入法返回
    {

        if(symbol_state ==1)                                //返回主菜单
        {
            if(isDefine_S3x0)
            {
                ui->widgetMain->setGeometry(0,60,384,150);
                ui->widget_symbol->setGeometry(0,220,384,150);
            }else{
                ui->widgetMain->setGeometry(0,110,640,261);
                ui->widget_symbol->setGeometry(0,400,640,261);
            }
        }else if(symbol_state == 2)                     //返回数字菜单
        {
            if(isDefine_S3x0)
            {
                ui->widget_sub->setGeometry(0,60,384,150);
                ui->widget_symbol->setGeometry(0,220,384,150);
            }else{
                ui->widget_sub->setGeometry(0,110,640,261);
                ui->widget_symbol->setGeometry(0,400,640,261);
            }
        }else{

        }
            symbol_state = 0;
    }
    else                                                    //其它按钮
    {
        QString value = btn->text();
        //如果是&按钮，因为对应&被过滤,所以真实的text为去除前面一个&字符
        if (objectName == "btnOther7") {
            value = value.right(1);
        }
        //当前不是中文模式,则单击按钮对应text为传递参数
        if (currentType != "chinese") {
            insertValue(value);
        } else {
            //中文模式下,不允许输入特殊字符,单击对应数字按键取得当前索引的汉字
            if (btn->property("btnOther").toBool()) {
                if (ui->labPY->text().length() == 0) {
                    insertValue(value);
                }
            } else if (btn->property("btnNum").toBool()) {
                if (ui->labPY->text().length() == 0) {
                    insertValue(value);
                } else if (objectName == "btn0") {
                    setChinese(0);
                } else if (objectName == "btn1") {
                    setChinese(1);
                } else if (objectName == "btn2") {
                    setChinese(2);
                } else if (objectName == "btn3") {
                    setChinese(3);
                } else if (objectName == "btn4") {
                    setChinese(4);
                } else if (objectName == "btn5") {
                    setChinese(5);
                } else if (objectName == "btn6") {
                    setChinese(6);
                } else if (objectName == "btn7") {
                    setChinese(7);
                } else if (objectName == "btn8") {
                    setChinese(8);
                } else if (objectName == "btn9") {
                    setChinese(9);
                }
            }
            else if (btn->property("btnLetter").toBool())
            {
                ui->labPY->setText(ui->labPY->text() + value);
                selectChinese();
            }
        }
    }
}

void frmInput::insertValue(QString value)
{
    if (currentEditType == "QLineEdit")
    {
        currentLineEdit->insert(value);
    }
    else if (currentEditType == "QTextEdit")
    {
        currentTextEdit->insertPlainText(value);
    }
    else if (currentEditType == "QPlainTextEdit")
    {
        currentPlain->insertPlainText(value);
    }
    else if (currentEditType == "QTextBrowser")
    {
        currentBrowser->insertPlainText(value);
    }
    else if (currentEditType == "QWidget")
    {
        QKeyEvent keyPress(QEvent::KeyPress, 0, Qt::NoModifier, QString(value));
        QApplication::sendEvent(currentWidget, &keyPress);
    }
}

void frmInput::deleteValue()
{
    if (currentEditType == "QLineEdit")
    {
        currentLineEdit->backspace();
    }
    else if (currentEditType == "QTextEdit")
    {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentTextEdit->textCursor();
        if(cursor.hasSelection())
        {
            cursor.removeSelectedText();
        }
        else
        {
            cursor.deletePreviousChar();
        }
    }
    else if (currentEditType == "QPlainTextEdit")
    {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentPlain->textCursor();
        if(cursor.hasSelection())
        {
            cursor.removeSelectedText();
        }
        else
        {
            cursor.deletePreviousChar();
        }
    }
    else if (currentEditType == "QTextBrowser")
    {
        //获取当前QTextEdit光标,如果光标有选中,则移除选中字符,否则删除光标前一个字符
        QTextCursor cursor = currentBrowser->textCursor();
        if(cursor.hasSelection())
        {
            cursor.removeSelectedText();
        }
        else
        {
            cursor.deletePreviousChar();
        }
    } else if (currentEditType == "QWidget")
    {
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier, QString());
        QApplication::sendEvent(currentWidget, &keyPress);
    }
}

void frmInput::setChinese(int index)
{
    int count = currentPY.count();
    if (count > index)
    {
        insertValue(currentPY[index]);
        //添加完一个汉字后,清空当前汉字信息,等待重新输入
        clearChinese();
        ui->labPY->setText("");
    }
}

void frmInput::clearChinese()
{
    //清空汉字,重置索引
    for (int i = 0; i < labCh.count(); i++)
    {
        labCh[i]->setText("");
    }
    allPY.clear();
    currentPY.clear();
    currentPY_index = 0;
    currentPY_count = 0;
}

void frmInput::ChangeStyle()
{
       if (currentStyle == "blue")
    {
        changeStyle("#DEF0FE", "#C0DEF6", "#C0DCF2", "#386487");
    }
    else if (currentStyle == "dev")
    {
        changeStyle("#C0D3EB", "#BCCFE7", "#B4C2D7", "#324C6C");
    }
    else if (currentStyle == "gray")
    {
        changeStyle("#E4E4E4", "#A2A2A2", "#A9A9A9", "#000000");
    }
    else if (currentStyle == "lightgray")
    {
        changeStyle("#EEEEEE", "#E5E5E5", "#D4D0C8", "#6F6F6F");
    }
    else if (currentStyle == "darkgray")
    {
        changeStyle("#D8D9DE", "#C8C8D0", "#A9ACB5", "#5D5C6C");
    }
    else if (currentStyle == "black")
    {
        changeStyle("#4D4D4D", "#292929", "#D9D9D9", "#CACAD0");
    }
    else if (currentStyle == "brown")
    {
        changeStyle("#667481", "#566373", "#C2CCD8", "#E7ECF0");
    }
    else if (currentStyle == "silvery")
    {
        changeStyle("#E1E4E6", "#CCD3D9", "#B2B6B9", "#000000");
    }
    else if (currentStyle == "new")
    {
  //       changeStyle("#E1E4E6", "#CCD3D9", "#B2B6B9", "#000000");
     }
  //     changeStyle(QString topColor, QString bottomColor, QString borderColor, QString textColor);
}

void frmInput::ChangeFont()
{
    QFont btnFont(this->font().family(), btnFontSize);
    QFont labFont(this->font().family(), labFontSize);

    QList<QPushButton *> btns = ui->widgetMain->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns)
    {
        btn->setFont(btnFont);
    }
    QList<QPushButton *> btnsb = ui->widget_sub->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btnsb)
    {
        btn->setFont(btnFont);
    }
    QList<QPushButton *> btnsym = ui->widget_symbol->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btnsym)
    {
        btn->setFont(btnFont);
    }
    QList<QLabel *> labs = ui->widgetTop->findChildren<QLabel *>();
    foreach (QLabel * lab, labs)
    {
        lab->setFont(labFont);
    }
    ui->btnPre->setFont(labFont);
    ui->btnNext->setFont(labFont);
    ui->btnClose->setFont(labFont);
}

void frmInput::changeStyle(QString topColor, QString bottomColor, QString borderColor, QString textColor)
{
/*
        QStringList qss;
        qss.append(QString("QWidget#widget_title{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 %1,stop:1 %2);}")
               .arg(topColor).arg(bottomColor));
        qss.append("QPushButton{padding:5px;border-radius:3px;}");
        qss.append(QString("QPushButton:hover{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 %1,stop:1 %2);}")
               .arg(topColor).arg(bottomColor));
        qss.append(QString("QLabel,QPushButton{color:%1;}").arg(textColor));
        qss.append(QString("QPushButton#btnPre,QPushButton#btnNext,QPushButton#btnClose{padding:5px;}"));
        qss.append(QString("QPushButton{border:1px solid %1;background:rgba(0,0,0,0);}")
               .arg(borderColor));
        qss.append(QString("QLineEdit{border:1px solid %1;border-radius:5px;padding:2px;background:none;selection-background-color:%2;selection-color:%3;}")
               .arg(borderColor).arg(bottomColor).arg(topColor));
        this->setStyleSheet(qss.join(""));
*/
}
void frmInput::slot_frminput_init()
{
    if(isDefine_S3x0)
    {
        ui->widgetMain->setGeometry(0,60,384,150);
        ui->widget_sub->setGeometry(0,220,384,150);
        ui->widget_symbol->setGeometry(0,370,384,150);
    }else{
        ui->widgetMain->setGeometry(0,110,640,261);
        ui->widget_sub->setGeometry(0,400,640,261);
        ui->widget_symbol->setGeometry(0,630,640,261);
    }
}

void frmInput::on_btnTask_clicked()
{
    //signalTask();
}
