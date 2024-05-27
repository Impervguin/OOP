#pragma once
#include "BaseDrawer.h"
#include <memory>

class BaseDrawerCreator {
    public:
        BaseDrawerCreator() = default;
        virtual ~BaseDrawerCreator() = 0;

        virtual std::shared_ptr<BaseDrawer> Create() = 0;
};