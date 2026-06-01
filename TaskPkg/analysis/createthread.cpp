#include "createthread.h"

createThread::createThread(QObject *parent) :
    QThread(parent)
{
    m_strPath = QString("/run/media/mmcblk2p1");
}

createThread::~createThread()
{

}

void createThread::run()
{
}

void createThread::set_sd_path(QString strPath)
{
    m_strPath = strPath;
}

/*********************************************************************************
 * @ description      : 删除数据库文件
 * @ param - fileName : 文件名
 * @ return           : null
 *********************************************************************************/
void createThread::Remove_sqlFile()
{
    if(this->isRunning()) {
        this->quit();
        m_ana_op.Close_AnalySql();
    }

    m_ana_op.Delete_AnalySql(ANALYSIS_FILE_NAME);
}


/********************************************************************************
 * @ description       : 初始化设备信息
 * @ param - fileName  : 数据库
 * @ return            : null
 ********************************************************************************/
void createThread::Init_MapDevices(QString fileName)
{
    QFile file(fileName);
    if(! file.exists())
        return;

    AnalydataOP anaOp;
    anaOp.Open_AnalySql(fileName);
    /* 读取 间隔单元-设备规格-设备名称--相别-部位角度-设备系统编号 */
    QList<QList<QPair<QString, QString>>> base_list_1;
    QList<QList<QPair<QString, QString>>> base_list_2;
    QList<QPair<QString, QString>> list_1;
    QList<QPair<QString, QString>> list_2;
    QPair<QString, QString> part_1[2];
    QPair<QString, QString> part_2[4];

    part_1[0].first = "id";
    part_1[1].first = "name";
    list_1.append(part_1[0]);
    list_1.append(part_1[1]);
    base_list_1.append(list_1);
    anaOp.Query_info("regions", &base_list_1);

    part_2[0].first = "id";
    part_2[1].first = "region_id";
    part_2[2].first = "content";
    part_2[3].first = "serial_no";
    for(int i = 0; i < 4; i++)
        list_2.append(part_2[i]);
    base_list_2.append(list_2);
    anaOp.Query_info("hp_common_shoot_sequences", &base_list_2);

    m_mapDevices.clear();
    for(int i = 0; i < base_list_2.count(); i++) {
        QString strDevName;
        for(int j = 0; j < base_list_1.count(); j++) {
            if(base_list_2.at(i).at(1).second == base_list_1.at(j).at(0).second) {
                strDevName.append(base_list_1.at(j).at(1).second + "-");
                break;
            }
        }
        QStringList tempList = base_list_2.at(i).at(2).second.split(";-");
        if(tempList.count() >= 7) {
            for(int m = 0; m < tempList.count(); m++) {
                if(m == 0 || m == 2 || m == 3 || m == 4 || m == 6) {
                    QStringList tempCell = QString(tempList.at(m)).split(":");
                    if(tempCell.count() == 2)
                        strDevName.append(tempCell.at(1));
                    strDevName.append("-");
                }
            }
        }
        strDevName.append(base_list_2.at(i).at(3).second);
        m_mapDevices.insert(strDevName, base_list_2.at(i).at(0).second.toInt());
    }
    anaOp.Close_AnalySql();
}

/*********************************************************************************
 * @ description      : 创建初始数据库
 * @ param - fileName : 源数据库文件名
 * @ return           : null
 *********************************************************************************/
void createThread::create_analysis_db()
{

}

/*********************************************************************************
 * @ description : 打开数据库连接,默认打开分析统计数据库
 * @ param       : null
 * @ return      : null
 *********************************************************************************/
void createThread::Open_analysis_db()
{
    m_ana_op.Open_AnalySql(ANALYSIS_FILE_NAME);
}

/*********************************************************************************
 * @ description : 关闭数据库连接,默认打开分析统计数据库
 * @ param       : null
 * @ return      : null
 *********************************************************************************/
void createThread::Close_analysis_db()
{
    m_ana_op.Close_AnalySql();
}

/*********************************************************************************
 * @ description       : 插入表,默认操作分析统计数据库
 * @ param - tableName : 需要插入的表名
 * @ return            : null
 *********************************************************************************/
