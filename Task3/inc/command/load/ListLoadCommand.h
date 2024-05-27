#pragma once
#include "BaseLoadCommand.h"


class ListLoadCommand : public BaseLoadCommand {
    public:
        ListLoadCommand();
        virtual ~ListLoadCommand() = default;
        virtual void Execute();
};