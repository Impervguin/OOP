#include "CenterStrategy.h"


BaseCenterStrategy::~BaseCenterStrategy() {}

Point ClassicCenterStrategy::CenterAlgorithm(std::vector<Point> points) const {
    if (points.empty())
        return Point();
    double minX = points[0].GetX(), minY = points[0].GetY(), minZ = points[0].GetZ();
    double maxX = points[0].GetX(), maxY = points[0].GetY(), maxZ = points[0].GetZ();

    for (auto &p : points) {
        if (minX > p.GetX())
            minX = p.GetX();
        if (minY > p.GetY())
            minY = p.GetY();
        if (minZ > p.GetZ())
            minZ = p.GetZ();
        if (maxX < p.GetX())
            maxX = p.GetX();
        if (maxY < p.GetY())
            maxY = p.GetY();
        if (maxZ < p.GetZ())
            maxZ = p.GetZ();
    }

    return Point((minX + maxX) / 2, (minY + maxY) / 2, (maxZ + minZ) / 2);
}