#include "hp_task_formula.h"

hp_task_formula::hp_task_formula(QObject *parent) : QObject(parent)
{
    m_strSDPath = QString("/run/media/mmcblk2p1");
    m_envTemp = 0;
    m_mapDevices.clear();
}

void hp_task_formula::set_sd_path(QString strPath)
{
    m_strSDPath = strPath;
}

/******************************************************************************
 * @ description  : 设置环境温度
 * @ param - temp : 环境温度
 * @ return       : null
 ******************************************************************************/
void hp_task_formula::set_envTemp(float temp)
{
    qDebug() << "#### [hp_task_formula] [set_envTemp] : running... m_envTemp = " << temp;
    m_envTemp = temp;
}


/******************************************************************************
 * @ description : 清空缓存，删除容器中保存的信息
 * @ param       : null
 * @ return      : null
 ******************************************************************************/
void hp_task_formula::clear_buffer()
{
    qDebug() << "#### [hp_task_formula] [clear_buffer] : running...";
    m_mapDevices.clear();
}


/******************************************************************************
 * @ description    : 向容器中添加设备信息
 * @ param - devcie : 设备名称、相位
 * @ param - params : 设备部位数据
 * @ return         : null
 ******************************************************************************/
void hp_task_formula::add_deviceInfo(ANA_DEVICE device, QVector<ANA_OUTLINE> params)
{
    qDebug() << "#### [hp_task_formula] [add_deviceInfo] : running... name = " << device.device_name << "; pos = " << device.device_pos;
    m_mapDevices.clear();
    m_mapDevices.insert(device, params);

    /* 获取同设备不同相的图片 */
    QDir dir;
    QStringList filters;
    QFileInfoList fileNames;
    filters.clear();
    fileNames.clear();
    filters.append("*.jpg");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setNameFilters(filters);
    dir.setSorting(QDir::Name | QDir::Reversed);
    dir.cd(QString("%1/DCIM").arg(m_strSDPath));
    fileNames = dir.entryInfoList();

    QString strFileName_A("");  //A相图片名
    QString strFileName_B("");  //B相图片名
    QString strFileName_C("");  //C相图片名
    for(int i = 0; i < fileNames.count(); i++) {
        QString fileName = fileNames.at(i).completeBaseName();
        /* 跳过当前相位,获取其他相位最新图片 */
        if((!fileName.contains(device.device_pos)) && (fileName.contains(replace_covert_char(device.device_name))) && (!fileName.contains(".vi"))) {
            if(fileName.contains("A相")) {
                if(!strFileName_A.isEmpty())
                    strFileName_A = compare_img_timestamp(strFileName_A, fileName);
                else
                    strFileName_A = fileName;
            } else if (fileName.contains("B相")) {
                if(!strFileName_B.isEmpty())
                    strFileName_B = compare_img_timestamp(strFileName_B, fileName);
                else
                    strFileName_B = fileName;
            } else if (fileName.contains("C相")) {
                if(!strFileName_C.isEmpty())
                    strFileName_C = compare_img_timestamp(strFileName_C, fileName);
                else
                    strFileName_C = fileName;
            }
        }
    }

    qDebug() << "#### [hp_task_formula] [add_deviceInfo] : strFileName_A = " << strFileName_A << "\r\n"
             << "                                          strFileName_B = " << strFileName_B << "\r\n"
             << "                                          strFileName_C = " << strFileName_C;

    ANA_DEVICE device_othr;
    if(! strFileName_A.isEmpty()) {
        device_othr.device_name = device.device_name;
        device_othr.device_pos = "A相";
        m_mapDevices.insert(device_othr, get_img_info(QString("%1/DCIM").arg(m_strSDPath), strFileName_A));
    }
    if (! strFileName_B.isEmpty()) {
        device_othr.device_name = device.device_name;
        device_othr.device_pos = "B相";
        m_mapDevices.insert(device_othr, get_img_info(QString("%1/DCIM").arg(m_strSDPath), strFileName_B));
    }
    if (! strFileName_C.isEmpty()) {
        device_othr.device_name = device.device_name;
        device_othr.device_pos = "C相";
        m_mapDevices.insert(device_othr, get_img_info(QString("%1/DCIM").arg(m_strSDPath), strFileName_C));
    }

    //test();
}


