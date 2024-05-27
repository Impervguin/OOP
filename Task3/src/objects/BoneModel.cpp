#include "../../inc/objects/BoneModel.h"
#include "../../inc/visitor/Visitor.h"


BoneModel::BoneModel() : _model(nullptr) {}

BoneModel::BoneModel(std::shared_ptr<ModelStructure> model) : _model(model) {}

BoneModel::BoneModel(const BoneModel &model) : _model(model._model) {}

void BoneModel::accept(const Visitor& v) {
    v.visit(*this);
}

void BoneModel::Transform(const TransformAction& action) {
    _model->Transform(action);
}

Point BoneModel::GetCenter() const {
    return _model->GetCenter();
}