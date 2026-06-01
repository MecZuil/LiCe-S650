#include "hp_pms.h"
#include "ui_hp_pms.h"

hp_pms::hp_pms(QWidget *parent) : QWidget(parent),
    ui(new Ui::hp_pms)
{
    ui->setupUi(this);
    isInAddItem = false;
    titleindex = 0;
    m_currCapRow = 0;
    m_lastTitleIndex = 2;
    m_nextCapRow = 0;
    ui->listWidget->setWordWrap(true);
    ui->listWidget->resize(181, 380);
    ui->listWidget->setGeometry(-20, 50, 181, 380);
    ui->listWidget->setItemDelegate(new RightCheckBoxDelegate(20));
    ui->listWidget->horizontalScrollBar()->hide();
    ui->listWidget->horizontalScrollBar()->setStyleSheet("height:0px;");

    ui->listWidget->verticalScrollBar()->hide();
    ui->listWidget->verticalScrollBar()->setStyleSheet("width:0px;");
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(m_hpListWidget_currentChanged(int)));
}
hp_pms::~hp_pms()
{
    delete ui;
}

void hp_pms::hp_setS3X0(bool isS3X0)
{
    qDebug() << ">> Hp_wait_warn::hp_setS3X0 <<";
    if(isS3X0)
    {
        QFont font11;
        font11.setPointSize(11);
        this->setGeometry(0,0,this->width() / 1.7,this->height() / 1.7);
        ui->label->setGeometry(ui->label->x() / 1.7,ui->label->y() / 1.7,ui->label->width() / 1.7,ui->label->height() / 1.7);
        ui->label_2->setGeometry(ui->label_2->x() / 1.7,ui->label_2->y() / 1.7,ui->label_2->width() / 1.7,ui->label_2->height() / 1.7);
        ui->listWidget->setGeometry(ui->listWidget->x() / 1.7,ui->listWidget->y() / 1.7,ui->listWidget->width() / 1.7,ui->listWidget->height() / 1.7);
        ui->toolButton->setGeometry(ui->toolButton->x() / 1.7,ui->toolButton->y() / 1.7,ui->toolButton->width() / 1.7,ui->toolButton->height() / 1.7);
        ui->label->setFont(font11);
        ui->label_2->setFont(font11);
        ui->listWidget->setFont(font11);
        ui->toolButton->setFont(font11);
    }
}

void hp_pms::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Hp_PMS::keyReleaseEvent qKeyEvent = " << event->type();
    switch(event->key())
    {
        case KEY_RETURN:
            signal_close_pms();
            break;
        case KEY_CAMERA_PICTURE:
            signal_take_picture();
            break;
        case 0x1000032:
            signal_set_focus();
            break;
        default:
            break;
    }
}
void hp_pms::hp_sortTestPoints(QList<TestPoint>& testPoints)
{
    std::sort(testPoints.begin(), testPoints.end(),
        [](const TestPoint& a, const TestPoint& b) {
            bool ok1, ok2;
            int snA = a.sn.toInt(&ok1);
            int snB = b.sn.toInt(&ok2);

            if (!ok1 || !ok2) {
                qWarning() << "Invalid sn value found during sorting";
                return false;
            }
            return snA < snB;
        });
}

void hp_pms::hp_sortClearances(QList<Clearance>& clearances)
{
    std::sort(clearances.begin(), clearances.end(),
        [](const Clearance& a, const Clearance& b) {
            bool ok1, ok2;
            int snA = a.sn.toInt(&ok1);
            int snB = b.sn.toInt(&ok2);

            if (!ok1 || !ok2) {
                qWarning() << "Invalid sn value found during sorting";
                return false;
            }
            return snA < snB;
        });
}

