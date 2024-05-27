#include "QtDrawer.h"
#include <iostream>

QtDrawer::QtDrawer(QGraphicsScene* scene) : _scene(scene) {}

void QtDrawer::DrawLine(const Point& p1, const Point& p2) {
    _scene->addLine(p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY());
}

void QtDrawer::Clear() {
    _scene->clear();
}