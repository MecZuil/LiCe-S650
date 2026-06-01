#include  "hp_display.h"
#include  "ui_mainwidget.h"
#include  "ui_hpdeledit.h"
#include  "ui_hpplredit.h"

Hp_Display::Hp_Display(QWidget *parent) : QWidget(parent)
{
    QString para;
    tmp = 0;
    g_battery = 0;
    m_isPolygonSelectMove = false;
    m_polygonSelectMoveIndex = -1;
    max_point_num = 20;
    max_line_num = 20;
    max_rect_num = 20;
    max_circle_num = 20;
    max_polygon_num = 20;
    m_currSebiao = 0;
    hp_parrent = (MainWidget *)parent;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timer()));

    timerGetRectTemp = new QTimer(this);
    connect(timerGetRectTemp,SIGNAL(timeout()),this,SLOT(slot_timer_get_rect_index()));
    timerGetRectTemp->stop();
    para = hpxmlreader.readXml("sys.xml","EMISSIVITY100","content");
    g_radiance100 = para.toInt();

    para = hpxmlreader.readXml("sys.xml","DISTANCE100","content");
    g_distance100 = para.toInt();

    para = hpxmlreader.readXml("sys.xml","REFLECTTEMP100","content");
    g_ReflectTemp100 = para.toInt();

    para = hpxmlreader.readXml("sys.xml","TEMPPARA","tempunit");
    tempunit = para.toInt();

    hpplredit = new HpPLREdit(this);

    gray_disp = new QLabel(this);
    gray_disp->setGeometry(0,400,640,55);
     QFont ft;
     ft.setPointSize(17);
     gray_disp->setFont(ft);

    gray_disp->setText("");
    gray_disp->setAlignment(Qt::AlignCenter);

    gray_disp->setAutoFillBackground(true);
    gray_disp->setStyleSheet("color:white;");
    gray_disp->close();


    if(hp_point_list.isEmpty())
    {
        pointIndex = 0;
    }
    else
    {
        QListIterator<ComPointPara> i_point(hp_point_list);
        ComPointPara l_hp_point;
        while(i_point.hasNext())
        {
            l_hp_point = i_point.next();
            pointIndex = l_hp_point.point_id;
        }
        pointIndex++;
    }

    if(hp_line_list.isEmpty())
    {
        lineIndex = 0;
    }
    else
    {
        QListIterator<ComLinePara> i_line(hp_line_list);
        ComLinePara l_hp_line;
        while(i_line.hasNext())
        {
            l_hp_line = i_line.next();
            lineIndex = l_hp_line.line_id;
        }
        lineIndex++;
    }
    if(hp_rect_list.isEmpty())
    {
        rectIndex = 0;
    }
    else
    {
        QListIterator<ComRectPara> i_rect(hp_rect_list);
        ComRectPara l_hp_rect;
        while(i_rect.hasNext())
        {
            l_hp_rect = i_rect.next();
            rectIndex = l_hp_rect.rect_id;
        }
        rectIndex++;
    }

    if(hp_circle_list.isEmpty())
    {
        circleIndex = 0;
    }
    else
    {
        QListIterator<ComCirclePara> i_rect(hp_circle_list);
        ComCirclePara l_hp_circle;
        while(i_rect.hasNext())
        {
            l_hp_circle = i_rect.next();
            circleIndex = l_hp_circle.circle_id;
        }
        circleIndex++;
    }

    if(hp_polygon_list.isEmpty())
    {
        polygonIndex = 0;
    }
    bottom_edge = 480;
    drawStatus = -1;
    nowselect.c = DS_NON;
    nowselect.s = -1;

//    define_S6X0_S3X0 = false;
    define_zoom = false;
    define_brightmode = false;
    task_errid = 0;
    m_doubleClickFocusFlag = true;
    m_doubleClickCounter = 0;
    m_isPolygonDraw = false;
    m_isInsulation = false;
    connect(hpdeledit.ui->del,SIGNAL(released()),this,SLOT(del_widget_click()));
    connect(hpdeledit.ui->edit,SIGNAL(released()),this,SLOT(edit_widget_click()));

    connect(hpplredit->ui->hs_distance,SIGNAL(valueChanged(double)),this,SLOT(hs_distance_value_changed(double)));
    connect(hpplredit->ui->hs_radiance,SIGNAL(valueChanged(int)),this,SLOT(hs_radiance_value_changed(int)));
    connect(hpplredit,SIGNAL(SignalRefreshDisplayMaxRect()),this,SLOT(SlotRefreshDisplayMaxRect()));
    connect(hpplredit,SIGNAL(signal_part_radTable_change(int,int)),this,SLOT(slot_part_radTable_change(int,int)));
    connect(hpplredit,SIGNAL(signal_part_radTable_mode(int)),this,SLOT(slot_part_radTable_mode(int)));

    connect(hpplredit->ui->hs_reflect,SIGNAL(valueChanged(double)),this,SLOT(hs_reflect_value_changed(double)));
    connect(hpplredit,SIGNAL(signal_temptype_changed(int)),this,SLOT(cb_temptype_current_index_channed(int)));
    connect(hpplredit->ui->cb_refer,SIGNAL(clicked(bool)),this,SLOT(cb_refer_clicked(bool)));
    connect(hpplredit,SIGNAL(signal_cb_refer_clicked(bool)),this,SLOT(cb_refer_clicked(bool)));
    connect(hpplredit->ui->pb_cancle,SIGNAL(released()),this,SLOT(pb_cancle_clicked()));
    connect(hpplredit->ui->pb_finish,SIGNAL(released()),this,SLOT(pb_finish_clicked()));
//2018.2.27.话框
    mouse_start_x=0;
    mouse_start_y=0;
    mouse_end_x=0;
    mouse_end_y=0;
    mouse_move = false;
    //====2018.4.20   sidian=========
    sketch_state = false;
    hidemenu_rect = false;          //隐藏菜单画框功能开始的判断
    hidemenu_point = false;
    auto_focus = false;
    time_event = false;
    m_filePathState = false;
    m_taskChangeState = false;
    isVisibleLight=false;
    hir_analyse = false;
    hir_stop = true;
    TaskSouldBepaint = true;
    display_aya_infos.clear();
    taskIndex = 0;
    lable_sidian = new QLabel(this);
    define_640_512 = false;

}

void Hp_Display::selectUpdate()
{
    qDebug() << __func__ << nowselect.c;
    if(nowselect.c == DS_POINT || nowselect.c == DS_LINE || nowselect.c == DS_RECT || nowselect.c == DS_CIRCLE || nowselect.c == DS_POLYGON)
    {
        qDebug() << __func__ << __LINE__;
        hpdeledit.hide();
        qDebug() << __func__ << __LINE__;
//        QRect rect = hpdeledit.geometry();
//        QPoint p;
//        ComPointPara cpp;
//        ComLinePara clp;
//        ComRectPara crp;
//        switch(nowselect.c)
//        {
//        case DS_POINT:
//            cpp = hp_point_list.at(nowselect.s);
//            rect.setTopLeft(getTopLeft(QPoint(cpp.p_xcoord,cpp.p_ycoord),hpdeledit.width(),hpdeledit.height()));
//            break;
//        case DS_LINE:
//            clp = hp_line_list.at(nowselect.s);
//            p.setX(qAbs(clp.l_x1coord-clp.l_xcoord)/2+qMin(clp.l_x1coord,clp.l_xcoord));
//            p.setY(qAbs(clp.l_y1coord-clp.l_ycoord)/2+qMin(clp.l_y1coord,clp.l_ycoord));
//            rect.setTopLeft(getTopLeft(p,hpdeledit.width(),hpdeledit.height()));
//            break;
//        case DS_RECT:
//            crp = hp_rect_list.at(nowselect.s);
//            rect.setTopLeft(getTopLeft(QPoint(crp.origin_xcoord+crp.rect_wide/2,crp.origin_ycoord+crp.rect_high/2),hpdeledit.width(),hpdeledit.height()));
//            break;
//        default:
//            break;
//        }
//        hpdeledit.setGeometry(rect);
        qDebug() << __func__ << __LINE__;
        hpdeledit.show();
    }
    else
    {
        hpdeledit.hide();
    }
}

void Hp_Display::hp_list_save()                         //链表保存  clear list_clean
{
    bak_hp_point_list.clear();
    bak_hp_line_list.clear();
    bak_hp_rect_list.clear();
    bak_hp_circle_list.clear();
    bak_hp_polygon_list.clear();

    QListIterator<ComPointPara> i_point(hp_point_list);
    ComPointPara l_hp_point;

    while(i_point.hasNext())
    {
        l_hp_point = i_point.next();
        bak_hp_point_list.append(l_hp_point);
    }

    QListIterator<ComLinePara> i_line(hp_line_list);
    ComLinePara l_hp_line;

    while(i_line.hasNext())
    {
        l_hp_line = i_line.next();
        bak_hp_line_list.append(l_hp_line);
    }

    QListIterator<ComRectPara> i_rect(hp_rect_list);
    ComRectPara l_hp_rect;

    while(i_rect.hasNext())
    {
        l_hp_rect = i_rect.next();
        bak_hp_rect_list.append(l_hp_rect);
    }

    QListIterator<ComCirclePara> i_cir(hp_circle_list);
    ComCirclePara l_hp_circle;

    while(i_cir.hasNext())
    {
        l_hp_circle = i_cir.next();
        bak_hp_circle_list.append(l_hp_circle);
    }
    QListIterator<ComPolygonPara> i_pol(hp_polygon_list);
    ComPolygonPara l_hp_polygon;

    while(i_pol.hasNext())
    {
        l_hp_polygon = i_pol.next();
        bak_hp_polygon_list.append(l_hp_polygon);
    }

    hp_point_list.clear();
    hp_line_list.clear();
    hp_rect_list.clear();
    hp_circle_list.clear();
    hp_polygon_list.clear();

    bak_pointIndex = pointIndex;
    pointIndex=0;
    bak_lineIndex = lineIndex;
    lineIndex = 0;
    bak_rectIndex = rectIndex;
    rectIndex = 0;
    bak_circleIndex = circleIndex;
    circleIndex = 0;
    bak_polygonIndex = polygonIndex;
    polygonIndex = 0;

    update();
}

void Hp_Display::hp_list_restore()                          //链表恢复  list_clean
{
    hp_point_list.clear();
    hp_line_list.clear();
    hp_rect_list.clear();
    hp_circle_list.clear();
    hp_polygon_list.clear();

    QListIterator<ComPointPara> i_point(bak_hp_point_list);
    ComPointPara l_hp_point;

    while(i_point.hasNext())
    {
        l_hp_point = i_point.next();
        hp_point_list.append(l_hp_point);
    }

    QListIterator<ComLinePara> i_line(bak_hp_line_list);
    ComLinePara l_hp_line;

    while(i_line.hasNext())
    {
        l_hp_line = i_line.next();
        hp_line_list.append(l_hp_line);
    }

    QListIterator<ComRectPara> i_rect(bak_hp_rect_list);
    ComRectPara l_hp_rect;

    while(i_rect.hasNext())
    {
        l_hp_rect = i_rect.next();
        hp_rect_list.append(l_hp_rect);
    }

    QListIterator<ComCirclePara> i_cir(bak_hp_circle_list);
    ComCirclePara l_hp_circle;

    while(i_cir.hasNext())
    {
        l_hp_circle = i_cir.next();
        hp_circle_list.append(l_hp_circle);
    }
    QListIterator<ComPolygonPara> i_pol(bak_hp_polygon_list);
    ComPolygonPara l_hp_polygon;

    while(i_pol.hasNext())
    {
        l_hp_polygon = i_pol.next();
        hp_polygon_list.append(l_hp_polygon);
    }
    pointIndex = bak_pointIndex;
    lineIndex = bak_lineIndex;
    rectIndex = bak_rectIndex;
    circleIndex = bak_circleIndex;
    polygonIndex = bak_polygonIndex;

    if(m_filePathState)
    {
        signal_pc_measure_clear();
        for(int i = 0; i < hp_point_list.count(); i++) {
            ComPointPara ll_hp_point = hp_point_list.at(i);
            if(define_zoom)
            {
                if(HP_S350_or_S300)
                {
                    ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                    ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/167;
                }else{
                    ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                    ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/176;
                }
            }//S300部分是正确的
            signal_pc_measure_set_point_add(ll_hp_point);
        }
        for(int i = 0; i < hp_line_list.count(); i++) {
            ComLinePara ll_hp_line = hp_line_list.at(i);
            if(define_zoom)
            {
                if(HP_S350_or_S300)
                {
                    ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                    ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/167;
                    ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                    ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/167;
                }else{
                    ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                    ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/176;
                    ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                    ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/176;
                }
            }//S300部分是正确的
            signal_pc_measure_set_line_add(ll_hp_line);
        }
        for(int i = 0; i < hp_rect_list.count(); i++) {
            ComRectPara l_hp_rect = hp_rect_list.at(i);
            if(define_zoom)
            {
                if(HP_S350_or_S300)
                {
                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
                }else{
                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/176;
                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/176;
                }
            }//S300部分是正确的
            signal_pc_measure_set_rect_add(l_hp_rect);
        }
        for(int i = 0; i < hp_circle_list.count(); i++) {
            ComCirclePara l_hp_circle = hp_circle_list.at(i);
            if( define_zoom )
            {
                l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*167/100;
                l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*167/100;
                l_hp_circle.radius =  l_hp_circle.radius*167/100;
            }
            signal_pc_measure_set_circle_add(l_hp_circle);
        }
        for(int i = 0; i < hp_polygon_list.count(); i++) {
            ComPolygonPara l_hp_polygon = hp_polygon_list.at(i);
            if( define_zoom )
            {
                for(int j = 0; j < l_hp_polygon.nNode; j++)
                {
                    l_hp_polygon.nX[j] = l_hp_polygon.nX[j]*167/100;
                    l_hp_polygon.nY[j] = l_hp_polygon.nY[j]*167/100;
                }
            }
            signal_pc_measure_set_polygon_add(l_hp_polygon);
        }
    }

    signal_dev_get_parameter();             //获取全局变量的信号
    update();
}

void Hp_Display::hp_jpg_read(QString path,QString file)         //图片处理
{
    int tag_num;
    int i = 0;
    qDebug() << "hp_jpg_read" << file;
    //qt编号清零，重新读取图片信息，赋值
    rectIndex = 0;
    lineIndex = 0;
    pointIndex = 0;
    circleIndex = 0;
    polygonIndex = 0;
    hp_point_list.clear();
    hp_line_list.clear();
    hp_rect_list.clear();
    hp_circle_list.clear();
    hp_polygon_list.clear();
    OP_DATA op_data;
    op_data.cmd_type = DS_NON;
    op_data.id = -1;
    signal_pc_measure_active(op_data);
    nowselect.c = DS_NON;
    nowselect.s = -1;
    selectUpdate();

    char bVaild;              //是否存储
    int nID;               //ID号
    int nQt_index;      //qt的编号，以便update
    //**********************新增

    QFile jpg_file_in(file);
    char *p_jpg_data;

    if(!jpg_file_in.open(QIODevice::ReadOnly))
        return ;

    p_jpg_data = (char *)malloc(jpg_file_in.size());
    if(p_jpg_data == NULL)
        return ;

    QDataStream in(&jpg_file_in);
    if(in.readRawData(p_jpg_data,jpg_file_in.size())!= jpg_file_in.size())
        return ;

    int filesize = jpg_file_in.size();

    tagnum_t tag_num_2;
    memcpy((char *)&tag_num_2,p_jpg_data+filesize-sizeof(tagnum_t),sizeof(tagnum_t));
    if(tag_num_2.nTag != TAGNUM_TAG)
        return ;

    taginfo_t tag_info[8];
    memcpy((char *)tag_info,p_jpg_data+filesize-sizeof(tagnum_t)-sizeof(taginfo_t)*tag_num_2.num,sizeof(taginfo_t)*tag_num_2.num);

    image_head_t head;
    memset((char *)&head,0,sizeof(image_head_t));

    for(int i=0;i<tag_num_2.num;i++)
    {
        if(tag_info[i].nTag == FILEINFO_TAG)
        {
            qDebug()<<"read head form jpg";
            int nDesLen = 0;//数据长度
            memcpy((char *)&nDesLen, p_jpg_data + tag_info[i].offset + 4, 4);
            int nLessLen = nDesLen;//拷贝内容长度
//            qDebug() << "’ndesLen" << nDesLen << sizeof(file_info_t);
            if(nDesLen > sizeof(file_info_t))
                nLessLen = sizeof(file_info_t);
            memcpy((char *)&head, p_jpg_data + tag_info[i].offset, nLessLen);

            int nDesLen2 =  0;
            memcpy((char *)&nDesLen2, p_jpg_data + tag_info[i].offset + nDesLen + 4, 4);
            int nLessLen2 = nDesLen2;//拷贝内容长度
            if(nDesLen2 > sizeof(product_info_t))
                nLessLen2 = sizeof(product_info_t);
//            qDebug() << "’nLessLen2" << nLessLen2 << head.file.nDesLen << sizeof(product_info_t);
            memcpy((char *)&head + sizeof(file_info_t), p_jpg_data + tag_info[i].offset + nDesLen, nLessLen2);

            int nDesLen3 = 0;
            memcpy((char *)&nDesLen3, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + 4,4);
            int nLessLen3 = nDesLen3;//拷贝内容长度
            if(nDesLen3 > sizeof(color_info_t))
                nLessLen3 = sizeof(color_info_t);
//            qDebug() << "’nLessLen3" << nLessLen3 << head.product.nDesLen << sizeof(color_info_t);
            memcpy((char *)&head + sizeof(file_info_t) + sizeof(product_info_t),
                   p_jpg_data + tag_info[i].offset + nLessLen2 + nDesLen, nLessLen3);

            int nDesLen4 = 0;
            memcpy((char *)&nDesLen4, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + 4,4);
            int nLessLen4 = nDesLen4;//拷贝内容长度
//            qDebug() << "’nLessLen3" << nLessLen4 << head.color.nDesLen << sizeof(alg_info_t);
            if(nDesLen4 > sizeof(alg_info_t))
                nLessLen4 = sizeof(alg_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(color_info_t),
                   p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3, nLessLen4);


            int nDesLen5 = 0;
            memcpy((char *)&nDesLen5, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + 4,4);
            int nLessLen5 = nDesLen5;//拷贝内容长度
//            qDebug() << "’nLessLen3" << nLessLen5 << head.alg.nDesLen << sizeof(temper_info_t);
            if(nDesLen5 > sizeof(temper_info_t))
                nLessLen5 = sizeof(temper_info_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(alg_info_t) + sizeof(color_info_t),
                   p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4, nLessLen5);

            int nDesLen6 = 0;
            memcpy((char *)&nDesLen6, p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + nDesLen5 + 4, 4);
            int nLessLen6 = nDesLen6;//拷贝内容长度
            qDebug() << "’nLessLen6" << nLessLen6 << sizeof(item_data_t);
            if(nDesLen6 > sizeof(item_data_t))
                nLessLen6 = sizeof(item_data_t);
            memcpy((char *)&head  + sizeof(file_info_t) + sizeof(product_info_t) + sizeof(alg_info_t) + sizeof(color_info_t) + sizeof(temper_info_t),
                   p_jpg_data + tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + nLessLen5, nLessLen6);
            m_pointList.clear();
            m_lineList.clear();
            m_rectList.clear();
            m_circleList.clear();
            m_polygonList.clear();
            int nLessLenAll = tag_info[i].offset + nDesLen + nDesLen2 + nDesLen3 + nDesLen4 + nDesLen5 + nDesLen6;

            int pointCount = head.item.temper_point.item_num;
            for(int indexPoint = 0; indexPoint < pointCount; indexPoint++)
            {
                POINT_PARA_t pointPara;
                memcpy((char *)&pointPara, p_jpg_data + nLessLenAll, sizeof(POINT_PARA_t));
                nLessLenAll += sizeof(POINT_PARA_t);
                m_pointList.append(pointPara);
            }

            int lineCount = head.item.temper_line.item_num;
            for(int indexLine = 0; indexLine < lineCount; indexLine++)
            {
                LINE_PARA_t linePara;
                memcpy((char *)&linePara, p_jpg_data + nLessLenAll, sizeof(LINE_PARA_t));
                nLessLenAll += sizeof(LINE_PARA_t);
                m_lineList.append(linePara);
            }

            int rectCount = head.item.temper_rect.item_num;
            for(int indexRect = 0; indexRect < rectCount; indexRect++)
            {
                RECT_PARA_t rectPara;
                memcpy((char *)&rectPara, p_jpg_data + nLessLenAll, sizeof(RECT_PARA_t));
                m_rectList.append(rectPara);
                nLessLenAll += sizeof(RECT_PARA_t);
            }

            int circleCount = head.item.temper_circle.item_num;
            for(int circleindex = 0; circleindex < circleCount; circleindex++)
            {
                CIRCLE_PARA_t circlePara;
                memcpy((char *)&circlePara, p_jpg_data + nLessLenAll, sizeof(CIRCLE_PARA_t));
                nLessLenAll += sizeof(CIRCLE_PARA_t);
                m_circleList.append(circlePara);
            }

            int polygonCount = head.item.temper_polygon.item_num;
            qDebug() << "polygonCount" << polygonCount;
            for(int polygonindex = 0; polygonindex < polygonCount; polygonindex++)
            {
                POLYGON_PARA_t polygonPara;
                memcpy((char *)&polygonPara, p_jpg_data + nLessLenAll, sizeof(CIRCLE_PARA_t));
                nLessLenAll += sizeof(POLYGON_PARA_t);
                m_polygonList.append(polygonPara);
            }
            jpg_mode = head.alg.nVideoOutState;
            qDebug() << "jpg_mode" << jpg_mode;
            jpg_sebiao = head.color.nColorRuleID;
            memcpy((char *)&pic_temper_info, (char *)&head.temper, sizeof(temper_info_t));
        }
    }
    signal_set_resize_nZoomRate10_value(head.alg.nZoomRate10);      //设置resize放大倍数
    signal_set_nProcessType_value(head.alg.nProcessType, head.alg.nMaxTempHand100, head.alg.nMinTempHand100);    //手动模式最高温最低温

    signal_set_twice_hzh_adjust(head.alg.PIP_nStartX, head.alg.PIP_nStartY, head.alg.PIP_nWidth,head.alg.PIP_nHight);         //画中画画布
    free(p_jpg_data);
    jpg_file_in.close();
    QString str = file;

    QByteArray barray = str.toUtf8();
    //QByteArray barray = str.toLatin1();
    char *mm = barray.data();

    g_picInfo.jpeg_fp = open(mm, O_RDONLY);
    lseek(g_picInfo.jpeg_fp, 0, SEEK_END);              //把“照片文件句柄指针” 移动到文件结尾 0字节处
    lseek(g_picInfo.jpeg_fp, -sizeof(tagnum_t), SEEK_CUR);  //把该指针移动到 离当前位置的 “标签数量结构”大小的位置（-- 应该表示右边）
    read(g_picInfo.jpeg_fp, &g_picInfo.tagnum, sizeof(tagnum_t));  //从“g_picInfo.jpeg_fp”文件指针中 读取  1*（sizeof(tagnum_t)）大小的内容

    if (g_picInfo.tagnum.nTag == TAGNUM_TAG)
    {
        tag_num = g_picInfo.tagnum.num;
    }
    else
    {
        qDebug("TAGNUM error\n");
        ::close(g_picInfo.jpeg_fp);
        return;
    }

    lseek(g_picInfo.jpeg_fp, -sizeof(tagnum_t)-sizeof(taginfo_t)*tag_num, SEEK_CUR);    //移动到当前位置的。。。。处
    read(g_picInfo.jpeg_fp, &g_picInfo.taginfo, sizeof(taginfo_t)*tag_num);    //读取 m 个标签结构体数量的大小

    for (i = 0; i < tag_num; i++)
    {
        if (FILEINFO_TAG == g_picInfo.taginfo[i].nTag)
        {
            lseek(g_picInfo.jpeg_fp, g_picInfo.taginfo[i].offset, SEEK_SET);     //p指针移动到离文件开头（对应标签信息在文件中的便宜）字节处
            read(g_picInfo.jpeg_fp, &g_picInfo.head, sizeof(g_picInfo.head) );    //读取 m 个标签结构体数量的大小
            temper_info_t *ptemper = &head.temper;
            qDebug() << " m_pointList" << m_pointList.count();
            for(int k=0; k < m_pointList.count(); k++)
            {
                bVaild = m_pointList[k].bValid;
                nID = m_pointList[k].nID;
                nQt_index = m_pointList[k].nRealIndex;

//                qDebug() << "bVaild" << bVaild;
                if(bVaild)
                {
                    ComPointPara l_hp_point;

                    l_hp_point.point_id = m_pointList[k].nID;
                    l_hp_point.p_xcoord = m_pointList[k].nX;
                    l_hp_point.p_ycoord = m_pointList[k].nY;
                    l_hp_point.p_distance100 = m_pointList[k].nDistance100;
//                    qDebug() << "l_hp_point.point_id" << l_hp_point.point_id;
//                    qDebug() << "l_hp_point.p_xcoord" << l_hp_point.p_xcoord;
//                    qDebug() << "l_hp_point.p_ycoord" << l_hp_point.p_ycoord;
                    l_hp_point.p_radTable_id = m_pointList[k].nradTable_id;
                    l_hp_point.p_radTable_switch = m_pointList[k].nradTable_switch;
                    l_hp_point.p_radTable_value100 = m_pointList[k].nradTable_value100;
                    l_hp_point.p_radiance100 = m_pointList[k].nradTable100;

                    if(ptemper->reference_para.ReferType == 2)
                    {
                        if(nID == ptemper->reference_para.nRefeTempID)
                        {
                            l_hp_point.refer_flag=1;
                        }else{
                            l_hp_point.refer_flag=0;
                        }
                    }else
                    {
                        l_hp_point.refer_flag=0;
                    }
                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_point.p_xcoord = l_hp_point.p_xcoord*167/100;
                            l_hp_point.p_ycoord = l_hp_point.p_ycoord*167/100;
                        }
                        else{
                            l_hp_point.p_xcoord = l_hp_point.p_xcoord*167/100;
                            l_hp_point.p_ycoord = l_hp_point.p_ycoord*176/100;
                        }
                    }
                    if(define_640_512)
                    {
                        l_hp_point.p_ycoord = l_hp_point.p_ycoord * SCF_Y_CONMUL;
                    }
                    hp_point_list.append(l_hp_point);
                    if(pointIndex < nQt_index)
                        pointIndex = nQt_index;
                }
            }
            if(m_pointList.count() > 0)
                pointIndex++;
            qDebug() << " m_lineList" << m_lineList.count();
            for(int k=0;k<m_lineList.count();k++)
            {
                bVaild = m_lineList[k].bValid;
                nID = m_lineList[k].nID;
                nQt_index = m_lineList[k].nRealIndex;
                if(bVaild)
                {
                    ComLinePara l_hp_line;
//                    qDebug() << "nStartX" << m_lineList[k].nStartX << "nStartY" << m_lineList[k].nStartY << "nEndX" << m_lineList[k].nEndX << "nEndY" << m_lineList[k].nEndY;
                    l_hp_line.line_id = m_lineList[k].nID;
                    l_hp_line.l_xcoord = m_lineList[k].nStartX;
                    l_hp_line.l_ycoord = m_lineList[k].nStartY;
                    l_hp_line.l_x1coord = m_lineList[k].nEndX;
                    l_hp_line.l_y1coord = m_lineList[k].nEndY;
                    l_hp_line.l_distance100 = m_lineList[k].nDistance100;
                    l_hp_line.l_temptype = m_lineList[k].nTempType;
                    l_hp_line.l_ReflectTemp100 = m_lineList[k].nReflectTemp100;

                    l_hp_line.l_radTable_id = m_lineList[k].nradTable_id;
                    l_hp_line.l_radTable_switch = m_lineList[k].nradTable_switch;
                    l_hp_line.l_radTable_value100 = m_lineList[k].nradTable_value100;
                    l_hp_line.l_radiance100  = m_lineList[k].nradTable100;

                    if(ptemper->reference_para.ReferType ==4)
                    {
                        if(nID ==ptemper->reference_para.nRefeTempID)
                        {
                            //                           qDebug( )<<"222";
                            l_hp_line.refer_flag=1;
                        }else{
                            l_hp_line.refer_flag=0;
                        }
                    }else
                    {
                        l_hp_line.refer_flag=0;
                    }
                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_line.l_xcoord = l_hp_line.l_xcoord*167/100;
                            l_hp_line.l_ycoord = l_hp_line.l_ycoord*167/100;
                            l_hp_line.l_x1coord = l_hp_line.l_x1coord*167/100;
                            l_hp_line.l_y1coord = l_hp_line.l_y1coord*167/100;
                        }
                        else{
                            l_hp_line.l_xcoord = l_hp_line.l_xcoord*167/100;
                            l_hp_line.l_ycoord = l_hp_line.l_ycoord*176/100;
                            l_hp_line.l_x1coord = l_hp_line.l_x1coord*167/100;
                            l_hp_line.l_y1coord = l_hp_line.l_y1coord*176/100;
                        }
                    }

                    if(define_640_512)
                    {
                        l_hp_line.l_ycoord = l_hp_line.l_ycoord * SCF_Y_CONMUL;
                        l_hp_line.l_y1coord = l_hp_line.l_y1coord * SCF_Y_CONMUL;
                    }
                    hp_line_list.append(l_hp_line);
                    if(lineIndex < nQt_index)
                        lineIndex = nQt_index;
                }
            }
            if(m_lineList.count() > 0)
                lineIndex++;
            //          qDebug()<<"\n=================RECT====================";

