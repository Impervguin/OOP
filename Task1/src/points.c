#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errs.h"
#include "points.h"
#include "point.h"

myerror_t points_init(points_t *points, size_t size)
{
    if (!points)
        return ERR_NULL_POINTER;
    
    if (size == 0)
    {
        points->arr = NULL;
        points->size = 0;
    }
    else 
    {
        point_t *arr = malloc(sizeof(point_t) * size);
        if (!arr)
            return ERR_MEMORY;
        points->arr = arr;
        points->size = size;
    }
    return OK;
}

void clear_points(points_t *points)
{
    if (!points)
        return;
    if (points->arr)
    {
        free(points->arr);
        points->arr = NULL;
    }
    points->size = 0;
}

myerror_t copy_points(points_t *dst, const points_t *src)
{
    if (!src || !dst)
        return ERR_NULL_POINTER;
    
    if (src->size != 0 && src->arr != NULL)
    {
        point_t *arr = realloc(dst->arr, sizeof(point_t) * src->size);
        if (!arr)
            return ERR_MEMORY;
        
        dst->size = src->size;
        dst->arr = arr;
        memcpy(dst->arr, src->arr, sizeof(point_t) * src->size);
    }
    else 
        clear_points(dst);
    return OK;
}

myerror_t read_points(points_t *points, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!points)
        return ERR_NULL_POINTER;
    points_t tmp; 

    size_t num;
    if (fscanf(f, "%zu", &num) != 1)
        return ERR_FILE_FORMAT;
    
    myerror_t err = points_init(&tmp, num);
    if (err)
        return err;
    
    for (size_t i = 0; i < num && !err; i++)
        err = read_point(&tmp.arr[i], f);
    
    if (!err)
        copy_points(points, &tmp);
    clear_points(&tmp);
    return err;
}

myerror_t write_points(FILE *f, points_t *points)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr && points->size)
        return ERR_NULL_POINTER;

    if (fprintf(f, "%zu\n", points->size) < 0)
        return ERR_NO_FILE;

    for (size_t i = 0; i < points->size; i++)
    {
        myerror_t err = write_point(f, &points->arr[i]);
        if (err)
            return err;
    }
    return OK;
}

myerror_t move_points(points_t *points, move_t *move)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || !points->size)
        return ERR_EMPTY;
    if (!move)
        return ERR_NULL_POINTER;
    
    points_t tmp = {0, NULL};
    myerror_t err = OK;
    err = copy_points(&tmp, points);

    for (size_t i = 0; i < points->size && !err; i++)
        err = move_point(&tmp.arr[i], move);

    if (err == OK)
        err = copy_points(points, &tmp);

    clear_points(&tmp);
    return err;
}

myerror_t scale_points(points_t *points, scale_t *scale, point_t *center)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || !points->size)
        return ERR_EMPTY;
    if (!scale || !center)
        return ERR_NULL_POINTER;
    

    points_t tmp = {0, NULL};
    myerror_t err = OK;
    err = copy_points(&tmp, points);

    move_t to_center = {-center->x, -center->y, -center->z};
    move_t reverse = {center->x, center->y, center->z};

    if (err == OK)
        err = move_points(&tmp, &to_center);
    
    for (size_t i = 0; i < points->size && !err; i++)
        err = scale_point(&tmp.arr[i], scale);

    if (err == OK)
        err = move_points(&tmp, &reverse);
    
    if (err == OK)
        err = copy_points(points, &tmp);

    clear_points(&tmp);
    return err;

}

myerror_t rotate_points(points_t *points, rotate_t *rotate, point_t *center)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || ! points->size)
        return ERR_EMPTY;
    if (!rotate || !center)
        return ERR_NULL_POINTER;
    
    points_t tmp = {0, NULL};
    myerror_t err = OK;
    err = copy_points(&tmp, points);

    move_t to_center = {-center->x, -center->y, -center->z};
    move_t reverse = {center->x, center->y, center->z};

    if (err == OK)
        err = move_points(&tmp, &to_center);
    
    for (size_t i = 0; i < points->size && !err; i++)
        err = rotate_point(&tmp.arr[i], rotate);

    if (err == OK)
        err = move_points(&tmp, &reverse);
    
    if (err == OK)
        err =  copy_points(points, &tmp);

    clear_points(&tmp);
    return err;
}


myerror_t points_rect(point_t *min_point, point_t *max_point, points_t *points)
{
    if (!min_point || !max_point || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    *min_point = points->arr[0];
    *max_point = points->arr[0];

    for (size_t i = 1; i < points->size; i++)
    {
        if (min_point->x > points->arr[i].x)
            min_point->x = points->arr[i].x;
        if (min_point->y > points->arr[i].y)
            min_point->y = points->arr[i].y;
        if (min_point->z > points->arr[i].z)
            min_point->z = points->arr[i].z;
        
        if (max_point->x < points->arr[i].x)
            max_point->x = points->arr[i].x;
        if (max_point->y < points->arr[i].y)
            max_point->y = points->arr[i].y;
        if (max_point->z < points->arr[i].z)
            max_point->z = points->arr[i].z;
    }

    return OK;
}


myerror_t points_center(point_t *center, points_t *points)
{
    if (!center || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    point_t min_point, max_point;
    myerror_t err = points_rect(&min_point, &max_point, points);
    if (err == OK)
    {
        center->x = (max_point.x - min_point.x) / 2 + min_point.x;
        center->y = (max_point.y - min_point.y) / 2 + min_point.y;
        center->z = (max_point.z - min_point.z) / 2 + min_point.z;
    }

    return err;   
}
