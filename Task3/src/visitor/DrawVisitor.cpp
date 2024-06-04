#include "DrawVisitor.h"
#include "BoneModel.h"
#include "Camera.h"
#include "Composite.h"
#include "CameraProjectionAction.h"

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : _drawer(drawer), _camera(camera) {}

Point DrawVisitor::getCameraProjection(const Point& point) const {
    std::cout << "Before: " << point.GetX() << " " << point.GetY() << " " << point.GetZ() << std::endl;
    CameraProjectionAction action(_camera);
    Point copy(point);
    action.TransformPoint(copy);
    std::cout << "After: " << copy.GetX() << " " << copy.GetY() << " " << copy.GetZ() << std::endl;
    return copy;
    // Point &cameraPoint = _camera->_self;
    // return Point(point.GetX() - cameraPoint.GetX(), point.GetY() - cameraPoint.GetY(), point.GetZ() - cameraPoint.GetZ());
}

#define FOCUS 500.0
#define R (1 / FOCUS)

void DrawVisitor::visit(BoneModel& model) const {
    auto points = model._model->GetPoints();
    auto edges = model._model->GetEdges();

    for (auto &edge : edges) {
        Point &p1 = points[edge.GetFirst()];
        Point &p2 = points[edge.GetSecond()];
        Point proj1(getCameraProjection(p1));
        Point proj2(getCameraProjection(p2));
        
        proj1.SetX(proj1.GetX() * (1 / (R * proj1.GetZ())));
        proj1.SetY(proj1.GetY() * (1 / (R * proj1.GetZ())));

        proj2.SetX(proj2.GetX() * (1 / (R * proj2.GetZ())));
        proj2.SetY(proj2.GetY() * (1 / (R * proj2.GetZ())));

        if (proj1.GetZ() > 0 && proj2.GetZ() > 0) {
            _drawer->DrawLine(proj1, proj2);
        }
        
    }
}
void DrawVisitor::visit(Camera& camera) const {
    (void) camera;
}
void DrawVisitor::visit(Composite& composite) const {
    for (auto &child : composite) {
        child->accept(*this);
    }
}