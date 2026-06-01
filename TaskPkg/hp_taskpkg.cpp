#include "hp_taskpkg.h"

Hp_TaskPkg *Hp_TaskPkg::m_instance = nullptr;
QMutex Hp_TaskPkg::m_mutex;

/******************************************************************************************************
 * @ description : 构造函数
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
Hp_TaskPkg::Hp_TaskPkg(QObject *parent) : QObject(parent)
{
    MYLOG << " RUNNING . . . ";
    tree_start_status = false;
    m_b_jumpFlag = false;
    tree_index = 0;
    m_hasInit = 0;
    m_strSDPath = QString("/run/media/mmcblk2p1");

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    m_sem_taskTree = new QSemaphore(1);
}


/******************************************************************************************************
 * @ description : 析构函数
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
Hp_TaskPkg::~Hp_TaskPkg()
{
    if(m_p_qmlPort != nullptr) {
        delete m_p_qmlPort;
        m_p_qmlPort = nullptr;
    }
    if(m_p_TaskSelectQWidget != nullptr) {
        delete m_p_TaskSelectQWidget;
        m_p_TaskSelectQWidget = nullptr;
    }
    if(m_p_MessageBoxQWidget != nullptr) {
        delete m_p_MessageBoxQWidget;
        m_p_MessageBoxQWidget = nullptr;
    }
    if(m_p_MessageDialogQWidget != nullptr) {
        delete m_p_MessageDialogQWidget;
        m_p_MessageDialogQWidget = nullptr;
    }
    if(m_p_TreeViewQWidget != nullptr) {
        delete m_p_TreeViewQWidget;
        m_p_TreeViewQWidget = nullptr;
    }
    if(m_p_formula != nullptr) {
        delete m_p_formula;
        m_p_formula = nullptr;
    }

    mp_analyOP->Close_analysis_db();
}

int Hp_TaskPkg::taskPkg_init(SCREEN_SIZE id)
{
    MYLOG << " RUNNING . . . ";

    m_screen_id = id;
    m_p_qmlPort = new QmlPort;
    m_p_qmlPort->set_screenSize(m_screen_id);

    m_p_formula = new hp_task_formula();

    mp_analyOP = new createThread();
    mp_analyOP->Open_analysis_db();
    mp_analyOP->create_analysis_db();

    m_p_TaskSelectQWidget = new QQuickWidget();
    m_p_TaskSelectQWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_p_TaskSelectQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_p_TaskSelectQWidget->setClearColor(QColor(Qt::transparent));
    m_p_TaskSelectQWidget->hide();

    m_p_MessageBoxQWidget = new QQuickWidget();
    m_p_MessageBoxQWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_p_MessageBoxQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_p_MessageBoxQWidget->setClearColor( QColor(0, 8, 16) );
    m_p_MessageBoxQWidget->hide();

    m_p_TreeViewQWidget = new QQuickWidget();
    m_p_TreeViewQWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_p_TreeViewQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_p_TreeViewQWidget->setClearColor(QColor(Qt::transparent));
    m_p_TreeViewQWidget->hide();

    m_p_MessageDialogQWidget = new QQuickWidget();
    m_p_MessageDialogQWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_p_MessageDialogQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_p_MessageDialogQWidget->setClearColor(QColor(Qt::transparent));
    m_p_MessageDialogQWidget->hide();

    AnalysisChartQWidget = new QQuickWidget();
    AnalysisChartQWidget->setWindowFlags(Qt::FramelessWindowHint);
    AnalysisChartQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    AnalysisChartQWidget->setClearColor(QColor(Qt::transparent));
    AnalysisChartQWidget->hide();

    m_p_InteractionQWidget = new QQuickWidget();
    m_p_InteractionQWidget->setWindowFlags(Qt::FramelessWindowHint);
    m_p_InteractionQWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_p_InteractionQWidget->setClearColor(QColor(Qt::transparent));
    m_p_InteractionQWidget->hide();

    //m_p_MessageBoxQWidget->setGeometry(220, 140, 480/2, 272/2);
    //m_p_MessageDialogQWidget->setGeometry(250, 175, 300, 100);
    if (m_screen_id == SCREEN_480_272) {
        m_p_MessageBoxQWidget->move(135, 76);
        m_p_MessageDialogQWidget->move(135, 101);
        m_p_InteractionQWidget->move(135, 76);
    } else if (m_screen_id == SCREEN_800_480) {
        m_p_MessageBoxQWidget->move(220, 140);
        m_p_MessageDialogQWidget->move(250, 175);
        m_p_InteractionQWidget->move(220, 140);
    } else if (m_screen_id == SCREEN_853_480) {
        m_p_MessageBoxQWidget->move(220, 140);
        m_p_MessageDialogQWidget->move(250, 175);
        m_p_InteractionQWidget->move(220, 140);
    } else if (m_screen_id == SCREEN_800_480_2) {
        m_p_MessageBoxQWidget->move(220, 140);
        m_p_MessageDialogQWidget->move(250, 175);
        m_p_InteractionQWidget->move(220, 140);
    } else if (m_screen_id == SCREEN_1920_1080) {
        m_p_MessageBoxQWidget->move(800, 300);
        m_p_MessageDialogQWidget->move(800, 300);
        m_p_InteractionQWidget->move(800, 300);
    }
    m_p_TaskSelectQWidget->move(0,0);
    m_p_TreeViewQWidget->move(0,0);
    AnalysisChartQWidget->move(0, 0);

    m_p_TaskSelectQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);
    m_p_TreeViewQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);
    m_p_MessageBoxQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);
    m_p_MessageDialogQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);
    AnalysisChartQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);
    m_p_InteractionQWidget->rootContext()->setContextProperty("qml_port", m_p_qmlPort);

    ChangeModel* change_model = new ChangeModel;
    m_p_TaskSelectQWidget->rootContext()->setContextProperty("change_model", change_model);
    m_p_TreeViewQWidget->rootContext()->setContextProperty("change_model", change_model);
    m_p_MessageBoxQWidget->rootContext()->setContextProperty("change_model", change_model);
    AnalysisChartQWidget->rootContext()->setContextProperty("change_model", change_model);
    m_p_InteractionQWidget->rootContext()->setContextProperty("change_model", change_model);

    file_list = new FileList;
    m_p_TaskSelectQWidget->rootContext()->setContextProperty( "file_list", file_list );
    m_p_TreeViewQWidget->rootContext()->setContextProperty( "file_list", file_list );
    m_p_MessageBoxQWidget->rootContext()->setContextProperty( "file_list", file_list );
    AnalysisChartQWidget->rootContext()->setContextProperty( "file_list", file_list );
    m_p_InteractionQWidget->rootContext()->setContextProperty( "file_list", file_list );

    xml_list = new XmlList;
    m_p_TaskSelectQWidget->rootContext()->setContextProperty( "xml_list", xml_list );
    m_p_TreeViewQWidget->rootContext()->setContextProperty( "xml_list", xml_list );
    m_p_MessageBoxQWidget->rootContext()->setContextProperty( "xml_list", xml_list );
    AnalysisChartQWidget->rootContext()->setContextProperty( "xml_list", xml_list );

    folder_list = new FolderList;
    m_p_TaskSelectQWidget->rootContext()->setContextProperty( "folder_list", folder_list );
    m_p_TreeViewQWidget->rootContext()->setContextProperty( "folder_list", folder_list );
    m_p_MessageBoxQWidget->rootContext()->setContextProperty( "folder_list", folder_list );
    AnalysisChartQWidget->rootContext()->setContextProperty( "folder_list", folder_list );
    m_p_InteractionQWidget->rootContext()->setContextProperty( "folder_list", folder_list );

    m_p_TaskSelectQWidget->rootContext()->setContextProperty( "analysis_op", mp_analyOP );
    m_p_TreeViewQWidget->rootContext()->setContextProperty( "analysis_op", mp_analyOP );
    m_p_MessageBoxQWidget->rootContext()->setContextProperty( "analysis_op", mp_analyOP );
    AnalysisChartQWidget->rootContext()->setContextProperty( "analysis_op", mp_analyOP );
    m_p_InteractionQWidget->rootContext()->setContextProperty( "analysis_op", mp_analyOP );

    m_p_MessageDialogQWidget->setSource(QUrl("qrc:///machine/MessageDialog.qml"));
    m_p_MessageBoxQWidget->setSource(QUrl("qrc:///machine/MessageTaskBase.qml"));

    m_p_DialogObject = (QObject*) m_p_MessageDialogQWidget->rootObject();
    m_p_MessageBoxObject = (QObject*) m_p_MessageBoxQWidget->rootObject();

    m_p_MessageBoxObject->setProperty("show_list", true);

    connect(m_p_DialogObject, SIGNAL(return_main_page()), this, SLOT(Slot_ReturnHandle()));
    connect(m_p_MessageBoxObject, SIGNAL(messageOKEvent()), this, SLOT(Slot_InitTreeView()));
    connect(m_p_MessageBoxObject, SIGNAL(messageCannelEvent()), this, SLOT(Slot_InitTaskSelect()));
    connect(m_p_qmlPort, SIGNAL(clear_tree_list()), this, SLOT(Slot_ReturnHandle()));
    connect(m_p_qmlPort, SIGNAL(start_parse_task_pack_sig()), this, SLOT(SlotLoadHistory()));
    connect(m_p_qmlPort, SIGNAL(outline_ana_selected(QStringList, QStringList)), this, SLOT(Slot_OutlineTreeList(QStringList,QStringList)));
    connect(m_p_qmlPort, SIGNAL(task_loaded()), this, SLOT(Slot_task_load()));
    connect(m_p_qmlPort, SIGNAL(signal_remove_file(QString)), this, SIGNAL(Signal_Remove_File(QString)));

    connect(file_list, SIGNAL(signale_insert_table_analysis(QString)), this, SLOT(slot_insert_table_analysis(QString)));
    connect(folder_list, SIGNAL(signal_delete_table_analysis(QString)), this, SLOT(slot_delete_table_analysis(QString)));
    //connect(hpcameracap, SIGNAL(signal_save_temp_analysis(QString)), this, SLOT(slot_save_temp_analysis(QString)));

#if 0
    m_p_TaskSelectQWidget->installEventFilter(this);
    m_p_TreeViewQWidget->installEventFilter(this);
    m_p_MessageBoxQWidget->installEventFilter(this);
    m_p_MessageDialogQWidget->installEventFilter(this);
    AnalysisChartQWidget->installEventFilter(this);
#endif

    m_hasInit = 1;

    return 0;
}

/******************************************************************************************************
 * @ description : 打开作业包界面,SD卡提示界面或恢复提示界面
 * @ param       : NULL
 * @ return      : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Open_Dlg()
{
#if 0
    Dump_to_index_by_name("aaa");
    return 0;
#endif

    MYLOG << " RUNNING . . . ";
    if(m_p_MessageBoxQWidget->isVisible()
            || m_p_MessageDialogQWidget->isVisible()
            || m_p_TaskSelectQWidget->isVisible()
            || m_p_TreeViewQWidget->isVisible())
        return RET_IS_SHOW;
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    m_b_qml_status = true;
    /* 未插入SD卡 */
    if(! m_p_qmlPort->is_inserted_sd()) {
        Init_MessageDialogQWidget();
    /* 已插入SD卡 */
    } else {
        if( m_p_qmlPort->get_restore_last_shoot_status_flag() != 1 ) {
            Init_SelectTaskQWidget();
        } else {
            Init_MessageBoxQWidget();
        }
    }

    return RET_OK;
}


