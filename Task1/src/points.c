#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errs.h"
#include "points.h"
#include "point.h"

void points_init(points_t *points)
{
    if (!points)
        return;
    points->arr = NULL;
    points->size = 0;
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

size_t get_points_size(points_t *points)
{
    if (!points)
        return 0;
    return points->size;
}

// static myerror_t copy_points_arr(point_t **arr, const point_t *src, size_t size)
// {
//     if (!src || !arr)
//         return ERR_NULL_POINTER;
//     if (!size)
//         return ERR_EMPTY;
    
//     point_t *new = malloc(sizeof(point_t) * size);
//     if (!new)
//         return ERR_MEMORY;

//     if (!*arr)
//         free(*arr);
//     *arr = new;

//     memcpy(*arr, src, sizeof(point_t) * size);

//     return OK;
// }

// myerror_t copy_points(points_t *dst, const points_t *src)
// {
//     if (!src || !dst)
//         return ERR_NULL_POINTER;
    
//     myerror_t err = copy_points_arr(&dst->arr, src->arr, src->size);
//     if (!err)
//         dst->size = src->size;

//     return err;
// }

static myerror_t read_points_count(size_t *count, FILE *f) 
{
    if (!f)
        return ERR_NO_FILE;
    
    size_t num;
    if (fscanf(f, "%zu", &num) != 1)
        return ERR_FILE_FORMAT;
    
    *count = num;
    return OK;
}

static myerror_t read_points_array(point_t *arr, size_t size, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!arr)
        return ERR_NULL_POINTER;

    myerror_t err = OK;

    for (size_t i = 0; !err && i < size; i++)
        err = read_point(arr + i, f);
    
    return err;
}

static myerror_t create_points_array(point_t **arr, size_t size)
{
    point_t *new = malloc(sizeof(point_t) * size);
    if (!new)
        return ERR_MEMORY;
    *arr = new;
    return OK;
}

static void free_points_array(point_t *arr)
{
    free(arr);
}

myerror_t read_points(points_t *points, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!points)
        return ERR_NULL_POINTER;

    myerror_t err = read_points_count(&points->size, f);

    if (!err && points->size == 0)
        err = ERR_EMPTY;

    if (!err)
        err = create_points_array(&points->arr ,points->size);

    if (!err)
    {
        err = read_points_array(points->arr, points->size, f);
        if (err)
            free_points_array(points->arr);
    }

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
    
    myerror_t err = OK;
    for (size_t i = 0; i < points->size; i++)
        err = write_point(f, points->arr + i);
    
    return err;
}

myerror_t move_points(points_t *points, const move_t *move)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || !points->size)
        return ERR_EMPTY;
    if (!move)
        return ERR_NULL_POINTER;
    
    for (size_t i = 0; i < points->size; i++)
        move_point(points->arr + i, move);
    
    return OK;
}

myerror_t scale_points(points_t *points, const scale_t *scale, const point_t *center)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || !points->size)
        return ERR_EMPTY;
    if (!scale || !center)
        return ERR_NULL_POINTER;
    
    for (size_t i = 0; i < points->size; i++)
        scale_point(points->arr + i, scale, center);

    return OK;

}

myerror_t rotate_points(points_t *points, const rotate_t *rotate, const point_t *center)
{
    if (!points)
        return ERR_NULL_POINTER;
    if (!points->arr || ! points->size)
        return ERR_EMPTY;
    if (!rotate || !center)
        return ERR_NULL_POINTER;
    

    for (size_t i = 0; i < points->size; i++)
        rotate_point(points->arr + i, rotate, center);
    
    return OK;
}

static myerror_t find_min_point(point_t *min, const points_t *points)
{
    if (!min || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    *min = points->arr[0];

    for (size_t i = 1; i < points->size; i++)
        *min = min_point(*min, points->arr[i]);
    
    return OK;
}

static myerror_t find_max_point(point_t *max, const points_t *points)
{
    if (!max || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    *max = points->arr[0];

    for (size_t i = 1; i < points->size; i++)
        *max = max_point(*max, points->arr[i]);
    
    return OK;
}  

myerror_t points_rect(point_t *min_point, point_t *max_point, const points_t *points)
{
    if (!min_point || !max_point || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    point_t max, min;

    myerror_t err = find_min_point(&min, points);

    if (!err)
        err = find_max_point(&max, points);
    
    if (!err)
    {
        *max_point = max;
        *min_point = min;
    }

    return OK;
}


myerror_t points_center(point_t *center, const points_t *points)
{
    if (!center || !points)
        return ERR_NULL_POINTER;
    if (!points->size || !points->arr)
        return ERR_EMPTY;
    
    point_t min_point, max_point;
    myerror_t err = points_rect(&min_point, &max_point, points);
    if (err)
        *center = rect_center(min_point, max_point);

    return err;   
}
