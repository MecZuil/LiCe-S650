#include  "hpcpumem.h"
#include  "ui_hpcpumem.h"

#define MB (1024 * 1024)
#define KB (1024)

HpCpuMem::HpCpuMem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HpCpuMem)
{
    ui->setupUi(this);
    timer0 = new QTimer(this);
    connect(timer0, SIGNAL(timeout()), this, SLOT(update_cpu()));

    cpuProcess = new QProcess(this);
    connect(cpuProcess,SIGNAL(readyRead()),this,SLOT(ReadCpuData()));

    memProcess = new QProcess(this);
    connect(memProcess,SIGNAL(readyRead()),this,SLOT(ReadMemData()));

}

HpCpuMem::~HpCpuMem()
{
    timer0->stop();
    delete ui;
}

void HpCpuMem::hp_setDefine_S3x0(bool isSelect)
{
    if(isSelect)
    {
        this->resize(312,153);
        ui->label->setGeometry(10,5,200,20);
        ui->widget->setGeometry(10,30,200,110);
    }
}

void HpCpuMem::update_cpu()
{
//    qDebug()<<cpuProcess->state();
    if(cpuProcess->state() == QProcess::NotRunning)
    {
        totalNew = idleNew = 0;
        cpuProcess->start("cat /proc/stat");
    }
    if(memProcess->state() == QProcess::NotRunning)
    {
        memProcess->start("cat /proc/meminfo");
    }
    ui->widget->list.append(cpuPercent);
    ui->widget->update();
}


void HpCpuMem::ReadCpuData()
{
    while (!cpuProcess->atEnd()) {
        QString s = QLatin1String(cpuProcess->readLine());
        if (s.startsWith("cpu")) {
            QStringList l_list = s.split(" ");
            idleNew = l_list.at(5).toInt();
            foreach (QString value, l_list) {
                totalNew += value.toInt();
            }

            int total = totalNew - totalOld;
            int idle = idleNew - idleOld;
            cpuPercent = 100 * (total - idle) / total;
            totalOld = totalNew;
            idleOld = idleNew;
            break;
        }

    }
}


void HpCpuMem::ReadMemData()
{
    while (!memProcess->atEnd()) {
        QString s = QLatin1String(memProcess->readLine());
        if (s.startsWith("MemTotal")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            memoryAll = s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("MemFree")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree = s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("Buffers")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree += s.left(s.length() - 3).toInt() / KB;
        } else if (s.startsWith("Cached")) {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree += s.left(s.length() - 3).toInt() / KB;
            memoryUse = memoryAll - memoryFree;
            memoryPercent = 100 * memoryUse / memoryAll;
            break;
        }
    }

    QString msg = QString("%1%(%2 MB/%3 MB )")
                  .arg(memoryPercent).arg(memoryUse).arg(memoryAll);
    ui->label->setText(msg);
}
