#include <cstdlib>
#include <cmath>

extern "C" {
    #include "actions.h"
    #include "figure.h"
    #include "errs.h"
}

int main(void)
{
    figure_t *fig = init_figure();

    read_figure("data/cube.txt", fig);
    // move_t move = {1, 1, 2};
    // move_figure(fig, &move);

    // scale_t scale = {2, 2, 3};
    // scale_figure(fig, &scale);

    rotate_t rotate = {0, M_PI / 4, 0};
    rotate_figure(fig, &rotate);
    write_figure("test", fig);
    clear_figure(fig);
    free(fig);
    return 0;
}