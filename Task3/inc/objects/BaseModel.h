#pragma once
#include "VisibleObject.h"


class BaseModel : public VisibleObject {
    public:
        BaseModel();
        virtual ~BaseModel() = 0;

        virtual void Add(std::shared_ptr<Object> obj) { (void) obj;};
        virtual void Remove(const iterator &it) { (void) it; };
        virtual void Transform(const TransformAction& action) { (void) action;};
        virtual iterator begin() { return iterator(); };
        virtual iterator end() { return iterator(); };
        virtual void accept(const Visitor &visitor) { (void) visitor; };
        virtual std::shared_ptr<Object> Clone() const { return nullptr;};


};