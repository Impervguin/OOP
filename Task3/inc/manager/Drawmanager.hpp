#pragma once
#include "DrawManager.h"

template <typename DrawerCreator, typename... Args>
requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args) {
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer>drawer = drawerCreator.Create();
    DrawVisitor vis(drawer, camera);
    for (auto it = scene->begin(); it != scene->end(); ++it) {
        (*it)->accept(vis);
    }
}