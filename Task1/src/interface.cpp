#include "interface.hpp"
#include "draw.hpp"

extern "C" {
    #include "figure.h"
}

static int INIT = 0;

myerror_t process_request(const request_t &req)
{
    static figure_t fig;
    if (!INIT)
    {
        INIT = 1;
        figure_init(&fig);
    }

    myerror_t err = OK;
    switch (req.type)
    {
    case CLEAR:
        clear_figure(&fig);
        break;
    case DRAW:
        err = draw_figure(req.draw, fig);
        break;
    case MOVE:
        err = move_figure(&fig, &req.move);
        break;
    case SCALE:
        err = scale_figure(&fig, &req.scale);
        break;
    case ROTATE:
        err = rotate_figure(&fig, &req.rotate);
        break;
    case SAVE:
        err = write_figure(req.savefname, &fig);
        break;
    case LOAD:
        err = read_figure(&fig, req.loadfname);
        break;
    default:
        err = ERR_UNKNOWN_ACTION;
        break;
    }
    return err;
}