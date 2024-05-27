#include "GetObjectIDsSceneCommand.h"

GetObjectIDsSceneCommand::GetObjectIDsSceneCommand() : _ids(std::vector<std::size_t>()) {}

void GetObjectIDsSceneCommand::Execute() {
    _ids = _sceneManager->GetObjectIds();
}
std::vector<std::size_t> GetObjectIDsSceneCommand::GetIDs() {
    return _ids;
}