/******************************************************************************************************
 * @ description : 初始化并显示恢复拍摄提示界面
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Init_MessageBoxQWidget()
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }

    m_p_qmlPort->Init_TaskBoxEX();
    QMetaObject::invokeMethod(m_p_MessageBoxObject,"init_dlg");
    m_p_MessageBoxObject->setProperty("show_list", true);
    m_p_MessageBoxQWidget->setFocus();
    m_p_MessageBoxQWidget->show();

    m_p_qmlPort->set_restore_last_shoot_status_flag( 0 );

    MYLOG << "TODO Signal_Show_MessageBox";
    emit Signal_Show_MessageBox();
}


/******************************************************************************************************
 * @ description : 初始化并显示SD卡提示界面
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Init_MessageDialogQWidget()
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }

    QVariant returnVar;
    QVariant arg1 = tr( "请插入SD卡" );
    QMetaObject::invokeMethod(m_p_DialogObject, "information", Q_RETURN_ARG(QVariant, returnVar),Q_ARG(QVariant, arg1));
    m_p_MessageDialogQWidget->show();

    MYLOG << "TODO Signal_Show_MessageDialog";
    emit Signal_Show_MessageDialog();
}


/******************************************************************************************************
 * @ description : 初始化并显示作业包选择界面
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Init_SelectTaskQWidget()
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }

    xml_list->uinit_xml_list();
    if(m_p_MessageBoxQWidget->isVisible()) {
        QMetaObject::invokeMethod(m_p_MessageBoxObject,"init_dlg");
        delaymsec(3);
        m_p_MessageBoxQWidget->hide();
    }

    m_p_TaskSelectQWidget->setSource(QUrl("qrc:///machine/TaskSelectList.qml"));
    QObject *p_TaskSelectObject = (QObject*) m_p_TaskSelectQWidget->rootObject();
    connect(p_TaskSelectObject, SIGNAL(sig_return_main_wnd()), this, SLOT(Slot_ReturnHandle()));
    connect(p_TaskSelectObject, SIGNAL(restore_main_form()), this, SLOT(Slot_InitTreeView()));
    connect(p_TaskSelectObject, SIGNAL(start_sel_taskTree()), this, SLOT(slot_start_sel_taskTree()));
    connect(p_TaskSelectObject, SIGNAL(select_xml()), this, SLOT(Slot_selectXml()));
    QMetaObject::invokeMethod(p_TaskSelectObject,"init_task_select_list");
    m_p_TaskSelectQWidget->setFocus();
    m_p_TaskSelectQWidget->show();
    m_p_MessageBoxObject->setProperty("show_list", false);
    p_TaskSelectObject->setProperty("show_list", true);

    MYLOG << "TODO Signal_Show_TaskSelect";
    emit Signal_Show_TaskSelect();
}

void Hp_TaskPkg::Slot_selectXml()
{
    MYLOG << xml_list->get_select_xml();
    emit Signal_get_select_xml(xml_list->get_select_xml());
}


void Hp_TaskPkg::slot_start_sel_taskTree()
{
    m_sem_taskTree->acquire(1);
}


/******************************************************************************************************
 * @ description : 初始化并显示设备拍摄界面
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Init_TreeViewQWidget()
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }

    m_p_qmlPort->set_restore_last_shoot_status_flag(1);
    if(! m_b_qml_status) {
        MYLOG << "m_b_qml_status : " << m_b_qml_status << " ! ! !";
        return;
    }

    m_p_TreeViewQWidget->setSource(QUrl("qrc:///machine/TreeViewEx.qml"));
    QObject* p_TreeViewObject = (QObject*) m_p_TreeViewQWidget->rootObject();
    connect(p_TreeViewObject, SIGNAL(treeViewReturn()), this, SLOT(SlotReturnFormTree()));
    connect(p_TreeViewObject, SIGNAL(histortShow()), this, SLOT(SlotInitHistory()));
    connect(p_TreeViewObject, SIGNAL(reset_curSelFlag()), this, SLOT(Slot_reset_sel_flag()));
    connect(p_TreeViewObject, SIGNAL(sig_interaction_show()), this, SLOT(slot_interaction_show()));
    //connect(p_TreeViewObject, SIGNAL(createFinish()), this, SLOT(SlotcreateFinish()));
    QMetaObject::invokeMethod(p_TreeViewObject,"init_focus");
    m_p_TreeViewQWidget->setFocus();
    m_p_TreeViewQWidget->show();
    p_TreeViewObject->setProperty("bshow_list", true);

    MYLOG << "TODO Signal_Show_TreeView";
    emit Signal_Show_TreeView();
    m_sem_taskTree->release(1);

    if(!m_save_imgName.isEmpty() || !m_save_anaInfos.isEmpty())
        emit Signal_ChangeAnaInfo(m_save_imgName, m_save_anaInfos);
}

void Hp_TaskPkg::Slot_reset_sel_flag()
{
    TASK_TREE_INFO selTreeInfo = m_p_qmlPort->get_curSelInfo();
    mp_analyOP->reset_capture_flag_by_index(selTreeInfo.task_info);
}

/******************************************************************************************************
 * @ description : 退出界面
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Slot_ReturnHandle()
{
    MYLOG << " RUNNING . . . ";

    if(AnalysisChartQWidget->isVisible()) {
        AnalysisChartQWidget->hide();
        MYLOG << "TODO Signal_Show_TreeView";
        emit Signal_Show_TreeView();
        return;
    }

    delaymsec(100);

    m_sem_taskTree->acquire(1);

    if(m_p_MessageBoxQWidget->isVisible())
        m_p_MessageBoxQWidget->hide();
    if(m_p_MessageDialogQWidget->isVisible())
        m_p_MessageDialogQWidget->hide();
    if(m_p_TaskSelectQWidget->isVisible())
        m_p_TaskSelectQWidget->hide();
    if(m_p_TreeViewQWidget->isVisible())
        m_p_TreeViewQWidget->hide();
    if( AnalysisChartQWidget->isVisible())
        AnalysisChartQWidget->hide();

    m_b_qml_status = false;
    tree_index = 0;
    MYLOG << "TODO Signal_CloseDlg";
    emit Signal_CloseDlg();

    m_sem_taskTree->release(1);
}


void Hp_TaskPkg::delaymsec(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


/******************************************************************************************************
 * @ description : 槽函数 执行设备拍摄界面初始化函数
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Slot_InitTreeView()
{
    MYLOG << " RUNNING . . . " << tree_index;

    if(tree_index == 0) {
        check_taskPkg_analysis();
        mp_analyOP->Init_MapDevices(m_p_qmlPort->get_taskpack_db_name());
        m_mapDevices = mp_analyOP->Get_MapDevices();
        mp_analyOP->Open_analysis_db();
        mp_analyOP->Set_current_dbName(m_p_qmlPort->get_taskpack_db_name());
        mp_analyOP->Init_MapFlags();
    }
    tree_index++;
    if(tree_index != 1) {
        MYLOG << "RETURN ! ! ! " << tree_index;
        return;
    }
    MYLOG << "--- --- --- --- ---> " << tree_index;

    if(m_p_TaskSelectQWidget->isVisible()) {
        m_p_qmlPort->reset_taskType_dlg();
        delaymsec(10);
        m_p_TaskSelectQWidget->hide();
        tree_start_status = false;
    }
    if(m_p_MessageBoxQWidget->isVisible()) {
        QMetaObject::invokeMethod(m_p_MessageBoxObject,"init_dlg");
        delaymsec(3);
        m_p_MessageBoxQWidget->hide();
        tree_start_status = true;
    }
    if (m_b_jumpFlag) {
        m_b_jumpFlag = false;
        tree_start_status = true;
    }

    Init_TreeViewQWidget();
}

void Hp_TaskPkg::SlotLoadHistory()
{

}


/******************************************************************************************************
 * @ description : 槽函数 执行作业包选择界面初始化函数
 * @ param       : NULL
 * @ return      : NULL
 ******************************************************************************************************/
