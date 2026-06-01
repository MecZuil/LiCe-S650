#ifndef HP_STATEMENT_H
#define HP_STATEMENT_H

#define DLG_NAME_TASKSELECT         "TaskSelect"
#define DLG_NAME_MESSAGEBOX         "MessageBox"
#define DLG_NAME_MESSAGEDIALOG      "MessageDialog"
#define DLG_NAME_TREEVIEW           "TreeView"
#define DLG_NAME_ANALYSIS           "AnalysisChart"

/*
 * @ description : 返回值
 */
typedef enum{
    RET_OK = 0,             //执行成功
    RET_IS_SHOW,            //当前界面已显示
    RET_FILE_ERR,           //图片文件不存在
    RET_RENAME_ERR,         //文件重命名执行失败
    RET_TREE_ERR            //拍摄界面未打开
}RET_FLAG;


/*
 * @ description : 分析测温参数
 */
typedef struct ana_outline{
    //int id;
    char ana_type[8];       //分析类型[0,2] : P=点, L=线, R=框
    int id;
    char deviceType[8];     //设备名称
    int origin_xcoord;      //x坐标 : 起点(左上角点)
    int origin_ycoord;      //y坐标 : 起点(左上角点)
    int dest_xcoord;        //x坐标 : 终点(右下角点)
    int dest_ycoord;        //y坐标 : 终点(右下角点)
    float maxtemp;          //最高温100倍
    float mintemp;          //最低温100倍
    float avgtemp;          //平均温100倍

    ana_outline() :
        id(-1),
        origin_xcoord(-1),
        origin_ycoord(-1),
        dest_xcoord(-1),
        dest_ycoord(-1),
        maxtemp(0),
        mintemp(0),
        avgtemp(0)
    {
    }
}ANA_OUTLINE;

/*
 * @ description : 保存的设备信息
 */
typedef struct ana_device{
    QString device_name;        //设备名称
    QString device_pos;         //设备相位

    ana_device() {}
    ana_device(QString name, QString pos)
    {
        this->device_name = name;
        this->device_pos = pos;
    }

    bool operator <(const ana_device &device) const
    {
        if(this->device_name.compare(device.device_name) < 0)
            return true;
        if(this->device_pos.compare(device.device_pos) < 0)
            return true;
        return false;
    }
}ANA_DEVICE;

#endif // HP_STATEMENT_H
