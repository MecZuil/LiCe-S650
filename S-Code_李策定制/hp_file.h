/**********************************************************************************************

                  版本所有（C）, 浙江红谱科技有限公司

 **********************************************************************************************

  文 件 名     : ti_file.h
  生成日期     : 2017-11-1
  功能描述     :

 ***********************************************************************************************/

#pragma once

#include <stdio.h>
#include <stdint.h>


#define TDJPEGINFO_TAG	0x5A5A0A01					//拍照文件信息标记

#define FILEINFO_TAG		0x5A5A0C01				//文件信息标签
#define PRODUCT_TAG			0x5A5A0C02				//产品信息标签
#define COLORINFO_TRG		0x5A5A0C03				//颜色信息标签
#define ALGINFO_TAG			0x5A5A0C04				//图像处理信息标签
#define TEMPERINFO_TAG		0x5A5A0C05				//测温信息标签
#define ITEMDATA_TAG		0x5A5A0C06				//测温项数据标签

#define ITEM_POINT_TAG		0x5A5B0A01				//测温点数据标签
#define ITEM_LINE_TAG		0x5A5B0A02				//测温线数据标签
#define ITEM_RECT_TAG		0x5A5B0A03				//测温框数据标签
#define ITEM_CIRCLE_TAG		0x5A5B0A04				//测温圆数据标签
#define ITEM_POLYGON_TAG	0x5A5B0A05				//测温多边形数据标签

#define GRAYINFO_TAG		0x5B5B0C02				//原始信息标签
#define	CCDINFO_TAG			0x5B5B0C03				//可见光信息标签
#define	HSINFO_TAG			0x5B5B0C04				//高灵敏度灰度信息标签
#define VOICEINFO_TAG		0x5B5B0C05				//音频信息标签
#define TEXTINFO_TAG		0x5B5B0C06				//文本信息标签
#define SKETCHINFO_TAG		0x5B5B0C07				//草图信息标签
#define IMAGEGRAYINFO_TAG	0x5B5B0C08				//灰度图像信息标签

#define VERSIONINFO_HIR_TAG 0x5C5C3A4A				//修改灰度流录像帧大小
#define VERSIONINFO_TAG		0x5C5C4A4A				//图片版本标签
#define HANDLEINFO_TAG		0x5C5C0C0C				//PC处理图片标签

#define TAGNUM_TAG      	0x5A5A0D01 				//标签数量信息标签
#define RAWFILE_TAG     	0x5A5A0B01				//灰度头标签


#define PANORAMA_FILEINFO_TAG		0x6A6A0C01		//全景文件信息标签
#define PANORAMA_IMAGEINFO_TAG		0x6A6A0C02		//全景图像信息标签

#define POINT_POLYGON_NODE_NUM				20


#define RAW_FILE_VERSION  	"HP2.0.1"					//灰度相关文件版本号
#define FILE_VERSION		"HP3.0.1"					//文件版本号


typedef struct
{
    int nVirtualLenID;                 			//虚拟档位，调区号
    int nBaseTempStart;                			//ad.lua 中心段温度 开始
    int nBaseTempEnd;                  			//ad.lua 中心段温度 结束
    int nRangeSubFactNum;              			//当前量程分段系数,共几段
    float fRangeSubFact[3];                 	//当前量程分段系数,预留5段系数
    float fBenchmarkComTemp;	          		//当前基准温度补偿
    float fDistanceRepair;             			//距离补偿系数
}__attribute__ ((packed))LUA_PARA_t;


