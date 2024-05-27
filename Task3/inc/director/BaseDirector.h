#pragma once
#include "Object.h"


class BaseDirector {
    public:
        BaseDirector() = default;

        virtual ~BaseDirector() = 0;

        virtual void Create() = 0;
        virtual std::shared_ptr<Object> Get() = 0;
};