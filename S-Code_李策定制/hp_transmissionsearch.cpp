#include "hp_transmissionsearch.h"
#include "ui_hp_transmissionsearch.h"

Hp_TransmissionSearch::Hp_TransmissionSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_TransmissionSearch)
{
    ui->setupUi(this);
    ui->label_5->close();
    m_bleNameMacAddr.clear();
    m_bleNameMacAddr.insert(QString("DULUN"), QString("6C2F80E41442"));
    m_bleNameMacAddr.insert(QString("DESKTOP_IT10289"), QString("CC15312C21B6"));
//    ui->pushButton_search->close();
}

Hp_TransmissionSearch::~Hp_TransmissionSearch()
{
    delete ui;
}

void Hp_TransmissionSearch::hp_setDefine_S3x0(bool isS3X0)
{
    qDebug() << ">> Hp_wait_warn::hp_setS3X0 <<";
    if(isS3X0)
    {
        QFont font11;
        font11.setPointSize(11);
        this->setGeometry(0,0,this->width() / 1.7,this->height() / 1.7);
        ui->label_4->setGeometry(ui->label_4->x() / 1.7,ui->label_4->y() / 1.7,ui->label_4->width() / 1.7,ui->label_4->height() / 1.7);
        ui->label_5->setGeometry(ui->label_5->x() / 1.7,ui->label_5->y() / 1.7,ui->label_5->width() / 1.7,ui->label_5->height() / 1.7);
        ui->toolButton_back->setGeometry(ui->toolButton_back->x() / 1.7,ui->toolButton_back->y() / 1.7,
                                         ui->toolButton_back->width() / 1.7,ui->toolButton_back->height() / 1.7);
        ui->listWidget_2->setGeometry(ui->listWidget_2->x() / 1.7,ui->listWidget_2->y() / 1.7,
                                    ui->listWidget_2->width() / 1.7,ui->listWidget_2->height() / 1.7);
        ui->pushButton_search->setGeometry(ui->pushButton_search->x() / 1.7,ui->pushButton_search->y() / 1.7,
                                    ui->pushButton_search->width() / 1.7,ui->pushButton_search->height() / 1.7);
        ui->pushButton_3->setGeometry(ui->pushButton_3->x() / 1.7,ui->pushButton_3->y() / 1.7,
                                    ui->pushButton_3->width() / 1.7,ui->pushButton_3->height() / 1.7);
        ui->pushButton_getXml->setGeometry(ui->pushButton_getXml->x() / 1.7,ui->pushButton_getXml->y() / 1.7,
                                    ui->pushButton_getXml->width() / 1.7,ui->pushButton_getXml->height() / 1.7);
        ui->label_4->setFont(font11);
        ui->label_5->setFont(font11);
        ui->toolButton_back->setFont(font11);
        ui->listWidget_2->setFont(font11);
        ui->pushButton_3->setFont(font11);
        ui->pushButton_search->setFont(font11);
        ui->pushButton_getXml->setFont(font11);
    }
}

void Hp_TransmissionSearch::on_listWidget_2_currentRowChanged(int currentRow)
{

}

void Hp_TransmissionSearch::slot_set_transmission_addr(QString addr)
{
    if(ui->listWidget_2->count() > 1)
        return;
    ui->listWidget_2->addItem(addr);
}

void Hp_TransmissionSearch::on_pushButton_3_clicked()
{
    if(ui->listWidget_2->count() != 0)
    {
        if(ui->listWidget_2->currentItem())
        {
            m_currMacAddr = ui->listWidget_2->currentItem()->text();
            m_currMacAddr = m_bleNameMacAddr.value(m_currMacAddr);
            qDebug() << __func__ << __LINE__ << m_currMacAddr;
            signal_link_transmission(m_bleNameMacAddr.value(m_currMacAddr));
        }
        else
        {
            m_currMacAddr = QString("6C2F80E41442");
            signal_link_transmission(QString("6C2F80E41442"));
        }
    }
}

void Hp_TransmissionSearch::on_toolButton_back_clicked()
{
    this->close();
}

void Hp_TransmissionSearch::on_pushButton_getXml_clicked()
{
    signal_start_get_xml();
}

void Hp_TransmissionSearch::on_pushButton_search_clicked()
{
    signal_get_ble_msg();
}

void Hp_TransmissionSearch::slot_get_ble_msg(QString addrs)
{
    qDebug() << __func__ << addrs;
    QStringList addrsLIst = addrs.split("\n");
    qDebug() << __func__ << " addrList" << addrsLIst;
    ui->listWidget_2->clear();
    m_bleNameMacAddr.clear();
    for(int i = 0; i < addrsLIst.count(); i++)
    {
        QString addrMac = addrsLIst.at(i);
        if(addrMac.contains(",") && addrMac.split(",").count() > 1)
        {
            QString currAddr = addrMac.split(",").at(0);
            QString currName = addrMac.split(",").at(1);
            m_bleNameMacAddr.insert(currName, currAddr);
            ui->listWidget_2->addItem(currName);
        }
    }
//    QMap<QString, QString>::const_iterator it = m_bleNameMacAddr.constBegin();
//    for(; it != m_bleNameMacAddr.constEnd(); it++)
//    {
//        QString name = it.key();
//        ui->listWidget_2->addItem(name);
//    }
//    ui->listWidget_2->setCurrentRow(0);
}
