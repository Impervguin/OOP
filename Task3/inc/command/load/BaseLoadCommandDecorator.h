#pragma once
#include "BaseLoadCommand.h"


class BaseLoadCommandDecorator : public BaseLoadCommand {
    public:
        BaseLoadCommandDecorator(BaseLoadCommand &command);
        virtual ~BaseLoadCommandDecorator() = 0;
    
    protected:
        BaseLoadCommand& _command;

};