#pragma once
#include "BaseCameraCommand.h"

class RemoveCameraCommand : public BaseCameraCommand {
    public:
        RemoveCameraCommand(std::size_t id);
        RemoveCameraCommand() = delete;
        virtual ~RemoveCameraCommand() = default;
        virtual void Execute();

    private:
        size_t _id;
};