QStringList getKeysSortedByValue(QList<TestPointSnId> &testpointSnIdList) {
    // 自定义排序：先按测点SN，再按间隔SN
    std::sort(testpointSnIdList.begin(), testpointSnIdList.end(), [](const TestPointSnId& a, const TestPointSnId& b) {
        if (a.pointSn.toInt() != b.pointSn.toInt()) {
            return a.pointSn.toInt() < b.pointSn.toInt();
        }
        return a.clearanceSn.toInt() < b.clearanceSn.toInt();
    });
    QStringList sortedIds;
    for (const auto& tp : testpointSnIdList) {
        sortedIds.append(tp.id);
    }

    return sortedIds;
}

bool hp_pms::hp_parseXmlFile(const QString &filePath, MainTask &mainTask)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        //qDebug() << "Failed to open file:" << filePath;
        return false;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        file.close();
        //qDebug() << "Failed to parse XML content";
        return false;
    }
    file.close();

    QDomElement root = doc.documentElement();
    if (root.tagName() != "IDescription") {
        //qDebug() << "Invalid XML format: root element is not IDescription";
        return false;
    }

    // 解析主任务
    QDomElement mainTaskElement = root.firstChildElement("main_task");

//    if(!mainTask.name.isEmpty() && mainTask.name != mainTaskElement.attribute("name"))
//    {
        m_mainTaskMsg.clear();
        m_mainTaskIdList.clear();
        m_mainTaskSnList.clear();
        m_itemIndexPhotoMap.clear();
        m_itemIndexSelectMap.clear();
        m_titleindexList.clear();
        m_testpointIdItemMap.clear();
//    }
    m_testpointSnIdList.clear();
    mainTask.name = mainTaskElement.attribute("name");
    mainTask.id = mainTaskElement.attribute("id");
    // 解析子任务
    QDomElement subTaskElement = mainTaskElement.firstChildElement("sub_task");
    while (!subTaskElement.isNull()) {
        SubTask subTask;
        subTask.name = subTaskElement.attribute("name");
        subTask.id = subTaskElement.attribute("id");

        // 解析间隔
        int clearanceElementCount = 0;
        QDomElement clearanceElement = subTaskElement.firstChildElement("clearance");
        while (!clearanceElement.isNull()) {
            clearanceElementCount++;
            Clearance clearance;
            clearance.name = clearanceElement.attribute("name");
            clearance.id = clearanceElement.attribute("id");
            clearance.sn = clearanceElement.attribute("sn");
            // 解析测试点
            QDomElement testPointElement = clearanceElement.firstChildElement("test_point");
            while (!testPointElement.isNull()) {
                TestPoint testPoint;
                testPoint.name = testPointElement.attribute("name");
                testPoint.part = testPointElement.attribute("part");
                testPoint.id = testPointElement.attribute("id");
                testPoint.sn = testPointElement.attribute("sn");
                clearance.testPoints.append(testPoint);
                testPointElement = testPointElement.nextSiblingElement("test_point");
                m_testpointIdSnMap[testPoint.id] = testPoint.sn;

                TestPointSnId currpointSnId;
                currpointSnId.clearanceSn = clearance.sn;
                currpointSnId.id = testPoint.id;
                currpointSnId.pointSn = testPoint.sn;
                m_testpointSnIdList.append(currpointSnId);
            }

            hp_sortTestPoints(clearance.testPoints);
            subTask.clearances.append(clearance);
            clearanceElement = clearanceElement.nextSiblingElement("clearance");
        }
        hp_sortClearances(subTask.clearances);
        mainTask.subTasks.append(subTask);
        subTaskElement = subTaskElement.nextSiblingElement("sub_task");
    }
    m_testpointIdSortList = getKeysSortedByValue(m_testpointSnIdList);
//    //qDebug() << m_testpointIdSortList;
    return true;
}

