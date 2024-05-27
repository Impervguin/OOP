#pragma once
#include "BaseDrawer.h"
#include <QGraphicsScene>


class QtDrawer : public BaseDrawer {
    public:
        QtDrawer() = delete;
        QtDrawer(QGraphicsScene* scene);
        virtual ~QtDrawer() = default;
        virtual void DrawLine(const Point& p1, const Point& p2);
        virtual void Clear();
    private:
        QGraphicsScene* _scene;
};