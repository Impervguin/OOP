#ifndef ERRS_H__
#define ERRS_H__

typedef enum {
    OK = 0,
    ERR_NO_FILE,
    ERR_FILE_FORMAT,
    ERR_NULL_POINTER, 
    ERR_MEMORY,
    ERR_ARGUMENTS
} error_t;

#endif // ERRS_H__