/******************************************************************************
 * @ description     : 字符替换 将源字符串中的特色字符进行替换
 * @ param - srcName : 源字符串
 * @ return          : 替换后的字符串
 ******************************************************************************/
QString hp_task_formula::replace_covert_char(QString srcName)
{
    srcName.replace( "~", "__1" );
    srcName.replace( "`", "__2" );
    srcName.replace( "!", "__3" );
    srcName.replace( "@", "__4" );
    srcName.replace( "#", "__5" );
    srcName.replace( "$", "__6" );
    srcName.replace( "%", "__7" );
    srcName.replace( "^", "__8" );
    srcName.replace( "&", "__9" );
    srcName.replace( "*", "__a" );
    srcName.replace( "(", "__b" );
    srcName.replace( ")", "__c" );
    srcName.replace( "+", "__d" );
    srcName.replace( "=", "__e" );
    srcName.replace( "{", "__f" );
    srcName.replace( "}", "__g" );
    srcName.replace( "[", "__h" );
    srcName.replace( "]", "__i" );
    srcName.replace( "|", "__j" );
    srcName.replace( "\\", "__k" );
    srcName.replace( ":", "__l" );
    srcName.replace( ";", "__m" );
    srcName.replace( "\"", "__n" );
    srcName.replace( "\'", "__o" );
    srcName.replace( "<", "__p" );
    srcName.replace( ">", "__q" );
    srcName.replace( ",", "__r" );
    srcName.replace( ".", "__s" );
    srcName.replace( "?", "__t" );
    srcName.replace( "/", "__u" );
    srcName.replace( " ", "__v" );
    srcName.replace( "__w", "\t" );

    return srcName;
}


/******************************************************************************
 * @ description      : 获取图像框选及高低温信息
 * @ param - fileName : 文件名
 * @ return           : 框选及高低温信息
 ******************************************************************************/
QVector<ANA_OUTLINE> hp_task_formula::get_img_info(QString path, QString fileName)
{
    qDebug() << "#### [hp_task_formula] [get_img_info] : running...";
    QVector<ANA_OUTLINE> tmpInfos;
    ti600s_picInfo_t picInfo;
    int tag_num;
    int id;
    int Qt_index;
    bool value;

    QString comFileName = path + "/" + fileName + ".jpg";
    QByteArray bFileName = comFileName.toUtf8();
    char* cFileName = bFileName.data();

    picInfo.jpeg_fp = fopen(cFileName, "r");
    if(picInfo.jpeg_fp == NULL) {
        qDebug() << "#### [hp_task_formula] [get_img_info] : picInfo.jpeg_fp == NULL !!!";
        return tmpInfos;
    }
    fseek(picInfo.jpeg_fp, 0, SEEK_END);
    fseek(picInfo.jpeg_fp, -sizeof(tagnum_t), SEEK_CUR);
    fread(&picInfo.tagnum, 1, sizeof(tagnum_t), picInfo.jpeg_fp);

    if(picInfo.tagnum.nTag == TAGNUM_TAG)
        tag_num = picInfo.tagnum.num;
    else
        return tmpInfos;

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
                    //param.deviceType = ptemper->draw_layer.Point[k].name;
                    strncpy(param.deviceType, ptemper->draw_layer.Point[k].name, sizeof(param.deviceType));
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
                    //param.deviceType = ptemper->draw_layer.Line[k].name;
                    strncpy(param.deviceType, ptemper->draw_layer.Line[k].name, sizeof(param.deviceType));
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
                    //param.deviceType = ptemper->draw_layer.Rect[k].name;
                    strncpy(param.deviceType, ptemper->draw_layer.Rect[k].name, sizeof(param.deviceType));
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

    return tmpInfos;
}


/******************************************************************************
 * @ description : 调试，打印容器内部数据
 * @ param       : null
 * @ return      : null
 ******************************************************************************/
void hp_task_formula::test()
{
    QMap<ANA_DEVICE, QVector<ANA_OUTLINE>>::iterator iter = m_mapDevices.begin();
    while (iter != m_mapDevices.end()) {
        qDebug() << "#### [hp_task_formula] [test] : device_name = " << iter.key().device_name << "\r\n"
                 << "     device_pos = " << iter.key().device_pos;
        for(int i = 0; i < iter->count(); i++) {
            ANA_OUTLINE tmp = iter->at(i);
            qDebug() << "#### [hp_task_formula] [test] : param_name = " << tmp.deviceType << "\r\n"
                     << "     x = " << tmp.origin_xcoord << "; y = " << tmp.origin_ycoord << "; x_p = " << tmp.dest_xcoord << "; y_p = " << tmp.dest_ycoord << "\r\n"
                     << "     maxTemp = " << tmp.maxtemp << "; minTemp = " << tmp.mintemp << "; averTemp = " << tmp.avgtemp;
        }
        iter++;
    }
}


