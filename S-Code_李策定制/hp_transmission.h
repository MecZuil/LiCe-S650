#ifndef HP_TRANSMISSION_H
#define HP_TRANSMISSION_H

#include <QWidget>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/time.h>

#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QStringList>
#include <QtEndian>
#include <QDebug>
#include "quazip/quazip.h"
#include "quazip/quazipfile.h"
#include "debug.h"
#include "pms_protocol_pkg.h"
#include "hp_bt1036.h"
#include "stdio.h"
#include "hi384_protocol.h"

static pthread_t g_pms_connect_thread_id = 0;   /*PMS通讯心跳线程ID*/
static int g_pms_connect_thread_quit = 1;       /*PMS通讯心跳线程退出标记*/
static int g_pms_connect_count = 0;             /*PMS连接状态*/
static int g_pms_pkg_number = 1;
static int g_pms_pkg_sending = 0;

#define BT1036_MODE             BT1036_GATT

#define BT1036_BLE              0
#define BT1036_AUDIO            1
#define BT1036_GATT             2
#define PMS_DETECTION_DATFILE           "/run/media/mmcblk2p1/DCIM/IMG_20240314_172706.dat"
#define PMS_BUSINESS_XMLFILE            "/home/root/pms_task_dection.xml"
#define PMS_TEST_XMLFILE                "/home/root/test.txt"

#define SEND_BUFFER_LENGTH      10

//namespace Ui {
//class hp_transmission;
//}

class hp_transmission : public QWidget
{
    Q_OBJECT

public:
    explicit hp_transmission(QWidget *parent = nullptr);
    ~hp_transmission();
    void setBleType(int bleType);
    void pms_detection_upload(const char *uploadFileName);
    int  getBleType();
    // 添加单例访问方法
    static hp_transmission* getInstance() {
        return instance;
    }
    void printAtlasRaw(const pms_ir_atlas_t &atlas) {
        // 辅助函数声明（放在函数外部或类中）
        auto strnlen16 = [](const char16_t* s, size_t maxlen) {
            const char16_t* end = s;
            while (maxlen-- > 0 && *end != 0) ++end;
            return end - s;
        };
        qint64 timestamp = atlas.ir_atlas_capture_time;  // 2022-01-01 00:00:00 UTC
        qDebug().nospace().noquote()
            << "ir_code_type: " << static_cast<int>(atlas.ir_code_type) << "\n"
            << "ir_atlas_len: " << atlas.ir_atlas_len << "\n"
            << "ir_atlas_capture_time: "
            << QString::number(timestamp) << "\n"
            << "ir_atlas_nature: " << static_cast<int>(atlas.ir_atlas_nature) << "\n"
            << "device_name: \"" << QString::fromUtf16(
                reinterpret_cast<const char16_t*>(atlas.device_name),
                strnlen16(reinterpret_cast<const char16_t*>(atlas.device_name), sizeof(atlas.device_name)/2)) << "\"\n"
            << "device_code: \"" << QByteArray(atlas.device_code,
                strnlen(atlas.device_code, sizeof(atlas.device_code))).constData() << "\"\n"
            << "test_point_name: \"" << QString::fromUtf16(
                reinterpret_cast<const char16_t*>(atlas.test_point_name),
                strnlen16(reinterpret_cast<const char16_t*>(atlas.test_point_name), sizeof(atlas.test_point_name)/2)) << "\"\n"
            << "test_point_code: \"" << QByteArray(atlas.test_point_code,
                strnlen(atlas.test_point_code, sizeof(atlas.test_point_code))).constData() << "\"\n"
            << "detection_channel_flag: 0x" << QString::number(atlas.detection_channel_flag, 16).toUpper() << "\n"
            << "storage_data_type: " << static_cast<int>(atlas.storage_data_type) << "\n"
            << "temp_unit: " << (atlas.temp_unit == 0 ? "°C" : "°F") << "\n"
            << "temp_matrix_width: " << atlas.temp_matrix_width << "\n"
            << "temp_matrix_height: " << atlas.temp_matrix_height << "\n"
            << "ccd_picture_size: " << atlas.ccd_picture_size << "\n"
            << "ir_picture_size: " << atlas.ir_picture_size << "\n"
            << "ir_emissivity: " << QString::number(atlas.ir_emissivity, 'f', 3) << "\n"
            << "ir_distance: " << atlas.ir_distance << "\n"
            << "ir_ambient_temp: " << QString::number(atlas.ir_ambient_temp, 'f', 1) << "\n"
            << "ir_relative_humidity: " << static_cast<int>(atlas.ir_relative_humidity) << "%\n"
            << "ir_reflection_temp: " << QString::number(atlas.ir_reflection_temp, 'f', 1) << "\n"
            << "ir_tempclass_max: " << QString::number(atlas.ir_tempclass_max, 'f', 1) << "\n"
            << "ir_tempclass_min: " << QString::number(atlas.ir_tempclass_min, 'f', 1) << "\n"
            << "manufacturer_reserved: "
            << QByteArray(atlas.manufacturer_reserved, sizeof(atlas.manufacturer_reserved)).toHex(' ');
    }


