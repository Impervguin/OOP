#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "points.h"
#include "actions.h"
#include "edges.h"
#include "figure.h"

void figure_init(figure_t *fig)
{
    if (!fig)
        return;
    point_init(&fig->center);
    points_init(&fig->points);
    edges_init(&fig->edges);
}

figure_t get_figure(void)
{
    figure_t fig;
    point_init(&fig.center);
    points_init(&fig.points);
    edges_init(&fig.edges);
    return fig;
}

void clear_figure(figure_t *fig)
{
    if (!fig)
        return;
    point_init(&fig->center);
    clear_points(&fig->points);
    clear_edges(&fig->edges);
}

// static myerror_t copy_figure_nsafe(figure_t *dst, const figure_t *src)
// {
//     if (src == NULL || dst == NULL)
//         return ERR_NULL_POINTER;
    
//     myerror_t err = copy_points(&dst->points, &src->points);
//     if (!err)
//     {
//         err = copy_edges(&dst->edges, &src->edges);
//         if (err)
//             clear_points(&dst->points);
//     }
        
    
//     if (!err)
//         dst->center = src->center;

    
//     return err; 
// }

// myerror_t copy_figure(figure_t *dst, const figure_t *src)
// {
//     if (src == NULL || dst == NULL)
//         return ERR_NULL_POINTER;
    
//     figure_t tmp;
//     figure_init(&tmp);

//     myerror_t err = copy_figure_nsafe(&tmp, src);

//     if (!err)
//     {
//         clear_figure(dst);
//         memcpy(dst, &tmp, sizeof(figure_t));
//     }

//     return err; 
// }

myerror_t copy_figure(figure_t *dst, const figure_t *src)
{
    if (!dst || !src)
        return ERR_NULL_POINTER;
    
    *dst = *src;
    return OK;
}

static myerror_t read_figure_nsafe(figure_t *fig, FILE *f)
{
    myerror_t err = read_points(&fig->points, f);
    
    if (!err)
    {
        err = figure_center(&fig->center, fig);
        if (err)
            clear_points(&fig->points);
    }

    if (!err)
    {
        err = read_edges(&fig->edges, f);
        if (err)
            clear_points(&fig->points);
    }

    return err;
}

static myerror_t figure_verify(figure_t *fig)
{
    size_t psize = get_points_size(&fig->points);
    return edges_verify(&fig->edges, psize);
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
  
    myerror_t err = read_figure_nsafe(&tmp, f);
    fclose(f);

    if (!err)
    {
        err = figure_verify(&tmp);
        if (err)
            clear_figure(&tmp); 
        else
        {
            clear_figure(fig);
            err = copy_figure(fig, &tmp);
        }
            
    }
        

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

myerror_t move_figure(figure_t *fig, const move_t *move)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    point_t center = fig->center;

    myerror_t err = move_point(&center, move);
    
    if (!err)
    {
        err = move_points(&fig->points, move);
        if (!err)
            fig->center = center;
    }
    
    return err;
}

myerror_t scale_figure(figure_t *fig, const scale_t *scale)
{
    if (!fig)
        return ERR_NULL_POINTER;
    return scale_points(&fig->points, scale, &fig->center);
}

myerror_t rotate_figure(figure_t *fig, const rotate_t *rotate)
{
    if (!fig)
        return ERR_NULL_POINTER;
    
    return rotate_points(&fig->points, rotate, &fig->center);
}

myerror_t figure_center(point_t *center, const figure_t *figure)
{
    if (!center || !figure)
        return ERR_NULL_POINTER;
    
    return points_center(center, &figure->points);
}
