#ifndef HPCPUMEM_H
#define HPCPUMEM_H

#include  <QWidget>
#include  <QTimer>
#include  <QDebug>
#include  <QProcess>

namespace Ui {
class HpCpuMem;
}

class HpCpuMem : public QWidget
{
    Q_OBJECT

public:
    explicit HpCpuMem(QWidget *parent = 0);
    ~HpCpuMem();

    QProcess *cpuProcess;
    QProcess *memProcess;

    QTimer *timer0,*timer1;
    void hp_setDefine_S3x0(bool isSelect);
public slots:
    void update_cpu();
    void ReadCpuData();
    void ReadMemData();
private:
    Ui::HpCpuMem *ui;

    int memoryPercent;
    int memoryAll;
    int memoryUse;
    int memoryFree;

    int totalNew, idleNew, totalOld, idleOld;
    int cpuPercent;

};

#endif // HPCPUMEM_H
