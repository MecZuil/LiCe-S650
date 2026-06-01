#include "hphide_laser.h"
#include "ui_hphide_laser.h"

hphide_laser::hphide_laser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hphide_laser)
{
    ui->setupUi(this);
    this->move(160,0);
    m_currRangeList.append(0.5);
    m_currRangeList.append(1.5);
    m_currRangeList.append(6.5);
    m_currRangeList.append(20);
    m_currentMoveSteep = 1;
    a = b = c = d = e = f = g = h = 0;
    m_xPosList = {0,0,0,0};
    m_yPosList = {0,0,0,0};
    dataX.clear();
    dataY.clear();
    m_isS3X0 = false;
    m_currRangeIndex = 0;
    ui->line_horizon->close();
    ui->line_vertical->close();
    ui->label_pos1->close();
    ui->label_pos2->close();
    ui->label_pos3->close();
    ui->label_pos4->close();
    m_isCCD = true;
//    QVector<QPair<double, double>> data;
//    data << QPair<double, double>(0.5, -207) << QPair<double, double>(1.5, -168) << QPair<double, double>(6.5, -154)
//         << QPair<double, double>(20, -151);

//    double e, b, c, d;
//    fitCubicEquation(data, e, b, c, d);
}

hphide_laser::~hphide_laser()
{
    delete ui;
}

void hphide_laser::hp_setDefineS3X0(bool isSelect)
{
    if(isSelect)
    {
        QFont font9;
        font9.setPointSize(9);
        QFont font10;
        font10.setPointSize(10);
        this->setGeometry(96, 0, 384, 272);
        ui->label->setGeometry(300, 240, 84, 32);
        ui->label_2->close();
        ui->line_horizon->close();
        ui->line_vertical->close();
        ui->label_mode->setGeometry(0, 240, 84, 32);
        ui->laser_pos->setGeometry(183, 130, 10, 10);
        ui->label->setFont(font10);
        ui->label_mode->setFont(font10);
        m_isS3X0 = true;
    }
}

void hphide_laser::start_laser_adjust()
{

}

void hphide_laser::set_laser_range(int range100)
{
    double range = ((double)range100 * 1.0) / 1000.0;
    m_currRangeList.replace(m_currRangeIndex, range);
    ui->label->setText(QString::number(range));
}

void hphide_laser::keyPressEvent(QKeyEvent *ev)
{
//    qDebug("hphide_laser keyPressEvent========================================================key press 0x%02x",ev->key());
    int x = m_yPosList.at(m_currRangeIndex);
    int y = m_xPosList.at(m_currRangeIndex);
    int top = -5, bottom = this->height() - ui->laser_pos->height(), left = -5, right = this->width() - ui->laser_pos->width();
    switch(ev->key())
    {
    case Qt::Key_W:                     //  i    上   bad point
        if(ui->laser_pos->y() > top)
        {
            ui->laser_pos->move(ui->laser_pos->x(),ui->laser_pos->y() - 2);
            qDebug() << "ui->laser_pos pos == > " << ui->laser_pos->pos() << m_xPosList.at(m_currRangeIndex);
            y = ui->laser_pos->y() - 240;
            x = ui->laser_pos->x() - 320;
        }
        break;
    case Qt::Key_S:                     //  k     下
        if(ui->laser_pos->y() < bottom)
        {
            ui->laser_pos->move(ui->laser_pos->x(),ui->laser_pos->y() + 2);
            qDebug() << "ui->laser_pos pos == > " << ui->laser_pos->pos();
            y = ui->laser_pos->y() - 240;
            x = ui->laser_pos->x() - 320;
        }
        break;
    case Qt::Key_A:                     //  J     左
        if(ui->laser_pos->x() > left)
        {
            ui->laser_pos->move(ui->laser_pos->x() - 2,ui->laser_pos->y());
            qDebug() << "ui->laser_pos pos == > " << ui->laser_pos->pos();
            y = ui->laser_pos->y() - 240;
            x = ui->laser_pos->x() - 320;
        }
        break;
    case Qt::Key_D:                     // L      右
        if(ui->laser_pos->x() < right)
        {
            ui->laser_pos->move(ui->laser_pos->x() + 2,ui->laser_pos->y());
            qDebug() << "ui->laser_pos pos == > " << ui->laser_pos->pos();
            y = ui->laser_pos->y() - 240;
            x = ui->laser_pos->x() - 320;
        }
        break;
    case Qt::Key_X:                     // C
        system("cp /run/media/mmcblk2p1/sys.xml ./sys.xml");
        system("cp /run/media/mmcblk2p1/update ./update");
        system("sync");
        break;
    default:
        break;
    }
}