/******************************************************************************
 * @ description       : 通过公式计算设备是否达到警告标准
 * @ param - curDevice : 当前需要扫描的设备信息
 * @ oaram - curPos    : 当前相位
 * @ paran - param     : 部位
 * @ param - rule      : 规则 公式：范围
 * @ param - formula   : 公式
 * @ return            : true->达到警告线; false->未达到警告线
 ******************************************************************************/
bool hp_task_formula::calculate_rule_formula(QString curDevice, QString curPos,QString param, QString rule, QString formula)
{
/*    qDebug() << "#### [hp_task_formula] [calculate_rule_formula] : curDevice : " << curDevice << "\r\n"
             << "                                                  curPos : " << curPos << "\r\n"
             << "                                                  param : " << param << "\r\n"
             << "                                                  formula : " << formula << "\r\n"
             << "                                                  rule : " << rule;*/

    QByteArray bParam = param.toUtf8();
    char* cParam = bParam.data();

    bool status_hot = true;         //热点温度状态
    bool status_inPhase = true;     //同相温差状态
    bool status_outPhase = true;    //异相温差状态
    bool status_delta = true;       //δ值状态
    QList<float> inPhase_temps;
    QList<ANA_DEVICE> device_list;
    device_list.append(ANA_DEVICE(curDevice, "A相"));
    device_list.append(ANA_DEVICE(curDevice, "B相"));
    device_list.append(ANA_DEVICE(curDevice, "C相"));

    /* 获取当前相位数据 */
    QMap<ANA_DEVICE, QVector<ANA_OUTLINE>>::iterator iter_last = m_mapDevices.end();
    QMap<ANA_DEVICE, QVector<ANA_OUTLINE>>::iterator iter_next = m_mapDevices.end();
    QMap<ANA_DEVICE, QVector<ANA_OUTLINE>>::iterator iter = m_mapDevices.find(ANA_DEVICE(curDevice, curPos));
    if(iter != m_mapDevices.end()) {
        if(curPos == "A相") {
            iter_last = m_mapDevices.find(device_list.at(1));
            iter_next = m_mapDevices.find(device_list.at(2));
        } else if (curPos == "B相") {
            iter_last = m_mapDevices.find(device_list.at(0));
            iter_next = m_mapDevices.find(device_list.at(2));
        } else if (curPos == "C相") {
            iter_last = m_mapDevices.find(device_list.at(1));
            iter_next = m_mapDevices.find(device_list.at(0));
        }
    }

    /* 遍历规则列表 */
    QStringList rule_list = rule.split(";");

    if(rule_list.count() < 2)
        return false;
    for(int index = 0; index < rule_list.count(); index++) {
        /* 区分规则 */
        QStringList formula_list = QString(rule_list.at(index)).split(":");
        if(formula_list.count() != 2)
            continue;
        int foemula_id = QString(formula_list.at(0)).toInt();   //公式编号
        float thrValue = QString(formula_list.at(1)).toFloat();     //阈值
        bool status_tmp = false;
        //qDebug() << "------------------------------> " << foemula_id << "; " << thrValue;
        switch (foemula_id) {
        case 1:   //热点温度计算
            /* 遍历当前相位所有部位 */
            for(int i = 0; i < iter->count(); i++) {
                if(strncmp(iter->at(i).deviceType, cParam, 2) == 0) {
                    if(cal_hot_temp(iter->at(i).maxtemp, thrValue))
                        status_tmp = true;
                }
            }
            status_hot = status_tmp;
            break;
        case 2:   //同相温差计算
            inPhase_temps.clear();
            /* 遍历所有部位，获取同相位所有同部位数据 */
            for(int i = 0; i < iter->count(); i++) {
                if(strncmp(iter->at(i).deviceType, cParam, 2) == 0)
                    inPhase_temps.append(iter->at(i).maxtemp);
            }
            if(inPhase_temps.count() >= 2) {
                for(int i = 0; i < inPhase_temps.count(); i++){
                    for(int j = i + 1; j < inPhase_temps.count(); j++) {
                        if(cal_inPhase_tempDiff(inPhase_temps.at(i), inPhase_temps.at(j), thrValue))
                            status_tmp = true;
                    }
                }
            }
            status_inPhase = status_tmp;
            break;
        case 3:   //相间温差计算
            /* 获取相间相位 */
            if(iter_last == m_mapDevices.end() && iter_next == m_mapDevices.end()) {
                return false;
            }
            /* 获取相同部位并计算 */
            for(int i = 0; i < iter->count(); i++) {
                if(strncmp(iter->at(i).deviceType, cParam, 2) == 0) {
                    if(iter_last != m_mapDevices.end()) {
                        for(int j = 0; j < iter_last->count(); j++) {
                            if((iter_last->at(j).origin_xcoord == iter->at(i).origin_xcoord) &&
                               (iter_last->at(j).origin_ycoord == iter->at(i).origin_ycoord) &&
                               (iter_last->at(j).dest_xcoord == iter->at(i).dest_xcoord) &&
                               (iter_last->at(j).dest_ycoord == iter->at(i).dest_ycoord)) {
                                if(cal_outPhase_tempDiff(iter->at(i).maxtemp, iter_last->at(j).maxtemp, thrValue))
                                status_tmp = true;
                            }
                        }
                    }
                    if(iter_next != m_mapDevices.end()) {
                        for(int j = 0; j < iter_next->count(); j++) {
                            if((iter_next->at(j).origin_xcoord == iter->at(i).origin_xcoord) &&
                               (iter_next->at(j).origin_ycoord == iter->at(i).origin_ycoord) &&
                               (iter_next->at(j).dest_xcoord == iter->at(i).dest_xcoord) &&
                               (iter_next->at(j).dest_ycoord == iter->at(i).dest_ycoord)) {
                                if(cal_outPhase_tempDiff(iter->at(i).maxtemp, iter_next->at(j).maxtemp, thrValue))
                                status_tmp = true;
                            }
                        }
                    }
                }
            }
            status_outPhase = status_tmp;
            break;
        case 4:   //δ值计算
            /* 获取相同部位并计算 */
            inPhase_temps.clear();
            for(int i = 0; i < iter->count(); i++) {
                /* 遍历所有部位，获取同相位所有同部位数据 */
                if(strncmp(iter->at(i).deviceType, cParam, 2) == 0)
                    inPhase_temps.append(iter->at(i).maxtemp);
            }
            if(inPhase_temps.count() >= 2) {
                for(int i = 0; i < inPhase_temps.count(); i++) {
                    if(i == (inPhase_temps.count() - 1)) {
                        if (cal_relative_tempDiff(inPhase_temps.at(i), inPhase_temps.at(0), thrValue))
                            status_tmp = true;
                    } else {
                        if(cal_relative_tempDiff(inPhase_temps.at(i), inPhase_temps.at(i+1), thrValue))
                            status_tmp = true;
                    }
                }
            }
            status_delta = status_tmp;
            break;
        default:
            break;
        }
    }

    if(status_hot && status_inPhase && status_outPhase && status_delta) {
        qDebug() << "#### [hp_task_formula] [calculate_rule_formula] : " << status_hot << status_inPhase << status_outPhase << status_delta << " ___________________ TRUE";
        return true;
    } else {
        qDebug() << "#### [hp_task_formula] [calculate_rule_formula] : " << status_hot << status_inPhase << status_outPhase << status_delta << " ___________________ FALSE";
        return false;
    }
}


