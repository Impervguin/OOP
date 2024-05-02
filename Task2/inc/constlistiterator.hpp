#ifndef CONSTLISTITERATOR_HPP__
#define CONSTLISTITERATOR_HPP__

#include "constlistiterator.h"

template <AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
}

template <AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(ConstListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
}

template <AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const ListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
}

template <AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(ListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
}

template <AssignCopyComparable T>
ConstListIterator<T>& ConstListIterator<T>::operator=(ConstListIterator<T>&& other) noexcept {
    this->wptr = other.wptr.lock();
    other.wptr.reset();
    return *this;
}

template <AssignCopyComparable T>
ConstListIterator<T>& ConstListIterator<T>::operator=(const ConstListIterator<T>& other) noexcept {
    this->wptr = other.wptr.lock();
    return *this;
}

template <AssignCopyComparable T>
ConstListIterator<T>::ConstListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept {
    this->wptr = node;
}

template <AssignCopyComparable T>
ConstListIterator<T>::reference ConstListIterator<T>::operator*() const {
    return *this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
ConstListIterator<T>::pointer ConstListIterator<T>::operator->() const {
    return this->wptr.lock()->GetData();
}

template <AssignCopyComparable T>
ConstListIterator<T> &ConstListIterator<T>::operator++() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    this->wptr = this->wptr.lock()->GetNext();
    return *this;
}

template <AssignCopyComparable T>
ConstListIterator<T> ConstListIterator<T>::operator++(int) {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }    
    ConstListIterator<T> ret(*this);
    this->wptr = this->wptr.lock()->GetNext();
    return ret;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstListIterator<T> &ConstListIterator<T>::operator+=(U steps) {
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
ConstListIterator<T> ConstListIterator<T>::operator+(U steps) {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    ConstListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ConstListIterator<T> ConstListIterator<T>::operator+(U steps) const {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    ConstListIterator<T> ret(*this);
    for (U i = 0; i < steps; i++) {
        ++ret;
    }
    return ret;
}


#endif // CONSTLISTITERATOR_HPP__
