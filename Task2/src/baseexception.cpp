#include "baseexception.h"
#include <cstring>

BaseException::BaseException(const char *time, const char *filename, 
                             const size_t line, const char *class_name, 
                             const char *method_name, const char *info)
{
    snprintf(errMsg, errSize, "\n Time: %s error in file %s, line %zu, in method %s of class %s.\n Info: %s\n", time, filename, line, method_name, class_name, info);
}

const char *BaseException::what() const noexcept
{
    return errMsg;
}