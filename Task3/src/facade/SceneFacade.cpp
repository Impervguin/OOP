#include "SceneFacade.h"

SceneFacade::SceneFacade() {
    _drawManager = std::make_shared<DrawManager>();
    _loadManager = std::make_shared<LoadManager>();
    _sceneManager = std::make_shared<SceneManager>();
    _transformManager = std::make_shared<TransformManager>();
}

void SceneFacade::Execute(BaseCommand& command) {
    command.SetManagers(_sceneManager, _loadManager, _transformManager, _drawManager);
    command.Execute();
}