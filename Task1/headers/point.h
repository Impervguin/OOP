#ifndef POINT_H__
#define POINT_H__

#include <stdio.h>
#include "errs.h"
#include "actions.h"

typedef struct point point_t;

struct point
{
    double x, y, z;
};


error_t read_point(FILE *f, point_t *p);
error_t write_point(FILE *f, point_t *p);

error_t move_point(point_t *p, move_t *move);
error_t rotate_point(point_t *p, rotate_t *rotate);
error_t scale_point(point_t *p, scale_t *scale);

#endif // POINT_H__
