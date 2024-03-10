#ifndef DRAW_H__
#define DRAW_H__
#include <QGraphicsScene>

extern "C" {
    #include "errs.h"
    #include "point.h"
    #include "figure.h"
    #include "points.h"
    #include "edges.h"
    #include "projection.h"
}



struct draw {
    QGraphicsScene *scene;
    double width;
    double height;
};

typedef struct draw draw_t;

myerror_t clear_scene(const draw_t& draw);

myerror_t draw_line(const draw_t &draw, const point2d_t &p1, const point2d_t &p2);

myerror_t draw_figure(const draw_t &draw, const figure_t &fig);


#endif // DRAW_H__