bool hp_pms::hp_parseTask(QString xmlFilePath)
{
    int i = 0;
    int mapIndex = 0;
    int firstTestPointRow = 0;
    hp_parseXmlFile(xmlFilePath, m_mainTaskMsg);
    hp_setMainTaskNameText(m_mainTaskMsg.name);
    bool notSameTask = false;
    if(m_itemIndexPhotoMap.isEmpty())
    {
        notSameTask = true;
    }
    if(notSameTask)
    {
        m_itemIndexSelectMap.insert(i, false);
        m_itemIndexPhotoMap.insert(i, false);
        m_titleindexList.append(i);
        m_mainTaskIdList.append(m_mainTaskMsg.id);
        m_mainTaskSnList.append(m_mainTaskMsg.id);
    }
    //qDebug() << "m_itemIndexSelectMap" << m_itemIndexSelectMap;
//    m_testpointIdItemMap[m_mainTaskMsg.id] = i;
    i++;
    for(int sub = 0; sub < m_mainTaskMsg.subTasks.count(); sub++)
    {
        SubTask currSubTask = m_mainTaskMsg.subTasks.at(sub);
        if(notSameTask)
        {
            m_itemIndexSelectMap.insert(i, false);
            m_itemIndexPhotoMap.insert(i, false);
            m_titleindexList.append(i);
            m_mainTaskIdList.append(m_mainTaskMsg.subTasks.at(sub).id);
            m_mainTaskSnList.append(m_mainTaskMsg.subTasks.at(sub).id);
        }
//        m_testpointIdItemMap[m_mainTaskMsg.subTasks.at(sub).id] = i;
        i++;
        hp_setSubTaskNameText(currSubTask.name);
        for(int clearanceIndex = 0; clearanceIndex < currSubTask.clearances.count(); clearanceIndex++)
        {
            Clearance currClearance = currSubTask.clearances.at(clearanceIndex);
            if(notSameTask)
            {
                m_itemIndexSelectMap.insert(i, false);
                m_itemIndexPhotoMap.insert(i, false);
                m_titleindexList.append(i);
                m_mainTaskIdList.append(currClearance.id);
                m_mainTaskSnList.append(currClearance.sn);
            }
//            m_testpointIdItemMap[currClearance.id] = i;
            i++;
            hp_setClearNameText(currClearance.name);
            if(currClearance.testPoints.count() == 0)
                continue;
            QStringList testPointNameList;
            for(int testPointINdex = 0; testPointINdex < currClearance.testPoints.count(); testPointINdex++)
            {
                if(firstTestPointRow == 0)
                    firstTestPointRow = i;
                TestPoint currTestPoint = currClearance.testPoints.at(testPointINdex);
                if(notSameTask)
                {
                    m_itemIndexSelectMap.insert(i, false);
                    m_itemIndexPhotoMap.insert(i, false);
                    m_mainTaskIdList.append(currTestPoint.id);
                    m_mainTaskSnList.append(currTestPoint.sn);
                }
                m_testpointIdItemMap[currTestPoint.id] = i;
                mapIndex++;
                i++;
                testPointNameList.append(currTestPoint.name);
            }
            hp_setText(testPointNameList);
        }
    }
    ui->listWidget->setCurrentRow(firstTestPointRow);//设置当前行
    nowindex = firstTestPointRow;
    return notSameTask;
}

void hp_pms::hp_clearListWidget()
{
    m_mainTaskMsg.clear();
    ui->listWidget->clear();
}


void hp_pms::hp_setMainTaskNameText(QString str)
{
    isInAddItem = true;
    ui->listWidget->addItem("    Ⅰ " + str);
    QList<QListWidgetItem*> listItem = ui->listWidget->findItems("    Ⅰ " + str,Qt::MatchExactly);
    if(listItem.count() > 0)
    {
        listItem.at(0)->setFlags(listItem.at(0)->flags() & ~Qt::ItemIsSelectable);
        listItem.at(0)->setBackgroundColor(QColor(22,40,88));
    }
    isInAddItem = false;
}

void hp_pms::hp_setSubTaskNameText(QString str)
{
    isInAddItem = true;
    ui->listWidget->addItem("     Ⅱ " + str);
    QList<QListWidgetItem*> listItem = ui->listWidget->findItems("     Ⅱ " + str,Qt::MatchExactly);
    if(listItem.count() > 0)
    {
        listItem.at(0)->setFlags(listItem.at(0)->flags() & ~Qt::ItemIsSelectable);
        listItem.at(0)->setBackgroundColor(QColor(121,139,163,63));
    }
    isInAddItem = false;
}

