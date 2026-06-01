#include "hp_download.h"
#include "ui_hp_download.h"

hp_download::hp_download(QWidget *parent)  :
    QWidget(parent),
    ui(new Ui::hp_DownLoad)
{
    ui->setupUi(this);
    fatherorchild = true;
    isInchilddir = false;
    isInfatherfile = false;
    sd_insert = false;
    go_up = false;
    IP = "";
    Account = "";
    Password = "";

    hp_autoupload_dialog = new Hp_Autoupload_Dialog(this);
    hp_autoupload_dialog->upload_break();
    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->isdownload_dialog = true;
    hp_autoupload_dialog->close();

    filelist.clear();

    dialog_timer = new QTimer();
    dialog_timer->setInterval(2000);

    dialog_wait_timer = new QTimer();
    dialog_wait_timer->setInterval(15000);

    QString para;
    para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
    if(para !=NULL)
    {
        if(para.toInt() == 0)
        {
            fonload = "加载中...";
            ffailload = "加载失败，请检查网络连接";
            ffaildownload = "下载失败";
            fokdownload = "下载成功";
            fnoSD = "SD卡没有插入";
            fselectupload = "请选择上传的类型";
            ftask = "台账";
            fnormal = "普通";
        }
        else if(para.toInt() == 1)
        {
            fonload = "加載中...";
            ffailload = "加載失敗，請檢查網絡連接";
            ffaildownload = "下載失敗";
            fokdownload = "下載成功";
            fnoSD = "SD卡沒有插入";
            fselectupload = "請選擇上傳的類型";
            ftask = "台賬";
            fnormal = "普通";
        }
        else if(para.toInt() == 2)//english
        {
            fonload = "Loading...";
            ffailload = "Loading failed,check network connection";
            ffaildownload = "Download failed";
            fokdownload = "Download successful";
            fnoSD = "SD not insert";
            fselectupload = "Please select the type of upload";
            ftask = "Ledger";
            fnormal = "ordinary";
        }
        else if(para.toInt() == 3)//俄语
        {
            fonload = "загрузка...";
            ffailload = "Ошибка загрузки, проверка сети";
            ffaildownload = "Ошибка загрузки";
            fokdownload = "Загрузка завершена";
            fnoSD = "нет карты SD";
            fselectupload = "Выберите тип загрузки";
            ftask = "Счета";
            fnormal = "Обычные";
        }
        else if(para.toInt() == 4)//匈牙利语
        {
            fonload = "Carregamento...";
            ffailload = "O carregamento falhou, verifique a rede";
            ffaildownload = "A transferência falhou";
            fokdownload = "A transferência foi bem sucedida";
            fnoSD = "nincs SD";
            fselectupload = "Válassza ki a feltöltés típusát";
            ftask = "Ledger";
            fnormal = "rendes";
        }
        else if(para.toInt() == 5)//西班牙语
        {
            fonload = "Cargado...";
            ffailload = "Fallo de carga, compruebe la red";
            ffaildownload = "Falló la descarga";
            fokdownload = "Descarga exitosa";
            fnoSD = "Isertar SD";
            fselectupload = "Por favor, elija el tipo de carga";
            ftask = "Cuenta";
            fnormal = "Ordinario";
        }
    }

    ui->listWidget_child->verticalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;width:35px;padding-top:0px;padding-bottom:0px;}");
    ui->listWidget_father->verticalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;width:35px;padding-top:0px;padding-bottom:0px;}");
    ui->listWidget_child->horizontalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;height:35px;padding-left:0px;padding-right:0px;}");
    ui->listWidget_father->horizontalScrollBar()->setStyleSheet("QScrollBar{background:#7CA6C9;height:35px;padding-left:0px;padding-right:0px;}");

    connect(dialog_timer,SIGNAL(timeout()),this,SLOT(slot_dialog_timer_timeout()));
    connect(dialog_wait_timer,SIGNAL(timeout()),this,SLOT(slot_dialog_wait_timer_timeout()));
}

hp_download::~hp_download()
{
    delete ui;
}


