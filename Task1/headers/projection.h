#ifndef PROJECTION_H__
#define PROJECTION_H__


typedef struct projection projection_t;
typedef struct points2d points2d_t;
typedef struct point2d point2d_t;

#include <stddef.h>
#include "figure.h"
#include "edges.h"
#include "points.h"
#include "point.h"

struct point2d
{
    double x, y;
};

struct points2d
{
    size_t size;
    point2d_t *arr;
};

struct projection
{
    point2d_t center;
    points2d_t points;
    edges_t edges;
};

myerror_t create_projection(projection_t **projection, const figure_t *fig);
void destroy_projection(projection_t *projection);
myerror_t project_point(point2d_t *p2d, const point_t *p3d);




#endif // PROJECTION_H__