//            qDebug() << " m_rectList" << m_rectList.count();
            for(int k=0; k < m_rectList.count(); k++)
            {
                bVaild = m_rectList[k].bValid;
                nID = m_rectList[k].nID;
                nQt_index = m_rectList[k].nRealIndex;

//                qDebug() << " m_rectList" << m_rectList[k].nID << m_rectList[k].nRealIndex << bVaild;
                if(bVaild)
                {
                    ComRectPara l_hp_rect;

                    l_hp_rect.rect_id = m_rectList[k].nID;
                    l_hp_rect.temptype = m_rectList[k].nTempType;
                    l_hp_rect.origin_xcoord = m_rectList[k].nStartX;
                    l_hp_rect.origin_ycoord = m_rectList[k].nStartY;
                    l_hp_rect.rect_wide = m_rectList[k].nWidth;
                    l_hp_rect.rect_high = m_rectList[k].nHeight;
                    l_hp_rect.r_radiance100 = m_rectList[k].nEmissivity100;
                    l_hp_rect.rect_distance100 = m_rectList[k].nDistance100;
                    l_hp_rect.rect_ReflectTemp100 = m_rectList[k].nReflectTemp100;

                    l_hp_rect.r_radTable_id = m_rectList[k].nradTable_id;
                    l_hp_rect.r_radTable_switch = m_rectList[k].nradTable_switch;
                    l_hp_rect.r_radTable_value100 = m_rectList[k].nradTable_value100;
                    l_hp_rect.r_radiance100  = m_rectList[k].nradTable100;

                    //                   qDebug( )<<"nQt_index"<<ptemper->reference_para.nRefeTempID;
                    if(ptemper->reference_para.ReferType ==3)
                    {
                        if(nID ==ptemper->reference_para.nRefeTempID)
                        {
                            l_hp_rect.refer_flag=1;
                        }else{
                            l_hp_rect.refer_flag=0;
                        }
                    }else
                    {
                        l_hp_rect.refer_flag=0;
                    }
                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*167/100;
                            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*167/100;
                            l_hp_rect.rect_wide = l_hp_rect.rect_wide*167/100;
                            l_hp_rect.rect_high = l_hp_rect.rect_high*167/100;
                        }else{
                            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*167/100;
                            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*176/100;
                            l_hp_rect.rect_wide = l_hp_rect.rect_wide*167/100;
                            l_hp_rect.rect_high = l_hp_rect.rect_high*176/100;
                        }
                    }
                    if(define_640_512)
                    {
                        l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*SCF_Y_CONMUL;
                        l_hp_rect.rect_high = l_hp_rect.rect_high*SCF_Y_CONMUL;
                    }
                    hp_rect_list.append(l_hp_rect);
                    if(rectIndex < nQt_index)
                        rectIndex = nQt_index;
                }
            }
            if(m_rectList.count() > 0)
                rectIndex++;
            for(int k=0; k < m_circleList.count(); k++)
            {
                bVaild = m_circleList[k].bValid;
                nID = m_circleList[k].nID;
                nQt_index = m_circleList[k].bRealIndex;

                qDebug() << " m_circleList" << m_circleList[k].nID << m_circleList[k].bRealIndex << bVaild;
                if(bVaild)
                {
                    ComCirclePara l_hp_circle;

                    l_hp_circle.circle_id = m_circleList[k].nID;
                    l_hp_circle.c_temptype = m_circleList[k].nTempType;
                    l_hp_circle.center_xcoord = m_circleList[k].nX;
                    l_hp_circle.center_ycoord = m_circleList[k].nY;
                    l_hp_circle.radius = m_circleList[k].nR;
                    l_hp_circle.c_distance100 = m_circleList[k].nDistance100;
                    l_hp_circle.c_radiance100 = m_circleList[k].nEmissivity100;
                    l_hp_circle.c_ReflectTemp100 = m_circleList[k].nReflectTemp100;
                    l_hp_circle.c_radTable_id = m_circleList[k].bradTable_id;
                    l_hp_circle.c_radTable_switch = m_circleList[k].bradTable_switch;
                    l_hp_circle.c_radTable_value100 = m_circleList[k].bradTable_value100;
                    if(ptemper->reference_para.ReferType ==3)
                    {
                        if(nID ==ptemper->reference_para.nRefeTempID)
                        {
                            l_hp_circle.refer_flag=1;
                        }else{
                            l_hp_circle.refer_flag=0;
                        }
                    }else
                    {
                        l_hp_circle.refer_flag=0;
                    }

                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_circle.center_xcoord = m_circleList[k].nX*167/100;
                            l_hp_circle.center_ycoord = m_circleList[k].nY*167/100;
                            l_hp_circle.radius =  m_circleList[k].nR*167/100;
                        }else{
                            l_hp_circle.center_xcoord = m_circleList[k].nX*167/100;
                            l_hp_circle.center_ycoord = m_circleList[k].nY*167/100;
                            l_hp_circle.radius =  m_circleList[k].nR*167/100;
                        }
                    }
                    hp_circle_list.append(l_hp_circle);
                    if(rectIndex < nQt_index)
                        rectIndex = nQt_index;
                }
            }

            for(int k=0; k < m_polygonList.count(); k++)
            {
                bVaild = true;
                nID = m_polygonList[k].nID;
                nQt_index = m_polygonList[k].nRealIndex;

                if(bVaild)
                {
                    ComPolygonPara l_hp_polygon;

                    l_hp_polygon.polygon_id = m_polygonList[k].nID;
                    l_hp_polygon.p_temptype = m_polygonList[k].nTempType;
                    l_hp_polygon.nNode = m_polygonList[k].nNode;
                    for(int pIndex = 0; pIndex < l_hp_polygon.nNode; pIndex++)
                    {
                        l_hp_polygon.nX[pIndex] = m_polygonList[k].nX[pIndex];
                        l_hp_polygon.nY[pIndex] = m_polygonList[k].nY[pIndex];
                        if( define_zoom )
                        {
                            l_hp_polygon.nX[pIndex] = l_hp_polygon.nX[pIndex] * 167/100;
                            l_hp_polygon.nY[pIndex] = l_hp_polygon.nY[pIndex] * 167/100;
                        }
                    }
                    l_hp_polygon.p_distance100 = m_polygonList[k].nDistance100;
                    l_hp_polygon.p_radiance100 = m_polygonList[k].nEmissivity100;
                    l_hp_polygon.p_ReflectTemp100 = m_polygonList[k].nReflectTemp100;
                    l_hp_polygon.p_radTable_id = m_polygonList[k].nradTable_id;
                    l_hp_polygon.p_radTable_switch = m_polygonList[k].nradTable_switch;
                    l_hp_polygon.p_radTable_value100 = m_polygonList[k].nradTable_value100;
                    if(ptemper->reference_para.ReferType == 4)
                    {
                        if(nID == ptemper->reference_para.nRefeTempID)
                        {
                            l_hp_polygon.refer_flag=1;
                        }else{
                            l_hp_polygon.refer_flag=0;
                        }
                    }else
                    {
                        l_hp_polygon.refer_flag=0;
                    }

                    hp_polygon_list.append(l_hp_polygon);
                    if(rectIndex < nQt_index)
                        rectIndex = nQt_index;
                }
            }
            //需要加多边形
            qDebug() << "head.alg.bTempCapture" << head.alg.bTempCapture;
            if( head.alg.bTempCapture == 1)
            {
                signal_JPGTemCaptrue_Switch(1);
            }
            else
            {
                signal_JPGTemCaptrue_Switch(0);
            }
        }
    }
    ::close(g_picInfo.jpeg_fp);


}

temper_info_t Hp_Display::get_jpg_wdxz()
{
    return pic_temper_info;
}

void Hp_Display::UpdatePMSRect()//目前默认就一个矩形
{
    display_aya_infos.clear();
    hp_point_list.clear();
    hp_line_list.clear();
    hp_rect_list.clear();
    signal_pc_measure_clear();

    int rect_id = 0;

    ANA_OUTLINE ana_ret;//暂时没用
    ana_ret.ana_type[0] = 'R';
    ana_ret.deviceType[0] = 'B';
    ana_ret.deviceType[1] = 'T';

    ComRectPara l_hp_rect;
    strncpy(l_hp_rect.deviceType, ana_ret.deviceType, 2);//rect BT ; line JT ; point SQ ;
    l_hp_rect.origin_xcoord = 100;
    l_hp_rect.origin_ycoord = 100;
    l_hp_rect.rect_wide = 440;
    l_hp_rect.rect_high = 280;
    l_hp_rect.rect_id = rect_id++;
    l_hp_rect.refer_flag = 0;
    l_hp_rect.rect_distance100 = g_distance100;
    l_hp_rect.rect_ReflectTemp100 = g_ReflectTemp100;
    l_hp_rect.r_radiance100 = g_radiance100;
    l_hp_rect.r_radTable_switch = g_radTable_switch;
    l_hp_rect.r_radTable_id = g_radTable_id;
    l_hp_rect.r_radTable_value100 = g_radTable_value100;
    l_hp_rect.temptype = 0;
    if(define_zoom)
    {
        if(HP_S350_or_S300)
        {
            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
            l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
            l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
        }else{
            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/176;
            l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
            l_hp_rect.rect_high =  l_hp_rect.rect_high*100/176;
        }

         signal_pc_measure_set_rect_add(l_hp_rect);
    }else
    {
         signal_pc_measure_set_rect_add(l_hp_rect);
    }
//    hp_rect_list.append(l_hp_rect);//无需选中

    ana_ret.id = l_hp_rect.rect_id;
    ana_ret.origin_xcoord = l_hp_rect.origin_xcoord;
    ana_ret.origin_ycoord = l_hp_rect.origin_ycoord;
    ana_ret.dest_xcoord = l_hp_rect.origin_xcoord + l_hp_rect.rect_wide;
    ana_ret.dest_ycoord = l_hp_rect.origin_ycoord + l_hp_rect.rect_high;

//    display_aya_infos << ana_ret;

    update();
}

void Hp_Display::UpdateTaskRect(QVector<ANA_OUTLINE> ana_infos)
{
    qDebug() << " --UpdateTaskRect-- " << m_taskChangeState;
    if(m_taskChangeState){//当处于改变时，不允许再次被改变
        return;
    }
    m_taskChangeState = true;
    display_aya_infos.clear();
    hp_point_list.clear();
    hp_line_list.clear();
    hp_rect_list.clear();
    display_aya_infos = ana_infos;//拷贝数据
    signal_pc_measure_clear();

    int point_id = 0;
    int line_id = 0;
    int rect_id = 0;

    //尹工那借的仪器用的屏幕是640*480底层为384*288的，所以要经过像素转化
    //但此时多了一个维度，也就是pc软件传给我的台账图片，图片大小为384*288
    //目前有三个维度    qt(640*480) -- 台账(384*288) -- 底层(384*288)
    //为了解决在屏幕中点击能选中正确的形状，此时要将台账图片中的点线框转化为640*480大小，存入链表当中
    //所以就如下就多了一步转化过程

    qDebug() << "define_zoom == HP_S350_or_S300 == > " << define_zoom << " ; " << HP_S350_or_S300;

    //但是改动后尹工那边说台账界面不需要有选择功能，所以把添加入链表这一个步骤去掉
    for(int i = 0; i < ana_infos.count(); i++)           //3.绘制点线
    {
        if(ana_infos.at(i).ana_type[0] == 'P')//这里缺一个转换
        {
            qDebug() << i << ": --P-- point id: " << point_id;
            ComPointPara ll_hp_point;
            strncpy(ll_hp_point.deviceType, ana_infos.at(i).deviceType, 2);
            ll_hp_point.p_xcoord = ana_infos.at(i).origin_xcoord;
            ll_hp_point.p_ycoord = ana_infos.at(i).origin_ycoord;
            if(define_640_512)
                ll_hp_point.p_ycoord = ana_infos.at(i).origin_ycoord * 1.07;
            ll_hp_point.point_id = point_id++;
            display_aya_infos[i].id = ll_hp_point.point_id;
            ll_hp_point.refer_flag = 0;
            ll_hp_point.p_distance100 = g_distance100;
            ll_hp_point.p_radiance100 = g_radiance100;
            ll_hp_point.p_radTable_switch = g_radTable_switch;
            ll_hp_point.p_radTable_id = g_radTable_id;
            ll_hp_point.p_radTable_value100 = g_radTable_value100;
            //以下转化为   台账-->Qt
            ComPointPara ll_hp_point_ret;
            strncpy(ll_hp_point_ret.deviceType, ll_hp_point.deviceType, 2);
            ll_hp_point_ret.p_xcoord = ll_hp_point.p_xcoord;
            ll_hp_point_ret.p_ycoord = ll_hp_point.p_ycoord;
            ll_hp_point_ret.point_id = ll_hp_point.point_id;
            ll_hp_point_ret.refer_flag = 0;
            ll_hp_point_ret.p_distance100 = g_distance100;
            ll_hp_point_ret.p_radiance100 = g_radiance100;
            ll_hp_point_ret.p_radTable_switch = g_radTable_switch;
            ll_hp_point_ret.p_radTable_id = g_radTable_id;
            ll_hp_point_ret.p_radTable_value100 = g_radTable_value100;
            //点击框图，查看是否选中，可检查是 台账-->Qt转化错误  还是 台账-->底层转化错误
//            if( define_zoom )//设置台账内无法选中
//            {
//                if(HP_S350_or_S300)
//                {
//                    ll_hp_point_ret.p_xcoord = ll_hp_point_ret.p_xcoord*167/100;
//                    ll_hp_point_ret.p_ycoord = ll_hp_point_ret.p_ycoord*167/100;
//                }
//                else{
//                    ll_hp_point_ret.p_xcoord = ll_hp_point_ret.p_xcoord*167/100;
//                    ll_hp_point_ret.p_ycoord = ll_hp_point_ret.p_ycoord*176/100;
//                }
//            }//S300部分是正确的
//            hp_point_list.append(ll_hp_point_ret);
            //以下转化为   台账-->底层
            if(this->width() == 384 && this->height() == 272)//S300特殊
            {
                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/167;
            }else if(define_zoom)//S350  OK
            {
                if(HP_S350_or_S300)
                {
                    ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                    ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/167;
                }else{
                    ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                    ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/106;
                }
            }
            else if(define_640_512)
            {
                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*1.07;
            }
            signal_pc_measure_set_point_add(ll_hp_point);
        }else if(ana_infos.at(i).ana_type[0] == 'L'){
            qDebug() << i << ": --L-- line id: " << line_id;
            ComLinePara ll_hp_line;
//            QByteArray name = point.name.toLatin1();
            strncpy(ll_hp_line.name, ana_infos.at(i).deviceType, 2);
            ll_hp_line.l_xcoord = ana_infos.at(i).origin_xcoord;
            ll_hp_line.l_ycoord = ana_infos.at(i).origin_ycoord;
            ll_hp_line.l_x1coord = ana_infos.at(i).dest_xcoord;
            ll_hp_line.l_y1coord = ana_infos.at(i).dest_ycoord;
            //ll_hp_line.l_temptype = ana_infos.at(i).temptype;
            ll_hp_line.line_id = line_id++;
            display_aya_infos[i].id = ll_hp_line.line_id;
            ll_hp_line.refer_flag = 0;
            ll_hp_line.l_distance100 = g_distance100;
            ll_hp_line.l_radiance100 = g_radiance100;
            ll_hp_line.l_radTable_switch = g_radTable_switch;
            ll_hp_line.l_radTable_id = g_radTable_id;
            ll_hp_line.l_radTable_value100 = g_radTable_value100;
            ll_hp_line.l_ReflectTemp100 = g_ReflectTemp100;
            ll_hp_line.l_temptype = 0;
            //以下转化为   台账-->Qt
            ComLinePara l_hp_line_ret = ll_hp_line;
            strncpy(l_hp_line_ret.name, ll_hp_line.name, 2);
            l_hp_line_ret.l_xcoord = ll_hp_line.l_xcoord;
            l_hp_line_ret.l_ycoord = ll_hp_line.l_ycoord;
            l_hp_line_ret.l_x1coord = ll_hp_line.l_x1coord;
            l_hp_line_ret.l_y1coord = ll_hp_line.l_y1coord;
            l_hp_line_ret.line_id = ll_hp_line.line_id;
            l_hp_line_ret.refer_flag = 0;
            l_hp_line_ret.l_distance100 = g_distance100;
            l_hp_line_ret.l_radiance100 = g_radiance100;
            l_hp_line_ret.l_radTable_switch = g_radTable_switch;
            l_hp_line_ret.l_radTable_id = g_radTable_id;
            l_hp_line_ret.l_radTable_value100 = g_radTable_value100;
            l_hp_line_ret.l_ReflectTemp100 = g_ReflectTemp100;
            l_hp_line_ret.l_temptype = 0;
//            if( define_zoom )
//            {
//                if(HP_S350_or_S300)
//                {
//                    l_hp_line_ret.l_xcoord = l_hp_line_ret.l_xcoord*167/100;
//                    l_hp_line_ret.l_ycoord = l_hp_line_ret.l_ycoord*167/100;
//                    l_hp_line_ret.l_x1coord = l_hp_line_ret.l_x1coord*167/100;
//                    l_hp_line_ret.l_y1coord = l_hp_line_ret.l_y1coord*167/100;
//                }
//                else{
//                    l_hp_line_ret.l_xcoord = l_hp_line_ret.l_xcoord*167/100;
//                    l_hp_line_ret.l_ycoord = l_hp_line_ret.l_ycoord*176/100;
//                    l_hp_line_ret.l_x1coord = l_hp_line_ret.l_x1coord*167/100;
//                    l_hp_line_ret.l_y1coord = l_hp_line_ret.l_y1coord*176/100;
//                }
//            }
//            hp_line_list.append(l_hp_line_ret);
            //以下转化为   台账-->底层
            if(this->width() == 384 && this->height() == 272)//S300特殊
            {
                ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/167;
                ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/167;
            }else if(define_zoom)//S350  OK
            {
                if(HP_S350_or_S300)
                {
                    ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                    ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/167;
                    ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                    ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/167;
                }else{
                    ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                    ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/176;
                    ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                    ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/176;
                }
            }
            if(define_640_512)
            {
                ll_hp_line.l_ycoord =ll_hp_line.l_ycoord * 1.07;
                ll_hp_line.l_y1coord = ll_hp_line.l_y1coord * 1.07;
            }
            signal_pc_measure_set_line_add(ll_hp_line);
        }else if(ana_infos.at(i).ana_type[0] == 'R'){
            qDebug()  << i << ": --R-- rect id: " << rect_id;
            ComRectPara l_hp_rect;
//            QByteArray name = point.name.toLatin1();
            strncpy(l_hp_rect.deviceType, ana_infos.at(i).deviceType, 2);
            l_hp_rect.origin_xcoord = ana_infos.at(i).origin_xcoord;
            l_hp_rect.origin_ycoord = ana_infos.at(i).origin_ycoord;
            l_hp_rect.rect_wide = qAbs(ana_infos.at(i).dest_xcoord - ana_infos.at(i).origin_xcoord);
            l_hp_rect.rect_high = qAbs(ana_infos.at(i).dest_ycoord - ana_infos.at(i).origin_ycoord);
            if(l_hp_rect.origin_xcoord >= 0 && l_hp_rect.origin_ycoord >= 0) {
                if(l_hp_rect.rect_wide < MIN_RECT_WIDTH)
                    l_hp_rect.rect_wide = MIN_RECT_WIDTH;
                if(l_hp_rect.rect_high < MIN_RECT_HEIGHT)
                    l_hp_rect.rect_high = MIN_RECT_HEIGHT;
            }
            //l_hp_rect.temptype = ana_infos.at(i).temptype;
            l_hp_rect.rect_id = rect_id++;
            display_aya_infos[i].id = l_hp_rect.rect_id;
            l_hp_rect.refer_flag = 0;
            l_hp_rect.rect_distance100 = g_distance100;
            l_hp_rect.rect_ReflectTemp100 = g_ReflectTemp100;
            l_hp_rect.r_radiance100 = g_radiance100;
            l_hp_rect.r_radTable_switch = g_radTable_switch;
            l_hp_rect.r_radTable_id = g_radTable_id;
            l_hp_rect.r_radTable_value100 = g_radTable_value100;
            l_hp_rect.temptype = 0;//这句一定要加？？？
            l_hp_rect.remapping_color_id = m_currSebiao;
            l_hp_rect.remapping_switch = 0;
//            qDebug() << "Analyse == > " << l_hp_rect.origin_xcoord << " , " << l_hp_rect.origin_ycoord;
            //以下转化为   台账-->Qt
            ComRectPara l_hp_rect_ret = l_hp_rect;
            l_hp_rect_ret.origin_xcoord = l_hp_rect.origin_xcoord;
            l_hp_rect_ret.origin_ycoord = l_hp_rect.origin_ycoord;
            l_hp_rect_ret.rect_wide = l_hp_rect.rect_wide;
            l_hp_rect_ret.rect_high = l_hp_rect.rect_high;
            l_hp_rect_ret.rect_id = l_hp_rect.rect_id;
            l_hp_rect_ret.refer_flag = 0;
            l_hp_rect_ret.rect_distance100 = g_distance100;
            l_hp_rect_ret.rect_ReflectTemp100 = g_ReflectTemp100;
            l_hp_rect_ret.r_radiance100 = g_radiance100;
            l_hp_rect_ret.r_radTable_switch = g_radTable_switch;
            l_hp_rect_ret.r_radTable_id = g_radTable_id;
            l_hp_rect_ret.r_radTable_value100 = g_radTable_value100;
            l_hp_rect_ret.temptype = l_hp_rect.temptype;
            l_hp_rect_ret.remapping_color_id = l_hp_rect.remapping_color_id;
            l_hp_rect_ret.remapping_switch = l_hp_rect.remapping_switch;
//            if( define_zoom )
//            {
//                if(HP_S350_or_S300)
//                {
//                    l_hp_rect_ret.origin_xcoord = l_hp_rect_ret.origin_xcoord*167/100;
//                    l_hp_rect_ret.origin_ycoord = l_hp_rect_ret.origin_ycoord*167/100;
//                    l_hp_rect_ret.rect_wide = l_hp_rect_ret.rect_wide*167/100;
//                    l_hp_rect_ret.rect_high = l_hp_rect_ret.rect_high*167/100;
//                }else{
//                    l_hp_rect_ret.origin_xcoord = l_hp_rect_ret.origin_xcoord*167/100;
//                    l_hp_rect_ret.origin_ycoord = l_hp_rect_ret.origin_ycoord*176/100;
//                    l_hp_rect_ret.rect_wide = l_hp_rect_ret.rect_wide*167/100;
//                    l_hp_rect_ret.rect_high = l_hp_rect_ret.rect_high*176/100;
//                }
//            }
//            hp_rect_list.append(l_hp_rect_ret);
            //以下转化为   台账-->底层
            if(this->width() == 384 && this->height() == 272)//S300特殊
            {
                l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
            }else if(define_zoom)//S350  OK
            {
                if(HP_S350_or_S300)
                {
                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
                }else{
                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/106;
                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/106;
                }
            }

            signal_pc_measure_set_rect_add(l_hp_rect);
        }
    }
    m_taskChangeState = false;
    update();
}
int Hp_Display::get_jpg_mode()
{
    return jpg_mode;
}

