#ifndef FRMINPUT_H
#define FRMINPUT_H

#include  <QWidget>
#include  <QMouseEvent>
#include  <QLabel>
#include  <QLineEdit>
#include  <QComboBox>
#include  <QTextEdit>
#include  <QPlainTextEdit>
#include  <QTextBrowser>
#include  <QtSql>
#include  <QPushButton>
#include  <QTimer>
#include  <QShowEvent>
#include  <QMutexLocker>
#include  <sqlite3.h>
#include "ui_frminput.h"

namespace Ui
{
class frmInput;
}

class frmInput : public QWidget
{
    Q_OBJECT

public:
    explicit frmInput(QWidget *parent = 0, double gui_scale=1);
    ~frmInput();

    //单例模式,保证一个程序只存在一个输入法实例对象
    static frmInput *Instance(double gui_scale=1)
    {
        if (!_instance)
        {
            static QMutex mutex;
            QMutexLocker locker(&mutex);
            if (!_instance)
            {
                _instance = new frmInput(0, gui_scale);
            }
        }
        return _instance;
    }

    //初始化面板状态,包括字体大小
    void Init(QString position, QString style, int btnFontSize, int labFontSize);

    void ShowPanel();

    void setpage();
    void setpage2(QString name);
    void hp_setDefine_S3x0(bool isSelect);
    bool isDefine_S3x0;
    void setbtnTaskVisble(bool visble);
public slots:
    void gotoShadow(){hide(); emit sigHidden();}
    void slot_frminput_init();

signals:
    void sigShowed(QRect geometry);
    void sigHidden();
    void signalTask();
protected:
    //事件过滤器,处理鼠标在汉字标签处单击操作
    bool eventFilter(QObject *obj, QEvent *event);
    //鼠标拖动事件
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    //焦点改变事件槽函数处理
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);
    //输入法面板按键处理
    void btn_clicked();
    //改变输入法面板样式
    void changeStyle(QString topColor, QString bottomColor,
                     QString borderColor, QString textColor);
    //定时器处理退格键
    void reClicked();
/*
    void on_btn123_released();

    void on_btn123_2_released();

    void on_btn123_3_released();

    void on_btn123_4_released();

    void on_new_3_released();
*/
    void on_btnTask_clicked();

private:
    void setupUiLocal(QWidget *f, double gui_scale=1);
    Ui::frmInput *ui;
    static frmInput *_instance;     //实例对象

    int deskWidth;                  //桌面宽度
    int deskHeight;                 //桌面高度
    int frmWidth;                   //窗体宽度
    int frmHeight;                  //窗体高度

    QPoint mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool mousePressed;              //鼠标是否按下

    bool isPress;                   //是否长按退格键
    QPushButton *btnPress;          //长按按钮
    QTimer *timerPress;             //退格键定时器
    bool checkPress();              //校验当前长按的按钮

    bool isFirst;                   //是否首次加载
    void InitForm();                //初始化窗体数据
    void InitProperty();            //初始化属性
    void ChangeStyle();             //改变样式
    void ChangeFont();              //改变字体大小
    //void ShowPanel();               //显示输入法面板

    QWidget *old_Widget;            //zhi前焦点的对象
    QWidget *currentWidget;         //当前焦点的对象
    QLineEdit *currentLineEdit;     //当前焦点的单行文本框
    QTextEdit *currentTextEdit;     //当前焦点的多行文本框
    QPlainTextEdit *currentPlain;   //当前焦点的富文本框
    QTextBrowser *currentBrowser;   //当前焦点的文本浏览框

    QString currentEditType;        //当前焦点控件的类型
    QString currentPosition;        //当前输入法面板位置类型
    QString currentStyle;           //当前输入法面板样式
    int btnFontSize;                //当前输入法面板按钮字体大小
    int labFontSize;                //当前输入法面板标签字体大小
    void insertValue(QString value);//插入值到当前焦点控件
    void deleteValue();             //删除当前焦点控件的一个字符

    QString currentType;            //当前输入法类型
    void changeType(QString type);  //改变输入法类型
    void changeLetter(bool isUpper);//改变字母大小写

    QList<QLabel *>labCh;           //汉字标签数组

    QStringList currentPY;          //当前拼音链表
    int currentPY_index;            //当前拼音索引

    void selectChinese();           //查询汉字
    void showChinese();             //显示查询到的汉字
    void setChinese(int index);     //设置当前汉字
    void clearChinese();            //清空当前汉字信息

    sqlite3* db;

    int symbol_state;         //切换符号的是什么状态  0--->没有。 1--->由主菜单切换过去。 2--->由数字键盘切换过去
};

int callback(void*,int,char**,char**);
#endif // FRMINPUT_H
