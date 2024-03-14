#include <stdlib.h>
#include "projection.h"

static void point2d_init(point2d_t *point)
{
    if (!point)
        return;
    point->x = 0;
    point->y = 0;
}

static void points2d_init(points2d_t *points)
{
    if (!points)
        return;
    
    points->arr = NULL;
    points->size = 0;
}

void projection_init(projection_t *projection)
{
    if (!projection)
        return;
    point2d_init(&projection->center);
    points2d_init(&projection->points);
    edges_init(&projection->edges);
}

static myerror_t project_point(point2d_t *p2d, const point_t *p3d)
{
    if (!p2d || !p3d)
        return ERR_NULL_POINTER;
    
    p2d->x = p3d->x;
    p2d->y = p3d->y;

    return OK;
}

static myerror_t create_point2d_array(point2d_t **arr, size_t size) {
    if (!arr)
        return ERR_NULL_POINTER;
    
    point2d_t *new = malloc(sizeof(point2d_t) * size);
    if (!new)
        return ERR_MEMORY;
    
    *arr = new;
    return OK;
}

static myerror_t project_points_arr(point2d_t **dst, const point_t *src, size_t size)
{
    if (!dst || !src)
        return ERR_NULL_POINTER;
    if (!size)
        return ERR_EMPTY;
    

    point2d_t *new = NULL;
    myerror_t err = create_point2d_array(&new, size);
    if (!err)
        for (size_t i = 0; !err && i < size; i++)
            err = project_point(new + i, src + i);
    
    if (!err)
        *dst = new;
    return err;
}

static myerror_t project_points(points2d_t *points2d, const points_t *points)
{
    if (!points2d || !points)
        return ERR_NULL_POINTER;
    if (!points->arr || !points->size)
        return ERR_EMPTY;
    
    myerror_t err = project_points_arr(&points2d->arr, points->arr, points->size);
    if (!err)
        points2d->size = points->size;
    
    return err;
        
}

static myerror_t project_edges(edges_t *edges2d, const edges_t *edges3d)
{
    myerror_t err = alloc_edges(edges2d, get_edges_size(edges3d));

    if (!err)
        err = copy_edges(edges2d, edges3d);
    
    return err;
}

static void clear_points2d(points2d_t *points)
{
    if (!points)
        return;
    
    if (points->arr)
        free(points->arr);
    points->size = 0;
}

myerror_t project_figure(projection_t *proj, const figure_t *fig)
{
    if (!proj || !fig)
        return ERR_NULL_POINTER;
    
    myerror_t err = project_point(&proj->center, &fig->center);
    if (!err)
        err = project_points(&proj->points, &fig->points);

    if (!err)
    {
        err = project_edges(&proj->edges, &fig->edges);
        if (err)
            clear_points2d(&proj->points);
    }

    return err;
}


void clear_projection(projection_t *proj)
{
    if (!proj)
        return;
    clear_edges(&proj->edges);
    clear_points2d(&proj->points);
}