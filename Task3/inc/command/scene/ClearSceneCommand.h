#pragma once
#include "BaseSceneCommand.h"

class ClearSceneCommand : public BaseSceneCommand {
    public:
        ClearSceneCommand() = default;
        virtual ~ClearSceneCommand() = default;

        virtual void Execute();
};