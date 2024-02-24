#include <cstdlib>

extern "C" {
    #include "figure.h"
    #include "errs.h"
}

int main(void)
{
    figure_t *fig = init_figure();

    read_figure("data/cube.txt", fig);
    write_figure("test", fig);
    clear_figure(fig);
    free(fig);
    return 0;
}