void createThread::Insert_table_analysis_db(QString tableName)
{
    QList<QPair<QString, QString>> listType;
    QPair<QString, QString> partType[4];
    partType[0].first = "date";         partType[0].second = "INTEGER PRIMARY KEY";
    partType[1].first = "match_id";     partType[1].second = "INTEGER";
    partType[2].first = "type";         partType[2].second = "TEXT";
    partType[3].first = "temp";         partType[3].second = "TEXT";
    for(int i = 0; i < 4; i++)
        listType.append(partType[i]);
    m_ana_op.Add_table(tableName, listType);

    QList<QPair<QString, QString>> listFlag;
    QPair<QString, QString> partFlag[2];
    partFlag[0].first = "id";           partFlag[0].second = "INTEGER PRIMARY KEY";
    partFlag[1].first = "flag";         partFlag[1].second = "INTEGER";
    for(int i = 0; i < 2; i++)
        listFlag.append(partFlag[i]);
    m_ana_op.Add_table(QString("%1_flag").arg(tableName), listFlag);
}

void createThread::Init_MapFlags()
{
    if(m_mapDevices.empty())
        return;

    QMap<QString, int>::iterator iter = m_mapDevices.begin();
    while(iter != m_mapDevices.end()) {
        QList<QString> listInfo;
        listInfo.append(QString("%1").arg(iter.value()));
        listInfo.append("0");
        m_ana_op.Insert_info_line(QString("%1_flag").arg(m_current_dbName), listInfo);
        iter++;
    }

    /* 创建初始数据库 */
    QList<QPair<QString, QString>> listType;
    QPair<QString, QString> partType[2];
    partType[0].first = "id";           partType[0].second = "INTEGER PRIMARY KEY";
    partType[1].first = "croods";       partType[1].second = "TEXT";
    for(int i = 0; i < 2; i++)
        listType.append(partType[i]);
    m_ana_op.Add_table(QString("%1_croods").arg(m_current_dbName), listType);
}

/*********************************************************************************
 * @ description       : 删除表,默认操作分析统计数据库
 * @ param - tableName : 需要删除的表名
 * @ return            : null
 *********************************************************************************/
void createThread::Delete_table_analysis_db(QString tableName)
{
    m_ana_op.Delete_table(tableName);
    m_ana_op.Delete_table(QString("%1_flag").arg(tableName));
    m_ana_op.Delete_table(QString("%1_croods").arg(tableName));
}

/*********************************************************************************
 * @ description       : 插入数据,默认操作分析统计数据库
 * @ param - tableName : 需要操作的表
 * @ param - listData  : 需要插入的数据
 * @ return            : null
 *********************************************************************************/
void createThread::Insert_line_analysis_db(QString tableName, QList<QString> listData)
{
    m_ana_op.Insert_info_line(tableName, listData);

#if 1
    Delete_extra_data_db(tableName, QString(listData.at(1)).toInt());
#endif
}

/*********************************************************************************
 * @ description       : 删除数据,默认操作分析统计数据库
 * @ param - tableName : 需要操作的表
 * @ param - listData  : 需要删除的数据
 * @ return            : null
 *********************************************************************************/
void createThread::Delete_line_analysis_db(QString tabName, QPair<QString, QString> where)
{
    m_ana_op.Delete_info_line(tabName, where);
}

/*********************************************************************************
 * @ description       : 判断数据是否存在,默认操作分析统计数据库
 * @ param - tableName : 需要操作的表
 * @ param - listData  : 需要判断的数据
 * @ return            : null
 *********************************************************************************/
bool createThread::Exist_line_analysis_db(QString tableName, QPair<QString, QString> where)
{
    return m_ana_op.Exist_info_line(tableName, where);
}