void hp_pms::hp_setClearNameText(QString str)
{
    isInAddItem = true;
    ui->listWidget->addItem("    Ⅲ " + str);
    QList<QListWidgetItem*> listItem = ui->listWidget->findItems("    Ⅲ " + str,Qt::MatchExactly);
    if(listItem.count() > 0)
    {
        listItem.at(0)->setFlags(listItem.at(0)->flags() & ~Qt::ItemIsSelectable);
        listItem.at(0)->setBackgroundColor(QColor(121,139,163,63));
        listItem.at(0)->setData(RightCheckBoxDelegate::ShowCheckBoxRole, true); // 关键控制参数
        listItem.at(0)->setData(Qt::CheckStateRole, Qt::Unchecked); // 初始状态
    }
    isInAddItem = false;
}

void hp_pms::hp_setText(QStringList list)//这个函数是在标题添加完毕之后，在执行的，为了初始化isInAddItem时，能得到标题数量
{
    if(list.count() < 0)
    {
        return;
    }
    isInAddItem = true;
    for(int i = 0;i < list.count();i++)
    {
        QListWidgetItem *item = new QListWidgetItem("       Ⅳ " + list.at(i));
        item->setData(RightCheckBoxDelegate::ShowCheckBoxRole, true); // 关键控制参数
        //qDebug() << ui->listWidget->count() << m_itemIndexSelectMap[ui->listWidget->count()];
        if(!m_itemIndexSelectMap[ui->listWidget->count()])
            item->setData(Qt::CheckStateRole, Qt::Unchecked); // 初始状态
        else
            item->setData(Qt::CheckStateRole, Qt::Checked); // 初始状态
        ui->listWidget->addItem(item);

    }
    isInAddItem = false;
}

void hp_pms::hp_createModifiedXml(const QString& outputPath) {//创建数据文件xml
    //qDebug() << __func__ << __LINE__;
    QFile file(outputPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "cannot create file:" << outputPath;
        return;
    }

    //qDebug() << __func__ << __LINE__;
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    // 根节点
    writer.writeStartElement("IDescription");

    // 版本号
    writer.writeTextElement("version", "1.0.0");

    // main_task节点
    writer.writeStartElement("main_task");
    writer.writeAttribute("id", m_mainTaskMsg.id);
    writer.writeAttribute("type", "1");
    writer.writeAttribute("name", m_mainTaskMsg.name);

    // 新增字段
    writer.writeTextElement("file_count", "0");
    QString fileType = "1";
    writer.writeTextElement("file_type", fileType);

    // sub_task节点
    writer.writeStartElement("sub_task");
    writer.writeAttribute("id", m_mainTaskMsg.subTasks.at(0).id);
    writer.writeAttribute("name", m_mainTaskMsg.subTasks.at(0).name);

    //qDebug() << __func__ << __LINE__;
    // clearance节点
    for (int i = 0; i < m_mainTaskMsg.subTasks.at(0).clearances.count(); ++i) {
        writer.writeStartElement("clearance");
        writer.writeAttribute("id", m_mainTaskMsg.subTasks.at(0).clearances.at(i).id);
        writer.writeAttribute("name", m_mainTaskMsg.subTasks.at(0).clearances.at(i).name);

        for (int j = 0; j < m_mainTaskMsg.subTasks.at(0).clearances.at(i).testPoints.count(); ++j) {
            writer.writeStartElement("test_point");
            writer.writeAttribute("id", m_mainTaskMsg.subTasks.at(0).clearances.at(i).testPoints.at(j).id);
            writer.writeAttribute("name", m_mainTaskMsg.subTasks.at(0).clearances.at(i).testPoints.at(j).name);
            writer.writeAttribute("part", m_mainTaskMsg.subTasks.at(0).clearances.at(i).testPoints.at(j).part);
            writer.writeAttribute("filename", QString::number(j));
            writer.writeAttribute("bgfilename", "");
            writer.writeEndElement(); // test_point
        }
        writer.writeEndElement(); // clearance
    }
    // 关闭所有打开的标签
    writer.writeEndElement(); // sub_task
    writer.writeEndElement(); // main_task
    writer.writeEndElement(); // IDescription

    writer.writeEndDocument();
    file.close();
    //qDebug() << __func__ << __LINE__;
}

