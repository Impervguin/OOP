#pragma once
#include "Point.h"

class BaseDrawer {
    public:
        BaseDrawer() = default;
        virtual ~BaseDrawer() = 0;

        virtual void DrawLine(const Point& p1, const Point& p2) = 0;
        virtual void Clear() = 0;
};