#ifndef HP_SD_SPACE_WARNING_H
#define HP_SD_SPACE_WARNING_H

#include  <QWidget>
#include  <QTimer>

namespace Ui {
class Hp_Sd_Space_Warning;
}

class Hp_Sd_Space_Warning : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_Sd_Space_Warning(QWidget *parent = 0);
    ~Hp_Sd_Space_Warning();

    void warning(QString title,QString text);
    void setDelayClose(int ms);
    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void timer_finish();

private:
    Ui::Hp_Sd_Space_Warning *ui;
    void changeEvent(QEvent *e);
};

#endif // HP_SD_SPACE_WARNING_H