void hp_pms::m_hpListWidget_currentChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }

    if(isInAddItem)
    {
        return;
    }
//    //qDebug() << __func__ << "m_lastTitleIndex" << m_lastTitleIndex << __LINE__;
    if(m_titleindexList.contains(currentRow))//头标题不被选中
    {
        if(ui->listWidget->count() > currentRow)
        {
            m_lastTitleIndex = currentRow;
//            //qDebug() << __func__ << "m_lastTitleIndex" << m_lastTitleIndex << __LINE__;
            ui->listWidget->setCurrentRow(currentRow + 1);
            return;
        }
        for(int i = 0; i < m_titleindexList.count() - 1; i++)
        {
            if(currentRow >= m_titleindexList.at(i) && currentRow < m_titleindexList.at(i + 1))
            {
                m_lastTitleIndex = currentRow;
//                //qDebug() << __func__ << "m_lastTitleIndex" << m_lastTitleIndex << __LINE__;
            }
            else
            {
                m_lastTitleIndex = 2;
//                //qDebug() << __func__ << "m_lastTitleIndex" << m_lastTitleIndex << __LINE__;
            }
        }
    }else{
        for(int rowTitleIndex = currentRow - 1; rowTitleIndex >= 0; rowTitleIndex--)
        {
            if(m_titleindexList.contains(rowTitleIndex))
            {
                m_lastTitleIndex = rowTitleIndex;
                break;
            }
        }
        signal_selectChanged(currentRow);
        nowindex = currentRow;
    }
}

void hp_pms::hp_setListWidgetIndex(int index)
{
    //qDebug() <<__func__ << index << ui->listWidget->count();
    if(ui->listWidget->currentItem() && ui->listWidget->currentItem()->text().contains("Ⅳ"));
    {
        ui->listWidget->currentItem()->setCheckState(Qt::Checked);
    }
    if(ui->listWidget->count() > index)
    {
        ui->listWidget->setCurrentRow(index);
        return;
    }
    return;
}

void hp_pms::hp_getCurrClearancePointName(QString &clearance, QString &point)
{
    QString currClearanceName = ui->listWidget->item(m_lastTitleIndex)->text();
    QString currPointName = ui->listWidget->currentItem()->text();
    int currClearanceTextLength = currClearanceName.count();
    int currPointNameTextLength = currPointName.count();

    clearance = currClearanceName.right(currClearanceTextLength - 6);
    point = currPointName.right(currPointNameTextLength - 9);
}

void hp_pms::hp_getCurrClearancePointId(QString &clearanceId, QString &pointId)
{
    //qDebug() << __func__ << ui->listWidget->currentRow() << m_lastTitleIndex;
    pointId = m_mainTaskIdList.at(ui->listWidget->currentRow());
    clearanceId = m_mainTaskIdList.at(m_lastTitleIndex);
}

void hp_pms::hp_getCurrClearanceSn(QString &clearanceSn, QString &pointSn)
{
    qDebug() << __func__ << __LINE__ << pointSn;
    pointSn = m_mainTaskSnList.at(ui->listWidget->currentRow());
    qDebug() << __func__ << __LINE__ << "m_lastTitleIndex" << m_lastTitleIndex;
    clearanceSn = m_mainTaskSnList.at(m_lastTitleIndex);
    qDebug() << __func__ << __LINE__ << "clearanceSn" << clearanceSn;
    m_currTestPointId = m_mainTaskIdList.at(ui->listWidget->currentRow());
    qDebug() << __func__ << __LINE__ << "m_currTestPointId" << m_currTestPointId;
    return;
}

