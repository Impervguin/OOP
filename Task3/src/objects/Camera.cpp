#include "Camera.h"
#include "Visitor.h"
#include "DrawVisitor.h"

Camera::Camera() : _self(Point()), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Point &self) : _self(self), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Camera &other) : _self(other._self), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(double x, double y, double z) : _self(Point(x, y, z)), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

void Camera::accept(const Visitor &v) {
    v.visit(*this);
}

void Camera::Transform(const TransformAction &action) {
    _self = action.TransformPoint(_self);
    _normalForward = action.TransformPoint(_normalForward);
    _normalUp = action.TransformPoint(_normalUp);
    _normalRight = action.TransformPoint(_normalRight);
}

bool Camera::IsComposite() const { return false; }

Point Camera::GetCenter() const {
    Point copy(_self);
    return copy;
}