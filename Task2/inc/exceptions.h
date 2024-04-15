#ifndef EXCEPTIONS_H__
#define EXCEPTIONS_H__

#include "baseexception.h"

class IteratorExpiredException : public BaseException
{
    public:
    IteratorExpiredException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Use of expired(Invalid) Iterator.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class PopEmptyException : public BaseException
{
    public:
    PopEmptyException(const std::string &time, const std::string &filename,
                     const size_t line, const std::string &class_name,
                     const std::string &method_name,
                     const std::string &info = "Popping from empty container.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

#endif // EXCEPTIONS_H__
