#pragma once
#include "Point.h"
#include <vector>


class BaseCenterStrategy {
    public:
        BaseCenterStrategy() = default;

        virtual ~BaseCenterStrategy() = 0;
        virtual Point CenterAlgorithm(std::vector<Point> points) const = 0;
};

class ClassicCenterStrategy : public BaseCenterStrategy {
    public:
        ClassicCenterStrategy() = default;

        virtual ~ClassicCenterStrategy() = default;
        virtual Point CenterAlgorithm(std::vector<Point> points) const;

};