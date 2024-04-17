#ifndef BASECONTAINER_H__
#define BASECONTAINER_H__

#include <cstdlib>

class BaseContainer {
    public:
        BaseContainer();
        BaseContainer(size_t size);
        bool IsEmpty() const;
        size_t GetSize() const;

        virtual ~BaseContainer() {};
    protected:
        size_t size;
};

#endif // BASECONTAINER_H__
