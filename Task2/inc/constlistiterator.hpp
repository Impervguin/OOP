#ifndef CONSTLISTITERATOR_HPP__
#define CONSTLISTITERATOR_HPP__

#include "constlistiterator.h"


template <typename T>
ConstListIterator<T>::ConstListIterator() {
    wptr = nullptr;
}

template <typename T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T>& other) {
    wptr = other.wptr.lock();
}

template <typename T>
ConstListIterator<T>::ConstListIterator(const std::shared_ptr<ListNode<T>>& node) {
    wptr = node;
}

template <typename T>
bool ConstListIterator<T>::IsValid() const {
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}

template <typename T>
void ConstListIterator<T>::checkValid(size_t line) const
{
    if (!IsValid())
    {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <typename T>
bool ConstListIterator<T>::operator==(const ConstListIterator<T>& other) const {
    return wptr.lock() == other.wptr.lock();
}

template <typename T>
bool ConstListIterator<T>::operator!=(const ConstListIterator<T>& other) const {
    return wptr.lock() != other.wptr.lock();
}

template <typename T>
ConstListIterator<T>::reference ConstListIterator<T>::operator*() const {
    return wptr.lock()->GetData();
}

template <typename T>
ConstListIterator<T>::pointer ConstListIterator<T>::operator->() const {
    return &wptr.lock()->GetData();
}

template <typename T>
ConstListIterator<T> &ConstListIterator<T>::operator++() {
    if (!wptr.expired())
        wptr = wptr.lock()->GetNext();
    return *this;
}

template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator++(int) {
    ConstListIterator<T> ret(*this);
    wptr = wptr.lock()->GetNext();
    return ret;
}

template <typename T>
ConstListIterator<T> &ConstListIterator<T>::operator+=(int steps) {
    for (int i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator+(int steps) {
    ConstListIterator<T> ret(*this);
    for (int i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator=(const ConstListIterator<T>& other) {
    wptr = other.wptr.lock();
    return *this;
}

template <typename T>
std::shared_ptr<ListNode<T>> ConstListIterator<T>::getNode() const {
    checkValid(__LINE__);
    return wptr.lock();
}

#endif // CONSTLISTITERATOR_HPP__
