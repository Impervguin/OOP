#include "baseexception.h"

BaseException::BaseException(const std::string &time, const std::string &filename, 
                             const size_t line, const std::string &class_name, 
                             const std::string &method_name, const std::string &info)
{
    errMsg = "\n Time: " + time + 
                " Error in file " + filename + 
                ", line " + std::to_string(line) + 
                ", in method " + method_name + 
                " of class " + class_name + 
                "\n Info: " + info + "\n";
}

const char *BaseException::what() const noexcept
{
    return errMsg.c_str();
}