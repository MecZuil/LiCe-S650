#include "hp_polygon.h"

Hp_Polygon::Hp_Polygon()
{

}
// 计算点集合中x小于p点的x的点的个数
int Hp_Polygon::points_statistics(point_t p, point_t* pts, int pts_size)
{
    int count = 0;
    for (int i = 0; i < pts_size; i++)
    {
        if (pts[i].x < p.x)
        {
            count++;
        }
    }
    return count;
}

// 计算向量叉积，用于判断点的相对位置
int Hp_Polygon::cross_product(point_t p, point_t q, point_t r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// 判断两条线段 j1j2 和 p1p2 的方向
// 返回值：0 表示共线，1 表示顺时针，2 表示逆时针
int Hp_Polygon::segment_orientation(point_t j1, point_t j2, point_t p1, point_t p2)
{
    int val_j1j2_p1 = cross_product(j1, j2, p1);
    int val_j1j2_p2 = cross_product(j1, j2, p2);

    if (val_j1j2_p1 == 0 && val_j1j2_p2 == 0) {
        return 0; // 共线
    } else if (val_j1j2_p1 > 0 || val_j1j2_p2 > 0) {
        return 1; // 顺时针
    } else {
        return 2; // 逆时针
    }
}
// 获取y坐标的中间值
point_t Hp_Polygon::get_median_y(point_t* pts, int num) {
    point_t temp_points[num];

    for (int i = 0; i < num; i++) {
        temp_points[i] = pts[i];
    }

    qsort(temp_points, num, sizeof(point_t), compare_points_y);

    return temp_points[num / 2];
}

// 对随机点进行处理
void Hp_Polygon::classify_points(QList<QPointF> &qtPts, int num) {

    int cmd = 1;//交叉标志位
    point_t upper[num];
    point_t lower[num];
    point_t pts[num];
    for(int i = 0; i < qtPts.count(); i++)
    {
        pts[i].x = qtPts.at(i).x();
        pts[i].y = qtPts.at(i).y();
    }
    int upper_count, lower_count;

    // 对这些点按x坐标进行排序
    qsort(pts, num, sizeof(point_t), compare_points_x);

    // 先对点按y坐标进行排序，找到中间值的那个点作为基准点
    point_t base = get_median_y(pts, num);

    upper_count = 0;
    lower_count = 0;
    for (int i = 0; i < num; i++) {
        if (pts[i].y >= base.y) {
            upper[upper_count] = pts[i];
            (upper_count)++;
        } else {
            lower[lower_count] = pts[i];
            (lower_count)++;
        }
    }
    //再按X坐标排序一次
    qsort(upper, upper_count, sizeof(point_t), compare_points_x);
    qsort(lower, lower_count, sizeof(point_t), compare_points_x);

    /*
    1-----先判断是否有可能交叉
    2.----处理交叉情况，重新排序
    */
    //上包头部
    if(((upper[1].y <= upper[0].y) && (lower[0].x >= upper[1].x))){

        int count1 = points_statistics(lower[0], upper, upper_count);
        for (int i = 0; i < count1; i++) {
            if (segment_orientation(upper[0],lower[0], upper[i], upper[i+1]) == 2) {
                cmd = 0;
            }
        }

        if(!cmd){

            point_t* new_upper1 = (point_t*)malloc(count1 * sizeof(point_t));
            int upper_count1 = upper_count;  //不能对原始数据修改，可能进行两次交叉判断的时候
            for (int i = 0; i < count1; i++) {
                new_upper1[i] = upper[i];
            }
            for (int i = count1; i < upper_count1; i++) {
                upper[i - count1] = upper[i];
            }
            upper_count1 -= count1;
            qsort(new_upper1, count1, sizeof(point_t), compare_points_y);

            // memset(pts, 0, sizeof(Point) * num);
            num = 0;  // 清空点计数
            //截断部分分两部分，确保在截断3点以上的时候也分离
            for (int i = count1/2-1; i < count1; i++) {
                pts[num++] = new_upper1[i];
            }
            for (int i = 0; i < upper_count1; i++) {
                pts[num++] = upper[i];
            }
            for (int i = lower_count - 1; i >= 0; i--) {
                pts[num++] = lower[i];
            }
            for (int i = 0; i < count1/2; i++) {
                pts[num++] = new_upper1[i];
            }
        }

    }
    //下包头部
    if((lower[1].y >= lower[0].y) && (upper[0].x >= lower[1].x)){

        int count2 = points_statistics(upper[0], lower, lower_count);
        for (int i = 0; i < count2; i++) {
            if (segment_orientation(lower[0],upper[0], lower[i], lower[i+1]) == 1) {
                cmd = 0;
            }
        }

        if(!cmd){

            point_t* new_lower1 = (point_t*)malloc(count2 * sizeof(point_t));
            int lower_count1 = lower_count;

            for (int i = 0; i < count2; i++) {
                new_lower1[i] = lower[i];
            }
            for (int i = count2; i < lower_count1; i++) {
                lower[i - count2] = lower[i];
            }
            lower_count1 -= count2;
            qsort(new_lower1, count2, sizeof(point_t), compare_points_y);

            //memset(pts, 0, sizeof(Point) * num);
            num = 0;  // 清空点计数
            for (int i = count2/2+1; i < count2; i++) {
                pts[num++] = new_lower1[i];
            }
            for (int i = 0; i < upper_count; i++) {
                pts[num++] = upper[i];
            }
            for (int i = lower_count1 - 1; i >= 0; i--) {
                pts[num++] = lower[i];
            }
            for (int i = 0; i <= count2/2; i++) {
                pts[num++] = new_lower1[i];
            }
        }

    }
    //尾部注意逆时针先画头部，再加入尾部截断
    //上包尾部
    if((upper[upper_count-1].y >= upper[upper_count-2].y) && (lower[lower_count-1].x <= upper[upper_count-2].x)){

        int count3 = upper_count - points_statistics(lower[lower_count - 1], upper, upper_count);
        for (int i = count3; i > 0; i--) {
            int idx = upper_count - 1 - (count3 - i);
            if(idx>=1)
            {
                if (segment_orientation(upper[upper_count-1],lower[lower_count-1],  upper[idx], upper[idx-1]) == 2) {
                    cmd = 0;
                }
            }
        }

        if(!cmd){

            point_t* new_upper2 = (point_t*)malloc(count3 * sizeof(point_t));
            int upper_count2 = upper_count;
            for (int i = 0; i < count3; i++) {
                new_upper2[i] = upper[upper_count2-(count3-i)];
            }
            upper_count2 -= count3;
            qsort(new_upper2, count3, sizeof(point_t), compare_points_y);

            //memset(pts, 0, sizeof(Point) * num);
            num = 0;  // 清空点计数

            for (int i = count3/2; i < count3; i++) {
                pts[num++] = new_upper2[i];
            }
            for (int i = upper_count2-1; i >= 0; i--) {
                pts[num++] = upper[i];
            }
            for (int i = 0; i < lower_count; i++) {
                pts[num++] = lower[i];
            }
            for (int i = 0; i < count3/2; i++) {
                pts[num++] = new_upper2[i];
            }
        }
    }
    //下包尾部
    if((lower[lower_count-1].y <= lower[lower_count-2].y) && (upper[upper_count-1].x <= lower[lower_count-2].x)){

        int count4 = lower_count - points_statistics(upper[upper_count - 1], lower, lower_count);
        for (int i = count4; i > 0; i--) {
            int idx = lower_count - 1 - (count4 - i);
            if(idx>=1)
            {
                if (segment_orientation(lower[lower_count - 1], upper[upper_count - 1], lower[idx], lower[idx - 1]) == 1) {
                    cmd = 0;
                }
            }
        }

        if(!cmd){
            point_t* new_lower2 = (point_t*)malloc(count4 * sizeof(point_t));
            int lower_count2 = lower_count;
            for (int i = 0; i < count4; i++) {
                new_lower2[i] = lower[lower_count2-(count4-i)];
            }
            lower_count2 -= count4;
            qsort(new_lower2, count4, sizeof(point_t), compare_points_y);

            //memset(pts, 0, sizeof(Point) * num);
            num = 0;  // 清空点计数
            for (int i = count4/2; i < count4; i++) {
                pts[num++] = new_lower2[i];
            }

            for (int i = upper_count-1; i >= 0; i--) {
                pts[num++] = upper[i];
            }
            for (int i = 0; i < lower_count2; i++) {
                pts[num++] = lower[i];
            }
            for (int i = 0; i < count4/2; i++) {
                pts[num++] = new_lower2[i];
            }
        }
    }

    //未出现交叉的情况
    if(cmd){
        num = 0;  // 清空点计数
        for (int i = 0; i < upper_count; i++) {
            pts[num++] = upper[i];
        }
        for (int i = lower_count - 1; i >= 0; i--) {
            pts[num++] = lower[i];
        }

    }
    qtPts.clear();
    for(int i = 0; i < num; i++)
    {
        QPointF qtpoint(pts[i].x, pts[i].y);
        qtPts.append(qtpoint);
    }
    return;
}

//射线法判断点是否在多边形内部
bool Hp_Polygon::point_in_polygon(QList<QPointF> qtPts, QPoint qtPoint1, int num)
{
    point_t point1;
    point1.x = qtPoint1.x();
    point1.y = qtPoint1.y();
    point_t pts[qtPts.count()];
    for(int i = 0; i < qtPts.count(); i++)
    {
        pts[i].x = qtPts.at(i).x();
        pts[i].y = qtPts.at(i).y();
    }
    int x = point1.x;
    int y = point1.y;
    int i, j = num - 1 ;
    int cross_product = 0;
    bool in_polygon = false;

    for (i=0; i<num; i++)
    {
        /*
        (注意嵌入式的坐标系，原点在左上角,y轴向下增大，x轴向右增大)
        从点 (x, y) 向右发射射线，逆时针遍历每一条边进行判断：
        1.待检测点的y值在不在这条边的y范围内，不在代表无相交可能
        2.如果在y值范围，判断该边的其中一个端点是否在测试点右侧，两点都在左侧不做判断
        */
        if (((pts[i].y < y && pts[j].y >= y) || (pts[j].y < y && pts[i].y >= y))
            && (pts[i].x >= x || pts[j].x >= x))
        {
            //计算叉交点坐标，交点在右侧有效
            if(pts[i].y < y && pts[j].y >= y){
                cross_product = (pts[i].x - ((double)(y-pts[i].y)/(pts[j].y-pts[i].y)*(pts[i].x - pts[j].x)));
                in_polygon^=( cross_product >= x);
            }else{
                cross_product = (pts[j].x - ((double)(y-pts[j].y)/(pts[i].y-pts[j].y)*(pts[j].x - pts[i].x)));
                in_polygon^=( cross_product >= x);
            }
        }

        j=i;
    }

    return in_polygon;
}
