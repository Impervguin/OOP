#ifndef LISTITERATOR_HPP__
#define LISTITERATOR_HPP__

#include "listiterator.h"
#include "exceptions.h"
#include <time.h>

template <Comparable T>
ListIterator<T>::ListIterator(const ListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
}

template <Comparable T>
ListIterator<T>::ListIterator(ListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
}

template <Comparable T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
    return *this;
}

template <Comparable T>
ListIterator<T> &ListIterator<T>::operator=(const ListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
    return *this;
}

template <Comparable T>
ListIterator<T>::ListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept {
   this->wptr = node;
}

template <Comparable T>
ListIterator<T>::reference ListIterator<T>::operator*() {
    this->checkValid(__LINE__);
    return *this->wptr.lock()->GetData();
}

template <Comparable T>
const ListIterator<T>::reference ListIterator<T>::operator*() const {
    this->checkValid(__LINE__);
    return *this->wptr.lock()->GetData();
}

template <Comparable T>
ListIterator<T>::pointer ListIterator<T>::operator->() {
    this->checkValid(__LINE__);
    return this->wptr.lock()->GetData();
}

template <Comparable T>
const ListIterator<T>::pointer ListIterator<T>::operator->() const {
    this->checkValid(__LINE__);
    return this->wptr.lock()->GetData();
}

template <Comparable T>
ListIterator<T> &ListIterator<T>::operator++() {
    this->checkValid(__LINE__);    
    this->wptr = this->wptr.lock()->GetNext();
    return *this;
}

template <Comparable T>
ListIterator<T> ListIterator<T>::operator++(int) {
    this->checkValid(__LINE__);
    ListIterator<T> ret(*this);
    this->wptr = this->wptr.lock()->GetNext();
    return ret;
}

template <Comparable T>
template <IncrementableandComparable U>
ListIterator<T> &ListIterator<T>::operator+=(U steps) {
    this->checkValid(__LINE__);
    for (U i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <Comparable T>
template <IncrementableandComparable U>
ListIterator<T> ListIterator<T>::operator+(U steps) {
    this->checkValid(__LINE__);
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <Comparable T>
template <IncrementableandComparable U>
const ListIterator<T> ListIterator<T>::operator+(U steps) const {
    this->checkValid(__LINE__);
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

#endif // LISTITERATOR_HPP__
