#ifndef HP_HIR_PLAYER_H
#define HP_HIR_PLAYER_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include "hi384_protocol.h"

namespace Ui {
class hp_Hir_Player;
}

class hp_hir_player : public QWidget
{
    Q_OBJECT
public:
    explicit hp_hir_player(QWidget *parent = 0);
    ~hp_hir_player();
    Ui::hp_Hir_Player *ui;
    QTimer* playstatus;
//    QTimer* getmeasure;
    void Start_Hir_video(QString filename);
    void set_toolButton_pause_checked(bool checked);
    void hp_setDefine_S3x0(bool isSelect);
signals:
    void signal_core_analysis_hir_twice_start(char *name);
    void signal_core_annlysis_hir_twice_suspend(int type);
    void signal_core_analysis_hir_twice_stop_cut();
    void signal_start_hir_analyse(QString filename,bool checked);
    void signal_core_get_hir_play_status();
    void signal_playstatusTimeout();
    void signal_hir_analyse_get_measure();
    void signal_clear_measure();
protected:
    virtual void keyReleaseEvent(QKeyEvent *ev);
public slots:
    void on_toolButton_close_released();
    void slot_core_get_hir_play_status(unsigned char return_value, int value);
    void playstatusTimeout();
//    void getmeasureTimeout();
private slots:


    void on_toolButton_pause_clicked(bool checked);

    void on_toolButton_hir_analyse_released();

private:

    QString fileName;
    void changeEvent(QEvent *e);
};

#endif // HP_HIR_PLAYER_H
