#include  "hp_twice_analysis.h"
#include  "ui_hp_twice_analysis.h"
#include  "mainwidget.h"

Hp_Twice_Analysis::Hp_Twice_Analysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Twice_Analysis)
{
    ui->setupUi(this);

    hp_parent = parent;
    init_flag = false;
    stop_twice_preview = false;
    voice_r_clicked_save = 0;
    voice_r_clicked = 0;
    needsave = false;

    save_state =false ;
    cancle_state = false;
    voice_state = false;
    record_state = false;
    play_state = false;

    twice_text_state = false;

    ui->frame->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->label_time->setVisible(false);
    //this->setGeometry(100,272-height()-2,width(),height());
     this->setGeometry(165,480-height()-2,width(),height());// 100->165; 272->480
    setFixedSize(width(), height());
    headset_status = false;

    jpg_voicefile_open = "/home/root/res/twice_audio_temp";
    jpg_voice_new = "/home/root/res/audio_temp";
    jpg_voice_close = "/home/root/res/twice_audio_temp";
    process = new QProcess(this);


    connect(process,SIGNAL(readyRead()),this,SLOT(ReadData()));
    connect(&hti,SIGNAL(sync_text()),this,SLOT(slot_sync_text()));
    connect(&timer_1s,SIGNAL(timeout()),this,SLOT(slot_timer_1s_out()));
    connect(&hti,SIGNAL(signal_frminput_set_lcd_offed_state()),this,SLOT(slot_twiceanalysis_set_lcd_offed_state()));

}
void Hp_Twice_Analysis::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->setGeometry(100,272-58-2,279,58);
        this->setFixedSize(279,58);
        ui->frame->setGeometry(40,0,241,40);
        ui->toolButton_cancle->setGeometry(160,2,36,36);
        ui->toolButton_save->setGeometry(120,2,36,36);
        ui->toolButton_text->setGeometry(0,2,36,36);
        ui->toolButton_text_2->setGeometry(200,2,36,36);
        ui->toolButton_voice_p->setGeometry(80,2,36,36);
        ui->toolButton_voice_r->setGeometry(40,2,36,36);
        ui->progressBar->setGeometry(40,40,196,16);
        ui->toolButton->setGeometry(2,2,36,36);
        ui->label_time->setGeometry(236,40,36,16);
    }
    hti.hp_setDefine_S3x0(isSelect);
}
void Hp_Twice_Analysis::ReadData()
{
    while (!process->atEnd())
    {
        QString s = QLatin1String(process->readLine());
        qDebug() << s;
        if(s.contains("Broken pipe"))
        {
            //可能是播放自动结束相关
            if(ui->toolButton_voice_p->isChecked())
                ui->toolButton_voice_p->setChecked(false);
            if(ui->toolButton_voice_r->isChecked())
            {
                ui->toolButton_voice_r->setChecked(false);
                ui->toolButton_voice_r->clicked(false);
            }
            if(play_state == true)
            {
                play_state = false;
                ui->toolButton_save->setEnabled(save_state);
                ui->toolButton_cancle->setEnabled(cancle_state);
            }
            process->close();
        }
    }

}
void Hp_Twice_Analysis::hp_setMaxAudioTime(int Time)
{
    ui->progressBar->setMaximum(Time);
}
void Hp_Twice_Analysis::slot_timer_1s_out()
{
    timer_1s_count++;
    ui->progressBar->setValue(timer_1s_count);

    ui->label_time->show();
    ui->label_time->setText(QString::number(timer_1s_count) + "s");
    //录音播放都会出现的函数
    if(timer_1s_count >= ui->progressBar->maximum())
    {
        if(ui->toolButton_voice_p->isChecked())
            ui->toolButton_voice_p->setChecked(false);
        if(ui->toolButton_voice_r->isChecked())
        {
            ui->toolButton_voice_r->setChecked(false);
            ui->toolButton_voice_r->clicked(false);
        }
        ui->progressBar->close();
        ui->label_time->close();
      //录音超时处理，。
        timer_1s_count = 0;
        process->close();
        timer_1s.stop();
        if(record_state)
        {
            ui->toolButton_cancle->setEnabled(cancle_state);        //取消按钮恢复到之前的状态
            record_state =false;
            voice_state = false;
        }
        if(play_state == true)
        {
            play_state = false;
            ui->toolButton_save->setEnabled(save_state);
            ui->toolButton_cancle->setEnabled(cancle_state);
        }
    }
}

