#pragma once

#include "baseexception.h"

class MatrixException : public BaseException 
{
    public:
    MatrixException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class MatrixRowException : public MatrixException 
{
    public:
    MatrixRowException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix exception.")
        : MatrixException(time, filename, line, class_name, method_name, info){};
};

class MatrixRowOutOfRangeException : public MatrixRowException 
{
    public:
    MatrixRowOutOfRangeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix Row index out of range.")
        : MatrixRowException(time, filename, line, class_name, method_name, info){};
};

class MatrixOutOfRangeException : public MatrixException 
{
    public:
    MatrixOutOfRangeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix index out of range.")
        : MatrixException(time, filename, line, class_name, method_name, info){};
};

class MatrixMultiplySizeException : public MatrixException  {
    public:
    MatrixMultiplySizeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix multiplication sizes exception.")
        : MatrixException(time, filename, line, class_name, method_name, info){};
};

class MatrixAddSizeException : public MatrixException  {
    public:
    MatrixAddSizeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Matrix add sizes exception.")
        : MatrixException(time, filename, line, class_name, method_name, info){};
};