#pragma once
#include "Object.h"
#include <memory>

class Composite : public Object {
    public:
        Composite() = default;
        Composite(std::vector<std::shared_ptr<Object>> objects);

        virtual ~Composite() = default;
        virtual std::shared_ptr<Object> Clone() const;
        virtual void Add(const std::shared_ptr<Object> object);
        virtual void Remove(const iterator &it);
        virtual void Transform(const TransformAction& transform);
        virtual void accept(const Visitor &visitor);
        virtual bool IsComposite() const;
        virtual bool IsVisible() const;
        virtual Point GetCenter() const;
        virtual iterator begin();
        virtual iterator end();

    protected:
        std::vector<std::shared_ptr<Object>> _objects;

};