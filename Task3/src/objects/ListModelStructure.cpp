#include "../../inc/objects/ListModelStructure.h"


ListModelStructure::ListModelStructure() : _center(Point()), _points(std::vector<Point>()), _edges(std::vector<Edge>()) {};

void ListModelStructure::Transform(const TransformAction& action) {
    for (Point& point : _points) {
        action.TransformPoint(point);
    }
    action.TransformPoint(_center);
}

std::vector<Point> ListModelStructure::GetPoints() const {
    return _points;
}

std::vector<Edge> ListModelStructure::GetEdges() const {
    return _edges;
}

Point ListModelStructure::GetCenter() const {
    Point copy(_center);
    return copy;
}

void ListModelStructure::SetCenter(const Point& center) {
    _center = center;
}

void ListModelStructure::AddPoint(const Point& point) {
    _points.push_back(point);
}

void ListModelStructure::AddEdge(const Edge& edge) {
    _edges.push_back(edge);
}

std::shared_ptr<ModelStructure> ListModelStructure::Clone() const {
    auto cloned = std::make_shared<ListModelStructure>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }
    
    for (const Edge& edge : _edges) {
        cloned->AddEdge(edge);
    }

    return cloned;
}
