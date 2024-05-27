#pragma once
#include "BaseModel.h"
#include "ModelStructure.h"
#include "../transform/TransformAction.h"
#include <memory>
#include "DrawVisitor.h"


class Visitor;

class BoneModel : public BaseModel {
    friend class DrawVisitor;
    public:
        BoneModel();
        explicit BoneModel(std::shared_ptr<ModelStructure>);
        explicit BoneModel(const BoneModel& other);
        ~BoneModel() = default;

        virtual void accept(const Visitor& visitor);
        virtual void Transform(const TransformAction& action);
        virtual Point GetCenter() const;

    protected:
        std::shared_ptr<ModelStructure> _model;

};