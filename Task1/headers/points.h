#ifndef POINTS_H__
#define POINTS_H__

#include <stdio.h>
#include "points.h"
#include "actions.h"
#include "point.h"
#include "errs.h"


typedef struct points points_t;


struct points
{
    size_t size;
    point_t *arr;
};

error_t points_init(points_t *points, size_t size);
void clear_points(const points_t *points);
error_t copy_points(const points_t *src, points_t *dst);

error_t read_points(FILE *f, points_t *points);
error_t write_points(FILE *f, points_t *points);

error_t move_points(points_t *points, move_t *move);
error_t scale_points(points_t *points, scale_t *move);
error_t rotate_points(points_t *points, rotate_t *move);

#endif // POINTS_H__
