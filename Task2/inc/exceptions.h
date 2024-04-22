#ifndef EXCEPTIONS_H__
#define EXCEPTIONS_H__

#include "baseexception.h"

class IteratorException : public BaseException 
{
    public:
    IteratorException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Iterator exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class IteratorExpiredException : public IteratorException
{
    public:
    IteratorExpiredException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Use of expired(Invalid) Iterator.")
        : IteratorException(time, filename, line, class_name, method_name, info){};
};

class ListException : public BaseException 
{
    public:
    ListException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "List exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class PopEmptyException : public ListException
{
    public:
    PopEmptyException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Popping from empty container.")
        : ListException(time, filename, line, class_name, method_name, info){};
};

class UseOfForeignIterator : public ListException
{
    public:
    UseOfForeignIterator(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Use of another's list iterator.")
        : ListException(time, filename, line, class_name, method_name, info){};
};

class InvalidListRange : public ListException
{
    public:
    InvalidListRange(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Use of invalid list iterator's range.")
        : ListException(time, filename, line, class_name, method_name, info){};
};



class IndexOutOfRangeException : public ListException
{
    public:
    IndexOutOfRangeException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Index out of range.")
        : ListException(time, filename, line, class_name, method_name, info){};
};


#endif // EXCEPTIONS_H__
