#pragma once
#include "Object.h"
#include "Visitor.h"
#include "SceneManager.h"
#include <list>


class Scene {
    friend class SceneManager;
    public:
        using iterator=std::list<std::shared_ptr<Object>>::iterator;
        using const_iterator=std::list<std::shared_ptr<Object>>::const_iterator;
        using reverse_iterator=std::list<std::shared_ptr<Object>>::reverse_iterator;
        using const_reverse_iterator=std::list<std::shared_ptr<Object>>::const_reverse_iterator;
        using size_type=std::list<std::shared_ptr<Object>>::size_type;
        using difference_type=std::list<std::shared_ptr<Object>>::difference_type;
        using iteratorCamera=std::list<iterator>::const_iterator;

        Scene();
        ~Scene() = default;

        void AddObject(const std::shared_ptr<Object> obj);
        void RemoveObject(const const_iterator& it);
        void AddComposite(const std::vector<std::shared_ptr<Object>> objects);

        void AddCamera(const std::shared_ptr<Object> obj);
        void RemoveCamera(const std::list<iterator>::const_iterator &it);
        std::shared_ptr<Object> GetCamera(const iteratorCamera &it);

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
        size_type size() const;

        iteratorCamera beginCamera();
        iteratorCamera endCamera();

        void accept(Visitor &visitor);
        std::shared_ptr<Scene> Clone();

    protected:
        std::list<std::shared_ptr<Object>> _objects;
        std::list<iterator> _cameras;
};