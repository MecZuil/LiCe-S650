#ifndef HP_CREATEPDF_H
#define HP_CREATEPDF_H

#include <QWidget>
#include <QFile>
#include <QImage>
#include <QBuffer>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QTextDocument>
#include <QTextFrameFormat>
#include <QDateTime>
#include <QTextBlock>
#include <QPrinter>
#include "hi384_protocol.h"
#include "hp_file.h"
#include "pms_protocol_pkg.h"

#include "opencv2/opencv.hpp"

namespace Ui {
class Hp_CreatePDF;
}

class Hp_CreatePDF : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_CreatePDF(QWidget *parent = nullptr);
    ~Hp_CreatePDF();
    void set_taisu_pdf_create_report(QString fileName);

    void hp_gw_img_read(QString gwPath, QString gwFile);

    QString get_taisu_pdf_html();

    bool saveImageSegment(const QString& filePath, int startPos, int length, const QString& outputPath);
private:
    Ui::Hp_CreatePDF *ui;
    QString m_text;
    QString m_irFilePath;
    QString m_ccdFilePath;
    float m_ftEmiss;
    float m_ftDist;
    float m_ftEnvTemp;
    float m_ftRelHum;
    long long m_curDatFileDateTime;
};

#endif // HP_CREATEPDF_H
