#pragma once
#include "BaseDrawerCreator.h"
#include <QGraphicsScene>

class QtDrawerCreator : public BaseDrawerCreator {
    public:
        QtDrawerCreator(QGraphicsScene* scene);
        QtDrawerCreator() = delete;
        ~QtDrawerCreator() = default;

        std::shared_ptr<BaseDrawer> Create();

    private:
        QGraphicsScene* _scene;
};