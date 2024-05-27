#pragma once
#include "baseexception.h"

class SqliteReaderException : public BaseException 
{
    public:
    SqliteReaderException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Sqlite Reader exception.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class SqliteNoFileException : public SqliteReaderException
{
    public:
    SqliteNoFileException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't open sqlite file exception.")
        : SqliteReaderException(time, filename, line, class_name, method_name, info){};
};

class SqliteReadException : public SqliteReaderException
{
    public:
    SqliteReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from sqlite file exception.")
        : SqliteReaderException(time, filename, line, class_name, method_name, info){};
};