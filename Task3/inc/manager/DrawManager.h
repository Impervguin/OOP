#pragma once
#include "DrawVisitor.h"
#include "Scene.h"
#include "concept.h"
#include "BaseDrawerCreator.h"
#include <memory>


class DrawManager {
    public:
        DrawManager() = default;
        ~DrawManager() = default;
        
        template <typename DrawerCreator, typename... Args>
        requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
        void DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args);
};

#include "Drawmanager.hpp"
