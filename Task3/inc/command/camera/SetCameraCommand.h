#pragma once
#include "BaseCameraCommand.h"


class SetCameraCommand : public BaseCameraCommand {
    public:
        SetCameraCommand(std::size_t id);
        SetCameraCommand() = delete;
        virtual ~SetCameraCommand() = default;

        virtual void Execute();
    
    private:
        size_t _id;

};