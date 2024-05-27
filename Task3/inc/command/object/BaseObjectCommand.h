#pragma once
#include "BaseCommand.h"


class BaseObjectCommand : public BaseCommand {
    public:
        BaseObjectCommand() = default;
        virtual ~BaseObjectCommand() = 0;
};