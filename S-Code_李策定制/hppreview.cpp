#include  "hppreview.h"
#include  "ui_hppreview.h"

#include  "mainwidget.h"
#include  <string.h>
//#include     <gst/gst.h>

//#include  <stdio.h>

HpPreview::HpPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpPreview)
{
    ui->setupUi(this);
    //    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    this->setGeometry(0,0,width(),height());
    setFixedSize(width(), height());
    fidpid = false;
    isDefineS300 = false;
    m_isVideoPlaying = false;
    if(FID_PID_MODE)
    {
        fidpid = true;
    }

    set_current_page = 0;
    hp_parent = parent;
    isFirstVideo = true;
    connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(slot_preview_close()));
    //    ui->listWidget->setStyleSheet("color:black;background:white;");
    define_640_512 = false;
    maskImage = new QImage(":/res/res/mask.png");
    hp_dialog = new Hp_Dialog(this);
    hp_dialog->setText("waiting..");
    hp_dialog->close();
    sdinsert = false;
    direct = "/run/media/mmcblk2p1/DCIM";
    pic_video = 0;
    current_page = 0;
    total_pages = 0;

    video_current = 0;
    picture_current = 0;
    picture_now = 0;
    picture_now_all = 0;
    twice_type = 0;

    Taskmode = false;

    pic_type =0;
    ui->list_type->setStyleSheet("QToolButton {border-image:url(:/res/res/mode_button_n.png);color:#7CA6C9;background:transparent;\
                                 border-image: url(:/res/res/preview_picture.png);}\
QToolButton:pressed{\
    border-image:url(:/res/res/mode_button_s.png);\
}");

//    update_dir_data(pic_video);
//    update_button_status();

if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
    qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
}

hssw = new Hp_Sd_Space_Warning(this);
hssw->close();

if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
    qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
}

define_hirplay = false;
if(Hir_Play)
{
    define_hirplay = true;
}

sd_format = false;

hp_text.setText("");
pre_pic_mode_i = 0;
first_pic_name = "jpg";
last_pic_name = "jpg";

//    hp_text_input = new Hp_Text_Input(this);
//    hp_text_input->setText("");
//    hp_text_input->close();
hp_text_input.setText("");
hp_text_input.isPreview = true;
hp_text_input.close();

ui->pages_info->installEventFilter(this);

connect(&hp_text_input,SIGNAL(sync_text()),this,SLOT(setpage()));

if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
    qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
}

StartCheckFile();

if(qEnvironmentVariable("QT_WAKE_UP_TEST") == "true"){
    qDebug() << "wake up test == > " << __func__ << " ; " << __LINE__;
}

}


HpPreview::~HpPreview()
{
    delete_preview_pointer();
    delete ui;
}


void HpPreview::delete_preview_pointer()
{
    if(hssw != nullptr)
    {
        delete hssw;
        hssw = nullptr;
    }
    if(hp_dialog != nullptr)
    {
        delete hp_dialog;
        hp_dialog = nullptr;
    }
    if(maskImage != nullptr)
    {
        delete maskImage;
        maskImage = nullptr;
    }
}

void HpPreview::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        QFont font7;
        font7.setPointSize(7);
        QFont font9;
        font9.setPointSize(9);
        QFont font10;
        font10.setPointSize(10);

        this->resize(480,272);
        isDefineS300 = true;
        ui->frame->setGeometry(0,0,480,272);
        ui->close->setGeometry(110,231,45,37);
        ui->delete_pic->setGeometry(162,231,39,37);
        ui->label->setGeometry(5,236,20,27);
        ui->label_sd->setGeometry(27,231,81,37);
        ui->last_page->setGeometry(380,231,39,37);
        ui->listWidget->setGeometry(4,4,472,222);
        ui->list_type->setGeometry(260,231,37,37);
        ui->next_page->setGeometry(430,231,39,37);
        ui->pages_info->setGeometry(323,232,51,37);
        ui->sr_1->setGeometry(76,8,15,15);
        ui->sr_2->setGeometry(197,8,15,15);
        ui->sr_3->setGeometry(316,8,15,15);
        ui->sr_4->setGeometry(435,8,15,15);
        ui->sr_5->setGeometry(76,128,15,15);
        ui->sr_6->setGeometry(197,128,15,15);
        ui->sr_7->setGeometry(316,128,15,15);
        ui->sr_8->setGeometry(435,128,15,15);
        ui->text_1->setGeometry(44,8,15,15);
        ui->text_2->setGeometry(165,8,15,15);
        ui->text_3->setGeometry(284,8,15,15);
        ui->text_4->setGeometry(403,8,15,15);
        ui->text_5->setGeometry(44,128,15,15);
        ui->text_6->setGeometry(165,128,15,15);
        ui->text_7->setGeometry(284,128,15,15);
        ui->text_8->setGeometry(403,128,15,15);
        ui->twice_analisys->setGeometry(211,231,39,37);
        ui->voice_1->setGeometry(60,8,15,15);
        ui->voice_2->setGeometry(181,8,15,15);
        ui->voice_3->setGeometry(300,8,15,15);
        ui->voice_4->setGeometry(419,8,15,15);
        ui->voice_5->setGeometry(60,128,15,15);
        ui->voice_6->setGeometry(181,128,15,15);
        ui->voice_7->setGeometry(300,128,15,15);
        ui->voice_8->setGeometry(419,128,15,15);

        ui->label_sd->setFont(font9);
        ui->pages_info->setFont(font10);
        ui->listWidget->setFont(font7);

        ui->listWidget->setIconSize(QSize(107,120));
        ui->listWidget->setGridSize(QSize(117,120));
        ui->listWidget->setSpacing(4);

        ui->listWidget->setStyleSheet("color:#7CA6C9;background:transparent;selection-color: rgb(82, 107, 161);selection-background-color: rgb(179, 163, 163);border:1px solid #2B5C83;");
    }
    connect(&hmp, SIGNAL(signal_stop_video_analysis()), this, SLOT(slot_stop_video_analysis()));
    hmp2.hp_setDefine_S3x0(isSelect);
    hp_dialog->hp_setDefine_S3x0(isSelect);
    hmp.hp_setDefine_S3x0(isSelect);
    hhp.hp_setDefine_S3x0(isSelect);
    pic_dialog.hp_setDefine_S3x0(isSelect);
    hp_text_input.hp_setDefine_S3x0(isSelect);
    hp_text.hp_setDefine_S3x0(isSelect);
    hssw->hp_setDefine_S3x0(isSelect);
    gstPlayer.hp_setDefine_S3x0(isSelect);
}
//手动修改页数
void HpPreview::setpage()
{
    QString str = hp_text_input.getText();
    if(str.isEmpty())
    {
        hp_text_input.close();
        return;
    }
    if(str.toInt() > total_pages || str.toInt() == 0)
    {
        hp_text_input.close();
        QString para;
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(define_s3X0 == 2)
        {
            hssw->move(hssw->x() - 48,hssw->y());
        }
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                hssw->warning("出错了","输入页号有误");
            }
            else if(para.toInt() == 1)
            {
                hssw->warning("出錯了","頁號有誤");
            }
            else if(para.toInt() == 2)//english
            {
                hssw->warning("Error","Wrong page number");
            }
            else if(para.toInt() == 3)//俄语
            {
                hssw->warning("ошибка","неправильно набран номер страницы");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                hssw->warning("Hiba","Rossz oldalszám");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                hssw->warning("Error","Número de página incorrecto");
            }
        }
        hssw->setDelayClose(3000);
        hssw->show();
        return;
    }
    current_page = str.toInt() - 1;//取消偏移
    show_page_info();
    //突然的卡住，应该是show_current_page函数之外还有信号没发
    //show_current_page(current_page);
    update_dir_data(pic_video);
    update_button_status();

    delaymsec(50);
    hp_text_input.close();
}
//延时函数
void HpPreview::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void HpPreview::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
bool HpPreview::eventFilter(QObject *w, QEvent *e)
{
    if(QEvent::MouseButtonPress == e->type())               //先判断是鼠标点击事件
    {
        if(w->objectName() == "pages_info")          //判断想要打开的是哪个下拉框
        {
            if(pic_type == 1)
            {
                hp_text_input.setbtnTaskVisble(false);
            }
            hp_text_input.setText("");
            hp_text_input.setpage();
            hp_text_input.show();
        }
    }
    return false;
}
void HpPreview::StartCheckFile()
{
    QDir dir;
    QString Strdirect="./res/TempStoragePng";
    QFileInfo fileInfo(Strdirect);

    if( fileInfo.isDir() )
    {
        return;
    }
    else
    {
        dir.mkdir(Strdirect);
    }
}

