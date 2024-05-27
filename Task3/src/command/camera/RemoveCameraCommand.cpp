#include "RemoveCameraCommand.h"


RemoveCameraCommand::RemoveCameraCommand(std::size_t id) : _id(id) {}
void RemoveCameraCommand::Execute() {
    _sceneManager->RemoveCamera(_id);
}