void Hp_TaskPkg::Slot_InitTaskSelect()
{
    MYLOG << " RUNNING . . . ";

    Init_SelectTaskQWidget();
}


/******************************************************************************************************
 * @ description               : 槽函数 获取分析轮廓及图片数据
 * @ param - s_outline_fn_list : 设备图片名
 * @ param - s_ana_list        : 分析框图坐标参数
 * @ return                    : NULL
 *****************************************************************************************************/
void Hp_TaskPkg::Slot_OutlineTreeList(QStringList s_outline_fn_list, QStringList s_ana_list)
{
    MYLOG << " RUNNING . . . ";

    m_save_imgName.clear();
    m_save_anaInfos.clear();
    if(s_outline_fn_list.isEmpty() && s_ana_list.isEmpty()) {
        mp_analyOP->Get_unit_change("");
        return;
    }

    QString db_name;
    QString ser_path;
    QString file_name;
    QString ana_info;
    QStringList ana_info_list;

    m_v_anaInfos.clear();
    db_name = m_p_qmlPort->get_taskpack_db_name();
    ser_path = db_name.remove(db_name.lastIndexOf( "/"), db_name.size() - db_name.lastIndexOf( "/"));
    if(s_outline_fn_list.count() > 0)
        file_name = ser_path + "/outlines/" + s_outline_fn_list.at(0);
    if(s_ana_list.count() > 0)
        ana_info = s_ana_list.at(0);

    mp_analyOP->Get_unit_change(ana_info);

    ana_info_list = ana_info.split(";-");
    for(int i = 0; i < ana_info_list.count(); i++) {
        ANA_OUTLINE anaInfo;
        QString ana_cell = ana_info_list.at(i);
        if (ana_cell.isEmpty())
            break;
        QStringList ana_temp_base = ana_cell.split(":");
        if(ana_temp_base.count() == 2) {
            QString comName = ana_temp_base.at(0);
            QString strRect = ana_temp_base.at(1);
            QString strType = comName.mid(0, 1);
            QString strName = comName.remove(0, 1);
            QStringList strRectSplit = strRect.split(";");
            QStringList strRectStart;
            QStringList strRectEnd;

            if(strType == "P" && strRectSplit.count() == 1) {
                strRectStart = strRectSplit.at(0).split(",");
            } else if(strType == "L" && strRectSplit.count() == 2) {
                strRectStart = strRectSplit.at(0).split(",");
                strRectEnd = strRectSplit.at(1).split(",");
            } else if(strType == "R" && strRectSplit.count() == 2) {
                strRectStart = strRectSplit.at(0).split(",");
                strRectEnd = strRectSplit.at(1).split(",");
            }

            if(strRectStart.count() == 2) {
                anaInfo.origin_xcoord = strRectStart.at(0).toInt(); //起点坐标
                anaInfo.origin_ycoord = strRectStart.at(1).toInt();
            }
            if(strRectEnd.count() == 2) {
                anaInfo.dest_xcoord = strRectEnd.at(0).toInt();     //终点坐标
                anaInfo.dest_ycoord = strRectEnd.at(1).toInt();
            }

            QByteArray b_anaType = strType.toLatin1();
            strcpy(anaInfo.ana_type, b_anaType.data());             //分析类型
            anaInfo.ana_type[strType.count()] = '\0';
            QByteArray b_deviceType = strName.toLatin1();
            strcpy(anaInfo.deviceType, b_deviceType.data());        //设备名称
            anaInfo.deviceType[strName.count()] = '\0';

            m_v_anaInfos.append(anaInfo);
        }
    }

    if(m_p_TreeViewQWidget->isVisible()) {
        emit Signal_ChangeAnaInfo(file_name, m_v_anaInfos);
    } else {
        m_save_imgName = file_name;
        m_save_anaInfos = m_v_anaInfos;
    }
}


