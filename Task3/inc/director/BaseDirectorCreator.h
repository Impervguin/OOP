#pragma once
#include "BaseDirector.h"
#include "BaseBoneModelDirector.h"
#include "BaseReader.h"


class BaseDirectorCreator {
    public:
        virtual ~BaseDirectorCreator() = default;
};


template <typename Director, typename... Args>
class BaseDirectorCreatorTemplate : public BaseDirectorCreator {
    public:
        virtual ~BaseDirectorCreatorTemplate() = default;

        virtual std::shared_ptr<Director> Create(Args&&... args) = 0;

};

using BoneModelDirectorCreator_t = BaseDirectorCreatorTemplate<BaseBoneModelDirector, std::shared_ptr<BoneModelReader>>;