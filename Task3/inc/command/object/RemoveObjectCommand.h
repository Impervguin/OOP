#pragma once
#include "BaseObjectCommand.h"

class RemoveObjectCommand : public BaseObjectCommand {
    public:
        RemoveObjectCommand() = delete;
        virtual ~RemoveObjectCommand() = default;
        RemoveObjectCommand(std::size_t id);

        virtual void Execute();


    private:
        size_t _id;
};