#ifndef BASECONTAINER_H__
#define BASECONTAINER_H__

#include <cstdlib>

class BaseContainer
{
public:
    virtual bool IsEmpty() const;
    virtual size_t size() const;
    virtual ~BaseContainer() = 0;

protected:
    size_t csize = 0;
};


#endif // BASECONTAINER_H__
