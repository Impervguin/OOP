#pragma once
#include "BaseDirectorCreator.h"
#include "BaseBoneModelDirector.h"
#include "ListBoneModelDirector.h"
#include "MatrixBoneModelDirector.h"
#include "concept.h"
#include <memory>




template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
class DirectorCreator : public BaseDirectorCreatorTemplate<DirectorBase, Args...> {
    public:
        virtual ~DirectorCreator() = default;
        virtual std::shared_ptr<DirectorBase> Create(Args&&... args);
};



using ListBoneModelDirectorCreator = DirectorCreator<BaseBoneModelDirector, ListBoneModelDirector, std::shared_ptr<BoneModelReader>>;
using MatrixBoneModelDirectorCreator = DirectorCreator<BaseBoneModelDirector, MatrixBoneModelDirector, std::shared_ptr<BoneModelReader>>;

#include "DirectorCreator.hpp"