void hp_download::hp_setDefine_S3x0(bool isDefine)
{
    if(isDefine)
    {
        QFont font12;
        font12.setPointSize(12);

        this->resize(480,272);
        ui->frame->setGeometry(0, 0, 480, 272);
        ui->toolButton_back->setGeometry(3,10,90,24);
        ui->label->setGeometry(100,10,360,24);
        ui->label_2->setGeometry(5, 55, 120, 18);
        ui->label_3->setGeometry(125, 55, 275, 18);
        ui->listWidget_father->setGeometry(5, 75, 120, 195);
        ui->listWidget_child->setGeometry(130, 75, 275, 195);
        ui->godown->setGeometry(415, 75, 55, 45);
        ui->goup->setGeometry(415, 125, 55, 45);
        ui->wifi_Flush->setGeometry(415, 175, 55, 45);
        ui->get_file->setGeometry(415, 225, 55, 45);
        ui->label->setFont(font12);
        ui->label_2->setFont(font12);
        ui->label_3->setFont(font12);
        ui->godown->setFont(font12);
        ui->goup->setFont(font12);
        ui->wifi_Flush->setFont(font12);
        ui->get_file->setFont(font12);
    }
}

void hp_download::changeEvent(QEvent *e)
{
    QString para;
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        para = hpxmlreader.readXml("sys.xml","LANGUAGEPARA","id");
        if(para !=NULL)
        {
            if(para.toInt() == 0)
            {
                fonload = "加载中...";
                ffailload = "加载失败，请检查网络连接";
                ffaildownload = "下载失败";
                fokdownload = "下载成功";
                fnoSD = "SD卡没有插入";
                fselectupload = "请选择上传的类型";
                ftask = "台账";
                fnormal = "普通";
            }
            else if(para.toInt() == 1)
            {
                fonload = "加載中...";
                ffailload = "加載失敗，請檢查網絡連接";
                ffaildownload = "下載失敗";
                fokdownload = "下載成功";
                fnoSD = "SD卡沒有插入";
                fselectupload = "請選擇上傳的類型";
                ftask = "台賬";
                fnormal = "普通";
            }
            else if(para.toInt() == 2)//english
            {
                fonload = "Loading...";
                ffailload = "Loading failed,check network connection";
                ffaildownload = "Download failed";
                fokdownload = "Download successful";
                fnoSD = "SD not insert";
                fselectupload = "Please select the type of upload";
                ftask = "Ledger";
                fnormal = "ordinary";
            }
            else if(para.toInt() == 3)//俄语
            {
                fonload = "загрузка...";
                ffailload = "Ошибка загрузки, проверка сети";
                ffaildownload = "Ошибка загрузки";
                fokdownload = "Загрузка завершена";
                fnoSD = "нет карты SD";
                fselectupload = "Выберите тип загрузки";
                ftask = "Счета";
                fnormal = "Обычные";
            }
            else if(para.toInt() == 4)//匈牙利语
            {
                fonload = "Carregamento...";
                ffailload = "O carregamento falhou, verifique a rede";
                ffaildownload = "A transferência falhou";
                fokdownload = "A transferência foi bem sucedida";
                fnoSD = "nincs SD";
                fselectupload = "Válassza ki a feltöltés típusát";
                ftask = "Ledger";
                fnormal = "rendes";
            }
            else if(para.toInt() == 5)//西班牙语
            {
                fonload = "Cargado...";
                ffailload = "Fallo de carga, compruebe la red";
                ffaildownload = "Falló la descarga";
                fokdownload = "Descarga exitosa";
                fnoSD = "Isertar SD";
                fselectupload = "Por favor, elija el tipo de carga";
                ftask = "Cuenta";
                fnormal = "Ordinario";
            }
        }
        break;
    default:
        break;
    }
}
void hp_download::slot_dialog_timer_timeout()
{
    hp_autoupload_dialog->setFrame3Text("加载中...");
    hp_autoupload_dialog->down_load(2);
    hp_autoupload_dialog->show();
    dialog_timer->stop();
    dialog_wait_timer->start();
}
void hp_download::slot_dialog_wait_timer_timeout()
{
    hp_autoupload_dialog->setFrame3Text(ffailload);
    hp_autoupload_dialog->down_load(2);
    hp_autoupload_dialog->show();
    dialog_wait_timer->stop();
}
QString hp_download::GetFilename()
{
    QString name = "/";
//    qDebug() << "File  name====================";
    for(int i = 0;i < filelist.size();i++)
    {
//        qDebug() << " filelist.at(i) == > " << i << " ; " << filelist.at(i);
        name = name + filelist.at(i) + "/";
    }
//    qDebug() << "filename == > " << name;
//    qDebug() << "File  name====================";
    return name;
}
void hp_download::Start_download()
{
    if(ui->listWidget_child->count() == 0)
    {
        if(ui->listWidget_father->count() == 0)
        {
            on_wifi_Flush_clicked();
            return;
        }else{
            if(ui->listWidget_father->currentItem()->backgroundColor() != QColor(121,139,163,63))
            {
                return;
            }else{
                if(filelist.size() != 0)
                    filelist.removeLast();
            }
        }
    }else{
        if(filelist.size() != 0)
            filelist.removeLast();
        if(filelist.size() != 0)
            filelist.removeLast();
    }


    fatherorchild = true;
    hp_autoupload_dialog->down_load(1);//为什么这里明明有数据要加载了，刚点进来还是能点击获取呢？
    hp_autoupload_dialog->show();
    dialog_timer->start();

    qDebug() << " START filename -- > " << GetFilename();

    download_shearch(GetFilename(),fatherorchild);
}
void hp_download::download_shearch(QString GetWho,bool fatherOrchild)
{
    if(fatherOrchild)
    {
//        qDebug() << "IP : " << IP;
//        qDebug() << "Account : " << Account;
//        qDebug() << "Password : " << Password;
        qDebug() << "Get Filename : " << GetWho << " ; Get Dir -d";
    }
    else{
//        qDebug() << "IP : " << IP;
//        qDebug() << "Account : " << Account;
//        qDebug() << "Password : " << Password;
        qDebug() << "Get Filename : " << GetWho << " ; Get file -f";
    }
//    qDebug() << "fatherOrchild == > " << fatherOrchild;
    ftp_para para;
    strcpy(para.HostIP,IP.toLocal8Bit().data());
    strcpy(para.UserName,Account.toLocal8Bit().data());
    strcpy(para.Password,Password.toLocal8Bit().data());
    para.cmd_para[0] = '-';
    if(fatherOrchild)//获取目录,不知为何，不能在里面qdebug
    {
        para.cmd_para[1] = 'd';
    }else{
        para.cmd_para[1] = 'f';
    }
    para.cmd_para[3] = '\0';
    strcpy(para.FileName,GetWho.toLocal8Bit().data());
    signal_pc_sys_set_filequery(para);
}
void hp_download::slot_pc_sys_set_filequery(unsigned char return_value,QString name,char *data,int returnlen)
{
    qDebug("slot_pc_sys_set_filequery:return_value:0x%02x  %d ",return_value,returnlen);

    if(dialog_timer->isActive())
    {
        dialog_timer->stop();
    }
    if(dialog_wait_timer->isActive())
    {
        dialog_wait_timer->stop();
    }
    if(hp_autoupload_dialog->isVisible())
    {
        hp_autoupload_dialog->close();
    }
//    qDebug() << "printf ==== 1";
//    qDebug("slot_pc_sys_set_filequery address = %x",data);
//    for(int i = 0;i < returnlen;i++)
//    {
//        printf("%c",data[i]);
//    }
//    qDebug() << "printf ==== 2";
//    QString name = QString::fromUtf8(data);

//    if(name.isEmpty() || name == "")
//    {
//        qDebug() << "--fromUtf8 ERROR--";
//        return;
//    }
    //if(return_value == RE_OK)
    //{
    qDebug() << isInfatherfile << " ; " << isInchilddir << " ; " << fatherorchild;
    int returnlen_ret = 0;
    if(isInfatherfile)//处于获取主文件状态
    {
        if(return_value == RE_OK)
        {
            QStringList strs = name.split("\n");
            foreach(QString s,strs)
            {
                if(s.contains("\\x00\\x00"))
                {
                    continue;
                }
                qDebug() << "father file == > " << s << " ; returnlen_ret = " << returnlen_ret;
                if(s != "")//这里不能多级判断，不知道为啥
                {
                    if(ui->listWidget_father->findItems(s,Qt::MatchExactly).count() == 0)
                    {
                        returnlen_ret += s.toLocal8Bit().length() + 1;//因为最后一位为'\r'所以要+1,需要考虑\n，是否+2
                        if(returnlen_ret > returnlen)
                        {
                            break;
                        }

                        ui->listWidget_father->addItem(s);
                    }
                }
            }
        }
        if(ui->listWidget_father->count() > 0)
        {
//            ui->listWidget_father->setCurrentRow(0);
            QString ret = ui->listWidget_father->currentItem()->text();
            if(ret[ret.length() - 1] == '\r')
            {
                ret.chop(1);
            }
            filelist.append(ret);
        }
        ui->label->setText(GetFilename());
        isInfatherfile = false;//处于获取子目录状态
        if(ui->listWidget_father->count() != 0)
        {
            if(ui->listWidget_father->currentItem()->backgroundColor() == QColor(121,139,163,63))
            {
                fatherorchild = false;//获取子文件
                hp_autoupload_dialog->down_load(1);
                hp_autoupload_dialog->show();
                dialog_timer->start();
                download_shearch(GetFilename(),fatherorchild);
            }
        }
    }
    else if(isInchilddir)//处于获取子目录状态
    {
        if(return_value == RE_OK)
        {
            QStringList strs = name.split("\n");
            foreach(QString s,strs)
            {
                if(s.contains("\\x00\\x00"))
                {
                    continue;
                }
                qDebug() << "Child Dir == > " << s << " ; returnlen_ret = " << returnlen_ret;
                if(s != "")//这里不能多级判断，不知道为啥
                {
                    if(ui->listWidget_child->findItems(s,Qt::MatchExactly).count() == 0)
                    {
                        returnlen_ret += s.toLocal8Bit().length() + 1;//因为最后一位为'\r'所以要+1
                        if(returnlen_ret > returnlen)
                        {
                            break;
                        }
                        if(s.contains("."))
                        {
                            continue;
                        }
                        if(s.contains(".."))
                        {
                            continue;
                        }
                        ui->listWidget_child->addItem(s);
                    }
                    QList<QListWidgetItem*> listItem = ui->listWidget_child->findItems(s,Qt::MatchExactly);
                    if(listItem.count() > 0)
                    {
                        listItem.at(0)->setBackgroundColor(QColor(121,139,163,63));
                    }
                }
            }
        }

        if(ui->listWidget_child->count() > 0)
        {
            ui->listWidget_child->setCurrentRow(0);
            QString ret = ui->listWidget_child->currentItem()->text();
            if(ret[ret.length() - 1] == '\r')
            {
                ret.chop(1);
            }
            filelist.append(ret);
        }
        ui->label->setText(GetFilename());
        isInchilddir = false;//处于获取子目录状态
    }
    else if(fatherorchild)//处于获取主目录状态
    {
        if(ui->listWidget_father->count() != 0)
        {
            ui->listWidget_father->clear();
        }
        if(ui->listWidget_child->count() != 0)
        {
            ui->listWidget_child->clear();
        }
        if(return_value == RE_OK)
        {
            QStringList strs = name.split("\n");
            foreach(QString s,strs)
            {
                if(s.contains("\""))
                {
                    continue;
                }
                if(s.contains("\\x00\\x00"))
                {
                    continue;
                }
                qDebug() << "s father Dir == > " << s << " ; returnlen_ret = " << returnlen_ret;
                if(s != "")//这里不能多级判断，不知道为啥
                {
                    if(ui->listWidget_father->findItems(s,Qt::MatchExactly).count() == 0)
                    {
                        returnlen_ret += s.toLocal8Bit().length() + 1;//因为最后一位为'\r'所以要+1
                        if(returnlen_ret > returnlen)
                        {
                            break;
                        }
                        if(s.contains("."))
                        {
                            continue;
                        }
                        if(s.contains(".."))
                        {
                            continue;
                        }
                        ui->listWidget_father->addItem(s);
                        QList<QListWidgetItem*> listItem = ui->listWidget_father->findItems(s,Qt::MatchExactly);//这个函数如果没有元素会卡住
                        if(listItem.count() > 0)
                        {
                            listItem.at(0)->setBackgroundColor(QColor(121,139,163,63));//主目录第一次也要赋予背景颜色,//这个返回的是const，不知道会不会有影响
                        }
                    }
                }
            }
        }

        if(ui->listWidget_father->count() > 0)
        {
            if(go_up)
            {
                QList<QListWidgetItem*> listItem2 = ui->listWidget_father->findItems(go_up_name,Qt::MatchExactly);//这个函数如果没有元素会卡住
                if(listItem2.count() > 0)
                {
                    ui->listWidget_father->setCurrentItem(listItem2[0]);
                }else{
                    ui->listWidget_father->setCurrentRow(0);
                }
                go_up = false;
            }else{
                ui->listWidget_father->setCurrentRow(0);
                QString ret = ui->listWidget_father->currentItem()->text();
                if(ret[ret.length() - 1] == '\r')
                {
                    ret.chop(1);
                }
    //            filelist.append(ret);
            }
        }

        ui->label->setText(GetFilename());
        isInfatherfile = true;
        fatherorchild = false;//获取父文件
        hp_autoupload_dialog->down_load(1);
        hp_autoupload_dialog->show();
        dialog_timer->start();
        download_shearch(GetFilename(),fatherorchild);
    }else{
        if(ui->listWidget_child->count() != 0)
        {
            ui->listWidget_child->clear();
        }
        if(return_value == RE_OK)
        {
            QStringList strs = name.split("\n");
            foreach(QString s,strs)
            {
                if(s.contains("\""))
                {
                    continue;
                }
                if(s.contains("\\x00\\x00"))
                {
                    continue;
                }
                qDebug() << "Child File == > " << s << " ; returnlen_ret = " << returnlen_ret;
                if(s != "")//这里不能多级判断，不知道为啥
                {
                    if(ui->listWidget_child->findItems(s,Qt::MatchExactly).count() == 0)
                    {
                        returnlen_ret += s.toLocal8Bit().length() + 1;//因为最后一位为'\r'所以要+1
                        if(returnlen_ret > returnlen)
                        {
                            break;
                        }
                        ui->listWidget_child->addItem(s);
    //                    returnlen_ret += s.length() + 1;//因为最后一位为'\r'所以要+1
                    }
                }
            }
        }
        if(ui->listWidget_child->count() > 0)
        {
            ui->listWidget_child->setCurrentRow(0);
            QString ret = ui->listWidget_child->currentItem()->text();
            if(ret[ret.length() - 1] == '\r')
            {
                ret.chop(1);
            }
//            filelist.append(ret);
        }
        ui->label->setText(GetFilename());
        //以下是获取子目录
        fatherorchild = true;//获取子目录
        isInchilddir = true;//处于获取子目录状态
        hp_autoupload_dialog->down_load(1);
        hp_autoupload_dialog->show();
        dialog_timer->start();
        download_shearch(GetFilename(),fatherorchild);
    }
    setBtstatus();//设置控件状态
    //}
    if(returnlen > 1024)//若包裹过大，则都要加上这一句
    {
        qDebug() << "========================== FREE SUCCESS ==========================";
        char *free_ret = data - sizeof(package_head_t);
        qDebug("Free Adress = %x",free_ret);
        free(free_ret);
    }
}
void hp_download::slot_pc_sys_set_download(unsigned char return_value)
{
    qDebug("slot_pc_sys_set_download:return_value:0x%02x",return_value);
    hp_autoupload_dialog->down_load(2);
    if(return_value == RE_OK)
    {
        hp_autoupload_dialog->setFrame3Text(fokdownload);
    }else{
        hp_autoupload_dialog->setFrame3Text(ffaildownload);
    }
    if(dialog_timer->isActive())
    {
        dialog_timer->stop();
    }
    if(dialog_wait_timer->isActive())
    {
        dialog_wait_timer->stop();
    }
    hp_autoupload_dialog->show();
}
void hp_download::slot_set_IP_Account_Password(QString ip,QString account,QString password,int errorMsg)
{
    if(errorMsg == 1)
    {

    }else{
        IP = ip;
        Account = account;
        Password = password;
    }
}
bool hp_download::setbtgoDown()
{
    if(ui->listWidget_child->count() == 0)
    {
        ui->godown->setEnabled(false);
    }else{
        QColor ret(121,139,163,63);
        if(ret == ui->listWidget_child->currentItem()->backgroundColor())
        {
            ui->godown->setEnabled(true);
        }else{
            ui->godown->setEnabled(false);
        }
    }
}
bool hp_download::setbtgoup()
{
    if(ui->listWidget_child->count() != 0)
    {
        if(filelist.size() > 2)
        {
            ui->goup->setEnabled(true);
        }else{
            ui->goup->setEnabled(false);
        }
    }else{
        if(ui->listWidget_father->count() != 0)
        {
            if(filelist.size() > 1)
            {
                ui->goup->setEnabled(true);
            }else{
                ui->goup->setEnabled(false);
            }
        }else{
            ui->goup->setEnabled(false);
        }
    }
}
bool hp_download::setbtgetFile()
{
    if(ui->listWidget_child->count() == 0)
    {
        if(ui->listWidget_father->count() == 0)
        {
            ui->get_file->setEnabled(false);
        }else{
            QColor ret(121,139,163,63);
            if(ret == ui->listWidget_father->currentItem()->backgroundColor())
            {
                ui->get_file->setEnabled(false);
            }else{
                ui->get_file->setEnabled(true);
            }
        }
    }else{
        QColor ret(121,139,163,63);
        if(ret == ui->listWidget_child->currentItem()->backgroundColor())
        {
            ui->get_file->setEnabled(false);
        }else{
            ui->get_file->setEnabled(true);
        }
    }
}
void hp_download::setBtstatus()
{
    setbtgoDown();
    setbtgetFile();
    setbtgoup();
}
void hp_download::on_toolButton_back_clicked()
{
    this->close();
}

