#ifndef HPHIDE_LASER_H
#define HPHIDE_LASER_H

#include "hi384_protocol.h"
#include "hpxmlreader.h"
#include <QWidget>
#include <QMouseEvent>
#include <QVector>
#include <QPair>
#include <QDebug>
#include <QFile>
#include <cmath>
namespace Ui {
class hphide_laser;
}

class hphide_laser : public QWidget
{
    Q_OBJECT

public:
    explicit hphide_laser(QWidget *parent = nullptr);
    ~hphide_laser();
    void hp_setDefineS3X0(bool isSelect);
    void start_laser_adjust();
    void set_laser_range(int range100);
    void fitCubicEquation(const QVector<QPair<double, double>>& data, double& a, double& b, double& c, double& d);
signals:
    void signal_hide_laser_get_lasserRange();
protected:
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
private:
    Ui::hphide_laser *ui;
    HpXmlReader m_hpxmlreader;
    QList<int>  m_xPosList;
    QList<int>  m_yPosList;
    int         m_currRangeIndex;
    int         m_currentMoveSteep;
    QList<double> m_currRangeList;
    double        a,b,c,d,e,f,g,h;
    bool        m_isS3X0;
    bool        m_isCCD;
    QVector<QPair<double, double>> dataX;
    QVector<QPair<double, double>> dataY;
};

#endif // HPHIDE_LASER_H