int Hp_Display::get_jpg_sebiao()
{
    return jpg_sebiao;
}

void Hp_Display::clear_reference_set()
{
    int i;
    QListIterator<ComPointPara> i_point(hp_point_list);
    ComPointPara l_hp_point;

    i=0;
    while(i_point.hasNext())
    {
        l_hp_point = i_point.next();

        if(l_hp_point.refer_flag == 1)
        {
            l_hp_point.refer_flag = 0;
            hp_point_list.replace(i,l_hp_point);
        }
        i++;
    }



    QListIterator<ComLinePara> i_line(hp_line_list);
    ComLinePara l_hp_line;

    i=0;
    while(i_line.hasNext())
    {
        l_hp_line = i_line.next();

        if(l_hp_line.refer_flag == 1)//
        {
            l_hp_line.refer_flag = 0;//
            hp_line_list.replace(i,l_hp_line);
        }
        i++;
    }

    QListIterator<ComRectPara> i_rect(hp_rect_list);
    ComRectPara l_hp_rect;

    i=0;
    while(i_rect.hasNext())
    {
        l_hp_rect = i_rect.next();
        if(l_hp_rect.refer_flag == 1)
        {
            l_hp_rect.refer_flag = 0;
            hp_rect_list.replace(i,l_hp_rect);
        }
        i++;
    }
    QListIterator<ComCirclePara> i_cir(hp_circle_list);
    ComCirclePara l_hp_circle;

    i=0;
    while(i_cir.hasNext())
    {
        l_hp_circle = i_cir.next();
        if(l_hp_circle.refer_flag == 1)
        {
            l_hp_circle.refer_flag = 0;
            hp_circle_list.replace(i,l_hp_circle);
        }
        i++;
    }
    QListIterator<ComPolygonPara> i_pol(hp_polygon_list);
    ComPolygonPara l_hp_polygon;

    i=0;
    while(i_pol.hasNext())
    {
        l_hp_polygon = i_pol.next();
        if(l_hp_polygon.refer_flag == 1)
        {
            l_hp_polygon.refer_flag = 0;
            hp_polygon_list.replace(i,l_hp_polygon);
        }
        i++;
    }
}

QPoint Hp_Display::getTopLeft(QPoint p, int width, int height)
{
    QPoint rp;
    int mm = 10;
    if(p.x()<this->width()/2 && p.y() < this->height()/2)
    {
        rp = p;
        rp+=QPoint(mm,mm);
        qDebug("getTopLeft:0");
    }
    if(p.x()>this->width()/2 && p.y() < this->height()/2)
    {
        rp.setX(p.x()-width-mm);
        rp.setY(p.y()+mm);
        qDebug("getTopLeft:0");
    }

    if(p.x()<this->width()/2 && p.y() > this->height()/2)
    {
        rp.setX(p.x()+mm);
        rp.setY(p.y()-height-mm);
        qDebug("getTopLeft:0");
    }

    if(p.x()>this->width()/2 && p.y() > this->height()/2)
    {
        rp.setX(p.x()-width-mm);
        rp.setY(p.y()-height-mm);
        qDebug("getTopLeft:0");
    }

    qDebug()<<p<<rp;
    return rp;
}

void Hp_Display::delete_item()
{

    if(nowselect.c == DS_POINT || nowselect.c == DS_LINE || nowselect.c == DS_RECT || nowselect.c == DS_CIRCLE || nowselect.c == DS_POLYGON)
    {
        switch(nowselect.c)
        {
        case DS_POINT:
            signal_pc_measure_set_point_del(hp_point_list.at(nowselect.s));
            hp_point_list.removeAt(nowselect.s);
            break;
        case DS_LINE:
            signal_pc_measure_set_line_del(hp_line_list.at(nowselect.s));
            hp_line_list.removeAt(nowselect.s);
            break;
        case DS_RECT:
            signal_pc_measure_set_rect_del(hp_rect_list.at(nowselect.s));
            hp_rect_list.removeAt(nowselect.s);
            getMaxRect();
            break;
        case DS_CIRCLE:
            signal_pc_measure_set_circle_del(hp_circle_list.at(nowselect.s));
            hp_circle_list.removeAt(nowselect.s);

            break;
        case DS_POLYGON:
            signal_pc_measure_set_polygon_del(hp_polygon_list.at(nowselect.s));
            hp_polygon_list.removeAt(nowselect.s);
            break;
        }

        //=======================
        // qt->core not select
        OP_DATA op_data;

        op_data.cmd_type = DS_NON;
        op_data.id = -1;

        signal_pc_measure_active(op_data);
        //==============================

        nowselect.c = DS_NON;
        nowselect.s = -1;
        update();
    }
}

void Hp_Display::clear_selecte_status()
{
//    qDebug() << " clear select--  -- statuse === > " << nowselect.c;
    if(nowselect.c != DS_NON)
    {
        OP_DATA op_data;
        op_data.cmd_type = DS_NON;
        op_data.id = -1;
        signal_pc_measure_active(op_data);


        nowselect.c = DS_NON;
        nowselect.s = -1;
        update();
        selectUpdate();
    }
}

void Hp_Display::clear_measure()
{
    if(hp_point_list.isEmpty() && hp_line_list.isEmpty() && hp_rect_list.isEmpty() && hp_circle_list.isEmpty() && hp_polygon_list.isEmpty())
        return;

    m_selectInsValueMap.clear();
    m_selectIdRectIdMap.clear();
    signal_show_insulation_warning(false, -1, 0, 0);
    hp_point_list.clear ();
    hp_line_list.clear ();
    hp_rect_list.clear ();
    hp_circle_list.clear ();
    hp_polygon_list.clear ();
    pointIndex=0;
    lineIndex = 0;
    rectIndex = 0;
    circleIndex = 0;
    polygonIndex = 0;
    getMaxRect();
    signal_pc_measure_clear();
    update();
}
void Hp_Display::Task_clear_measure()
{
    signal_pc_measure_clear();
    m_filePath.clear();
    update();
}

void Hp_Display::clear_circle()
{
    for(int i = 0; i < hp_circle_list.count(); i++)
    {
        signal_pc_measure_set_circle_del(hp_circle_list.at(i));
    }

    hp_circle_list.clear();
}

void Hp_Display::clear_measure2()
{
    qDebug()<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee3";
   if(hp_point_list.isEmpty() && hp_line_list.isEmpty() && hp_rect_list.isEmpty())
   {
        qDebug()<<"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee4";
       return;
   }

   m_selectInsValueMap.clear();
   m_selectIdRectIdMap.clear();
   signal_show_insulation_warning(false, -1, 0, 0);
   for(int i=0;i<100;i++)
   {
       points[i]=-1;
       lines[i]=-1;
       rects[i]=-1;
       circles[i]=-1;
       points1[i]=-1;
       lines1[i]=-1;
       rects1[i]=-1;
       circles1[i]=-1;
   }
   point_id=0;
   line_id=0;
   rect_id=0;
   circle_id=0;
   pointIndex=0;
   lineIndex = 0;
   rectIndex = 0;
   circleIndex = 0;
   hp_point_list.clear ();
   hp_line_list.clear ();
   hp_rect_list.clear ();
   hp_circle_list.clear ();
   update();
}


void Hp_Display::slot_pc_sys_get_standard(unsigned char return_value, StandardInfo msg)
{
//    double f[6];
//    QString s[6],str;


//    f[0] = msg.ch1100/100.0;
//    f[1] = msg.ch2100/100.0;
//    f[2] = msg.ch3100/100.0;
//    f[3] = msg.ch4100/100.0;
//    f[4] = msg.ch5100/100.0;
//    f[5] = msg.ch6100/100.0;

//    s[0] = QString::number(f[0],'f',2);
//    s[1] = QString::number(f[1],'f',2);
//    s[2] = QString::number(f[2],'f',2);
//    s[3] = QString::number(f[3],'f',2);
//    s[4] = QString::number(f[4],'f',2);
//    s[5] = QString::number(f[5],'f',2);

//    str = "";
//    for(int i=0;i<5;i++)
//    {
//        str += s[i];
//        str +=" ";
//    }

//    gray_disp->setText(str);
}

void Hp_Display::slot_pc_measure_active(unsigned char return_value)
{
    qDebug("slot_pc_measure_active:return_value:0x%02x",return_value);

}