/* 测温参数结构 */
typedef struct tagMeasureTempPara
{
    float  fMeasureTempParaGroup[50];// 测温参数组
    float  fGrayScaleTable[20];//灰度差值表，实时变化

    union {
        float CH5_zero;// 探测器调零温度
        float f385DetectorTempZero;// 为了兼容性考虑，无名union相当于取了别名
    };

    LUA_PARA_t sLuaPara;//lua文件系数

    int nTempClass;// 测温档的实际值（0，1，2）+ 1
    int nLensID;// 镜头ID(+1)
    int nOpenMachineTimeLong;// 开机时长，以秒为单位

    int nLensTemp100;		// CH2	 	实时镜头温度
    int nShiderTemp100;		// CH1		实时挡片温度
    int nAmbientTemp100;	// CH4		实时环境温度
    int nCircuitTemp100;	// CH3		实时电路板温度
    int n385DetectorTemp100;// CH5

    int nDistance100;			// 距离的100倍
    int nNewReviseGray;			// 实时修正灰度以挡片为基准
    int nZeroParaA100;			// 系数，内部定值
    int nZeroParaB1000;			// 系数，内部定值
    int nHumidity100;			// 环境湿度100倍
    int nInterGray;				// 隐藏菜单修正灰度

    int nClassMinTemp;			// 测温档最低温
    int nClassMaxTemp;			// 测温档最高温
    int nBarrierGray;			// 挡片灰度, 调零时更新 （也就是平均灰度（FPGA对全图做平均得出））
    union {
        float CH1_zero;			// 挡片调零温度（调零时更新）
        float fShiderTempZero;
    };
    union {
        float CH2_zero;			//镜头调零温度（调零时更新）
        float fLensTempZero;
    };

    int nK2Class100;			//需要外部初始化定值100，似乎没用
    int nEmissivity100;			//辐射率100倍
    int nImagecode;				//图片分析模式
    int nTransmission100;		//透射率100倍
    int nAmbientTempManu100;	//环境温度100倍
    int nReflectTemp100;        //反射温度100倍
    union {
        float CH3_zero;			//内部电路调零温度（调零时更新）
        int  fCircuitTempZero;
    };
    union {
        float CH4_zero;			//腔体环境调零温度（调零时更新）
        float fAmbientTempZero;
    };

    int nVirtualLenID;			//挡位号(nTempClass-1+(nLensID-1)*rangenum)
    int f_LowTemp_sw;
    int f_HighTemp_sw;
    float g_ch1_first;
    float g_ch3_first;
    float fDist_ft_ld; 			//距离补偿计算参数
    float fDist_ft_hd;			//距离补偿计算参数
    float fDist_ft_ht1;			//距离补偿计算参数
    float fDist_ft_lt1;			//距离补偿计算参数
    float fDist_ft_ht2;			//距离补偿计算参数
    float fDist_ft_lt2;			//距离补偿计算参数
    int   nTempadjust100;
    int   nReserve[7];
} MeasureTempPara;

/* 区域参数的测温参数结构 */
typedef struct tagPOINT_Gray2Temp_t
{
    int	nX;			    //区域最高温点或者最低温点的X坐标
    int	nY;				//区域最高温点或者最低温点的Y坐标
    int	nGray;			//灰度值，最高、最低或者平均
    int	nTemp;			//温度值，最高、最低或者平均
    int nXMax;			//区域最高温点的X坐标
    int nYMax;			//区域最高温点的Y坐标
    int nGrayMax;		//区域最高灰度
    int nTempMax100;	//区域最高温100倍
    int nXMin;			//区域最低温点的X坐标
    int nYMin;			//区域最低温点的Y坐标
    int nGrayMin;		//区域最低灰度
    int nTempMin100;	//区域最低温度100倍
    int nGrayAve;		//区域平均灰度
    int nTempAve100;	//区域平均温度100倍
}POINT_Gray2Temp_t;



typedef struct tagPOINT_PARA_t
{
    int nID;   					//Qt记录的下标
    int nX;
    int nY;
    int bValid;					//是否有效添加	--- 新链表改版后该值含义无效，只要我们创建了节点就代表一定是有效的
    int bActive;				//测温点是否被激活，首次计算之后被激活
    int nEmissivity100;
    int nDistance100;    		//测温点距离值
    int nGray;
    int nTemp;

    int nradTable_switch;
    int nradTable_id;
    int nradTable_value100;
    int nradTable100;
    int nRealIndex;				/*对应的该测温点是第几个添加的*/
    char name[8];				//用于台账标记类型
    int nDirection; 			//3右上，2左上，1左下，0右下

    int nReserve[24];
} POINT_PARA_t;

