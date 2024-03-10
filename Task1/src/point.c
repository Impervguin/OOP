#include <stdio.h>
#include <math.h>
#include "errs.h"
#include "point.h"
#include "actions.h"

void point_init(point_t *point)
{
    if (!point)
        return;
    
    point->x = 0;
    point->y = 0;
    point->z = 0;
}

myerror_t read_point(point_t *p, FILE *f)
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

myerror_t write_point(FILE *f, point_t *p)
{
    if (!f)
        return ERR_NO_FILE;
    if (!p)
        return ERR_NULL_POINTER;
    
    if (fprintf(f, "%lf %lf %lf\n", p->x, p->y, p->z) < 0)
        return ERR_NO_FILE;
    return OK;
}

myerror_t move_point(point_t *p, const move_t *move)
{
    if (!move || !p)
        return ERR_NULL_POINTER;
    p->x += move->x;
    p->y += move->y;
    p->z += move->z;
    return OK;
}


static myerror_t rotate_around_x(point_t *point, double angle)
{
    if (!point)
        return ERR_NULL_POINTER;
    
    point_t new;
    new.z = point->z * cos(angle) - point->y * sin(angle);
    new.y = point->z * sin(angle) + point->y * cos(angle);
    new.x = point->x;
    *point = new;
    return OK;
}

static myerror_t rotate_around_y(point_t *point, double angle)
{
    if (!point)
        return ERR_NULL_POINTER;
    
    point_t new;
    new.x = point->x * cos(angle) - point->z * sin(angle);
    new.z = point->x * sin(angle) + point->z * cos(angle);
    new.y = point->y;
    *point = new;
    return OK;
}

static myerror_t rotate_around_z(point_t *point, double angle)
{
    if (!point)
        return ERR_NULL_POINTER;

    point_t new;
    new.y = point->y * cos(angle) - point->x * sin(angle);
    new.x = point->y * sin(angle) + point->x * cos(angle);
    new.z = point->z;
    *point = new;
    return OK;
}

myerror_t rotate_point(point_t *point, const rotate_t *rotate, const point_t *center)
{
    if (!point || !center || !rotate)
        return ERR_NULL_POINTER;

    move_t to_center = {.x = -center->x, .y = -center->y, .z = -center->z};
    move_point(point, &to_center);
    rotate_around_x(point, rotate->ox);
    rotate_around_y(point, rotate->oy);
    rotate_around_z(point, rotate->oz);
    move_t back = {.x = center->x, .y = center->y, .z = center->z};
    move_point(point, &back);

    return OK;
}


myerror_t scale_point(point_t *point, const scale_t *scale, const point_t *center)
{
    if (!scale || !point || !center)
        return ERR_NULL_POINTER;
    point->x = (point->x - center->x) * scale->x + center->x;
    point->y = (point->y - center->y) * scale->y + center->y;
    point->z = (point->z - center->z) * scale->z + center->z;
    return OK;
}

point_t min_point(point_t p1, point_t p2)
{
    p1.x = p1.x < p2.x ? p2.x : p1.x;
    p1.y = p1.y < p2.y ? p2.y : p1.y;
    p1.z = p1.z < p2.z ? p2.z : p1.z;
    return p1;
}

point_t max_point(point_t p1, point_t p2)
{
    p1.x = p1.x > p2.x ? p2.x : p1.x;
    p1.y = p1.y > p2.y ? p2.y : p1.y;
    p1.z = p1.z > p2.z ? p2.z : p1.z;
    return p1;
}

point_t rect_center(point_t min, point_t max)
{
    point_t center;
    center.x = (max.x - min.x) / 2 + min.x;
    center.y = (max.y - min.y) / 2 + min.y;
    center.z = (max.z - min.z) / 2 + min.z;
    return center;
}