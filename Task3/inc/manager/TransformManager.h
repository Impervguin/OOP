#pragma once
#include "TransformAction.h"
#include "Object.h"

class TransformManager {
    public:
        TransformManager() = default;
        ~TransformManager() = default;

        void RotateObject(std::shared_ptr<Object> object, double ox, double oy, double oz);
        void ScaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz);
        void ShiftObject(std::shared_ptr<Object> object, double x, double y, double z);
        void TransformObject(std::shared_ptr<Object> object, const TransformAction& transform);
};