#ifndef HP_HANDFUTION_H
#define HP_HANDFUTION_H

#include  <QWidget>

namespace Ui {
class Hp_HandFution;
}

class Hp_HandFution : public QWidget
{
    Q_OBJECT

public:
    explicit Hp_HandFution(QWidget *parent = 0);
    ~Hp_HandFution();

    bool set_current_index(int index);

    void hp_setDefine_S3x0(bool isSelect);
private slots:
    void on_toolButton_up_released();

    void on_toolButton_down_released();

    void slot_pc_sys_set_handfusion(unsigned char return_value);

signals:
    void current_index_changed(int index);
private:
    Ui::Hp_HandFution *ui;

    int current_row;
    QStringList list;

    void update_ui();
};

#endif // HP_HANDFUTION_H
