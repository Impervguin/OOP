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

void projection_init(projection_t *projection);
myerror_t project_figure(projection_t *proj, const figure_t *fig);
void clear_projection(projection_t *proj);


#endif // PROJECTION_H__
