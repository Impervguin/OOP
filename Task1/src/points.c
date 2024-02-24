#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errs.h"
#include "points.h"
#include "point.h"

error_t points_init(points_t *points, size_t size)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (size == 0)
        return ERR_ARGUMENTS;
    
    point_t *arr = malloc(sizeof(point_t) * size);
    if (!arr)
        return ERR_MEMORY;
    points->arr = arr;
    points->size = size;
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

error_t copy_points(const points_t *src, points_t *dst)
{
    if (!src || !dst)
        return ERR_NULL_POINTER;
    if (src->arr)
    {
        point_t *arr = malloc(sizeof(point_t) * src->size);
        if (!arr)
            return ERR_MEMORY;
        memcpy(arr, src->arr, sizeof(point_t) * src->size);
        if (dst->arr)
            clear_points(dst);
        dst->size = src->size;
        dst->arr = arr;
    }
    else
        if (dst->arr)
            clear_points(dst);
    return OK;
}

error_t read_points(FILE *f, points_t *points)
{
    if (!f)
        return ERR_NO_FILE;
    if (!points)
        return ERR_NULL_POINTER;
    points_t tmp; 

    size_t num;
    if (fscanf(f, "%zu", &num) != 1)
        return ERR_FILE_FORMAT;
    
    error_t err = points_init(&tmp, num);
    if (err)
        return err;
    
    for (size_t i = 0; i < num && !err; i++)
        err = read_point(f, &tmp.arr[i]);
    
    if (!err)
        copy_points(&tmp, points);
    clear_points(&tmp);
    return err;
}

error_t write_points(FILE *f, points_t *points)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr && points->size)
        return ERR_NULL_POINTER;

    if (fprintf(f, "%zu\n", points->size) < 0)
        return ERR_NO_FILE;

    for (size_t i = 0; i < points->size; i++)
    {
        error_t err = write_point(f, &points->arr[i]);
        if (err)
            return err;
    }
    return OK;
}

error_t move_points(points_t *points, move_t *move)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr && points->size)
        return ERR_NULL_POINTER;
    if (!move)
        return ERR_NULL_POINTER;
    
    for (size_t i = 0; i < points->size; i++)
    {
        error_t err = move_point(&points->arr[i], move);
        if (err)
            return err;
    }
    return OK;

}

error_t scale_points(points_t *points, scale_t *scale)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr && points->size)
        return ERR_NULL_POINTER;
    if (!scale)
        return ERR_NULL_POINTER;
    
    for (size_t i = 0; i < points->size; i++)
    {
        error_t err = scale_point(&points->arr[i], scale);
        if (err)
            return err;
    }
    return OK;

}

error_t rotate_points(points_t *points, rotate_t *rotate)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr && points->size)
        return ERR_NULL_POINTER;
    if (!rotate)
        return ERR_NULL_POINTER;
    
    for (size_t i = 0; i < points->size; i++)
    {
        error_t err = rotate_point(&points->arr[i], rotate);
        if (err)
            return err;
    }
    return OK;

}