/******************************************************************************************************
 * @ description      : 轮廓图片处理
 * @ param - fileName : 轮廓图片文件名
 * @ return           : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Bmp2Png(QImage &img)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    img = img.convertToFormat(QImage::Format_RGBA8888_Premultiplied, Qt::NoFormatConversion);
    int bmpWidth = img.width();
    int bmpHeight = img.height();

    QColor bmpBack(0, 0, 0);
    QColor bmpBack2(255, 255, 255, 255);
    QColor bmpBackA(255, 255, 255, 0);
    QColor bmpBackR(0, 255, 255, 255);

    for(int i = 0; i < bmpWidth; ++i) {
        for(int j = 0; j < bmpHeight; ++j) {
            if(/*(bmp.pixelColor(i, j) == bmpBack) ||*/ (img.pixelColor(i, j) != bmpBack2)) {
                img.setPixelColor(i, j, bmpBackA);
            } else {
                img.setPixelColor(i, j, bmpBackR);
            }
        }
    }

    return RET_OK;
}


/******************************************************************************************************
 * @ description : 主动关闭作业包界面
 * @ param       : NULL
 * @ return      : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Close_Dlg()
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    Slot_ReturnHandle();
    return RET_OK;
}


/******************************************************************************************************
 * @ description         : 图片文件重命名
 * @ param - fileName    : 需要重命名的文件
 * @ param - videoMode   : 视频模式
 * @ return              : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Rename_Img(QString &fileName, int videoMode, QVector<ANA_OUTLINE> tempInfos)
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    if(! m_p_TreeViewQWidget->isVisible())
        return RET_TREE_ERR;

    QString strPath = m_p_qmlPort->get_cunrrentdb_savepath();
    QDir dir;
    if (!dir.exists(strPath)) {
        qDebug() << "dir " << strPath << " is not exist !!!";
        return -1;
    }

    TASK_TREE_INFO selTreeInfo = m_p_qmlPort->get_curSelInfo();
    mp_analyOP->Set_capturt_flag(selTreeInfo.task_info);
    QString dbName = m_p_qmlPort->get_taskpack_db_name();
    QStringList filePaths = dbName.split("/");

    QString strNewName = m_p_qmlPort->GetCurrentImgName();

#if 1
    //台账 Version2.0 重命名修改
    QString strSetFile;
    for (int i = 0; i < filePaths.count()-1; i++) {
        strSetFile += filePaths.at(i) + "/";
    }
    strSetFile += "setting.conf";
    QString ident = m_setting.setting_para_read(strSetFile, SETTING_IDENT_CODE);
    QString cap = "";
    if (ident.compare(QString("ERROR")) == 0) {
        qDebug() << "ident is not exist";
    /* 新版本 */
    } else {
        qDebug() << "ident : " << ident;
        QString strContent = selTreeInfo.content;
        QStringList listContent = strContent.split(";-");
        if (listContent.count() >= 8) {
            QString strCap = listContent.at(7);
            QStringList listCap = strCap.split(":");
            if (listCap.count() >= 2) {
                cap = listCap.at(1);
            }
        }

        QString strTmp;
        QStringList listNewName = strNewName.split("-");
        for (int i = 0; i < listNewName.count()-1; i++) {
            strTmp += listNewName.at(i);
            strTmp += "-";
        }
        strTmp += cap + "-" + ident + "-" + listNewName.at(listNewName.count()-1);
        strNewName = strTmp;
    }
#endif

    QString tmp_fileName = QString("%1/%2").arg(strPath).arg(strNewName);
    QString new_fileName = QString("%1/%2").arg(strPath).arg(strNewName);
    QString old_fileName = QString("%1/%2").arg(m_strSDPath).arg(fileName);

    if(videoMode == MODE_KEJIAN) {
        new_fileName += ".vi.jpg";
    } else {
        new_fileName += ".irp.jpg";
    }
    qDebug() << "new img : " << new_fileName;

    if(! QFile::exists(old_fileName))
        return RET_FILE_ERR;

    if(QFile::exists(new_fileName)) {
        QStringList namePaths = strNewName.split("-");
        if(filePaths.count() < 5)
            return RET_FILE_ERR;
        QString pkgName = filePaths.at(4);
        QPair<QString, QString> where;
        where.first = "date";
        where.second = namePaths.at(0);
        mp_analyOP->Delete_line_analysis_db(pkgName, where);
        QFile::remove(new_fileName);
    }

    if(! QFile::rename(old_fileName, new_fileName))
        return RET_RENAME_ERR;

    //QStringList pathList = new_fileName.split("/");
    //fileName = pathList.at(pathList.count() - 1);
    fileName = new_fileName;
    slot_save_temp_analysis(tmp_fileName, tempInfos);
    m_p_qmlPort->capture_to_tree();

    return RET_OK;
}

/******************************************************************************************************
 * @ description     : 获取当前活跃界面名
 * @ param - dlgName : 当前活跃界面名
 *                     TaskSelect -> 作业包选择界面
 *                     MessageBox -> 恢复拍摄状态界面
 *                     MessageDialog -> SD卡未插入提示界面
 *                     TreeView -> 拍摄树界面
 * @ return          : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Get_CurrentDlg(QString &dlgName)
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    dlgName.clear();
    if(m_p_MessageBoxQWidget->isVisible())
        dlgName = DLG_NAME_MESSAGEBOX;
    if(m_p_MessageDialogQWidget->isVisible())
        dlgName = DLG_NAME_MESSAGEDIALOG;
    if(m_p_TaskSelectQWidget->isVisible())
        dlgName = DLG_NAME_TASKSELECT;
    if(m_p_TreeViewQWidget->isVisible())
        dlgName = DLG_NAME_TREEVIEW;
    if(AnalysisChartQWidget->isVisible())
        dlgName = DLG_NAME_ANALYSIS;

    return RET_OK;
}


/******************************************************************************************************
 * @ description       : 通过温度信息计算报错结果
 * @ param - ana_infos : 温度信息
 * @ param - env_temp  : 环境温度
 * @ param - flag      : 警报等级 (未知/正常/关注/一般缺陷/严重缺陷/紧急缺陷)
 * @ param - title     : 警报标题
 * @ param - text      : 警报提示文本
 * @ return            : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Cal_TaskWarning(QVector<ANA_OUTLINE> ana_infos, float env_temp, QString &flag, QString &title, QString &text, int &err_id)
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
#if 0
    for(int i = 0; i < ana_infos.count(); i++) {
        qDebug() << "\r\n";
        qDebug() << ana_infos.at(i).ana_type << "\r\n";
        qDebug() << ana_infos.at(i).avgtemp << "\r\n";
        qDebug() << ana_infos.at(i).dest_xcoord << "\r\n";
        qDebug() << ana_infos.at(i).dest_ycoord << "\r\n";
        qDebug() << ana_infos.at(i).deviceType << "\r\n";
        qDebug() << ana_infos.at(i).id << "\r\n";
        qDebug() << ana_infos.at(i).maxtemp << "\r\n";
        qDebug() << ana_infos.at(i).mintemp << "\r\n";
        qDebug() << ana_infos.at(i).origin_xcoord << "\r\n";
        qDebug() << ana_infos.at(i).origin_ycoord << "\r\n";
        qDebug() << "\r\n";
    }
#endif
    if(! m_p_TreeViewQWidget->isVisible())
        return RET_TREE_ERR;

    flag = "未知";
    title.clear();
    text.clear();

    int     devType = 0;
    QString devName = "";
    QString devRule = "";
    QString devTitle = "";
    QString devText = "";
    QString devFormula = "";

    int errId = -1;
    QString errFlag = "";
    QString errTitle = "";
    QString errText = "";

    DEVTYPEINFO devTypeInfo    = m_p_qmlPort->get_curDevInfo();         //公式等信息
    TASK_TREE_INFO selTreeInfo = m_p_qmlPort->get_curSelInfo();         //当前选择设备信息
    QStringList fault_list     = m_p_qmlPort->get_fault_nature_list();  //错误等级列表

#if 0
    qDebug() << "\r\n\r\n";
    qDebug() << "--- local_name = " << selTreeInfo.local_name << "\r\n";
    qDebug() << "--- task_name = " << selTreeInfo.task_name << "\r\n";
    qDebug() << "--- path_list = " << selTreeInfo.path_list << "\r\n";
    qDebug() << "--- task_info = " << selTreeInfo.task_info << "\r\n";
    qDebug() << "--- device_type_id = " << selTreeInfo.device_type_id << "\r\n";
    qDebug() << "--- model_style_id = " << selTreeInfo.model_style_id << "\r\n";
    qDebug() << "--- part_postion_id = " << selTreeInfo.part_postion_id << "\r\n";
    qDebug() << "--- device_param_id = " << selTreeInfo.device_param_id << "\r\n";
    qDebug() << "--- basic_subtypes_id = " << selTreeInfo.basic_subtypes_id << "\r\n";
    qDebug() << "--- device_comment = " << selTreeInfo.device_comment << "\r\n";
    qDebug() << "--- father_id = " << selTreeInfo.father_id << "\r\n";
    qDebug() << "--- down_node_number = " << selTreeInfo.down_node_number << "\r\n";
    qDebug() << "--- task_level = " << selTreeInfo.task_level << "\r\n";
    qDebug() << "\r\n\r\n";
#endif

    /* 设备信息 */
    ANA_DEVICE tmp_device;
    QStringList deviceNames = selTreeInfo.task_info.split("-");
    if(deviceNames.count() > 3)
        tmp_device.device_name = QString("%1-%2-%3").arg(deviceNames.at(0)).arg(deviceNames.at(1)).arg(deviceNames.at(2));
    tmp_device.device_pos = selTreeInfo.task_name.remove(selTreeInfo.local_name);

    /* 添加设备及温度信息 */
    m_p_formula->add_deviceInfo(tmp_device, ana_infos);
    /* 设置环境温度 */
    m_p_formula->set_envTemp(env_temp);
    /* 遍历设备相关公式及报警信息 */
    for(int i = 0; i < devTypeInfo.vc_rules.count(); i++) {
        devName    = devTypeInfo.vc_rules.at(i).ana_other_name;     //部位名称
        devType    = devTypeInfo.vc_rules.at(i).n_error_type;       //警报等级
        devRule    = devTypeInfo.vc_rules.at(i).s_rule;             //规则范围
        devTitle   = devTypeInfo.vc_rules.at(i).s_rule_title;       //报警标题
        devText    = devTypeInfo.vc_rules.at(i).s_rule_text;        //报警文本
        devFormula = devTypeInfo.vc_rules.at(i).s_rule_formula;     //计算公式

        /* 计算 */
        if(m_p_formula->calculate_rule_formula(tmp_device.device_name, tmp_device.device_pos, devName, devRule, devFormula))
        {
            if(devType > errId) {
                errId = devType;
                errText = devText;
                errTitle = devTitle;
            }
        }
    }
    if(errId == -1)
        errFlag = fault_list.at(fault_list.count() - 1);
    else if(errId > 0 && errId < fault_list.count())
        errFlag = fault_list.at(errId - 1);

    flag = errFlag;
    title = errTitle;
    text = errText;
    err_id = errId;
    return RET_OK;
}


