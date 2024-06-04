#pragma once
#include "InvisibleObject.h"
#include "TransformAction.h"
#include "DrawVisitor.h"
#include "CameraProjectionAction.h"


class Camera : public InvisibleObject {
    friend class DrawVisitor;
    friend class CameraProjectionAction;
    public:
        Camera();
        Camera(double x, double y, double z);
        explicit Camera(const Point &p);
        explicit Camera(const Camera &other);

        virtual bool IsComposite() const;
        virtual void Transform(const TransformAction &action);
        virtual void accept(const Visitor &visitor);
        virtual Point GetCenter() const;

        virtual ~Camera() = default;

    protected:
        Point _self;
        Point _normalForward;
        Point _normalUp;
        Point _normalRight;
};