void Hp_Twice_Analysis::slot_sync_text()
{
    text = hti.getText();
    ui->toolButton_save->setEnabled(true);
    signal_to_send_twice_text(text);
}

Hp_Twice_Analysis::~Hp_Twice_Analysis()
{
    delete ui;
}

void Hp_Twice_Analysis::on_toolButton_clicked(bool checked)
{
    signal_update_lcdoff_time(false);
    if(init_flag)
        return;
    ui->frame->setVisible(checked);
}

bool Hp_Twice_Analysis::start_twice_analysis(QString file)
{
    qDebug() << " ((((( Twice ))))) 1.0 ";
    if(QFile::exists(jpg_voicefile_open))
    {
        QFile::remove(jpg_voicefile_open);
    }
    qDebug() << " ((((( Twice ))))) 1.1 ";
//    allfilename = file;
    if(!readDataFromJpg(file))
        return false;
    stop_twice_preview =false;          //标志复位
    qDebug() << " ((((( Twice ))))) 1.2 ";
 //   needsave = false;
    MainWidget *p = (MainWidget *)hp_parent;
    init_flag = true;

    new_text = hti.getText();
    qDebug() << __func__ << new_text;
    ui->frame->setVisible(ui->toolButton->isChecked());
    ui->progressBar->setVisible(false);
    ui->label_time->setVisible(false);
    ui->toolButton_cancle->setEnabled(false);            //needsave ->false
    ui->toolButton_save->setEnabled(false);
    ui->toolButton_voice_p->setChecked(false);
    if(!p->hpsetting.hpblesearch.isLinked && !p->hpsetting.hpblesearchold.get_conn_status())
    {
        ui->toolButton_voice_p->setEnabled(false);
    }
    else
    {
        ui->toolButton_voice_p->setEnabled(QFile::exists(jpg_voicefile_open));
    }
    ui->toolButton_voice_r->setChecked(false);
    ui->toolButton_voice_r->setEnabled(p->get_headset_status());
    init_flag = false;

    if(ui->toolButton_text_2->isChecked())
    {
        QString text = hti.getText();
        signal_set_twice_text(twice_text_state,text);
    }
//    qDebug() << " ((((( Twice ))))) 1.3 ";
    return true;

}

bool Hp_Twice_Analysis::stop_twice_analysis(QString file)
{
    qDebug() << "Hp_Twice_Analysis::stop_twice_analysis : running . . .";
    if(!taskFileName.isEmpty() && !taskFileName_src.isEmpty()) {
        QString fileName = taskFileName;
        QFile tempFile(fileName);
        if(tempFile.exists()) {
            QString cmd = QString("mv %1 %2").arg(taskFileName).arg(taskFileName_src);
            QByteArray cmd_b = cmd.toUtf8();
            char* cmd_c = cmd_b.data();
            system(cmd_c);
            system("sync");
            qDebug() << cmd;
        } else {
            qDebug() << "Hp_Twice_Analysis::stop_twice_analysis : file is not exists ! ! !";
        }
    }

    save_state =false ;
    cancle_state = false;
    record_state = false;
    play_state = false;


    if(  10==voice_r_clicked_save ){                     //值为10表示开始录音.并且需要保存
         voice_r_clicked_save = voice_r_clicked_save*2;                 //20  表示需要保存
    }else{
        voice_r_clicked_save =0;
    }

    if(needsave)
    {
        if( true == stop_twice_preview){                //点击预览的时候停止二次分析
            allfilename = allfilename_now;
            slot_return_close_voice_r();
            slot_return_close_voice_p();
        }else{                                                           //切换图片的时候停止二次分析
            allfilename = allfilename_old;
            slot_return_close_voice_r();
            slot_return_close_voice_p();
        }
        stop_twice_preview =false;                      //标志复位

        if(QFile::exists(jpg_voice_close))
        {
              QFile::remove(jpg_voice_close);
        }


        if(writeDataToJpg(allfilename))
        {
            needsave =false;
            return true;
        }
        else
        {
            needsave =false;
            return false;
        }
    }else{
        needsave =false;
    }

    return true;
}

bool Hp_Twice_Analysis::stop_twice_analysis_name(QString file_old, QString file_now)      //获取停止二次分析的图片名字
{
    allfilename_old = file_old;
    allfilename_now = file_now;
}