void hp_download::on_wifi_Flush_clicked()
{
    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->show();
    dialog_timer->start();

    ui->listWidget_child->clear();
    ui->listWidget_father->clear();

    isInchilddir = false;
    isInfatherfile = false;
    fatherorchild = true;
    filelist.clear();
    download_shearch(GetFilename(),fatherorchild);
}

void hp_download::on_get_file_clicked()
{
    qDebug() << "on_get_file_clicked  sd_insert = " << sd_insert;
    if(!sd_insert)
    {
        hp_autoupload_dialog->down_load(2);
        hp_autoupload_dialog->setFrame3Text(fnoSD);
        hp_autoupload_dialog->show();
        return;
    }

    ftp_para para;
    memset(&para,0,sizeof(ftp_para));
    strcpy(para.HostIP,IP.toLocal8Bit().data());
    strcpy(para.UserName,Account.toLocal8Bit().data());
    strcpy(para.Password,Password.toLocal8Bit().data());

    QString ret = ui->label->text();
    if(ret[ret.length() - 1] == '/')
    {
        ret.chop(1);
    }

    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->show();
    dialog_timer->start();

    strcpy(para.FileName,ret.toUtf8().data());
    qDebug() << "Download File == > " << ret;
    signal_pc_sys_set_download(para);
}

