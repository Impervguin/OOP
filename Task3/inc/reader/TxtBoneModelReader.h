#pragma once
#include "BoneModelReader.h"
#include "CenterStrategy.h"
#include <fstream>
#include <memory>

class TxtBoneModelReader : public BoneModelReader {
    public:
        TxtBoneModelReader(const char* filename);
        virtual ~TxtBoneModelReader();


        virtual void Open();
        virtual void Close();
        virtual bool IsOpen();

        virtual std::vector<Point> ReadPoints();
        virtual std::vector<Edge> ReadEdges();
        virtual Point ReadCenter();

    protected:
        const char* _fname;
        std::ifstream _file;
        std::shared_ptr<BaseCenterStrategy> _centerStrategy;

};