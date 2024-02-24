#include <cstdlib>

extern "C" {
    #include "actions.h"
    #include "figure.h"
    #include "errs.h"
}

#include <QOpenGLWidget>
#include <QApplication>
#include <QGraphicsView>
#include "window.hpp"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Window window;
 window.show();

 return app.exec();

    // figure_t *fig = init_figure();
    // read_figure("./data/cube.txt", fig);
    // for (size_t i = 0; i < fig->edges.size; i++)
    // {
    //     printf("glColor3f(1, 1, 1);\n");
    //     printf("glVertex3d(%lf, %lf, %lf);\n", fig->points.arr[fig->edges.arr[i].p1].x,fig->points.arr[fig->edges.arr[i].p1].y,fig->points.arr[fig->edges.arr[i].p1].z);
    //     printf("glVertex3d(%lf, %lf, %lf);\n", fig->points.arr[fig->edges.arr[i].p2].x,fig->points.arr[fig->edges.arr[i].p2].y,fig->points.arr[fig->edges.arr[i].p2].z);
    // }
}