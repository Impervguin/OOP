#pragma once
#include "BaseDirectorCreator.h"
#include "DirectorCreator.h"
#include <map>

class DirectorSolution {
    public:
        DirectorSolution();
        DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list);

        void Register(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator);
        bool Check(std::size_t index);
        std::shared_ptr<BaseDirectorCreator> Create(std::size_t index);

        ~DirectorSolution();

    private:
        std::map<size_t, std::shared_ptr<BaseDirectorCreator>> _creators;
};