#include "hp_panorama.h"
#include "ui_hp_panorama.h"

Hp_Panorama::Hp_Panorama(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_Panorama)
{
    ui->setupUi(this);
    m_isS3X0 = false;
    m_saveCheck = false;
    isSavePanorama = false;
    m_degreeTimer = new QTimer(this);
    connect(m_degreeTimer,SIGNAL(timeout()),this,SLOT(slot_timer_get_match_degree()));//定时器获取匹配度
    m_degreeTimer->stop();
    m_dialog.slot_panorama_dialog_type(1);//写的很捞的翻译
    m_dialog.setParent(this);
    m_dialog.close();
    connect(&m_dialog, SIGNAL(signal_panorama_start()), this, SLOT(slot_ret_match_panorama()));//点击确认或者拍照键进行拼接展示
    init_panorama();
    qDebug() << "Over panorama init";
    set_language(0);
}

Hp_Panorama::~Hp_Panorama()
{
    delete ui;
}
void Hp_Panorama::scaleWidgetAndChildren(QWidget *widget, qreal scaleFactor)
{
    // 缩放当前 QWidget
//    widget->resize(widget->size() * scaleFactor);
//    qDebug() << widget->objectName();
//    // 递归缩放子控件
//    foreach(QObject *child, widget->children()) {
//        if(QWidget *childWidget = qobject_cast<QWidget*>(child)) {
//            scaleWidgetAndChildren(childWidget, scaleFactor);
//        }
//    }
}

void Hp_Panorama::hp_setDefineS3X0(bool isDefine)
{
    m_isS3X0 = isDefine;
    if(isDefine)
    {
        qDebug() << "init_panorama";
        QFont font70;
        font70.setPointSize(12);
        QFont font60;
        font60.setPointSize(11);
        ui->line_11->hide();
        ui->line_12->hide();
        ui->line_13->hide();
        ui->line_14->hide();
        ui->line_15->hide();
        ui->line_16->hide();
        ui->line_17->hide();
        ui->line_18->hide();
        ui->line_19->hide();

        this->setGeometry(96, 0, 384, 272);
        ui->frame_5->setGeometry(0, 0, 384, 272);
        ui->frame_3->setStyleSheet("color: rgb(255, 255, 255);border: 1px solid white; border-radius: 2px;");
        ui->label_7->setGeometry(0, 15, 384, 15);
        ui->widget_2->setGeometry(150, 40, 70, 20);
        ui->label_degree->setGeometry(0, 0, ui->widget_2->width(), ui->widget_2->height());
        ui->frame_3->setGeometry(0, 110, 384, 55);
        ui->panoramaView->setGeometry(2, 1, 77, 53);
        ui->panoramaView_2->setGeometry(77, 1, 77, 53);
        ui->line->setGeometry(0, 26, 384, 1);
        ui->panorema_ok_2->setGeometry(348 - 20, 7, 40, 40);
        ui->label_degreeTips->setGeometry(0, 165, 384, 15);
        ui->frame_4->setGeometry(0, 220, 384, 25);
        ui->label_5->setGeometry(50, 0, 250, 25);
        ui->panorema_ok->setGeometry(300, 0, 25, 25);
        ui->label_degree->setFont(font70);
        ui->label_7->setFont(font70);
        ui->label_5->setFont(font70);
        ui->label_8->setFont(font70);
        ui->label_degreeTips->setFont(font60);
        currPicNo = 0;
        m_matchRet = 0;
        m_mousePressPosX = 0;
        m_panoramaStartPosX = 0;
        m_isTooLong = false;
        m_isMoveView = false;
        m_degreeTimerStart = false;
        m_mouseMoveMaxX = 3000;
        panoremaPicPath = "abc";
        m_picNameList.clear();
        ui->label_degree->setText("100%");
        ui->label_8->hide();
        ui->panoramaView->hide();
        ui->panoramaView_2->move(ui->panoramaView->width() + 2, 2);
        ui->panoramaView_2->hide();
    }

}

