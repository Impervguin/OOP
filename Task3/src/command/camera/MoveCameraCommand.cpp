#include "MoveCameraCommand.h"

MoveCameraCommand::MoveCameraCommand(std::size_t id, double dx, double dy, double dz)
: _id(id), _dx(dx), _dy(dy), _dz(dz) {}

void MoveCameraCommand::Execute() {
    auto cam = _sceneManager->GetCamera(_id);
    _transformManager->ShiftObject(cam, _dx, _dy, _dz);
}