typedef struct tagLINE_PARA_t
{
    int nStartX;						//起点X坐标
    int nStartY;						//起点Y坐标
    int nEndX;							//终点X坐标
    int nEndY;							//终点Y坐标
    int nID;							//测温线索引
    int bValid;							//测温线是否有效	--- 新链表改版后该值含义无效，只要我们创建了节点就代表一定是有效的
    int bActive;						//测温线是否被激活，首次计算之后被激活
    int nEmissivity100;					//测温线辐射率
    int nTempType;						//0最高温 1最低温 2平均温 3全选（最高 最低 平均）（3 & type所有温度）
    int nDistance100;					//距离
    int nReflectTemp100;				//反射温度
    int nradTable_switch;				//默认为0--->辐射率 。1--->辐射率表
    int nradTable_id;
    int nradTable_value100;
    int nradTable100;					//设置值
    POINT_Gray2Temp_t	sPointTemp;		//温度参数
    int nRealIndex;						/*对应的该测温线是第几个添加的*/
    char name[8];						//用于台账标记类型
    int nDirection; 					//3右上，2左上，1左下，0右下

    int nReserve[24];
} LINE_PARA_t;
/* 矩形参数 */
typedef struct tagRECT_PARA_t
{
    int nID;                            //id号
    int nStartX;                        //起点X坐标
    int nStartY;                        //起点Y坐标
    int nWidth;                         //测温区域宽
    int nHeight;                        //测温区域高
    int nRealIndex;                     /*对应的该测温矩形是第几个添加的*/
    int bValid;                         //测温区域是否有效  --- 新链表改版后该值含义无效，只要我们创建了节点就代表一定是有效的
    int bActive;                        //测温区域是否被激活，首次计算之后被激活
    int bRectMoveFlag;                  //0移动方位，1改变大小
    int nEmissivity100;                 //测温区域比辐射率
    int nDistance100;                   //距离
    int nReflectTemp100;                //反射温度
    int nTempType;                      //0最高温 1最低温 2平均温 3全选（最高 最低 平均）（3 & type所有温度）
    int nradTable_switch;               //默认为0--->辐射率 。1--->辐射率表。
    int nradTable_id;
    int nradTable_value100;
    int nradTable100;                   //设置值
    POINT_Gray2Temp_t   sPointTemp;     //温度参数
    char name[8];                       //用于台账标记类型
    int nDirection;                     //3右上，2左上，1左下，0右下
    int draw_reverse;                   //绘制反向
    short remapping_switch;             //重映射开关
    short remapping_color_id;           //重映射颜色ID
    int substation_type;                //变电设备类型

    int nReserve[22];
} RECT_PARA_t;


typedef struct tagCIRCLE_PARA_t
{
    int nX;								//id号
    int nY;
    int nR;
    int nDistance100;
    int nEmissivity100;
    int nReflectTemp100;				//反射温度
    int nTempType;

    unsigned char bActive;
    unsigned char bValid;					//--- 新链表改版后该值含义无效，只要我们创建了节点就代表一定是有效的
    unsigned char nID;
    unsigned char bRealIndex;				/*对应的该测温圆是第几个添加的*/

    unsigned char bradTable_switch;			//默认为0--->辐射率 。1--->辐射率表。
    unsigned char bradTable_id;
    unsigned char bradTable_value100;
    unsigned char bradTable100;

    unsigned char name[4];					//用于台账标记类型

    POINT_Gray2Temp_t	sPointTemp;

    int nDirection;                         //3右上，2左上，1左下，0右下
    int nReserve[25];
} CIRCLE_PARA_t;
/*多边形*/
typedef struct tagPOLYGON_PARA_t
{
    int nID;                          	//id号
    int nX[POINT_POLYGON_NODE_NUM];		//X坐标
    int nY[POINT_POLYGON_NODE_NUM];		//Y坐标
    int nNode;                			//节点个数
    int nRealIndex;						//测温索引
    int bupdate;						//多边形是否被更新
    int bActive;						//测温区域是否被激活，首次计算之后被激活
    int bPolygonMoveFlag;				//0移动方位，1改变大小
    int nEmissivity100;					//测温区域比辐射率

    int nDistance100;                  	//距离
    int nReflectTemp100;               	//反射温度
    int nTempType;						// 0最高温 1最低温 2平均温 （4 & type所有温度）
    short int nradTable_switch;      	//默认为0--->辐射率 。1--->辐射率表。
    short int nradTable_id;
    short int nradTable_value100;
    short int nradTable100;
    char name[8];						//用于台账标记类型
    int nDirection;                		//3右上，2左上，1左下，0右下
    int draw_reverse;					//绘制反向

    POINT_Gray2Temp_t	sPointTemp;

    int nReserve[10];
} POLYGON_PARA_t;
/* 参考参数,pc->dev */
typedef struct {
    int ReferType;			//使能，0关闭 1全局 2点测温 3:区域 4:线
    int nRefeTempID;
    int nTempType;			//测温类型  0:无 1:最高温 2:最低温 3:平均温
    int nRefeTemp100;		//全局参考温度100
}__attribute__ ((packed))temp_reference_para_t;