void Hp_Panorama::init_panorama()
{
    if(m_isS3X0)
    {
        qDebug() << "m_isS3X0" << m_isS3X0;
        hp_setDefineS3X0(m_isS3X0);
        m_dialog.hp_setDefine5_5(m_isS3X0);
        return;
    }
    m_dialog.setGeometry(180,160,300,150);
    qDebug() << "init_panorama";
    QFont font70;
    font70.setPointSize(20);
    QFont font60;
    font60.setPointSize(15);

    ui->frame_5->setHidden(false);
    ui->panoramaView_2->setGeometry(107, 5, 111, 95);
    ui->widget_2->setGeometry(260, 100, 121, 31);
    ui->panoramaView->setGeometry(5, 5, 111, 95);
    ui->line->setGeometry(0, 53, 640, 2);
    ui->previewPanorama->move(640, 0);
    ui->label_degree->setFont(font70);
    ui->label_7->setFont(font70);
    ui->label_5->setFont(font70);
    ui->label_8->setFont(font70);
    ui->label_degreeTips->setFont(font60);


    currPicNo = 0;
    m_matchRet = 0;
    m_mousePressPosX = 0;
    m_panoramaStartPosX = 0;
    m_isTooLong = false;
    m_isMoveView = false;
    m_degreeTimerStart = false;
    m_mouseMoveMaxX = 3000;
    panoremaPicPath = "abc";
    m_picNameList.clear();
    ui->label_degree->setText("100%");
    ui->label_8->hide();
    ui->panoramaView->hide();
    ui->panoramaView_2->move(ui->panoramaView->width() + 5, 5);
    ui->panoramaView_2->hide();
}

int  Hp_Panorama::getMatchDegree()
{
    return m_matchRet;
}

void Hp_Panorama::stopTimer()
{
    m_degreeTimer->stop();
    m_saveCheck = true;
    m_degreeTimerStart = false;
}

bool Hp_Panorama::getDialogVisiable()
{
    return m_dialog.isVisible();
}

void Hp_Panorama::setDialogVisiable(bool isVisiable)
{
    if(isVisiable)
    {
        slot_ret_match_panorama();
    }
    m_dialog.close();
}

void Hp_Panorama::set_language(int type)
{
    qDebug() << " Hp_Panorama::set_language" << type;
    switch(type)
    {
    case 0:
        m_fusionDegreeMsg = "匹配度低于30%,确认将覆盖原有照片";
        m_confirmFusionMsg = "按确定或OK键进行拼接";
        m_previewMsg = "图片过长，是否进入预览";
        m_picFail = "拼接失败";
        break;
    case 1:
        m_fusionDegreeMsg = "融合度過低是否拼接";
        m_confirmFusionMsg = "按确定或OK键進行拼接";
        m_previewMsg = "圖片過長，是否進入預覽";
        m_picFail = "拼接失敗";
        break;
    case 2:
        m_fusionDegreeMsg = "Matching rate is below 30%, confirm to overwrite the original photo";
        m_confirmFusionMsg = "Whether to proceed with stitching";
        m_previewMsg = "start preview pic?";
        m_picFail = "failed";
        break;
    case 3:
        m_fusionDegreeMsg = "Процент совпадения ниже 30%, подтвердите перезапись оригинального фото";
        m_confirmFusionMsg = "Следует ли продолжить соединение";
        m_previewMsg = "start preview pic?";
        m_picFail = "подключения";
        break;
    case 4:
        m_fusionDegreeMsg = "A megfelelőségi arány 30% alatt van, erősítse meg az eredeti fénykép felülírását";
        m_confirmFusionMsg = "Folytassuk-e a varrást?";
        m_previewMsg = "start preview pic?";
        m_picFail = "sikertelen";
        break;
    case 5:
        m_fusionDegreeMsg = "La tasa de coincidencia es inferior al 30%, confirme para sobrescribir la foto original";
        m_confirmFusionMsg = "¿Proceder con la unión?";
        m_previewMsg = "start preview pic?";
        m_picFail = "fallida";
        break;
    }
    qDebug() << " Hp_Panorama::set_language" << __LINE__;
}

void Hp_Panorama::splice_panorama()
{
//    slot_ret_match_panorama();
}

void Hp_Panorama::stop_comparsion()
{
    ui->panoramaView_2->close();
    m_picNameList.pop_back();
}

void Hp_Panorama::on_panorema_ok_clicked()
{
    if(currPicNo == 0)
        return;
    show_preview_panorama();
    ui->frame_5->setHidden(true);
}

void Hp_Panorama::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Hp_Panorama::mousePressEvent" << ui->previewPanorama->x() << event->pos().x();
    signal_update_lcdoff_time(true);
    m_mousePressPosX = event->pos().x();
    m_panoramaStartPosX = -ui->previewPanorama->x();
    if(!m_isMoveView)
    {
        signal_sent_press_pos_to_display(event);
    }
}