QStringList HpPreview::getFileList()
{
    //获取所有一及目录
    QStringList subDirs;
    QDir dir("/run/media/mmcblk2p1/");
    QFileInfoList fileList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QFileInfo fileInfo, fileList) {
        if (fileInfo.isDir()) {
            subDirs.append(fileInfo.filePath());
            //            qDebug() << "dir filePath " << fileInfo.filePath();
            //            qDebug() << "dir fileName " << fileInfo.fileName();
        }
    }
    return subDirs;
}
//深度搜索QDir目录下文件
void HpPreview::getAllFiles(const QString &directory, QStringList &fileList) {
    QDir dir(directory);
    QFileInfoList infoList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QFileInfo info, infoList) {
        if (info.isDir()) {
            getAllFiles(info.filePath(), fileList);
        } else {
            fileList.append(info.filePath());
        }
    }
}

QFileInfoList HpPreview::StartAutoUpload_once(bool isTask)
{
    QFileInfoList returnlist;
    QFileInfoList returnlist_only;
    QDir dir;
    QStringList filters;
    if(isTask)//旧的ftp上传只上传台账图像
    {
        filters.append(QString("*.irp.jpg"));
        filters.append(QString("*.vi.jpg"));
    }
    else
    {
        filters.append(QString("*.jpg"));
        filters.append(QString("*.bmp"));
    }
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setNameFilters(filters);
    dir.setSorting(QDir::Name | QDir::Reversed);
    QStringList dirlist ;
    dirlist = getFileList();//深度搜索DCIM目录下文件
    //    qDebug() << "dirlist.count()" << dirlist.count();
    if(dirlist.count() != 0)
    {
        for(int i = 0; i < dirlist.count(); i++)
        {
            dir.cd(dirlist.at(i));
            //            qDebug() << " current dir name" << dirlist.at(i);
            returnlist.append(dir.entryInfoList());
        }
    }
    if(isTask)
    {
        return returnlist;
    }else
    {
        for(int i = 0;i < returnlist.size();i++)//过滤台账图像
        {
            if(returnlist.at(i).fileName().contains(".irp.jpg",Qt::CaseInsensitive) || returnlist.at(i).fileName().contains(".vi.jpg",Qt::CaseInsensitive) || returnlist.at(i).fileName().contains(".avi",Qt::CaseInsensitive))
            {
                continue;
            }
            returnlist_only.append(returnlist.at(i));
        }
        return returnlist_only;
    }
    return returnlist;
}
void HpPreview::update_dir_data(int type)         //更新目录
{
    QDir dir;
    QStringList filters;
    QStringList dirlist;
    MainWidget* p = (MainWidget*)hp_parent;
    if(sdinsert)
    {
        signal_core_get_sd_info();   //向内核索取SD卡容量信息
    }

    QString timeReport = "【SD卡插入耗时】\n\n";
    struct timeval tv_begin, tv_end;
    long t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    long tt1 = 0, tt2 = 0, tt3 = 0, tt4 = 0;

    filters.clear();
    //根据类型显示0->图片。  1->视频
    switch(type)
    {
    case 0:{
        //        filters.append(QString("*.jpg"));
        //        filters.append(QString("*.avi"));
        //        if(define_hirplay)
        //        {
        //            filters.append(QString("*.hir"));
        //        }
        gettimeofday(&tv_begin, NULL);
        while(!p->hp_sorts->isSortOver())
        {
            qDebug() << "isSorting...";
            delaymsec(500);
        }
        if(sdinsert)
            sortedFileList = p->hp_sorts->getSortFileList();
        else
            sortedFileList.clear();

        filters.append(QString("*.avi"));
        if(define_hirplay)
        {
            filters.append(QString("*.hir"));
        }
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setNameFilters(filters);
        dir.setSorting(QDir::Name | QDir::Reversed);
        file_list.clear();
        dirlist = getFileList();

        gettimeofday(&tv_end, NULL);
        t1 = (tv_end.tv_sec - tv_begin.tv_sec) * 1000 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
        timeReport += QString("1. 获取文件列表: %1 ms\n").arg(t1);

        gettimeofday(&tv_begin, NULL);

        //获取一级目录下的所有 avi 文件列表
        if(dirlist.count() != 0)
        {
            for(int i = 0; i < dirlist.count(); i++)
            {
                dir.cd(dirlist.at(i));

                //所有 一级 所有文件 列表
                file_list.append(dir.entryInfoList());
            }
        }

        gettimeofday(&tv_end, NULL);
        t2 = (tv_end.tv_sec - tv_begin.tv_sec) * 1000 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
        timeReport += QString("1. 拾取文件: %1 ms\n").arg(t2);
    }

        break;
    case 1:
        filters.append(QString("*.avi"));
        if(define_hirplay)
        {
            filters.append(QString("*.hir"));
        }
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setNameFilters(filters);
        dir.setSorting(QDir::Name | QDir::Reversed);
        file_list.clear();
        dirlist = getFileList();
        if(dirlist.count() != 0)
        {
            for(int i = 0; i < dirlist.count(); i++)
            {
                dir.cd(dirlist.at(i));
                file_list.append(dir.entryInfoList());
            }
        }
        for(int i = 0;i<file_list.count();i++){
            QFileInfo fileInfo = file_list.at(i);
            qDebug() << " 486 filename:" << fileInfo.filePath(); // 打印文件路径
        }
        break;
    default:
        break;
    }
    if(sd_insert)
    {
        gettimeofday(&tv_begin, NULL);
        show_current_page(current_page);     //new

        gettimeofday(&tv_end, NULL);
        //        t4 = (tv_end.tv_sec - tv_begin.tv_sec) * 1000 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
        //        timeReport += QString("1. 加载新文件: %1 ms\n").arg(t4);
        //        timeReport += QString("【总耗时】: %1 ms").arg(t1 + t2 + t3 + t4 +
        //                                                  tt1 + tt2 + tt3 + tt4);
        //        QMessageBox::information(nullptr, "性能测试结果", timeReport);

    }


    if(0 == pic_type)               //0>pic
    {
        total_pages = ((sortedFileList.count()) % 8 == 0)?((sortedFileList.count())/8):((sortedFileList.count())/8+1);
    }
    else if(1 == pic_type)          //1->video
    {
        if(define_hirplay)
        {
            total_pages = ((all_avi + all_hir)%8 ==0)?((all_avi + all_hir)/8):((all_avi + all_hir)/8+1);
        }else{
            total_pages = ((all_avi)%8 ==0)?((all_avi)/8):((all_avi)/8+1);
        }
    }else{};

    //2018.5.9
    if(file_list.size() ==0 && sortedFileList.count() == 0){
        sd_format = true;
    }else{
        sd_format = false;
    }
    if(sd_insert)
    {
        show_page_info();
    }
    update_button_status();    //2018.5.9

    //    show_current_page(current_page);          //提到前面
}

void HpPreview::setSdInfo(sdinfo_t sdinfo)  //SD卡信息相关
{
    //   ui->widget->update_sd_info(sdinfo);
}

void HpPreview::setsdinsert(bool f)     //SD卡插入相关.是否插入
{
    //   ui->widget->update_sd_insert(f);
    MainWidget* p = (MainWidget*)hp_parent;
    sdinsert = f;
    p->hp_sorts->sdReinsert(sdinsert);

    if(false == f)
    {
        p->hp_sorts->clearSortList(false);
        set_current_page = 0;
        current_page = 0;
        ui->label_sd->setStyleSheet( QStringLiteral("color: rgb(255, 0, 0);") );
        QString para;
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                ui->label_sd->setText("卡没插入");
            }
            else if(para.toInt() == 1)
            {
                ui->label_sd->setText("卡未插入");
            }
            else if(para.toInt() == 2)//english
            {
                ui->label_sd->setText("No card");
            }
            else if(para.toInt() == 3)//俄语
            {
                ui->label_sd->setText("без карты");
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                ui->label_sd->setText("Sem cartão");
            }
            else if(para.toInt() == 5)//西班牙语
            {
                ui->label_sd->setText("Sin tarjeta");
            }
        }
        if(!this->isVisible())
            return;
        sortedFileList.clear();
        update_dir_data(pic_video);//重新更新列表
        sd_format =true;
        //sd_format
    }
    else
    {
        if(!this->isVisible())
            return;
        update_dir_data(pic_video);//重新更新列表,需更新代码
    }

}

