#ifndef EXCEPTIONS_H__
#define EXCEPTIONS_H__

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

class ListException : public BaseException 
{
    public:
    ListException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "List exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class PopEmptyException : public ListException
{
    public:
    PopEmptyException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Popping from empty container.")
        : ListException(time, filename, line, class_name, method_name, info){};
};

class UseOfForeignIterator : public ListException
{
    public:
    UseOfForeignIterator(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Use of another's list iterator.")
        : ListException(time, filename, line, class_name, method_name, info){};
};

class InvalidListRange : public ListException
{
    public:
    InvalidListRange(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Use of invalid list iterator's range.")
        : ListException(time, filename, line, class_name, method_name, info){};
};



class IndexOutOfRangeException : public ListException
{
    public:
    IndexOutOfRangeException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Index out of range.")
        : ListException(time, filename, line, class_name, method_name, info){};
};


#endif // EXCEPTIONS_H__
