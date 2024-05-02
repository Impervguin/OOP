#ifndef BASELISTITERATOR_HPP__
#define BASELISTITERATOR_HPP__

#include "baselistiterator.h"

template <AssignCopyComparable T>
std::shared_ptr<typename List<T>::ListNode> BaseListIterator<T>::getNode() const {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return wptr.lock();
}

template <AssignCopyComparable T>
bool BaseListIterator<T>::IsValid() const noexcept {
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}

template <AssignCopyComparable T>
BaseListIterator<T>::operator bool() const noexcept {
    return IsValid();
}

template <AssignCopyComparable T>
bool BaseListIterator<T>::operator==(const BaseListIterator<T>& other) const noexcept {
    return wptr.lock() == other.wptr.lock();
}

template <AssignCopyComparable T>
bool BaseListIterator<T>::operator!=(const BaseListIterator<T>& other) const noexcept {
    return wptr.lock() != other.wptr.lock();
}

template <AssignCopyComparable T>
BaseListIterator<T>::~BaseListIterator() {}

#endif // BASELISTITERATOR_H__
