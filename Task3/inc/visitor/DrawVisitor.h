#pragma once
#include "Visitor.h"
#include "BaseDrawer.h"

class DrawVisitor : public Visitor {
    public:
        DrawVisitor() = delete;
        DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
        ~DrawVisitor() = default;

        virtual void visit(BoneModel& model) const;
        virtual void visit(Camera& camera) const ;
        virtual void visit(Composite& composite) const;


    private:
        Point getCameraProjection(const Point& point) const;
        std::shared_ptr<BaseDrawer> _drawer;
        std::shared_ptr<Camera> _camera;
};