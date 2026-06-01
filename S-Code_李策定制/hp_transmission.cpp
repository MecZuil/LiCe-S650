#include "hp_transmission.h"

hp_transmission* hp_transmission::instance = nullptr;

void pms_connect_link_signal()
{
    if(g_pms_pkg_sending == 1)
        return;
    pms_package_head_t pms_package_head = {0};
    pms_package_end_t pms_package_end = {0};
    unsigned long long business_len = 0;
    unsigned long long detection_len = 0;
    /*组建心跳包*/
    pms_protocol_pkg_create_head(&pms_package_head, g_pms_pkg_number++, e_PMS_PKG_TYPE_CONNECT_REQUEST, business_len, detection_len);

    pms_protocol_pkg_create_end(&pms_package_end);

    pms_protocol_pkg_update_end(&pms_package_end, (void *)&pms_package_head, sizeof(pms_package_head)); /*先将报文头数据进行更新*/

    /*上传报文头*/

    if(hp_transmission::getInstance()->getBleType() == 0)
        bt986_transmission_send((char *)&pms_package_head, sizeof(pms_package_head));
    else if(hp_transmission::getInstance()->getBleType() == 1)
        ble_transparent_send((char *)&pms_package_head, sizeof(pms_package_head));

    /*上传包尾*/
    pms_package_end.verify = htonl( pms_package_end.verify );

    if(hp_transmission::getInstance()->getBleType() == 0)
        bt986_transmission_send((char *)&pms_package_end, sizeof(pms_package_end));
    else if(hp_transmission::getInstance()->getBleType() == 1)
        ble_transparent_send((char *)&pms_package_end, sizeof(pms_package_end));
    return;
}

void *pms_connect_handle_thread(void *arg)
{
    (void)arg;
    struct timeval start={0}, stop={0};
    static int pms_connect_count_storage = 0;
    static int pms_connect_count = 0;
    int link_time_msec = 20000;

    gettimeofday(&start, NULL);
    gettimeofday(&stop, NULL);/*初始化时间*/
    while( 1 == g_pms_connect_thread_quit ) {
        /*间隔40s主动发送一次心跳*/
        if( ( (stop.tv_sec-start.tv_sec)*1000+(stop.tv_usec-start.tv_usec)/1000 ) >= link_time_msec  && 1 == g_pms_get_link_msg && g_ble_trans_mode == 1) {

//            ble_get_spp_stat();
            printf("pms_connect_count_storage:%d   g_pms_connect_count:%d !\n",
                        pms_connect_count_storage, g_pms_connect_count);
            /*上次请求未响应*/
            if( pms_connect_count_storage == g_pms_connect_count ) {
                pms_connect_count++;
                if(pms_connect_count > 2)
                {
                    pms_connect_count = 0;
                    g_ble_spp_link = 0;
                }
                err_printf("Connection not replied, it may have been disconnected !\n");
            }
            pms_connect_count_storage = g_pms_connect_count;    /*等待连接回复*/

            pms_connect_link_signal();
            printf("pms connect link send finish !\n");

            gettimeofday(&start, NULL); /*更新计时*/
//            g_pms_get_link_msg = 0;
        }

        gettimeofday(&stop, NULL);/*初始化时间*/
        sleep(40);
    }

    return NULL;
}


