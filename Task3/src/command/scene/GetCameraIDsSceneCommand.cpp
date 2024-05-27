#include "GetCameraIDsSceneCommand.h"

GetCameraIDsSceneCommand::GetCameraIDsSceneCommand() : _ids(std::vector<std::size_t>()) {}

void GetCameraIDsSceneCommand::Execute() {
    _ids = _sceneManager->GetCameraIds();
}
std::vector<std::size_t> GetCameraIDsSceneCommand::GetIDs() {
    return _ids;
}