void Hp_Panorama::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Hp_Panorama::mouseReleaseEvent" << ui->previewPanorama->x() << event->pos().x();
    signal_update_lcdoff_time(true);
    if(!m_isMoveView)
    {
        signal_sent_release_pos_to_display(event);
    }
}

void Hp_Panorama::mouseMoveEvent(QMouseEvent *event)
{
    if(!m_isMoveView)
        return;

    qDebug() << "Hp_Panorama::mouseMoveEvent" << ui->previewPanorama->x() << event->pos().x();
    int moveLength = -(m_panoramaStartPosX + (m_mousePressPosX - event->pos().x()));
    int maxWidth = 640;
    if(m_isS3X0)
        maxWidth = 384;
    if(moveLength + ui->previewPanorama->width() < maxWidth)
        moveLength = maxWidth - ui->previewPanorama->width();
    if(moveLength > 0)
        moveLength = 0;
    ui->previewPanorama->setGeometry(moveLength, 0, ui->previewPanorama->width(), ui->previewPanorama->height());
}

void Hp_Panorama::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
    }
}

void Hp_Panorama::show_preview_panorama()
{
    m_degreeTimer->stop();
    m_degreeTimerStart = false;
    int saveX1 = 130;
    int saveX2 = 470;
    int saveY = 380;
    int showHeight = 480;
    int buttonWidth = 51;
    if(m_isS3X0)
    {
        saveX1 = 70;
        saveX2 = 300;
        saveY = 230;
        showHeight = 272;
        buttonWidth = 30;
    }
    ui->panorema_save->setGeometry(saveX2, saveY, buttonWidth, buttonWidth);
    ui->panorema_cancel->setGeometry(saveX1, saveY, buttonWidth, buttonWidth);
    ui->previewPanorama->move(0, 0);
    ui->label_8->setGeometry(ui->label_7->geometry());
    ui->panorema_save->show();
    ui->panorema_cancel->show();
    ui->previewPanorama->raise();
    ui->panorema_save->raise();
    ui->label_8->show();
    ui->label_8->raise();
    ui->panorema_cancel->raise();
    m_isMoveView = true;
    show_next_panorama_pic(ui->previewPanorama, "/home/root/panorama_osd_image.bmp", showHeight);
}

void Hp_Panorama::slot_core_key_capture_stop(unsigned char return_value, QString name)
{
    qDebug() << "Hp_Panorama::slot_core_key_capture_stop" << currPicNo << return_value << name;
    if(!this->isVisible())
    {
        return;
    }QString photoNo = name.split("-").at(1);
    photoNo = photoNo.split(".").at(0);
    int photoNoInt = photoNo.toInt();
    if(photoNoInt == currPicNo)
    {
        m_picNameList.append(name);
    }
    if(return_value == RE_OK)
    {
        if(m_matchRet <= 30)
        {
            currPicNo = 0;
        }
        if(currPicNo < 5)
        {
            currPicNo++;
        }
        else if(currPicNo == 5)
        {
            m_isTooLong = true;
            m_dialog.setDialogText(m_previewMsg);
            m_dialog.show();
            return;
        }
        qDebug() << "Hp_Panorama::slot_core_key_capture_stop" << currPicNo << return_value << name <<currPicNo;
        slot_ret_match_panorama();
    }
}


void Hp_Panorama::slot_pc_sys_get_matching_degree(unsigned char return_value, int degree)
{
//    qDebug() << "slot_pc_sys_get_matching_degree" << return_value << degree;
    if(return_value == RE_OK)
    {
        ui->label_degree->setText(QString::number(degree) + "%");
        m_matchRet = degree;

        if(m_degreeTimerStart && this->isVisible())
            signal_pc_sys_get_matching_degree(2);
        else
        {
            if(m_saveCheck)
            {
                m_saveCheck = false;
                signal_check_panorama_photo(true);
            }
        }
    }
}

