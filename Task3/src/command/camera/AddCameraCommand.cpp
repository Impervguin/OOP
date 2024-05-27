#include "AddCameraCommand.h"

AddCameraCommand::AddCameraCommand(const Point &pos) : _pos(pos) {}

void AddCameraCommand::Execute() {
    _sceneManager->AddCamera(_pos);
}