typedef struct {
    char bVaild;//是否存储
    int nID;//ID号
    int nQt_index;//qt的编号，以便update
}__attribute__ ((packed))MeasureArrayState;

typedef struct {
    MeasureArrayState array[100];
}__attribute__ ((packed))MeasureArray;

typedef struct
{
    int cmd_type;/*0-点 1-线 2-框 3-圆 4-多边形*/
    int id;
}__attribute__ ((packed))OP_DATA;


typedef struct temper_item_s {
    int nTag;								//测温项信息标签
    int nDesLen;							//结构长度
    int item_num;							//测温项数量
    int item_data_len;						//测温项数量大小 - 例如-点：sizeof(POINT_PARA_t)*point_num;
} temper_item_t;

typedef struct colornormal_s
{
    int iHue;
    int Saturation;
    int iBrightness;
} colornormal_t;

typedef struct colorhover_s
{
    int iHue;
    int Saturation;
    int iBrightness;
} colorhover_t;

typedef struct colorselect_s
{
    int iHue;
    int Saturation;
    int iBrightness;
} colorselect_t;

typedef struct fontset_s
{
    int FontSize;
    int FontBold; //1加粗， 0不加粗
    int FontItalics;//1斜体， 0不斜体
} fontset_t;

/*草图点坐标*/
typedef struct{
    short point_x;
    short point_y;
}sketch_point;
/*草图信息结构*/
typedef struct sketchinfo_s
{
    int nTag;
    int nDesLen;
    int nSketchLen;//为点数据字节数非点的个数
} sketchinfo_t;

/*文本信息结构*/
typedef struct textinfo_s
{
    int nTag;
    int nDesLen;
    int nTextLen;
} textinfo_t;

/*音频信息结构*/
typedef struct voiceinfo_s
{
    int nTag;
    int nDesLen;
    int nVoiceType;
    int nSampleFre;
    int nSampleBits;
    int nVoiceLen;
} voiceinfo_t;

typedef struct image_gray_info_s
{
    int nTag;
    int nDesLen;
    int nImageGrayW;
    int nImageGrayH;
    int nImageGrayBits;
    int nImageGrayAttr;
    int nImageGrayFrameNums;
    float fImageGrayFrameFreq;
    int nImageGrayLen;
} image_gray_info_t;

/* 原始灰度信息 */
typedef struct gray_info_s
{
    int nTag; 					  	//原始灰度信息标签 0x5A5A0C06
    int nDesLen;				  	//结构长度
    int nGrayImageW;				//原始灰度图像宽度
    int nGrayImageH;				//原始灰度图像高度
    int nGrayImageBits;				//原始灰度图像位宽
    int nGrayImageAttr;				//单幅，多幅，录像0,1,2
    int nGrayImageFrameNums;		//帧个数
    float fGrayImageFrameFreq;		//帧频
    int nGrayImageLen;				//原始灰度数据长度
} gray_info_t;

typedef struct {
    int lcd_pos_x;      //5.5寸的LCD和HDMI的偏移是X Y相反的
    int lcd_pos_y;      //HDMI的y永远比lcd的大60
    int hdmi_pos_x;     //设置偏移量时需要同时设置hdmi的偏移量
    int hdmi_pos_y;     //正常X600 X300的偏移是x：80 y：00 hmid_x:80 hdmi_y:60
} ti_pos;


