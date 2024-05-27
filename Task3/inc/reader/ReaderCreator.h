#pragma once
#include "BaseReaderCreator.h"
#include "BoneModelReader.h"
#include "TxtBoneModelReader.h"
#include "SqliteBoneModelReader.h"
#include "concept.h"
#include <memory>

template <typename ReaderBase, typename ReaderProd, typename... Args>
requires NotAbstract<ReaderProd> && Derivative<ReaderProd, ReaderBase> && Constructible<ReaderProd, Args...>
class ReaderCreator : public BaseReaderCreatorTemplate<ReaderBase, Args...> {
    public:
        virtual ~ReaderCreator() = default;
        virtual std::shared_ptr<ReaderBase> Create(Args&&... args);
};

using TxtBoneModelReaderCreator = ReaderCreator<BoneModelReader, TxtBoneModelReader, const char *>;
using SqliteBoneModelReaderCreator = ReaderCreator<BoneModelReader, SqliteBoneModelReader, const char *>;

#include "ReaderCreator.hpp"