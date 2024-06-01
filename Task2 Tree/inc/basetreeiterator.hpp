#pragma once
#include "basetreeiterator.h"
#include "exceptions.h"

template <AssignCopyComparable T>
BaseTreeIterator<T>::~BaseTreeIterator() {}


template <AssignCopyComparable T>
BaseTreeIterator<T>::BaseTreeIterator(std::shared_ptr<nodeTree> root) noexcept
: _root(root), _index(0), _current(root) {
    if (root != nullptr) {
        while (_current.lock()->GetLeft() != nullptr) {
            _stackNext.push(_current);
            _current = _current.lock()->GetLeft();
        }
    }
}

template <AssignCopyComparable T>
BaseTreeIterator<T>::BaseTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept 
: _root(root), _current(current), _index(index) {}

template <AssignCopyComparable T>
BaseTreeIterator<T>::BaseTreeIterator(std::weak_ptr<nodeTree> root, std::weak_ptr<nodeTree> current, size_t index) noexcept 
: _root(root), _current(current), _index(index) {}

template <AssignCopyComparable T>
BaseTreeIterator<T>::operator bool() const noexcept {
    return !_current.expired() && _current.lock() != nullptr;
}

template <AssignCopyComparable T>
bool BaseTreeIterator<T>::operator<=>(const BaseTreeIterator<T>& other) const noexcept {
    return _index > other._index;    
}