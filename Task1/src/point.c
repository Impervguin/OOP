#include <stdio.h>
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
    return OK;
}


error_t rotate_point(point_t *p, rotate_t *rotate)
{
    return OK;
}

error_t scale_point(point_t *p, scale_t *scale)
{
    return OK;
}