void hp_download::on_listWidget_father_currentRowChanged(int currentRow)
{
    qDebug() << "on_listWidget_father_currentRowChanged";
}

void hp_download::on_listWidget_father_itemClicked(QListWidgetItem *item)
{
    qDebug() << "on_listWidget_father_itemClicked";
    if(ui->listWidget_father->currentItem()->backgroundColor() != QColor(121,139,163,63))
    {
        if(ui->listWidget_child->count() == 0)
        {
            if(filelist.size() != 0)
                filelist.removeLast();
        }else{
            if(filelist.size() != 0)
                filelist.removeLast();
            if(filelist.size() != 0)
                filelist.removeLast();
        }
        QString ret = ui->listWidget_father->currentItem()->text();
        if(ret[ret.length() - 1] == '\r')
        {
            ret.chop(1);
        }
        filelist.append(ret);
        ui->label->setText(GetFilename());//重新设置文件名
        if(ui->listWidget_child->count() != 0)
        {
            ui->listWidget_child->clear();
        }
        setBtstatus();
        ui->get_file->setEnabled(true);
        return;//若不是目录，则直接返回
    }
    fatherorchild = false;
    if(ui->listWidget_child->count() == 0)
    {
        if(filelist.size() != 0)
            filelist.removeLast();
    }else{
        if(filelist.size() != 0)
            filelist.removeLast();
        if(filelist.size() != 0)
            filelist.removeLast();
    }
    QString ret = ui->listWidget_father->currentItem()->text();
    if(ret[ret.length() - 1] == '\r')
    {
        ret.chop(1);
    }
    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->show();
    dialog_timer->start();
    filelist.append(ret);
    download_shearch(GetFilename(),fatherorchild);

    ui->label->setText(GetFilename());
    if(ui->listWidget_child->count() != 0)
    {
        ui->listWidget_child->clear();
    }
    setBtstatus();
}

