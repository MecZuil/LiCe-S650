#include "hp_createpdf.h"
#include "ui_hp_createpdf.h"

Hp_CreatePDF::Hp_CreatePDF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hp_CreatePDF)
{
    ui->setupUi(this);
    m_curDatFileDateTime = 20250520115431;
}

Hp_CreatePDF::~Hp_CreatePDF()
{
    delete ui;
}
void Hp_CreatePDF::set_taisu_pdf_create_report(QString fileName)
{
    qDebug() << __func__ << __LINE__ << "fileNAme" << fileName;
    hp_gw_img_read(fileName, fileName);
    QFile pdfFile("hp_pdf.pdf");
    pdfFile.open(QIODevice::WriteOnly);

    QPdfWriter pdfWriter(&pdfFile);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(76);
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20));

    QPainter painter;

    m_ccdFilePath  = "ccd.jpg";
    m_irFilePath = "ir.jpg";
    //获取可见光
    QString s_text = m_text;
    //获取注释

    QString strHtml = get_taisu_pdf_html();

    if(!painter.begin(&pdfWriter)) {
        qDebug() << "set_taisu_pdf_create_report begin failed ";
    }


    QTextDocument text_document;
    text_document.setPageSize(QSizeF(630, 851));
    text_document.setHtml(strHtml);
    text_document.drawContents(&painter, QRectF(0, 0, 630, 851));
    text_document.end();

//    system("cp hp_pdf.pdf /run/media/mmcblk2p1/");
    qDebug() << "set_taisu_pdf_create_report end ";
}

QString Hp_CreatePDF::get_taisu_pdf_html()
{
    // 加载图片并转换为 Base64
    QImage image(m_irFilePath);
    if (image.isNull()) {
        qDebug() << "Error: Cannot load image!";
        return "";
    }

    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    if (!image.save(&buffer, "PNG")) {
        qDebug() << "Error: Failed to save image to buffer!";
        return "";
    }
    QString imageBase64 = "data:image/png;base64," + ba.toBase64();


    QImage image2(m_ccdFilePath);
    if (image2.isNull()) {
        qDebug() << "Error: Cannot load image2!";
        return "";
    }

    QByteArray ba2;
    QBuffer buffer2(&ba2);
    buffer2.open(QIODevice::WriteOnly);
    if (!image2.save(&buffer2, "PNG")) {
        qDebug() << "Error: Failed to save image to buffer2!";
        return "";
    }
    QString imageBase642 = "data:image/png;base64," + ba2.toBase64();
    QString strHtml = nullptr;
    strHtml =  "<html>";
    strHtml += "<head>";
    strHtml += "    <title>热成像检测报告</title>";
    strHtml += "    <style>";
    strHtml += "        body {";
    strHtml += "            font-family: Arial, sans-serif;";
    strHtml += "            font-size: 12px;";  // 全局基础字体调小
    strHtml += "            margin: 10px;";    // 边距调小
    strHtml += "            color: #333;";
    strHtml += "            line-height: 1.3;";
    strHtml += "        }";
    strHtml += "        @page {";
    strHtml += "            size: A4;";
    strHtml += "            margin: 10mm;";
    strHtml += "        }";
    strHtml += "        .container {";
    strHtml += "            display: flex;";
    strHtml += "            gap: 12px;";       // 间距调小
    strHtml += "        }";
    strHtml += "        .left-column {";
    strHtml += "            flex: 1;";
    strHtml += "            min-width: 0;";
    strHtml += "        }";
    strHtml += "        .right-column {";
    strHtml += "            flex: 1;";
    strHtml += "            min-width: 0;";
    strHtml += "            display: flex;";
    strHtml += "            flex-direction: column;";
    strHtml += "            align-items: center;";
    strHtml += "        }";
    strHtml += "        .header {";
    strHtml += "            text-align: center;";
    strHtml += "            margin-bottom: 12px;";
    strHtml += "        }";
    strHtml += "        .header h1 {";
    strHtml += "            color: #0066cc;";
    strHtml += "            font-size: 12px;";  // 标题调小
    strHtml += "            margin-bottom: 2px;";
    strHtml += "        }";
    strHtml += "        .header .subtitle {";
    strHtml += "            color: #666;";
    strHtml += "            font-size: 10px;";   // 副标题调小
    strHtml += "        }";
    strHtml += "        table {";
    strHtml += "            width: 100%;";
    strHtml += "            border-collapse: collapse;";
    strHtml += "            margin-bottom: 12px;";
    strHtml += "            font-size: 11px;";   // 表格字体调小
    strHtml += "        }";
    strHtml += "        th, td {";
    strHtml += "            border: 1px solid #ddd;";
    strHtml += "            padding: 4px;";     // 内边距调小
    strHtml += "            text-align: left;";
    strHtml += "        }";
    strHtml += "        th {";
    strHtml += "            background-color: #f2f2f2;";
    strHtml += "        }";
    strHtml += "        .img {";
    strHtml += "            width: 100%;";      // 宽度自适应
    strHtml += "            max-width: 270px;"; // 最大宽度限制
    strHtml += "            height: 180px;";    // 高度调小
    strHtml += "            margin: 6px 0;";    // 边距调小
    strHtml += "            border: 1px solid #ddd;";
    strHtml += "            display: flex;";
    strHtml += "            object-fit: contain;";
    strHtml += "            align-items: center;";
    strHtml += "            justify-content: center;";
    strHtml += "            color: #666;";
    strHtml += "            font-size: 10px;";   // 占位文字调小
    strHtml += "        }";
    strHtml += "        .footer {";
    strHtml += "            position: absolute;";
    strHtml += "            bottom: 10px;"; // 距离底部 10px
    strHtml += "            width: 100%;";
    strHtml += "            font-size: 9px;";
    strHtml += "            color: #999;";
    strHtml += "            text-align: center;";
    strHtml += "        }";
    strHtml += "    </style>";
    strHtml += "</head>";
    strHtml += "<body>";
    strHtml += "    <div class=\"header\">";
    strHtml += "        <h1>热成像检测报告</h1>";
    strHtml += "        <div class=\"subtitle\">专业温度分析报告</div>";
    strHtml += "    </div>";
    strHtml += "          ";
    strHtml += "    <div class=\"container\">";
    strHtml += "        <div class=\"left-column\">";
    strHtml += "            <table>";
    strHtml += "                <tr>";
    strHtml += "                    <th>报告日期</th>";
    strHtml += "                    <td>2025/04/29 17:39:08</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>仪器类型</th>";
    strHtml += "                    <td>X630</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>序列号</th>";
    strHtml += "                    <td>X300-123456</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>测量模式</th>";
    strHtml += "                    <td>自动</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>距离</th>";
    strHtml += "                    <td>" + QString::number(m_ftDist) + "</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>大气温度</th>";
    strHtml += "                    <td>" + QString::number(m_ftEnvTemp) + "°C</td>";
    strHtml += "                </tr>";
    strHtml += "                <tr>";
    strHtml += "                    <th>发射率</th>";
    strHtml += "                    <td>" + QString::number(m_ftEmiss) + "</td>";
    strHtml += "                </tr>";
    strHtml += "            </table>";
    strHtml += "        </div>";
    strHtml += "";
    strHtml += "        <div class=\"right-column\">";
    strHtml += "            <div class=\"img\">";
    strHtml += "                <img src='" + imageBase64 + "' width='270' height='180'>";
    strHtml += "            </div>";
    strHtml += "            <div class=\"img\">";
    strHtml += "                <img src='" + imageBase642 + "' width='270' height='180'>";
    strHtml += "            </div>";
    strHtml += "        </div>";
    strHtml += "    </div>";
    strHtml += "";
    strHtml += "    <div class=\"footer\">";
    strHtml += "        <p>报告生成时间:" + QString::number(m_curDatFileDateTime) + "</p>";
    strHtml += "    </div>";
    strHtml += "</body>";
    strHtml += "</html>";

    return strHtml;
}

