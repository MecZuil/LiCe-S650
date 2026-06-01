#ifndef HP_PMS_H
#define HP_PMS_H

#include <QFile>
#include <QPainter>
#include <QWidget>
#include <QKeyEvent>
#include <QScrollBar>
#include <QListWidget>
#include <QDomDocument>
#include <QApplication>
#include <QStyleOptionButton>
#include <QStyledItemDelegate>
#include "hi384_protocol.h"
#include "hpxmlreader.h"

namespace Ui {
class hp_pms;
}

// 测试点结构体
struct TestPoint {
    QString name;
    QString id;
    QString part;
    QString sn;
    void clear(){
        part.clear();
        name.clear();
        id.clear();
        sn.clear();
    }
};

// 间隔结构体
struct Clearance {
    QString name;
    QString id;
    QString sn;
    QList<TestPoint> testPoints;
    void clear(){
        testPoints.clear();
        name.clear();
        id.clear();
        sn.clear();
    }
};

// 子任务结构体
struct SubTask {
    QString name;
    QString id;
    QList<Clearance> clearances;
    void clear(){
        clearances.clear();
        name.clear();
        id.clear();
    }
};

// 主任务结构体
struct MainTask {
    QString name;
    QString id;
    QList<SubTask> subTasks;
    void clear(){
        subTasks.clear();
        name.clear();
        id.clear();
    }
};

struct TestPointSnId {
    QString id;
    QString clearanceSn;  // 间隔SN
    QString pointSn;     // 测点SN
};


class RightCheckBoxDelegate : public QStyledItemDelegate {
public:
    // 自定义数据角色：控制是否显示CheckBox（用户可自由定义）
    enum CustomRoles {
        ShowCheckBoxRole = Qt::UserRole + 100
    };

    explicit RightCheckBoxDelegate(int checkSize = 40, QObject *parent = nullptr)
        : QStyledItemDelegate(parent), m_checkSize(checkSize) {}

    void setCheckBoxSize(int checkSize)
    {
        if(checkSize > 0 && checkSize < 200)
            m_checkSize = checkSize;
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
              const QModelIndex &index) const override {
        // 1. 绘制默认内容（文本/图标等）
        QStyledItemDelegate::paint(painter, option, index);

        // 2. 根据数据决定是否绘制CheckBox
        if (index.data(ShowCheckBoxRole).toBool()) {
            QRect checkRect = getCheckBoxRect(option.rect);
            drawCheckBox(painter, checkRect, index.data(Qt::CheckStateRole).toBool());
        }
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                    const QStyleOptionViewItem &option, const QModelIndex &index) override {
        // 只处理需要CheckBox的Item
        if (!index.data(ShowCheckBoxRole).toBool())
            return QStyledItemDelegate::editorEvent(event, model, option, index);

        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QRect checkRect = getCheckBoxRect(option.rect);

            if (checkRect.contains(mouseEvent->pos())) {
                // 切换选中状态
                Qt::CheckState newState = (index.data(Qt::CheckStateRole).toBool() ?
                                           Qt::Unchecked : Qt::Checked);
                model->setData(index, newState, Qt::CheckStateRole);
                return true; // 阻断事件传递
            }
        }
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

private:
    int m_checkSize;

    QRect getCheckBoxRect(const QRect &itemRect) const {
        return QRect(
            itemRect.right() - m_checkSize - 5,
            itemRect.top() + (itemRect.height() - m_checkSize)/2,
            m_checkSize,
            m_checkSize
        );
    }
    void drawCheckBox(QPainter *painter, const QRect &rect, bool checked) const {
        painter->save();
        QPen borderPen(Qt::white, 2);
        painter->setPen(borderPen);
        painter->drawRoundedRect(rect.adjusted(1,1,-1,-1), 3, 3);  // 向内缩进1像素避免边缘裁切

        // 绘制勾选状态
        if(checked) {
            QPainterPath checkPath;
            checkPath.moveTo(rect.left() + rect.width()*0.3, rect.top() + rect.height()*0.5);
            checkPath.lineTo(rect.left() + rect.width()*0.45, rect.top() + rect.height()*0.7);
            checkPath.lineTo(rect.left() + rect.width()*0.7, rect.top() + rect.height()*0.3);

            QPen checkPen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap);
            painter->setPen(checkPen);
            painter->drawPath(checkPath);
        }
        painter->restore();
    }
};
class hp_pms : public QWidget
{
    Q_OBJECT
public:
    explicit hp_pms(QWidget *parent = 0);
    ~hp_pms();
    void hp_setS3X0(bool isS3X0);
    void hp_setMainTaskNameText(QString str);
    void hp_setSubTaskNameText(QString str);
    void hp_setClearNameText(QString str);
    void hp_setText(QStringList list);
    void hp_clearListWidget();
    bool hp_parseTask(QString xmlFilePath);
    bool hp_parseXmlFile(const QString &filePath, MainTask &mainTask);
    void hp_sortTestPoints(QList<TestPoint>& testPoints);
    void hp_sortClearances(QList<Clearance>& clearances);
    void hp_createModifiedXml(const QString& outputPath);
    void hp_setListWidgetIndex(int index);
    void hp_getCurrClearancePointName(QString &clearance, QString &point);
    void hp_getCurrClearancePointId(QString &clearanceId, QString &pointId);
    void hp_getCurrClearanceSn(QString &clearanceSn, QString &pointSn);
    MainTask hp_getMainTask();
    QString hp_getCurrTestpointId();
    QMap<int, bool> hp_getCurrSelectMap();

    int  hp_getTitleIndex();
    int  hp_getNowIndex();

signals:
    void signal_selectChanged(int index);
    void signal_close_pms();
    void signal_take_picture();
    void signal_set_focus();
    void signal_upload_pms_dat();
    void signal_relink_last_ble_server();

public slots:

private slots:
    void m_hpListWidget_currentChanged(int currentRow);
    void on_toolButton_clicked();

    void on_pms_upload_clicked();

    void on_listWidget_itemChanged(QListWidgetItem *item);

    void on_pms_upload_2_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    Ui::hp_pms *ui;
    int           m_currCapRow;
    int           m_nextCapRow;
    int           titleindex;
    int           nowindex;
    bool          isInAddItem;
    bool          m_isDefine5_5;
    int           m_lastTitleIndex;
    QString       m_currTestPointId;
    MainTask      m_mainTaskMsg;
    QStringList   m_mainTaskIdList;
    QStringList   m_mainTaskSnList;
    QList<int>    m_titleindexList;//标题数量MainTaskName、SubTaskName、ClearName都属于标题
    QMap<int, bool> m_itemIndexSelectMap;
    QMap<int, bool> m_itemIndexPhotoMap;
    QMap<QString, QString> m_testpointIdSnMap;
    QMap<QString, int> m_testpointIdItemMap;
    QList<TestPointSnId> m_testpointSnIdList;
    QStringList m_testpointIdSortList;
};

#endif // HP_PMS_H