/******************************************************************************************************
 * @ description    : 设置拍摄界面控件使能状态
 * @ param - enable : 使能状态
 * @ return         : 0-->成功  非0-->失败
 ******************************************************************************************************/
int Hp_TaskPkg::Enable_TreeView(bool enable)
{
    MYLOG << " RUNNING . . . ";
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    if(! m_p_TreeViewQWidget->isVisible())
        return RET_TREE_ERR;

    m_p_qmlPort->enable_TreeView(enable);

    return RET_OK;
}


void Hp_TaskPkg::hp_InstallEventFilter(QObject *o)
{
   m_p_TaskSelectQWidget->installEventFilter(o);
   m_p_TreeViewQWidget->installEventFilter(o);
   m_p_MessageBoxQWidget->installEventFilter(o);
   m_p_MessageDialogQWidget->installEventFilter(o);
   AnalysisChartQWidget->installEventFilter(o);
   m_p_InteractionQWidget->installEventFilter(o);
}


/******************************************************************************************************
 * @ description : 移动恢复拍摄界面
 * @ param - x   : x
 * @ param - y   : y
 * @ return      : null
 ******************************************************************************************************/
int Hp_TaskPkg::Move_MessageBox(int x, int y)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    if(!m_p_MessageBoxQWidget->isVisible()) {
        if (m_screen_id == SCREEN_480_272) {
            m_p_MessageBoxQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_800_480) {
            m_p_MessageBoxQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_800_480_2) {
            m_p_MessageBoxQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_853_480) {
            m_p_MessageBoxQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_1920_1080) {
            m_p_MessageBoxQWidget->move(x, y);
        }
    }

    return 0;
}


/******************************************************************************************************
 * @ description : 移动SD卡提示界面
 * @ param - x   : x
 * @ param - y   : y
 * @ return      : null
 ******************************************************************************************************/
int Hp_TaskPkg::Move_MessageDialog(int x, int y)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    if(!m_p_MessageDialogQWidget->isVisible()) {
        if (m_screen_id == SCREEN_480_272) {
            m_p_MessageDialogQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_800_480) {
            m_p_MessageDialogQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_800_480_2) {
            m_p_MessageDialogQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_853_480) {
            m_p_MessageDialogQWidget->move(x, y);
        } else if (m_screen_id == SCREEN_1920_1080) {
            m_p_MessageDialogQWidget->move(x, y);
        }
    }

    return 0;
}

/**************************************************************************************
 * @ description : 检查统计分析数据库中是否存在当前作业包对应的表,没有则创建
 * @ param       : null
 * @ return      : null
 **************************************************************************************/
void Hp_TaskPkg::check_taskPkg_analysis()
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }
    QString dbName = m_p_qmlPort->get_taskpack_db_name();
    QStringList filePaths = dbName.split("/");
    if(filePaths.count() < 5) {
        qDebug() << "check_taskPkg_analysis dbName " << dbName << " !!!";
        return;
    }
    QString pkgName = filePaths.at(4);
    mp_analyOP->Insert_table_analysis_db(pkgName);
}

/**************************************************************************************
 * @ description : 导入作业包时, 新建表格
 * @ param       : 需要新建的表格名
 * @ return      : null
 **************************************************************************************/
void Hp_TaskPkg::slot_insert_table_analysis(QString tableName)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }
    mp_analyOP->Insert_table_analysis_db(tableName);
}

/**************************************************************************************
 * @ description       : 删除作业包时, 删除对应表格
 * @ param - tableName : 需要删除的表格名
 * @ return            : null
 **************************************************************************************/
void Hp_TaskPkg::slot_delete_table_analysis(QString tableName)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }
    mp_analyOP->Delete_table_analysis_db(tableName);
}

void Hp_TaskPkg::InitAnalysisView()
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return;
    }
    AnalysisChartQWidget->setSource(QUrl("qrc:///machine/AnalysisChart.qml"));
    QObject *AnalysisObject = (QObject*) AnalysisChartQWidget->rootObject();
    connect(AnalysisObject, SIGNAL(sig_return_tree_wnd()), this, SLOT(SlotRetureTree()));
    AnalysisChartQWidget->setFocus();
    AnalysisChartQWidget->show();

    MYLOG << "TODO Signal_Show_AnalysisChart";
    emit Signal_Show_AnalysisChart();
}

void Hp_TaskPkg::SlotRetureTree()
{
    if( AnalysisChartQWidget->isVisible() ) {
        AnalysisChartQWidget->hide();
        emit Signal_Show_TreeView();
    }
}

void Hp_TaskPkg::SlotInitHistory()
{
    QString pkgName;
    QString deviceInfo;

    TASK_TREE_INFO selTreeInfo = m_p_qmlPort->get_curSelInfo();
    QStringList pathList = m_p_qmlPort->get_taskpack_db_name().split("/");
    if(pathList.count() > 5)
        pkgName = pathList.at(4);
    deviceInfo = selTreeInfo.task_info;

    mp_analyOP->Get_historyData(pkgName, deviceInfo);

    InitAnalysisView();
}


