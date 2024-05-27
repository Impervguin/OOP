#pragma once

#include <exception>
#include <string>


class BaseException : public std::exception
{
protected:
    static const size_t errSize = 512;
    char errMsg[errSize] = "";
public:
   BaseException(const char *time, const char *filename,
                  const size_t line, const char *class_name,
                  const char *method_name, const char *info);
    virtual const char *what() const noexcept override;
};