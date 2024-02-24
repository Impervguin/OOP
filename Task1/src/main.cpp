#include <cstdlib>
#include <cmath>

extern "C" {
    #include "actions.h"
    #include "figure.h"
    #include "errs.h"
}

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