/**************************************************************************************
 * @ description     : 作业包下拍摄图片时, 将数据插入表格
 * @ param - imgName : 图片名
 * @ return          : null
 **************************************************************************************/
void Hp_TaskPkg::slot_save_temp_analysis(QString imgName, QVector<ANA_OUTLINE>tempInfos)
{
    MYLOG << " RUNNING . . . " << imgName;

    QList<QString> listInsertValue;
    QString strImgName;
    QString strTableName;
    QString strTmpTableName;
    QString strDeviceId;
    QString strDate;
    QString strDeviceInfo;
    QString strTmpDeviceInfo;
    QString strCoords;
    QString strTmpCoords;
    QString strTemp;
    QString strIrType;

    if (tempInfos.count() <= 0)
        return;

    /* strImgName */
    QStringList listImgPath = imgName.split("/");
    if(listImgPath.count() != 6) {
        qDebug() << "\r\n------------------->>>>>>>>>   0\r\n";
        return;
    }
    strImgName = QString("\"%1\"").arg(listImgPath.at(5));

    /* strIrType */
    QStringList listImgPath_2 = QString(listImgPath.at(5)).split(".");
    if(listImgPath_2.count() >= 3)
        strIrType = listImgPath_2.at(listImgPath_2.count() - 2);

    /* strTableName */
    QStringList listDbPath = m_p_qmlPort->get_taskpack_db_name().split("/");
    for (int i = 0; i < listDbPath.count(); i++)
        qDebug() << "listDbPath.at(" << i << ") : " << listDbPath.at(i);
    if(listDbPath.count() != 6) {
        qDebug() << "\r\n------------------->>>>>>>>>   1\r\n";
        return;
    }
    strTableName = QString("\"%1\"").arg(listDbPath.at(4));
    strTmpTableName = listDbPath.at(4);

    /* strDate */
    QStringList listDeviceInfo = QString(listImgPath.at(5)).split("-");
    for (int i = 0; i < listDeviceInfo.count(); i++)
        qDebug() << "listDeviceInfo.at(" << i << ") : " << listDeviceInfo.at(i);
    if(listDeviceInfo.count() != 8) {
        qDebug() << "\r\n------------------->>>>>>>>>   2\r\n";
        return;
    }
    strDate = listDeviceInfo.at(0);

    /* strDeviceInfo */
    QStringList lisTail = QString(listDeviceInfo.at(7)).split(".");
    for (int i = 0; i < lisTail.count(); i++)
        qDebug() << "lisTail.at(" << i << ") : " << lisTail.at(i);
    if(lisTail.count() < 1) {
        qDebug() << "\r\n------------------->>>>>>>>>   3\r\n";
        return;
    }
    strDeviceInfo.append("\"");
    for(int i = 1; i < listDeviceInfo.count(); i++) {
        if(i != listDeviceInfo.count() - 1) {
            strDeviceInfo.append(listDeviceInfo.at(i));
            strTmpDeviceInfo.append(listDeviceInfo.at(i));
            strDeviceInfo.append("-");
            strTmpDeviceInfo.append("-");
        } else {
            strDeviceInfo.append(lisTail.at(0));
            strTmpDeviceInfo.append(lisTail.at(0));
        }
    }
    strDeviceInfo.append("\"");

    /* strDeviceId */
    QMap<QString, int>::iterator iter = m_mapDevices.find(mp_analyOP->replace_covert_char(strTmpDeviceInfo));
    if(iter == m_mapDevices.end()) {
        qDebug() << "\r\n------------------->>>>>>>>>   4\r\n" << strTmpDeviceInfo;
        return;
    }
    strDeviceId = QString("%1").arg(iter.value());

#if 0
    /* 读取文件头信息 */
    int tag_num;
    int id;
    int Qt_index;
    bool value;
    QByteArray bImgName = imgName.toUtf8();
    char* cImgName = bImgName.data();
    QFile file(imgName);
    if(! file.exists()) {
        qDebug() << "\r\n------------------->>>>>>>>>   5\r\n";
        return;
    }
    QVector<ANA_OUTLINE> tmpInfos;
    ti600s_picInfo_t picInfo;
    picInfo.jpeg_fp = fopen(cImgName, "r");
    if(picInfo.jpeg_fp == NULL) {
        qDebug() << "\r\n------------------->>>>>>>>>   6\r\n";
        return;
    }
    fseek(picInfo.jpeg_fp, 0, SEEK_END);
    fseek(picInfo.jpeg_fp, -sizeof(tagnum_t), SEEK_CUR);
    fread(&picInfo.tagnum, 1, sizeof(tagnum_t), picInfo.jpeg_fp);

    if(picInfo.tagnum.nTag == TAGNUM_TAG) {
        tag_num = picInfo.tagnum.num;
    } else  {
        qDebug() << "\r\n------------------->>>>>>>>>   7\r\n";
        return;
    }

    fseek(picInfo.jpeg_fp, -sizeof(tagnum_t)-sizeof(taginfo_t)*tag_num, SEEK_CUR);    //移动到当前位置的。。。。处
    fread(picInfo.taginfo, 1, sizeof(taginfo_t)*tag_num, picInfo.jpeg_fp);            //读取 m 个标签结构体数量的大小

    for(int i = 0; i < tag_num; i++) {
        if(FILEINFO_TAG == picInfo.taginfo[i].nTag) {
            fseek(picInfo.jpeg_fp, picInfo.taginfo[i].offset, SEEK_SET);     //p指针移动到离文件开头（对应标签信息在文件中的便宜）字节处
            fread(&picInfo.head, 1, sizeof(picInfo.head), picInfo.jpeg_fp);

            temper_info_t *ptemper = &picInfo.head.temper;

            for(int k = 0; k < MAX_MEASURE_TEMP_POINT_NUM; k++) {   //点
                value = ptemper->point_array[k].bVaild;
                id = ptemper->point_array[k].nID;
                Qt_index = ptemper->point_array[k].nQt_index;
                if(value) {
                    ANA_OUTLINE param;
                    strncpy(param.ana_type, "P", 1);
                    QString strtest = QString(ptemper->draw_layer.Point[k].name);
                    strncpy(param.deviceType, ptemper->draw_layer.Point[k].name, strtest.count());
                    param.id = ptemper->draw_layer.Point[k].nRealIndex;
                    param.origin_xcoord = ptemper->draw_layer.Point[k].nX;
                    param.origin_ycoord = ptemper->draw_layer.Point[k].nY;
                    param.dest_xcoord = 0;
                    param.dest_ycoord = 0;
                    param.avgtemp = 0;
                    param.maxtemp = (float)ptemper->draw_layer.Point[k].nTemp / 100.00;
                    param.mintemp = 0;
                    tmpInfos.append(param);
                }
            }
            for(int k = 0; k < MAX_MEASURE_TEMP_LINE_NUM; k++) {    //线
                value = ptemper->line_array[k].bVaild;
                id = ptemper->line_array[k].nID;
                Qt_index = ptemper->line_array[k].nQt_index;
                if(value) {
                    ANA_OUTLINE param;
                    strncpy(param.ana_type, "L", 1);
                    QString strtest = QString(ptemper->draw_layer.Line[k].name);
                    strncpy(param.deviceType, ptemper->draw_layer.Line[k].name, strtest.count());
                    param.id = ptemper->draw_layer.Line[k].nRealIndex;
                    param.origin_xcoord = ptemper->draw_layer.Line[k].nStartX;
                    param.origin_ycoord = ptemper->draw_layer.Line[k].nStartY;
                    param.dest_xcoord = ptemper->draw_layer.Line[k].nEndX;
                    param.dest_ycoord = ptemper->draw_layer.Line[k].nEndY;
                    param.avgtemp = (float)ptemper->draw_layer.Line[k].sPointTemp.nTempAve100 / 100.00;
                    param.maxtemp = (float)ptemper->draw_layer.Line[k].sPointTemp.nTempMax100 / 100.00;
                    param.mintemp = (float)ptemper->draw_layer.Line[k].sPointTemp.nTempMin100 / 100.00;
                    tmpInfos.append(param);
                }
            }
            for(int k = 0; k < MAX_MEASURE_TEMP_RECT_NUM; k++) {    //框
                value = ptemper->rect_array[k].bVaild;
                id = ptemper->rect_array[k].nID;
                Qt_index = ptemper->rect_array[k].nQt_index;
                if(value) {
                    ANA_OUTLINE param;
                    strncpy(param.ana_type, "R", 1);
                    QString strtest = QString(ptemper->draw_layer.Rect[k].name);
                    strncpy(param.deviceType, ptemper->draw_layer.Rect[k].name, strtest.count());
                    param.id = ptemper->draw_layer.Rect[k].nRealIndex;
                    param.origin_xcoord = ptemper->draw_layer.Rect[k].nStartX;
                    param.origin_ycoord = ptemper->draw_layer.Rect[k].nStartY;
                    param.dest_xcoord = ptemper->draw_layer.Rect[k].nStartX + ptemper->draw_layer.Rect[k].nWidth;
                    param.dest_ycoord = ptemper->draw_layer.Rect[k].nStartY + ptemper->draw_layer.Rect[k].nHeight;
                    param.avgtemp = (float)ptemper->draw_layer.Rect[k].sPointTemp.nTempAve100 / 100.00;
                    param.maxtemp = (float)ptemper->draw_layer.Rect[k].sPointTemp.nTempMax100 / 100.00;
                    param.mintemp = (float)ptemper->draw_layer.Rect[k].sPointTemp.nTempMin100 / 100.00;
                    tmpInfos.append(param);
                }
            }
        }
    }
    fclose(picInfo.jpeg_fp);
#endif

    /* strCoords & strTemp */
    strCoords.append("\"");
    strTmpCoords.append("\"");
    strTemp.append("\"");
    for(int i = 0; i < tempInfos.count(); i++) {
        ANA_OUTLINE param = tempInfos.at(i);
        QString strTmp;
        if (param.deviceType[1] != '\0') {
            strTmp = QString("%1:%2%3:%4:%5,%6;%7,%8;-").arg(param.id).arg(param.deviceType[0])
                    .arg(param.deviceType[1]).arg(param.ana_type[0]).arg(param.origin_xcoord)
                    .arg(param.origin_ycoord).arg(param.dest_xcoord).arg(param.dest_ycoord);
        } else {
            strTmp = QString("%1:%2:%3:%4,%5;%6,%7;-").arg(param.id).arg(param.deviceType[0])
                    .arg(param.ana_type[0]).arg(param.origin_xcoord)
                    .arg(param.origin_ycoord).arg(param.dest_xcoord).arg(param.dest_ycoord);
        }
        strTmpCoords.append(strTmp);

        QString strTmp_2 = QString("%1,,;-").arg(param.maxtemp);
        strTemp.append(strTmp_2);
    }
    strCoords.append(QString("%1-%2").arg(strDate).arg(strDeviceId));
    strCoords.append("\"");
    strTmpCoords.append("\"");
    strTemp.append("\"");

    /* 写入作业包对应表 */
    listInsertValue.clear();
    listInsertValue.append(strDate);
    listInsertValue.append(strDeviceId);
    listInsertValue.append(QString("\"%1\"").arg(strIrType));
    listInsertValue.append(strTemp);
    mp_analyOP->Insert_line_analysis_db(strTmpTableName, listInsertValue);

    QPair<QString, QString> where;
    where.first = "id";
    where.second = strDeviceId;
    if(!mp_analyOP->Exist_line_analysis_db(QString("%1_croods").arg(strTmpTableName), where)) {
        QList<QString> strList;
        strList.clear();
        strList.append(strDeviceId);
        strList.append(strTmpCoords);

        mp_analyOP->Insert_line_analysis_db(QString("%1_croods").arg(strTmpTableName), strList);
    }

}