QString createThread::replace_covert_char(QString strName)
{
#if 0
    strName.replace( "-", "__0" );
    strName.replace( "~", "__1" );
    strName.replace( "`", "__2" );
    strName.replace( "!", "__3" );
    strName.replace( "@", "__4" );
    strName.replace( "#", "__5" );
    strName.replace( "$", "__6" );
    strName.replace( "%", "__7" );
    strName.replace( "^", "__8" );
    strName.replace( "&", "__9" );
    strName.replace( "*", "__a" );
    strName.replace( "(", "__b" );
    strName.replace( ")", "__c" );
    strName.replace( "+", "__d" );
    strName.replace( "=", "__e" );
    strName.replace( "{", "__f" );
    strName.replace( "}", "__g" );
    strName.replace( "[", "__h" );
    strName.replace( "]", "__i" );
    strName.replace( "|", "__j" );
    strName.replace( "\\", "__k" );
    strName.replace( ":", "__l" );
    strName.replace( ";", "__m" );
    strName.replace( "\"", "__n" );
    strName.replace( "\'", "__o" );
    strName.replace( "<", "__p" );
    strName.replace( ">", "__q" );
    strName.replace( ",", "__r" );
    strName.replace( ".", "__s" );
    strName.replace( "?", "__t" );
    strName.replace( "/", "__u" );
    strName.replace( " ", "__v" );
    strName.replace( "__w", "\t" );
#else
    strName.replace( "__0", "-" );
    strName.replace( "__1", "~" );
    strName.replace( "__2", "`" );
    strName.replace( "__3", "!" );
    strName.replace( "__4", "@" );
    strName.replace( "__5", "#" );
    strName.replace( "__6", "$" );
    strName.replace( "__7", "%" );
    strName.replace( "__8", "^" );
    strName.replace( "__9", "&" );
    strName.replace( "__a", "*" );
    strName.replace( "__b", "(" );
    strName.replace( "__c", ")" );
    strName.replace( "__d", "+" );
    strName.replace( "__e", "=" );
    strName.replace( "__f", "{" );
    strName.replace( "__g", "}" );
    strName.replace( "__h", "[" );
    strName.replace( "__i", "]" );
    strName.replace( "__j", "|" );
    strName.replace( "__k", "\\" );
    strName.replace( "__l", ":" );
    strName.replace( "__m", ";" );
    strName.replace( "__n", "\"" );
    strName.replace( "__o", "\'" );
    strName.replace( "__p", "<" );
    strName.replace( "__q", ">" );
    strName.replace( "__r", "," );
    strName.replace( "__s", "." );
    strName.replace( "__t", "?" );
    strName.replace( "__u", "/" );
    strName.replace( "__v", " " );
    strName.replace( "\t", "__w" );
#endif
    return strName;
}


/*********************************************************************************
 * @ description      : 删除额外的历史数据
 * @ param - pkgName  : 作业包名称
 * @ param - deviceId : 设备id
 * @ return           : null
 *********************************************************************************/
void createThread::Delete_extra_data_db(QString pkgName, int deviceId)
{
    /* 查表hp_image_match */
    QList<QList<QPair<QString, QString>>> listQuery;
    QList<QPair<QString, QString>> listQueryPart;
    QPair<QString, QString> pair;
    pair.first = "date";
    listQueryPart.append(pair);
    listQuery.append(listQueryPart);
    QList<QString> listWhere;
    listWhere.append(QString("match_id = %1").arg(deviceId));
    m_ana_op.Query_info_by_rules(pkgName, &listQuery, listWhere);

    if(listQuery.count() <= HP_ANALYSIS_SAVE_COUNT)
        return;

    QPair<QString, QString> pairWhere;
    pairWhere.first = "date";    pairWhere.second = listQuery.at(0).at(0).second;
    m_ana_op.Delete_info_line(pkgName, pairWhere);
}


/*********************************************************************************
 * @ description        : 获取最新的一百条数据,保存至成员变量
 * @ param - pkgName    : 作业包名称
 * @ param - deviceInfo : 设备信息
 * @ return             : null
 *********************************************************************************/
