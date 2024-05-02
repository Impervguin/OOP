#ifndef LISTITERATOR_HPP__
#define LISTITERATOR_HPP__

#include "listiterator.h"
#include "exceptions.h"
#include <time.h>

template <AssignCopyComparable T>
ListIterator<T>::ListIterator(const ListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
}

template <AssignCopyComparable T>
ListIterator<T>::ListIterator(ListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
}

template <AssignCopyComparable T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
    return *this;
}

template <AssignCopyComparable T>
ListIterator<T> &ListIterator<T>::operator=(const ListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
    return *this;
}

template <AssignCopyComparable T>
ListIterator<T>::ListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept {
   this->wptr = node;
}

template <AssignCopyComparable T>
ListIterator<T>::reference ListIterator<T>::operator*() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
const ListIterator<T>::reference ListIterator<T>::operator*() const {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
ListIterator<T>::pointer ListIterator<T>::operator->() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
const ListIterator<T>::pointer ListIterator<T>::operator->() const {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
ListIterator<T> &ListIterator<T>::operator++() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }      
    this->wptr = this->wptr.lock()->GetNext();
    return *this;
}

template <AssignCopyComparable T>
ListIterator<T> ListIterator<T>::operator++(int) {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    ListIterator<T> ret(*this);
    this->wptr = this->wptr.lock()->GetNext();
    return ret;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ListIterator<T> &ListIterator<T>::operator+=(U steps) {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    for (U i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ListIterator<T> ListIterator<T>::operator+(U steps) {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ListIterator<T> ListIterator<T>::operator+(U steps) const {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    ListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

#endif // LISTITERATOR_HPP__
