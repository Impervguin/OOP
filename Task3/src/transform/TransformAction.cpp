#include "TransformAction.h"
#include <vector>

TransformAction::TransformAction() : _matrix(SquareMatrix<double>(4)) {
    _matrix[0][0] = 1;
    _matrix[1][1] = 1;
    _matrix[2][2] = 1;
    _matrix[3][3] = 1;
}

Point &TransformAction::TransformPoint(Point &p) const {
    std::vector<double> pvector = {p.GetX(), p.GetY(), p.GetZ(), 1};
    std::vector<double> result = _matrix.MultiplyLeft(pvector);
    if (result[3] == 0) {
        p.SetX(0);
        p.SetY(0);
        p.SetZ(0);
    } else {
        p.SetX(result[0] / result[3]);
        p.SetY(result[1] / result[3]);
        p.SetZ(result[2] / result[3]);
    }

    return p;
}

const SquareMatrix<double> &TransformAction::GetMatrix() const {
    return _matrix;
}

SquareMatrix<double> &TransformAction::GetMatrix() {
    return _matrix;
}