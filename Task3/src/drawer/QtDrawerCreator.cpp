#include "QtDrawerCreator.h"
#include "QtDrawer.h"
#include <iostream>


QtDrawerCreator::QtDrawerCreator(QGraphicsScene* scene) : _scene(scene) {}

std::shared_ptr<BaseDrawer> QtDrawerCreator::Create() {
    return std::make_shared<QtDrawer>(_scene);
}