void createThread::Get_historyData(QString pkgName, QString deviceInfo)
{
    qDebug() << "#### [createThread] [Get_historyData] : RUN . . . " << deviceInfo.replace("__0", "-");
    map_analysisInfo.clear();
    QList<QList<QPair<QString, QString>>> values;
    QList<QPair<QString, QString>> value;
    QPair<QString, QString> value_part[2];
    value_part[0].first = "date";
    value_part[1].first = "temp";
    for(int i = 0; i < 2; i++)
        value.append(value_part[i]);
    values.append(value);
    QList<QString> where;
    QMap<QString, int>::iterator iter = m_mapDevices.find(deviceInfo);
    if(iter == m_mapDevices.end()) {
        qDebug() << "#### [createThread] [Get_historyData] : WARNING . . . " << deviceInfo;
        return;
    }
    where.append(QString("match_id = %1").arg(iter.value()));
    m_ana_op.Query_info_by_rules(pkgName, &values, where);

    QList<QList<QPair<QString, QString>>> values_croods;
    QList<QPair<QString, QString>> value_croods;
    QPair<QString, QString> value_croods_part;
    value_croods_part.first = "croods";
    value_croods.append(value_croods_part);
    values_croods.append(value_croods);
    QList<QString> where_croods;
    where_croods.append(QString("id = %1").arg(iter.value()));
    m_ana_op.Query_info_by_rules(QString("%1_croods").arg(pkgName), &values_croods, where_croods);

    QDir dir(m_strPath);
    if(! dir.exists())
        return;
    /* 遍历 */
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot | QDir::Dirs);
    int count = HP_ANALYSIS_SHOW_COUNT;
    for(int i = values.count() - 1; i >= 0; i--) {  //从最新的图片开始遍历
        if(count <= 0)
             return;
        for (int d = 0; d < fileInfoList.count(); d++) {
            if (fileInfoList.at(d).isDir()) {
                QStringList filters;
                QStringList deviceInfoPaths = deviceInfo.split("-");
                if(deviceInfoPaths.count() < 2)
                    continue;
                filters << QString("*%1.irp.jpg").arg(deviceInfoPaths.at(deviceInfoPaths.count() - 1)) <<
                           QString("*%1.vi.jpg").arg(deviceInfoPaths.at(deviceInfoPaths.count() - 1));
                QDir dirpart(fileInfoList.at(d).absoluteFilePath());
                if (!dirpart.exists())
                    continue;
                QStringList listFilters = dirpart.entryList(filters, QDir::Files | QDir::NoSymLinks);

                QString imgBaseName = QString("%1-%2").arg(values.at(i).at(0).second).arg(deviceInfo);
                for(int j = 0; j < listFilters.count(); j++) {
                    if(replace_covert_char(QString(listFilters.at(j))).contains(imgBaseName)) {
                        ANALYSIS_INFO analysis_info;
                        analysis_info.date = values.at(i).at(0).second;
                        analysis_info.deviceInfo = deviceInfo;

                        QString strCoords;
                        if(values_croods.count() > 0) {
                            if(values_croods.at(0).count() > 0)
                                strCoords = values_croods.at(0).at(0).second;
                        }
                        QString strTemp = values.at(i).at(1).second;
                        QStringList listCoords = strCoords.split(";-");
                        QStringList listTemp = strTemp.split(";-");
                        if(listCoords.count() != listTemp.count())
                            continue;
                        analysis_info.count = listCoords.count() - 1;

                        for(int m = 0; m < analysis_info.count; m++) {
                            QString coordsPart = listCoords.at(m);
                            QString tempPart = listTemp.at(m);

                            QStringList listCoordsPart = coordsPart.split(":");
                            if(listCoordsPart.count() == 4) {
                                analysis_info.partInfo[m].id = QString(listCoordsPart.at(0)).toInt();
                                analysis_info.partInfo[m].name = listCoordsPart.at(1);
                                analysis_info.partInfo[m].type = listCoordsPart.at(2);

                                QStringList listPartCoord = QString(listCoordsPart.at(3)).split(";");
                                QStringList originList = QString(listPartCoord.at(0)).split(",");
                                analysis_info.partInfo[m].x = QString(originList.at(0)).toInt();
                                analysis_info.partInfo[m].y = QString(originList.at(1)).toInt();
                                if ((QString::compare(listCoordsPart.at(1), "L", Qt::CaseSensitive) == 0) ||
                                   (QString::compare(listCoordsPart.at(1), "R", Qt::CaseSensitive) == 0)) {
                                    QStringList destList = QString(listPartCoord.at(1)).split(",");
                                    analysis_info.partInfo[m].x_p = QString(destList.at(0)).toInt();
                                    analysis_info.partInfo[m].y_p = QString(destList.at(1)).toInt();
                                }
                            }

                            QStringList listTempPart = tempPart.split(",");
                            if(listTempPart.count() == 3) {
                                analysis_info.partInfo[m].maxTemp = QString(listTempPart.at(0)).toFloat();
                                analysis_info.partInfo[m].minTemp = QString(listTempPart.at(1)).toFloat();
                                analysis_info.partInfo[m].aveTemp = QString(listTempPart.at(2)).toFloat();
                            }
                        }

                        map_analysisInfo.insert(count--, analysis_info);
                        continue;
                    }
                }
            }

#if 0
            QMap<int, ANALYSIS_INFO>::iterator iterTmp = map_analysisInfo.begin();
            int a = 0;
            while (iterTmp != map_analysisInfo.end()) {
                qDebug() << "\r\n";
                qDebug() << a << " = " << iterTmp.value().date;
                qDebug() << a << " = " << iterTmp.value().deviceInfo;
                qDebug() << a << " = " << iterTmp.value().count;
                for(int i = 0; i < iterTmp.value().count; i++) {
                    qDebug() << a << " = " << iterTmp.value().partInfo[i].id;
                    qDebug() << a << " = " << iterTmp.value().partInfo[i].maxTemp;
                    qDebug() << a << " = " << iterTmp.value().partInfo[i].name;
                    qDebug() << a << " = " << iterTmp.value().partInfo[i].type;
                }
                iterTmp++;
                a++;
            }
#endif
        }
    }

    if(m_mapDevices.count() > 0) {
        QMap<int, ANALYSIS_INFO>::iterator iter = map_analysisInfo.begin();
        if(iter != map_analysisInfo.end()) {
            m_units.clear();
            for(int i = 0; i < iter.value().count; i++) {
                QString strUnit = QString("%1_%2").arg(iter.value().partInfo[i].name).arg((iter.value().partInfo[i].id + 1));
                m_units.append(strUnit);
            }
        }
    }
}

