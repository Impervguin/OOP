#pragma once
#include "Object.h"


class VisibleObject : public Object {
    public:
        VisibleObject();
        virtual ~VisibleObject() = 0;

        virtual bool IsVisible() const;
        virtual bool IsComposite() const;
};