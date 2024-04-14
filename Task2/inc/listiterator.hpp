#ifndef LISTITERATOR_HPP__
#define LISTITERATOR_HPP__

#include "listiterator.h"


template <typename T>
ListIterator<T>::ListIterator() {
    wptr = nullptr;
}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T>& other) {
    wptr = other.wptr.lock();
}

template <typename T>
ListIterator<T>::ListIterator(const std::shared_ptr<ListNode<T>>& node) {
    wptr = node;
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
T &ListIterator<T>::operator*() {
    return wptr.lock()->GetData();
}

template <typename T>
const T &ListIterator<T>::operator*() const {
    return wptr.lock()->GetData();
}

template <typename T>
T *ListIterator<T>::operator->() {
    return &wptr.lock()->GetData();
}

template <typename T>
const T *ListIterator<T>::operator->() const {
    return &wptr.lock()->GetData();
}

template <typename T>
ListIterator<T> &ListIterator<T>::operator++() {
    wptr = wptr.lock()->GetNext();
    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
    ListIterator<T> ret(*this);
    wptr = wptr.lock()->GetNext();
    return ret;
}

template <typename T>
ListIterator<T> &ListIterator<T>::operator+=(int steps) {
    for (int i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator+(int steps) {
    ListIterator<T> ret(*this);
    for (int i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator=(const ListIterator<T>& other) {
    wptr = other.wptr.lock();
    return *this;
}

#endif // LISTITERATOR_HPP__