/*********************************************************************************
 * @ description        : 更新当前设备分析框信息
 * @ param - unitChange : 分析框信息
 * @ return             : null
 *********************************************************************************/
void createThread::Get_unit_change(QString unitChange)
{
    m_units.clear();
    QStringList tmpUnit = unitChange.split(";-");
    for(int i = 0; i < tmpUnit.count(); i++) {
        QStringList tmpUnitParts = QString(tmpUnit.at(i)).split(":");
        if(tmpUnitParts.count() > 1)
            m_units.append(tmpUnitParts.at(0));
    }
}

/*********************************************************************************
 * @ description   : 根据索引获取分析框名称
 * @ param - index : 索引
 * @ return        : 分析框名称
 *********************************************************************************/
QString createThread::get_unit_name(int index)
{
    if(index < m_units.count())
        return m_units.at(index);
    return "...";
}

/*********************************************************************************
 * @ description : 获取当前历史数据中的最高温度
 * @ param       : null
 * @ return      : 当前历史数据中的最高温度
 *********************************************************************************/
float createThread::get_maxTemp()
{
    float maxTemp = -50.00;
    QMap<int, ANALYSIS_INFO>::iterator iter = map_analysisInfo.begin();
    while(iter != map_analysisInfo.end()) {
        for(int i = 0; i < iter.value().count; i++) {
            if(maxTemp < iter.value().partInfo[i].maxTemp)
                maxTemp = iter.value().partInfo[i].maxTemp;
        }
        iter++;
    }

    if(maxTemp == -50.00)
        return 50.00;
    else
        return maxTemp + 1.50;
}

/*********************************************************************************
 * @ description : 获取当前历史数据中的最低温度
 * @ param       : null
 * @ return      : 当前历史数据中的最低温度
 *********************************************************************************/
float createThread::get_minTemp()
{
    float minTemp = 1200.00;
    QMap<int, ANALYSIS_INFO>::iterator iter = map_analysisInfo.begin();
    while(iter != map_analysisInfo.end()) {
        for(int i = 0; i < iter.value().count; i++) {
            if(minTemp > iter.value().partInfo[i].maxTemp)
                minTemp = iter.value().partInfo[i].maxTemp;
        }
        iter++;
    }

    if(minTemp == 1200.00)
        return 0.00;
    else
        return minTemp - 1.50;
}

/*********************************************************************************
 * @ description         : 根据索引获取温度
 * @ param - deviceIndex : 设备索引
 * @ param - partIndex   : 部位索引
 * @ return              : 温度
 *********************************************************************************/
