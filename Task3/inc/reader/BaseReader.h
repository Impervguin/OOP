#pragma once

class BaseReader {
    public:
        BaseReader() = default;
        virtual ~BaseReader() = 0;

        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual bool IsOpen() = 0;
};