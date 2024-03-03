#include "interface.hpp"
#include "draw.hpp"

extern "C" {
    #include "figure.h"
}


myerror_t process_request(const request_t &req)
{
    static figure_t fig;
    
    request_type_t req_type = req.type;

    myerror_t err = OK;

    switch (req_type)
    {
    case INIT:
        figure_init(&fig);
        break;
    case CLEAR:
        clear_figure(&fig);
        break;
    case DRAW:
        err = draw_figure(req.data.draw, fig);
        break;
    case MOVE:
        err = move_figure(&fig, &req.data.move);
        break;
    case SCALE:
        err = scale_figure(&fig, &req.data.scale);
        break;
    case ROTATE:
        err = rotate_figure(&fig, &req.data.rotate);
        break;
    case SAVE:
        err = write_figure(req.data.save.fname, &fig);
        break;
    case LOAD:
        err = read_figure(&fig, req.data.load.fname);
        break;
    default:
        err = ERR_UNKNOWN_ACTION;
        break;
    }
    return err;
}