float createThread::get_temp_by_index(int deviceIndex, int partIndex)
{
    if(deviceIndex < map_analysisInfo.count()) {
        QMap<int, ANALYSIS_INFO>::iterator iter = map_analysisInfo.find(map_analysisInfo.begin().key() + deviceIndex);
        if(iter != map_analysisInfo.end()) {
            if(partIndex < iter.value().count)
                return iter.value().partInfo[partIndex].maxTemp;
        }
    }

    return -50.00;
}

/*********************************************************************************
 * @ description   : 重置当前y轴索引
 * @ param - index : 需要设置的索引
 * @ return        : null
 *********************************************************************************/
void createThread::reset_current_index(int index)
{
    m_index = 0;
    if(index <= map_analysisInfo.count())
        m_index = index;
}

/*********************************************************************************
 * @ description : 计算上一x轴索引
 * @ param       : null
 * @ return      : null
 *********************************************************************************/
void createThread::pre_current_index()
{
    if(m_index == 0)
        return;
    if((m_index % 20) == 1) {
        m_index += 19;
        if(m_index > map_analysisInfo.count())
            m_index = map_analysisInfo.count();
    } else {
        m_index--;
    }
}

/*********************************************************************************
 * @ description : 计算下一x轴索引
 * @ param       : null
 * @ return      : null
 *********************************************************************************/
void createThread::next_current_index()
{
    if(m_index == 0)
        return;
    if((m_index % 20) == 0) {
        m_index -= 19;
    } else {
        ++m_index;
        if(m_index > map_analysisInfo.count())
            m_index -= ((m_index % 20) - 1);
    }
}

int createThread::get_currentdb_flag(QList<QPair<QString, QString>> &value)
{
    QList<QList<QPair<QString, QString>>> values;
    QList<QPair<QString, QString>> valuePart;
    QPair<QString, QString> pair;
    pair.first = "id";
    valuePart.append(pair);
    values.append(valuePart);
    QList<QString> whereList;
    whereList.append(QString("flag = 1"));
    m_ana_op.Query_info_by_rules(QString("%1_flag").arg(m_current_dbName), &values, whereList);

    value.clear();
    if (values.count() == 1) {
        value = values.at(0);
        return 0;
    }
    return -1;
}


int createThread::exist_history_by_info(QList<QString> infoList)
{   
    for(int i = 0; i < infoList.count(); i++) {
        QMap<QString, int>::iterator iter = m_mapDevices.find(QString(infoList.at(i)).replace("__0", "-"));
        if(iter == m_mapDevices.end())
            return 0;
        QList<QList<QPair<QString, QString>>> values;
        QList<QPair<QString, QString>> valuePart;
        QPair<QString, QString> pair;
        pair.first = "flag";
        valuePart.append(pair);
        values.append(valuePart);
        QList<QString> where;
        where.append(QString("id = %1").arg(iter.value()));
        m_ana_op.Query_info_by_rules(QString("%1_flag").arg(m_current_dbName), &values, where);

        if(values.count() != 1)
            return 0;
        if (values.at(0).at(0).second == "0") {
            return 0;
        } else if (values.at(0).at(0).second == "1") {

            /* 判断最新图片状态 */
            QList<QList<QPair<QString, QString>>> tmp_values;
            QList<QPair<QString, QString>> tmp_value;
            QPair<QString, QString> tmp_value_part[1];
            tmp_value_part[0].first = "date";
            tmp_value.append(tmp_value_part[0]);
            tmp_values.append(tmp_value);
            QList<QString> tmp_where;
            tmp_where.append(QString("match_id = %1").arg(iter.value()));
            m_ana_op.Query_info_by_rules(QString("%1").arg(m_current_dbName), &tmp_values, tmp_where);
            if (tmp_values.count() < 1)
                return 2;
            QString strDate = QString("%1").arg(tmp_values.last().at(0).second);

            /* 读取当前任务路径 */
            QFile file;
            file.setFileName(QString("/mnt/data/unzipped/%1/path").arg(m_current_dbName));
            if (file.exists()) {
                if (file.open(QIODevice::ReadOnly)) {
                    char r_data[128] = {0x00};
                    if (file.read(r_data, sizeof(r_data)) > 0) {
                        QDir dir(r_data);
                        if(! dir.exists())
                            return 2;
                        QStringList filters;
                        filters << QString("%1*.irp.jpg").arg(strDate);
                        QStringList listFilters = dir.entryList(filters, QDir::Files | QDir::NoSymLinks);
                        if (listFilters.count() < 1)
                            return 2;
                    } else {
                        return 2;
                    }
                } else {
                    return 2;
                }
            } else {
                return 2;
            }
        }

        return 1;
    }
    return 0;
}