typedef struct{
    int switch_value;/*1-开启客户端 0-关闭客户端*/
    int ServicePort;/*连接的服务器端口号*/
    char ServiceIP[16];/*连接的服务器IP*/
}client_para;
typedef struct{
    char ServiceUser[32];/*服务器用户名*/
    char ServicePassword[32];/*服务器用户密码*/
    char ServiceIP[16];/*连接的服务器IP*/
    int ServicePort;/*连接的服务器端口号*/
    int switch_value;/*1-开启客户端 0-关闭客户端*/
}server_para;
typedef struct{
    char ssid[32];//连接的网络名称
    char password[64];//连接网络的密码
    char switch_value;//是否连接  连接为1 关闭为0
}ap_para;
typedef struct{
    char cmd_para[20];
    char HostIP[16];
    char UserName[50];
    char Password[50];
    char FileName[200];
}ftp_para;
/* 可见光信息 */
typedef struct ccd_info_s
{
    int nTag; 				       	//可见光信息标签 0x5A5A0C07
    int nDesLen;				    //结构长度
    int nImageFormat;			  	//可见光数据格式
    int nVisualImageW;				//可见光图像宽度
    int nVisualImageH;				//可见光图像高度
    int nVisualImageBits;			//可见光图像位宽
    int nVisualImageAttr;			//单幅，多幅，录像0,1,2
    int nVisualImageFrameNums;		//帧个数
    float fVisualImageFrameFreq;	//帧频
    int nVisualImageLen;			//可见光数据长度
} ccd_info_t;

/* 文件信息结构 */
typedef struct file_info_s
{
    int nTag;					//文件信息标签 0x5A5A0201
    int nDesLen;				//结构长度
    char file_version[20];		//文件版本，"HP1.0.1"
    char CapTime[30];  			//拍摄时间
    char PicName[230];  		//图片名称
    char GPSLongitude[20];		//Gps经度
    char GPSLatitude[20];		//Gps纬度
    int laser_disance;			//异常计算距离
    int OsdTime;  				//显示叠加时间
    int osd_gps_on;				//1显示GPS信息 0关闭
    int osd_time_on;			//1显示时间信息 0关闭
    int osd_color_on;			//1显示色标，0关闭
    int osd_videomode_on;		//1显示视频模式，0关闭
    int osd_emissivity_on;		//1显示辐射率，0关闭
    int osd_object_on;			//1显示测温对象，0关闭
    int osd_abnormal_on;		//1显示异常信息，0关闭
    int osd_temphum_on;			//1显示温湿度数据信息，0关闭
    int elevation_angle;		//仰角角度
    short sensor_temp100;		/*外接温湿度传感器获取的温度*/
    short sensor_humidity100;	/*外接温湿度传感器获取的湿度*/
    int picflag;				/*图片类型*/
    char watermark[50];			/*叠加水印信息*/
    int position_data;			/*方位数据*/
} file_info_t;

/* 产品信息结构 */
typedef struct product_s {
    int nTag;					//产品信息标签 0x5A5A0202
    int nDesLen;				//该结构长度
    char deviceType[32];		//内部型号
    char OEMDeviceType[32];		//贴牌型号
    char DataProtocal[32];		//数据协议
    char SerialNumber[20];		//序列号
    char ProduceTime[16];		//生产日期
    char SoftwareVersion[16];	//软件版本
    int  TempCalcType;			//测温算法编号
    int  ImageCalcType;			//图像算法编号
    int  nDetectorImageW;		//探测器宽度
    int  nDetectorImageH;		//探测器高度
    int  nDetectorImageBits;	//探测器位宽
    int  ImageWidth;			//图像宽
    int  ImageHeight;			//图像高
    int  ImageBpp;				//图像字节数每像素点
    int  pictureWidth;			//照片宽
    int  pictureHeight;			//照片高
} product_info_t;

/* 颜色信息结构 */
typedef struct color_s {
    int nTag;					//颜色信息标签 0x5A5A0203
    int nDesLen;				//该结构长度
    int nColorRuleID;			//色标ID
    int nColorHightID;			//最大色标ID
    int nColorLowID;			//最小色标ID
    int nAlarmType;				//报警类型
    int bAlarm;					//报警开关
    float fAlarmTemp;			//报警温度
    int nColorAlarmID;			//报警色ID
    colornormal_t   corlor_normal;
    colorhover_t    corlor_hover;
    colorselect_t   corlor_select;
    fontset_t       fontset;
} color_info_t;

