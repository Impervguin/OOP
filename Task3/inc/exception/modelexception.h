#pragma once
#include "baseexception.h"

class ModelStructureException : public BaseException 
{
    public:
    ModelStructureException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Model structure exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class EdgeOutOfPointsException : public ModelStructureException 
{
    public:
    EdgeOutOfPointsException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Edge has not existing points exception.")
        : ModelStructureException(time, filename, line, class_name, method_name, info){};
};

