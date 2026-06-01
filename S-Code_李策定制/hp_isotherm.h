#ifndef HP_ISOTHERM_H
#define HP_ISOTHERM_H

#include  <QWidget>
#include  <QDebug>
#include  <QFile>

#include  <QTimer>
#include     <QListWidget>
#include  <QKeyEvent>
#include  "hi384_protocol.h"
#include  "hp_file.h"
#include  "hptempunitconvert.h"
#include  "hpxmlreader.h"
namespace Ui {
class hp_Isotherm;
}

class hp_Isotherm : public QWidget
{
    Q_OBJECT

public:
    explicit hp_Isotherm(QWidget *parent = 0);
    ~hp_Isotherm();
//    ComIsothermTemp Isotherm;
    void hp_setDefine_S3x0(bool isSelect);
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
    virtual bool eventFilter(QObject *w, QEvent *e);

signals:
   void signal_pc_image_set_Isotemp(ComIsothermTemp para);
public slots:
   void slot_pc_image_set_Isotherm(unsigned char return_value);
private slots:

   void on_listWidget_dengwense_currentRowChanged(int currentRow);

   void on_comboBox_dengwenwendu_valueChanged(double value);

   void on_comboBox_dengwengaodu_valueChanged(double value);

private:
    Ui::hp_Isotherm *ui;

    int tempunit;
    int  listwidget_type;
    ComIsothermTemp Isotherm;
    HpTempUnitConvert hptempunitconvert;
    HpXmlReader hpxmlreader;
    void para_init();
    void listwidget_drop_manage_dengwense(bool type);
    void changeEvent(QEvent *e);
};

#endif // HP_ISOTHERM_H
