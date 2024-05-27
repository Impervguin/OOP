#pragma once
#include "BoneModel.h"
#include "ModelStructure.h"


class BaseBoneModelBuilder {
    public:
        BaseBoneModelBuilder() = default;

        virtual ~BaseBoneModelBuilder() = 0;

        virtual std::shared_ptr<BoneModel> Get();
        virtual void BuildPoint(const Point &p);
        virtual void BuildEdge(const Edge &edge);
        virtual void BuildCenter(const Point &center);
        virtual bool IsBuilt();
    protected:
        std::shared_ptr<ModelStructure> _model;
};