void Hp_Panorama::slot_cameracap_panorama_errmsg(unsigned char return_value)
{
    if(!m_degreeTimerStart && this->isVisible())
    {
        signal_pc_sys_get_matching_degree(2);
        m_saveCheck = false;
        m_degreeTimerStart = true;
    }

    if(return_value != RE_OK)
    {
        m_dialog.setDialogText(m_picFail);
        m_dialog.show();
    }
//    if(return_value == RE_ERR_STITCHING_IMAGE)
//    {
//        m_dialog.setDialogText("图像拼接失败");
// //        m_dialog.setGeometry(180,160,300,150);
// //        m_dialog.hp_setDefine5_5(true);
//         m_dialog.show();
//     }
//     if(return_value == RE_ERR_STITCHING_MISMATCH)
//     {
//         m_dialog.setDialogText("拼接不匹配");
// //        m_dialog.setGeometry(180,160,300,150);
// //        m_dialog.hp_setDefine5_5(true);
//         m_dialog.show();
//     }
//     if(return_value == RE_ERR_STITCHING_REVERSE)
//     {
//         m_dialog.setDialogText("拼接反向");
// //        m_dialog.setGeometry(180,160,300,150);
// //        if()
// //        m_dialog.hp_setDefine5_5(true);
//        m_dialog.show();
//    }
}

void Hp_Panorama::slot_timer_get_match_degree()
{
}

void Hp_Panorama::slot_ret_match_panorama()
{
    if(m_isTooLong)
    {
        show_preview_panorama();//照片过长结束
    }
    QString background_image_url = "/home/root/panorama_osd_image.bmp";//莫工 凭借完没保存的照片放在这个目录
    ui->widget_2->setGeometry(260, 100, 121, 31);
    if(m_isS3X0)
    {
        ui->widget_2->setGeometry(150, 40, 70, 20);
        show_next_panorama_pic(ui->panoramaView, background_image_url, 53);
    }
    else
    {
        show_next_panorama_pic(ui->panoramaView, background_image_url, 95);
    }
    ui->line->setGeometry(ui->panoramaView->x() + ui->panoramaView->width() , ui->line->y(), 640, 2);
    if(!m_degreeTimerStart && this->isVisible())
    {
        signal_pc_sys_get_matching_degree(2);
        m_degreeTimerStart = true;
    }
}

void Hp_Panorama::show_next_panorama_pic(QLabel* view, QString filaPath, int height)
{
    qDebug() << "file Path" << filaPath << QFile::exists(filaPath) << currPicNo;
    if(!QFile::exists(filaPath))
    {
        return;
    }
    QPixmap pixmap(filaPath);

    double aspectRatio =static_cast<double>(pixmap.height()) / static_cast<double>(pixmap.width());

    // 根据需要调整 QLabel 的大小
    int labelHeight = height;
    int labelWidth = 126 * currPicNo;
    if(m_isS3X0)
        labelWidth = 77 * currPicNo;

    if(m_isMoveView){
        labelWidth = static_cast<int>(labelHeight / aspectRatio); // 根据需要设置宽度
        view->setFixedSize(labelWidth, labelHeight);
        view->setPixmap(pixmap.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio));
    }
    else
    {
        view->setFixedSize(labelWidth, labelHeight);
        view->setPixmap(pixmap.scaled(labelWidth, labelHeight, Qt::IgnoreAspectRatio));
    }
    qDebug() << "Hp_Panorama::show_next_panorama_pic" << labelWidth << labelHeight << aspectRatio;
    view->show();
}

void Hp_Panorama::on_panorema_cancel_clicked()
{
    ui->frame_5->setHidden(false);
    isSavePanorama = false;
    int temp=0;
    temp |= 0x20;
    signal_pc_sys_set_panorama_stop(0);
    for(int i = 0; i < m_picNameList.count(); i++)
    {
        qDebug() << __func__ << m_picNameList.at(i);
        signal_panorama_set_unsave(m_picNameList.at(i));
    }
    over_panorama();
    signal_close_panorama(true);
}

void Hp_Panorama::on_panorema_save_clicked()
{
    isSavePanorama = true;
    int temp=0;
    temp |= 0x20;
    signal_pc_sys_set_panorama_stop(1);
    for(int i = 0; i < m_picNameList.count(); i++)
    {
        qDebug() << m_picNameList.at(i);
    }
    over_panorama();
    ui->frame_5->setHidden(false);
    signal_close_panorama(true);
//    this->close();
}

void Hp_Panorama::over_panorama()
{
    m_degreeTimer->stop();
    m_degreeTimerStart = false;
    m_picNameList.clear();
    ui->panorema_save->hide();
    ui->panorema_cancel->hide();
    ui->panorema_save->hide();
    ui->panorema_cancel->hide();
    ui->previewPanorama->move(640, 0);
    init_panorama();
}

bool Hp_Panorama::getPreviewState()
{
    return m_isMoveView;
}