/**************************************************************************************
 * @ description : 逐级返回界面
 * @ param       : null
 * @ return      : null
 **************************************************************************************/
int Hp_TaskPkg::GoBack_Dlg()
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    if ( AnalysisChartQWidget->isVisible() ) {
        AnalysisChartQWidget->hide();
        MYLOG << "TODO Signal_Show_TreeView";
        emit Signal_Show_TreeView();
    } else if ( m_p_TreeViewQWidget->isVisible() ) {
        tree_index = 0;
        if(tree_start_status) {
            MYLOG << "TODO Signal_CloseDlg";
            emit Signal_CloseDlg();
            delaymsec(100);
        }
        m_p_TreeViewQWidget->hide();
        //m_b_qml_status = false;
        QMetaObject::invokeMethod(m_p_MessageBoxObject,"init_dlg");
        if(! tree_start_status) {
            m_p_TaskSelectQWidget->show();
            MYLOG << "TODO Signal_Show_TaskSelect";
            emit Signal_Show_TaskSelect();
            m_p_qmlPort->init_sel_taskType();
        }
    } else if ( m_p_TaskSelectQWidget->isVisible() ) {
        m_p_qmlPort->back_last_pkg();
    } else if ( m_p_MessageBoxQWidget->isVisible() ) {
        QMetaObject::invokeMethod(m_p_MessageBoxObject,"init_dlg");
        delaymsec(3);
        m_p_MessageBoxQWidget->hide();
    } else if ( m_p_MessageDialogQWidget->isVisible() ) {
        m_p_MessageDialogQWidget->hide();
    }

    return 0;
}

void Hp_TaskPkg::SlotReturnFormTree()
{
    tree_index = 0;
    if(tree_start_status) {
        MYLOG << "TODO Signal_CloseDlg";
        emit Signal_CloseDlg();
        delaymsec(100);
    }
    m_p_TreeViewQWidget->hide();
    if(! tree_start_status) {
        MYLOG << "TODO Signal_Show_TaskSelect";
        m_p_TaskSelectQWidget->show();
        emit Signal_Show_TaskSelect();
        m_p_qmlPort->init_sel_taskType();
    }
}


/**************************************************************************************
 * @ description        : 外部跳转至作业包
 * @ param - strDevName : 0级设备名称 包名
 * @ return             : null
 **************************************************************************************/
int Hp_TaskPkg::Dump_to_task_by_name_extend(QString strDevName)
{
    MYLOG << " RUNNING . . . " << strDevName;
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    if (m_p_TreeViewQWidget->isVisible()) {
        MYLOG << "m_p_TreeViewQWidget is already available ! ! !";
        return -1;
    }

    QString tmpDirName = QString("/mnt/data/unzipped/%1").arg(strDevName);
    QDir tmpDir(tmpDirName);
    if (! tmpDir.exists()) {
        MYLOG << tmpDirName << "is not exist ! ! !";
        return -1;
    }

    m_b_qml_status = true;

    m_p_qmlPort->set_taskpack_cell_byname(strDevName);

    m_p_qmlPort->set_device_tree_expand_way(1);
    m_p_qmlPort->is_task_area_selectded();

    m_p_qmlPort->regist_success_slot();

    tree_start_status = true;

    return 0;
}

void Hp_TaskPkg::Slot_task_load()
{
    MYLOG << "RUNNING . . .";
    if (m_p_TaskSelectQWidget->isVisible()) {
        return;
    }

    m_b_jumpFlag = true;
    Slot_InitTreeView();
}

void Hp_TaskPkg::SlotcreateFinish()
{
    MYLOG << "RUNNING . . .";
}


