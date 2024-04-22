#include "basecontainer.h"

bool BaseContainer::IsEmpty() const
{
    return csize == 0;
}

size_t BaseContainer::size() const
{
    return csize;
}

BaseContainer::~BaseContainer() {};