    // 打印函数实现
    void printPackageDatRaw(const pms_package_dat_t& dat) {
        // 辅助函数：安全获取定长字符数组有效长度
        auto safeStrLen = [](const char* s, size_t maxlen) {
            const char* end = s;
            while (maxlen-- > 0 && *end != '\0') ++end;
            return static_cast<int>(end - s);
        };
        auto strnlen16 = [](const char16_t* s, size_t maxlen) {
            const char16_t* end = s;
            while (maxlen-- > 0 && *end != 0) ++end;
            return end - s;
        };

        // 特殊类型处理
        const QString versionStr = QString("%1.%2.%3.%4")
            .arg(dat.version[0]).arg(dat.version[1])
            .arg(dat.version[2]).arg(dat.version[3]);

        // 开始逐项输出
        QDebug dbg = qDebug().nospace().noquote();
        dbg << "==== PMS Package Dat Structure ====\n";

        // 基础数值类型
        dbg << "fileLength: " << dat.fileLength << "\n";
        dbg << "version: " << versionStr << "\n";

        // 时间戳处理（假设存储的是秒级时间戳）
        dbg << "fileCreateTime: "
            << dat.fileCreateTime << "\n";

        // 定长字符串处理
        dbg << "device_name: \""
            << QString(dat.device_name)
            << "\"\n";
        dbg << "device_code: \""
            << QString::fromLatin1(dat.device_code,
                safeStrLen(dat.device_code, sizeof(dat.device_code)))
            << "\"\n";

        // 枚举/数值类型
        dbg << "weather: " << static_cast<uint>(dat.weather) << "\n";

        // 浮点数（保留两位小数）
        dbg << "ir_ambient_temp: "
            << dat.ir_ambient_temp << "\n";
        dbg << "ir_relative_humidity: "
            << dat.ir_relative_humidity << "\n";

        // 设备信息字符串
        dbg << "equipFactory: \""
            << QString::fromLatin1(dat.equipFactory,
                safeStrLen(dat.equipFactory, sizeof(dat.equipFactory)))
            << "\"\n";
        dbg << "equipType: \""
            << QString::fromLatin1(dat.equipType,
                safeStrLen(dat.equipType, sizeof(dat.equipType)))
            << "\"\n";

        // 不支持的地理信息
        dbg << "longitude: "
            << QString::number(dat.longitude, 'g', 10) << "\n";
        dbg << "latitude: "
            << QString::number(dat.latitude, 'g', 10) << "\n";
        dbg << "height: " << dat.height << "m\n";

        dbg << "==== End of Structure ====";
    }

signals:
    void signal_set_transmission_addr(QString addr);
    void signal_transmission_init_over();
    void signal_transmission_allow_upload();
    void signal_transmission_send_heartbeat();
    void signal_transmission_get_download();
    void signal_stop_get_bleInfo(QString bleInfo);
    void signal_transmission_send_upload_success();
public slots:
    void slot_link_transmission(QString addr);
    void slot_start_get_xml();
    void slot_start_get_bleInfo();
    void slot_stop_get_bleInfo(QString bleInfo);
    void setBleMode(int mode);
    void slot_timer_get_ble_link_msg();
    void hp_start_transmission();
    void hp_stop_transmission();
    void hp_upload_xml_dat(QStringList uploadFileList, QString datFilePath, QString xmlFilePath, bool isZip);
    void packDatFilesToZip(const QStringList& datFiles, const QString& outputZipPath = "");
    QString createDatFile(QString datFilePath);
    void hp_setFactoryName(QString factoryName);
    void hp_setEquipID(QString equipType, QString ID);
private:
    static hp_transmission* instance; // 单例指针
    QString m_xmlFilePath;
    QString m_datFilePath;
    QString m_factoryName;
    QTimer * m_getBleLinkMsgTimer;
    pms_package_dat_t pms_package_dat;
    QStringList m_datIsCreateLIst;
    int m_clearanceDatNum;
    int m_bleMode;
    int m_bleType;
    int m_pmsConnectCSount;
    int m_pmsConnectCountStorage;
    bool m_isUpload;
    QString m_equipType;
    QString m_equipID;
};

#endif // HP_TRANSMISSION_H