void HpPreview::update_button_status()     //更新按钮状态
{
    signal_update_lcdoff_time(false);
    if(hp_dialog->isVisible())
        hp_dialog->close();
    if(current_page == 0)
    {
        ui->last_page->setEnabled(false);
    }
    else
    {
        ui->last_page->setEnabled(true);
    }
    if(current_page == total_pages-1 || total_pages == 0)
    {
        ui->next_page->setEnabled(false);
    }
    else
    {
        ui->next_page->setEnabled(true);
    }
    ui->twice_analisys->setEnabled(!ui->listWidget->selectedItems().isEmpty());
    ui->delete_pic->setEnabled(!ui->listWidget->selectedItems().isEmpty());
}

int HpPreview::VideoForPNG(QString file,QString filename)
{
    QString cmd;
    QProcess process;
//    qDebug() << "flie name " << file << filename;

    cmd = "ffmpeg -n -i "+file+" -r 12 -vframes 1 /home/root/res/TempStoragePng/"+filename+".jpg";
    //cmd = "ffmpeg -n -i /run/media/mmcblk2p1/DCIM/" + file + " -r 23 -vframes 23 /home/root/res/TempStoragePng/" + filename + "%d.jpg";
    //通过过execute函数是阻塞 直到我们启动的外部程序结束才会往下进行 如果使用start我发现这个外部程序会被干掉
    process.execute(cmd);
    //    cmd = "cp /home/root/res/TempStoragePng/"+filename+"2.jpg" + " /run/media/mmcblk2p1/"+filename+"2.jpg";
    //    process.execute(cmd);
    process.close();

    return 0;
}

void HpPreview::show_current_page(int page)
{
    //入参表示当前处于 第几页
    text_voice_init(0,0);
    int index;
    ui->listWidget->clear();
    all_avi = 0;
    all_hir = 0;
    QFileInfoList fileret_avihir;
    QFileInfoList fileret_jpg;
    fileret_avihir.clear();
    fileret_jpg.clear();
    //遍历所有一级目录下的所有文件，找出jpg文件，剔除不需要的文件
    for(int i=0; i < file_list.count(); i++)
    {
        QFileInfo fileInfo = file_list.at(i);
        if(fileInfo.fileName().contains(".avi",Qt::CaseInsensitive))
        {
            all_avi++;
            fileret_avihir.append(file_list.at(i));
        }
        if(define_hirplay)
        {
            if(fileInfo.fileName().contains(".hir",Qt::CaseInsensitive))
            {
                all_hir++;
                fileret_avihir.append(file_list.at(i));
            }
        }
        if(fileInfo.fileName().contains(".jpg",Qt::CaseInsensitive) || fileInfo.fileName().contains(".bmp",Qt::CaseInsensitive))
        {
            fileret_jpg.append(file_list.at(i));
        }
    }
    //根据类型显示0->图片。  1->视频
    if(1 == pic_type)
    {
        if(define_hirplay)
        {
            if(all_hir == 0 && all_avi == 0)
            {
                return ;
            }
            if(all_hir != 0)
            {
                hirFileNameLists.clear();
                set_pc_image_hir_composite();
            }
        }else{
            if( all_avi == 0)
            {
                return ;
            }
        }
        for (int i = 0; i < 8; ++i)
        {
            index = i+page*8;
            if(index<fileret_avihir.size())
            {
                QFileInfo fileInfo = fileret_avihir.at(index);
                if(fileInfo.fileName().contains(".avi",Qt::CaseInsensitive))
                {
                    QString FileName;
                    FileName = fileInfo.fileName().section('.',0,0);
                    QImage imgret;

                    if( (QString::compare(FileName,avi_bad_name))==0)
                    {
                        QImage * newImage =0;
                        newImage = new QImage(":/res/res/preview_avi.png");
                        QIcon icon(QPixmap::fromImage(*newImage));
                        QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                        ui->listWidget->addItem(tmp);
                        continue;
                    }
                    QFile file("/home/root/res/TempStoragePng/"+FileName+".jpg");
//                    qDebug() << "----------!QFile(\"./res/TempStoragePng/\"+FileName+\".jpg\").exists()" << file.fileName() << file.exists();

                    if (!file.exists()) {
                        VideoForPNG(fileInfo.filePath(),FileName);
                    }
                    QImage * newImage =0;
                    //                    qDebug() << "QFile::exists(\"./res/TempStoragePng/\"+FileName+\".jpg\")" << QFile::exists("./res/TempStoragePng/"+FileName+".jpg");
                    if( QFile::exists("./res/TempStoragePng/"+FileName+".jpg") )
                    {
                        newImage = new QImage("./res/TempStoragePng/"+FileName+".jpg");
                        QPainter painter;
                        painter.begin(newImage);
                        if(define_s3X0 == 2)
                        {
                            *maskImage = maskImage->scaled(newImage->size());
                        }else if(define_s3X0 == 0){
                            *maskImage = maskImage->scaled(newImage->size());
                        }
                        painter.drawImage(0,0,*maskImage);//画播放形状
                        painter.end();
                        newImage->save("./res/TempStoragePng/"+FileName+".jpg");//保存回去
                    }
                    else
                    {
                        avi_bad_name = FileName;
                        newImage = new QImage(":/res/res/preview_avi.png");
                    }
                    imgret = *newImage;
                    QIcon icon(QPixmap::fromImage(imgret));
                    QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                    ui->listWidget->addItem(tmp);
                }else if(fileInfo.fileName().contains(".hir",Qt::CaseInsensitive))
                {
                    if(!define_hirplay)
                    {
                        continue;
                    }
                    QImage * newImage = 0;
                    QString filename_ret = fileInfo.fileName().left(fileInfo.fileName().indexOf(".hir")) + ".jpg";
                    if( QFile::exists("./res/"+filename_ret) )
                    {
                        newImage = new QImage("./res/"+filename_ret);
                        QPainter painter;
                        painter.begin(newImage);
                        if(define_s3X0 == 2)
                        {
                            *maskImage = maskImage->scaled(newImage->size());
                        }else if(define_s3X0 == 0){
                            *maskImage = maskImage->scaled(newImage->size());
                        }
                        painter.drawImage(0,0,*maskImage );
                        painter.end();
                    }else{
                        newImage = new QImage(":/res/res/preview_HIR.png");
                    }
                    QIcon icon(QPixmap::fromImage(*newImage));
                    QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                    ui->listWidget->addItem(tmp);
                }
            }
        }
    }else if( 0 == pic_type)
    {
        //将所有tf卡下之前搜索的 文件都 继续复制到这个列表中
        for(int i = sortedFileList.count() - 1; i >= 0; i--)
        {
            fileret_jpg.append(sortedFileList.at(i));
        }

        qDebug() << __LINE__ << "lzj ------------> " << fileret_jpg.count();

        pic_bad_exit =false;                     //每次重新刷新页面时，设置为false
        damaged_pic_list.clear();                //清理链表

        m_fileNameList.clear();
        int pic_voice_page =  0;
        //模式数组初始化
        pre_pic_mode_i = 0;
        memset(pre_pic_mode, 0, sizeof(pre_pic_mode));
        int maxPIcNum = 8;
        for (int i = 0; i < maxPIcNum; ++i)
        {
            index = i+page*8;
            if(index < fileret_jpg.size())
            {
                QFileInfo fileInfo = fileret_jpg.at(index);
                qDebug() << "HpPreview::show_current_page" << page << "fileNAme" << fileInfo.fileName();
                if(fileInfo.fileName().contains(".avi",Qt::CaseInsensitive))
                {
                }
                else
                {
                    if((fileInfo.fileName().contains(".jpg",Qt::CaseInsensitive)) ||
                            fileInfo.fileName().contains(".bmp",Qt::CaseInsensitive))
                    {
                        if(fileInfo.fileName().contains("GW",Qt::CaseInsensitive))//国网模式图片的读取
                        {
                            QIcon icon(fileInfo.filePath());
                            QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                            ui->listWidget->addItem(tmp);
                            m_fileNameList.append(fileInfo.filePath());
                            pic_voice_page++;
                            continue;
                        }
                        int item_current;
                        item_current = i;
                        bool pic_normal = true;
                        QString filePath = fileInfo.filePath();
                        m_fileNameList.append(fileInfo.filePath());
                        if(fileInfo.fileName().contains("GW",Qt::CaseInsensitive) ||
                                fileInfo.fileName().contains("bmp",Qt::CaseInsensitive) ||
                                fileInfo.fileName().contains("ccd",Qt::CaseInsensitive))//国网模式图片的读取
                        {
                            QElapsedTimer tim;
                            tim.start();
                            const int targetWidth = 640;
                            const int targetHeight = 480;

                            // 加载并缩放图片
                            QPixmap originalPixmap(filePath);
                            Qt::AspectRatioMode ratiomode = Qt::KeepAspectRatio;
                            QPixmap scaledPixmap = originalPixmap.scaled(targetWidth, targetHeight, ratiomode, Qt::SmoothTransformation);
                            QIcon icon(scaledPixmap);

                            QString showFileName = fileInfo.fileName();
                            qDebug() << tim.elapsed();
                            QListWidgetItem *tmp = new QListWidgetItem(icon, showFileName);
                            ui->listWidget->addItem(tmp);
                            pic_voice_page++;
                            continue;
                        }
                        //读取图片信息
                        QFile jpg_file(fileInfo.filePath());
                        if(!jpg_file.open(QIODevice::ReadOnly))
                        {
                            pic_normal = false;
                        }
                        p_jpg_data = (char *)malloc(jpg_file.size());
                        if(p_jpg_data == NULL)
                        {
                            qDebug() << "p_jpg_data == NULL";
                            pic_normal = false;
                        }
                        QDataStream in(&jpg_file);                  //读取数据流
                        if(in.readRawData(p_jpg_data,jpg_file.size())!= jpg_file.size())
                        {
                            qDebug() << "in.readRawData(p_jpg_data,jpg_file.size())!= jpg_file.size()";
                            pic_normal = false;
                        }
                        //标签数量结构体。内容
                        memcpy((char *)&tagnum,p_jpg_data+jpg_file.size()-sizeof(tagnum_t),sizeof(tagnum_t));
                        //判断标签是否正确
                        if(tagnum.nTag != TAGNUM_TAG)
                        {
                            if(jpg_file.fileName().contains("PAN") && !jpg_file.fileName().contains("-"))
                            {
                                int imageWidth = 640;
                                int imageHeight = 480;
                                //                                if(isDefineS300)
                                //                                {
                                //                                    imageWidth = 384;
                                //                                    imageHeight = 288;
                                //                                }
                                QImage blackImage(imageWidth, imageHeight, QImage::Format_ARGB32);
                                blackImage.fill(Qt::black);
                                blackImage.setAlphaChannel(blackImage.createAlphaMask());
                                QImage* newImage = new QImage(fileInfo.filePath());
                                QPainter painter(&blackImage);// 创建QPainter并传入QImage
                                painter.setCompositionMode(QPainter::CompositionMode_SourceOver);// 设置CompositionMode
                                qDebug() << "8imageHeigeh == " << newImage->height();
                                double aspectRatio =static_cast<double>(newImage->height()) / static_cast<double>(newImage->width());

                                Qt::AspectRatioMode ratiomode = Qt::KeepAspectRatio;
                                //                                if(define_640_512)
                                //                                {
                                //                                    ratiomode = Qt::KeepAspectRatioByExpanding;
                                //                                }
                                *newImage = newImage->scaled(640, 480, ratiomode );
                                int iconsHeight = imageWidth * aspectRatio;
                                painter.drawImage(0, (imageHeight - iconsHeight) / 2, *newImage);// 进行实际的绘制操作，假设你希望绘制在(0, 120)的位置
                                QPixmap pixmap(QPixmap::fromImage(blackImage));// 创建QPixmap并传入QImage
                                QIcon icon(pixmap);// 创建QIcon并传入QPixmap
                                QString showFileName = fileInfo.fileName();// 获取文件名
                                QListWidgetItem *tmp = new QListWidgetItem(icon, showFileName);// 创建QListWidgetItem并添加到QListWidget
                                ui->listWidget->addItem(tmp);
                                pic_voice_page++;
                                continue;
                            }
                            qDebug() << "tagnum.nTag != TAGNUM_TAG" << tagnum.nTag << TAGNUM_TAG;
                            pic_normal = false;
                        }
                        if(pic_normal == true)
                        {
                            //标签结构
                            memcpy((char *)taginfo, p_jpg_data + jpg_file.size() - sizeof(tagnum_t) - sizeof(taginfo_t)  *tagnum.num, sizeof(taginfo_t) * tagnum.num);
                            //语音信息结构体
                            memset((char *)&voiceinfo,0,sizeof(voiceinfo_t));
                            memset((char *)&textinfo,0,sizeof(textinfo_t));
                            pic_voice_page++;
                            //根据标签数量循环遍历
                            for(int j=0 ; j < tagnum.num;j++)
                            {
                                if(taginfo[j].nTag == VOICEINFO_TAG)  //1515 850 248
                                {
                                    text_voice_init(2,pic_voice_page);
                                    memcpy((char *)&voiceinfo,p_jpg_data+taginfo[j].offset,sizeof(voiceinfo_t));
                                }
                                else if(taginfo[j].nTag == TEXTINFO_TAG)    ////1515 850 249
                                {
                                    memcpy((char *)&textinfo,p_jpg_data+taginfo[j].offset,sizeof(textinfo_t));
                                    char text_s[textinfo.nTextLen+1];
                                    memset(text_s,'\0',textinfo.nTextLen+1);
                                    memcpy(text_s,p_jpg_data+taginfo[j].offset+sizeof(textinfo_t),textinfo.nTextLen);
                                    text = QByteArray(text_s);

                                    if(text.isEmpty()){
                                    }else{           //有文本标志，且文本不为空时。显示文本标签
                                        text_voice_init(1,pic_voice_page);
                                    }
                                }
                                else if( taginfo[j].nTag == IMAGEGRAYINFO_TAG )
                                {
                                    text_voice_init(3,pic_voice_page);
                                    //                                    int file_mode1;
                                    //                                    file_mode1 = get_pic_mode(fileInfo.fileName());
                                    //这里需要注意！！！这样写是错误的
                                    //                                    if( 1 != file_mode1 &&((4 != file_mode1) &&FID_PID_MODE))
                                    //                                    {

                                    //                                    }
                                }
                            }
                            free(p_jpg_data);
                            jpg_file.close();    //关闭图片
                            //判断该图片是否是可见光图片 mode==1
                            int file_mode;
                            file_mode = get_pic_mode(fileInfo.filePath());
                            if(file_mode == 10)
                            {
                                maxPIcNum++;
                                continue;
                            }
                            //这里需要注意！！！
                            if( 1 != file_mode && 5 != file_mode){                                 //非可见光模式
                                pre_pic_mode[pre_pic_mode_i] = i;
                                pre_pic_mode_i++;
                            }
                            QIcon icon(fileInfo.filePath());
                            QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                            ui->listWidget->addItem(tmp);
                        }else
                        {
                            //添加错误图片链表
                            damaged_pic_list<<fileInfo.filePath();
                            QIcon icon(":/res/res/error_waring.png");
                            QListWidgetItem *tmp = new QListWidgetItem(icon, fileInfo.fileName());
                            ui->listWidget->addItem(tmp);
                            pic_bad_exit = true;
                        }
                    }
                }
            }
        }
        pic_bad_exit_manage();
    }else{};
}

