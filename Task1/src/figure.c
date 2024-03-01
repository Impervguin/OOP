#include <stdio.h>
#include <stdlib.h>
#include "points.h"
#include "actions.h"
#include "edges.h"
#include "figure.h"

figure_t *create_figure(void)
{
    figure_t *fig = calloc(1, sizeof(figure_t));
    return fig;
}

void figure_init(figure_t *fig)
{
    fig->center = (point_t){0, 0, 0};
    fig->points = (points_t){0, NULL};
    fig->edges = (edges_t){0, NULL};
}

void clear_figure(figure_t *fig)
{
    fig->center = (point_t){0, 0, 0};
    clear_points(&fig->points);
    clear_edges(&fig->edges);
}

myerror_t copy_figure(figure_t *dst, const figure_t *src)
{
    if (src == NULL || dst == NULL)
        return ERR_NULL_POINTER;
    myerror_t err = copy_points(&dst->points, &src->points);
    if (!err)
        err = copy_edges(&dst->edges, &src->edges);
    if (!err)
        dst->center = src->center;
    return err; 
}

myerror_t read_figure(figure_t *fig, const char *fname)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    FILE *f = fopen(fname, "r");
    if (!f)
        return ERR_NO_FILE;
    
    figure_t tmp;
    figure_init(&tmp);

    myerror_t err = read_points(&tmp.points, f);
    if (!err)
        err = read_edges(&tmp.edges, f);
    
    fclose(f);
    if (!err)
        err = figure_center(&tmp.center, &tmp);
    
    if (!err)
        err = copy_figure(fig, &tmp);
    clear_figure(&tmp);


    return err;
}

myerror_t write_figure(const char *fname, figure_t *fig)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    FILE *f = fopen(fname, "w");
    if (!f)
        return ERR_NO_FILE;
    
    myerror_t err = write_points(f, &fig->points);
    if (!err)
        err = write_edges(f, &fig->edges);
    
    fclose(f);
    return err;
}

myerror_t move_figure(figure_t *fig, move_t *move)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    point_t center = fig->center;

    myerror_t err = move_point(&center, move);
    
    if (!err)
        err = move_points(&fig->points, move);
    
    if (!err)
        fig->center = center;
    
    return err;
}

myerror_t scale_figure(figure_t *fig, scale_t *scale)
{
    if (!fig)
        return ERR_NULL_POINTER;
    return scale_points(&fig->points, scale, &fig->center);
}

myerror_t rotate_figure(figure_t *fig, rotate_t *rotate)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    return rotate_points(&fig->points, rotate, &fig->center);
}

myerror_t figure_center(point_t *center, figure_t *figure)
{
    if (!center || !figure)
        return ERR_NULL_POINTER;
    
    return points_center(center, &figure->points);
}
