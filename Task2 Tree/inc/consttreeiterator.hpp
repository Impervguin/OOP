#include "consttreeiterator.h"
#include  <iostream>

template <AssignCopyComparable T>
ConstTreeIterator<T>::ConstTreeIterator(const ConstTreeIterator<T>& other) noexcept
: BaseTreeIterator<T>(other._root, other._current, other._index) {
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

template <AssignCopyComparable T>
ConstTreeIterator<T>::ConstTreeIterator(ConstTreeIterator<T>&& other) noexcept
: BaseTreeIterator<T>(other._root, other._current, other._index) {
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

template <AssignCopyComparable T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator=(const ConstTreeIterator<T>& other) noexcept {
    this->_root = other._root;
    this->_current = other._current;
    this->_index = other._index;
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
    return *this;
}

template <AssignCopyComparable T>
ConstTreeIterator<T>::ConstTreeIterator(const ConstTreeIterator<T>&& other) noexcept {
    this->_root = other._root;
    this->_current = other._current;
    this->_index = other._index;
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

template <AssignCopyComparable T>
ConstTreeIterator<T>::ConstTreeIterator(std::shared_ptr<nodeTree> root) noexcept
: BaseTreeIterator<T>(root) {}

template <AssignCopyComparable T>
ConstTreeIterator<T>::ConstTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept
: BaseTreeIterator<T>(root, current, index) {}


template <AssignCopyComparable T>
ConstTreeIterator<T>::reference ConstTreeIterator<T>::operator*() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
const ConstTreeIterator<T>::reference ConstTreeIterator<T>::operator*() const  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
ConstTreeIterator<T>::pointer ConstTreeIterator<T>::operator->()  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
const ConstTreeIterator<T>::pointer ConstTreeIterator<T>::operator->() const  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}


template <AssignCopyComparable T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator++() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    this->_stackPrev.push(this->_current);
    auto _cur = this->_current.lock();

    if (_cur->GetRight() != nullptr) {
        auto tmp = _cur->GetRight();
        this->_stackNext.push(tmp);
        while (tmp->GetLeft()!= nullptr) {
            tmp = tmp->GetLeft();
            this->_stackNext.push(tmp);
        }
    }

    this->_index++;
    if (this->_stackNext.empty()) {
        this->_current.reset();
    } else {
        this->_current = this->_stackNext.top();
        this->_stackNext.pop();
    }
    return *this;
}

template <AssignCopyComparable T>
ConstTreeIterator<T> ConstTreeIterator<T>::operator++(int) {
    ConstTreeIterator<T> tmp(*this);
    ++(*this);
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator+=(U steps) {
    for (size_t i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstTreeIterator<T> ConstTreeIterator<T>::operator+(U steps) {
    ConstTreeIterator<T> tmp(*this);
    tmp += steps;
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ConstTreeIterator<T> ConstTreeIterator<T>::operator+(U steps) const {
    ConstTreeIterator<T> tmp(*this);
    tmp += steps;
    return tmp;
}

template <AssignCopyComparable T>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator--() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    this->_stackNext.push(this->_current);
    this->_index--;
    if (this->_stackPrev.empty()) {
        this->_current.reset();
    } else {
        this->_current = this->_stackPrev.top();
        this->_stackPrev.pop();
    }
    return *this;
}

template <AssignCopyComparable T>
ConstTreeIterator<T> ConstTreeIterator<T>::operator--(int) {
    ConstTreeIterator<T> tmp(*this);
    --(*this);
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstTreeIterator<T> &ConstTreeIterator<T>::operator-=(U steps) {
    for (size_t i = 0; i < steps; i++) {
        --(*this);
    }
    return *this;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstTreeIterator<T> ConstTreeIterator<T>::operator-(U steps) {
    ConstTreeIterator<T> tmp(*this);
    tmp -= steps;
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ConstTreeIterator<T> ConstTreeIterator<T>::operator-(U steps) const {
    ConstTreeIterator<T> tmp(*this);
    tmp -= steps;
    return tmp;
}