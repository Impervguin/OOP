#pragma once
#include "BaseLoadCommandDecorator.h"

class TxtLoadCommandDecorator : public BaseLoadCommandDecorator {
    public:
        virtual ~TxtLoadCommandDecorator() = default;
        TxtLoadCommandDecorator() = delete;
        TxtLoadCommandDecorator(BaseLoadCommand &command, const char *filename);
        virtual void Execute();
    protected:
        const char *_filename;
};