QString hp_pms::hp_getCurrTestpointId()
{
    m_itemIndexPhotoMap[ui->listWidget->currentRow()] = true;
    return m_currTestPointId;
}

QMap<int, bool> hp_pms::hp_getCurrSelectMap()
{
    return m_itemIndexSelectMap;
}

MainTask hp_pms::hp_getMainTask()
{
    //qDebug() << __func__ << __LINE__;
    return m_mainTaskMsg;
}

void hp_pms::on_toolButton_clicked()
{
    signal_close_pms();
}

int  hp_pms::hp_getTitleIndex()
{
    return titleindex;
}

int  hp_pms::hp_getNowIndex()
{
    //qDebug() << "m_testpointIdItemMap" << m_testpointIdItemMap;
    //qDebug() << "m_testpointIdSortList" << m_testpointIdSortList;
    //qDebug() << "nowindex" << nowindex << ui->listWidget->currentRow();
    QString currTestPointID = m_testpointIdItemMap.key(nowindex);
    //qDebug() << "currTestPointID" << currTestPointID;
    //qDebug() << "m_testpointIdSortList.indexOf(currTestPointID)" << m_testpointIdSortList.indexOf(currTestPointID);

    int nextIndex = 0;
    if(m_testpointIdSortList.indexOf(currTestPointID) + 1 <= m_testpointIdSortList.count() - 1)
        nextIndex = m_testpointIdSortList.indexOf(currTestPointID) + 1;
    else
        nextIndex = 0;
    //qDebug() << "nextIndex" << nextIndex;
    currTestPointID = m_testpointIdSortList.at(nextIndex);
    //qDebug() << "currTestPointSn" << currTestPointID;
    nextIndex = m_testpointIdItemMap.value(currTestPointID);
    //qDebug() << "nextIndex" << nextIndex;
    nowindex = nextIndex;
    return nowindex;
}

void hp_pms::on_pms_upload_clicked()
{
    signal_upload_pms_dat();
    update();
}

void hp_pms::on_listWidget_itemChanged(QListWidgetItem *item)
{
    const int currRow = ui->listWidget->row(item);
    const bool isChecked = item->checkState() == Qt::Checked;
    const QString text = item->text();

    if (m_itemIndexSelectMap.value(currRow) == isChecked)
        return;

    if(item->checkState() && !m_itemIndexPhotoMap[currRow] && !text.contains("Ⅲ"))
    {
        item->setCheckState(Qt::Unchecked);
        return;
    }


    // 处理Ⅲ类项目
    if (text.contains("Ⅲ"))
    {
        int endRow = ui->listWidget->count();
        for (int i = currRow + 1; i < ui->listWidget->count(); ++i) {
            if (ui->listWidget->item(i)->text().contains("Ⅲ")) {
                endRow = i;
                break;
            }
        }

        for (int i = currRow + 1; i < endRow; ++i) {
            ui->listWidget->item(i)->setCheckState(isChecked ? Qt::Checked : Qt::Unchecked);
            if(m_itemIndexSelectMap[i])
                m_itemIndexSelectMap[i] = isChecked;
        }
    }
    // 处理Ⅳ类项目
    else if (text.contains("Ⅳ"))
    {
        m_itemIndexSelectMap[currRow] = isChecked;
    }

    for(int rowTitleIndex = currRow; rowTitleIndex >= 0; rowTitleIndex--)
    {
        if(m_titleindexList.contains(rowTitleIndex))
        {
            m_lastTitleIndex = rowTitleIndex;
            break;
        }
    }
    //qDebug() << __func__ << "m_lastTitleIndex" << m_lastTitleIndex << __LINE__;
}

void hp_pms::on_pms_upload_2_clicked()
{
    signal_relink_last_ble_server();
}
