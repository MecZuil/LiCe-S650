#ifndef HP_TASK_FORMULA_H
#define HP_TASK_FORMULA_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QMap>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QDateTime>

#include <iterator>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hp_statement.h"
#include "hi384_protocol.h"


class hp_task_formula : public QObject
{
    Q_OBJECT
public:
    explicit hp_task_formula(QObject *parent = 0);

    void set_sd_path(QString strPath);
    /* 调试信息 */
    void test();
    /* 设置环境温度 */
    void set_envTemp(float temp);
    /* 清空容器 */
    void clear_buffer();
    /* 添加设备信息 */
    void add_deviceInfo(ANA_DEVICE device, QVector<ANA_OUTLINE> params);
    /* 公式计算 */
    bool calculate_rule_formula(QString curDevice, QString curPos,QString param, QString rule, QString formula);

signals:

public slots:

private:
    QString m_strSDPath;
    float m_envTemp;                                            //环境温度
    QMap<ANA_DEVICE, QVector<ANA_OUTLINE>> m_mapDevices;   //设备信息

    /* 读取图像信息 */
    QVector<ANA_OUTLINE> get_img_info(QString path, QString fileName);
    /* 热点温度条件判断 */
    bool cal_hot_temp(float temp, float thrValue);
    /* 同相温差条件判断 */
    bool cal_inPhase_tempDiff(float temp_1, float temp_2, float thrValue);
    /* 相间温差条件判断 */
    bool cal_outPhase_tempDiff(float temp_1, float temp_2, float thrValue);
    /* δ值计算 */
    bool cal_relative_tempDiff(float temp_1, float temp_2, float thrValue);
    /* 获取较低的温度 */
    float compare_min(float temp_1, float temp_2);
    /* 获取较高的温度 */
    float compare_max(float temp_1, float temp_2);
    /* 文件名时间戳比较 */
    QString compare_img_timestamp(QString fileName_1, QString fileName_2);
    /* 字符替换 */
    QString replace_covert_char(QString srcName);
};

#endif // HP_TASK_FORMULA_Htemp














