#pragma once
#include "BaseCommand.h"


class BaseDrawCommand : public BaseCommand {
    public:
        BaseDrawCommand() = default;
        virtual ~BaseDrawCommand() = 0;
};