void HpPreview::pic_bad_exit_manage()
{
    if(pic_bad_exit == true){
        if(this->isHidden() == false)
        {
            if(0 == pic_type)
            {
                pic_dialog.time_select(2);
            }
        }
    }
}
//显示页码信息更新
void HpPreview::show_page_info()
{
    //2018.5.9
    if(sd_format == true)
    {
        current_page = 0;
        QString msg = QString("%1/%2")
                .arg(0).arg(0);
        sd_format =false;
        ui->pages_info->setText(msg);
    }else{
        if(define_hirplay)
        {
            if(((sortedFileList.count()== 0)&&(pic_type==0))  ||  (pic_type &&(all_avi == 0) && (all_hir == 0)))               //判断照片为0 或者视频为0 的时候输出0/0
            {
                current_page = 0;
                QString msg = QString("%1/%2")
                        .arg(0).arg(0);
                sd_format =false;
                ui->pages_info->setText(msg);
                return ;
            }
        }else{
            if(   ((sortedFileList.count()== 0)&&(pic_type==0))  ||  (pic_type &&(all_avi == 0)) )               //判断照片为0 或者视频为0 的时候输出0/0
            {
                current_page = 0;
                QString msg = QString("%1/%2")
                        .arg(0).arg(0);
                sd_format =false;
                ui->pages_info->setText(msg);
                return ;
            }
        }

        QString msg;
        if( current_page+1 <= total_pages && total_pages != 0 )
            msg = QString("%1/%2").arg(current_page+1).arg(total_pages);
        else
            msg = QString("%1/%2").arg(total_pages).arg(total_pages);
        ui->pages_info->setText(msg);
    }
}

void HpPreview::slot_preview_close()
{
    if(m_isVideoPlaying)
        return;
    signal_preview_close();
}

