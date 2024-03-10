#ifndef INTERFACE_H__
#define INTERFACE_H__

#include "actions.h"
#include "draw.hpp"

typedef enum {
    DRAW,
    SCALE,
    MOVE,
    ROTATE,
    SAVE,
    LOAD,
    CLEAR
} request_type_t;

typedef struct request request_t;



struct request
{
    request_type_t type;
    union 
    {
        draw_t draw;
        move_t move;
        scale_t scale;
        rotate_t rotate;
        const char *savefname;
        const char *loadfname;
    };
};

myerror_t process_request(const request_t &req);

#endif // INTERFACE_H__
