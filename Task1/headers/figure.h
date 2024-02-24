#ifndef FIGURE_H__
#define FIGURE_H__

#include <stdio.h>
#include "actions.h"
#include "points.h"
#include "edges.h"
#include "errs.h"

typedef struct figure figure_t;

struct figure {
    points_t points;
    edges_t edges;
};

figure_t *init_figure(void);
void clear_figure(figure_t *fig);
error_t copy_figure(const figure_t *src, figure_t *dst);

error_t read_figure(const char *fname, figure_t *fig);
error_t write_figure(const char *fname, figure_t *fig);

error_t move_figure(figure_t *fig, move_t *move);
error_t scale_figure(figure_t *fig, scale_t *scale);
error_t rotate_figure(figure_t *fig, rotate_t *rotate);

#endif // FIGURE_H__