void hp_download::on_listWidget_child_itemClicked(QListWidgetItem *item)
{
    if(filelist.size() != 0)
        filelist.removeLast();
    QString ret = ui->listWidget_child->currentItem()->text();
    if(ret[ret.length() - 1] == '\r')
    {
        ret.chop(1);
    }
    filelist.append(ret);
    ui->label->setText(GetFilename());
    setBtstatus();//设置控件状态
}

void hp_download::on_godown_clicked()
{
    qDebug() << "on_godown_clicked";

    //顺序问题或许是本质问题
    ui->listWidget_father->clear();
    int currentrow = ui->listWidget_child->currentRow();
    for(int i = 0;i < ui->listWidget_child->count();i++)
    {
        ui->listWidget_father->addItem(ui->listWidget_child->item(i)->text());//从0开始
        if(ui->listWidget_child->item(i)->backgroundColor() == QColor(121,139,163,63))
            ui->listWidget_father->item(i)->setBackgroundColor(QColor(121,139,163,63));
    }
    ui->listWidget_father->setCurrentRow(currentrow);
    ui->listWidget_child->clear();

    fatherorchild = false;//查询该节点的子节点
    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->show();
    dialog_timer->start();
    download_shearch(GetFilename(),fatherorchild);
}

void hp_download::on_goup_clicked()
{
    qDebug() << "on_goup_clicked";
    if(ui->listWidget_child->count() == 0)//若没有子文件，也就是说当前为父目录
    {
        if(filelist.size() <= 1)
        {
            return;
        }
    }else{
        if(filelist.size() <= 2)
        {
            return;
        }
    }

    if(ui->listWidget_child->count() == 0)//若没有子文件，也就是说当前为父目录
    {
        if(filelist.size() != 0)//删除最后一个
            filelist.removeLast();
        go_up_name = filelist.at(filelist.size() - 1) + "\r";
        if(filelist.size() != 0)//删除父节点
            filelist.removeLast();
    }else{
        if(filelist.size() != 0)//删除最后一个
            filelist.removeLast();
        if(filelist.size() != 0)//删除父节点
            filelist.removeLast();
        go_up_name = filelist.at(filelist.size() - 1) + "\r";
        if(filelist.size() != 0)//删除父父节点
            filelist.removeLast();
    }
    ui->listWidget_child->clear();
    ui->listWidget_father->clear();
    fatherorchild = true;
    go_up = true;
    hp_autoupload_dialog->down_load(1);
    hp_autoupload_dialog->show();
    dialog_timer->start();
    download_shearch(GetFilename(),fatherorchild);

}

void hp_download::on_listWidget_child_currentRowChanged(int currentRow)
{
}