int pms_pkg_callb(pms_pkg_callback_info_t pms_pkg_info)
{
    qDebug("pms_pkg_callb %d\n" ,pms_pkg_info.info_type);
    switch(pms_pkg_info.info_type)
    {
    case e_PMS_PKG_TYPE_CONNECT_REQUEST:
//        g_pms_get_link_msg = 1;
        break;
    case e_PMS_PKG_TYPE_TASK_DISTRIBUTE:
    {
        pms_package_head_t pms_package_head = {0};
        pms_package_end_t pms_package_end = {0};
        unsigned long long business_len = 0;
        unsigned long long detection_len = 0;

        pms_protocol_pkg_create_head(&pms_package_head, pms_pkg_info.pkg_number, e_PMS_PKG_TYPE_TASK_CONFIRM, business_len, detection_len);
        pms_protocol_pkg_create_end(&pms_package_end);
        /*没有业务数据需要上传*/
        pms_protocol_pkg_update_end(&pms_package_end, (void *)&pms_package_head, sizeof(pms_package_head)); /*先将报文头数据进行更新*/
        /*任务下发的回应，业务数据和检测文件数据都为0，不需要进行更新*/

        /*上传报文头*/
        if(hp_transmission::getInstance()->getBleType() == 0)
            bt986_transmission_send((char *)&pms_package_head, sizeof(pms_package_head));
        else if(hp_transmission::getInstance()->getBleType() == 1)
            ble_transparent_send((char *)&pms_package_head, sizeof(pms_package_head));

        qDebug("%x", pms_package_end.verify);
        pms_package_end.verify = htonl( pms_package_end.verify );
        qDebug("%x", pms_package_end.verify);

        /*上传包尾*/
        if(hp_transmission::getInstance()->getBleType() == 0)
            bt986_transmission_send((char *)&pms_package_end, sizeof(pms_package_end));
        else if(hp_transmission::getInstance()->getBleType() == 1)
            ble_transparent_send((char *)&pms_package_end, sizeof(pms_package_end));

        printf("pms_pkg_callb:%s !\n", pms_pkg_info.task_file);

        sleep(5);

        g_pms_get_link_msg = 1;
        g_pms_pkg_number = pms_pkg_info.pkg_number++;
        hp_transmission::getInstance()->signal_transmission_get_download();

        break;
    }
    case e_PMS_PKG_TYPE_CONNECT_CONFIRM:
    {
        g_pms_connect_count++;
        printf("pms connect confirm connect count:%d !\n", g_pms_connect_count);
        hp_transmission::getInstance()->signal_transmission_allow_upload();
        break;
    }
    case e_PMS_PKG_TYPE_DETECTION_CONFIRM:
    {
        if( pms_pkg_info.task_file[0] != 0 ) {  /*存在有效文件*/
            FILE *task_fp = NULL;

            printf("task_file:%s !\n", pms_pkg_info.task_file);

            task_fp = fopen(pms_pkg_info.task_file, "r+");
            if( task_fp != NULL ) {
                int task_file_size = 0;
                fseek(task_fp, 0L, SEEK_END);       /*转到文件尾*/
                task_file_size = ftell(task_fp);    /*获取文件大小*/
                printf("task_file_size:%d !\n", task_file_size);
                if( task_file_size ) {
                    unsigned char task_data[task_file_size];
                    int read_len = 0;

                    fseek(task_fp, 0L, SEEK_SET);       /*转到文件头*/
                    memset(task_data, 0x00, sizeof(task_data));

                    read_len = fread(task_data, 1, task_file_size, task_fp);
                    printf("read_len:%d !\n", read_len);

                    if( read_len == task_file_size ) {
                        printf("task_data:%s !\n", task_data);
                    }
                }
                fclose(task_fp);
            }
        }
        break;
    }
    case e_PMS_PKG_TYPE_UNKNOW:
    {
        err_printf("pms pkg analysis fail !\n");
        break;
    }
    default:
        break;
    }
    g_pms_get_link_msg = 1;
    g_pms_ble_link = 0;
    return 0;
}

