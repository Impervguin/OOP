#pragma once
#include "BaseReader.h"
#include "BaseReaderCreator.h"
#include <map>

class ReaderSolution {
    public:
        ReaderSolution();
        ReaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseReaderCreator>>> list);

        void Register(std::size_t index, std::shared_ptr<BaseReaderCreator> creator);
        bool Check(std::size_t index);
        std::shared_ptr<BaseReaderCreator> Create(std::size_t index);

        ~ReaderSolution();

    private:
        std::map<size_t, std::shared_ptr<BaseReaderCreator>> _creators;

};