#pragma once
#include "baseexception.h"

class SolutionException : public BaseException 
{
    public:
    SolutionException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class SolutionNotFoundException : public SolutionException 
{
    public:
    SolutionNotFoundException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : SolutionException(time, filename, line, class_name, method_name, info){};
};


class SolutionAlreadyInException : public SolutionException 
{
    public:
    SolutionAlreadyInException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : SolutionException(time, filename, line, class_name, method_name, info){};
};