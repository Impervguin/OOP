#include <QGraphicsScene>
#include "draw.hpp"

extern "C" {
    #include "errs.h"
    #include "figure.h"
    #include "point.h"
    #include "edges.h"
    #include "points.h"
    #include "projection.h"
}

myerror_t clear_scene(const draw_t& draw)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    draw.scene->clear();
    return OK;
}

point2d_t on_screen_point(const draw_t &draw, const point2d_t &source)
{
    point2d_t on_screen;
    on_screen.x = draw.width / 2 + source.x;
    on_screen.y = draw.height / 2 - source.y;
    return on_screen;
}

myerror_t draw_line(const draw_t &draw, const point2d_t &p1, const point2d_t &p2)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    point2d_t sc_p1 = on_screen_point(draw, p1);
    point2d_t sc_p2 = on_screen_point(draw, p2);
    draw.scene->addLine(sc_p1.x, sc_p1.y, sc_p2.x, sc_p2.y);
    return OK;
}

myerror_t draw_edges(const draw_t &draw, const points2d_t &points, const edges_t &edges)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    if (!points.size  || !edges.size)
        return ERR_EMPTY;
    if (!points.arr || !edges.arr)
        return ERR_NULL_POINTER;
    
    myerror_t err = OK;
    for (size_t i = 0; i < edges.size && !err; ++i)
    {
        point2d_t p1 = points.arr[edges.arr[i].p1];
        point2d_t p2 = points.arr[edges.arr[i].p2];
        err = draw_line(draw, p1, p2);
    }

    return err;
}

myerror_t draw_projection(const draw_t &draw, const projection_t &projection)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    return draw_edges(draw, projection.points, projection.edges);
}

myerror_t draw_figure(const draw_t &draw, const figure_t &fig)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    projection_t *proj = NULL;
    myerror_t err = create_projection(&proj, &fig);
    if (!err)
        err = clear_scene(draw);
    if (!err)
        err = draw_projection(draw, *proj);
    
    destroy_projection(proj);
    return err;
}
