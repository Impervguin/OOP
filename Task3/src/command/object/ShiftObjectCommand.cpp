#include "ShiftObjectCommand.h"

ShiftObjectCommand::ShiftObjectCommand(std::size_t id, double x, double y, double z)
: _id(id), _x(x), _y(y), _z(z) {}

void ShiftObjectCommand::Execute() {
    auto obj = _sceneManager->GetObject(_id);
    _transformManager->ShiftObject(obj, _x, _y, _z);
}