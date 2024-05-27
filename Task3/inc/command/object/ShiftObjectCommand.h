#pragma once
#include "BaseObjectCommand.h"

class ShiftObjectCommand : public BaseObjectCommand {
    public:
        ShiftObjectCommand() = delete;
        virtual ~ShiftObjectCommand() = default;
        ShiftObjectCommand(std::size_t id, double x, double y, double z);

        virtual void Execute();


    private:
        size_t _id;
        double _x;
        double _y;
        double _z;
};