void HpPreview::on_last_page_clicked()
{
    if(m_isVideoPlaying)
        return;
    if(current_page == total_pages)
    {
        current_page--;
    }
    else
    {
        current_page--;
    }
    MainWidget *p = (MainWidget*)hp_parent;
    if(!hp_dialog->isVisible())
    {
        hp_dialog->raise();
        hp_dialog->setText(p->hpcameracap->WaitShow);
        hp_dialog->show();
    }
    update();
    update_dir_data(pic_video);
    show_page_info();
    update_button_status();

}
void HpPreview::set_pc_image_hir_composite()
{
    QDir dirsor;
    QStringList filterssor;
    QFileInfoList fileListsor;

    filterssor.clear();
    filterssor.append(QString("*.hir"));

    dirsor.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirsor.setNameFilters(filterssor);
    dirsor.setSorting(QDir::Name | QDir::Reversed);
    dirsor.cd(direct);
    fileListsor.clear();
    if (dirsor.exists()) {
        QStringList subDirs = dirsor.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        foreach (QString subDir, subDirs) {
            QDir subDirectory(dirsor.absolutePath() + "/" + subDir);
            QFileInfoList files = subDirectory.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
            fileListsor.append(files);
        }
    }

    //    for(int i = 0; i < fileListsor.size();i++)
    //    {
    //        qDebug() << "source : " << fileListsor.at(i).fileName();//能读取到所有有相同尾字符的文件
    //    }


    QDir dirtar;
    QString tardrect = "/home/root/res";
    QStringList filterstar;
    QFileInfoList fileListtar;

    filterstar.clear();
    filterstar.append(QString("*.jpg"));

    dirtar.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dirtar.setNameFilters(filterstar);
    dirtar.setSorting(QDir::Name | QDir::Reversed);
    dirtar.cd(tardrect);

    fileListtar.clear();
    fileListtar = dirtar.entryInfoList();

    //    for(int i = 0; i < fileListtar.size();i++)
    //    {
    //        qDebug() << "tar : " << fileListtar.at(i).fileName();//能读取到所有有相同尾字符的文件
    //    }


    bool flag = false;
    compositeCount = 0;
    //以下可以优化，就是乒乓球问题，每个人都要和另外一个队伍打，如何简化算法
    //后期这里会消耗大量时间
    for(int i = 0; i < fileListsor.size(); i++)
    {
        QFileInfo fileInfosor = fileListsor.at(i);
        QString sorfilename_ret = fileInfosor.fileName().left(fileInfosor.fileName().indexOf(".hir")) + ".jpg";
        for(int j = 0; j < fileListtar.size(); j++)
        {
            QFileInfo fileInfotar = fileListtar.at(j);
            if(sorfilename_ret == fileInfotar.fileName())
            {
                fileListtar.removeAt(j);
                flag = true;
                break;
            }
        }
        if(!flag)//若未找到同名文件
        {
            compositeCount++;
            QString hirFileName = fileInfosor.fileName();
            hirFileNameLists.append(hirFileName);
            QByteArray barray = fileInfosor.fileName().toUtf8();
            char *mm = barray.data();
            signal_pc_image_hir_composite(mm);//发送文件名
        }
        flag = false;//若找到则继续
    }
}

void HpPreview::slot_pc_image_hir_composite(unsigned char return_value)
{
    qDebug("HpPreview::slot_pc_image_hir_composite:%02x",return_value);
    if(return_value == RE_OK)
    {
        qDebug() << __func__ << hirFileNameLists.at(0);
        for(int i = 0; i < ui->listWidget->count(); i++)
        {
            qDebug() << __func__ << ui->listWidget->item(i)->text() << hirFileNameLists.at(0);
            QListWidgetItem *item = ui->listWidget->item(i);
            QString hirFileName = hirFileNameLists.at(0);
            if (item && (ui->listWidget->item(i)->text().contains(hirFileName.split(".").at(0)))) {

                if( QFile::exists("./res/"+hirFileName.split(".").at(0) + ".jpg") )
                {
                    QPixmap newPixmap("./res/" + hirFileName.split(".").at(0) + ".jpg");
                    QPainter painter;
                    painter.begin(&newPixmap);

                    if(define_s3X0 == 2)
                    {
                        *maskImage = maskImage->scaled(newPixmap.size());
                    }else if(define_s3X0 == 0){
                        *maskImage = maskImage->scaled(newPixmap.size());
                    }
                    painter.drawImage(0,0,*maskImage );
                    painter.end();
                    QIcon newIcon(newPixmap);
                    item->setIcon(newIcon);
                }

            }
        }
        if(hirFileNameLists.count() > 0)
        {
            hirFileNameLists.pop_front();
        }
    }
}

void HpPreview::on_next_page_clicked()
{
    if(m_isVideoPlaying)
        return;
    if(current_page == 0)
    {
        current_page++;
    }
    else
    {
        current_page++;
    }

    MainWidget *p = (MainWidget*)hp_parent;
    if(!hp_dialog->isVisible())
    {
        hp_dialog->raise();
        hp_dialog->setText(p->hpcameracap->WaitShow);
        hp_dialog->show();
    }
    update();
    update_dir_data(pic_video);
    show_page_info();
    update_button_status();
}

