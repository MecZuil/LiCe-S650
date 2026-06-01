#ifndef TASKPKG_H
#define TASKPKG_H

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 *
 * @ description : 作业包模块动态库
 *
 * @ author      : 王颢博
 *
 * @ date        : 2022/04/15
 *
 * @ comment     : 预览图片时,底层会重新生成重命名前的图片,需要在切换或关闭当前
 *                 图片预览时进行收到删除
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <QObject>
#include <QDebug>
#include <QMetaType>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickWidget>
#include <QTextCodec>
#include <QEventLoop>
#include <QTextCodec>
#include <QFile>
#include <QVector>
#include <QByteArray>
#include <QMutex>
#include <QMutexLocker>
#include <QImage>
#include <QSemaphore>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hp_task_formula.h"
#include "hp_statement.h"
#include "hi384_protocol.h"
#include "machine/qml-port.h"
#include "machine/change-model.h"
#include "machine/file-list.h"
#include "machine/folder-list.h"
#include "machine/xml-list.h"
#include "machine/setting_conf.h"

#include "analysis/createthread.h"


class Hp_TaskPkg : public QObject
{
    Q_OBJECT
public:
    static Hp_TaskPkg* getInstance(){
        if(m_instance == nullptr) {
            QMutexLocker locker(&m_mutex);
            if(m_instance == nullptr) {
                m_instance = new Hp_TaskPkg();
            }
        }
        return m_instance;
    }
    ~Hp_TaskPkg();

    int taskPkg_init(SCREEN_SIZE id);

    /* 1. 打开作业包界面 */
    int Open_Dlg();
    /* 2. 关闭作业包界面 */
    int Close_Dlg();
    /* 3. 逐级返回界面 */
    int GoBack_Dlg();
    /* 4. 图片文件重命名 */
    int Rename_Img(QString &fileName, int videoMode, QVector<ANA_OUTLINE>tempInfos);
    /* 5. 获取当前活跃界面名 */
    int Get_CurrentDlg(QString &dlgName);
    /* 6. 拍照结果分析计算 */
    int Cal_TaskWarning(QVector<ANA_OUTLINE> ana_infos, float env_temp, QString &flag, QString &title, QString &text, int &err_id);
    /* 7. 设置拍摄界面控件使能状态 */
    int Enable_TreeView(bool enable);
    /* 8. 图片轮廓处理 */
    int Bmp2Png(QImage &img);
    /* 9. 界面移动 */
    int Move_MessageDialog(int x, int y);
    int Move_MessageBox(int x, int y);
    /* 10. 事件捕获 */
    void hp_InstallEventFilter(QObject *o);
    /* 11. 跳转至指定索引 */
    int Dump_to_index_by_name(QString strDevName);
    /* 12. 从外部跳转至作业包 */
    int Dump_to_task_by_name_extend(QString strDevName);
    /* 13. 设置SD卡路径 */
    int set_SDPath(QString strPath);

    /* 13. 键值设置 */
    int set_key_value_to_up(int value);
    int set_key_value_to_down(int value);
    int set_key_value_to_left(int value);
    int set_key_value_to_right(int value);
    int set_key_value_to_center(int value);
    int set_key_value_to_return(int value);

    void test();

protected:

private:
    Hp_TaskPkg(QObject *parent = 0);
    static QMutex m_mutex;
    static Hp_TaskPkg *m_instance;

    QString m_strSDPath;

    int m_screen_id;
    int m_hasInit;

    QString m_save_imgName;
    QVector<ANA_OUTLINE> m_save_anaInfos;

    hp_task_formula* m_p_formula;
    QmlPort* m_p_qmlPort;
    FileList* file_list;
    FolderList* folder_list;
    XmlList* xml_list;
    Setting_Conf m_setting;

    QQuickWidget* m_p_TaskSelectQWidget;
    QQuickWidget* m_p_MessageBoxQWidget;
    QQuickWidget* m_p_MessageDialogQWidget;
    QQuickWidget* m_p_TreeViewQWidget;
    QQuickWidget* AnalysisChartQWidget;
    QQuickWidget* m_p_InteractionQWidget;
    QObject* m_p_DialogObject;
    QObject* m_p_MessageBoxObject;

    QSemaphore *m_sem_taskTree;

    createThread* mp_analyOP;

    QVector<ANA_OUTLINE> m_v_anaInfos;
    bool m_b_qml_status;
    bool tree_start_status;
    bool m_b_jumpFlag;
    int m_n_videoMode;
    int tree_index;

    QMap<QString, int> m_mapDevices;

    void Init_MessageDialogQWidget();
    void Init_SelectTaskQWidget();
    void Init_MessageBoxQWidget();
    void Init_TreeViewQWidget();
    void check_taskPkg_analysis();
    void InitAnalysisView();

    void delaymsec(int msec);

signals:
    /* 11. 信号 通知作业包已关闭 */
    void Signal_CloseDlg();
    /* 12. 信号 通知轮廓文件及分析底线框 */
    void Signal_ChangeAnaInfo(QString bmp, QVector<ANA_OUTLINE> ana_infos);
    /* 13. 信号 显示作业包选择界面 */
    void Signal_Show_TaskSelect();
    /* 14. 信号 显示设备拍摄界面 */
    void Signal_Show_TreeView();
    /* 15. 信号 显示拍摄恢复提示界面 */
    void Signal_Show_MessageBox();
    /* 16. 信号 显示SD卡提示界面 */
    void Signal_Show_MessageDialog();
    /* 17. 信号 显示统计折线界面 */
    void Signal_Show_AnalysisChart();
    /* 18. 信号 通知上层删除文件 */
    void Signal_Remove_File(QString strFileName);
    /* 19. 信号 拍摄树展开时发送当前打开的xml */
    void Signal_get_select_xml(QString fileName);

public slots:

private slots:
    void Slot_ReturnHandle();
    void Slot_InitTreeView();
    void Slot_InitTaskSelect();
    void Slot_OutlineTreeList(QStringList s_outline_fn_list, QStringList s_ana_list);

    void slot_delete_table_analysis(QString tableName);
    void slot_insert_table_analysis(QString tableName);
    void slot_save_temp_analysis(QString imgName, QVector<ANA_OUTLINE>tempInfos);
    void SlotInitHistory();
    void SlotRetureTree();
    void SlotReturnFormTree();
    void SlotLoadHistory();
    void Slot_task_load();
    void SlotcreateFinish();
    void Slot_selectXml();
    void Slot_reset_sel_flag();

    void slot_interaction_show();
    void slot_interaction_sure_click();
    void slot_interaction_cancel_click();

    void slot_start_sel_taskTree();
};


#endif // TASKPKG_H