int parse_hfpdev(const unsigned char* u_data, size_t data_len, char* dev_id) {
    const char* pattern = "+HFPDEV=";
    const size_t pattern_len = strlen(pattern);
    const char* paired_pattern = "PAIRED=0,";
    const size_t paired_pattern_len = strlen(paired_pattern);
    const char* a2dpdev_pattern = "+A2DPDEV=";
    const size_t a2dpdev_pattern_len = strlen(a2dpdev_pattern);
    const char* spp_pattern = "+SPPDEV=";
    const size_t spp_pattern_len = strlen(spp_pattern);
    const size_t target_id_len = 12; // C42B44D2C054长度

    const char* c_data = reinterpret_cast<const char*>(u_data);  // C++风格

    // 逐行查找目标字段
    const char* line_start = c_data;
    while(line_start < c_data + data_len) {
        const char* line_end = strstr(line_start, "\r\n");
        if(!line_end) break;

        // 检查是否为目标行
        if(strncmp(line_start, pattern, pattern_len) == 0) {
            const char* id_start = line_start + pattern_len;
            if(line_end - id_start >= target_id_len) {
                memcpy(dev_id, id_start, target_id_len);
                dev_id[target_id_len] = '\0';
                return 1; // 成功提取
            }
        }
        if(strncmp(line_start, paired_pattern, paired_pattern_len) == 0) {
            const char* id_start = line_start + paired_pattern_len;
            if(line_end - id_start >= target_id_len) {
                memcpy(dev_id, id_start, target_id_len);
                dev_id[target_id_len] = '\0';
                return 1; // 成功提取
            }
        }
        if(strncmp(line_start, a2dpdev_pattern, a2dpdev_pattern_len) == 0) {
            const char* id_start = line_start + a2dpdev_pattern_len;
            if(line_end - id_start >= target_id_len) {
                memcpy(dev_id, id_start, target_id_len);
                dev_id[target_id_len] = '\0';
                return 1; // 成功提取
            }
        }
        if(strncmp(line_start, spp_pattern, spp_pattern_len) == 0) {
            const char* id_start = line_start + spp_pattern_len;
            if(line_end - id_start >= target_id_len) {
                memcpy(dev_id, id_start, target_id_len);
                dev_id[target_id_len] = '\0';
                return 1; // 成功提取
            }
        }
        line_start = line_end + 2; // 跳过\r\n
    }
    return 0; // 未找到
}

static int ble_data_call(unsigned char *data, int datalen)
{
    printf("recv data: \n");
    int i = 0;
    for( i = 0; i< datalen; i++  ) {
        printf("%c", data[i]);
    }
//    printf("\n");
//    for( i = 0; i< datalen; i++  ) {
//        printf("0x%02X ", data[i], data[i]);
//    }
    printf("\n");

    pms_protocol_pkg_analysis(data, datalen);
    return 0;
}


hp_transmission::hp_transmission(QWidget *parent) :
    QWidget(parent)
{
    instance = this;
    m_bleMode = 339;
    m_bleType = 0;//0外接 1内置 2SD
    m_isUpload = false;
    m_clearanceDatNum = 0;
    m_pmsConnectCSount = 0;
    m_pmsConnectCountStorage = 0;
    m_equipType = "S650";
    m_equipID = "0606010371";
    m_getBleLinkMsgTimer = new QTimer(this);
    m_getBleLinkMsgTimer->setInterval(40000);
    m_getBleLinkMsgTimer->stop();
    connect(m_getBleLinkMsgTimer, SIGNAL(timeout()), this, SLOT(slot_timer_get_ble_link_msg()));
    m_xmlFilePath = PMS_BUSINESSFILE_NAME;
    m_datFilePath = PMS_BUSINESSFILE_XMLNAME;
    memset(&pms_package_dat, 0, sizeof(pms_package_dat_t));
}

hp_transmission::~hp_transmission()
{
    instance = nullptr; // 防止悬空指针
}

void hp_transmission::setBleMode(int mode)
{
    if(mode == 172)
    {
        ble_transmission_reset();
        return;
    }
    m_bleMode = mode;
}

