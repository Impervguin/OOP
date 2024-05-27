#include "Camera.h"
#include "Visitor.h"
#include "DrawVisitor.h"

Camera::Camera() : _self(Point()) {}

Camera::Camera(const Point &self) : _self(self) {}

Camera::Camera(const Camera &other) : _self(other._self) {}

Camera::Camera(double x, double y, double z) : _self(Point(x, y, z)) {}

void Camera::accept(const Visitor &v) {
    v.visit(*this);
}

void Camera::Transform(const TransformAction &action) {
    _self = action.TransformPoint(_self);
}

bool Camera::IsComposite() const { return false; }

Point Camera::GetCenter() const {
    Point copy(_self);
    return copy;
}