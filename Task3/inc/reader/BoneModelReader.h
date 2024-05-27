#pragma once
#include "BaseReader.h"
#include "Point.h"
#include "Edge.h"
#include <vector>

class BoneModelReader : public BaseReader {
    public:
        BoneModelReader() = default;

        virtual ~BoneModelReader() = 0;

        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual bool IsOpen() = 0;

        virtual std::vector<Point> ReadPoints() = 0;
        virtual std::vector<Edge> ReadEdges() = 0;
        virtual Point ReadCenter() = 0;
}; 