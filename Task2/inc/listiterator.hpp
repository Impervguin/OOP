#ifndef LISTITERATOR_HPP__
#define LISTITERATOR_HPP__

#include "listiterator.h"
#include "exceptions.h"
#include <time.h>

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T>& other) noexcept {
    wptr = other.wptr.lock();
}

template <typename T>
ListIterator<T>::ListIterator(ListIterator<T>&& other) noexcept {
    wptr = other.wptr.lock();
    other.wptr.reset();
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T>&& other) noexcept {
    wptr = other.wptr.lock();
    other.wptr.reset();
    return *this;
}

template <typename T>
ListIterator<T> &ListIterator<T>::operator=(const ListIterator<T>& other) noexcept {
    wptr = other.wptr.lock();
    return *this;
}

template <typename T>
ListIterator<T>::ListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept {
    wptr = node;
}

template <typename T>
bool ListIterator<T>::IsValid() const {
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}

template <typename T>
ListIterator<T>::operator bool() const {
    return IsValid();
}

template <typename T>
void ListIterator<T>::checkValid(size_t line) const
{
    if (!IsValid())
    {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}




template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T>& other) const {
    return wptr.lock() == other.wptr.lock();
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& other) const {
    return wptr.lock() != other.wptr.lock();
}

template <typename T>
ListIterator<T>::reference ListIterator<T>::operator*() {
    checkValid(__LINE__);
    return *wptr.lock()->GetData();
}

template <typename T>
const ListIterator<T>::reference ListIterator<T>::operator*() const {
    checkValid(__LINE__);
    return *wptr.lock()->GetData();
}

template <typename T>
ListIterator<T>::pointer ListIterator<T>::operator->() {
    checkValid(__LINE__);
    return wptr.lock()->GetData();
}

template <typename T>
const ListIterator<T>::pointer ListIterator<T>::operator->() const {
    checkValid(__LINE__);
    return wptr.lock()->GetData();
}

template <typename T>
ListIterator<T> &ListIterator<T>::operator++() {
    checkValid(__LINE__);    
    wptr = wptr.lock()->GetNext();
    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
    checkValid(__LINE__);
    ListIterator<T> ret(*this);
    wptr = wptr.lock()->GetNext();
    return ret;
}

template <typename T>
template <IncrementableandComparable U>
ListIterator<T> &ListIterator<T>::operator+=(U steps) {
    checkValid(__LINE__);
    for (U i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <typename T>
template <IncrementableandComparable U>
ListIterator<T> ListIterator<T>::operator+(U steps) {
    checkValid(__LINE__);
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <typename T>
template <IncrementableandComparable U>
const ListIterator<T> ListIterator<T>::operator+(U steps) const {
    checkValid(__LINE__);
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}



template <typename T>
std::shared_ptr<typename List<T>::ListNode> ListIterator<T>::getNode() const {
    checkValid(__LINE__);
    return wptr.lock();
}

#endif // LISTITERATOR_HPP__