void Hp_Twice_Analysis::slot_twiceanalysis_set_lcd_offed_state()
{
    qDebug( ) << "@@@@@@@@@@@@@@@@@@@@@";
    signal_twiceanalysis_set_lcd_offed_state();
}

bool Hp_Twice_Analysis::readDataFromJpg(QString file)            //读取图片信息
{
    hti.setText("");    //加载图片信息之前，先把上个图片的 留下的text清除
    voice_r_clicked = 0;
//    qDebug() << " ((((( Twice ))))) 1.1.1 ";
    QFile jpg_file(file);
    if(!jpg_file.open(QIODevice::ReadOnly))
        return false;

    p_jpg_data = (char *)malloc(jpg_file.size());
    if(p_jpg_data == NULL)
        return false;
//    qDebug() << " ((((( Twice ))))) 1.1.2 ";
    QDataStream in(&jpg_file);                  //读取数据流
    if(in.readRawData(p_jpg_data,jpg_file.size())!= jpg_file.size())
        return false;

    //标签数量结构体。内容
    memcpy((char *)&tagnum,p_jpg_data+jpg_file.size()-sizeof(tagnum_t),sizeof(tagnum_t));

    //判断标签是否正确
    if(tagnum.nTag != TAGNUM_TAG)
        return false;

    //标签结构
    memcpy((char *)taginfo,p_jpg_data+jpg_file.size()-sizeof(tagnum_t)-sizeof(taginfo_t)*tagnum.num,sizeof(taginfo_t)*tagnum.num);
//    qDebug() << " ((((( Twice ))))) 1.1.3 ";
    text.clear();
    //语音信息结构体
    memset((char *)&voiceinfo,0,sizeof(voiceinfo_t));
    memset((char *)&textinfo,0,sizeof(textinfo_t));

//    needsave = false;
    //根据标签数量循环遍历
    taskFileName.clear();
    taskFileName_src.clear();
//    qDebug() << " ((((( Twice ))))) 1.1.4 ";
    for(int i=0;i<tagnum.num;i++)
    {
//        qDebug("%x \n", taginfo[i].nTag);
//        qDebug("VOICEINFO_TAG %x  %d\n", VOICEINFO_TAG, voiceinfo.nVoiceLen);
        if(taginfo[i].nTag == VOICEINFO_TAG)  //1515 850 248
        {

            memcpy((char *)&voiceinfo,p_jpg_data+taginfo[i].offset,sizeof(voiceinfo_t));

            QFile voicefile(jpg_voice_close);
            voicefile.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QDataStream out(&voicefile);
            out.writeRawData(p_jpg_data+taginfo[i].offset+sizeof(voiceinfo_t),voiceinfo.nVoiceLen);
//            qDebug("VOICEINFO_TAG %x  %d\n", VOICEINFO_TAG, voiceinfo.nVoiceLen);
            voicefile.close();
            MainWidget* p = (MainWidget*)hp_parent;
            qDebug() << "p->hpsetting.hpblesearch.isLinked" << p->hpsetting.hpblesearch.isLinked;
            if(!p->hpsetting.hpblesearch.isLinked && !p->hpsetting.hpblesearchold.get_conn_status())
            {
                ui->toolButton_voice_p->setChecked(false);
                ui->toolButton_voice_p->setEnabled(false);
            }
            else
            {
                ui->toolButton_voice_p->setEnabled(QFile::exists(jpg_voicefile_open));
            }
        }
        else if(taginfo[i].nTag == TEXTINFO_TAG)    ////1515 850 249
        {
            memcpy((char *)&textinfo,p_jpg_data+taginfo[i].offset,sizeof(textinfo_t));
            char text_s[textinfo.nTextLen+1];
            memset(text_s,'\0',textinfo.nTextLen+1);

            memcpy(text_s,p_jpg_data+taginfo[i].offset+sizeof(textinfo_t),textinfo.nTextLen);
            text = QByteArray(text_s);                                      //读取到的文本信息
//读取文本信息，进行格式转换
            QString tttt;
            tttt = text.toUtf8();
            hti.setText(tttt);
        }else if(taginfo[i].nTag == FILEINFO_TAG) {
            int nDesLen = 0;
            int nDesLen2 = 0;
            int nDesLen3 = 0;
            int nDesLen4 = 0;
            int nDesLen5 = 0;
            int nDesLen6 = 0;
            int nLessLen;
            int nLessLen2 = 0;
            int nLessLen3 = 0;
            int nLessLen4 = 0;
            int nLessLen5 = 0;
            int nLessLen6 = 0;
            image_head_t head;
            memcpy((char *)&nDesLen, p_jpg_data + taginfo[i].offset + 4, 4);
            nLessLen = nDesLen;//拷贝内容长度
            qDebug() << "’ndesLen" << nDesLen << sizeof(file_info_t);
            if(nDesLen > sizeof(file_info_t))
                nLessLen = sizeof(file_info_t);
            memcpy((char *)&head, p_jpg_data + taginfo[i].offset, nLessLen);

            memcpy((char *)&nDesLen2, p_jpg_data + taginfo[i].offset + nDesLen + 4, 4);
            nLessLen2 = nDesLen2;//拷贝内容长度
            if(nDesLen2 > sizeof(product_info_t))
                nLessLen2 = sizeof(product_info_t);
            qDebug() << "’nLessLen2" << nLessLen2 << head.file.nDesLen << sizeof(product_info_t);
            memcpy((char *)&head + sizeof(file_info_t), p_jpg_data + taginfo[i].offset + nDesLen, nLessLen2);

            memcpy((char *)&nDesLen3, p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + 4,4);
            nLessLen3 = nDesLen3;//拷贝内容长度
            if(nDesLen3 > sizeof(color_info_t))
                nLessLen3 = sizeof(color_info_t);
            qDebug() << "’nLessLen3" << nLessLen3 << head.product.nDesLen << sizeof(color_info_t);
            memcpy((char *)&head + sizeof(file_info_t) + sizeof(product_info_t),
                   p_jpg_data + taginfo[i].offset + nLessLen2 + nDesLen, nLessLen3);

            memcpy((char *)&nDesLen4, p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3 + 4,4);
            nLessLen4 = nDesLen4;//拷贝内容长度
            qDebug() << "’nLessLen4" << nLessLen4 << head.color.nDesLen << sizeof(alg_info_t);
            if(nDesLen4 > sizeof(alg_info_t))
                nLessLen4 = sizeof(alg_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(color_info_t),
                   p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3, nLessLen4);

            memcpy((char *)&nDesLen5, p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + 4,4);
            nLessLen5 = nDesLen5;//拷贝内容长度
            qDebug() << "’nLessLen5" << nLessLen5 << head.alg.nDesLen << sizeof(temper_info_t);
            if(nDesLen5 > sizeof(temper_info_t))
                nLessLen5 = sizeof(temper_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(alg_info_t) + sizeof(color_info_t),
                   p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4, nLessLen5);
            qDebug() << "6";
            memcpy((char *)&nDesLen6, p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + nDesLen5 + 4,4);
            nLessLen6 = nDesLen6;//拷贝内容长度
            qDebug() << " ’nLessLen6" << nLessLen5 << head.temper.nDesLen << sizeof(item_data_t);
            if(nDesLen6 > sizeof(item_data_t))
                nLessLen6 = sizeof(item_data_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(alg_info_t) + sizeof(color_info_t) + sizeof(temper_info_t),
                   p_jpg_data + taginfo[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + nDesLen5, nLessLen6);

            if((file.contains(".irp") || file.contains(".vi")) && !file.contains("IMG"))
            {
                taskFileName = head.file.PicName;
                taskFileName_src = file;
                qDebug() << "Hp_Twice_Analysis::readDataFromJpg : taskFileName_src = " << taskFileName_src << "; taskFileName = " << taskFileName;
            }
        }
    }
//    qDebug() << " ((((( Twice ))))) 1.1.5 ";
    free(p_jpg_data);
    jpg_file.close();
    return true;
}

bool Hp_Twice_Analysis::writeDataToJpg(QString file)
{
    qDebug() << "Hp_Twice_Analysis::writeDataToJpg ";
    if(!new_text.isEmpty())
        signal_core_analysis_pic_twice_addtext(new_text.toLocal8Bit().data());
    voice_r_clicked_save = 0;
    voice_r_clicked = 0;

    if(QFile::exists(jpg_voice_new))
    {
        QFile::remove(jpg_voice_new);
    }
    return true;
}
void Hp_Twice_Analysis::keyReleaseEvent(QKeyEvent *ev)
{
    signal_update_lcdoff_time(true);
    qDebug()<<"Hp_Twice_Analysis::keyReleaseEvent(QKeyEvent *ev)............................................."<<ev->key();
    switch( ev->key() )
    {
    case KEY_RETURN:
        if( play_state==true )
        {
            on_toolButton_voice_r_clicked(false);
            ui->toolButton_voice_r->setChecked(false);
            ui->toolButton_voice_p->setEnabled(false);
            ui->toolButton_cancle->setEnabled(false);
            ui->toolButton_save->setEnabled(false);
        }
        this->close();
        break;
    default:
        break;
    }
}
void Hp_Twice_Analysis::slot_get_audio_status()
{
    qDebug() << "Hp_Twice_Analysis::slot_get_audio_status";
    signal_core_get_twice_audio_status();
}

void Hp_Twice_Analysis::slot_core_get_twice_audio_status(unsigned char return_value, int status)
{
    qDebug() << "Hp_Twice_Analysis::slot_core_get_twice_audio_status" << return_value << status;
    if(!this->isVisible())
    {
        return;
    }
    if(RE_OK == return_value)
    {
        if(status == 0)
        {
            if(ui->toolButton_voice_p->isChecked())
            {
                ui->toolButton_voice_p->setChecked(false);
                on_toolButton_voice_p_clicked(false);
            }
        }
        else if(status == 1)
        {
            QTimer::singleShot(300, this, SLOT(slot_get_audio_status()));
        }
        else if(status == 2)
        {
            QTimer::singleShot(300, this, SLOT(slot_get_audio_status()));
        }
    }
}

void Hp_Twice_Analysis::slot_core_analysis_pic_twice_audioplay_start(unsigned char return_value)
{
    qDebug() << "slot_core_analysis_pic_twice_audioplay_start" << return_value;
    if(return_value == RE_OK)
    {
        play_state = true;
        timer_1s_count = 0;
        ui->progressBar->setValue(timer_1s_count);
        ui->label_time->setText(QString::number(timer_1s_count) + "s");
        timer_1s.start(1000);
        QTimer::singleShot(100, this, SLOT(slot_get_audio_status()));
    }
}
void Hp_Twice_Analysis::slot_core_analysis_pic_twice_audioplay_stop(unsigned char return_value)
{
    qDebug() << "slot_core_analysis_pic_twice_audioplay_stop" << return_value;
    if(return_value == RE_OK){

    }
    timer_1s.stop();
    play_state = false;
    ui->toolButton_save->setEnabled(save_state);
    ui->toolButton_cancle->setEnabled(cancle_state);

    ui->label_time->setVisible(false);
}

void Hp_Twice_Analysis::slot_core_analysis_pic_twice_audiocap_start(unsigned char return_value)
{
    qDebug() << "slot_core_analysis_pic_twice_audiocap_start" << return_value;

}

void Hp_Twice_Analysis::slot_core_analysis_pic_twice_audiocap_stop(unsigned char return_value)
{

    ui->label_time->setVisible(false);
    qDebug() << "slot_core_analysis_pic_twice_audiocap_stop" << return_value;

}

void Hp_Twice_Analysis::on_toolButton_voice_p_clicked(bool checked)         //播放
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        signal_core_analysis_pic_twice_audioplay_start();
    }
    else
    {
        signal_core_analysis_pic_twice_audioplay_stop();
    }
}