/******************************************************************************
 * @ description      : 热点温度条件判断
 * @ param - temp     : 温度1
 * @ param - thrValue : 阈值
 * @ return           : true->达到阈值，false->未达到阈值
 ******************************************************************************/
bool hp_task_formula::cal_hot_temp(float temp, float thrValue)
{
    if (temp >= (float)thrValue) {
        //qDebug() << "#### [hp_task_formula] [cal_hot_temp] : formula : " << temp << " >= " << thrValue << "  true\r\n";
        return true;
    } else {
        //qDebug() << "#### [hp_task_formula] [cal_hot_temp] : formula : " << temp << " >= " << thrValue << "  false\r\n";
        return false;
    }
}


/******************************************************************************
 * @ description      : 同相温差条件判断
 * @ param - temp_1   : 温度1
 * @ param - temp_2   : 温度2
 * @ param - thrValue : 阈值
 * @ return           : true->达到阈值，false->未达到阈值
 ******************************************************************************/
bool hp_task_formula::cal_inPhase_tempDiff(float temp_1, float temp_2, float thrValue)
{
    if ((float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 >= (float)thrValue) {
        //qDebug() << "#### [hp_task_formula] [cal_inPhase_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 << ") >= " << thrValue << "  true  " << (float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 << "\r\n";
        return true;
    } else {
        //qDebug() << "#### [hp_task_formula] [cal_inPhase_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 << ") >= " << thrValue << "  false  " << (float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 << "\r\n";
        return false;
    }
}


/******************************************************************************
 * @ description      : 相间温差条件判断
 * @ param - temp_1   : 温度1
 * @ param - temp_2   : 温度2
 * @ param - thrValue : 阈值
 * @ return           : true->达到阈值，false->未达到阈值
 ******************************************************************************/
bool hp_task_formula::cal_outPhase_tempDiff(float temp_1, float temp_2, float thrValue)
{
    if ((float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 >= (float)thrValue) {
        //qDebug() << "#### [hp_task_formula] [cal_outPhase_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 <<") >= " << thrValue << "  true  " << (float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 << "\r\n";
        return true;
    } else {
        //qDebug() << "#### [hp_task_formula] [cal_outPhase_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 <<") >= " << thrValue << "  false  " << (float)abs(temp_1 * 100 - temp_2 * 100) / 100.00 << "\r\n";
        return false;
    }
}


/******************************************************************************
 * @ description      : δ值计算
 * @ param - temp_1   : 温度1
 * @ param - temp_2   : 温度2
 * @ param - thrValue : 阈值
 * @ return           : true->达到阈值，false->未达到阈值
 ******************************************************************************/
bool hp_task_formula::cal_relative_tempDiff(float temp_1, float temp_2, float thrValue)
{
    if(((float)abs(temp_1 * 100 - temp_2 * 100) / (float)abs(temp_1 * 100 - m_envTemp * 100)) * 100.00 >= thrValue) {
        //qDebug() << "#### [hp_task_formula] [cal_relative_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 << ") / abs(" << temp_1 <<" - " << m_envTemp << ")) >= " << thrValue << "  true  " << ((float)abs(temp_1 * 100 - temp_2 * 100) / (float)abs(temp_1 * 100 - m_envTemp * 100)) * 100.00 << "\r\n";
        return true;
    } else {
        //qDebug() << "#### [hp_task_formula] [cal_relative_tempDiff] : formula : abs(" << temp_1 << " - " << temp_2 << ") / abs(" << temp_1 <<" - " << m_envTemp << ")) >= " << thrValue << "  false  " << ((float)abs(temp_1 * 100 - temp_2 * 100) / (float)abs(temp_1 * 100 - m_envTemp * 100)) * 100.00 << "\r\n";
        return false;
    }
}


/******************************************************************************
 * @ description    : 获取较低的温度
 * @ param - temp_1 : 温度一
 * @ param - temp_2 : 温度二
 * @ return         : 较低的温度
 ******************************************************************************/
float hp_task_formula::compare_min(float temp_1, float temp_2)
{
    if(temp_1 > temp_2)
        return temp_2;
    else
        return temp_1;
}


/******************************************************************************
 * @ description    : 获取较高的温度
 * @ param - temp_1 : 温度一
 * @ param - temp_2 : 温度二
 * @ return         : 较高的温度
 ******************************************************************************/
float hp_task_formula::compare_max(float temp_1, float temp_2)
{
    if(temp_1 < temp_2)
        return temp_2;
    else
        return temp_1;
}


/******************************************************************************
 * @ description        : 比较文件名中的时间戳
 * @ param - fileName_1 : 文件名一
 * @ param - fileName_2 : 文件名二
 * @ return             : 事件戳较大的文件名
 ******************************************************************************/
QString hp_task_formula::compare_img_timestamp(QString fileName_1, QString fileName_2)
{
    QString timeStap_1 = fileName_1.left(14);
    QString timeStap_2 = fileName_2.left(14);
    qint64 stap_1 = timeStap_1.toLongLong();
    qint64 stap_2 = timeStap_2.toLongLong();
    return stap_1 > stap_2 ? fileName_1 : fileName_2;
}






















