#include "MatrixBoneModelBuilder.h"
#include "MatrixModelStructure.h"

MatrixBoneModelBuilder::MatrixBoneModelBuilder() {
    _model = std::make_shared<MatrixModelStructure>();
}