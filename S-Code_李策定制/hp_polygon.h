#ifndef HP_POLYGON_H
#define HP_POLYGON_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QPointF>
#include <QSortFilterProxyModel>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
} point_t;

class Hp_Polygon
{
public:
    Hp_Polygon();

    static int compare_points_x(const void* a, const void* b) {
        point_t* pointA = (point_t*)a;
        point_t* pointB = (point_t*)b;

        return (pointA->x - pointB->x);
    }

    static int compare_points_y(const void* a, const void* b) {
        point_t* pointA = (point_t*)a;
        point_t* pointB = (point_t*)b;

        return pointA->y - pointB->y;
    }
    int points_statistics(point_t p, point_t* pts, int pts_size);
    int cross_product(point_t p, point_t q, point_t r);
    int segment_orientation(point_t j1, point_t j2, point_t p1, point_t p2);
    point_t get_median_y(point_t* pts, int num);
    void classify_points(QList<QPointF> &pts, int num);
    bool point_in_polygon(QList<QPointF> pts, QPoint point1, int num);
};

#endif // HP_POLYGON_H
