#pragma once
#include "BaseCommand.h"

class BaseSceneCommand : public BaseCommand {
    public:
        BaseSceneCommand() = default;
        virtual ~BaseSceneCommand() = 0;

};