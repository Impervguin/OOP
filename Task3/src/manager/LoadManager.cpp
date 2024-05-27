#include "LoadManager.h"
#include "managerexception.h"
#include "ReaderCreator.h"

LoadManager::LoadManager() {
    _dsolution.Register(LISTBONEMODELDIRECTORCREATOR_ID, std::make_shared<ListBoneModelDirectorCreator>());
    _dsolution.Register(MATRIXBONEMODELDIRECTORCREATOR_ID, std::make_shared<MatrixBoneModelDirectorCreator>());

    _rsolution.Register(TXTBONEMODELREADERCREATOR_ID, std::make_shared<TxtBoneModelReaderCreator>());
    _rsolution.Register(SQLITEBONEMODELREADERCREATOR_ID, std::make_shared<SqliteBoneModelReaderCreator>());
}


std::shared_ptr<Object> LoadManager::LoadBoneModelFile(std::size_t directorID, std::size_t ReaderID, const char* filename) {
    std::shared_ptr<BaseDirectorCreator> absDirectorCr = _dsolution.Create(directorID);
    std::shared_ptr<BaseReaderCreator> absReaderCr = _rsolution.Create(ReaderID);

    std::shared_ptr<BoneModelDirectorCreator_t> boneModelDirectorCr = std::dynamic_pointer_cast<BoneModelDirectorCreator_t>(absDirectorCr);
    if (boneModelDirectorCr == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongDirectorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<BoneModelReaderCreator_t> boneModelReaderCr = std::dynamic_pointer_cast<BoneModelReaderCreator_t>(absReaderCr);
    if (boneModelReaderCr == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongReaderException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<BoneModelReader> boneModelReader = boneModelReaderCr->Create(std::move(filename));
    std::shared_ptr<BaseBoneModelDirector> boneModelDirector = boneModelDirectorCr->Create(std::move(boneModelReader));
    boneModelDirector->Create();
    return boneModelDirector->Get();
};