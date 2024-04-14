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
    return wptr == other.wptr;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& other) const {
    return wptr!= other.wptr;
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
const ListIterator<T> &ListIterator<T>::operator++() const {
    wptr = wptr.lock()->GetNext();
    return *this;
}

template <typename T>
const ListIterator<T> ListIterator<T>::operator++(int) const {
    const ListIterator<T> ret(*this);
    wptr = wptr.lock()->GetNext();
    return ret;
}

#endif // LISTITERATOR_HPP__