void hp_transmission::hp_start_transmission()
{
    qDebug() << __func__;
    __attribute__((unused))char *salve_scan_result = NULL;
    __attribute__((unused))int result_length = 0;
    __attribute__((unused))char *save_dev_info = NULL;
    __attribute__((unused))int dev_info_length = 0;
    __attribute__((unused))char *save_pair_info = NULL;
    __attribute__((unused))int pair_info_length = 0;
    __attribute__((unused))static int wait_count = 0;
    __attribute__((unused))int scan_state = 0;
    __attribute__((unused))int a2dp_state = 0;
    __attribute__((unused))int pair_state = 0;
    struct timeval start, stop;
    int init_time = 0;

    gettimeofday(&start, NULL);
    qDebug() << __func__ << start.tv_sec;
    pms_protocol_init(pms_pkg_callb);

    if(m_bleType == 0)
    {
        if(QFile::exists("/dev/ttyACM1"))
            bt986_transmission_init("/dev/ttyACM1", 115200, ble_data_call);
        else if(QFile::exists("/dev/ttyACM0"))
            bt986_transmission_init("/dev/ttyACM0", 115200, ble_data_call);
    }
    else if(m_bleType == 1)
        ble_transparent_transmission_init("/dev/ttymxc2", 115200, ble_data_call, 1, 0);
    qDebug() << __func__ << "ble_transparent_transmission_init over";
    gettimeofday(&stop, NULL);
    qDebug() << __func__ << stop.tv_sec;
    init_time = (stop.tv_sec - start.tv_sec)*1000000+(stop.tv_usec-start.tv_usec);
    qDebug("init time:%d !\n", init_time);
    usleep(200);
    signal_transmission_init_over();
}

void hp_transmission::hp_stop_transmission()
{
    if(m_bleType == 0)
        bt986_transmission_uninit();
    else if(m_bleType == 1)
        ble_transparent_transmission_uninit();
    g_ble_spp_link = 0;
    g_pms_connect_thread_quit = 0;
    m_getBleLinkMsgTimer->stop();
}

void hp_transmission::hp_upload_xml_dat(QStringList uploadFileList, QString datFilePath, QString xmlFilePath, bool isZip)
{
    if(!m_isUpload)
        m_isUpload = true;
    else
        return;
    g_pms_get_link_msg = 0;
//    pms_connect_link_signal();
//    sleep(3);
    m_xmlFilePath = xmlFilePath;
    m_datFilePath = datFilePath;
    m_clearanceDatNum = 0;
    if(isZip)
    {
        QStringList uploadDatFileList;
        if(uploadFileList.count() != 0)
        {
            for(int i = 0; i < uploadFileList.count(); i++)
            {
                if(!m_datIsCreateLIst.contains(uploadFileList.at(i)))
                {
                    QString newDatFileName = createDatFile(uploadFileList.at(i));
                    uploadDatFileList.append(newDatFileName);
                    m_datIsCreateLIst.append(uploadFileList.at(i));
                }
                else
                {
                    uploadDatFileList.append(uploadFileList.at(i));
                }
            }
        }
                QString outDatFile = m_datFilePath + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz") + ".zip";
                packDatFilesToZip(uploadDatFileList, outDatFile);
    }
    else
    {
        m_datFilePath = createDatFile(uploadFileList.at(0));
    }
    system("sync");
    pms_detection_upload(m_xmlFilePath.toLocal8Bit().constData());
}

