#include "ShiftAction.h"

ShiftAction::ShiftAction(double x, double y, double z) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = x;
    _matrix[3][1] = y;
    _matrix[3][2] = z;
    _matrix[3][3] = 1.0;
}

ShiftAction::ShiftAction(double x, double y, double z, double w) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = x;
    _matrix[3][1] = y;
    _matrix[3][2] = z;
    _matrix[3][3] = w;
}

ShiftAction::ShiftAction(const Point &p) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = p.GetX();
    _matrix[3][1] = p.GetY();
    _matrix[3][2] = p.GetZ();
    _matrix[3][3] = 1.0;
}