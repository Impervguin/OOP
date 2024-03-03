#include <stdlib.h>
#include "projection.h"

myerror_t init_points2d(points2d_t *points, size_t psize)
{
    point2d_t *parr = malloc(psize * sizeof(point2d_t));
    if (!parr)
        return ERR_MEMORY;
    
    points->arr = parr;
    points->size = psize;
    return OK;
}


myerror_t create_projection(projection_t **projection, const figure_t *fig)
{
    if (!fig || !projection)
        return ERR_NULL_POINTER;
    if (fig->points.size == 0 || fig->edges.size == 0)
        return ERR_EMPTY;

    projection_t *tmp = calloc(1, sizeof(projection_t));
    if (!tmp)
        return ERR_MEMORY;
    
    myerror_t err = init_points2d(&tmp->points, fig->points.size);

    for (size_t i = 0; i < fig->points.size && !err; i++)
        err = project_point(&tmp->points.arr[i], &fig->points.arr[i]);
    
    if (!err)
        err = copy_edges(&tmp->edges, &fig->edges);
    
    if (!err)
        err = project_point(&tmp->center, &fig->center);
    
    if (!err)
        *projection = tmp;
    else
        destroy_projection(tmp);
    
    return OK;
}



void destroy_projection(projection_t *projection)
{
    if (!projection)
        return;
    if (projection->edges.size != 0)
        clear_edges(&projection->edges);
    if (projection->points.size != 0)
        free(projection->points.arr);
    free(projection);
}

myerror_t project_point(point2d_t *p2d, const point_t *p3d)
{
    if (!p2d || !p3d)
        return ERR_NULL_POINTER;

    p2d->x = p3d->x;
    p2d->y = p3d->y;
    return OK;
}