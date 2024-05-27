#include "../../inc/objects/Object.h"
#include "../../inc/visitor/Visitor.h"

std::size_t GetNextId() {
    static std::size_t id = 0;
    return ++id;
}

Object::Object() : _id(GetNextId()) {}

Object::~Object() {}


std::size_t Object::GetId() const {
    return _id;
}