void Hp_Display::slot_pc_measure_clear(unsigned char return_value)
{
    qDebug("slot_pc_measure_clear:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_line_add(unsigned char return_value)
{
    qDebug("pc_measure_set_line_add:return_value:0x%02x",return_value);
    //增加线的槽
}

void Hp_Display::slot_pc_measure_set_line_del(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_line_del:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_line_update(unsigned char return_value)
{

    qDebug("slot_pc_measure_set_line_update:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_point_add(unsigned char return_value)
{

    qDebug("slot_pc_measure_set_point_add:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_point_del(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_point_del:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_point_update(unsigned char return_value)
{
    qDebug("slot_pc_measure_set_point_update:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_rect_add(unsigned char return_value)
{

    qDebug("slot_pc_measure_set_rect_add:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_set_rect_del(unsigned char return_value)
{

    qDebug("slot_pc_measure_set_rect_del:return_value:0x%02x",return_value);
}

void Hp_Display::slot_pc_measure_get_point(unsigned char return_value, ComPointPara point)
{
    qDebug() << "Hp_Display::slot_pc_measure_get_point" << point.point_id << pointIndex;
    if(return_value == RE_OK)
    {
        /* 设备树模式运行过程 */
        if(m_filePathState)
        {
            for(int i = 0; i < display_aya_infos.count(); i++) {
                ANA_OUTLINE point_d = display_aya_infos.at(i);
                if((point_d.id == point.point_id) && (point_d.ana_type[0] == 'P')) {
                    point_d.maxtemp = (float)point.temp100 / 100.00;
                    display_aya_infos.replace(i, point_d);
                    taskIndex++;
                }
            }
            if(taskIndex == display_aya_infos.count())
            {
                QString flag;
                QString title;
                QString text;
                float env_temp = (float)hp_parrent->hpsetting.get_environ_temp() / 100.00;
                Hp_TaskPkg::getInstance()->Cal_TaskWarning(display_aya_infos, env_temp, flag, title, text,task_errid);
                signal_setTaskTest(flag, title, text);
            }
            else
            {
                emit signal_read_img_process(taskIndex);
            }
        /* 非设备树模式运行过程 */
        }else{
            if( hp_point_list.count() < max_point_num )
            {
                if(!hir_analyse)//若为hir模式则不予drawStatus变化
                {
                    drawStatus = DS_POINT;
                }
                ComPointPara ll_hp_point;
                pointIndex = point.point_id;
                ll_hp_point.point_id = point.point_id;
                ll_hp_point.p_xcoord = point.p_xcoord;
                ll_hp_point.p_ycoord = point.p_ycoord;

                ll_hp_point.p_distance100 = point.p_distance100;
                ll_hp_point.refer_flag = point.refer_flag;
                ll_hp_point.p_radiance100 = point.p_radiance100;
                ll_hp_point.p_vaild =point.p_vaild;

                ll_hp_point.p_radTable_switch = point.p_radTable_switch;
                ll_hp_point.p_radTable_id = point.p_radTable_id;
                ll_hp_point.p_radTable_value100 = point.p_radTable_value100;
                ll_hp_point.temp100=point.temp100;

                if(hir_analyse)
                {
                    if( define_zoom )
                    {
                        ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*167/100;
                        ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*167/100;
                    }
                }

                hp_point_list.append(ll_hp_point);
                qDebug() << "Hp_Display::slot_pc_measure_get_point append over" << pointIndex;
                if(hir_analyse)
                {
                    return;
                }
            }
        }
        drawStatus = DS_NON;
    }
}

void Hp_Display::slot_pc_measure_get_line(unsigned char return_value, ComLinePara line)
{
    qDebug("slot_pc_measure_get_line:return_value:0x%02x %d ",return_value,lineIndex);
    if(return_value == RE_OK)
    {
        /* 设备树模式运行过程 */
        if(m_filePathState) {
//            qDebug() << "Shearch ===================";
            for(int i = 0; i < display_aya_infos.count(); i++) {
                ANA_OUTLINE point = display_aya_infos.at(i);
//                qDebug() << i << " ; " << point.id << " ; " << line.line_id << " ; " << point.ana_type[0];
                if((point.id == line.line_id) && (point.ana_type[0] == 'L')) {
                    point.maxtemp = (float)line.maxtemp100 / 100.00;
                    point.mintemp = (float)line.mintemp100 / 100.00;
                    point.avgtemp = (float)line.avgtemp100 / 100.00;
                    display_aya_infos.replace(i, point);
//                    qDebug() << " SUCCESS " << point.maxtemp << " ; " << display_aya_infos.at(i).maxtemp;
                    taskIndex++;
                }
            }
//            qDebug() << "Shearch ===================";
//            qDebug() << "L line.id == > " << line.line_id << "maxtemp100 == > " << (float)line.maxtemp100 / 100.00;
//            qDebug() << "L taskIndex ========> " << taskIndex << " display_aya_infos ==>" << display_aya_infos.count();
//            qDebug() << "L display_aya_infos(i) == > " << display_aya_infos.at(taskIndex - 1).maxtemp;
            if(taskIndex == display_aya_infos.count())
            {
                QString flag;
                QString title;
                QString text;
                float env_temp = (float)hp_parrent->hpsetting.get_environ_temp() / 100.00;
                qDebug("2display_aya_infos.count: %d,\n env_temp :%f, \nflag: %s, \ntitle: %s, \ntext :%s,\ntask_errid: %d\n",display_aya_infos.count(), env_temp, flag, title, text,task_errid);

                Hp_TaskPkg::getInstance()->Cal_TaskWarning(display_aya_infos, env_temp, flag, title, text,task_errid);
                signal_setTaskTest(flag, title, text);
            }
            else
            {
                emit signal_read_img_process(taskIndex);
            }

        /* 非设备树模式运行过程 */
        } else {
//            qDebug() << " hp_Line_list ===> " << hp_line_list.count() << " ; hir_analyse == > " << hir_analyse;
            if( hp_line_list.count() < max_line_num )
            {
                if(!hir_analyse)
                {
                    drawStatus = DS_LINE;
                }
                ComLinePara ll_hp_line;
                lineIndex=line.line_id;
                 ll_hp_line.line_id = line.line_id;
    //              ll_hp_line.line_id =lines[line_id]+1;
//                qDebug()<<"tttttttttttttttttttttttttttttttttttttttt5    "<<line_id<<"  "<<line.line_id <<"   "<<lineIndex;
                ll_hp_line.l_xcoord = line.l_xcoord;
                ll_hp_line.l_ycoord = line.l_ycoord;
                ll_hp_line.l_x1coord = line.l_x1coord;
                ll_hp_line.l_y1coord = line.l_y1coord;


                ll_hp_line.refer_flag = line.refer_flag;//
                ll_hp_line.l_distance100 = line.l_distance100;
                ll_hp_line.line_vaild = line.line_vaild;
                ll_hp_line.l_radiance100 = line.l_radiance100;

                ll_hp_line.l_radTable_switch = line.l_radTable_switch;
                ll_hp_line.l_radTable_id = line.l_radTable_id;
                ll_hp_line.l_radTable_value100 = line.l_radTable_value100;

                ll_hp_line.l_ReflectTemp100 = line.l_ReflectTemp100;
                ll_hp_line.l_temptype = line.l_temptype;
    //            ll_hp_line.temp100=line.temp100;     //由于更新结构体而注释
                if(hir_analyse)
                {
                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*167/100;
                            ll_hp_line.l_ycoord = ll_hp_line.l_ycoord*167/100;
                            ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*167/100;
                            ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*167/100;
                        }
                        else{
                            ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*167/100;
                            ll_hp_line.l_ycoord = ll_hp_line.l_ycoord*176/100;
                            ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*167/100;
                            ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*176/100;
                        }
                    }
//                    qDebug() << " )))) line = > " << ll_hp_line.l_xcoord << " ; " << ll_hp_line.l_ycoord << " ; " << ll_hp_line.l_x1coord << " ; " << ll_hp_line.l_y1coord;
                }
                hp_line_list.append(ll_hp_line);

//                qDebug() << "============================== 2 ";
//                qDebug() << " rectIndex = " << lineIndex;
//                qDebug() << " l_xcoord = " << ll_hp_line.l_xcoord;
//                qDebug() << " l_ycoord = " << ll_hp_line.l_ycoord;
//                qDebug() << " l_x1coord = " << ll_hp_line.l_x1coord;//和temptype一起控制按钮2
//                qDebug() << " l_y1coord = " << ll_hp_line.l_y1coord;//辐射率
//                qDebug() << " refer_flag = " << ll_hp_line.refer_flag;//距离
//                qDebug() << " l_distance100 = " << ll_hp_line.l_distance100;
//                qDebug() << " l_radiance100 = " << ll_hp_line.l_radiance100;//反射温度
//                qDebug() << " l_radTable_switch = " << ll_hp_line.l_radTable_switch;//控控制按钮1，为1则开
//                qDebug() << " l_radTable_id = " << ll_hp_line.l_radTable_id;
//                qDebug() << " l_radTable_value100 = " << ll_hp_line.l_radTable_value100;
//                qDebug() << " l_ReflectTemp100 = " << ll_hp_line.l_ReflectTemp100;
//                qDebug() << " l_temptype = " << ll_hp_line.l_temptype;//标识测温类型第几行，从0开始
//                qDebug() << "============================== 2 ";

                if(hir_analyse)//若为hir模式则不予drawStatus变化
                {
                    return;
                }
            }
        }
        drawStatus = DS_NON;
    }
}

void Hp_Display::slot_pc_measure_get_rect(unsigned char return_value, ComRectPara rect)
{
    if(return_value == RE_OK)
    {
        /* 设备树模式运行过程 */
        if(m_filePathState) {
            for(int i = 0; i < display_aya_infos.count(); i++) {
                ANA_OUTLINE point = display_aya_infos.at(i);
                if((point.id == rect.rect_id) && (point.ana_type[0] == 'R')) {
                    point.avgtemp = (float)rect.avgtemp100 / 100.00;
                    point.maxtemp = (float)rect.maxtemp100 / 100.00;
                    point.mintemp = (float)rect.mintemp100 / 100.00;
                    display_aya_infos.replace(i, point);
                    taskIndex++;
                }
            }
            if(taskIndex == display_aya_infos.count())
            {
                QString flag;
                QString title;
                QString text;
                float env_temp = (float)hp_parrent->hpsetting.get_environ_temp() / 100.00;
                Hp_TaskPkg::getInstance()->Cal_TaskWarning(display_aya_infos, env_temp, flag, title, text,task_errid);
                signal_setTaskTest(flag, title, text);
            }
            else
            {
                emit signal_read_img_process(taskIndex);
            }

        /* 非设备树模式运行过程 */
        } else {
            if(!m_selectInsValueMap.isEmpty())
            {
                qDebug() << __func__ << __LINE__ << rect.rect_id << nowselect.s;
                if(m_selectInsValueMap.contains(rect.rect_id))
                {
                    int maxMinusAvg = rect.maxtemp100 - rect.avgtemp100;
                    int avgMinusMin = rect.avgtemp100 - rect.mintemp100;
                    if(maxMinusAvg > avgMinusMin * 3)
                    {
                        qDebug() << __func__ << __LINE__ << "rect waring" << rect.origin_xcoord << rect.origin_ycoord;
                        qDebug() << __func__ << m_selectIdRectIdMap;
                        signal_show_insulation_warning(true, m_selectIdRectIdMap[rect.rect_id], rect.origin_xcoord, rect.origin_ycoord);
                    }
                    else
                    {
                        signal_show_insulation_warning(false, m_selectIdRectIdMap[rect.rect_id], rect.origin_xcoord, rect.origin_ycoord);
                    }
                }
                return;
            }
            if( hp_rect_list.count() < 100 )
            {
                if(!hir_analyse)
                {
                    drawStatus = DS_RECT;
                }
                ComRectPara l_hp_rect;
                rectIndex=rect.rect_id;
                l_hp_rect.rect_id =rect.rect_id;
                l_hp_rect.temptype = rect.temptype;
                l_hp_rect.origin_xcoord = rect.origin_xcoord;
                l_hp_rect.origin_ycoord = rect.origin_ycoord;
                l_hp_rect.rect_wide = rect.rect_wide;
                l_hp_rect.rect_high = rect.rect_high;

                if(l_hp_rect.rect_wide < MIN_RECT_WIDTH)
                    l_hp_rect.rect_wide = MIN_RECT_WIDTH;
                if(l_hp_rect.rect_high < MIN_RECT_HEIGHT)
                    l_hp_rect.rect_high = MIN_RECT_HEIGHT;

                l_hp_rect.r_radiance100 = rect.r_radiance100;
                l_hp_rect.refer_flag = rect.refer_flag;
                l_hp_rect.rect_distance100 = rect.rect_distance100;
                l_hp_rect.rect_vaild = rect.rect_vaild;
                l_hp_rect.rect_ReflectTemp100 = rect.rect_ReflectTemp100;

                l_hp_rect.remapping_color_id = m_currSebiao;
                l_hp_rect.remapping_switch = 0;
                l_hp_rect.r_radTable_switch = rect.r_radTable_switch;
                l_hp_rect.r_radTable_id = rect.r_radTable_id;
                l_hp_rect.r_radTable_value100 = rect.r_radTable_value100;

                if(hir_analyse)
                {
                    if( define_zoom )
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*167/100;
                            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*167/100;
                            l_hp_rect.rect_wide = l_hp_rect.rect_wide*167/100;
                            l_hp_rect.rect_high = l_hp_rect.rect_high*167/100;
                        }else{
                            l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*167/100;
                            l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*176/100;
                            l_hp_rect.rect_wide = l_hp_rect.rect_wide*167/100;
                            l_hp_rect.rect_high = l_hp_rect.rect_high*176/100;
                        }
                    }
                }
                hp_rect_list.append(l_hp_rect);
                if(hir_analyse)//若为hir模式则不予drawStatus变化
                {
                    return;
                }
            }
        }
        drawStatus = DS_NON;
    }
}

void Hp_Display::slot_pc_measure_get_circle(unsigned char return_value, ComCirclePara circle)
{
    if(return_value != RE_OK)
        return;
    if(m_filePathState) {
        for(int i = 0; i < display_aya_infos.count(); i++) {
            ANA_OUTLINE point = display_aya_infos.at(i);
            if((point.id == circle.circle_id) && (point.ana_type[0] == 'C')) {
                point.avgtemp = (float)circle.avgtemp100 / 100.00;
                point.maxtemp = (float)circle.maxtemp100 / 100.00;
                point.mintemp = (float)circle.mintemp100 / 100.00;
                display_aya_infos.replace(i, point);
                taskIndex++;
            }
        }
        if(taskIndex == display_aya_infos.count())
        {
            QString flag;
            QString title;
            QString text;
            float env_temp = (float)hp_parrent->hpsetting.get_environ_temp() / 100.00;

            Hp_TaskPkg::getInstance()->Cal_TaskWarning(display_aya_infos, env_temp, flag, title, text,task_errid);
            signal_setTaskTest(flag, title, text);
        }
        else
        {
            emit signal_read_img_process(taskIndex);
        }
    } else {
        if( hp_circle_list.count() < max_circle_num )
        {
            if(!hir_analyse)
            {
                drawStatus = DS_CIRCLE;
            }
            ComCirclePara l_hp_circle;
            circleIndex = circle.circle_id;
             l_hp_circle.circle_id = circle.circle_id;
            l_hp_circle.c_temptype = circle.c_temptype;
            l_hp_circle.center_xcoord = circle.center_xcoord;
            l_hp_circle.center_ycoord = circle.center_ycoord;
            l_hp_circle.radius = circle.radius;

            if(l_hp_circle.radius < MIN_RECT_WIDTH / 2)
                l_hp_circle.radius = MIN_RECT_WIDTH / 2;

            l_hp_circle.c_radiance100 = circle.c_radiance100;
            l_hp_circle.refer_flag = circle.refer_flag;
            l_hp_circle.c_distance100 = circle.c_distance100;

            l_hp_circle.c_radiance100 = circle.c_radiance100;
            l_hp_circle.circle_vaild = circle.circle_vaild;

            l_hp_circle.c_radTable_switch = circle.c_radTable_switch;
            l_hp_circle.c_radTable_id = circle.c_radTable_id;
            l_hp_circle.c_radTable_value100 = circle.c_radTable_value100;

            if(hir_analyse)
            {
                if( define_zoom )
                {
                    if(HP_S350_or_S300)
                    {
                        l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*167/100;
                        l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*167/100;
                        l_hp_circle.radius = l_hp_circle.radius*167/100;
                    }else{
                        l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*167/100;
                        l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*176/100;
                        l_hp_circle.radius = l_hp_circle.radius*167/100;
                    }
                }
            }
            hp_circle_list.append(l_hp_circle);
            if(hir_analyse)//若为hir模式则不予drawStatus变化
            {
                return;
            }
        }
    }
    drawStatus = DS_NON;
}


void Hp_Display::slot_pc_measure_set_rect_update(unsigned char return_value)
{

    qDebug("slot_pc_measure_set_rect_update:return_value:0x%02x",return_value);
}

void Hp_Display::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1 ){
        if(time_event == true){
            auto_focus =false;
          //  time_event =false;
            signal_lable_focus_state(false);
            update();
        }
    }
}
void Hp_Display::sltImageChange(QString file_path)
{
    qDebug() << "Hp_Display::sltImageChange :  --> " << file_path;
    m_filePath = file_path;
    update();
}
/****************************************************************
 * @ description : 槽函数 停止任务包相关显示
 * @ param       : null
 * @ return      : null
 ****************************************************************/
void Hp_Display::sltStopTask()
{
    m_filePathState = false;
    m_filePath.clear();
    update();
}
/****************************************************************
 * @ description : 槽函数 开始任务包相关显示
 * @ param       : null
 * @ return      : null
 ****************************************************************/
void Hp_Display::sltStartTask()
{
    m_filePathState = true;
    update();
}

//2018 .4.20    dasidian
void Hp_Display::paintEvent(QPaintEvent *event)                                    // paint
{
    Q_UNUSED(event);

    /* 任务包相关重绘事件 */
    if(m_filePathState && !m_filePath.isEmpty() && TaskSouldBepaint) {
        QPainter painter_stack;
        if(painter_stack.begin(this)) {
            /* 绘制设备框图 */
            QImage imageStack(m_filePath);
            Hp_TaskPkg::getInstance()->Bmp2Png(imageStack);
            painter_stack.drawImage(0, 0, imageStack.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
            painter_stack.end();
//            qDebug() << "Draw >> " << this->width() << " ; " << this->height();
        }
    }
    if(define_brightmode)
    {
        if(auto_focus == true)
        {
            QPainter painter_focus(this);
            //画笔颜色#c87b37
//            painter_focus.setPen(QColor(255,0,0));
            painter_focus.setPen(QColor(200,123,55));           //画笔颜色
            painter_focus.drawRect( 240,180,160,120);           //框 （x,y,宽,高）

            painter_focus.drawLine(320,180,320,195);            //上线（x1,y1,x2,y2）起点和终止坐标
            painter_focus.drawLine(320,285,320,300);            //下线

            painter_focus.drawLine(240,240,255,240);            //左线
            painter_focus.drawLine(385,240,400,240);            //右线
            signal_lable_focus_state(true);
            //label_focus

            if(time_event == false){
                id1 = startTimer(6000);    //6s控制消失时间
                time_event =true;
            }
        }
    }
//    if(isVisibleLight)
//    {
//        QPainter painter(this);
//        painter.setPen(QColor(255,255,255));
//        {
//            painter.drawPoint(this->width() / 2, this->height() / 2);
//            painter.drawLine(0, this->height() / 2, this->width() / 2 - 5, this->height() / 2);
//            painter.drawLine(this->width() / 2 + 5, this->height() / 2, this->width(), this->height() / 2);
//            painter.drawLine(this->width() / 2, 0, this->width() / 2, this->height() / 2 - 5);
//            painter.drawLine(this->width() / 2, this->height() / 2 + 5, this->width() / 2, this->height());
//        }
//    }

    //2018.4.20   sidian
    if(true == hidemenu_rect){
        QPainter painter_sidian(this);
        if((true == decide_state.press_shape)&&(true == decide_state.release_shape))
        {
            decide_state.shape_was_pich = true;             //图形被选中
        }else{
            decide_state.shape_was_pich = false;
        }

        //设置画笔颜色
        if ( true == decide_state.shape_was_pich){
            painter_sidian.setPen(QColor(255,255,0));              //此时框为选中状态可以进行相应的操作. 黄色
        }else{
            painter_sidian.setPen(QColor(255,0,0));
        }
        //设置框的区间范围（不能超过屏幕的范围）

        painter_sidian.drawRect( rect.rect_x, rect.rect_y,rect.rect_widget, rect.rect_hight );     //画框  //有相应的画点函数
    }
//2018.2.27 。   界面画框
    QPainter painter(this);
    painter.setPen(QColor(255,255,255));
    if(drawStatus == DS_LINE)
    {
        //进入画线流程
        if(isDrawing)
        {
            if(mouse_move == true){
               painter.drawLine(mouse_start_x, mouse_start_y, mouse_end_x, mouse_end_y);       //线
            }
        }else{;}
    }
      //进入画框流程
    else if(drawStatus == DS_RECT)
    {
        if(isDrawing)
        {
             if(mouse_move == true)
             {
                painter.drawRect(mouse_start_x, mouse_start_y, (mouse_end_x-mouse_start_x), (mouse_end_y-mouse_start_y));     //框
            }
         }
        else{;}
    }
    else if(drawStatus == DS_CIRCLE)
    {
        if(isDrawing)
        {
             if(mouse_move == true){
                 painter.setRenderHint(QPainter::Antialiasing);
                 QPoint startPoint(mouse_start_x,mouse_start_y);
                 QPoint endPoint(mouse_end_x,mouse_end_y);
                 QPoint center = (startPoint + endPoint) / 2;
                 int radius = QLineF(startPoint, endPoint).length() / 2;

                 painter.drawEllipse(center, radius, radius);
            }
         }else{;}
    }
    else if(drawStatus == DS_POLYGON)
    {
        QPointF points[30];
        if(m_isPolygonDraw)
        {
            for(int i = 0; i < m_polygonsPosList.count(); i++)
            {
                points[i] = m_polygonsPosList.at(i);
                if(i > 0)
                {
                    painter.drawLine(m_polygonsPosList.at(i-1).x(), m_polygonsPosList.at(i-1).y(), m_polygonsPosList.at(i).x(), m_polygonsPosList.at(i).y());
                }
            }
            QPen pen(Qt::white); // 创建黑色画笔
                pen.setWidth(4);      // 设置宽度为3像素
                painter.setPen(pen);  // 应用画笔
            painter.drawPoints(points, m_polygonsPosList.count());
        }
    }
    else{
        isDrawing = false;
        return;
    }
//***********************************************2018.2.27


        return;             //不知道为什么存在？ 之前就有

    painter.setPen(Qt::green);

    int i;

    QListIterator<ComPointPara> i_point(hp_point_list);
    ComPointPara l_hp_point;

    QPoint pt0,pt1,tmp_pt;
    int m = 15;

    i=0;
    while(i_point.hasNext())
    {
        l_hp_point = i_point.next();

        tmp_pt.setX(l_hp_point.p_xcoord);
        tmp_pt.setY(l_hp_point.p_ycoord);

        pt0 = tmp_pt;

        pt1 = pt0;
        pt1.setX(pt0.x()-m);
        if(pt1.x()<0)
            pt1.setX(0);
        painter.drawLine(pt1,pt0);

        pt1=pt0;
        pt1.setY(pt0.y()-m);
        if(pt1.y()< 0)
            pt1.setY(0);
        painter.drawLine(pt1,pt0);

        pt1 = pt0;
        pt1.setX(pt0.x()+m);
        if(pt1.x()>640)
            pt1.setX(640);
        painter.drawLine(pt0,pt1);

        pt1=pt0;
        pt1.setY(pt0.y()+m);
        if(pt1.y()>bottom_edge)
            pt1.setY(bottom_edge);
        painter.drawLine(pt0,pt1);



        if(nowselect.c == DS_POINT && nowselect.s == i && drawStatus == DS_NON)
        {
            //画小圆，表示选中

            painter.drawEllipse(pt0,5,5);
        }


        i++;

    }

    QListIterator<ComLinePara> i_line(hp_line_list);
    ComLinePara l_hp_line;
    QLine l_line;

    i = 0;

    while(i_line.hasNext())
    {
        l_hp_line = i_line.next();
        l_line.setP1(QPoint(l_hp_line.l_x1coord,l_hp_line.l_y1coord));
        l_line.setP2(QPoint(l_hp_line.l_xcoord,l_hp_line.l_ycoord));
        painter.drawLine(l_line.p1(),l_line.p2());

        if(nowselect.c == DS_LINE && nowselect.s == i && drawStatus == DS_NON)
        {
            //画小圆，表示选中
            painter.drawEllipse(l_line.p1(),5,5);
            painter.drawEllipse(l_line.p2(),5,5);

        }
        i++;
    }



    QListIterator<ComRectPara> i_rect(hp_rect_list);
    ComRectPara l_hp_rect;
    QRect l_rect;

    i=0;

    while(i_rect.hasNext())
    {
        l_hp_rect = i_rect.next();

        l_rect.setTopLeft(QPoint(l_hp_rect.origin_xcoord,l_hp_rect.origin_ycoord));
        l_rect.setWidth(l_hp_rect.rect_wide);
        l_rect.setHeight(l_hp_rect.rect_high);

        painter.drawRect(l_rect);



        if(nowselect.c == DS_RECT && nowselect.s == i && drawStatus == DS_NON)
        {
            QPoint pt[9];//四角+边中点

            pt[0] = l_rect.topLeft();//左上角
            pt[1] = l_rect.topRight();//右上角
            pt[2] = l_rect.bottomRight();//右下角
            pt[3] = l_rect.bottomLeft();//左下角

            pt[4] = pt[0];
            pt[4].rx() += l_rect.width()/2;

            pt[5] = pt[1];
            pt[5].ry() += l_rect.height()/2;

            pt[6] = pt[3];
            pt[6].rx() += l_rect.width()/2;

            pt[7] = pt[0];
            pt[7].ry() += l_rect.height()/2;

            pt[8] = pt[0];
            pt[8].rx() += l_rect.width()/2;
            pt[8].ry() += l_rect.height()/2;

            for(int k=0;k<9;k++)
            {
                painter.drawEllipse(pt[k],5,5);
            }
        }
        i++;
    }

    QListIterator<ComCirclePara> i_circle(hp_circle_list);
    ComCirclePara l_hp_circle;
    QRect l_circle;

    i=0;

    while(i_rect.hasNext())
    {
        l_hp_circle = i_circle.next();

        l_circle.setTopLeft(QPoint(l_hp_circle.center_xcoord - l_hp_circle.radius, l_hp_circle.center_ycoord - l_hp_circle.radius));
        l_circle.setWidth(l_hp_circle.radius * 2);
        l_circle.setHeight(l_hp_circle.radius * 2);

        painter.drawEllipse(l_circle);



        if(nowselect.c == DS_CIRCLE && nowselect.s == i && drawStatus == DS_NON)
        {
            QPoint pt[5];//四角+边中点

            pt[0] = l_rect.topLeft();//左上角
            pt[1] = l_rect.topRight();//右上角
            pt[2] = l_rect.bottomRight();//右下角
            pt[3] = l_rect.bottomLeft();//左下角

            pt[4] = pt[0];
            pt[4].rx() += l_rect.width()/2;

            pt[5] = pt[1];
            pt[5].ry() += l_rect.height()/2;

            pt[6] = pt[3];
            pt[6].rx() += l_rect.width()/2;

            pt[7] = pt[0];
            pt[7].ry() += l_rect.height()/2;

            pt[8] = pt[0];
            pt[8].rx() += l_rect.width()/2;
            pt[8].ry() += l_rect.height()/2;

            for(int k=4;k<9;k++)
            {
                painter.drawEllipse(pt[k],5,5);
            }
        }
        i++;
    }
}
//2018 .4.20    dasidian
void Hp_Display::mousePressEvent(QMouseEvent *ev)                                                   //press
{
//    qDebug() << "Hp_Display::mousePressEvent == > " << ev->pos();
    signal_update_lcdoff_time(false);
    //记录按下时的坐标点

    pressPoint = ev->pos();
    rect_start_press = ev->pos();
    if(define_640_512)
    {
        pressPoint.setY(pressPoint.y() * SCF_Y_MUL);
    }
    if(sketch_state==true)
    {
        sketch_point  sketch_temp;
        if(define_640_512)
        {
            sketch_temp.point_x = ev->pos().x();
            sketch_temp.point_y = ev->pos().y() * SCF_Y_MUL;
        }
        else if(define_zoom)
        {
            sketch_temp.point_x = ev->pos().x() * 100/167;
            sketch_temp.point_y = ev->pos().y() * 100/167;
        }
        else{
            sketch_temp.point_x = ev->pos().x();
            sketch_temp.point_y = ev->pos().y();
        }
        signal_pc_image_set_sketch_start(sketch_temp);
    }
//***********************************************2018.4.20   sidian

    if( !isVisibleLight )
    {
        int mouse_x;
        int mouse_y;
        QString pos =  QString("%1, %2").arg(ev->pos().x()).arg(ev->pos().y()); //获取当前位置的坐标
        mouse_x = ev->pos().x();
        mouse_y = ev->pos().y();
        if(define_640_512)
        {
            mouse_y *= SCF_Y_MUL;
        }
        //point
        if(true == hidemenu_point)
        {
            point.press_x = mouse_x;
            point.press_y = mouse_y;
            if(( mouse_x >= point.point_x - point.point_widget) && ( mouse_x <= point.point_x + point.point_widget))        //点的横坐标在框内
            {
                if( ( mouse_y >= point.point_y -point.point_widget) && ( mouse_y <= point.point_y + point.point_widget))        //点的横坐标在框内
                {
                    point.point_select =true;       //点被选中
                    //获取初始位置
                    point.begin_x = point.point_x;
                    point.begin_y = point.point_y;
                }
            }
        }

        //rect
        //记录此时框的一些初始状态
        if(true == hidemenu_rect)
        {
            fu_zhu.begin_x = rect.rect_x;
            fu_zhu.begin_y = rect.rect_y;
            fu_zhu.begin_widget = rect.rect_widget;
            fu_zhu.begin_hight = rect.rect_hight;

            fu_zhu.press_x = mouse_x;
            fu_zhu.press_y = mouse_y;

        //判断选中的位置是否在图形内
            if((mouse_x >= (rect.rect_x-fu_zhu.wai_widget)) && (mouse_x <= (rect.rect_x+rect.rect_widget+fu_zhu.wai_widget)))     //横坐标在区域范围内
            {
                if((mouse_y >= (rect.rect_y-fu_zhu.wai_widget)) && (mouse_y <= (rect.rect_y+rect.rect_hight+fu_zhu.wai_widget)))      //纵坐标也在区域范围内
                {
                     decide_state.press_shape =true;
                }else{
                    decide_state.press_shape =false;
                }
            }else{
                decide_state.press_shape =false;
            }

            //根据选中图标后再次点击图标的位置。判断进行哪种操作。 边线外为5，边线内为5；
            if( true ==decide_state.shape_was_pich)
            {
                //选中左上角 >= <= >   根据点击时首座标判断 进行哪种处理;
                if((mouse_x >= (rect.rect_x-fu_zhu.wai_widget)) && (mouse_x <= (rect.rect_x+fu_zhu.nei_widget)))              //左
                {
                    if((mouse_y >= (rect.rect_y-fu_zhu.wai_widget)) && (mouse_y <=(rect.rect_y+fu_zhu.nei_widget)))           //左上
                    {
                        fu_zhu.change_style = 11;
                    }
                    else if((mouse_y > (rect.rect_y+fu_zhu.nei_widget)) && (mouse_y < (rect.rect_y+rect.rect_hight-fu_zhu.nei_widget)))  //左中
                    {
                        fu_zhu.change_style =12;
                    }
                    else if(( mouse_y >= (rect.rect_y+rect.rect_hight-fu_zhu.nei_widget) ) && ( mouse_y <= ( rect.rect_y + rect.rect_hight + fu_zhu.wai_widget)) )   //左下
                    {
                         fu_zhu.change_style=13;
                    }
                    else{
                        ;
                    }
                }
                else if( (mouse_x >= ( rect.rect_x + rect.rect_widget -fu_zhu.nei_widget)) && ( mouse_x <= (rect.rect_x + rect.rect_widget +fu_zhu.wai_widget )))  //选中右边
                {
                    if( (mouse_y >= (rect.rect_y - fu_zhu.wai_widget) ) && (mouse_y <= (rect.rect_y +fu_zhu.nei_widget)) )       //右上
                    {
                            fu_zhu.change_style=31;
                    }
                    else if( (mouse_y > (rect.rect_y + fu_zhu.nei_widget) ) && ( mouse_y < (rect.rect_y +rect.rect_hight - fu_zhu.nei_widget) ) )      //右中
                    {
                            fu_zhu.change_style=32;
                    }
                    else if( (mouse_y >= (rect.rect_y +rect.rect_hight - fu_zhu.nei_widget) ) &&( mouse_y <= (rect.rect_y + rect.rect_hight +fu_zhu.wai_widget) ))      //右下
                    {
                            fu_zhu.change_style=33;
                    }
                    else{
                        ;
                    }
                }
                else if((mouse_x > (rect.rect_x +fu_zhu.nei_widget)) && (mouse_x < ( rect.rect_x+rect.rect_widget-fu_zhu.nei_widget))) //选中中间
                {
                    if( (mouse_y >= (rect.rect_y - fu_zhu.wai_widget) ) && (mouse_y <= (rect.rect_y +fu_zhu.nei_widget)) )       //中上
                    {
                            fu_zhu.change_style=21;
                    }
                    else if(  (mouse_y >= (rect.rect_y +rect.rect_hight - fu_zhu.nei_widget) ) &&( mouse_y <= (rect.rect_y + rect.rect_hight +fu_zhu.wai_widget) ) )  //中下
                    {
                            fu_zhu.change_style=23;
                    }
                    else if( (mouse_y > (rect.rect_y + fu_zhu.nei_widget) ) && ( mouse_y < (rect.rect_y +rect.rect_hight - fu_zhu.nei_widget) ) )  //中中--->移动事件
                    {
                            fu_zhu.change_style=22;
                    }else{
                        ;
                    }

                }else{
                    ;
                }
            }
        }
    }
    update();

//***********************************************
//2018.2.27
    isDrawing = true;
 //   QString pos =  QString("%1, %2").arg(ev->pos().x()).arg(ev->pos().y()); //获取当前位置的坐标
    mouse_start_x = ev->pos().x();
    mouse_start_y = ev->pos().y();
    movePos = ev->pos();
    if(define_640_512)
    {
        movePos = ev->pos();
    }
//    QToolTip::showText(ev->globalPos(),pos,this);   //工具提示中显示坐标

}
//2018 .4.20    dasidian
void Hp_Display::mouseReleaseEvent(QMouseEvent *ev)                                                                             //release
{
    qDebug() << "Hp_Display::mouseReleaseEvent == > " << ev->pos() << " isVisibleLight == > " << isVisibleLight;
    signal_update_lcdoff_time(false);
    mouse_move =false;
    m_isPolygonSelectMove = false;
    m_polygonSelectMoveIndex = -1;
    //====2018.4.20   sidian=========
    int mouse_x;
    int mouse_y;
    QString pos =  QString("%1, %2").arg(ev->pos().x()).arg(ev->pos().y()); //获取当前位置的坐标
    mouse_x = ev->pos().x();
    mouse_y = ev->pos().y();

    if(m_doubleClickFocusFlag && m_doubleClickCounter == 0)
    {
        if(ev->x() > 160 && ev->x() < bottom_edge && ev->y() > 120 && ev->y() < 360)
            m_doubleClickCounter++;
        QTimer::singleShot(300, this, SLOT(sltDoubleClickFocus()));
    }
    if(m_doubleClickCounter != 0)
    {
        if(ev->x() > 160 && ev->x() < bottom_edge && ev->y() > 120 && ev->y() < 360)
            m_doubleClickCounter++;
    }
    if(sketch_state==true)
    {
        sketch_point  sketch_temp;
        if(define_640_512)
        {
            sketch_temp.point_x =ev->pos().x();
            sketch_temp.point_y= ev->pos().y() * SCF_Y_MUL;
        }
        else if(define_zoom)
        {
            sketch_temp.point_x =ev->pos().x() * 100/167;
            sketch_temp.point_y= ev->pos().y() * 100/167;
        }else{
            sketch_temp.point_x =ev->pos().x();
            sketch_temp.point_y= ev->pos().y();
        }
        signal_pc_image_set_sketch_draw( sketch_temp);
    }
    if(define_640_512)
    {
        mouse_y *= SCF_Y_MUL;
    }
    if( !isVisibleLight )
    {
        //point
            if(true == hidemenu_point)
            {
               if(true ==point.point_select)
                {
                    point.point_select =false;
                    point.point_x = mouse_x - point.press_x +point.begin_x;
                    point.point_y = mouse_y - point.press_y + point.begin_y;
        //            qDebug( )<<"point.point_x = "<<point.point_x << "point.point_y = "<<point.point_y;
                    //判断松开鼠标时 点是否在界面区间范围内。若不在恢复上一次状态
                    if(((mouse_x+(point.begin_x-point.press_x)) >=0) && ((mouse_y +(point.begin_y - point.press_y))>=0))
                    {
                        if(((mouse_x+(point.begin_x-point.press_x)) <=640) && ((mouse_y +(point.begin_y - point.press_y)) <=640))
                        {
                            ;   //在界面上时，不做处理
                        }else{
                            point.point_x = point.begin_x;                      //坐标恢复到上一个状态
                            point.point_y = point.begin_y;
                        }
                    }else{
                        point.point_x = point.begin_x;
                        point.point_y = point.begin_y;
                    }

                    lable_sidian->setGeometry(point.point_x - point.point_widget , point.point_y - point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1);
                    point_struct_copy();        //松开点
               }
            }

        //rect
            if(true == hidemenu_rect)
            {
                //判断选中的位置是否在图形内
                if(true == decide_state.press_shape)
                {
                    if((mouse_x >= (rect.rect_x-fu_zhu.wai_widget)) && (mouse_x <= (rect.rect_x+rect.rect_widget+fu_zhu.wai_widget)))     //横坐标在区域范围内
                    {
                        if((mouse_y >= (rect.rect_y-fu_zhu.wai_widget)) && (mouse_y <= (rect.rect_y+rect.rect_hight+fu_zhu.wai_widget)))      //纵坐标也在区域范围内
                        {
                             decide_state.release_shape =true;
                        }else{
                            decide_state.release_shape =false;
                        }
                    }else{
                        decide_state.release_shape =false;
                    }

                    //判断框是否在界面区间范围内。若不在恢复上一次状态
                    if( (rect.rect_x >= 0) && ( rect.rect_y >= 0)){                           //左上角在界面。判断右下角在界面上吗？
                            if( (rect.rect_x+rect.rect_widget <= 640) && (rect.rect_y+rect.rect_hight <= bottom_edge))       //右上角在界面
                            {
                                ;
                            }else{
                                rect.rect_x = fu_zhu.begin_x;
                                rect.rect_y = fu_zhu.begin_y;
                                rect.rect_widget = fu_zhu.begin_widget;
                                rect.rect_hight = fu_zhu.begin_hight;
                            }
                    }else{
                        rect.rect_x = fu_zhu.begin_x;
                        rect.rect_y = fu_zhu.begin_y;
                        rect.rect_widget = fu_zhu.begin_widget;
                        rect.rect_hight = fu_zhu.begin_hight;
                    }

                    rect_struct_copy();     //松开框：
                }else{
                  decide_state.release_shape =false;
                }
            fu_zhu.change_style = 0;
            }

            update();
            //=================================
            //记录释放时的坐标点
            releasePoint = ev->pos();
            int xx,yy;
            xx = qAbs(releasePoint.x() - pressPoint.x());
            yy = qAbs(releasePoint.y()-pressPoint.y());
            if(define_640_512)
            {
                yy = qAbs(releasePoint.y()-pressPoint.y() / SCF_Y_MUL);
                releasePoint.setY(releasePoint.y() * SCF_Y_MUL);
            }

            //判断按下和释放时的坐标是否相同，如果相同，表示是单击事件，否则进入画线和框流程
            if(xx <20 && yy<20)
            {
                //进入单击事件流程
                //判断当前状态，如果不是画点状态，则进入选点线框模式，根据算法判断是否有点或线或框被选中
                if(drawStatus == DS_NON)
                {
                    if(!hir_stop)
                    {
                        return;
                    }
                    //进入非画点线框模式，计算有没点线框被选中

                    //先遍历点,再遍历线，最后遍历框

                    //遍历点
                    QListIterator<ComPointPara> item_point(hp_point_list);
                    ComPointPara l_hp_point;
                    QPoint l_point,l_p;

                    int i = 0;

                    while(item_point.hasNext())
                    {
                        l_hp_point = item_point.next();

                        l_point.setX(l_hp_point.p_xcoord);
                        l_point.setY(l_hp_point.p_ycoord);

                        l_p = l_point - releasePoint;
                        if(qAbs(l_p.x()) < 30 && qAbs(l_p.y())<30)
                        {

                            //=========================>>
                            //qt->core select point
                            OP_DATA op_data;
                            op_data.cmd_type = DS_POINT;                              //类型
                            op_data.id = l_hp_point.point_id;                            //编号
                            signal_pc_measure_active(op_data);                       //给内核发送的操作命令（结构体）
                            //<<============================

                            nowselect.c = DS_POINT;                                         //表示目前选中的项目
                            nowselect.s = i;
                            update();
                            selectUpdate();
                            return ;
                        }
                        i++;                                                                            //表示第几个点
                    }
                    //遍历线,cichu suanfa xuyao you hua
                    QListIterator<ComLinePara> item_line(hp_line_list);
                    ComLinePara l_hp_line;
                    QLine l_line;
                    QRect l_rect;
                    QRect l_circle;
                    i = 0;
                    while(item_line.hasNext())
                    {
                        l_hp_line = item_line.next();

                        l_line.setP1(QPoint(l_hp_line.l_xcoord,l_hp_line.l_ycoord));                     //P1 起始坐标
                        l_line.setP2(QPoint(l_hp_line.l_x1coord,l_hp_line.l_y1coord));                  //P2 终止坐标
                        //以线为对角线。 画框
                        l_rect.setX(qMin(l_line.x1(),l_line.x2()));
                        l_rect.setY(qMin(l_line.y1(),l_line.y2()));
                        l_rect.setHeight(qAbs(l_line.y1()-l_line.y2()));
                        l_rect.setWidth(qAbs(l_line.x1()-l_line.x2()));
                        if(qAbs(l_line.x1()-l_line.x2())<15 )
                        {
                            if(releasePoint.y() < qMax(l_line.y1(),l_line.y2()) && releasePoint.y() > qMin(l_line.y1(),l_line.y2()) && ((qAbs(releasePoint.x() - l_line.x1()) <15)||(qAbs(releasePoint.x() - l_line.x2()) <15)) )
                            {
                                //=========================>>
                                //qt->core select line
                                OP_DATA op_data;
                                op_data.cmd_type = DS_LINE;
                                op_data.id = l_hp_line.line_id;
                                signal_pc_measure_active(op_data);
                                //<<============================

                                nowselect.c = DS_LINE;
                                nowselect.s = i;
                                update();
                                selectUpdate();
                                return;
                            }
                        }
                        else if(qAbs(l_line.y1()-l_line.y2())<15)
                        {
                            if(releasePoint.x() < qMax(l_line.x1(),l_line.x2()) && releasePoint.x() > qMin(l_line.x1(),l_line.x2()) && ((qAbs(releasePoint.y() - l_line.y1()) <15)||(qAbs(releasePoint.y() - l_line.y2()) <15)))
                            {
                                //=========================>>
                                //qt->core select line
                                OP_DATA op_data;
                                op_data.cmd_type = DS_LINE;
                                op_data.id = l_hp_line.line_id;
                                signal_pc_measure_active(op_data);
                                //<<============================

                                nowselect.c = DS_LINE;
                                nowselect.s = i;
                                update();
                                selectUpdate();
                                return;
                            }
                        }
                        else
                        {
                            if(l_rect.contains(releasePoint))
                            {
                                int len;
                               len = point_line_distance(l_line.x1(), l_line.y1(), l_line.x2(), l_line.y2(), releasePoint.x(), releasePoint.y());
                                if(len>=0 && len<=225)
                                {
                                    OP_DATA op_data;
                                    op_data.cmd_type = DS_LINE;
                                    op_data.id = l_hp_line.line_id;
                                    signal_pc_measure_active(op_data);

                                    nowselect.c = DS_LINE;
                                    nowselect.s = i;
                                    update();
                                    selectUpdate();
                                    return;
                                }
                            }
                        }
                        i++;
                    }
                    //遍历多边形
                    QListIterator<ComPolygonPara> item_polygon(hp_polygon_list);
                    ComPolygonPara l_hp_polygon;//当前获取的多边形信息
                    i = 0;
                    int minRange = 999999;//多边形最近点距离
                    OP_DATA op_data_polygon;
                    bool get_polygon = false;//是否选中多边形
                    int nearMidIndexPolygon = -1;
                    while(item_polygon.hasNext())
                    {
                        l_hp_polygon = item_polygon.next();
                        int polygonId = l_hp_polygon.polygon_id;
                        QList<QPointF> currPointfList;
                        int minRangeCurr = 999999;
                        for(int i = 0; i < l_hp_polygon.nNode; i++)
                        {
                            QPointF pointf(l_hp_polygon.nX[i], l_hp_polygon.nY[i]);
                            currPointfList.append(pointf);
                            int rangeX = (int)qAbs(pointf.x() - releasePoint.x());
                            int rangeY = (int)qAbs(pointf.y() - releasePoint.y());

                            int currPointRange = (int)sqrt(1.0 * (rangeX * rangeX + rangeY * rangeY));
                            if(currPointRange < minRangeCurr)
                                minRangeCurr = currPointRange;
                            qDebug() << minRangeCurr;
                        }
//                        m_polygonCal.classify_points(currPointfList, currPointfList.count());
                        qDebug() << currPointfList;
                        qDebug() << minRangeCurr << minRange;
                        if(m_polygonCal.point_in_polygon(currPointfList, releasePoint, currPointfList.count()))
                        {
                            qDebug() << minRangeCurr << minRange;
                            if(minRangeCurr < minRange)
                            {
                                minRange = minRangeCurr;
                                get_polygon = true;
                                op_data_polygon.cmd_type = DS_POLYGON;
                                op_data_polygon.id = l_hp_polygon.polygon_id;
                                nowselect.c = DS_POLYGON;
                                nowselect.s = i;
                                qDebug() << __func__ << "op_data.cmd_type" << op_data_polygon.cmd_type << "op_data.id" << op_data_polygon.id << "nowselect.c" << nowselect.c << "nowselect.s"  << nowselect.s;
                                nearMidIndexPolygon = i;
                            }
                        }
                        i++;
                    }

                    //遍历框
                    QListIterator<ComRectPara> item_rect(hp_rect_list);
                    ComRectPara l_hp_rect;
                    i = 0;
                    OP_DATA op_data;
                    int sumarea_rect = 999999;
                    int nearMidIndexRect = -1;
                    int sumarea = 0;
                    bool get_rect = false;

                    while(item_rect.hasNext())
                    {
                        l_hp_rect = item_rect.next();
                        //框左上角起始坐标
                        l_rect.setTopLeft(QPoint(l_hp_rect.origin_xcoord,l_hp_rect.origin_ycoord));
                        l_rect.setWidth(l_hp_rect.rect_wide);
                        l_rect.setHeight(l_hp_rect.rect_high);
                        if(l_rect.contains(releasePoint))
                        {
                            rect_centre_select.rx() = l_rect.topLeft().x() + l_rect.width()/2;     //框被选中的中心坐标x坐标
                            rect_centre_select.ry() = l_rect.topRight().y() + l_rect.height()/2;   //框被选中的中心坐标y坐标
                            int rangeX = (int)qAbs(rect_centre_select.rx() - releasePoint.x());
                            int rangeY = (int)qAbs(rect_centre_select.ry() - releasePoint.y());

                            int currPointRange = (int)sqrt(1.0 * (rangeX * rangeX + rangeY * rangeY));
                            if(currPointRange < minRange)
                            {
                                get_polygon = false;
                            }
                            else
                            {
                                i++;
                                continue;
                            }
                            sumarea = l_rect.width() * l_rect.height();//求面积
                            if(sumarea < sumarea_rect)//根据距离中心点坐标的远近
                            {
                                sumarea_rect = l_rect.width() * l_rect.height();
                                nearMidIndexRect = i;
                                op_data.cmd_type = DS_RECT;
                                op_data.id = l_hp_rect.rect_id;
                                nowselect.c = DS_RECT;
                                nowselect.s = i;
                                get_rect = true;
                            }
                        }
                        i++;
                    }
                    //遍历圆
                    QListIterator<ComCirclePara> item_circle(hp_circle_list);
                    ComCirclePara l_hp_circle;
                    i = 0;
                    int sumarea_circle = 999999;
                    int sumCircle = 0;
                    OP_DATA op_data_circle;
                    bool get_circle = false;
                    while(item_circle.hasNext())
                    {
                        l_hp_circle = item_circle.next();
                        //框左上角起始坐标
                        l_circle.setTopLeft(QPoint(l_hp_circle.center_xcoord - l_hp_circle.radius, l_hp_circle.center_ycoord - l_hp_circle.radius));
                        l_circle.setWidth(l_hp_circle.radius * 2);
                        l_circle.setHeight(l_hp_circle.radius * 2);
                        if(l_circle.contains(releasePoint))
                        {
                            sumCircle = l_circle.width() * l_circle.height();

                            sumarea = l_circle.width() * l_circle.height();//求面积,面积最小的最先选中
                            rect_centre_select.rx() = l_circle.topLeft().x() + l_circle.width()/2;     //框被选中的中心坐标x坐标
                            rect_centre_select.ry() = l_circle.topRight().y() + l_circle.height()/2;   //框被选中的中心坐标y坐标
                            int rangeX = (int)qAbs(rect_centre_select.rx() - releasePoint.x());
                            int rangeY = (int)qAbs(rect_centre_select.ry() - releasePoint.y());

                            int currPointRange = (int)sqrt(1.0 * (rangeX * rangeX + rangeY * rangeY));
                            if(currPointRange < minRange)
                            {
                                get_polygon = false;
                            }
                            else
                            {
                                i++;
                                continue;
                            }
                            if(sumarea < sumarea_rect && sumarea < sumarea_circle)//根据距离中心点坐标的远近
                            {
                                sumarea_circle = sumarea;
                                if(sumarea_rect < sumarea_circle)
                                {
                                    nowselect.c = DS_RECT;
                                    nowselect.s = nearMidIndexRect;
                                    get_circle = false;
                                    i++;
                                    continue;
                                }
                                op_data_circle.cmd_type = DS_CIRCLE;
                                op_data_circle.id = l_hp_circle.circle_id;
                                nowselect.c = DS_CIRCLE;
                                nowselect.s = i;
                                get_rect = false;
                                get_circle = true;
                            }
                        }
                        i++;
                    }

                    if(get_polygon == true)
                    {
                        qDebug() << __func__ << "op_data.cmd_type" << op_data.cmd_type << "op_data.id" << op_data.id << "nowselect.c" << nowselect.c << "nowselect.s"  << nowselect.s;
                        signal_pc_measure_active(op_data_polygon);
                        selectUpdate();
                        return;
                    }
                    if(get_circle == true)
                    {
                        signal_pc_measure_active(op_data_circle);
                        selectUpdate();
                        return;
                    }
                    if(get_rect == true)
                    {
                        signal_pc_measure_active(op_data);
                        selectUpdate();
                        return;
                    }
                    if(nowselect.c != DS_NON)
                    {
                        OP_DATA op_data;
                        op_data.cmd_type = DS_NON;
                        op_data.id = -1;
                        signal_pc_measure_active(op_data);
                        nowselect.c = DS_NON;
                        nowselect.s = -1;
                        update();
                        selectUpdate();
                    }
                    return;

                }
                else if(drawStatus == DS_POINT)
                {
                    //进入画点状态
                    //把点加如点列表
                    if( hp_point_list.count() < max_point_num )
                    {
                        ComPointPara ll_hp_point;

                        ll_hp_point.p_xcoord = releasePoint.x();    //点X坐标
                        ll_hp_point.p_ycoord = releasePoint.y();    //点Y坐标

                        pointIndex = pointIndex+1;
                        ll_hp_point.point_id = pointIndex;   //测温编号

                        ll_hp_point.refer_flag = 0;

                        ll_hp_point.p_distance100 = g_distance100;
                        ll_hp_point.p_radiance100 = g_radiance100;

                        ll_hp_point.p_radTable_switch = g_radTable_switch;
                        ll_hp_point.p_radTable_id = g_radTable_id;
                        ll_hp_point.p_radTable_value100 = g_radTable_value100;
                        hp_point_list.append(ll_hp_point);
                        if(define_zoom)
                        {
                            if(HP_S350_or_S300)
                            {
                                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/167;
                            }else{
                                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord*100/167;
                                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord*100/176;
                            }

                            signal_pc_measure_set_point_add(ll_hp_point);
                        }else
                        {
                            signal_pc_measure_set_point_add(ll_hp_point);
                        }
                    }
                }
                else if(drawStatus == DS_POLYGON)
                {
                    if(m_isPolygonDraw)
                    {
                        if(m_polygonsPosList.count() < 20)
                        {
                            int currRange = 9999;
                            if(m_polygonsPosList.count() > 2)
                            {
                                currRange = (int)sqrt(1.0 * (qAbs((m_polygonsPosList.at(0).x() - releasePoint.x()) * (m_polygonsPosList.at(0).x() - releasePoint.x())) + qAbs((m_polygonsPosList.at(0).y() - releasePoint.y()) * (m_polygonsPosList.at(0).y() - releasePoint.y()))));
                            }
                            if(currRange < 30)
                            {
                                commit_current_polygon(true);
                            }
                            else
                            {
                                m_polygonsPosList.append(QPointF(releasePoint));
                                update();
                            }
                        }
                        else
                        {
                            commit_current_polygon(true);
                        }
                    }
                }
            }
            else
            {
                //进入画线或框状态流程

                //判断是否在画线或框状态
                if(drawStatus == DS_LINE)
                {
                    //进入画线流程

                    //添加线到线列表
                    if( hp_line_list.count() < max_line_num )
                    {
                        QLine l_line;
                        l_line.setP1(pressPoint);
                        l_line.setP2(releasePoint);
                        ComLinePara ll_hp_line;

                        ll_hp_line.l_xcoord = l_line.p1().x();
                        ll_hp_line.l_ycoord = l_line.p1().y();
                        ll_hp_line.l_x1coord = l_line.p2().x();
                        ll_hp_line.l_y1coord = l_line.p2().y();
                        qDebug() << "ll_hp_line.l_xcoord" << ll_hp_line.l_xcoord << "ll_hp_line.l_ycoord" << ll_hp_line.l_ycoord << "ll_hp_line.l_x1coord" << ll_hp_line.l_x1coord << "ll_hp_line.l_y1coord" << ll_hp_line.l_y1coord;
                        if( ll_hp_line.l_xcoord >= 0 && ll_hp_line.l_ycoord >= 0 && ll_hp_line.l_x1coord >= 0 && ll_hp_line.l_y1coord >= 0 )
                        {
                            lineIndex =  lineIndex+1;
                            ll_hp_line.line_id = lineIndex;

                            ll_hp_line.refer_flag = 0;//
//                            ll_hp_line.line_vaild = 1;//
                            ll_hp_line.l_distance100 = g_distance100;
                            ll_hp_line.l_radiance100 = g_radiance100;

                            ll_hp_line.l_radTable_switch = g_radTable_switch;
                            ll_hp_line.l_radTable_id = g_radTable_id;
                            ll_hp_line.l_radTable_value100 = g_radTable_value100;

                            ll_hp_line.l_ReflectTemp100 = g_ReflectTemp100;
                            ll_hp_line.l_temptype = 0;

//                            if(!hir_analyse)
//                            {
                                hp_line_list.append(ll_hp_line);
//                            }

                             if(define_zoom)
                             {
                                 if(HP_S350_or_S300)
                                 {
                                     ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                                     ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/167;
                                     ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                                     ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/167;
                                 }else{
                                     ll_hp_line.l_xcoord = ll_hp_line.l_xcoord*100/167;
                                     ll_hp_line.l_ycoord =ll_hp_line.l_ycoord*100/176;
                                     ll_hp_line.l_x1coord = ll_hp_line.l_x1coord*100/167;
                                     ll_hp_line.l_y1coord = ll_hp_line.l_y1coord*100/176;
                                 }

                                  signal_pc_measure_set_line_add(ll_hp_line);
                             }else
                             {
                                  signal_pc_measure_set_line_add(ll_hp_line);
                             }
                        }
                    }

                }
                  //进入画框流程
                else if(drawStatus == DS_RECT)
                {
                    //进入画框流程

                    //添加框到框列表
                    if( hp_rect_list.count() < max_rect_num )
                    {
                        ComRectPara l_hp_rect;
                        l_hp_rect.origin_xcoord = (pressPoint.x()<releasePoint.x())?pressPoint.x():releasePoint.x();
                        l_hp_rect.origin_ycoord = (pressPoint.y()<releasePoint.y())?pressPoint.y():releasePoint.y();
                        l_hp_rect.rect_wide = qAbs(pressPoint.x()-releasePoint.x());
                        l_hp_rect.rect_high = qAbs(pressPoint.y()-releasePoint.y());

                        if( l_hp_rect.origin_xcoord >= 0 && l_hp_rect.origin_ycoord >= 0 )
                        {
                            if(l_hp_rect.rect_wide < MIN_RECT_WIDTH)
                                l_hp_rect.rect_wide = MIN_RECT_WIDTH;
                            if(l_hp_rect.rect_high < MIN_RECT_HEIGHT)
                                l_hp_rect.rect_high = MIN_RECT_HEIGHT;

                            rectIndex = rectIndex +1;
                            l_hp_rect.rect_id = rectIndex;


                            l_hp_rect.remapping_color_id = m_currSebiao;
                            l_hp_rect.remapping_switch = 0;
                            l_hp_rect.refer_flag = 0;
                            l_hp_rect.rect_distance100 = g_distance100;
                            l_hp_rect.rect_ReflectTemp100 = g_ReflectTemp100;
                            l_hp_rect.r_radiance100 = g_radiance100;
                            l_hp_rect.temptype = 0;

                            l_hp_rect.r_radTable_switch = g_radTable_switch;
                            l_hp_rect.r_radTable_id = g_radTable_id;
                            l_hp_rect.r_radTable_value100 = g_radTable_value100;

//                            if(!hir_analyse)
//                            {
                                hp_rect_list.append(l_hp_rect);
//                            }

                            if(define_zoom)
                            {
                                if(HP_S350_or_S300)
                                {
                                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
                                }else{
                                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/176;
                                    l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                                    l_hp_rect.rect_high =  l_hp_rect.rect_high*100/176;
                                }

                                 signal_pc_measure_set_rect_add(l_hp_rect);
                            }else
                            {
                                signal_pc_measure_set_rect_add(l_hp_rect);
                            }
                            getMaxRect();//获取最大的框
                        }
                    }
                }
                //进入画原流程
                else if(drawStatus == DS_CIRCLE)
                {
                    qDebug() <<"DS_CIRCLE" << hp_circle_list.count();
                  //进入画原流程
                  if( hp_circle_list.count() < max_circle_num )
                  {
                      ComCirclePara l_hp_circle;
//                      QPoint startPoint(mouse_start_x,mouse_start_y);
//                      QPoint endPoint(releasePoint.x(),releasePoint.y());
                      QPoint center = (pressPoint + releasePoint) / 2;
                      int radius = QLineF(pressPoint, releasePoint).length() / 2;

                      l_hp_circle.radius = radius;
                      l_hp_circle.center_xcoord = center.x();
                      l_hp_circle.center_ycoord = center.y();
                        qDebug("l_hp_circle.center_xcoord %d,l_hp_circle.radius %d , l_hp_circle.center_ycoord %d"
                               , l_hp_circle.center_xcoord, l_hp_circle.radius, l_hp_circle.center_ycoord);
                      if( l_hp_circle.center_xcoord >= 0 && l_hp_circle.center_ycoord >= 0 )
                      {
                          if(l_hp_circle.radius < MIN_RECT_WIDTH)
                              l_hp_circle.radius = MIN_RECT_WIDTH;

                          circleIndex = circleIndex +1;
                          l_hp_circle.circle_id = circleIndex;
                          l_hp_circle.refer_flag = 0;
                          l_hp_circle.c_distance100 = g_distance100;
                          l_hp_circle.c_radiance100 = g_radiance100;
                          l_hp_circle.c_temptype = 0;

                          l_hp_circle.c_radTable_switch = g_radTable_switch;
                          l_hp_circle.c_radTable_id = g_radTable_id;
                          l_hp_circle.c_radTable_value100 = g_radTable_value100;

//                            if(!hir_analyse)
//                            {
                              hp_circle_list.append(l_hp_circle);
//                            }
                            qDebug() << "define zoom" << define_zoom;
                          if(define_zoom)
                          {
                              if(HP_S350_or_S300)
                              {
                                  l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*100/167;
                                  l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*100/167;
                                  l_hp_circle.radius = l_hp_circle.radius*100/167;
                              }else{
                                  l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*100/167;
                                  l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*100/167;
                                  l_hp_circle.radius = l_hp_circle.radius*100/167;
                              }

                              qDebug() <<"DS_CIRCLE" << hp_circle_list.count();
                              signal_pc_measure_set_circle_add(l_hp_circle);
                          }else
                          {
                              qDebug("l_hp_circle.center_xcoord %d,l_hp_circle.radius %d , l_hp_circle.center_ycoord %d"
                                     , l_hp_circle.center_xcoord, l_hp_circle.radius, l_hp_circle.center_ycoord);
                              signal_pc_measure_set_circle_add(l_hp_circle);
                          }
                      }
                  }
              }
              else
              {
                  //不处理
                  return;
              }

            }
            isDrawing = false;
            update();
    }
}
//2018 .4.20    dasidian
void Hp_Display::mouseMoveEvent(QMouseEvent *ev)
{
    signal_update_lcdoff_time(false);
    if(sketch_state==true)
    {
        sketch_point  sketch_temp;
        if(define_640_512)
        {
            sketch_temp.point_x =ev->pos().x();
            sketch_temp.point_y= ev->pos().y() * SCF_Y_MUL;
        }
        else if(define_zoom)
        {
            sketch_temp.point_x =ev->pos().x() * 100/167;
            sketch_temp.point_y= ev->pos().y() * 100/167;
        }else{
            sketch_temp.point_x =ev->pos().x();
            sketch_temp.point_y= ev->pos().y();
        }
        signal_pc_image_set_sketch_draw( sketch_temp);
    }
    mouse_move =true;
    //*************************************2018.4.20   sidian
    int mouse_x;
    int mouse_y;
    QString pos =  QString("%1, %2").arg(ev->pos().x()).arg(ev->pos().y()); //获取当前位置的坐标
    mouse_x = ev->pos().x();
    mouse_y = ev->pos().y();

    if(define_640_512)
    {
        ev->pos().setY(ev->y() * SCF_Y_MUL);
    }
    if( !isVisibleLight )
    {
        //point
            if(true ==hidemenu_point)
            {
                if(true == point.point_select){
                    point.point_x = mouse_x - point.press_x +point.begin_x;
                    point.point_y = mouse_y - point.press_y + point.begin_y;
                    //点被选中(框)
                    lable_sidian->setGeometry(point.point_x - point.point_widget , point.point_y - point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1);
                }
            }
        //rect
            if(true == hidemenu_rect)
            {
                if( decide_state.shape_was_pich == true)
                {

                    //根据改变方式给坐标赋值
                    if(11 == fu_zhu.change_style){
                        if((mouse_x <=fu_zhu.begin_x +fu_zhu.begin_widget) && (mouse_y <= fu_zhu.begin_y + fu_zhu.begin_hight ))       //左上
                        {
                            rect.rect_x = mouse_x;
                            rect.rect_y = mouse_y;
                            rect.rect_widget =fu_zhu.begin_x - mouse_x + fu_zhu.begin_widget ;
                            rect.rect_hight = fu_zhu.begin_y - mouse_y +fu_zhu.begin_hight;
                        };
                    }else if(12 == fu_zhu.change_style){                                                                                                //xx            //左边
                        if(mouse_x <=fu_zhu.begin_x +fu_zhu.begin_widget)
                        {
                            rect.rect_x = mouse_x;
                            rect.rect_y = fu_zhu.begin_y;
                            rect.rect_widget =fu_zhu.begin_x - mouse_x + fu_zhu.begin_widget;
                            rect.rect_hight = fu_zhu.begin_hight;

                        }
                    }else if(13 == fu_zhu.change_style){                                                                                        //xx                //左下
                        if((mouse_x <=fu_zhu.begin_x +fu_zhu.begin_widget) && (mouse_y >= fu_zhu.begin_y))
                        {
                            rect.rect_x = mouse_x;
                            rect.rect_y = fu_zhu.begin_y;
                            rect.rect_widget =fu_zhu.begin_x - mouse_x + fu_zhu.begin_widget;
                            rect.rect_hight =mouse_y - fu_zhu.begin_y;
                        };
                    }else if(31 == fu_zhu.change_style ){                                                                               //右上
                        if( (mouse_x >= fu_zhu.begin_x ) && ( mouse_y <= fu_zhu.begin_y + fu_zhu.begin_hight ))
                        {
                            rect.rect_x = fu_zhu.begin_x;
                            rect.rect_y = mouse_y;
                            rect.rect_widget = mouse_x - fu_zhu.begin_x;
                            rect.rect_hight = fu_zhu.begin_hight + (fu_zhu.begin_y - mouse_y  );
                        }
                    }else if(32 == fu_zhu.change_style ){                                                                               //右边
                        if( mouse_x >= fu_zhu.begin_x )
                        {
                            rect.rect_x = fu_zhu.begin_x;
                            rect.rect_y = fu_zhu.begin_y;
                            rect.rect_widget = mouse_x - fu_zhu.begin_x;
                            rect.rect_hight = fu_zhu.begin_hight;

                        }
                    }else if(33 == fu_zhu.change_style ){                                                                                //右下
                        if((mouse_x >= fu_zhu.begin_x) && ( mouse_y >= fu_zhu.begin_y ))
                        {
                            rect.rect_x = fu_zhu.begin_x;
                            rect.rect_y = fu_zhu.begin_y;
                            rect.rect_widget = mouse_x - fu_zhu.begin_x;
                            rect.rect_hight = mouse_y - fu_zhu.begin_y;

                        }
                    }else if(21 == fu_zhu.change_style ){                                                                               //中上边
                        if( mouse_y <= ( fu_zhu.begin_y + fu_zhu.begin_hight) )
                        {
                            rect.rect_x = fu_zhu.begin_x;
                            rect.rect_y = mouse_y;
                            rect.rect_widget = fu_zhu.begin_widget;
                            rect.rect_hight = fu_zhu.begin_hight + (fu_zhu.begin_y - mouse_y);
                        }

                    }else if(23 == fu_zhu.change_style ){                                                                               //中下边
                        if(mouse_y >= fu_zhu.begin_y )
                         {
                            rect.rect_x = fu_zhu.begin_x;
                            rect.rect_y = fu_zhu.begin_y;
                            rect.rect_widget = fu_zhu.begin_widget;
                            rect.rect_hight = mouse_y - fu_zhu.begin_y;
                        }
                    }else if(22 == fu_zhu.change_style ){                                                                               //中间   （移动）
                        rect.rect_x = fu_zhu.begin_x + (mouse_x - fu_zhu.press_x);
                        rect.rect_y = fu_zhu.begin_y + (mouse_y - fu_zhu.press_y);
                        rect.rect_widget = fu_zhu.begin_widget;
                        rect.rect_hight = fu_zhu.begin_hight;
                    }else{
                         ;
                    }
                }
            }
            update();

            mouse_end_x = ev->pos().x();
            mouse_end_y = ev->pos().y();
            update();

            ComPointPara l_hp_point;
            ComLinePara l_hp_line;
            ComRectPara l_hp_rect;
            ComCirclePara l_hp_circle;
            ComPolygonPara l_hp_polygon;

            if(tmp%10 != 0)
            {
                tmp++;
                return;
            }
            tmp++;

            QPoint pt[9];//四角+边中点
            QRect l_rect;
            QPoint pt_circle[5];//四角+边中点
            QRect l_circle;
            bool zoomFlag = false;//真为缩小
            int circleWidth = 0;
            int circleHeight = 0;
            int minRangeIndex = 0;
            int minRange = 999999;

            switch(nowselect.c)
            {
            case DS_POINT:

                l_hp_point = hp_point_list.at(nowselect.s);

                if(qAbs(l_hp_point.p_xcoord - pressPoint.x())<30 && qAbs(l_hp_point.p_ycoord-pressPoint.y())<30)
                {
                    if(ev->pos().x() >= 0  && ev->pos().x() <=640)
                    {
                        l_hp_point.p_xcoord = ev->pos().x();
                    }else if(ev->pos().x() <0 ){
                        l_hp_point.p_xcoord = 0;
                    }else if(ev->pos().x() >640 ){
                        l_hp_point.p_xcoord = 640;
                    }

                    if(ev->pos().y() >= 0  && ev->pos().y() <=bottom_edge)
                    {
                        l_hp_point.p_ycoord = ev->pos().y();
                    }else if(ev->pos().y() <0 ){
                        l_hp_point.p_ycoord = 0;
                    }else if(ev->pos().y() >bottom_edge ){
                        l_hp_point.p_ycoord = bottom_edge;
                    }

                    pressPoint.setX(ev->pos().x());
                    pressPoint.setY(ev->pos().y());

                    hp_point_list.replace(nowselect.s,l_hp_point);

                    if(define_zoom)
                    {
                        if(HP_S350_or_S300)
                        {
                            l_hp_point.p_xcoord = l_hp_point.p_xcoord *100/167;
                            l_hp_point.p_ycoord = l_hp_point.p_ycoord *100/167;
                        }else{
                            l_hp_point.p_xcoord = l_hp_point.p_xcoord *100/167;
                            l_hp_point.p_ycoord = l_hp_point.p_ycoord *100/176;
                        }

                        signal_pc_measure_set_point_update(l_hp_point);
                    }else
                    {
                        if(define_640_512)
                        {
                            l_hp_point.p_ycoord = l_hp_point.p_ycoord *1.07;
                        }
                        signal_pc_measure_set_point_update(l_hp_point);
                    }

                    update();
                }

                break;
            case DS_LINE:
                l_hp_line = hp_line_list.at(nowselect.s);

                if(qAbs(l_hp_line.l_xcoord-pressPoint.x())<30 && qAbs(l_hp_line.l_ycoord-pressPoint.y())<30)
                {
                    if(ev->pos().x() >= 0  && ev->pos().x() <=640)
                    {
                        l_hp_line.l_xcoord = ev->pos().x();
                    }else if(ev->pos().x() <0 ){
                        l_hp_line.l_xcoord = 0;
                    }else if(ev->pos().x() >640 ){
                        l_hp_line.l_xcoord = 640;
                    }

                    if(ev->pos().y() >= 0  && ev->pos().y() <=bottom_edge)
                    {
                       l_hp_line.l_ycoord = ev->pos().y();
                    }else if(ev->pos().y() <0 ){
                        l_hp_line.l_ycoord = 0;
                    }else if(ev->pos().y() >bottom_edge ){
                        l_hp_line.l_ycoord = bottom_edge;
                    }
                }
                else if(qAbs(l_hp_line.l_x1coord-pressPoint.x())<30 && qAbs(l_hp_line.l_y1coord-pressPoint.y())<30)
                {
                    if(ev->pos().x() >= 0  && ev->pos().x() <=640)
                    {
                        l_hp_line.l_x1coord = ev->pos().x();
                    }else if(ev->pos().x() <0 ){
                        l_hp_line.l_x1coord = 0;
                    }else if(ev->pos().x() >640 ){
                        l_hp_line.l_x1coord = 640;
                    }

                    if(ev->pos().y() >= 0  && ev->pos().y() <=bottom_edge)
                    {
                       l_hp_line.l_y1coord= ev->pos().y();
                    }else if(ev->pos().y() <0 ){
                        l_hp_line.l_y1coord = 0;
                    }else if(ev->pos().y() >bottom_edge ){
                       l_hp_line.l_y1coord = bottom_edge;
                    }
                }
                else
                {
                    break;
                }

                pressPoint.setX(ev->pos().x());
                pressPoint.setY(ev->pos().y());

                hp_line_list.replace(nowselect.s,l_hp_line);
                if(define_zoom)
                {
                    if(HP_S350_or_S300)
                    {
                        l_hp_line.l_x1coord = l_hp_line.l_x1coord*100/167;
                        l_hp_line.l_xcoord = l_hp_line.l_xcoord*100/167;
                        l_hp_line.l_y1coord = l_hp_line.l_y1coord *100/167;
                        l_hp_line.l_ycoord = l_hp_line.l_ycoord*100/167;
                    }else{
                        l_hp_line.l_x1coord = l_hp_line.l_x1coord*100/167;
                        l_hp_line.l_xcoord = l_hp_line.l_xcoord*100/167;
                        l_hp_line.l_y1coord = l_hp_line.l_y1coord *100/176;
                        l_hp_line.l_ycoord = l_hp_line.l_ycoord*100/176;
                    }
                    signal_pc_measure_set_line_update(l_hp_line);
                }else
                {

                    if(define_640_512)
                    {
                        l_hp_line.l_x1coord = l_hp_line.l_x1coord;
                        l_hp_line.l_xcoord = l_hp_line.l_xcoord*1.07;
                        l_hp_line.l_y1coord = l_hp_line.l_y1coord;
                        l_hp_line.l_ycoord = l_hp_line.l_ycoord*1.07;
                    }
                       signal_pc_measure_set_line_update(l_hp_line);
                }

                update();
                break;
            case DS_RECT:

                l_hp_rect = hp_rect_list.at(nowselect.s);

                l_rect.setTopLeft(QPoint(l_hp_rect.origin_xcoord,l_hp_rect.origin_ycoord));
                l_rect.setWidth(l_hp_rect.rect_wide);
                l_rect.setHeight(l_hp_rect.rect_high);

                //获取框的初始状态
                pt[0] = l_rect.topLeft();//左上角
                pt[1] = l_rect.topRight();//右上角
                pt[2] = l_rect.bottomRight();//右下角
                pt[3] = l_rect.bottomLeft();//左下角

                pt[4] = pt[0];                                       //上边中点
                pt[4].rx() += l_rect.width()/2;

                pt[5] = pt[1];                                        //右边中点
                pt[5].ry() += l_rect.height()/2;

                pt[6] = pt[3];                                        //下边中点
                pt[6].rx() += l_rect.width()/2;

                pt[7] = pt[0];                                           //左边中点
                pt[7].ry() += l_rect.height()/2;

                pt[8] = pt[0];                                          //框中点
                pt[8].rx() += l_rect.width()/2;
                pt[8].ry() += l_rect.height()/2;

            //    bool move;
            //    move = false;
                if(qAbs(pt[0].x() - pressPoint.x()) <30 && qAbs(pt[0].y() - pressPoint.y()) < 30)           //左上角移动
                {

                    if(ev->pos().x() >=0 && ev->pos().y() >= 0)
                    {
                        l_rect.setLeft(ev->pos().x());
                        l_rect.setTop(ev->pos().y());

                    }
                }
                else if(qAbs(pt[1].x() - pressPoint.x()) <30 && qAbs(pt[1].y() - pressPoint.y()) < 30)          //右上角移动
                {

                    if(ev->pos().x() <= 640 && ev->pos().y() >= 0)
                    {
                        l_rect.setTop(ev->pos().y());
                        l_rect.setRight(ev->pos().x());

                    }
                }
                else if(qAbs(pt[2].x() - pressPoint.x()) <30 && qAbs(pt[2].y() - pressPoint.y()) < 30)         //右下角移动
                {
                    if(ev->pos().x() <=640 && ev->pos().y()<=bottom_edge)
                    {
                        l_rect.setBottom(ev->pos().y());
                        l_rect.setRight(ev->pos().x());
                    }
                }
                else if(qAbs(pt[3].x() - pressPoint.x()) <30 && qAbs(pt[3].y() - pressPoint.y()) < 30)          //左下角移动
                {
                    if(ev->pos().x() >=0 && ev->pos().y()<=bottom_edge)
                    {
                        l_rect.setBottom(ev->pos().y());
                        l_rect.setLeft(ev->pos().x());
                    }
                }
                else if((pressPoint.x()<pt[1].x() && pressPoint.x()>pt[0].x() ) && qAbs(pt[4].y() - pressPoint.y()) < 30)          //上边移动 。
                {
                    if(ev->pos().y() >=0 )
                    {
                       l_rect.setTop(ev->pos().y());
                    }else{
                        l_rect.setTop(0);
                    }
                }
                else if(qAbs(pt[5].x() - pressPoint.x()) <30 && (pressPoint.y() <pt[2].y() && pressPoint.y()>pt[1].y()))         //右边移动
                {

                    if(ev->pos().x()<= 639 )
                    {
                        l_rect.setRight(ev->pos().x());
                    }else{
                        l_rect.setRight(639);
                    }
                }
                else if((pressPoint.x()<pt[1].x() && pressPoint.x()>pt[0].x()) && qAbs(pt[6].y() - pressPoint.y()) < 30)          //下边移动
                {
                    if(ev->pos().y() <= bottom_edge - 1 )
                    {
                        l_rect.setBottom(ev->pos().y());
                    }else{
                        l_rect.setBottom(bottom_edge - 1);
                    }
                }
                else if(qAbs(pt[7].x() - pressPoint.x()) <30 && (pressPoint.y()<pt[2].y() && pressPoint.y()>pt[1].y()))           //左边移动
                {
                    if(ev->pos().x() >=0)
                    {
                         l_rect.setLeft(ev->pos().x());
                    }else{
                        l_rect.setLeft(0);
                    }
                }
                else if((pressPoint.x()<pt[1].x() && pressPoint.x()>pt[0].x()) && (pressPoint.y()<pt[2].y() && pressPoint.y()>pt[1].y()))
                {
                    int wide ;
                    int high;
                    QPoint point_1;

                    if((l_hp_rect.rect_wide % 2) ==0)
                    {
                        wide = l_hp_rect.rect_wide/2;
                    }else{
                        wide = l_hp_rect.rect_wide/2+1;
                    }
                    if((l_hp_rect.rect_high % 2) ==0)
                    {
                        high = l_hp_rect.rect_high/2;
                    }else{
                        high = l_hp_rect.rect_high/2+1;
                    }

                    //计算移动过程中 ，中心点坐标的变化
                QPoint centre_new;
                centre_new.rx() = rect_centre_select.x() +(ev->pos().x() - rect_start_press.x());
                centre_new.ry() = rect_centre_select.y() +(ev->pos().y() - rect_start_press.y());
                //限制移动范围在界面内
                if((centre_new.x() - wide >=0)     && (centre_new.x() +wide <=640))
                {
                     if((centre_new.y() - high >=0)     && (centre_new.y() +high <=bottom_edge))
                    {
                        l_rect.moveCenter(centre_new);
                        pressPoint.setX(ev->pos().x());             //设置按压的坐标
                        pressPoint.setY(ev->pos().y());
            //               move = true;
                    }
                };
                }
                else
                {
                    break;
                }

                pressPoint.setX(ev->pos().x());
                pressPoint.setY(ev->pos().y());

                //限定 x+w  y+h 在界面内
                if(l_rect.left() +l_rect.width()>639 )
                    l_rect.setWidth( 639-l_rect.left());

                if(l_rect.top() + l_rect.height()>bottom_edge - 1)
                    l_rect.setHeight(bottom_edge - 1-l_rect.top());
                //限定 最小宽高、xy
                if(l_rect.width() < MIN_RECT_WIDTH)
                    l_rect.setWidth(MIN_RECT_WIDTH);
                if(l_rect.height() < MIN_RECT_HEIGHT)
                    l_rect.setHeight(MIN_RECT_HEIGHT);

                //限定左边左边
                if(l_rect.left()<0)
                    l_rect.setLeft(0);
                if(l_rect.left() > 639-MIN_RECT_WIDTH)
                {
                    l_rect.setLeft(639-MIN_RECT_WIDTH);
                    l_rect.setWidth(MIN_RECT_WIDTH);
                }
                //限定上边坐标
                if(l_rect.top()<0)
                    l_rect.setTop(0);
                if(l_rect.top()>bottom_edge - 1-MIN_RECT_HEIGHT)
                {
                    l_rect.setTop(bottom_edge - 1-MIN_RECT_HEIGHT);
                    l_rect.setHeight(MIN_RECT_HEIGHT);
                }

                l_hp_rect.origin_xcoord = l_rect.left();
                l_hp_rect.origin_ycoord = l_rect.top();
                l_hp_rect.rect_wide = l_rect.width();
                l_hp_rect.rect_high = l_rect.height();

                hp_rect_list.replace(nowselect.s,l_hp_rect);
                if( define_zoom )
                {
                    if(HP_S350_or_S300)
                    {
                        l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                        l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                        l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                        l_hp_rect.rect_high = l_hp_rect.rect_high*100/167;
                    }else{
                        l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                        l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/176;
                        l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                        l_hp_rect.rect_high = l_hp_rect.rect_high*100/176;
                    }

                }
                if(define_640_512)
                {
                    l_hp_rect.origin_xcoord = l_rect.left();
                    l_hp_rect.origin_ycoord = l_rect.top()*1.07;
                    l_hp_rect.rect_wide = l_rect.width();
                    l_hp_rect.rect_high = l_rect.height() *1.07;
                }
                signal_pc_measure_set_rect_update(l_hp_rect);
                getMaxRect();

                update();
                break;
            case DS_CIRCLE:
                l_hp_circle = hp_circle_list.at(nowselect.s);

                //获取框的初始状态
                pt[0] = QPoint(l_hp_circle.center_xcoord + l_hp_circle.radius,l_hp_circle.center_ycoord);//右点
                pt[1] = QPoint(l_hp_circle.center_xcoord - l_hp_circle.radius,l_hp_circle.center_ycoord);//左点
                pt[2] = QPoint(l_hp_circle.center_xcoord,l_hp_circle.center_ycoord - l_hp_circle.radius);//上点
                pt[3] = QPoint(l_hp_circle.center_xcoord,l_hp_circle.center_ycoord + l_hp_circle.radius);//下点
                pt[4] = QPoint(l_hp_circle.center_xcoord,l_hp_circle.center_ycoord);//中点


                if(qAbs(pt[0].x() - pressPoint.x()) <30 && qAbs(pt[0].y() - pressPoint.y()) < 30)           //右点
                {
                    int radius_ret = ev->pos().x() - l_hp_circle.center_xcoord;
                    if(l_hp_circle.center_ycoord + radius_ret <= bottom_edge - 1 && l_hp_circle.center_ycoord - radius_ret >= 0 && ev->pos().x() <= 640)
                    {
    //                    qDebug() << " 1111111111111-------------1111111111 ";
                        l_hp_circle.radius = ev->pos().x() - l_hp_circle.center_xcoord;
                    }
                }
                else if(qAbs(pt[1].x() - pressPoint.x()) <30 && qAbs(pt[1].y() - pressPoint.y()) < 30)          //左点
                {
                    int radius_ret = l_hp_circle.center_xcoord - ev->pos().x();
                    if(l_hp_circle.center_ycoord + radius_ret <= bottom_edge - 1 && l_hp_circle.center_ycoord - radius_ret >= 0 && ev->pos().x() >= 0)
                    {
    //                    qDebug() << " 22222222222222-------------2222222222222 ";
                        l_hp_circle.radius = l_hp_circle.center_xcoord - ev->pos().x();
                    }
                }
                else if(qAbs(pt[2].x() - pressPoint.x()) <30 && qAbs(pt[2].y() - pressPoint.y()) < 30)         //上点
                {
                    int radius_ret = l_hp_circle.center_ycoord - ev->pos().x();
                    if(l_hp_circle.center_xcoord + radius_ret <= 640 && l_hp_circle.center_xcoord - radius_ret >= 0 && ev->pos().y() >= 0)
                    {
    //                    qDebug() << " 33333333333333-------------3333333333333 ";
                        l_hp_circle.radius = l_hp_circle.center_ycoord - ev->pos().y();
                    }
                }
                else if(qAbs(pt[3].x() - pressPoint.x()) <30 && qAbs(pt[3].y() - pressPoint.y()) < 30)          //下点
                {
                    int radius_ret = ev->pos().x() - l_hp_circle.center_ycoord;
                    if(l_hp_circle.center_xcoord + radius_ret <= 640 && l_hp_circle.center_xcoord - radius_ret >= 0 && ev->pos().y() <= bottom_edge - 1)
                    {
    //                    qDebug() << " 4444444444444444-------------4444444444444 ";
                        l_hp_circle.radius = ev->pos().y() - l_hp_circle.center_ycoord;
                    }
                }
                else if((pressPoint.x()<pt[0].x() && pressPoint.x()>pt[1].x()) && (pressPoint.y()<pt[3].y() && pressPoint.y()>pt[2].y()))//中点
                {
                    //计算移动过程中 ，中心点坐标的变化
                    if(movePos.x() != ev->pos().x() || movePos.y() != ev->pos().y())//当手指不动时，不触发位移
                    {
                        QPoint centre_new;
                        centre_new.setX(l_hp_circle.center_xcoord + (ev->pos().x() - pressPoint.x()));
                        centre_new.setY(l_hp_circle.center_ycoord +(ev->pos().y() - pressPoint.y()));

                        if((centre_new.x() - l_hp_circle.radius >=0)     && (centre_new.x() + l_hp_circle.radius <= 640))
                        {
                            if((centre_new.y() - l_hp_circle.radius >=0)     && (centre_new.y() + l_hp_circle.radius <= bottom_edge - 1))
                            {
    //                            qDebug() << " 555555555-------------5555555555 ";
                                l_hp_circle.center_xcoord = centre_new.x();
                                l_hp_circle.center_ycoord = centre_new.y();
                                pressPoint.setX(ev->pos().x());             //设置按压的坐标
                                pressPoint.setY(ev->pos().y());
                            }
                        }
                    }
                }
                else
                {
                    break;
                }
                pressPoint.setX(ev->pos().x());
                pressPoint.setY(ev->pos().y());
                if(l_hp_circle.center_xcoord < 0)
                {
                    l_hp_circle.center_xcoord = 0;
                }
                if(l_hp_circle.center_xcoord > 639)
                {
                    l_hp_circle.center_xcoord = 639;
                }
                if(l_hp_circle.center_ycoord < 0)
                {
                    l_hp_circle.center_ycoord = 0;
                }
                if(l_hp_circle.center_ycoord > bottom_edge - 1)
                {
                    l_hp_circle.center_ycoord = bottom_edge - 1;
                }
                hp_circle_list.replace(nowselect.s,l_hp_circle);
                if( define_zoom )
                {
                    if(HP_S350_or_S300)
                    {
                        l_hp_circle.center_xcoord = l_hp_circle.center_xcoord*100/167;
                        l_hp_circle.center_ycoord = l_hp_circle.center_ycoord*100/167;
                        l_hp_circle.radius = l_hp_circle.radius*100/167;
                    }

                }
                signal_pc_measure_set_circle_update(l_hp_circle);

                update();
                break;
            case DS_POLYGON:
                l_hp_polygon = hp_polygon_list.at(nowselect.s);
                m_polygonsPosList.clear();
                if(!m_isPolygonSelectMove)
                {
                    for(int i = 0; i < l_hp_polygon.nNode; i++)
                    {
                        int currRange = (int)sqrt(1.0 * (qAbs((l_hp_polygon.nX[i] - pressPoint.x()) * (l_hp_polygon.nX[i] - pressPoint.x())) + qAbs((l_hp_polygon.nY[i] - pressPoint.y()) * (l_hp_polygon.nY[i] - pressPoint.y()))));
                        if(currRange < minRange)
                        {
                            m_isPolygonSelectMove = true;
                            m_polygonSelectMoveIndex = i;
                            minRange = currRange;
                        }
                    }
                }
                if(m_isPolygonSelectMove && (-1 != m_polygonSelectMoveIndex))
                {
                    l_hp_polygon.nX[m_polygonSelectMoveIndex] = ev->pos().x();
                    l_hp_polygon.nY[m_polygonSelectMoveIndex] = ev->pos().y();
                    hp_polygon_list.replace(nowselect.s, l_hp_polygon);
                    if( define_zoom )
                    {
                        for(int i = 0; i < l_hp_polygon.nNode; i++)
                        {
                            l_hp_polygon.nX[i] = l_hp_polygon.nX[i] * 100/167;
                            l_hp_polygon.nY[i] = l_hp_polygon.nY[i] * 100/167;
                        }
                    }
                    qDebug() << "PC_MEASURE_SET_POLYGON_UPDATE" << "minrangeIndex" << minRangeIndex << __LINE__;
                    signal_pc_measure_set_polygon_update(l_hp_polygon);
                }
                update();
                break;
            default:
                break;
            }
            movePos = ev->pos();
    }
}


void Hp_Display::display_set_max_num(int point, int line, int rect, int circle, int polygon)
{
    max_point_num = point;
    max_line_num = line;
    max_circle_num = circle;
    max_rect_num = rect;
    max_polygon_num = polygon;
}

void Hp_Display::commit_current_polygon(bool isCommit)
{
    if(!isCommit || (hp_polygon_list.count() >= max_polygon_num))
    {
        m_polygonsPosList.clear();
        update();
        return;
    }
    if(m_polygonsPosList.count() < 3)
    {
        m_polygonsPosList.clear();
        update();
        return;
    }
    ComPolygonPara currPolygon;
    polygonIndex++;
    currPolygon.polygon_id = polygonIndex;
    int top = 0, left = 0, bottom = 0, right = 0;
    int polygonCount = m_polygonsPosList.count();
    if(m_polygonsPosList.count() > 20)
    {
        polygonCount = 20;
    }

    currPolygon.nNode = m_polygonsPosList.count();
    currPolygon.refer_flag = 0;
    currPolygon.polygon_vaild = 1;
    currPolygon.p_distance100 = g_distance100;
    currPolygon.p_radiance100 = g_radiance100;
    currPolygon.p_ReflectTemp100 = g_ReflectTemp100;
    currPolygon.p_temptype = 0;

    currPolygon.p_radTable_switch = g_radTable_switch;
    currPolygon.p_radTable_id = g_radTable_id;
    currPolygon.p_radTable_value100 = g_radTable_value100;
    for(int i = 0; i < m_polygonsPosList.count(); i++)
    {
        qDebug() << m_polygonsPosList.at(i);
        int currX = m_polygonsPosList.at(i).x();
        int currY = m_polygonsPosList.at(i).y();
        currPolygon.nX[i] = currX;
        currPolygon.nY[i] = currY;
    }
    hp_polygon_list.append(currPolygon);
    for(int i = 0; i < m_polygonsPosList.count(); i++)
    {
        if(define_zoom)
        {
            currPolygon.nX[i] = currPolygon.nX[i] * 100 / 167;
            currPolygon.nY[i] = currPolygon.nY[i] * 100 / 167;
        }
    }
    signal_pc_measure_set_polygon_add(currPolygon);
    m_polygonsPosList.clear();
//    hp_parrent->ui->checkBox_polygon->setChecked(false);
//    hp_parrent->ui->checkBox_polygon->clicked(false);
    update();
}

void Hp_Display::del_widget_click()
{
        delete_item();
        selectUpdate();
}

void Hp_Display::edit_widget_click()
{
    HpTempUnitConvert htuc;

    switch(nowselect.c)
        {
        case DS_POINT:
            hpplredit->ui->hs_reflect->setVisible(false);
            hpplredit->ui->hs_reflect->setVisible(false);
//         hpplredit->ui->cb_temptype->setVisible(false);
            hpplredit->ui->frame_temptype->setVisible(false);

            tmp_point_para = hp_point_list.at(nowselect.s);

            hpplredit->ui->hs_distance->setValue(tmp_point_para.p_distance100/100.0);

            hpplredit->ui->hs_radiance->setValue(tmp_point_para.p_radiance100);

            //界面 辐射率表赋初值
            hpplredit->part_radTable_switch = tmp_point_para.p_radTable_switch;
            hpplredit->part_radTable_id = tmp_point_para.p_radTable_id;
            hpplredit->part_radTable_value100 = tmp_point_para.p_radTable_value100;
            if( hpplredit->part_radTable_switch == 1)
               hpplredit->set_checkBox_radiance_state(true);
           else
               hpplredit->set_checkBox_radiance_state(false);

            if(hpplredit->part_radTable_id >= 0 && hpplredit->part_radTable_id<=24){
                hpplredit->ui->listWidget_radiance->setCurrentRow(hpplredit->part_radTable_id);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }else{
                hpplredit->ui->listWidget_radiance->setCurrentRow(0);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }

            if(tmp_point_para.refer_flag == 1)
                hpplredit->ui->cb_refer->setChecked(true);
            else
                hpplredit->ui->cb_refer->setChecked(false);

            hpplredit->show();
            break;

        case DS_LINE:
            hpplredit->ui->hs_reflect->setVisible(true);
            hpplredit->ui->hs_reflect->setVisible(true);
//         hpplredit->ui->cb_temptype->setVisible(true);
            hpplredit->ui->frame_temptype->setVisible(true);

            tmp_line_para = hp_line_list.at(nowselect.s);

            hpplredit->ui->hs_distance->setValue(tmp_line_para.l_distance100/100.0);

            hpplredit->ui->hs_radiance->setValue(tmp_line_para.l_radiance100);

            if(tmp_line_para.l_temptype == 3)
            {
                hpplredit->ui->cb_refer->setChecked(false);
                hpplredit->ui->cb_refer->setEnabled(false);
            }else
            {
                if(tmp_line_para.refer_flag == 1)//
                    hpplredit->ui->cb_refer->setChecked(true);
                else
                    hpplredit->ui->cb_refer->setChecked(false);
            }

            if(tmp_line_para.l_temptype <0)
            {
                tmp_line_para.l_temptype =0;
            }

            hpplredit->ui->cb_temptype->setCurrentIndex(tmp_line_para.l_temptype);
             hpplredit->ui->listWidget_temptype->setCurrentRow(tmp_line_para.l_temptype);
             hpplredit->ui->label_temptype_2->setText(hpplredit->ui->listWidget_temptype->currentItem()->text());

            hpplredit->ui->hs_reflect->setSuffix(htuc.getTempUnitString(tempunit));
            hpplredit->ui->hs_reflect->setValue(htuc.getTempValue(tempunit,tmp_line_para.l_ReflectTemp100)/100.0);

            //界面 辐射率表赋初值
            hpplredit->part_radTable_switch = tmp_line_para.l_radTable_switch;
            hpplredit->part_radTable_id = tmp_line_para.l_radTable_id;
            hpplredit->part_radTable_value100 = tmp_line_para.l_radTable_value100;

            if( hpplredit->part_radTable_switch == 1)
                hpplredit->set_checkBox_radiance_state(true);
            else
                hpplredit->set_checkBox_radiance_state(false);


            if(hpplredit->part_radTable_id >= 0 && hpplredit->part_radTable_id<=24){
                hpplredit->ui->listWidget_radiance->setCurrentRow(hpplredit->part_radTable_id);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }else{
                hpplredit->ui->listWidget_radiance->setCurrentRow(0);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }

            if(HP_ReflectTemp == 0)
            {
                hpplredit->ui->hs_reflect->close();
            }

            hpplredit->show();
            break;
        case DS_RECT:
            hpplredit->ui->hs_reflect->setVisible(true);
            hpplredit->ui->hs_reflect->setVisible(true);
            hpplredit->ui->frame_temptype->setVisible(true);

            tmp_rect_para = hp_rect_list.at(nowselect.s);
            hpplredit->ui->hs_distance->setValue(tmp_rect_para.rect_distance100/100.0);
            hpplredit->ui->hs_radiance->setValue(tmp_rect_para.r_radiance100);
            if(tmp_rect_para.temptype == 3)
            {
                hpplredit->ui->cb_refer->setChecked(false);
                hpplredit->ui->cb_refer->setEnabled(false);
            }else
            {
                if(tmp_rect_para.refer_flag == 1)
                    hpplredit->ui->cb_refer->setChecked(true);
                else
                    hpplredit->ui->cb_refer->setChecked(false);
            }
            if(tmp_rect_para.temptype <0)
            {
                tmp_rect_para.temptype =0;
            }
            hpplredit->ui->cb_temptype->setCurrentIndex(tmp_rect_para.temptype);
            hpplredit->ui->listWidget_temptype->setCurrentRow(tmp_rect_para.temptype);
            hpplredit->ui->label_temptype_2->setText(hpplredit->ui->listWidget_temptype->currentItem()->text());
            hpplredit->ui->hs_reflect->setSuffix(htuc.getTempUnitString(tempunit));
            hpplredit->ui->hs_reflect->setValue(htuc.getTempValue(tempunit,tmp_rect_para.rect_ReflectTemp100)/100.0);
            //界面 辐射率表赋初值
            hpplredit->part_radTable_switch = tmp_rect_para.r_radTable_switch;
            hpplredit->part_radTable_id = tmp_rect_para.r_radTable_id;
            hpplredit->part_radTable_value100 = tmp_rect_para.r_radTable_value100;
            if( hpplredit->part_radTable_switch == 1)
                hpplredit->set_checkBox_radiance_state(true);
            else
                hpplredit->set_checkBox_radiance_state(false);
            if(hpplredit->part_radTable_id >= 0 && hpplredit->part_radTable_id <=24){
                hpplredit->ui->listWidget_radiance->setCurrentRow(hpplredit->part_radTable_id);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }else{
                hpplredit->ui->listWidget_radiance->setCurrentRow(0);
                hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
            }
            if(m_isInsulation && tmp_rect_para.rect_id < 10)
            {
                hpplredit->ui->cb_rectTemp->show();
                if(m_selectInsValueMap.contains(tmp_rect_para.rect_id))
                    hpplredit->ui->cb_rectTemp->setChecked(true);
                else
                    hpplredit->ui->cb_rectTemp->setChecked(false);
            }
            else
            {
                hpplredit->ui->cb_rectTemp->close();
            }
            if(HP_ReflectTemp == 0)
            {
                hpplredit->ui->hs_reflect->close();
            }
            hpplredit->show();
            break;

    case DS_CIRCLE:
        hpplredit->ui->hs_reflect->setVisible(true);
        hpplredit->ui->hs_reflect->setVisible(true);
        hpplredit->ui->cb_linedepth->setVisible(false);
        hpplredit->ui->frame_temptype->setVisible(true);
        tmp_circle_para = hp_circle_list.at(nowselect.s);
        hpplredit->ui->hs_distance->setValue(tmp_circle_para.c_distance100/100.0);
        hpplredit->ui->hs_radiance->setValue(tmp_circle_para.c_radiance100);

        if(tmp_circle_para.c_temptype == 3)
        {
            hpplredit->ui->cb_refer->setChecked(false);
            hpplredit->ui->cb_refer->setEnabled(false);
        }else
        {
            if(tmp_circle_para.refer_flag == 1)
                hpplredit->ui->cb_refer->setChecked(true);
            else
                hpplredit->ui->cb_refer->setChecked(false);
        }

        if(tmp_circle_para.c_temptype < 0)
        {
            tmp_circle_para.c_temptype =0;
        }
        hpplredit->ui->cb_temptype->setCurrentIndex(tmp_circle_para.c_temptype);
        hpplredit->ui->listWidget_temptype->setCurrentRow(tmp_circle_para.c_temptype);
        hpplredit->ui->label_temptype_2->setText(hpplredit->ui->listWidget_temptype->currentItem()->text());
        hpplredit->ui->hs_reflect->setSuffix(htuc.getTempUnitString(tempunit));
        hpplredit->ui->hs_reflect->setValue(htuc.getTempValue(tempunit,tmp_circle_para.c_ReflectTemp100)/100.0);
        //界面 辐射率表赋初值
        hpplredit->part_radTable_switch = tmp_circle_para.c_radTable_switch;
        hpplredit->part_radTable_id = tmp_circle_para.c_radTable_id;
        hpplredit->part_radTable_value100 = tmp_circle_para.c_radTable_value100;

        if( hpplredit->part_radTable_switch == 1)
            hpplredit->set_checkBox_radiance_state(true);
        else
            hpplredit->set_checkBox_radiance_state(false);

        if(hpplredit->part_radTable_id >= 0 && hpplredit->part_radTable_id <=24){
            hpplredit->ui->listWidget_radiance->setCurrentRow(hpplredit->part_radTable_id);
            hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
        }else{
            hpplredit->ui->listWidget_radiance->setCurrentRow(0);
            hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
        }

        if(HP_ReflectTemp == 0)
        {
            hpplredit->ui->hs_reflect->close();
        }
        hpplredit->show();
        break;
    case DS_POLYGON:
        hpplredit->ui->hs_reflect->setVisible(true);
        hpplredit->ui->hs_reflect->setVisible(true);
        hpplredit->ui->cb_linedepth->setVisible(false);
        hpplredit->ui->frame_temptype->setVisible(true);
        tmp_polygon_para = hp_polygon_list.at(nowselect.s);
        hpplredit->ui->hs_distance->setValue(tmp_polygon_para.p_distance100/100.0);
        hpplredit->ui->hs_radiance->setValue(tmp_polygon_para.p_radiance100);

        if(tmp_polygon_para.p_temptype == 3)
        {
            hpplredit->ui->cb_refer->setChecked(false);
            hpplredit->ui->cb_refer->setEnabled(false);
        }else
        {
            if(tmp_polygon_para.refer_flag == 1)
                hpplredit->ui->cb_refer->setChecked(true);
            else
                hpplredit->ui->cb_refer->setChecked(false);
        }

        if(tmp_polygon_para.p_temptype < 0)
        {
            tmp_polygon_para.p_temptype = 0;
        }
        hpplredit->ui->cb_temptype->setCurrentIndex(tmp_polygon_para.p_temptype);
        hpplredit->ui->listWidget_temptype->setCurrentRow(tmp_polygon_para.p_temptype);
        hpplredit->ui->label_temptype_2->setText(hpplredit->ui->listWidget_temptype->currentItem()->text());
        hpplredit->ui->hs_reflect->setSuffix(htuc.getTempUnitString(tempunit));
        hpplredit->ui->hs_reflect->setValue(htuc.getTempValue(tempunit,tmp_polygon_para.p_ReflectTemp100)/100.0);
        //界面 辐射率表赋初值
        hpplredit->part_radTable_switch = tmp_polygon_para.p_radTable_switch;
        hpplredit->part_radTable_id = tmp_polygon_para.p_radTable_id;
        hpplredit->part_radTable_value100 = tmp_polygon_para.p_radTable_value100;

        if( hpplredit->part_radTable_switch == 1)
            hpplredit->set_checkBox_radiance_state(true);
        else
            hpplredit->set_checkBox_radiance_state(false);

        if(hpplredit->part_radTable_id >= 0 && hpplredit->part_radTable_id <=24){
            hpplredit->ui->listWidget_radiance->setCurrentRow(hpplredit->part_radTable_id);
            hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
        }else{
            hpplredit->ui->listWidget_radiance->setCurrentRow(0);
            hpplredit->ui->label_radiance_2->setText(hpplredit->ui->listWidget_radiance->currentItem()->text());
        }

        if(HP_ReflectTemp == 0)
        {
            hpplredit->ui->hs_reflect->close();
        }
        hpplredit->show();
        break;
        default:
            break;
        }
}

void Hp_Display::hs_distance_value_changed(double value)
{
    switch(nowselect.c)
    {
    case DS_POINT:
        tmp_point_para.p_distance100 = value*100;
        break;
    case DS_LINE:
        tmp_line_para.l_distance100 = value*100;
        break;
    case DS_RECT:
        tmp_rect_para.rect_distance100 = value*100;
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_distance100 = value*100;
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_distance100 = value*100;
        break;
    default:
        break;
    }
}

void Hp_Display::slot_global_distance_value_changed(int value)
{
    g_distance100 = value;
}

void Hp_Display::hs_radiance_value_changed(int value)
{
    switch(nowselect.c)
    {
    case DS_POINT:
        tmp_point_para.p_radiance100 = value;
        break;
    case DS_LINE:
        tmp_line_para.l_radiance100 = value;
        break;
    case DS_RECT:
        tmp_rect_para.r_radiance100 = value;
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_radiance100 = value;
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_radiance100 = value;
        break;
    default:
        break;
    }
    getMaxRect();
}

void Hp_Display::slot_part_radTable_change( int id, int value)
{
    switch(nowselect.c)
    {
    case DS_POINT:
        tmp_point_para.p_radTable_id = id;
        tmp_point_para.p_radTable_value100 = value;
        break;
    case DS_LINE:
        tmp_line_para.l_radTable_id = id;
        tmp_line_para.l_radTable_value100 = value;
        break;
    case DS_RECT:
        tmp_rect_para.r_radTable_id = id;
        tmp_rect_para.r_radTable_value100 = value;
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_radTable_id = id;
        tmp_circle_para.c_radTable_value100 = value;
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_radTable_id = id;
        tmp_polygon_para.p_radTable_value100 = value;
        break;
    default:
        break;
    }
}

void Hp_Display::slot_part_radTable_mode(int mode)
{
    switch(nowselect.c)
    {
    case DS_POINT:
        tmp_point_para.p_radTable_switch = mode;
        break;
    case DS_LINE:
        tmp_line_para.l_radTable_switch =mode;
        break;
    case DS_RECT:
        tmp_rect_para.r_radTable_switch = mode;
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_radTable_switch = mode;
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_radTable_switch = mode;
        break;
    default:
        break;
    }
}

void Hp_Display::slot_global_radiance_value_changed(int value)
{
    g_radiance100 = value;
}

void Hp_Display::slot_global_radTable_value_changed( int id, int value)
{
    g_radTable_id = id;
    g_radTable_value100 = value;
}

void Hp_Display::slot_global_radTable_mode_changed(int mode)
{
    g_radTable_switch = mode;
}

void Hp_Display::hs_reflect_value_changed(double value)
{
    HpTempUnitConvert htuc;

    switch(nowselect.c)
    {
    case DS_LINE:
        tmp_line_para.l_ReflectTemp100 = htuc.getCTempValue(tempunit,value*100);
        break;
    case DS_RECT:
        tmp_rect_para.rect_ReflectTemp100 = htuc.getCTempValue(tempunit,value*100);
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_ReflectTemp100 = htuc.getCTempValue(tempunit,value*100);
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_ReflectTemp100 = htuc.getCTempValue(tempunit,value*100);
        break;
    default:
        break;
    }
}

void Hp_Display::slot_global_reflect_value_changed(int value)
{
//    qDebug("display:g_ReflectTemp100 = %d",value);
    g_ReflectTemp100 = value;
}

void Hp_Display::cb_temptype_current_index_channed(int value)
{
    switch(nowselect.c)
    {
    case DS_LINE:
        tmp_line_para.l_temptype = value;
        break;
    case DS_RECT:
        tmp_rect_para.temptype = value;
        break;
    case DS_CIRCLE:
        tmp_circle_para.c_temptype = value;
        break;
    case DS_POLYGON:
        tmp_polygon_para.p_temptype = value;
        break;
    default:
        break;
    }

    if(value == 3)
    {
        switch(nowselect.c)
        {
        case DS_POINT:
                tmp_point_para.refer_flag = 0;
            break;
        case DS_LINE:
                tmp_line_para.refer_flag = 0;//
            break;
        case DS_RECT:
                tmp_rect_para.refer_flag = 0;
            break;
        case DS_CIRCLE:
                tmp_circle_para.refer_flag = 0;
            break;
        default:
            break;
        }


    }

}

void Hp_Display::cb_refer_clicked(bool checked)
{

    switch(nowselect.c)
    {
    case DS_POINT:
        if(checked)
            tmp_point_para.refer_flag = 1;
        else
            tmp_point_para.refer_flag = 0;
        break;
    case DS_LINE:
        if(checked)
            tmp_line_para.refer_flag = 1;//
        else
            tmp_line_para.refer_flag = 0;//
        break;
    case DS_RECT:
        if(checked)
            tmp_rect_para.refer_flag = 1;
        else
            tmp_rect_para.refer_flag = 0;
        break;
    case DS_CIRCLE:
        if(checked)
            tmp_circle_para.refer_flag = 1;
        else
            tmp_circle_para.refer_flag = 0;
        break;
    case DS_POLYGON:
        if(checked)
            tmp_polygon_para.refer_flag = 1;
        else
            tmp_polygon_para.refer_flag = 0;
        break;
    default:
        break;
    }

    qDebug()<<"cb_refer_clicked "<<checked;
}

void Hp_Display::pb_cancle_clicked()
{
    if(hpplredit->listwidget_type != 0)
    {
        hpplredit->listwidget_type_manage();
        hpplredit->listwidget_type = 0;
    }
    hpplredit->close();
}

void Hp_Display::pb_finish_clicked()                //不知道需不需要修改
{
    int i;
    switch(nowselect.c)
    {
    case DS_POINT:
        ComPointPara tmp_point ;
        tmp_point = hp_point_list.at(nowselect.s);
        if(tmp_point_para.refer_flag == tmp_point.refer_flag
                && tmp_point_para.p_distance100 == tmp_point.p_distance100
                && tmp_point_para.p_radiance100 == tmp_point.p_radiance100
                &&tmp_point_para.p_radTable_switch == tmp_point.p_radTable_switch
                && tmp_point_para.p_radTable_id == tmp_point.p_radTable_id
                && tmp_point_para.p_radTable_value100 == tmp_point.p_radTable_value100
                )
            break;

        if(tmp_point_para.refer_flag == 1)
        {
            clear_reference_set();
            signal_set_globle_ReferTemp(false);
        }

        hp_point_list.replace(nowselect.s,tmp_point_para);
        if(define_zoom)
        {
            if(HP_S350_or_S300)
            {
                tmp_point_para.p_xcoord = tmp_point_para.p_xcoord *100/167;
                tmp_point_para.p_ycoord = tmp_point_para.p_ycoord *100/167;
            }else{
                tmp_point_para.p_xcoord = tmp_point_para.p_xcoord *100/167;
                tmp_point_para.p_ycoord = tmp_point_para.p_ycoord *100/176;
            }

            signal_pc_measure_set_point_update(tmp_point_para);
        }else
        {
            signal_pc_measure_set_point_update(tmp_point_para);
        }

        break;

    case DS_LINE:
        ComLinePara tmp_line;
        tmp_line = hp_line_list.at(nowselect.s);
        if(tmp_line_para.refer_flag == tmp_line.refer_flag \
                && tmp_line_para.l_distance100 == tmp_line.l_distance100 \
                && tmp_line_para.l_radiance100 == tmp_line.l_radiance100 \
                && tmp_line_para.l_temptype == tmp_line.l_temptype \
                && tmp_line_para.l_ReflectTemp100 == tmp_line.l_ReflectTemp100
                &&tmp_line_para.l_radTable_switch == tmp_line.l_radTable_switch
                && tmp_line_para.l_radTable_id == tmp_line.l_radTable_id
                && tmp_line_para.l_radTable_value100 == tmp_line.l_radTable_value100
                )
            break;

        if(tmp_line_para.refer_flag == 1)//
        {
            clear_reference_set();
            signal_set_globle_ReferTemp(false);
        }

        hp_line_list.replace(nowselect.s,tmp_line_para);

        if(define_zoom)
        {
            if(HP_S350_or_S300)
            {
                tmp_line_para.l_x1coord = tmp_line_para.l_x1coord*100/167;
                tmp_line_para.l_xcoord = tmp_line_para.l_xcoord*100/167;
                tmp_line_para.l_y1coord = tmp_line_para.l_y1coord *100/167;
                tmp_line_para.l_ycoord = tmp_line_para.l_ycoord*100/167;
            }else{
                tmp_line_para.l_x1coord = tmp_line_para.l_x1coord*100/167;
                tmp_line_para.l_xcoord = tmp_line_para.l_xcoord*100/167;
                tmp_line_para.l_y1coord = tmp_line_para.l_y1coord *100/176;
                tmp_line_para.l_ycoord = tmp_line_para.l_ycoord*100/176;
            }


               signal_pc_measure_set_line_update(tmp_line_para);
        }else
        {
               signal_pc_measure_set_line_update(tmp_line_para);
        }
        break;
    case DS_RECT:
        ComRectPara tmp_rect;
        tmp_rect = hp_rect_list.at(nowselect.s);
        if(hpplredit->ui->cb_rectTemp->isChecked())
        {
            double rectTempIns = hpplredit->ui->hs_rectTemp->value();
            int nowSelectId = tmp_rect.rect_id;
            m_selectIdRectIdMap[nowselect.s] = nowSelectId;
            m_selectInsValueMap[nowSelectId] = rectTempIns;
            if(!timerGetRectTemp->isActive())
                timerGetRectTemp->start(3000);
        }
        else
        {
            int nowSelectId = tmp_rect.rect_id;
            signal_show_insulation_warning(false, m_selectIdRectIdMap[nowSelectId], 900, 0);
            m_selectIdRectIdMap.remove(nowSelectId);
            m_selectInsValueMap.remove(nowSelectId);
            if(m_selectInsValueMap.isEmpty())
                timerGetRectTemp->stop();
        }
        if(tmp_rect_para.refer_flag == tmp_rect.refer_flag
                && tmp_rect_para.rect_distance100 == tmp_rect.rect_distance100
                &&tmp_rect_para.r_radiance100 == tmp_rect.r_radiance100
                &&tmp_rect_para.temptype == tmp_rect.temptype
                &&tmp_rect_para.rect_ReflectTemp100 == tmp_rect.rect_ReflectTemp100
                &&tmp_rect_para.r_radTable_switch == tmp_rect.r_radTable_switch
                && tmp_rect_para.r_radTable_id == tmp_rect.r_radTable_id
                && tmp_rect_para.r_radTable_value100 == tmp_rect.r_radTable_value100
                )
            break;

        if(tmp_rect_para.refer_flag == 1)
        {
            clear_reference_set();
            signal_set_globle_ReferTemp(false);
        }

        hp_rect_list.replace(nowselect.s,tmp_rect_para);
        if(define_zoom)
        {
            if(HP_S350_or_S300)
            {
                tmp_rect_para.origin_xcoord = tmp_rect_para.origin_xcoord*100/167;
                tmp_rect_para.origin_ycoord = tmp_rect_para.origin_ycoord*100/167;
                tmp_rect_para.rect_wide = tmp_rect_para.rect_wide*100/167;
                tmp_rect_para.rect_high =  tmp_rect_para.rect_high*100/167;
            }else{
                tmp_rect_para.origin_xcoord = tmp_rect_para.origin_xcoord*100/167;
                tmp_rect_para.origin_ycoord = tmp_rect_para.origin_ycoord*100/176;
                tmp_rect_para.rect_wide = tmp_rect_para.rect_wide*100/167;
                tmp_rect_para.rect_high =  tmp_rect_para.rect_high*100/176;
            }

             signal_pc_measure_set_rect_update(tmp_rect_para);
        }else
        {
            if(define_640_512)
            {
                tmp_rect_para.origin_xcoord = tmp_rect_para.origin_xcoord;
                tmp_rect_para.origin_ycoord = tmp_rect_para.origin_ycoord*1.07;
                tmp_rect_para.rect_wide = tmp_rect_para.rect_wide;
                tmp_rect_para.rect_high =  tmp_rect_para.rect_high*1.07;
            }
             signal_pc_measure_set_rect_update(tmp_rect_para);
        }
        getMaxRect();
        break;
    case DS_CIRCLE:
        ComCirclePara tmp_circle;
        tmp_circle = hp_circle_list.at(nowselect.s);
        if(tmp_circle_para.refer_flag == tmp_circle.refer_flag
                && tmp_circle_para.c_distance100 == tmp_circle.c_distance100
                &&tmp_circle_para.c_radiance100 == tmp_circle.c_radiance100
                &&tmp_circle_para.c_temptype == tmp_circle.c_temptype
                &&tmp_circle_para.c_ReflectTemp100 == tmp_circle.c_ReflectTemp100
                &&tmp_circle_para.c_radTable_switch == tmp_circle.c_radTable_switch
                && tmp_circle_para.c_radTable_id == tmp_circle.c_radTable_id
                && tmp_circle_para.c_radTable_value100 == tmp_circle.c_radTable_value100
                )
            break;

        if(tmp_circle_para.refer_flag == 1)
        {
            clear_reference_set();
            signal_set_globle_ReferTemp(false);
        }

        hp_circle_list.replace(nowselect.s,tmp_circle_para);
        if(define_zoom)
        {
            if(HP_S350_or_S300)
            {
                tmp_circle_para.center_xcoord = tmp_circle_para.center_xcoord*100/167;
                tmp_circle_para.center_ycoord = tmp_circle_para.center_ycoord*100/167;
                tmp_circle_para.radius = tmp_circle_para.radius*100/167;
            }else{
                tmp_circle_para.center_xcoord = tmp_circle_para.center_xcoord*100/167;
                tmp_circle_para.center_ycoord = tmp_circle_para.center_ycoord*100/176;
                tmp_circle_para.radius = tmp_circle_para.radius*100/167;
            }
        }
        signal_pc_measure_set_circle_update(tmp_circle_para);
        break;
    case DS_POLYGON:
        ComPolygonPara tmp_polygon;
        tmp_polygon = hp_polygon_list.at(nowselect.s);
        if(tmp_polygon_para.refer_flag == tmp_polygon.refer_flag
                && tmp_polygon_para.p_distance100 == tmp_polygon.p_distance100
                &&tmp_polygon_para.p_radiance100 == tmp_polygon.p_radiance100
                &&tmp_polygon_para.p_temptype == tmp_polygon.p_temptype
                &&tmp_polygon_para.p_ReflectTemp100 == tmp_polygon.p_ReflectTemp100
                &&tmp_polygon_para.p_radTable_switch == tmp_polygon.p_radTable_switch
                && tmp_polygon_para.p_radTable_id == tmp_polygon.p_radTable_id
                && tmp_polygon_para.p_radTable_value100 == tmp_polygon.p_radTable_value100
                )
            break;

        if(tmp_polygon_para.refer_flag == 1)
        {
            clear_reference_set();
            signal_set_globle_ReferTemp(false);
        }

        hp_polygon_list.replace(nowselect.s, tmp_polygon_para);
        if( define_zoom )
        {
            for(int i = 0; i < tmp_polygon_para.nNode; i++)
            {
                tmp_polygon_para.nX[i] = tmp_polygon_para.nX[i] * 100/167;
                tmp_polygon_para.nY[i] = tmp_polygon_para.nY[i] * 100/167;
            }
        }
        qDebug() << "PC_MEASURE_SET_POLYGON_UPDATE" << __LINE__;
        qDebug() << "polygon.refer_flag" << tmp_polygon_para.refer_flag;
        signal_pc_measure_set_polygon_update(tmp_polygon_para);
        break;
    default:
        break;
    }
    if(hpplredit->listwidget_type != 0)
    {
        hpplredit->listwidget_type_manage();
        hpplredit->listwidget_type = 0;
    }
    hpplredit->close();
}

void Hp_Display::slot_set_part_ReferTemp(bool checked)
{
    if(checked ==false)
    {
        clear_reference_set();
    }
}

void Hp_Display::slot_hidemenu_gray(bool checked)
{
    gray_enable = checked;
//    if(gray_enable)
//    {
//        timer->start(3000);
//        gray_disp->show();
//    }
//    else
//    {
//        timer->stop();
//        gray_disp->close();
//    }
}

void Hp_Display::slot_timer()
{
    signal_pc_sys_get_standard();
}


void Hp_Display::slot_tempunit_changed(int unit)
{
    tempunit = unit;
}
//隐藏界面， 画框，点
void Hp_Display::slot_painter_rect(bool checked)
{
     hidemenu_rect = checked;
    if(true == checked)
    {
//画框的一些初始化
//        if( define_zoom )
//        {
//            if(HP_S350_or_S300)
//            {
//                rect.rect_x = 240*100/167;                                  //初始框的一些初始化
//                rect.rect_y =180*100/167;
//                rect.rect_widget= 160*100/167;
//                rect.rect_hight = 120*100/167;
//            }else{
//                rect.rect_x = 240*100/167;                                  //初始框的一些初始化
//                rect.rect_y =180*100/176;
//                rect.rect_widget= 160*100/167;
//                rect.rect_hight = 120*100/176;
//            }

//        }
//        else
//        {
            rect.rect_x = 240;                                  //初始框的一些初始化
            rect.rect_y =170;//原来是180
            rect.rect_widget= 160;
            rect.rect_hight = 120;
            if(define_640_512)
            {
                rect.rect_x = rect.rect_x + 3;                                  //初始框的一些初始化
                rect.rect_y = rect.rect_y * SCF_Y_CONMUL;
                rect.rect_widget= rect.rect_widget + 1;
                rect.rect_hight = rect.rect_hight * SCF_Y_CONMUL + 3;//后面的减法是用于减去偏差的，使矩形框吻合
            }
//        }

       if(this->width() == 384 && this->height() == 272)//S300特殊,开始就设置一下位置
       {
           rect.rect_x = 240 / 1.7 + 3;                                  //初始框的一些初始化
           rect.rect_y =170 / 1.7 + 2;//原来是180
           rect.rect_widget= 160 / 1.7 + 2;
           rect.rect_hight = 120 / 1.7 - 2;
       }

       decide_state.press_shape=false;
       decide_state.release_shape=false;
       decide_state.shape_was_pich=false;
       fu_zhu.begin_y = 0;
       fu_zhu.begin_y = 0;
       fu_zhu.nei_widget = 5;
       fu_zhu.wai_widget = 5;
       fu_zhu.zhong_widget = 10;            //没用到
       fu_zhu.change_style = 0;                 //框的移动类型

    }else{
//        hidemenu_rect = false;
    }
     update();    //更新画布
}

void Hp_Display::slot_painter_point(bool checked)
{
    hidemenu_point = checked;
     if(true == checked)
     {
//         if( define_zoom )
//         {
//             if(HP_S350_or_S300)
//             {
//                 point.point_x =320*100/167;
//                 point.point_y = 240*100/167;
//             }else
//             {
//                 point.point_x =320*100/167;
//                 point.point_y = 240*100/176;
//             }

//         }
//         else
//         {
             point.point_x =320;
             point.point_y = 230;//原来240
//         }
         point.point_widget = 13;       //像素点到左边的距离和右边的距离  实际宽度：13+1+13
         point.point_select = false;

         lable_sidian->setObjectName(QStringLiteral("lable_sidian"));
         lable_sidian->setGeometry(point.point_x-point.point_widget,  point.point_y-point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1 );
         lable_sidian->setStyleSheet(QLatin1String("backgrounf:transparent;\n""background-image: url(:/res/res/laser.png);"));
         lable_sidian->show();

     }else{
         lable_sidian->close();
     }
}
//框的坐标复制发送
void Hp_Display::rect_struct_copy( ){

    qDebug() << "rect.rect_y" << rect.rect_y << " rect.rect_hight" << rect.rect_hight;
    if(rect.rect_y + rect.rect_hight >= 480)
    {
        rect.rect_hight = 480 - rect.rect_y;
    }
    qDebug() << "rect.rect_y" << rect.rect_y << " rect.rect_hight" << rect.rect_hight;
    if(define_zoom)
    {
        if(HP_S350_or_S300)
        {
            com_rect_pixel.start_x = rect.rect_x*100/167;
            com_rect_pixel.start_y = rect.rect_y*100/167;
            com_rect_pixel.width = rect.rect_widget*100/167;
            com_rect_pixel.high = rect.rect_hight*100/167;
        }else{
            com_rect_pixel.start_x = rect.rect_x*100/167;
            com_rect_pixel.start_y = rect.rect_y*100/176;
            com_rect_pixel.width = rect.rect_widget*100/167;
            com_rect_pixel.high = rect.rect_hight*100/176;
        }
    }else
    {
        com_rect_pixel.start_x = rect.rect_x;
        com_rect_pixel.start_y = rect.rect_y;
        com_rect_pixel.width = rect.rect_widget;
        com_rect_pixel.high = rect.rect_hight;
        if(define_640_512)
        {
            com_rect_pixel.start_x = rect.rect_x - 1;
            com_rect_pixel.start_y = rect.rect_y * 1.07;
            com_rect_pixel.width = rect.rect_widget;
            com_rect_pixel.high = rect.rect_hight * 1.07;
        }
    }
    if(com_rect_pixel.start_y + com_rect_pixel.high >= bottom_edge)
    {
        com_rect_pixel.high = bottom_edge - com_rect_pixel.start_y;
    }
   signal_display_rect((unsigned char*)&com_rect_pixel, sizeof(ComRectBadPixel));
}

void Hp_Display::point_struct_copy( ){

    if(define_zoom)
    {
        if(HP_S350_or_S300)
        {
            com_point_pixel.xcoord = point.point_x*100/167;
            com_point_pixel.ycoord = point.point_y*100/167;
        }else{
            com_point_pixel.xcoord = point.point_x*100/167;
            com_point_pixel.ycoord = point.point_y*100/176;
        }

    }else
    {
        com_point_pixel.xcoord = point.point_x;
        com_point_pixel.ycoord = point.point_y;
    }
    signal_display_point( (unsigned char *)&com_point_pixel,sizeof(ComPointBadPixel));
}
//快捷键移动框;
void Hp_Display::slot_del_badpixel_rect(int direction ){

    //首先判断。是否使能 rect。如果没使能，结束
    if( false == hidemenu_rect){
        return;
    }
    //1234.上下左右
    switch(direction){
     case 1:
        {
            if((rect.rect_y -1) >= 0)             //保证上移不出边界
            {
                rect.rect_x = rect.rect_x;
                rect.rect_y = rect.rect_y - 1;
                rect_struct_copy();
                update();
            }
        }
        break;
    case 2:
        {
            if((rect.rect_y +rect.rect_hight+ 1) <=bottom_edge)         //保证下移不出边界
            {
                rect.rect_x = rect.rect_x;
                rect.rect_y = rect.rect_y + 1;
                rect_struct_copy();
                update();
            }
        }
        break;
    case 3:
    {
            if((rect.rect_x  -1) >=0 )           //保证左移不出边界
            {
                rect.rect_x = rect.rect_x - 1;
                rect.rect_y = rect.rect_y;
                rect_struct_copy();
                update();
            }
    }
        break;
    case 4:
    {
            if((rect.rect_x +rect.rect_widget+1) <=640)        //保证有移不出边界
            {
                rect.rect_x = rect.rect_x + 1;
                rect.rect_y = rect.rect_y;
                rect_struct_copy();
                update();
            }
    }
        break;
    default:
        break;
    }

}
//快捷键移动 点
void Hp_Display::slot_del_badpixel_point(int direction ){

    //首先判断。是否使能 rect。如果没使能，结束
    if( false == hidemenu_point){
        return;
    }
  switch(direction){
   case 1:
        {
            if((point.point_y - 1) >=0)                     //保证上移不出边界
            {
                point.point_x = point.point_x;
                point.point_y = point.point_y -1;
                lable_sidian->setGeometry(point.point_x-point.point_widget,  point.point_y-point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1 );
                point_struct_copy();
            }
        }
      break;
  case 2:
      {
            if((point.point_y + 1) <= bottom_edge)                     //保证下移不出边界
            {
                point.point_x = point.point_x;
                point.point_y = point.point_y + 1;
                lable_sidian->setGeometry(point.point_x-point.point_widget,  point.point_y-point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1 );
                point_struct_copy();
            }
      }
      break;
  case 3:
      {
            if((point.point_x -1) >=  0)
            {
                point.point_x = point.point_x - 1;
                point.point_y = point.point_y;
                lable_sidian->setGeometry(point.point_x-point.point_widget,  point.point_y-point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1 );
                point_struct_copy();
            }
      }
      break;
  case 4:
      {
            if((point.point_x +1) <=  640)
            {
                point.point_x = point.point_x + 1;
                point.point_y = point.point_y;
                lable_sidian->setGeometry(point.point_x-point.point_widget,  point.point_y-point.point_widget, 2*point.point_widget+1, 2*point.point_widget+1 );
                point_struct_copy();
            }
      }
       break;
  default:
      break;
  }
}
//点到直线的距离
int Hp_Display::point_line_distance(int a1, int b1, int a2, int b2, int x, int y)
{
    int fenmu,fenzi,distance;
    //点到直线距离的平方
    if(a1 ==a2)
    {
        distance = (x-a1)*(x-a1);
    }else if(b1==b2)
    {
        distance = (y-b1)*(y-b1);
    }else
    {
        fenmu = qAbs(((b2-b1)*x +(a1-a2)*y +(a2*b1-a1*b2)));        //分母
        fenzi = (b2-b1)*(b2-b1) +(a1-a2)*(a1-a2);                               //分子的平方
        distance = fenmu*fenmu/fenzi;
    }
    return distance;
}

void Hp_Display::setInsulation(bool isInsulation)
{
    m_isInsulation = isInsulation;
    if(!isInsulation)
    {
        hpplredit->ui->listWidget_temptype->setItemHidden(hpplredit->ui->listWidget_temptype->item(4), true);

        hpplredit->ui->listWidget_temptype->setGeometry(133,254,385,140);
    }

}

void Hp_Display::slot_timer_get_rect_index()
{
    if(m_selectInsValueMap.isEmpty())
        return;
    for(int i = 0; i < hp_rect_list.count(); i++)
    {
        signal_pc_measure_get_rect(i);
    }
}

void Hp_Display::slot_sent_press_pos_to_display(QMouseEvent *event)
{
    mousePressEvent(event);
}

void Hp_Display::slot_sent_release_pos_to_display(QMouseEvent *event)
{
    mouseReleaseEvent(event);
}

void Hp_Display::setDoubleClickFocusFlag(bool flag)
{
    m_doubleClickFocusFlag = flag;
}

void Hp_Display::sltDoubleClickFocus()
{
    if(m_doubleClickCounter >= 3 && !hir_analyse)
        signal_double_clicked_focus();
    m_doubleClickCounter = 0;
}

void Hp_Display::slot_set_preset_mode(int presetMode)
{
    if(1 == presetMode)
    {
        if( hp_point_list.count() < max_point_num )
        {
            ComPointPara ll_hp_point;

            ll_hp_point.p_xcoord = 200;    //点X坐标
            ll_hp_point.p_ycoord = 240;    //点Y坐标

            pointIndex = pointIndex + 1;
            ll_hp_point.point_id = pointIndex;   //测温编号

            ll_hp_point.refer_flag = 0;

            ll_hp_point.p_distance100 = g_distance100;
            ll_hp_point.p_radiance100 = g_radiance100;

            ll_hp_point.p_radTable_switch = g_radTable_switch;
            ll_hp_point.p_radTable_id = g_radTable_id;
            ll_hp_point.p_radTable_value100 = g_radTable_value100;
            hp_point_list.append(ll_hp_point);
            if(define_zoom)
            {
                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord * 100 / 167;
                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord * 100 / 167;
            }
            signal_pc_measure_set_point_add(ll_hp_point);
        }
    }
    if(2 == presetMode)
    {
        if( hp_point_list.count() < max_point_num )
        {
            ComPointPara ll_hp_point;
            ll_hp_point.p_xcoord = 150;    //点X坐标
            ll_hp_point.p_ycoord = 130;    //点Y坐标

            pointIndex = pointIndex + 1;
            ll_hp_point.point_id = pointIndex;   //测温编号

            ll_hp_point.refer_flag = 0;

            ll_hp_point.p_distance100 = g_distance100;
            ll_hp_point.p_radiance100 = g_radiance100;

            ll_hp_point.p_radTable_switch = g_radTable_switch;
            ll_hp_point.p_radTable_id = g_radTable_id;
            ll_hp_point.p_radTable_value100 = g_radTable_value100;
            hp_point_list.append(ll_hp_point);
            if(define_zoom)
            {
                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord * 100 / 167;
                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord * 100 / 167;
            }
            signal_pc_measure_set_point_add(ll_hp_point);
        }

        if( hp_point_list.count() < max_point_num )
        {
            ComPointPara ll_hp_point;

            ll_hp_point.p_xcoord = 490;    //点X坐标
            ll_hp_point.p_ycoord = 110;    //点Y坐标

            pointIndex = pointIndex + 1;
            ll_hp_point.point_id = pointIndex;   //测温编号

            ll_hp_point.refer_flag = 0;

            ll_hp_point.p_distance100 = g_distance100;
            ll_hp_point.p_radiance100 = g_radiance100;

            ll_hp_point.p_radTable_switch = g_radTable_switch;
            ll_hp_point.p_radTable_id = g_radTable_id;
            ll_hp_point.p_radTable_value100 = g_radTable_value100;
            hp_point_list.append(ll_hp_point);
            if(define_zoom)
            {
                ll_hp_point.p_xcoord = ll_hp_point.p_xcoord * 100 / 167;
                ll_hp_point.p_ycoord = ll_hp_point.p_ycoord * 100 / 167;
            }
            signal_pc_measure_set_point_add(ll_hp_point);
        }

        if( hp_rect_list.count() < max_rect_num )
        {
            ComRectPara l_hp_rect;
            l_hp_rect.origin_xcoord = 300;
            l_hp_rect.origin_ycoord = 200;
            l_hp_rect.rect_wide = 200;
            l_hp_rect.rect_high = 200;

            if( l_hp_rect.origin_xcoord >= 0 && l_hp_rect.origin_ycoord >= 0 )
            {
                if(l_hp_rect.rect_wide < MIN_RECT_WIDTH)
                    l_hp_rect.rect_wide = MIN_RECT_WIDTH;
                if(l_hp_rect.rect_high < MIN_RECT_HEIGHT)
                    l_hp_rect.rect_high = MIN_RECT_HEIGHT;

                rectIndex = rectIndex + 1;
                l_hp_rect.rect_id = rectIndex;

                l_hp_rect.refer_flag = 0;
                l_hp_rect.rect_distance100 = g_distance100;
                l_hp_rect.rect_ReflectTemp100 = g_ReflectTemp100;
                l_hp_rect.r_radiance100 = g_radiance100;
                l_hp_rect.temptype = 0;

                l_hp_rect.remapping_color_id = m_currSebiao;
                l_hp_rect.remapping_switch = 0;
                l_hp_rect.r_radTable_switch = g_radTable_switch;
                l_hp_rect.r_radTable_id = g_radTable_id;
                l_hp_rect.r_radTable_value100 = g_radTable_value100;
                hp_rect_list.append(l_hp_rect);
                if(define_zoom)
                {
                    l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord * 100 / 167;
                    l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord * 100 / 167;
                    l_hp_rect.rect_wide = l_hp_rect.rect_wide * 100 / 167;
                    l_hp_rect.rect_high = l_hp_rect.rect_high * 100 / 167;
                }
                signal_pc_measure_set_rect_add(l_hp_rect);
                getMaxRect();
            }
        }
    }
}

void Hp_Display::SlotRefreshDisplayMaxRect()
{
    getMaxRect();
}

void Hp_Display::getMaxRect()
{
    QElapsedTimer timer;
    timer.start();
    ComRectPara maxRect ;
    memset(&maxRect,0,sizeof(ComRectPara));
    if(hp_rect_list.isEmpty())//开机不添加框
    {
        maxRect.origin_xcoord = -1;//若读取的x值小于0，则不画框
    }
    else
    {
        maxRect = hp_rect_list.at(0);
        int maxArea = maxRect.rect_wide * maxRect.rect_high;

        QListIterator<ComRectPara> i_rect(hp_rect_list);
        ComRectPara l_hp_rect;

        while(i_rect.hasNext())
        {
            l_hp_rect = i_rect.next();
            int area = l_hp_rect.rect_wide * l_hp_rect.rect_high;
            if(area > maxArea)
            {
                maxArea = area;
                maxRect = l_hp_rect;
            }
        }
    }
    //若数组变化则重新写入
    if(!compareComRectPara(maxRect,m_maxRect))
    {
        //若文件没问题则备份
        if(!hpxmlreader.CheckFileNormal("qtconfig.xml","MAX_RECT_PARA","origin_xcoord")){
            MYLOG;
            hpxmlreader.restoreFromBackup("qtconfig.xml");
            qDebug() << "[getMaxRect] CheckFileNormal FAIL";
        }
        else{
            MYLOG;
        }
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","temptype",QString::number(maxRect.temptype));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","origin_xcoord",QString::number(maxRect.origin_xcoord));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","origin_ycoord",QString::number(maxRect.origin_ycoord));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","rect_wide",QString::number(maxRect.rect_wide));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","rect_high",QString::number(maxRect.rect_high));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","r_radiance100",QString::number(maxRect.r_radiance100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","refer_flag",QString::number(maxRect.refer_flag));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","rect_distance100",QString::number(maxRect.rect_distance100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","rect_vaild",QString::number(maxRect.rect_vaild));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","rect_ReflectTemp100",QString::number(maxRect.rect_ReflectTemp100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_switch",QString::number(maxRect.r_radTable_switch));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","remapping_switch",QString::number(maxRect.remapping_switch));

        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_id",QString::number(maxRect.r_radTable_id));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_value100",QString::number(maxRect.r_radTable_value100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","remapping_color_id",QString::number(maxRect.remapping_color_id));

        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","mintemp100",QString::number(maxRect.mintemp100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","maxtemp100",QString::number(maxRect.maxtemp100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","avgtemp100",QString::number(maxRect.avgtemp100));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","MaxX",QString::number(maxRect.MaxX));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","MaxY",QString::number(maxRect.MaxY));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","MinX",QString::number(maxRect.MinX));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","MinY",QString::number(maxRect.MinY));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","deviceType",QString::fromUtf8(maxRect.deviceType));
        // hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","subStationType",QString::number(maxRect.subStationType));

        // 批量写入所有属性
        QMap<QString, QString> attrs;
        attrs["temptype"] = QString::number(maxRect.temptype);
        attrs["origin_xcoord"] = QString::number(maxRect.origin_xcoord);
        attrs["origin_ycoord"] = QString::number(maxRect.origin_ycoord);
        attrs["rect_wide"] = QString::number(maxRect.rect_wide);
        attrs["rect_high"] = QString::number(maxRect.rect_high);
        attrs["r_radiance100"] = QString::number(maxRect.r_radiance100);
        attrs["refer_flag"] = QString::number(maxRect.refer_flag);
        attrs["rect_distance100"] = QString::number(maxRect.rect_distance100);
        attrs["rect_vaild"] = QString::number(maxRect.rect_vaild);
        attrs["rect_ReflectTemp100"] = QString::number(maxRect.rect_ReflectTemp100);
        attrs["r_radTable_switch"] = QString::number(maxRect.r_radTable_switch);
        attrs["remapping_switch"] = QString::number(maxRect.remapping_switch);
        attrs["r_radTable_id"] = QString::number(maxRect.r_radTable_id);
        attrs["r_radTable_value100"] = QString::number(maxRect.r_radTable_value100);
        attrs["remapping_color_id"] = QString::number(maxRect.remapping_color_id);
        attrs["mintemp100"] = QString::number(maxRect.mintemp100);
        attrs["maxtemp100"] = QString::number(maxRect.maxtemp100);
        attrs["avgtemp100"] = QString::number(maxRect.avgtemp100);
        attrs["MaxX"] = QString::number(maxRect.MaxX);
        attrs["MaxY"] = QString::number(maxRect.MaxY);
        attrs["MinX"] = QString::number(maxRect.MinX);
        attrs["MinY"] = QString::number(maxRect.MinY);
        attrs["deviceType"] = QString::fromLocal8Bit(maxRect.deviceType, 2);
        attrs["subStationType"] = QString::number(maxRect.subStationType);

        hpxmlreader.writeXml_more("qtconfig.xml", "MAX_RECT_PARA", attrs);

        //写入完毕后检查文件读取是否正常
        if(!hpxmlreader.CheckFileNormal("qtconfig.xml","MAX_RECT_PARA","origin_xcoord")){
            MYLOG;
            hpxmlreader.restoreFromBackup("qtconfig.xml");
            qDebug() << "[getMaxRect] AFTER write - CheckFileNormal FAIL, restore from backup";
        }
        else{
            MYLOG;
            hpxmlreader.backupFile("qtconfig.xml");
            m_maxRect = maxRect;
        }
    }
    qDebug() << "[ZJJ]getMaxRect time:" << timer.elapsed() << "ms";

}

//框结构体是否一致
bool Hp_Display::compareComRectPara(const ComRectPara& a, const ComRectPara& b) {
    // 先比较位置和大小
    if (a.origin_xcoord != b.origin_xcoord ||
        a.origin_ycoord != b.origin_ycoord ||
        a.rect_wide != b.rect_wide ||
        a.rect_high != b.rect_high) {
        return false;
    }

    // 再比较ID和类型
    if (a.rect_id != b.rect_id ||
        a.temptype != b.temptype ||
        strncmp(a.deviceType, b.deviceType, 2) != 0) {
        return false;
    }

    // 最后比较其他参数
    return a.r_radiance100 == b.r_radiance100 &&
           a.rect_distance100 == b.rect_distance100 &&
           a.rect_ReflectTemp100 == b.rect_ReflectTemp100 &&
           a.r_radTable_id == b.r_radTable_id &&
           a.r_radTable_switch == b.r_radTable_switch &&
           a.r_radTable_value100 == b.r_radTable_value100 &&
           a.refer_flag == b.refer_flag &&
           a.remapping_color_id == b.remapping_color_id &&
           a.remapping_switch == b.remapping_switch;
}
//清空最大框，当x为负数时不加最大框，约等于清空
void Hp_Display::SlotClearMaxRectPara()
{
    qDebug()<<"!!!!!!!!!!!!!!___________SlotClearMaxRectPara";
    m_maxRect.origin_xcoord = -1;
     hpxmlreader.writeXml("qtconfig.xml","MAX_RECT_PARA","origin_xcoord",QString::number(-1));//参数重置了所以清空
     //若文件没问题则备份
     if(!hpxmlreader.CheckFileNormal("qtconfig.xml","MAX_RECT_PARA","origin_xcoord")){
         MYLOG;
         hpxmlreader.restoreFromBackup("qtconfig.xml");
         qDebug() << "[SlotClearMaxRectPara] CheckFileNormal FAIL, restore from backup";
     }
     else{
         MYLOG;
         hpxmlreader.backupFile("qtconfig.xml");
     }

}

void Hp_Display::initMaxRectPara()
{
    QString para;
    ComRectPara l_hp_rect;
    if(!hpxmlreader.CheckFileNormal("qtconfig.xml","MAX_RECT_PARA","origin_xcoord")){
        hpxmlreader.restoreFromBackup("qtconfig.xml");
        qDebug() << "[initMaxRectPara] CheckFileNormal FAIL, restore from backup";
    }
    else{
        hpxmlreader.backupFile("qtconfig.xml");
    }

    bool isNormal = true;//若位置大小参数不正常则为false
    //区域测温类型[0,2]:其中0=最高温，1=最低温，2=平均温;
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","temptype");
    if(!para.isNull()){
        if(para.toInt()>=0 &&para.toInt()<= 4){
            l_hp_rect.temptype = para.toInt();
        }
        else{
            l_hp_rect.temptype = 0;
        }
    }
    else{
        l_hp_rect.temptype = 0;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","origin_xcoord");
    if(!para.isNull()){
        if(para.toInt()>=0 ){
            l_hp_rect.origin_xcoord = para.toInt();
        }
        else{
            qDebug()<<"!______________!"<<__LINE__;
            isNormal = false;
        }
    }
    else{
        qDebug()<<"!______________!"<<__LINE__;
       isNormal = false;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","origin_ycoord");
    if(!para.isNull()){
        if(para.toInt()>=0){
            l_hp_rect.origin_ycoord = para.toInt();
        }
        else{
            qDebug()<<"!______________!"<<__LINE__;
            isNormal = false;
        }
    }
    else{
        qDebug()<<"!______________!"<<__LINE__;
       isNormal = false;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","rect_wide");
    if(!para.isNull()){
        if(para.toInt()>=MIN_RECT_WIDTH && para.toInt()<=640){
            l_hp_rect.rect_wide = para.toInt();
        }
        else{
            l_hp_rect.rect_wide = 200;
        }
    }
    else{
        qDebug()<<"!______________!"<<__LINE__;
       isNormal = false;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","rect_high");
    if(!para.isNull()){
        if(para.toInt()>=MIN_RECT_WIDTH && para.toInt()<=480){
            l_hp_rect.rect_high = para.toInt();
        }
        else{
             l_hp_rect.rect_high = 100;
        }
    }
    else{
        qDebug()<<"!______________!"<<__LINE__;
       isNormal = false;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","r_radiance100");
    if(para != NULL)
        l_hp_rect.r_radiance100 = para.toInt();
    else
        l_hp_rect.r_radiance100 = 96;
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","refer_flag");
    if(!para.isNull()){
        if(para.toInt()==0 || para.toInt()== 1 ){
            l_hp_rect.refer_flag = para.toInt();
        }
        else{
            l_hp_rect.refer_flag = 0;
        }
    }
    else{
       l_hp_rect.refer_flag = 0;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","rect_distance100");
    if(!para.isNull()){
            l_hp_rect.rect_distance100 = para.toInt();
    }
    else{
        l_hp_rect.rect_distance100 = 150;
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","rect_vaild");
    if(!para.isNull()){
            l_hp_rect.rect_vaild = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","rect_ReflectTemp100");
    if(!para.isNull()){
            l_hp_rect.rect_ReflectTemp100 = para.toInt();
    }
    else{
        l_hp_rect.rect_ReflectTemp100 = 3000;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_switch");
    if(!para.isNull()){
            l_hp_rect.r_radTable_switch = para.toInt();
    }
    else{
        l_hp_rect.r_radTable_switch = 0;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","remapping_color_id");
    if(!para.isNull()){
            l_hp_rect.remapping_color_id = para.toInt();
    }
    else{
        l_hp_rect.remapping_color_id = m_currSebiao;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","mintemp100");
    if(!para.isNull()){
            l_hp_rect.mintemp100 = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","maxtemp100");
    if(!para.isNull()){
            l_hp_rect.maxtemp100 = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","avgtemp100");
    if(!para.isNull()){
            l_hp_rect.avgtemp100 = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","MaxX");
    if(!para.isNull()){
            l_hp_rect.MaxX = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","MaxY");
    if(!para.isNull()){
            l_hp_rect.MaxY = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","MinX");
    if(!para.isNull()){
            l_hp_rect.MinX = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","MinY");
    if(!para.isNull()){
            l_hp_rect.MinY = para.toInt();
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","remapping_switch");
    if(!para.isNull()){
            l_hp_rect.remapping_switch = para.toInt();
    }
    else{
        l_hp_rect.remapping_switch = 0;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_id");
    if(!para.isNull()){
            l_hp_rect.r_radTable_id = para.toInt();
    }
    else{
        l_hp_rect.r_radTable_id = 0;
    }
    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","r_radTable_value100");
    if(!para.isNull()){
            l_hp_rect.r_radTable_value100 = para.toInt();
    }
    else{
            l_hp_rect.r_radTable_value100 = 96;
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","deviceType");
    if(!para.isNull()){
        strncpy(l_hp_rect.deviceType, para.toUtf8().data(), 2);
    }

    para = hpxmlreader.readXml("qtconfig.xml","MAX_RECT_PARA","subStationType");
    if(!para.isNull()){
            l_hp_rect.subStationType = para.toInt();
    }

    qDebug()<<"!______________!"<<__LINE__<<"isNormal: "<<isNormal;
    if(isNormal)
    {
        rectIndex++;
        l_hp_rect.rect_id = rectIndex;
        hp_rect_list.append(l_hp_rect);
        if(define_zoom)
        {
            if(HP_S350_or_S300)
            {
                l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/167;
                l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                l_hp_rect.rect_high =  l_hp_rect.rect_high*100/167;
            }else{
                l_hp_rect.origin_xcoord = l_hp_rect.origin_xcoord*100/167;
                l_hp_rect.origin_ycoord = l_hp_rect.origin_ycoord*100/176;
                l_hp_rect.rect_wide = l_hp_rect.rect_wide*100/167;
                l_hp_rect.rect_high =  l_hp_rect.rect_high*100/176;
            }
        }//S300部分是正确的
        qDebug()<<"!______________!draw"<<__LINE__<<"origin_xcoord: "<<l_hp_rect.origin_xcoord;
        qDebug()<<"!______________!draw"<<__LINE__<<"origin_xcoord: "<<l_hp_rect.origin_ycoord;
        qDebug()<<"!______________!draw"<<__LINE__<<"rect_high: "<<l_hp_rect.rect_high;
        qDebug()<<"!______________!draw"<<__LINE__<<"rect_wide: "<<l_hp_rect.rect_wide;

        signal_pc_measure_set_rect_add(l_hp_rect);
    }
}
