#include "RotateAction.h"
#include "ShiftAction.h"
#include <vector>
#include <cmath>

RotateAction::RotateAction(double ox, double oy, double oz) {
    SquareMatrix<double> z(4);
    z[0][0] = cos(oz);
    z[0][1] = sin(oz);
    z[1][0] = -sin(oz);
    z[1][1] = cos(oz);
    z[2][2] = 1;
    z[3][3] = 1;

    SquareMatrix<double> y(4);
    y[0][0] = cos(oy);
    y[0][2] = -sin(oy);
    y[1][1] = 1;
    y[2][0] = sin(oy);
    y[2][2] = cos(oy);
    y[3][3] = 1;

    SquareMatrix<double> x(4);
    x[0][0] = 1;
    x[1][1] = cos(ox);
    x[1][2] = sin(ox);
    x[2][1] = -sin(ox);
    x[2][2] = cos(ox);
    x[3][3] = 1;

    _matrix *= x * y * z;
}

RotateAction::RotateAction(const Point & center, double ox, double oy, double oz) {
    ShiftAction toCenter(Point(-center.GetX(), -center.GetY(), -center.GetZ()));
    _matrix *= toCenter.GetMatrix();
    RotateAction rotate(ox, oy, oz);
    _matrix *= rotate.GetMatrix();
    ShiftAction fromCenter(center);
    _matrix *= fromCenter.GetMatrix();
}