/* 图像处理信息结构 */
typedef struct alg_info_s
{
    int nTag;					   	//图像信息标签 0x5A5A0204
    int nDesLen;				  	//结构长度

    int nZoomRate10;				//放大倍率
    int nVideoOutState;				//图像模式
    int nProcessType;				//0 手动 1 自动
    int nMaxTempHand100;			//手动模式最高温100倍
    int nMinTempHand100;			//手动模式最低温100倍
    int nReverseImage;				//1 图像反相
    int nImageHandleType;			//图像处理模式
    int nflipDirection;				//图像翻转方向

    short nSculptureShake;			//高灵敏度开关
    short nSculpture;				//高灵敏度档位
    int nSculptureFactor;			//高灵敏度增益

    int nMaxGray;					//最高灰度
    int nMinGray;					//最低灰度
    int nMaxTemp100;				//最高温度
    int nMinTemp100;				//最低温度

    int nFusionType;				//融合类型，0 among 1 above 2 below
    int nFusionAmongHighTemp100;	//融合高温区间
    int nFusionAmongLowTemp100;		//融合低温区间
    int nFusionAboveTemp100;		//融合之上温度
    int nFusionBelowTemp100;		//融合之下温度

    int nPIPRate100;				//画中画比例
    int PIP_nStartX;				//画中画起始坐标x
    int PIP_nStartY;				//画中画起始坐标y
    int PIP_nWidth;					//画中画宽
    int PIP_nHight;					//画中画高
    int bTempCapture;      			//高低温捕获
    int vertical_handle;			//竖纹处理
    int suppression_handle;         //均匀抑制算法
} alg_info_t;

/* 测温信息结构 */
typedef struct {
    int nTag;							//测温信息标签0x5A5A0205
    int nDesLen;						//结构长度
    int nTempUnit;						//温度单位
    MeasureTempPara temp_para;			//测温参数
    temp_reference_para_t reference_para;	//参考参数
    OP_DATA    	MeasureActive;				//测温点、线、框选中状态
} temper_info_t;

/*测温数据结构*/
typedef struct {
    int nTag;								//测温信息标签 ITEMDATA_TAG
    int nDesLen;							//结构长度 - 仅当前结构体定义大小后跟数据大小不统计在内

    temper_item_t temper_point;				/*测温点信息 标签 ITEM_POINT_TAG*/
    temper_item_t temper_line;				/*测温线信息 标签 ITEM_LINE_TAG*/
    temper_item_t temper_rect;				/*测温框信息 标签 ITEM_RECT_TAG*/
    temper_item_t temper_circle;			/*测温圆信息 标签 ITEM_CIRCLE_TAG*/
    temper_item_t temper_polygon;			/*测温多边形信息 标签 ITEM_CIRCLE_TAG*/
    /*紧跟 point_num*sizeof(POINT_PARA_t) 点测温数据 + point_num*sizeof(LINE_PARA_t) 线测温数据 ... */
} item_data_t;
/* 照片头信息 */
typedef struct image_info_s
{
    file_info_t file;		//文件信息
    product_info_t product;	//产品信息
    color_info_t color;		//颜色信息
    alg_info_t alg;			//图像处理信息
    temper_info_t temper;	//测温信息
    item_data_t item;		//测温项数据
} image_head_t;

/* 标签结构 */
typedef struct taginfo_s
{
    int  nTag; 		//标签,对应上面各种信息标签
    int offset;		//对应标签信息在文件中的偏移
} taginfo_t;

/* 标签数量结构 */
typedef struct tagnum_s
{
    int  nTag; 	//0x5A5A0301 ，可以用来检查文件完整性
    int  num;	//标签的数量
} tagnum_t;