void HpPreview::slot_Show_TaskPic()
{
    int num_Task = 0;

    for(int i = sortedFileList.count() - 1; i >= 0; i--)
    {
        qDebug() << sortedFileList.at(i).fileName();//能读取到所有有相同尾字符的文件
        num_Task++;
        if(sortedFileList.at(i).fileName().contains(".irp",Qt::CaseInsensitive))
        {
            if(num_Task > 0)
                hp_text_input.setText(QString::number((num_Task - 1) / 8 + 1));
            break;
        }
    }
    if(num_Task <= 0)
    {
        hp_text_input.setText("");
    }
    qDebug() << "--<Task Btn>--  num_Task = " << num_Task - 1;
    qDebug() << "--<Task Btn>--  num_Task / 8 + 1 = " << QString::number((num_Task - 1) / 8 + 1);
}
//暂时没用
void HpPreview::show_pic_clicked()
{
    if(m_isVideoPlaying)
    {
        return;
    }
    pic_video = 0;
    current_page = 0;

    update_dir_data(pic_video);
    show_current_page(current_page);
    show_page_info();
    update_button_status();
}
//暂时没用
void HpPreview::show_video_clicked()
{
    if(m_isVideoPlaying)
        return;
    pic_video = 1;
    current_page = 0;

    update_dir_data(pic_video);
    show_current_page(current_page);
    show_page_info();
    update_button_status();
}
//点击二次分析时
void HpPreview::on_twice_analisys_clicked()
{
    qDebug() << "HpPreview::on_twice_analisys_clicked()" << m_isVideoPlaying;
    if(ui->listWidget->currentItem()->text().contains(".jpg",Qt::CaseInsensitive) ||
            ui->listWidget->currentItem()->text().contains(".bmp",Qt::CaseInsensitive))
    {
        file_name = m_fileNameList.at(ui->listWidget->currentRow());
//        qDebug() << "on_twice_analisys_clicked" << file_name;
        if(file_name.contains("GW_",Qt::CaseInsensitive))
        {
            signal_pic_kjg_on(m_fileNameList.at(ui->listWidget->currentRow()));
            return;
        }
        //判断是否是已经损坏的图片
        if(damaged_pic_list.contains(file_name))
        {
            qDebug()<<"Damaged picture cannot twice analisys !!!";
            return;
        }
        //判断是否是可见光。可见光下不能进行二次分析
        if(file_name.contains("PAN") && !file_name.contains("-"))
        {
            signal_pic_kjg_on(m_fileNameList.at(ui->listWidget->currentRow()));
            return;
        }
        else if(file_name.contains("ccd") || file_name.contains(".vi"))
        {
            signal_pic_kjg_on(m_fileNameList.at(ui->listWidget->currentRow()));
            return;
        }

        //判断是否是可见光。可见光下不能进行二次分析
        int file_mode;

        file_mode = get_pic_mode(file_name);
        if( 1 == file_mode){
            //进入可见光界面
            //           signal_pic_kjg_open(file_name);
            signal_pic_kjg_on(file_name);
            return;

        }

        if((5== file_mode)&&fidpid)//若时HSE模式
        {
            signal_pic_kjg_on(file_name);
            return;
        }

        MainWidget *p = (MainWidget *)hp_parent;
        p->hta->stop_twice_analysis_name(file_name,file_name);

        //QByteArray barray = file_name.toLatin1();
        QByteArray barray = file_name.toUtf8();
        char *mm = barray.data();
        if(p->hta->start_twice_analysis(file_name))                     //进入二次分析读取图片信息
            signal_core_analysis_pic_twice_start(mm);   //这个信号的槽函数是执行更改主界面状态的函数                //进入display中的二次分析。点 线 框状态
        signal_pic_twice_begin();                                                  //显示左右移动按钮
        //判断当前页和当前目录,设置 左右切换图标的状态
        int last,next;
        picture_now = ui->listWidget->currentRow();          //当前页的第几张
        picture_now_all = ui->listWidget->count();               //总共几页

        //根据当前条目判断是  非可见光数组中  的哪一张非可见光图片
        int current_mode = 0;
        for(current_mode =0 ;current_mode<pre_pic_mode_i;current_mode++){
            if(picture_now == pre_pic_mode[current_mode]){
                break;
            }
        }
        //        for(int i = 0; i < 8;i++)
        //        {
        //            qDebug() << "pre_pic_mode[i] == > " << pre_pic_mode[i];
        //        }
        //       qDebug() << "picture_now == > " << picture_now << "  ;  " << "pre_pic_mode_i == > " << pre_pic_mode_i;
        //下面这个方法比较快但有点缺憾。点击 第一张非可见光，该可见光不在第一页。图标显示可以向上翻页。翻页后还是这一张。不影响使用
        //       qDebug() << " current_mode == > " << current_mode << "  ;  " << "current_page == > " << current_page;
        if((0 ==current_mode && 0 == current_page))      //第一页，第一个图片
        {
            last = 0;
        }else{
            last = 1;
        }
        if(((pre_pic_mode_i -1) == current_mode)  && ( current_page == ( total_pages-1)))   //最后一页最后一个图片
        {
            next =0;
        }else{
            next =1;
        }

        if(first_pic_name == file_name){
            last =0;
        };
        if(last_pic_name == file_name){
            next =0;
        }
        signal_pic_twice_type(last,next);
    }
    else if(ui->listWidget->currentItem()->text().contains(".avi",Qt::CaseInsensitive))
    {
        if(!hmp2.start_play_media(getListWidgetCurrentFilePath()))
        {
            qDebug()<<"play error";
        }
        return;
        //带APP用下面的方式
        if(m_isVideoPlaying)
        {
            return;
        }
        else
        {
            m_isVideoPlaying = true;
            MainWidget *p = (MainWidget*)hp_parent;
            ui->twice_analisys->close();
            //            hmp.show();
            if(getAudioSize(ui->listWidget->currentItem()->text()) != 0x800000 && p->hpsetting.isNewBle && p->hpsetting.isNewBle && p->hpsetting.isBleOpen)
            {
                hmp.start_play_media(true, getListWidgetCurrentFilePath());
            }
            else
            {
                hmp.start_play_media(false, getListWidgetCurrentFilePath());
            }
        }
    }
    else if(ui->listWidget->currentItem()->text().contains(".hir",Qt::CaseInsensitive))
    {
        MainWidget *p = (MainWidget*)hp_parent;
        if(!hp_dialog->isVisible())
        {
            hp_dialog->raise();
            hp_dialog->setText(p->hpcameracap->WaitShow);
            hp_dialog->show();
        }
        hhp.Start_Hir_video(ui->listWidget->currentItem()->text());

    }
}
//列表选中
void HpPreview::on_listWidget_itemSelectionChanged()
{
    update_button_status();
}
//获取SD卡容量信息
void HpPreview::slot_core_get_sd_info(unsigned char return_value, sdinfo_t sdinfo)
{
    if(return_value == RE_OK)
    {
        if(true == sdinsert)
        {
            if( 0 == sdinfo.totalMB )
            {
                QString para;
                para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
                if(para !=NULL)
                {
                    if(para.toInt() == 0)
                    {
                        ui->label_sd->setText("卡错误");
                    }
                    else if(para.toInt() == 1)
                    {
                        ui->label_sd->setText("卡錯誤");
                    }
                    else if(para.toInt() == 2)//english
                    {
                        ui->label_sd->setText("Card error");
                    }
                    else if(para.toInt() == 3)//俄语
                    {
                        ui->label_sd->setText("ошибка");
                    }
                    else if(para.toInt() == 4)//匈牙利语
                    {
                        ui->label_sd->setText("Erro");
                    }
                    else if(para.toInt() == 5)//西班牙语
                    {
                        ui->label_sd->setText("Error");
                    }
                }
                //                current_page = 0;
                sd_format =true;
                show_page_info();
                ui->label_sd->setStyleSheet( QStringLiteral("color: rgb(255, 0, 0);") );
            }else
            {
                //if(sdinfo.usedMB < sdinfo.totalMB/2)
                if(sdinfo.usedMB < 1024)
                {
                    double sd_toltal_G = sdinfo.totalMB/1024+(((sdinfo.totalMB%1024)*100)/1024)*0.01;
                    QString msg = QString("%1M/\n%2G")
                            .arg(sdinfo.usedMB).arg(sd_toltal_G);
                    ui->label_sd->setStyleSheet( QStringLiteral("color: rgb(124, 166, 201);") );
                    ui->label_sd->setText(msg);
                }else
                {
                    double sd_toltal_G = sdinfo.totalMB/1024+(((sdinfo.totalMB%1024)*100)/1024)*0.01;
                    double sd_usd_G = sdinfo.usedMB/1024+(((sdinfo.usedMB%1024)*100)/1024)*0.01;
                    QString msg = QString("%1G/\n%2G")
                            .arg(sd_usd_G).arg(sd_toltal_G);
                    ui->label_sd->setStyleSheet( QStringLiteral("color: rgb(124, 166, 201);") );
                    ui->label_sd->setText(msg);
                }
            }
        }else{
            QString para;
            para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
            if(para !=NULL)
            {
                if(para.toInt() == 0)
                {
                    ui->label_sd->setText("卡没插入");
                }
                else if(para.toInt() == 1)
                {
                    ui->label_sd->setText("卡未插入");
                }
                else if(para.toInt() == 2)//english
                {
                    ui->label_sd->setText("No card");
                }
                else if(para.toInt() == 3)//俄语
                {
                    ui->label_sd->setText("без карты");
                }
                else if(para.toInt() == 4)//匈牙利语
                {
                    ui->label_sd->setText("Sem cartão");
                }
                else if(para.toInt() == 5)//西班牙语
                {
                    ui->label_sd->setText("Sin tarjeta");
                }
            }
            sd_format =true;
            show_page_info();
            ui->label_sd->setStyleSheet( QStringLiteral("color: rgb(255, 0, 0);") );
        }
        //      ui->widget->update_sd_info(sdinfo);
    }
    else
    {
        ;
    }
}
//删除图片
void HpPreview::on_delete_pic_clicked()
{
    if(m_isVideoPlaying)
    {
        return;
    }
    QString cmd;

    MainWidget* p = (MainWidget*)hp_parent;
    QString delFileName = ui->listWidget->currentItem()->text();
    QString delFilePath = "/run/media/mmcblk2p1/";
    
    // 查找/run/media/mmcblk2p1/内哪个文件夹内的图片要删
    QDir dcimDir("/run/media/mmcblk2p1/");
    if (dcimDir.exists()) {
        QStringList subDirs = dcimDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        foreach (QString subDir, subDirs) {
            qDebug()<<"subDir : "<<subDir;
            QDir subDirectory(dcimDir.absolutePath() + "/" + subDir);
            QStringList files = subDirectory.entryList(QDir::Files);
            foreach (QString file, files) {
                if (file == delFileName) {
                    delFilePath = subDirectory.absolutePath() + "/" + file;
                    MYLOG<<delFilePath;
                    break;
                }
            }
//            if (!delFilePath.isEmpty()) {
//                MYLOG<<delFilePath;
//                break;
//            }
        }
    }
    
    if(0 == pic_type)
    {

        //删除图片
        qDebug() << "ui->listWidget->currentRow()" << ui->listWidget->currentRow() << "m_fileNameList" << m_fileNameList;
        p->hp_sorts->removeFile(m_fileNameList.at(ui->listWidget->currentRow()));
        cmd = "rm -f " + m_fileNameList.at(ui->listWidget->currentRow());
    }
    else if(1 == pic_type)
    {
        //删除视频
        cmd = "rm -f " + delFilePath;

    }

    if(ui->listWidget->count() == 1)
    {
        total_pages = total_pages - 1;
    }
    qDebug() << cmd;
    //QByteArray ba=cmd.toLatin1();
    QByteArray ba=cmd.toUtf8();

    system(ba);
    system("sync");
    QString cmd2;
    cmd2 = "rm -f ./res/TempStoragePng/" + ui->listWidget->currentItem()->text().split(".").at(0) + ".jpg";

    qDebug() << cmd2;
    QByteArray ba2=cmd2.toUtf8();
    system(ba2);
    system("sync");

    if(current_page > total_pages - 1)
        current_page = total_pages - 1;

    if(current_page <0)
        current_page = 0;

    //2018.5.9
    if(current_page < 0)
    {
        sd_format = true;
        current_page = 0;
    }else{
        sd_format = false;
    }

    delaymsec(100);
    update_dir_data(pic_video);
    show_page_info();
    update_button_status();
}

