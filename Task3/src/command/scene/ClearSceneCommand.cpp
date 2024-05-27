#include "ClearSceneCommand.h"


void ClearSceneCommand::Execute() {
    _sceneManager->ClearScene();
}