QString hp_transmission::createDatFile(QString xmlFilePath)
{
    qDebug() << __func__ << __LINE__ << xmlFilePath;//修改后
    memset(&pms_package_dat, 0, sizeof(pms_package_dat_t));
    pms_package_dat.datNum = 1;
    pms_ir_atlas_t atlas;
    QFile file(xmlFilePath);
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << "Failed to open file:" << file.errorString();
    }
    else
    {
        qint64 read_size = file.read(reinterpret_cast<char*>(&atlas), sizeof(pms_ir_atlas_t));

        pms_package_dat.fileCreateTime = atlas.ir_atlas_capture_time;
        qDebug() << __func__ << pms_package_dat.fileCreateTime << __LINE__;
        if (read_size != sizeof(pms_ir_atlas_t)) {
            qCritical() << "Incomplete data read (expected"
                       << sizeof(pms_ir_atlas_t) << "bytes, got" << read_size << ")";
        }
        else
        {
//            printAtlasRaw(atlas);
            pms_package_dat.version[0] = 0x01;
            pms_package_dat.version[1] = 0x00;
            pms_package_dat.version[2] = 0x00;
            pms_package_dat.version[3] = 0x00;
            memcpy(pms_package_dat.device_name, atlas.device_name, 118);
            memcpy(pms_package_dat.device_code, atlas.device_code, 42);
            pms_package_dat.weather = 0xff;
            pms_package_dat.ir_ambient_temp = atlas.ir_ambient_temp;

            const ushort* utf16equipType = m_equipType.utf16();
            int byteLength = m_equipType.length() * 2;
            memcpy(pms_package_dat.equipType, utf16equipType, byteLength);
            if (byteLength < 32) {
                memset(pms_package_dat.equipType + byteLength, 0, 32 - byteLength);
            }

            QString currEquipFactory("HongPu");
            const ushort* utf16equipFactory = currEquipFactory.utf16();
            byteLength = currEquipFactory.length() * 2;
            memcpy(pms_package_dat.equipFactory, utf16equipFactory, byteLength);
            if (byteLength < 32) {
                memset(pms_package_dat.equipFactory + byteLength, 0, 32 - byteLength);
            }

            pms_package_dat.equipId[0] = 0x00;
            pms_package_dat.equipId[1] = 0x05;
            pms_package_dat.equipId[2] = 0x03;
            pms_package_dat.equipId[3] = 0x18;
            std::string equipID = m_equipID.toLocal8Bit().toStdString();
            const char* cequipID = equipID.c_str();  // 需要时获取C风格字符串

            std::copy(cequipID, cequipID + std::min(strlen(cequipID)+1,
                      sizeof(pms_package_dat.equipSn)), pms_package_dat.equipSn);
            pms_package_dat.systemP = 25;
            pms_package_dat.latitude = 0;
            pms_package_dat.latitude = 0;
            pms_package_dat.height = 0;

        }
    }
    file.close();
//    QString outDatFile = m_datFilePath + QString::number(atlas.ir_atlas_capture_time) + "_gw.dat";

    QString outDatFile = m_datFilePath + "/" + QString::number(atlas.ir_atlas_capture_time) + "_gw.dat";
    bool istwiceUpload = QFile::exists(outDatFile);
//    return outDatFile;
    QFile datFile(outDatFile);
    if (!datFile.open(QIODevice::ReadWrite)) {
        qDebug() << "create dat fail" << outDatFile;
    }
    else
    {
        qDebug() << __func__ << __LINE__ << m_datFilePath << outDatFile;
        // 写入包头
        int ret = datFile.write(reinterpret_cast<char*>(&pms_package_dat), sizeof(pms_package_dat));
        qDebug() << __func__ << __LINE__ << "datFile.write" << ret;
        // 逐个读取文件并写入
        QFile xmlFile(xmlFilePath);
        if (!xmlFile.open(QIODevice::ReadOnly)) {
            qDebug() << "xmlFile.open(QIODevice::ReadOnly)";
        }
        QByteArray xmlData = xmlFile.readAll();
        datFile.write(xmlData);
        xmlFile.close();
        int totalSize = datFile.size();
        if(!istwiceUpload){
            totalSize = datFile.size() + 36;
        }
        datFile.seek(0);  // 回到文件头
        pms_package_dat.fileLength = totalSize;

        datFile.write(reinterpret_cast<char*>(&pms_package_dat.fileLength), sizeof(int));
        datFile.seek(totalSize - 36);
        QByteArray zeros(32, 0x00);  // 32 字节的 0
        datFile.write(zeros);
        datFile.close();
        sleep(1);
        QFile addDatFile(outDatFile);
        if (addDatFile.open(QIODevice::ReadWrite)) {
            QByteArray fileData = addDatFile.readAll();
            if (fileData.isEmpty()) {
                addDatFile.close();
                qDebug() << "Error: Failed to read file data";
            }
            else
            {
                // 计算并写入CRC
                qDebug() << "fileData.size()" << fileData.size();
                qDebug("fileData.data() 0x%x", fileData.data());
                unsigned int crc = crc32_calculate(0xFFFFFFFF, fileData.data(), fileData.size());
                qDebug("crcvalue 0x%x", crc);
                addDatFile.seek(totalSize - 4);
                addDatFile.write(reinterpret_cast<char*>(&crc), sizeof(int));
                qDebug("crcvalue 0x%x", crc);
                addDatFile.close();
            }
        } else {
            qDebug() << "Error: Failed to open file";
        }
    }

    return outDatFile;
}

