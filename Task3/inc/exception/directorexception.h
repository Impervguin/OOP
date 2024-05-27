#pragma once
#include "baseexception.h"

class DirectorException : public BaseException 
{
    public:
    DirectorException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Director exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class BoneModelDirectorException : public DirectorException
{
    public:
    BoneModelDirectorException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Bonemodel director exception.")
        : DirectorException(time, filename, line, class_name, method_name, info){};
};

class BoneModelDirectorWrongReaderException : public BoneModelDirectorException
{
    public:
    BoneModelDirectorWrongReaderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Wrong Reader type passed to director, expected BoneModelReader exception.")
        : BoneModelDirectorException(time, filename, line, class_name, method_name, info){};
};