#pragma once
#include "BaseCommand.h"


class BaseCameraCommand : public BaseCommand {
    public:
        BaseCameraCommand() = default;
        virtual ~BaseCameraCommand() = 0;
};