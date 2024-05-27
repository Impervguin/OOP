#pragma once
#include "ModelStructure.h"
#include "Point.h"
#include <vector>


class MatrixModelStructure : public ModelStructure {
    public:
        MatrixModelStructure();
        
        ~MatrixModelStructure() = default;
        virtual void Transform(const TransformAction& action);
        virtual std::vector<Point> GetPoints() const;
        virtual std::vector<Edge> GetEdges() const;
        virtual void AddPoint(const Point& point);
        virtual void AddEdge(const Edge& edge);
        virtual Point GetCenter() const;
        virtual void SetCenter(const Point& center);
        virtual std::shared_ptr<ModelStructure> Clone() const;
    
    private:
        Point _center;

        std::vector<Point> _points;
        SquareMatrix<int> _edgeMatrix;
};