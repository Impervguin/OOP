#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager() : _scene(std::make_shared<Scene>()), _camera(std::make_shared<Camera>()) {}


void SceneManager::SetScene(std::shared_ptr<Scene> scene) {
    _scene = scene;
}
std::shared_ptr<Scene> SceneManager::GetScene() {
    return _scene;
}

void SceneManager::SetCamera(std::shared_ptr<Camera> camera) {
    _camera = camera;
}

void SceneManager::AddObject(std::shared_ptr<Object> object) {
    _scene->AddObject(object);
}


std::vector<std::shared_ptr<Object>> SceneManager::GetObjects() {
    std::vector<std::shared_ptr<Object>> objects;
    for (auto it = _scene->begin(); it != _scene->end(); ++it) {
        objects.push_back(*it);
    }
    return objects;
}

void SceneManager::AddCamera(const Point& pos) {
    auto camera = std::make_shared<Camera>(pos);
    _scene->AddCamera(camera);
}

std::shared_ptr<Object> SceneManager::GetObject(std::size_t id) {
    for (auto it = _scene->begin(); it != _scene->end(); ++it) {
        if ((*it)->GetId() == id) {
            return *it;
        }
    }
    return nullptr;
}

void SceneManager::RemoveObject(std::size_t id) {
    for (auto it = _scene->cbegin(); it!= _scene->cend(); ++it) {
        if ((*it)->GetId() == id) {
            _scene->RemoveObject(it);
            return;
        }
    }
}

std::vector<std::shared_ptr<Object>> SceneManager::GetCameras() {
    std::vector<std::shared_ptr<Object>> cameras;
    for (auto it = _scene->beginCamera(); it!= _scene->endCamera(); ++it) {
        cameras.push_back(**it);
    }
    return cameras;
}

std::shared_ptr<Camera> SceneManager::GetCamera(std::size_t id) {
    for (auto it = _scene->beginCamera(); it!= _scene->endCamera(); ++it) {
        if ((**it)->GetId() == id) {
            auto obj = std::dynamic_pointer_cast<Camera>(**it);
            if (obj == nullptr) {
                throw std::runtime_error("Object is not a camera");
            }
            return obj;
        }
    }
    return nullptr;
}
void SceneManager::RemoveCamera(std::size_t id) {
    for (auto it = _scene->beginCamera(); it!= _scene->endCamera(); ++it) {
        if ((**it)->GetId() == id) {
            _scene->RemoveCamera(it);
            return;
        }
    }
}

void SceneManager::SetCamera(std::size_t id) {
    _camera = GetCamera(id);
}

void SceneManager::ClearScene() {
    _scene->_cameras.clear();
    _scene->_objects.clear();
}

std::shared_ptr<Camera> SceneManager::GetMainCamera() {
    return _camera;
}

std::vector<std::size_t> SceneManager::GetObjectIds() {
    std::vector<std::size_t> ids;
    for (auto it = _scene->begin(); it!= _scene->end(); ++it) {
        ids.push_back((*it)->GetId());
    }
    return ids;
}

std::vector<std::size_t> SceneManager::GetCameraIds() {
    std::vector<std::size_t> ids;
    for (auto it = _scene->beginCamera(); it!= _scene->endCamera(); ++it) {
        ids.push_back((**it)->GetId());
    }
    return ids;
}


void SceneManager::MakeComposite(std::vector<size_t> ids) {
    std::vector<std::shared_ptr<Object>> objects;
    for (auto it = ids.begin(); it!= ids.end(); ++it) {
        objects.push_back(GetObject(*it));
    }
    _scene->AddComposite(objects);
}