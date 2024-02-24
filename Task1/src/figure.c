#include <stdio.h>
#include <stdlib.h>
#include "points.h"
#include "actions.h"
#include "edges.h"
#include "figure.h"

figure_t *init_figure(void)
{
    figure_t *fig = malloc(sizeof(figure_t));
    return fig;
}



void clear_figure(figure_t *fig)
{
    clear_points(&fig->points);
    clear_edges(&fig->edges);
}

error_t copy_figure(const figure_t *src, figure_t *dst)
{
    if (src == NULL || dst == NULL)
        return ERR_NULL_POINTER;
    error_t err = copy_points(&src->points, &dst->points);
    if (!err)
        err = copy_edges(&src->edges, &dst->edges);
    return err; 
}

error_t read_figure(const char *fname, figure_t *fig)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    FILE *f = fopen(fname, "r");
    if (!f)
        return ERR_NO_FILE;
    
    figure_t tmp;

    error_t err = read_points(f, &tmp.points);
    if (!err)
        err = read_edges(f, &tmp.edges);
    
    fclose(f);
    if (!err)
        err = copy_figure(&tmp, fig);
    return err;
}

error_t write_figure(const char *fname, figure_t *fig)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    FILE *f = fopen(fname, "w");
    if (!f)
        return ERR_NO_FILE;
    
    error_t err = write_points(f, &fig->points);
    if (!err)
        err = write_edges(f, &fig->edges);
    
    fclose(f);
    return err;
}

error_t move_figure(figure_t *fig, move_t *move)
{
    return move_points(&fig->points, move);
}

error_t scale_figure(figure_t *fig, scale_t *scale)
{
    return scale_points(&fig->points, scale);
}

error_t rotate_figure(figure_t *fig, rotate_t *rotate)
{
    return rotate_points(&fig->points, rotate);
}