void hp_transmission::packDatFilesToZip(const QStringList& datFiles, const QString& outputZipPath)
{
    qDebug() << __func__ << datFiles << outputZipPath;
    if(datFiles.count() == 0 || datFiles.isEmpty())
    {
        qWarning() << "fileList empty!";
        return;
    }
    qDebug() << __func__ << datFiles.count() << outputZipPath;

    // 自动生成ZIP路径（如果未指定）
    QString zipPath = outputZipPath;
    if (zipPath.isEmpty()) {
        qDebug() << __func__ << QFileInfo(datFiles.first()).absolutePath();
        QDir dir(QFileInfo(datFiles.first()).absolutePath());
        zipPath = dir.absoluteFilePath("output_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".zip");
    }

    QuaZip zip(zipPath);
    if (!zip.open(QuaZip::mdCreate)) {
        qWarning() << "can not create zip file" << zipPath;
        return;
    }

    // 逐个添加文件到ZIP
    for (const QString& datFile : datFiles) {
        QFileInfo fileInfo(datFile);
        if (!fileInfo.exists()) {
            qWarning() << "file not exist" << datFile;
            continue;
        }

        QFile inFile(datFile);
        if (!inFile.open(QIODevice::ReadOnly)) {
            qWarning() << "file open fail" << datFile;
            continue;
        }

        // 在ZIP中创建同名文件
        QuaZipFile outFile(&zip);
        if (!outFile.open(QIODevice::WriteOnly, QuaZipNewInfo(fileInfo.fileName(), datFile))) {
            qWarning() << "cannot addTo zip" << datFile;
            inFile.close();
            continue;
        }

        // 写入数据
        outFile.write(inFile.readAll());
        outFile.close();
        inFile.close();
    }

    zip.close();
    m_datFilePath = zipPath;
}

void hp_transmission::pms_detection_upload(const char *uploadFileName)
{
    qDebug() << __LINE__ << __func__;
    g_pms_ble_link = 1;
    g_pms_pkg_sending = 1;
    pms_package_head_t pms_package_head = {0};
    pms_package_end_t pms_package_end = {0};
    memset(&pms_package_dat, 0, sizeof(pms_package_dat_t));
    unsigned long long business_len = 0;
    unsigned long long detection_len = 0;
    unsigned long long business_send_len = 0;
    unsigned long long detection_send_len = 0;
    FILE *business_fp = NULL;
    FILE *detection_fp = NULL;
    struct timeval start, stop;
    int transparent_time = 0;
    int send_len = 0;
    qDebug() << __func__ << __LINE__;

    business_fp = fopen(m_xmlFilePath.toLocal8Bit().constData(), "r+");
    if( business_fp == NULL ) {
        err_printf("open %s fail !\n", m_xmlFilePath.toLatin1().constData());
        goto quit;
    }
    qDebug() << __func__ << __LINE__;
    qDebug() << m_datFilePath << m_xmlFilePath;
    detection_fp = fopen(m_datFilePath.toLocal8Bit().constData(), "r+");
    if( detection_fp == NULL ) {
        err_printf("open %s fail !\n", m_datFilePath.toLatin1().constData());
        goto quit;
    }
    fseek(business_fp, 0L, SEEK_END);   /*转到文件尾*/
    business_len = ftell(business_fp);  /*获取业务数据大小*/
    fseek(detection_fp, 0L, SEEK_END);   /*转到文件尾*/
    detection_len = ftell(detection_fp);  /*获取检测数据大小*/

    pms_package_dat.fileLength = detection_len;

    /*组建心跳包*/
    pms_protocol_pkg_create_head(&pms_package_head, g_pms_pkg_number++, e_PMS_PKG_TYPE_DETECTION_UPLOAD, business_len, detection_len);

    pms_package_head.direction_len = htobe64( detection_len);   /*字节顺序交换*/
    if(m_datFilePath.contains("zip"))
    {
        pms_package_head.compress_flag = 0x01;
    }
    pms_protocol_pkg_create_end(&pms_package_end);

    pms_protocol_pkg_update_end(&pms_package_end, (void *)&pms_package_head, sizeof(pms_package_head) - 8); /*先将报文头数据进行更新*/

    gettimeofday(&start, NULL);

    qDebug() << __func__ << __LINE__;
    /*上传报文头*/
    if(m_bleType == 0)
        send_len += bt986_transmission_send((char *)&pms_package_head, sizeof(pms_package_head) - 8);
    else if(m_bleType == 1)
        send_len += ble_transparent_send((char *)&pms_package_head, sizeof(pms_package_head) - 8);

    qDebug() << __func__ << __LINE__;

    printf("start send business file !\n");
    fseek(business_fp, 0L, SEEK_SET);   /*定位到文件头*/
    while( business_send_len < business_len ) { /*上传业务数据*/
        char data_buffer[SEND_BUFFER_LENGTH] = {0};
        int read_len = 0;

        read_len = fread(data_buffer, 1, sizeof(data_buffer), business_fp);
        int currsendLen = 0;

        if(m_bleType == 0)
            currsendLen = bt986_transmission_send(data_buffer, read_len);
        else if(m_bleType == 1)
            currsendLen = ble_transparent_send(data_buffer, read_len);
        if(currsendLen == 0)
        {
            qDebug() << __func__ << __LINE__;
            break;
        }
        send_len += currsendLen;
        pms_protocol_pkg_update_end(&pms_package_end, (void *)data_buffer, read_len); /*更新传输的业务数据*/

        business_send_len += read_len;  /*这里不做发送成功的字节校验，实测实际数据已经发送出去了但是也会没有接收到反馈*/
    }

    qDebug() << __func__ << __LINE__;
    if(m_bleType == 0)
        send_len += bt986_transmission_send((char *)&pms_package_head.direction_len, sizeof(pms_package_head.direction_len));
    else if(m_bleType == 1)
        send_len += ble_transparent_send((char *)&pms_package_head.direction_len, sizeof(pms_package_head.direction_len));

    pms_protocol_pkg_update_end(&pms_package_end, (void *)&pms_package_head.direction_len, sizeof(pms_package_head.direction_len)); /*更新检测数据长度*/

    qDebug() << __func__ << __LINE__;
    printf("start send detection file !\n");
    fseek(detection_fp, 0L, SEEK_SET);   /*定位到文件头*/
    while( detection_send_len < detection_len ) {
        char data_buffer[SEND_BUFFER_LENGTH] = {0};
        int read_len = 0;

        read_len = fread(data_buffer, 1, sizeof(data_buffer), detection_fp);
        int currsendLen = 0;
        if(m_bleType == 0)
            currsendLen = bt986_transmission_send(data_buffer, read_len);
        else if(m_bleType == 1)
            currsendLen = ble_transparent_send(data_buffer, read_len);
        if(currsendLen == 0)
            break;
        send_len += currsendLen;
        pms_protocol_pkg_update_end(&pms_package_end, (void *)data_buffer, read_len); /*更新传输的检测文件数据*/

        detection_send_len += read_len;  /*这里不做发送成功的字节校验，实测实际数据已经发送出去了但是也会没有接收到反馈*/
    }

    qDebug() << __func__ << __LINE__;
    /*上传包尾*/
    pms_package_end.verify = htonl(pms_package_end.verify);
    if(m_bleType == 0)
        send_len += bt986_transmission_send((char *)&pms_package_end, sizeof(pms_package_end));
    else if(m_bleType == 1)
        send_len += ble_transparent_send((char *)&pms_package_end, sizeof(pms_package_end));
    qDebug() << __func__ << __LINE__;
    gettimeofday(&stop, NULL);
    transparent_time = (stop.tv_sec-start.tv_sec)*1000000+(stop.tv_usec-start.tv_usec);
    printf("verify:%d   pms_package_head.direction_len:%lld   send_len:%d !\n",
                    pms_package_end.verify, pms_package_head.direction_len, send_len);
    qDebug() << pms_package_head.direction_len;
    qDebug() << "verify" << pms_package_end.verify;
    signal_transmission_send_upload_success();
    m_isUpload = false;
quit:
    if(business_fp) {
        fclose(business_fp);
        business_fp = NULL;
    }
    if(detection_fp) {
        fclose(detection_fp);
        detection_fp = NULL;
    }
    printf("pms detection upload finish !\n");
    g_pms_pkg_sending = 0;
    g_pms_ble_link = 0;
    m_isUpload = false;
    return;
}

void hp_transmission::slot_timer_get_ble_link_msg()
{
    printf("pms_connect_count_storage:%d   g_pms_connect_count:%d !\n",
                m_pmsConnectCountStorage, g_pms_connect_count);
    /*上次请求未响应*/
    if( m_pmsConnectCountStorage == g_pms_connect_count ) {
        m_pmsConnectCSount++;
        if(m_pmsConnectCSount > 10)
        {
            m_pmsConnectCSount = 0;
        }
        err_printf("Connection not replied, it may have been disconnected !\n");
    }
    m_pmsConnectCountStorage = g_pms_connect_count;    /*等待连接回复*/
    qDebug() << "g_pms_get_link_msg" << g_pms_get_link_msg;
    if(g_pms_get_link_msg == 1)
    {
        signal_transmission_send_heartbeat();
        pms_connect_link_signal();
    }
}

void hp_transmission::slot_link_transmission(QString addr)
{
    qDebug() << "g_pms_get_link_msg" << g_pms_get_link_msg << "g_ble_spp_link" << g_ble_spp_link;
    g_pms_get_link_msg = 1;
    if(g_ble_spp_link == 1)
        return;

    g_ble_spp_link = 1;
    bt986_transmission_start(addr);
    m_getBleLinkMsgTimer->start(30000);
}

void hp_transmission::slot_start_get_xml()
{
    g_pms_get_link_msg = 0;
}


void hp_transmission::slot_start_get_bleInfo()
{
    qDebug() << __func__;
    bt1036_scan_ble_info();
}

void hp_transmission::slot_stop_get_bleInfo(QString bleInfo)
{
    qDebug() << __func__ << __LINE__ << bleInfo;
    signal_stop_get_bleInfo(bleInfo);
}

void hp_transmission::hp_setFactoryName(QString factoryName)
{
    m_factoryName = factoryName;
}

void hp_transmission::hp_setEquipID(QString equipType, QString ID)
{
    m_equipID = ID;
    m_equipType = equipType;
}

void hp_transmission::setBleType(int bleType)
{
    m_bleType = bleType;
}

int  hp_transmission::getBleType()
{
    return m_bleType;
}
