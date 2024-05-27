#include "BaseBoneModelDirector.h"
#include "directorexception.h"
#include <iostream>


BaseBoneModelDirector::~BaseBoneModelDirector() {};

BaseBoneModelDirector::BaseBoneModelDirector(std::shared_ptr<BoneModelReader> reader)
: _strategy(std::make_shared<ClassicCenterStrategy>()), _reader(reader)  {}

void BaseBoneModelDirector::Create() {
    if (_reader == nullptr) {
        std::cout << "BaseBoneModelDirector::Create" << std::endl;
    }
    _reader->Open();
    auto points = _reader->ReadPoints();
    auto edges = _reader->ReadEdges();
    _reader->Close();

    for (auto &p : points) {
        _builder->BuildPoint(p);
    }
    for (auto &e : edges) {
        _builder->BuildEdge(e);
    }

    _builder->BuildCenter(_strategy->CenterAlgorithm(points));
}

std::shared_ptr<Object> BaseBoneModelDirector::Get() {
    return _builder->Get();
}