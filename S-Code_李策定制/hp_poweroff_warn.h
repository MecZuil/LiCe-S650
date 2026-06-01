#ifndef HP_POWEROFF_WARN_H
#define HP_POWEROFF_WARN_H

#include  <QWidget>
#include  "hpxmlreader.h"

namespace Ui {
class HP_Poweroff_Warn;
}

class HP_Poweroff_Warn : public QWidget
{
    Q_OBJECT

public:
    explicit HP_Poweroff_Warn(QWidget *parent = 0);
    ~HP_Poweroff_Warn();
    bool battery_warn_state;

    void hp_setDefine_S3x0(bool isSelect);
public slots:
    void chongdian_on_toolButton_clicked();
private slots:
    void on_toolButton_clicked(bool checked);

private:
    Ui::HP_Poweroff_Warn *ui;
    void changeEvent(QEvent *e);

    HpXmlReader hpxmlreader;

protected:

    virtual void keyReleaseEvent(QKeyEvent *ev);

};

#endif // HP_POWEROFF_WARN_H
