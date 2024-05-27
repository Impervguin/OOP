#pragma once
#include "Object.h"


class InvisibleObject : public Object {
    public:
        InvisibleObject();
        virtual ~InvisibleObject() = 0;

        virtual bool IsVisible() const;
        virtual bool IsComposite() const;
};