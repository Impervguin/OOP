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
}