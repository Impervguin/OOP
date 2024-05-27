#include "ListBoneModelDirector.h"
#include "ListBoneModelBuilder.h"

ListBoneModelDirector::ListBoneModelDirector(std::shared_ptr<BoneModelReader> reader)
: BaseBoneModelDirector(reader) {
    _builder = std::make_shared<ListBoneModelBuilder>();
}