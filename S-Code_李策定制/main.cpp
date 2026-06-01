#include "mainwidget.h"
#include <QApplication>

/**
 * @brief main 111
 * @param argc 222
 * @param argv 333
 * @return
 */
#define SDPICFULLFILE  "/run/media/mmcblk2p1/DCIM/"
#define QDEBUG_OVER 0  //串口重定向

#if QDEBUG_OVER
QFile logfile;
QTextStream logts;

void customMessageHandler(QtMsgType type,const QMessageLogContext &,const QString & str)
{
    logts << QDateTime::currentDateTime().toString("hhmmss") << "-" << str << endl;
    logts.flush();
}
#endif

int debug_level = ERR_LEVEL|WARN_LEVEL|INIT_LEVEL|INFO_LEVEL|DBG_LEVEL_LOW;
int debug_object = DEBUG_PMS_PKG;
int debug_dev_level = ERR_LEVEL|WARN_LEVEL|INIT_LEVEL|INFO_LEVEL|DBG_LEVEL_LOW;/*|DBG_LEVEL_HIGH*/
int debug_dev_object = DEBUG_DEV_BLE;
int debug_redirect = 0;
FILE *debug_fp = NULL;

int malloc_switch = 0;
int malloc_redirect = 0;
FILE *malloc_fp = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if QDEBUG_OVER
    //log
    QString svret = QString("QtLog_") + QDateTime::currentDateTime().toString("ddhhmm");
    QString logaddr = SDPICFULLFILE + svret + QString(".txt");
    logfile.setFileName(logaddr);
    if(logfile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        logts.setDevice(&logfile);
    }
    //log

    qInstallMessageHandler(customMessageHandler);
#endif
    gst_init (&argc, &argv);//初始化gstreamer

    QFont font;
    font.setPointSize(10);
    font.setFamily("msyh");
    a.setFont(font);

    MainWidget w;

    bool readError = false;
    readError = w.hpsetting.winInit();//通过配置文件设置图标位置,如果不想用配置文件配置，则屏蔽这个
    while(readError)
    {
        readError = w.hpsetting.winInit();
    }

    w.show();

    return a.exec();
}
