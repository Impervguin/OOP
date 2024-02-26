#include "errs.h"

    // ERR_NO_FILE,
    // ERR_FILE_FORMAT,
    // ERR_NULL_POINTER, 
    // ERR_MEMORY,
    // ERR_ARGUMENTS

const char *err_message(myerror_t err)
{
    switch (err)
    {
    case OK:
        return "OK.";
        break;
    case ERR_NO_FILE:
        return "No file found or can't open file.";
        break;
    case ERR_FILE_FORMAT:
        return "Incorrect file format.";
        break;
    case ERR_NULL_POINTER:
        return "NULL pointer passed to function.";
        break;
    case ERR_MEMORY:
        return "Memory allocation error.";
        break;
    case ERR_ARGUMENTS:
        return "Incorrect arguments passed to function.";
        break;
    default:
        return "Unknown error.";
        break;
    }
}