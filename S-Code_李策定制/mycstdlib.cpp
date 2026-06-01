#include "mycstdlib.h"
/**********************************************************************************************

   函 数 名     : myexp
   功能描述     : 以e为底的指数运算
   输入参数     :
       double x					指数
   输出参数     :
   返 回 值     :
       double							指数运算结果
***********************************************************************************************/
double myexp(double x)
{
   int i, k, m, t;
   int xm = (int)x;
   double sum;
   double e ;
   double ef;
   double z ;
   double sub = x - xm;

   m		=	1;
   e		=	1.0;
   ef		=	1.0;
   t		=	10;
   z		=	1;
   sum		=	1;

   if (xm < 0) {
       xm = (-xm);
       for (k = 0; k < xm; k++) {
           ef *= 2.718281;
       }
       e /= ef;
   }
   else {
       for (k = 0; k < xm; k++) {
           e *= 2.718281;
       }
   }

   for (i = 1; i < t; i++) {
       m *= i;
       z *= sub;
       sum += z/m;
   }

   return sum * e;
}


/**********************************************************************************************

   函 数 名     : _itoa_
   功能描述     : int型的数字d转化为字符串str
   输入参数     :
       int	d						int型整数
   输出参数     :
       char *str					对应字符串输出
   返 回 值     :
       int							字符串长度
***********************************************************************************************/
int _itoa_(int d, char *str)
{
   int r;
   int len = 0;
   char tmp_buf[32];
   int ret_len = 0;

   if (d < 0) {
       d = -d;
       *str++ = '-';
       ret_len += 1;
   }
   do {
       r = d % 10;
       d = d / 10;
       *(tmp_buf + len) = r + '0';
       len++;
   } while (d > 0);

   str[len] = '\0';	// null
   ret_len += len;

   while (len > 0) {
       *str++ = tmp_buf[len - 1];
       len--;
   }

   return ret_len;
}


/**********************************************************************************************

   函 数 名     : _ftoa_
   功能描述     : float 型的数字d转化为字符串str
   输入参数     :
       float	f						float 型浮点数
       int n							小数位数
   输出参数     :
       char *str						对应字符串输出
   返 回 值     :
       int							字符串长度
***********************************************************************************************/
int _ftoa_(float f, char *str, int n)
{
   int r;
   int len = 0, tmp_len = 0;
   char tmp_buf[32], *pstart = str;
   int d;
   float in;

   //判断正负
   if (f < 0) {
       f = -f;
       *str++ = '-';
       len++;
   }

   d = (int)f;//取整数部分
   in = f - d;//取小数部分

   do {
       r = d % 10;
       d = d / 10;
       *(tmp_buf + tmp_len) = r + '0';
       tmp_len++;
   } while (d > 0);//获取整数部分的字符

   while (tmp_len > 0) {
       *str++ = tmp_buf[tmp_len - 1];
       tmp_len--;
       len++;
   }//将整数部分字符填充入字符串

   *str++ = '.';
   len++;

   //对小数部分补充精度
   if( n <= 4 )
       in = (in>=0.99999)?in:(in+0.00001);

   do {//获取小数部分
       if (n == 0)
           break;

       in = in * 10;
       d = (int)in;
       in = in - d;
       *str++ = d + '0';
       len++;
       n--;
   } while (in > 0.000001);

   pstart[len] = '\0';

   return len;
}


/**********************************************************************************************

   函 数 名     : mk_time_str
   功能描述     : 将xx:xx:xx格式的时间转换为字符串
   输入参数     :
       struct tm *p_time			需转换的时间
   输出参数     :
       char *timestr				时间字符串
   返 回 值     : 无
***********************************************************************************************/
void mk_time_str(char *timestr, struct tm *p_time)
{
   char *ptr = timestr;
   int year=0;
   int month=0;

   year = p_time->tm_year + 1900;
   month = p_time->tm_mon + 1;

   *ptr++ = '0' + year  / 1000;
   *ptr++ = '0' + (year%1000)  / 100;
   *ptr++ = '0' + (year%100) / 10;
   *ptr++ = '0' + year % 10;
   *ptr++ = '-';
   *ptr++ = '0' + month / 10;
   *ptr++ = '0' + month % 10;
   *ptr++ = '-';
   *ptr++ = '0' + p_time->tm_mday / 10;
   *ptr++ = '0' + p_time->tm_mday % 10;
   *ptr++ = ' ';

   *ptr++ = '0' + p_time->tm_hour / 10;
   *ptr++ = '0' + p_time->tm_hour % 10;
   *ptr++ = ':';
   *ptr++ = '0' + p_time->tm_min / 10;
   *ptr++ = '0' + p_time->tm_min % 10;
   *ptr++ = ':';
   *ptr++ = '0' + p_time->tm_sec / 10;
   *ptr++ = '0' + p_time->tm_sec % 10;
   *ptr++ = '\0';
}