void createThread::Set_current_dbName(QString dbName)
{
    QStringList pathList = dbName.split("/");
    if(pathList.count() >= 5)
        m_current_dbName = pathList.at(4);
    qDebug() << "#### [createThread] [Set_current_dbName] : " << m_current_dbName;
}

void createThread::Set_capturt_flag(QString deviceInfo)
{
    qDebug() << "#### [createThread] [Set_capturt_flag] : RUN . . . " << deviceInfo;
    QMap<QString, int>::iterator iter = m_mapDevices.find(deviceInfo.replace("__0", "-"));
    if(iter == m_mapDevices.end()) {
        qDebug() << "#### [createThread] [Set_capturt_flag] :" << deviceInfo.replace("__0", "-") << " WARNING ! ! !";
        iter = m_mapDevices.begin();
        while (iter != m_mapDevices.end()) {
            qDebug() << "---> " << iter.key();
            iter++;
        }
        return;
    }

    QPair<QString, QString> where;
    where.first = "id";
    where.second = QString("%1").arg(iter.value());
    QList<QPair<QString, QString>> listTarget;
    QPair<QString, QString> target;
    target.first = "flag";  target.second = "1";
    listTarget.append(target);
    m_ana_op.Update_info_line(QString("%1_flag").arg(m_current_dbName), where, listTarget);
}

void createThread::reset_capture_flag_by_index(QString deviceInfo)
{
    qDebug() << "#### [createThread] [Set_capturt_flag] : RUN . . . " << deviceInfo;
    QMap<QString, int>::iterator iter = m_mapDevices.find(deviceInfo.replace("__0", "-"));
    if(iter == m_mapDevices.end()) {
        qDebug() << "#### [createThread] [Set_capturt_flag] :" << deviceInfo.replace("__0", "-") << " WARNING ! ! !";
        iter = m_mapDevices.begin();
        while (iter != m_mapDevices.end()) {
            //qDebug() << "---> " << iter.key();
            iter++;
        }
        return;
    }

    QPair<QString, QString> where;
    where.first = "id";
    where.second = QString("%1").arg(iter.value());
    QList<QPair<QString, QString>> listTarget;
    QPair<QString, QString> target;
    target.first = "flag";  target.second = "0";
    listTarget.append(target);
    m_ana_op.Update_info_line(QString("%1_flag").arg(m_current_dbName), where, listTarget);
}

void createThread::reset_capture_flag()
{
    QList<QList<QPair<QString, QString>>> value;
    QList<QPair<QString, QString>> valuePart;
    QPair<QString, QString> pair;
    pair.first = "id";
    valuePart.append(pair);
    value.append(valuePart);
    QList<QString> whereList;
    whereList.append(QString("flag = 1"));
    m_ana_op.Query_info_by_rules(QString("%1_flag").arg(m_current_dbName), &value, whereList);

    for(int i = 0; i < value.count(); i++) {
        QPair<QString, QString> where;
        where.first = "id";     where.second = QString("%1").arg(value.at(i).at(0).second);
        QList<QPair<QString, QString>> listTarget;
        QPair<QString, QString> target;
        target.first = "flag";  target.second = "0";
        listTarget.append(target);
        m_ana_op.Update_info_line(QString("%1_flag").arg(m_current_dbName), where, listTarget);
    }

    if (QFile::exists(QString("/mnt/data/unzipped/%1/path").arg(m_current_dbName)))
        QFile::remove(QString("/mnt/data/unzipped/%1/path").arg(m_current_dbName));
}

bool createThread::get_pre_btn_status()
{
    if(map_analysisInfo.empty())
        return false;

    if(m_index % 20 == 1)
        return false;
    else
        return true;
}

bool createThread::get_next_btn_status()
{
    if(map_analysisInfo.empty())
        return false;

    if((m_index % 20 == 0 && m_index != 0) || m_index == map_analysisInfo.count())
        return false;
    else
        return true;
}

































