#pragma once
#include "BaseCommand.h"

class BaseLoadCommand : public BaseCommand {
    public:
        BaseLoadCommand() = default;
        virtual ~BaseLoadCommand() = 0;
        size_t GetDirectorId();
        size_t GetReaderId();
    
    protected:
        size_t _reader_id;
        size_t _director_id;
};