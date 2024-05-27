#pragma once
#include <memory>

class BoneModel;
class Camera;
class Composite;

class Visitor {
    public:
        Visitor() {};

        virtual ~Visitor() {};
        virtual void visit(BoneModel& model) const = 0;
        virtual void visit(Camera& camera) const = 0;
        virtual void visit(Composite& composite) const = 0;
};