#include "BaseBoneModelBuilder.h"


BaseBoneModelBuilder::~BaseBoneModelBuilder() {}

void BaseBoneModelBuilder::BuildPoint(const Point& p) {
    _model->AddPoint(p);
}

void BaseBoneModelBuilder::BuildEdge(const Edge& edge) {
    _model->AddEdge(edge);
}

void BaseBoneModelBuilder::BuildCenter(const Point& center) {
    _model->SetCenter(center);
}

std::shared_ptr<BoneModel> BaseBoneModelBuilder::Get() {
    return std::make_shared<BoneModel>(_model);
}

bool BaseBoneModelBuilder::IsBuilt() {
    return _model->GetPoints().size() != 0;
}