typedef enum {
    e_picture_none          = 0x000,
    e_picture_voice         = 0x001,        /*声音录制*/
    e_picture_super_gray    = 0x002,        /*超分辨率*/
    e_picture_guowang       = 0x004,        /*国网模式*/
    e_picture_qrcode        = 0x008,        /*二维码命名模式*/
    e_picture_ccd           = 0x010,        /*可见光(用于配合国网同时生产可见光照片)*/
    e_picture_bmp           = 0x020,        /*BMP格式保存*/
    e_picture_resize        = 0x040,        /*缩放保存*/
    e_picture_panorama      = 0x080,        /*全景保存*/
    e_picture_watermark     = 0x100,        /*水印保存*/
    e_picture_pms           = 0x200,        /*PMS拍照模式*/
    e_picture_png           = 0x400,        /*PNG拍照模式*/
    e_picture_record        = 0x80000000,   /*录像照片头*/
}E_PICTURE_MODE;
/* 照片信息结构 */
typedef struct
{
    int out_width;		//照片宽
    int out_height;		//照片高
    int jpeg_fp;		//照片文件句柄
    image_head_t head;	//照片头信息
    gray_info_t grayinfo;	//原始信息
    ccd_info_t ccdinfo;	   	//可见光信息
    image_gray_info_t imagegrayinfo;//灰度图像数据
    sketchinfo_t sketchinfo;//草图信息
    voiceinfo_t voiceinfo;	//音频信息
    textinfo_t textinfo;	//文本信息
    taginfo_t taginfo[8];	//标签
    tagnum_t  tagnum;	   //标签数量
} ti600s_picInfo_t;

typedef struct panorama_file_info_s
{
    int nTag; 				       	//全景文件信息标签 0x6A6A0C01
    int nDesLen;				    //结构长度
    char CapTime[30];  				//拍摄时间
    char PicName[230];  			//图片名称
    char GPSLongitude[20];			//Gps经度
    char GPSLatitude[20];			//Gps纬度
    int OsdTime;  					//显示叠加时间
    int crop_height;				//照片被裁剪高度
    int frame_splicing_width[20];	//每帧续接宽度
    int picflag;					/*图片类型*/
} panorama_file_info_t;

/* 全景拼接图像信息 */
typedef struct panorama_image_info_s
{
    int nTag; 				       	//全景拼接图像信息标签 0x6A6A0C02
    int nDesLen;				    //结构长度
    int nImageFormat;			  	//全景拼接图像数据格式
    int nVisualImageW;				//全景拼接图像宽度
    int nVisualImageH;				//全景拼接图像高度
    int nVisualImageBits;			//全景拼接图像位宽
    int nVisualImageAttr;			//单幅，多幅，录像0,1,2
    int nVisualImageFrameNums;		//帧个数
    float fVisualImageFrameFreq;	//帧频
    int nVisualImageLen;			//全景拼接数据长度
} panorama_image_info_t;

/*全景照片信息结构*/
typedef struct {
    panorama_file_info_t panorama_file_info;	//全景文件信息
    panorama_image_info_t image_info;			//全景图像信息
    taginfo_t taginfo[2];						//标签
    tagnum_t  tagnum;	   						//标签数量
} ir600_panorama_info_t;

typedef struct {
    unsigned char ir_code_type;         /*图谱类型*/
    int ir_atlas_len;                   /*红外图谱数据长度（从编码类型到图谱数据结束的长度）*/
    long long ir_atlas_capture_time;    /*图谱生产时间*/
    unsigned char ir_atlas_nature;      /*图谱性质*/
    char device_name[118];              /*被测设备名称 --- 使用 UNICODE 编码 --- 以 0x0000 结尾*/
    char device_code[42];               /*被测设备编码 --- 使用 ASCII 编码。以\0结尾*/
    char test_point_name[128];          /*被测设备的检测部位或位置，使用 UNICODE 编码 --- 末尾填充0x0000*/
    char test_point_code[32];           /*被测设备的检测部位或位置编码 --- 使用 ASCII 编码。以\0结尾*/
    short detection_channel_flag;       /*检测通道标识*/
    unsigned char storage_data_type;    /*用来表示存储的温度矩阵数据类型*/
    unsigned char temp_unit;            /*温度单位*/
    int temp_matrix_width;              /*温度点阵宽度*/
    int temp_matrix_height;             /*温度点阵高度*/
    int ccd_picture_size;               /*可见光照片数据大小*/
    int ir_picture_size;                /*红外照片数据大小*/
    float ir_emissivity;                /*辐射率*/
    float ir_distance;                  /*距离*/
    float ir_ambient_temp;              /*大气温度（环境温度）*/
    char ir_relative_humidity;          /*相对湿度*/
    float ir_reflection_temp;           /*反射温度*/
    float ir_tempclass_max;             /*温度档上限*/
    float ir_tempclass_min;             /*温度档下限*/
    char manufacturer_reserved[133];    /*厂家预留字节*/
} __attribute__((packed))pms_ir_atlas_t;
