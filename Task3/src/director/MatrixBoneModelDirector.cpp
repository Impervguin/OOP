#include "MatrixBoneModelDirector.h"
#include "MatrixBoneModelBuilder.h"

MatrixBoneModelDirector::MatrixBoneModelDirector(std::shared_ptr<BoneModelReader> reader)
: BaseBoneModelDirector(reader) {
    _builder = std::make_shared<MatrixBoneModelBuilder>();
}