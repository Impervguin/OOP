#include <stdio.h>
#include <math.h>
#include "errs.h"
#include "point.h"
#include "actions.h"

error_t read_point(FILE *f, point_t *p)
{
    if (!f)
        return ERR_NO_FILE;
    if (!p)
        return ERR_NULL_POINTER;
    
    double x,y,z;
    if (fscanf(f, "%lf%lf%lf", &x, &y, &z) != 3)
        return ERR_FILE_FORMAT;
    
    p->x = x;
    p->y = y;
    p->z = z;

    return OK;
}

error_t write_point(FILE *f, point_t *p)
{
    if (!f)
        return ERR_NO_FILE;
    if (!p)
        return ERR_NULL_POINTER;
    
    if (fprintf(f, "%lf %lf %lf\n", p->x, p->y, p->z) < 0)
        return ERR_NO_FILE;
    return OK;
}

error_t move_point(point_t *p, move_t *move)
{
    if (!move || !p)
        return ERR_NULL_POINTER;
    p->x += move->x;
    p->y += move->y;
    p->z += move->z;
    return OK;
}

// Угол в радианах против часовой стрелке
static error_t rotate_around_axis(double x, double y, double angle, double *new_x, double *new_y)
{
    if (!new_x || !new_y)
        return ERR_NULL_POINTER;
    *new_x = x * cos(angle) - y * sin(angle);
    *new_y = y * cos(angle) + x * sin(angle);
    return OK;
}

error_t rotate_point(point_t *p, rotate_t *rotate)
{
    if (!rotate || !p)
        return ERR_NULL_POINTER;
    rotate_around_axis(p->x, p->y, rotate->oz, &p->x, &p->y);
    rotate_around_axis(p->x, p->z, rotate->oy, &p->x, &p->z);
    rotate_around_axis(p->z, p->y, rotate->ox, &p->z, &p->y);
    return OK;
}


error_t scale_point(point_t *p, scale_t *scale)
{
    if (!scale || !p)
        return ERR_NULL_POINTER;
    p->x *= scale->x;
    p->y *= scale->y;
    p->z *= scale->z;
    return OK;
}