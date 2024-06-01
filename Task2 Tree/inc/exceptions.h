#pragma once

#include "baseexception.h"

class IteratorException : public BaseException 
{
    public:
    IteratorException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Iterator exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class IteratorExpiredException : public IteratorException
{
    public:
    IteratorExpiredException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Use of expired(Invalid) Iterator.")
        : IteratorException(time, filename, line, class_name, method_name, info){};
};

class TreeException : public BaseException 
{
    public:
    TreeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Tree exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};