void HpPreview::slot_stop_video_analysis()
{
    ui->twice_analisys->setEnabled(true);
    ui->twice_analisys->show();
    m_isVideoPlaying = false;
}

void HpPreview::slot_sd_formatting()
{
    sd_format = true;
}

void HpPreview::text_voice_init(int type, int num)
{
    if( 0== type){
        ui->text_1->close();
        ui->text_2->close();
        ui->text_3->close();
        ui->text_4->close();
        ui->text_5->close();
        ui->text_6->close();
        ui->text_7->close();
        ui->text_8->close();

        ui->voice_1->close();
        ui->voice_2->close();
        ui->voice_3->close();
        ui->voice_4->close();
        ui->voice_5->close();
        ui->voice_6->close();
        ui->voice_7->close();
        ui->voice_8->close();

        ui->sr_1->close();
        ui->sr_2->close();
        ui->sr_3->close();
        ui->sr_4->close();
        ui->sr_5->close();
        ui->sr_6->close();
        ui->sr_7->close();
        ui->sr_8->close();
    }else if(1 == type){            //text
        switch(num)
        {
        case 1:
            ui->text_1->show();
            break;
        case 2:
            ui->text_2->show();
            break;
        case 3:
            ui->text_3->show();
            break;
        case 4:
            ui->text_4->show();
            break;
        case 5:
            ui->text_5->show();
            break;
        case 6:
            ui->text_6->show();
            break;
        case 7:
            ui->text_7->show();
            break;
        case 8:
            ui->text_8->show();
            break;
deflaut:
            break;
        }
    }else if(2 == type){            //voice
        switch(num)
        {
        case 1:
            ui->voice_1->show();
            break;
        case 2:
            ui->voice_2->show();
            break;
        case 3:
            ui->voice_3->show();
            break;
        case 4:
            ui->voice_4->show();
            break;
        case 5:
            ui->voice_5->show();
            break;
        case 6:
            ui->voice_6->show();
            break;
        case 7:
            ui->voice_7->show();
            break;
        case 8:
            ui->voice_8->show();
            break;
        default:
            break;
        }
    }else if(3 == type){//超分辨率照片
        switch(num)
        {
        case 1:
            ui->sr_1->show();
            break;
        case 2:
            ui->sr_2->show();
            break;
        case 3:
            ui->sr_3->show();
            break;
        case 4:
            ui->sr_4->show();
            break;
        case 5:
            ui->sr_5->show();
            break;
        case 6:
            ui->sr_6->show();
            break;
        case 7:
            ui->sr_7->show();
            break;
        case 8:
            ui->sr_8->show();
            break;
        default:
            break;
        }
    }
}
//图片 视频列表切换
void HpPreview::on_list_type_released()
{
    if(m_isVideoPlaying)
        return;
    //获取当前显示状态
    if(0 == pic_type)                           //0此时是图片，点击后切换为视频
    {
        pic_type = 1;
        if(isFirstVideo)
        {
            isFirstVideo = false;
            signal_set_main_analog_audio();
        }
        //        ui->list_type->setText("video");
        ui->list_type->setStyleSheet("QToolButton {border-image:url(:/res/res/mode_button_n.png);color:#7CA6C9;background:transparent;\
                                     border-image: url(:/res/res/preview_video.png);}\
QToolButton:pressed{\
        border-image:url(:/res/res/mode_button_s.png);\
    }");

    picture_current = current_page;     //获取此时图片在第几页
    current_page =  video_current;       //设置视频在上一个状态的页数

    hp_text_input.setbtnTaskVisble(false);
}
else if(1 == pic_type)                  //1此时是视频， 点击后切换为图片
{
    pic_type = 0;
    //        ui->list_type->setText("picture");
    ui->list_type->setStyleSheet("QToolButton {border-image:url(:/res/res/mode_button_n.png);color:#7CA6C9;background:transparent;\
                                 border-image: url(:/res/res/preview_picture.png);}\
QToolButton:pressed{\
    border-image:url(:/res/res/mode_button_s.png);\
}");
video_current = current_page;     //获取此时视频在第几页
current_page =  picture_current;       //设置图片在上一个状态的页数

if(Taskmode)
{
    hp_text_input.setbtnTaskVisble(true);
}
}else{};
//pic_video = 0;        //不知道有什么作用

update_dir_data(pic_video);
}

void HpPreview::slot_twice_lastpage()           //上一张。
{
    picture_now = ui->listWidget->currentRow();                                                              //获取当前是第几个条目
    file_name_close = ui->listWidget->currentItem()->text();                                             //传递当前需要关闭保存的 二次分析图片名字
    //根据当前条目判断是  非可见光数组中  的哪一张非可见光图片

    int current_mode = 0;
    for(current_mode =0 ;current_mode<pre_pic_mode_i;current_mode++)
    {
        if(picture_now == pre_pic_mode[current_mode])
        {
            break;
        }
    }
    int current_page_old = current_page;            //记录当前状态。页‘条目
    int picture_now_old = picture_now;
    int  kjg_no_exist = 0;                                                                                  //0--->初始状态。1--->非可见光存在。 -1--->非可见光不存在

    if(current_mode >0)
    {                                                                                 //当前图片不是该页 第一张非可见光图片
        picture_now = pre_pic_mode[current_mode -1];                                 //设置当前条目为  上一张非可见光图片
        current_mode--;
    }else
    {                                                                                                           //当前图片是 该页第一张图片

        //循环判断该页是不是第一页。如果是第一页不进行处理。
        //如果不是第一页。判断该页前面的页是否有非可见光
        if( first_pic_name != file_name_close)                                                                          //根据文件名字。判断是不是第一张 非可见光图片
        {
            for( current_page; current_page>0 ;current_page)
            {
                current_page--;
                update_dir_data(pic_video);
                //判断该界面有没有非可见光。如果有跳出该循环。并加载该界面第一张图片
                if( 0 != pre_pic_mode_i)        //有非可见光模式
                {
                    picture_now =pre_pic_mode[pre_pic_mode_i-1];                                            ////设置当前条目为  翻页后的最后一张非可见光图片
                    current_mode = pre_pic_mode_i-1;
                    kjg_no_exist =1;
                    break;
                }else{                                   //没有非可见光
                    kjg_no_exist =-1;
                }
            }
        }else
        {
            kjg_no_exist =2;
        }

    }
    if(-1 == kjg_no_exist)
    {
        //恢复到上一个状态
        current_page = current_page_old;
        update_dir_data(pic_video);
        picture_now = picture_now_old;
        first_pic_name = file_name_close;                                  //记录当前图片的名字.当前图片为第一张非可见光图片
    }
    ui->listWidget->setCurrentRow(picture_now);                                                //设置第几个条目为当前条目

    MainWidget *p = (MainWidget *)hp_parent;                                                  //加载需要打开的图片
    file_name = m_fileNameList.at(ui->listWidget->currentRow());
    p->hta->stop_twice_analysis_name(file_name_close,file_name);
    //很有可能二次分析时，底层自己关闭了线条哪些显示
    signal_core_analysis_pic_twice_stop_cut( );                                                     //停止二次分析
    /*
             QByteArray barray = file_name.toLatin1();
             char *mm = barray.data();
              if(p->hta->start_twice_analysis(file_name))
              signal_core_analysis_pic_twice_start(mm);
*/
    //根据所选图片进行  处理图标状态
    int last,next;
    picture_now_all = ui->listWidget->count();
    if((0 ==current_mode && 0 == current_page))      //第一页，第一个图片
    {
        last = 0;
    }else{
        last = 1;
    }
    if(((pre_pic_mode_i -1) == current_mode)  && ( current_page == ( total_pages-1)))   //最后一页最后一个图片
    {
        next =0;
    }else{
        next =1;
    }
    if((-1 == kjg_no_exist) || (2 == kjg_no_exist)){
        last = 0;
    }
    signal_pic_twice_type(last,next);

}