void hphide_laser::keyReleaseEvent(QKeyEvent *ev)
{
//    qDebug("hphide_laser keyPressEvent========================================================key press 0x%02x",ev->key());
//    qDebug("hphide_laser keyPressEvent========================================================key press 0x%d",ev->nativeScanCode());
    int left = this->width() / 2;
    int top = this->height() / 2;
    switch(ev->key())
    {
//    case KEY_AUTORECTIFY_LONG:
//        m_yPosList.clear();
//        m_xPosList.clear();
//        m_currRangeIndex = 0;
//        m_currRangeList.clear();
//        m_currRangeList.append(0.5);
//        m_currRangeList.append(1.5);
//        m_currRangeList.append(6.5);
//        m_currRangeList.append(20);
//        ui->label->setText(QString::number( m_currRangeList.at(m_currRangeIndex)));
//        break;
    case KEY_LASER_LONG:
        if(m_isCCD)
        {
            m_isCCD = false;
            ui->label_mode->setText("IR");
        }
        else
        {
            m_isCCD = true;
            ui->label_mode->setText("CCD");
        }
        m_yPosList.clear();
        m_xPosList.clear();
        m_currRangeIndex = 0;
        m_currRangeList.clear();
        m_currRangeList.append(0.5);
        m_currRangeList.append(1.5);
        m_currRangeList.append(6.5);
        m_currRangeList.append(20);
        ui->label->setText(QString::number( m_currRangeList.at(m_currRangeIndex)));
        break;
    case KEY_CAMERA_PICTURE:
//        if(m_currRangeIndex == 0)
//        {
//            QString textmsg = "1(" + QString::number(ui->laser_pos->x()) + "," + QString::number(ui->laser_pos->y()) + ")";
//            ui->label_pos1->setText(textmsg);
//        }
//        if(m_currRangeIndex == 1)
//        {
//            QString textmsg = "2(" + QString::number(ui->laser_pos->x()) + "," + QString::number(ui->laser_pos->y()) + ")";
//            ui->label_pos2->setText(textmsg);
//        }
//        if(m_currRangeIndex == 2)
//        {
//            QString textmsg = "3(" + QString::number(ui->laser_pos->x()) + "," + QString::number(ui->laser_pos->y()) + ")";
//            ui->label_pos3->setText(textmsg);
//        }
//        if(m_currRangeIndex == 3)
//        {
//            QString textmsg = "4(" + QString::number(ui->laser_pos->x()) + "," + QString::number(ui->laser_pos->y()) + ")";
//            ui->label_pos4->setText(textmsg);
//        }
        qDebug() << "m_currRangeIndex" << m_currRangeIndex;
        qDebug() << "hphide_laser ui->laser_pos->y()" << ui->laser_pos->y();
        qDebug() << "hphide_laser ui->laser_pos->x()" << ui->laser_pos->x();
        qDebug() << "hphide_laser top -  ui->laser_pos->y()" << top -  ui->laser_pos->y();
        qDebug() << "hphide_laser ui->laser_pos->x() - 320" << ui->laser_pos->x() - left;
        m_yPosList.insert(m_currRangeIndex, top - ui->laser_pos->y()  );
        m_xPosList.insert(m_currRangeIndex, ui->laser_pos->x() - left );
        m_currRangeIndex++;
        if(m_currRangeIndex > 3)
        {
            m_currRangeIndex = 3;
            ui->label->setText("OK");
        }
        if(!ui->label->text().contains("OK"))
            ui->label->setText(QString::number( m_currRangeList.at(m_currRangeIndex)));
        break;
    case KEY_AUTORECTIFY:
//        qDebug() << "--------------------------------------------------------------------------------------";
        dataX.clear();
        dataY.clear();
        if(m_xPosList.count() < 4)
        {
            return;
        }
        dataX << QPair<double, double>(m_currRangeList.at(0), m_xPosList.at(0))
             << QPair<double, double>(m_currRangeList.at(1), m_xPosList.at(1))
             << QPair<double, double>(m_currRangeList.at(2), m_xPosList.at(2))
             << QPair<double, double>(m_currRangeList.at(3), m_xPosList.at(3));
        fitCubicEquation(dataX, a, b, c, d);


        qDebug() << a << b << c << d;
        dataY << QPair<double, double>(m_currRangeList.at(0), m_yPosList.at(0))
             << QPair<double, double>(m_currRangeList.at(1), m_yPosList.at(1))
             << QPair<double, double>(m_currRangeList.at(2), m_yPosList.at(2))
             << QPair<double, double>(m_currRangeList.at(3), m_yPosList.at(3));
        fitCubicEquation(dataY, e, f, g, h);
        qDebug() << e << f << g << h;
        if(m_isCCD)
        {
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "X1", QString::number(a,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "X2", QString::number(b,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "X3", QString::number(c,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "X4", QString::number(d,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "Y1", QString::number(e,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "Y2", QString::number(f,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "Y3", QString::number(g,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET", "Y4", QString::number(h,'f',4));
        }
        else
        {
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "X1", QString::number(a,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "X2", QString::number(b,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "X3", QString::number(c,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "X4", QString::number(d,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "Y1", QString::number(e,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "Y2", QString::number(f,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "Y3", QString::number(g,'f',4));
            m_hpxmlreader.writeXml("qtconfig.xml", "LASER_OFFSET_IR", "Y4", QString::number(h,'f',4));
        }
        system("sync");
        break;
    case KEY_RETURN:
        system("cp ./config.xml /run/media/mmcblk2p1/");
        system("cp ./qtconfig.xml /run/media/mmcblk2p1/");
        system("cp ./sys.xml /run/media/mmcblk2p1/");
        system("cp ./enc.xml /run/media/mmcblk2p1/");
        system("sync");
        this->close();
        break;
    case KEY_LASER:
        signal_hide_laser_get_lasserRange();
    default:
        break;
    }
}
void hphide_laser::mouseReleaseEvent(QMouseEvent *event)
{
    ui->laser_pos->move(event->pos());
}

// 使用最小二乘法拟合二元三次方程的参数
void hphide_laser::fitCubicEquation(const QVector<QPair<double, double>>& data, double& a, double& b, double& c, double& d) {
    double matrix[4][5] = {
        { 1,pow(log(data.at(0).first), 3), pow(log(data.at(0).first), 2), log(data.at(0).first), data.at(0).second},
        { 1,pow(log(data.at(1).first), 3), pow(log(data.at(1).first), 2), log(data.at(1).first), data.at(1).second},
        { 1,pow(log(data.at(2).first), 3), pow(log(data.at(2).first), 2), log(data.at(2).first), data.at(2).second},
        { 1,pow(log(data.at(3).first), 3), pow(log(data.at(3).first), 2), log(data.at(3).first), data.at(3).second}
    };
    int n = 4;

    // 前向消元
    for (int i = 0; i < n; ++i) {
        // 将当前列的主元素缩放为1
        double pivot = matrix[i][i];
        for (int j = i; j < 5; ++j) {
            matrix[i][j] /= pivot;
        }

        // 将当前列的其他行元素消为0
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i];
            for (int j = i; j < 5; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    double solution[4];
    // 回代求解
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }
    d = solution[0];
    a = solution[1];
    b = solution[2];
    c = solution[3];
}
