#pragma once
#include "../transform/TransformAction.h"
#include <memory>
#include <vector>
#include <cstddef>

class Visitor;

std::size_t GetNextId();

class Object {
    public:
        using iterator = std::vector<std::shared_ptr<Object>>::iterator;
        Object();
        virtual ~Object() = 0;

        


        virtual void Add(std::shared_ptr<Object> obj) { (void) obj;};
        virtual void Remove(const iterator &it) { (void) it; };
        virtual void Transform(const TransformAction& action) { (void) action;};
        virtual iterator begin() { return iterator(); };
        virtual iterator end() { return iterator(); };
        virtual void accept(const Visitor &visitor) { (void) visitor; };
        virtual std::shared_ptr<Object> Clone() const { return nullptr;};
        
        virtual std::size_t GetId() const;

        virtual Point GetCenter() const = 0;
        virtual bool IsVisible() const = 0;
        virtual bool IsComposite() const = 0;
    
    protected:
        std::size_t _id = 0;


};