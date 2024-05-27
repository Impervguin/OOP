#include "LoadManager.h"
#include "SceneManager.h"
#include "TransformManager.h"
#include "DrawManager.h"
#include "BaseCommand.h"


class SceneFacade {
    public :
        SceneFacade();
        ~SceneFacade() = default;

        void Execute(BaseCommand &command);
    
    private :
        std::shared_ptr<SceneManager> _sceneManager;
        std::shared_ptr<LoadManager> _loadManager;
        std::shared_ptr<TransformManager> _transformManager;
        std::shared_ptr<DrawManager> _drawManager;
};