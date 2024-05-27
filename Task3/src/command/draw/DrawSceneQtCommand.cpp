#include "DrawSceneQtCommand.h"
#include "QtDrawerCreator.h"
#include <iostream>


DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene* sceneQt)
{
    _sceneQt = sceneQt;
}


void DrawSceneQtCommand::Execute() {
    auto camera = _sceneManager->GetMainCamera();
    auto scene = _sceneManager->GetScene();
    _drawManager->DrawScene<QtDrawerCreator, QGraphicsScene*>(scene, camera, _sceneQt);
}
