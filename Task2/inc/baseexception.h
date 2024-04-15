#ifndef BASEEXCEPTION_H__
#define BASEEXCEPTION_H__

#include <exception>
#include <string>

class BaseException : public std::exception
{
protected:
    std::string errMsg;
public:
   BaseException(const std::string &time, const std::string &filename,
                  const size_t line, const std::string &class_name,
                  const std::string &method_name, const std::string &info);
    virtual const char *what() const noexcept override;
};


#endif // BASEEXCEPTION_H__