void Hp_Twice_Analysis::on_toolButton_voice_r_clicked(bool checked)             //录音
{
    signal_update_lcdoff_time(false);
    if(checked)
    {
        signal_core_analysis_pic_twice_audiocap_start();
        voice_state = true;
        record_state = true;                                      //表示开始录音
        voice_r_clicked_save = 5;
        timer_1s_count = 0;
        ui->label_time->setText(QString::number(timer_1s_count) + "s");
        ui->progressBar->setValue(timer_1s_count);
        timer_1s.start(1000);
    }
    else
    {
        signal_core_analysis_pic_twice_audiocap_stop();
        timer_1s.stop();
        voice_state = false;
        record_state = false;
        qDebug() << "on_toolButton_voice_r_clicked close";
        ui->toolButton_voice_p->setEnabled(QFile::exists(jpg_voicefile_open));
        ui->toolButton_save->setEnabled(true);
        save_state = true;
        ui->toolButton_cancle->setEnabled(cancle_state);        //取消按钮恢复到之前的状态
    }
}

void Hp_Twice_Analysis::slot_return_close_voice_r()
{
        on_toolButton_voice_r_clicked(false);
        ui->toolButton_voice_r->setChecked(false);
        ui->toolButton_voice_p->setEnabled(false);
        ui->toolButton_cancle->setEnabled(false);
        ui->toolButton_save->setEnabled(false);
         voice_state= false;
}

