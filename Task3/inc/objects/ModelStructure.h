#pragma once
#include "../transform/TransformAction.h"
#include "Edge.h"
#include "Point.h"
#include <vector>
#include <memory>


class ModelStructure {
    public:
        ModelStructure() = default;
        ModelStructure(const ModelStructure& other) = delete;
        ModelStructure(ModelStructure&& other) = delete;
        virtual ~ModelStructure() = 0;

        virtual void Transform(const TransformAction& action) = 0;
        virtual std::vector<Point> GetPoints() const = 0;
        virtual std::vector<Edge> GetEdges() const = 0;
        virtual void AddPoint(const Point& point) = 0;
        virtual void AddEdge(const Edge& edge) = 0;
        virtual Point GetCenter() const = 0;
        virtual void SetCenter(const Point& center) = 0;
        virtual std::shared_ptr<ModelStructure> Clone() const = 0;
};