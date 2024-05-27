#pragma once

#include "BaseBoneModelDirector.h"

class MatrixBoneModelDirector : public BaseBoneModelDirector {
    public:
        MatrixBoneModelDirector(std::shared_ptr<BoneModelReader> reader);
        virtual ~MatrixBoneModelDirector() = default;
};