void Hp_Twice_Analysis::slot_return_close_voice_p()
{
    on_toolButton_voice_p_clicked(false);
    record_state = false;
    save_state = false;
    play_state= false;
    voice_state = false;
    ui->toolButton_voice_r->setChecked(false);
    ui->toolButton_voice_p->setChecked(false);
    ui->toolButton_cancle->setEnabled(false);
    ui->toolButton_save->setEnabled(false);
}

void Hp_Twice_Analysis::slot_send_twice_text()
{
    //if(ui->toolButton_text_2->isChecked())//接下来就是展示的问题了，这里只是传值
    //{
        QString text = hti.getText();
        signal_to_send_twice_text(text);
    //}
}

void Hp_Twice_Analysis::on_toolButton_text_released()    //点击文本按钮
{
    signal_update_lcdoff_time(false);
    hti.show();
}

void Hp_Twice_Analysis::on_toolButton_save_released()       //点击保存按钮。获取文本
{
    signal_update_lcdoff_time(false);
    if(  5==voice_r_clicked_save ){                     //值为5表示开始录音
     voice_r_clicked_save = voice_r_clicked_save*2;                 //值为10，表示进行录音，并且需要保存
    }else{
//        voice_r_clicked_save = 0;
    }

    //    new_text = hti.getText();
    QString text = hti.getText();
    qDebug() << __func__ << text;
    signal_core_analysis_pic_twice_addtext(text.toLocal8Bit().data());

    needsave = true;
    ui->toolButton_cancle->setEnabled(needsave);
    ui->toolButton_save->setEnabled(false);             //点击一下后变为灰色。

    qDebug() << "on_toolButton_save_released == > " << QFile::exists(jpg_voicefile_open) << " ; " << QFile::exists(jpg_voice_new);
    if(QFile::exists(jpg_voicefile_open) || QFile::exists(jpg_voice_new))
    {
        signal_core_analysis_pic_twice_addaudio();
        MainWidget* p = (MainWidget*)hp_parent;
        if(!p->hpsetting.hpblesearch.isLinked && !p->hpsetting.hpblesearchold.get_conn_status())
        {
            ui->toolButton_voice_p->setChecked(false);
            ui->toolButton_voice_p->setEnabled(false);
        }
        else
        {
            ui->toolButton_voice_p->setEnabled(true);
        }
    }
    cancle_state =true;    //取消按钮的状态
    save_state = false;
}

