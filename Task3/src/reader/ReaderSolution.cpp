#include "ReaderSolution.h"
#include "solutionexception.h"


ReaderSolution::ReaderSolution() : _creators(std::map<std::size_t, std::shared_ptr<BaseReaderCreator>>()) {}

ReaderSolution::~ReaderSolution() {}

ReaderSolution::ReaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseReaderCreator>>> list) {
    for (const auto& pair : list) {
        _creators[pair.first] = pair.second;
    }
}


bool ReaderSolution::Check(std::size_t index) {
    return _creators.find(index)!= _creators.end();
}

std::shared_ptr<BaseReaderCreator> ReaderSolution::Create(std::size_t index) {
    if (Check(index)) {
        return _creators[index];
    }
    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}


void ReaderSolution::Register(std::size_t index, std::shared_ptr<BaseReaderCreator> creator) {
    if (Check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    _creators[index] = creator;
}