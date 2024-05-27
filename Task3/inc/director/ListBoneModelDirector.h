#pragma once
#include "BaseBoneModelDirector.h"


class ListBoneModelDirector : public BaseBoneModelDirector {
    public:
        ListBoneModelDirector(std::shared_ptr<BoneModelReader> reader);
        virtual ~ListBoneModelDirector() = default;
};