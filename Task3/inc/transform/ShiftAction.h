#pragma once
#include "TransformAction.h"
#include "SquareMatrix.h"
#include "Point.h" 

class ShiftAction : public TransformAction {
    public:
        ShiftAction(double sx, double sy, double sz);
        ShiftAction(const Point &p);
        ShiftAction(double x, double y, double z, double w);
        ShiftAction();

        virtual ~ShiftAction() = default;
};