void HpPreview::slot_twice_nextpage()           //下一页
{
    picture_now = ui->listWidget->currentRow();                             //获取当前第几个条目
    picture_now_all = ui->listWidget->count();                             //获取当前界面共几个条目

    //根据当前条目判断是  非可见光数组中  的哪一张非可见光图片
    int current_mode = 0;

    for(current_mode =0 ;current_mode<pre_pic_mode_i;current_mode++){
        if(picture_now == pre_pic_mode[current_mode]){
            break;
        }
    }

    file_name_close = m_fileNameList.at(picture_now);               //获取当前图片（需要关闭的图片）的名字

    int current_page_old = current_page;            //记录当前状态。页‘条目
    int picture_now_old = picture_now;
    int  kjg_no_exist = 0;


    if( current_mode < pre_pic_mode_i-1)                    //当前张不是最后一张。则选择下一张
    {
        picture_now = pre_pic_mode[current_mode + 1];
        current_mode++;
    }else{                                                                      //当前张是该界面的最后一张。
        if(last_pic_name != file_name_close)
        {
            //循环判断该页是不是最后一页。如果是最后一页不进行处理
            for( current_page; current_page< ( total_pages-1);current_page)
            {
                current_page++;
                //更新预览图标和预览界面。 进入下一个界面
                update_dir_data(pic_video);
                //判断该界面有没有非可见光。如果有跳出该循环。并加载该界面第一张图片
                if( 0 != pre_pic_mode_i)        //有非可见光模式
                {
                    picture_now = pre_pic_mode[0];
                    current_mode = 0;
                    kjg_no_exist =1;
                    break;
                }else{
                    kjg_no_exist = -1;
                }
            }
        }else
        {
            kjg_no_exist =2;
        }
    }

    if(-1 == kjg_no_exist){
        //恢复到上一个状态
        current_page = current_page_old;
        update_dir_data(pic_video);
        picture_now = picture_now_old;
        last_pic_name = file_name_close;
    }
    ui->listWidget->setCurrentRow(picture_now);                                                //设置第几个条目为当前新条目

    //关闭图片.停止二次分析
    signal_core_analysis_pic_twice_stop_cut( );

    MainWidget *p = (MainWidget *)hp_parent;

    //图片切换是通过发送信号
    //加载图片
    file_name = m_fileNameList.at(ui->listWidget->currentRow());
    p->hta->stop_twice_analysis_name(file_name_close,file_name);

    int last,next;
    if((0 ==current_mode && 0 == current_page))      //第一页，第一个图片
    {
        last = 0;
    }else{
        last = 1;
    }
    if(((pre_pic_mode_i -1) == current_mode)  && ( current_page == ( total_pages-1)))   //最后一页最后一个图片
    {
        next =0;
    }else{
        next =1;
    }
    if((-1 == kjg_no_exist) || (2 == kjg_no_exist)){
        next = 0;
    }
    signal_pic_twice_type(last,next);
}

void HpPreview::slot_twice_pic_start()
{
    MainWidget *p = (MainWidget *)hp_parent;
    //QByteArray barray = file_name.toLatin1();
    QByteArray barray = file_name.toUtf8();
    char *mm = barray.data();
    if(p->hta->start_twice_analysis(file_name))
        signal_core_analysis_pic_twice_start(mm);
    qDebug() << "HpPreview::slot_twice_pic_start() -- > " << file_name;
}

void HpPreview::to_set_twice_text_show_or_not()
{
    signal_twice_text_show_or_not(pic_video);   //发送当前打开的是图片还是视频 ，以及打开的图片的文字
}
//获取当前图片mode 。1->可见光
int HpPreview::get_pic_mode(QString file_name)
{
    qDebug() << file_name << __func__ << __LINE__;
    int jpg_mode = 0;
    QFile jpg_file_in(file_name);
    char *p_jpg_data;

    if(!jpg_file_in.open(QIODevice::ReadOnly))
        return 1;

    p_jpg_data = (char *)malloc(jpg_file_in.size());
    if(p_jpg_data == NULL)
        return 1;

    QDataStream in(&jpg_file_in);
    if(in.readRawData(p_jpg_data,jpg_file_in.size())!= jpg_file_in.size())
        return 1;

    int filesize = jpg_file_in.size();

    tagnum_t tag_num_2;
    memcpy((char *)&tag_num_2,p_jpg_data+filesize-sizeof(tagnum_t),sizeof(tagnum_t));
    if(tag_num_2.nTag != TAGNUM_TAG)
        return 1;

    taginfo_t tag_info[8];
    memcpy((char *)tag_info,p_jpg_data+filesize-sizeof(tagnum_t)-sizeof(taginfo_t)*tag_num_2.num,sizeof(taginfo_t)*tag_num_2.num);

    image_head_t head;
    memset((char *)&head,0,sizeof(image_head_t));
    //    qDebug() << " get_pic_mode " << file_name << "tag num" << tag_num_2.num;
    for(int i=0;i<tag_num_2.num;i++)
    {
        //         qDebug() << "nTag" << tag_info[i].nTag << "HANDLEINFO_TAG" << HANDLEINFO_TAG;
        if(tag_info[i].nTag == HANDLEINFO_TAG)
        {
            return 10;
        }
        if(tag_info[i].nTag == FILEINFO_TAG)
        {
            int nDesLen = 0;//数据长度
            memcpy((char *)&nDesLen, p_jpg_data + tag_info[i].offset + 4, 4);
            int nLessLen = nDesLen;//拷贝内容长度
            //             qDebug() << "’ndesLen" << nDesLen << sizeof(file_info_t);
            if(nDesLen > sizeof(file_info_t))
                nLessLen = sizeof(file_info_t);
            memcpy((char *)&head, p_jpg_data + tag_info[i].offset, nLessLen);

            int nDesLen2 =  0;
            memcpy((char *)&nDesLen2, p_jpg_data + tag_info[i].offset + nDesLen + 4, 4);
            int nLessLen2 = nDesLen2;//拷贝内容长度
            if(nDesLen2 > sizeof(product_info_t))
                nLessLen2 = sizeof(product_info_t);
            //             qDebug() << "’nLessLen2" << nLessLen2 << head.file.nDesLen << sizeof(product_info_t);
            memcpy((char *)&head + sizeof(file_info_t), p_jpg_data + tag_info[i].offset + nDesLen, nLessLen2);

            int nDesLen3 = 0;
            memcpy((char *)&nDesLen3, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + 4,4);
            int nLessLen3 = nDesLen3;//拷贝内容长度
            if(nDesLen3 > sizeof(color_info_t))
                nLessLen3 = sizeof(color_info_t);
            //             qDebug() << "’nLessLen3" << nLessLen3 << head.product.nDesLen << sizeof(color_info_t);
            memcpy((char *)&head + sizeof(file_info_t) + sizeof(product_info_t),
                   p_jpg_data + tag_info[i].offset + nLessLen2 + nDesLen, nLessLen3);

            int nDesLen4 = 0;
            memcpy((char *)&nDesLen4, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + 4,4);
            int nLessLen4 = nDesLen4;//拷贝内容长度
            //             qDebug() << "’nLessLen3" << nLessLen4 << head.color.nDesLen << sizeof(alg_info_t);
            if(nDesLen4 > sizeof(alg_info_t))
                nLessLen4 = sizeof(alg_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(color_info_t),
                   p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3, nLessLen4);


            int nDesLen5 = 0;
            memcpy((char *)&nDesLen5, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + 4,4);
            int nLessLen5 = nDesLen5;//拷贝内容长度
            //             qDebug() << "’nLessLen3" << nLessLen5 << head.alg.nDesLen << sizeof(temper_info_t);
            if(nDesLen5 > sizeof(temper_info_t))
                nLessLen5 = sizeof(temper_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(alg_info_t) + sizeof(color_info_t),
                   p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4, nLessLen5);

            jpg_mode = head.alg.nVideoOutState;
        }
    }
    free(p_jpg_data);
    jpg_file_in.close();
    qDebug() << "jpgmode" << jpg_mode;
    return jpg_mode;
}

int HpPreview::getAudioSize(const QString fileName)
{
    QString filePath = "/run/media/mmcblk2p1/DCIM/" + fileName;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return 0;
    }

    // 设置偏移量到 264 字节处
    qint64 offset = 264;
    if (!file.seek(offset)) {
        qDebug() << "Failed to seek to offset" << offset;
        file.close();
        return 0;
    }

    QDataStream in(&file);
    in.setByteOrder(QDataStream::BigEndian);

    int value;
    in >> value;

    if (in.status() != QDataStream::Ok) {
        qDebug() << "Failed to read integer from file";
        file.close();
        return 1;
    }

    qDebug() << "Read value:" << value;
    qDebug("0x%x", value);

    file.close();

    return value;
}
//获取当前列表选中项路径
QString HpPreview::getListWidgetCurrentFilePath()
{
    QString playVideoFilePath;//将播放的文件路径
    for(int i=0; i < file_list.count(); i++)
    {
        QFileInfo fileInfo = file_list.at(i);
        if(fileInfo.fileName() == ui->listWidget->currentItem()->text()){
            playVideoFilePath = fileInfo.filePath();
        }
    }
    return playVideoFilePath;
}
