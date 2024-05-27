#pragma once
#include "BaseObjectCommand.h"

class ScaleObjectCommand : public BaseObjectCommand {
    public:
        ScaleObjectCommand() = delete;
        virtual ~ScaleObjectCommand() = default;
        ScaleObjectCommand(std::size_t id, double kx, double ky, double kz);

        virtual void Execute();


    private:
        size_t _id;
        double _kx;
        double _ky;
        double _kz;
};