/**************************************************************************************
 * @ description        : 内部跳转 根据设备名跳转至指定索引位置
 * @ param - strDevName : 4级设备名称 站名;-设备规格;-设备间隔;-设备名称;-相位
 *                        3级设备名称 站名;-设备规格;-设备间隔;-设备名称
 *                        2级设备名称 站名;-设备规格;-设备间隔
 *                        1级设备名称 站名;-设备规格
 * @ return             : null
 **************************************************************************************/
int Hp_TaskPkg::Dump_to_index_by_name(QString strDevName)
{
    MYLOG << " RUNNING . . . " << strDevName;
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }

    if (! m_p_TreeViewQWidget->isVisible()) {
        MYLOG << "m_p_TreeViewQWidget is unavailable ! ! !";
        return -1;
    }

    int i = 0;
    int j = 0;
    int index = 1;
    QStringList strDevNames = strDevName.split(";-");
    QString strCurPathlist;
    TASK_TREE_INFO treeInfo;

    QList<TASK_TREE_INFO> list_treeInfos = m_p_qmlPort->get_tree_listInfo();

    if(strDevNames.at(0) != m_p_qmlPort->get_task_tree_list_str(0)) {
        qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : station is error " << strDevNames.at(0) << " != " << m_p_qmlPort->get_task_tree_list_str(0) << " ! ! !\r\n";
        return -1;
    }

    if (strDevNames.count() != 2 && strDevNames.count() != 3 &&
        strDevNames.count() != 4 && strDevNames.count() != 5) {
        qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : param is error ! ! !\r\n";
        return -1;
    }

    for (j = 1; j < strDevNames.count(); j++) {
        for (i = index; i < m_p_qmlPort->get_task_tree_list_count(); i++) {
            if (m_p_qmlPort->get_task_tree_list_str(i) == strDevNames.at(j)) {
                qDebug() << m_p_qmlPort->get_task_tree_list_str(i) << " - " << strDevNames.at(j);
                index = i;
                break;
            }
        }
    }

    treeInfo = list_treeInfos.at(index);
    strCurPathlist = treeInfo.path_list;
    QStringList strCurPaths = strCurPathlist.split("/");

    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strCurPathlist = " << strCurPathlist << "\r\n";
    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strCurPaths.count = " << strCurPaths.count() << "\r\n";

    QString strPathList[4];
    if (strCurPaths.count() >= 2) {
        strPathList[0] = QString("%1/%2").arg(strCurPaths.at(0)).arg(strCurPaths.at(1));
    }
    if (strCurPaths.count() >= 3) {
        strPathList[1] = QString("%1/%2/%3").arg(strCurPaths.at(0)).arg(strCurPaths.at(1)).arg(strCurPaths.at(2));
    }
    if (strCurPaths.count() >= 4) {
        strPathList[2] = QString("%1/%2/%3/%4").arg(strCurPaths.at(0)).arg(strCurPaths.at(1)).arg(strCurPaths.at(2)).arg(strCurPaths.at(3));
    }
    if (strCurPaths.count() >= 5) {
        strPathList[3] = QString("%1/%2/%3/%4/%5").arg(strCurPaths.at(0)).arg(strCurPaths.at(1)).arg(strCurPaths.at(2)).arg(strCurPaths.at(3)).arg(strCurPaths.at(4));
    }

    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strPathList[0] = " << strPathList[0] << "\r\n";
    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strPathList[1] = " << strPathList[1] << "\r\n";
    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strPathList[2] = " << strPathList[2] << "\r\n";
    qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : strPathList[3] = " << strPathList[3] << "\r\n";

    for (int j = 0; j < 4; j++) {
        if (! strPathList[j].isEmpty()) {
            for (int m = 0; m < list_treeInfos.count(); m++) {
                if (list_treeInfos.at(m).path_list == strPathList[j]) {
                    if (j == 3) {
                        qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : index = " << m << "; true\r\n";
                        emit m_p_qmlPort->signal_doDump_by_index(m, true);
                    } else if (strPathList[j+1].isEmpty()) {
                        qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : index = " << m << "; true\r\n";
                        emit m_p_qmlPort->signal_doDump_by_index(m, true);
                    } else {
                        qDebug() << "[Hp_TaskPkg][Dump_to_index_by_name] : index = " << m << "; false\r\n";
                        emit m_p_qmlPort->signal_doDump_by_index(m, false);
                    }
                }
            }
        }
    }

    return 0;
}

int Hp_TaskPkg::set_key_value_to_up(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_up(value);

    return 0;
}

int Hp_TaskPkg::set_key_value_to_down(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_down(value);

    return 0;
}

int Hp_TaskPkg::set_key_value_to_left(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_left(value);

    return 0;
}

int Hp_TaskPkg::set_key_value_to_right(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_right(value);

    return 0;
}

int Hp_TaskPkg::set_key_value_to_center(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_center(value);

    return 0;
}

int Hp_TaskPkg::set_key_value_to_return(int value)
{
    if (! m_hasInit) {
        qDebug() << "---> module has not init !!!";
        return -1;
    }
    m_p_qmlPort->set_keyValue_to_return(value);

    return 0;
}

void Hp_TaskPkg::test()
{
#if 0
    if( m_p_TaskSelectQWidget->isVisible() )
        m_p_TaskSelectQWidget->hide();
    else
        m_p_TaskSelectQWidget->show();
#endif
    TASK_TREE_INFO selTreeInfo = m_p_qmlPort->get_curSelInfo();
    mp_analyOP->Set_capturt_flag(selTreeInfo.task_info);
    QString dbName = m_p_qmlPort->get_taskpack_db_name();
    QStringList filePaths = dbName.split("/");

#if 1
    //台账 Version2.0 重命名修改
    QString strSetFile;
    for (int i = 0; i < filePaths.count()-1; i++) {
        strSetFile += filePaths.at(i) + "/";
    }
    strSetFile += "setting.conf";
    QString ident = m_setting.setting_para_read(strSetFile, SETTING_IDENT_CODE);
    if (ident.isEmpty()) {
        qDebug() << "ident is empty";
    /* 新版本 */
    } else {
        qDebug() << "ident : " << ident;
    }
#endif

    qDebug() << __LINE__ << " : " << m_p_qmlPort->get_taskpack_db_name();
    qDebug() << __LINE__ << " : " << selTreeInfo.task_info;
    qDebug() << __LINE__ << " : " << selTreeInfo.content;
    qDebug() << __LINE__ << " : " << strSetFile;
}


void Hp_TaskPkg::slot_interaction_sure_click()
{
    if (m_p_InteractionQWidget->isVisible()) {
        m_p_InteractionQWidget->hide();
    }
    m_p_TreeViewQWidget->setEnabled(true);
    m_p_qmlPort->reset_tree_flag();
}

void Hp_TaskPkg::slot_interaction_cancel_click()
{
    if (m_p_InteractionQWidget->isVisible()) {
        m_p_InteractionQWidget->hide();
    }
    m_p_TreeViewQWidget->setEnabled(true);
}

void Hp_TaskPkg::slot_interaction_show()
{
    m_p_InteractionQWidget->setSource(QUrl("qrc:///machine/MessageInteraction.qml"));
    QObject *InteractionObject = (QObject*) m_p_InteractionQWidget->rootObject();
    connect(InteractionObject, SIGNAL(sig_sure_click()), this, SLOT(slot_interaction_sure_click()));
    connect(InteractionObject, SIGNAL(sig_cancel_click()), this, SLOT(slot_interaction_cancel_click()));
    m_p_TreeViewQWidget->setEnabled(false);
    m_p_InteractionQWidget->setFocus();
    m_p_InteractionQWidget->show();
}

int Hp_TaskPkg::set_SDPath(QString strPath)
{
    m_strSDPath = strPath;
    m_p_qmlPort->set_sd_path(strPath);
    m_p_formula->set_sd_path(strPath);
    file_list->set_sd_path(strPath);
    mp_analyOP->set_sd_path(strPath);
    folder_list->set_sd_path(strPath);
    xml_list->set_save_path(strPath);

    return 0;
}



