void Hp_CreatePDF::hp_gw_img_read(QString gwPath, QString gwFile)
{
    pms_ir_atlas_t atlas;
    QFile file(gwFile);
    if (!file.open(QIODevice::ReadWrite)) {
        qCritical() << "Failed to open file:" << file.errorString();
    }
    else
    {
        qDebug() << __func__ << __LINE__;
        qint64 read_size = file.read(reinterpret_cast<char*>(&atlas), sizeof(pms_ir_atlas_t));
        m_ftEmiss = atlas.ir_emissivity;
        m_ftDist  = atlas.ir_distance;
        m_ftEnvTemp = atlas.ir_ambient_temp;
        m_curDatFileDateTime = atlas.ir_atlas_capture_time;
        int ccdPictureOffset = 512 + atlas.temp_matrix_width * atlas.temp_matrix_height * 4;

        file.close();
        saveImageSegment(gwPath, ccdPictureOffset, atlas.ccd_picture_size, QString("ccd.jpg"));
        saveImageSegment(gwPath, ccdPictureOffset + atlas.ccd_picture_size, atlas.ir_picture_size, QString("ir.jpg"));
    }
}

bool Hp_CreatePDF::saveImageSegment(const QString& filePath, int startPos, int length, const QString& outputPath)
{
    qDebug() << __func__ << __LINE__;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败";
        return false;
    }

    qDebug() << __func__ << __LINE__;
    // 定位到指定起始位置
    if (!file.seek(startPos)) {
        qDebug() << "文件定位失败";
        file.close();
        return false;
    }
    // 定位到指定起始位置
    if (!file.seek(startPos)) {
        qDebug() << "文件定位失败";
        file.close();
        return false;
    }

    // 读取指定长度的二进制数据
    QByteArray imageData = file.read(length);
    file.close();

    // 验证数据长度
    if (imageData.size() != length) {
        qDebug() << "读取数据长度不匹配";
        return false;
    }

    // 检查JPG文件头标志(SOI标记)
    if (imageData.size() < 2 ||
        static_cast<uchar>(imageData[0]) != 0xFF ||
        static_cast<uchar>(imageData[1]) != 0xD8) {
        qDebug() << "无效的JPG文件头";
        return false;
    }

    // 写入输出文件
    QFile outFile(outputPath);
    if (!outFile.open(QIODevice::WriteOnly)) {
        qDebug() << "输出文件创建失败";
        return false;
    }

    if (outFile.write(imageData) != length) {
        qDebug() << "文件写入失败";
        outFile.close();
        return false;
    }

    outFile.close();
    return true;
}
