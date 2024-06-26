#include "constreversetreeiterator.h"
#include  <iostream>

template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::ConstReverseTreeIterator(const ConstReverseTreeIterator<T>& other) noexcept
: BaseTreeIterator<T>(other._root, other._current, other._index) {
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::ConstReverseTreeIterator(ConstReverseTreeIterator<T>&& other) noexcept
: BaseTreeIterator<T>(other._root, other._current, other._index) {
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator=(const ConstReverseTreeIterator<T>& other) noexcept {
    this->_root = other._root;
    this->_current = other._current;
    this->_index = other._index;
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
    return *this;
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::ConstReverseTreeIterator(const ConstReverseTreeIterator<T>&& other) noexcept {
    this->_root = other._root;
    this->_current = other._current;
    this->_index = other._index;
    this->_stackNext = other._stackNext;
    this->_stackPrev = other._stackPrev;
}

// template <AssignCopyComparable T>
// ConstReverseTreeIterator<T>::ConstReverseTreeIterator(const ReverseTreeIterator<T>& other) noexcept
// : BaseTreeIterator<T>(other._root, other._current, other._index) {
//     this->_stackNext = other._stackNext;
//     this->_stackPrev = other._stackPrev;
// }

// template <AssignCopyComparable T>
// ConstReverseTreeIterator<T>::ConstReverseTreeIterator(ReverseTreeIterator<T>&& other) noexcept
// : BaseTreeIterator<T>(other._root, other._current, other._index) {
//     this->_stackNext = other._stackNext;
//     this->_stackPrev = other._stackPrev;
// }

// template <AssignCopyComparable T>
// ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator=(const ReverseTreeIterator<T>& other) noexcept {
//     this->_root = other._root;
//     this->_current = other._current;
//     this->_index = other._index;
//     this->_stackNext = other._stackNext;
//     this->_stackPrev = other._stackPrev;
//     return *this;
// }

// template <AssignCopyComparable T>
// ConstReverseTreeIterator<T>::ConstReverseTreeIterator(const ReverseTreeIterator<T>&& other) noexcept {
//     this->_root = other._root;
//     this->_current = other._current;
//     this->_index = other._index;
//     this->_stackNext = other._stackNext;
//     this->_stackPrev = other._stackPrev;
// }


template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::ConstReverseTreeIterator(std::shared_ptr<nodeTree> root) noexcept
: BaseTreeIterator<T>(root, root, 0) {
    if (this->_current.lock() != nullptr) {
        while (this->_current.lock()->GetRight() != nullptr) {
            this->_stackNext.push(this->_current);
            this->_current = this->_current.lock()->GetRight();
        }
    }
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::ConstReverseTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept
: BaseTreeIterator<T>(root, current, index) {}


template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::reference ConstReverseTreeIterator<T>::operator*() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
const ConstReverseTreeIterator<T>::reference ConstReverseTreeIterator<T>::operator*() const  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T>::pointer ConstReverseTreeIterator<T>::operator->()  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return this->_current.lock()->GetData();
}

template <AssignCopyComparable T>
const ConstReverseTreeIterator<T>::pointer ConstReverseTreeIterator<T>::operator->() const  {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    return *this->_current.lock()->GetData();
}


template <AssignCopyComparable T>
ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator++() {
    if (!*this) {
        time_t cur_time = time(NULL);
        throw IteratorExpiredException(ctime(&cur_time), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }  
    this->_stackPrev.push(this->_current);
    auto _cur = this->_current.lock();

    if (_cur->GetLeft() != nullptr) {
        auto tmp = _cur->GetLeft();
        this->_stackNext.push(tmp);
        while (tmp->GetRight()!= nullptr) {
            tmp = tmp->GetRight();
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
ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator++(int) {
    ConstReverseTreeIterator<T> tmp(*this);
    ++(*this);
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator+=(U steps) {
    for (size_t i = 0; i < steps; i++) {
        ++(*this);
    }
    return *this;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator+(U steps) {
    ConstReverseTreeIterator<T> tmp(*this);
    tmp += steps;
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator+(U steps) const {
    ConstReverseTreeIterator<T> tmp(*this);
    tmp += steps;
    return tmp;
}

template <AssignCopyComparable T>
ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator--() {
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
ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator--(int) {
    ConstReverseTreeIterator<T> tmp(*this);
    --(*this);
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstReverseTreeIterator<T> &ConstReverseTreeIterator<T>::operator-=(U steps) {
    for (size_t i = 0; i < steps; i++) {
        --(*this);
    }
    return *this;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator-(U steps) {
    ConstReverseTreeIterator<T> tmp(*this);
    tmp -= steps;
    return tmp;
}

template <AssignCopyComparable T>
template <IncrementableandComparable U>
const ConstReverseTreeIterator<T> ConstReverseTreeIterator<T>::operator-(U steps) const {
    ConstReverseTreeIterator<T> tmp(*this);
    tmp -= steps;
    return tmp;
}