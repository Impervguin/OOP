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


static myerror_t check_draw_scene(const draw_t &draw)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    return OK;
}

myerror_t clear_scene(const draw_t& draw)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    draw.scene->clear();
    return OK;
}

point2d_t on_screen_point(double width, double height, const point2d_t &source)
{
    point2d_t on_screen;
    on_screen.x = width / 2 + source.x;
    on_screen.y = height / 2 - source.y;
    return on_screen;
}

myerror_t draw_line(const draw_t &draw, const point2d_t &p1, const point2d_t &p2)
{
    if (!draw.scene)
        return ERR_NO_SCENE;
    
    point2d_t sc_p1 = on_screen_point(draw.width, draw.height, p1);
    point2d_t sc_p2 = on_screen_point(draw.width, draw.height, p2);
    draw.scene->addLine(sc_p1.x, sc_p1.y, sc_p2.x, sc_p2.y);
    return OK;
}

static myerror_t draw_edge(const draw_t &draw, const points2d_t &points, const edge_t &edge)
{
    if (check_draw_scene(draw))
        return ERR_NO_SCENE;
    if (!points.size || !points.arr)
        return ERR_EMPTY;
    if (edge.p1 >= points.size || edge.p2 >= points.size)
        return ERR_RANGE;

    return draw_line(draw, points.arr[edge.p1], points.arr[edge.p2]);
}

static myerror_t draw_edges(const draw_t &draw, const points2d_t &points, const edges_t &edges)
{
    if (check_draw_scene(draw))
        return ERR_NO_SCENE;
    if (!points.size  || !edges.size || !points.arr || !edges.arr)
        return ERR_EMPTY;
    
    myerror_t err = OK;
    for (size_t i = 0; i < edges.size && !err; ++i)
        err = draw_edge(draw, points, edges.arr[i]);

    return err;
}

static myerror_t draw_projection(const draw_t &draw, const projection_t &projection)
{
    if (check_draw_scene(draw))
        return ERR_NO_SCENE;
    
    return draw_edges(draw, projection.points, projection.edges);
}

myerror_t draw_figure(const draw_t &draw, const figure_t &fig)
{
    if (check_draw_scene(draw))
        return ERR_NO_SCENE;
    
    projection_t proj;
    projection_init(&proj);

    myerror_t err = project_figure(&proj, &fig);
    
    if (!err)
    {
        err = clear_scene(draw);
        if (!err)
            err = draw_projection(draw, proj);
    }
        
    clear_projection(&proj);
    return err;
}


