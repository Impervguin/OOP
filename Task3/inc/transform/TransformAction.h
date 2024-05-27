#pragma once
#include "Point.h"
#include "SquareMatrix.h"

class TransformAction {
    public:
    TransformAction();

    virtual ~TransformAction() = default;

    Point &TransformPoint(Point &p) const;
    const SquareMatrix<double> &GetMatrix() const;
    SquareMatrix<double> &GetMatrix();

    protected:
        SquareMatrix<double> _matrix;
};