void Hp_Twice_Analysis::on_toolButton_cancle_released()
{
    signal_update_lcdoff_time(false);
    signal_core_analysis_pic_twice_addtext(new_text.toLocal8Bit().data());
    signal_core_analysis_pic_twice_cancelaudio();
    if(QFile::exists(jpg_voicefile_open))
    {
        MainWidget* p = (MainWidget*)hp_parent;
        if(!p->hpsetting.hpblesearch.isLinked && !p->hpsetting.hpblesearchold.get_conn_status())
        {
            ui->toolButton_voice_p->setChecked(false);
            ui->toolButton_voice_p->setEnabled(false);
        }
        else
        {
            ui->toolButton_voice_p->setEnabled(true);
        }
    }
    needsave = false;
    ui->toolButton_cancle->setEnabled(false);
    cancle_state = false;
    save_state = true;
    ui->toolButton_save->setEnabled(true);
}

void Hp_Twice_Analysis::on_toolButton_text_2_released()
{
    signal_update_lcdoff_time(false);
    if(twice_text_state == true)
    {
        twice_text_state = false;
        ui->toolButton_text_2->setChecked(false);
    }
    else
    {
        twice_text_state = true;
        ui->toolButton_text_2->setChecked(true);
    }
    QString text = hti.getText();
    signal_set_twice_text(twice_text_state,text);
}
