#include "../../inc/objects/Point.h"


Point::Point(double x, double y, double z) : _x(x), _y(y), _z(z) {};

// Point::Point(const Point& p) : _x(p._x), _y(p._y), _z(p._z) {};


double Point::GetX() const {
    return _x;
}

double Point::GetY() const {
    return _y;
}

double Point::GetZ() const {
    return _z;
}

void Point::SetX(double x) {
    _x = x;
}

void Point::SetY(double y) {
    _y = y;
}


void Point::SetZ(double z) {
    _z = z;
}

void Point::Set(const Point& p) {
    _x = p._x;
    _y = p._y;
    _z = p._z;   
}

void Point::Set(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

bool Point::IsEqual(const Point& p) const {
    return _x == p._x && _y == p._y && _z == p._z;
}

bool Point::IsNotEqual(const Point& p) const {
    return !IsEqual(p);
}

bool Point::operator==(const Point& p) const {
    return IsEqual(p);
}

bool Point::operator!=(const Point& p) const {
    return IsNotEqual(p);
}