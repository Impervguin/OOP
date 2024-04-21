#ifndef CONSTLISTITERATOR_HPP__
#define CONSTLISTITERATOR_HPP__

#include "constlistiterator.h"

template <typename T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T>& other) noexcept {
    wptr = other.wptr.lock();
}

template <typename T>
ConstListIterator<T>::ConstListIterator(ConstListIterator<T>&& other) noexcept {
    wptr = other.wptr.lock();
    other.wptr.reset();
}

template <typename T>
ConstListIterator<T>& ConstListIterator<T>::operator=(ConstListIterator<T>&& other) noexcept {
    wptr = other.wptr.lock();
    other.wptr.reset();
    return *this;
}

template <typename T>
ConstListIterator<T>& ConstListIterator<T>::operator=(const ConstListIterator<T>& other) noexcept {
    wptr = other.wptr.lock();
    return *this;
}

template <typename T>
ConstListIterator<T>::ConstListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept {
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
ConstListIterator<T>::operator bool() const {
    return IsValid();
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
    return *wptr.lock()->GetData();
}

template <typename T>
ConstListIterator<T>::pointer ConstListIterator<T>::operator->() const {
    return wptr.lock()->GetData();
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
template <IncrementableandComparable U>
ConstListIterator<T> &ConstListIterator<T>::operator+=(U steps) {
    for (U i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <typename T>
template <IncrementableandComparable U>
ConstListIterator<T> ConstListIterator<T>::operator+(U steps) {
    ConstListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <typename T>
const std::shared_ptr<typename List<T>::ListNode> ConstListIterator<T>::getNode() const {
    checkValid(__LINE__);
    return wptr.lock();
}

#endif // CONSTLISTITERATOR_HPP__
