#ifndef ACTIONS_H__
#define ACTIONS_H__

typedef struct move move_t;
typedef struct scale scale_t;
typedef struct rotate rotate_t;

struct move {
    double x, y, z;
};

struct scale {
    double x, y, z;
};

struct rotate {
    double ox, oy, oz;
};



#endif // ACTIONS_H__
