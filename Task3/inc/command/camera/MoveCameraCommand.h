#pragma once
#include "BaseCameraCommand.h"


class MoveCameraCommand : public BaseCameraCommand {
    public:
        MoveCameraCommand(std::size_t id, double dx, double dy, double dz);
        MoveCameraCommand() = delete;
        virtual ~MoveCameraCommand() = default;
        virtual void Execute();

    private:
        size_t _id;
        double _dx;
        double _dy;
        double _dz;
};