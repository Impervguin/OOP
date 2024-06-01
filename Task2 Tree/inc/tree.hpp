#include "tree.h"

template <AssignCopyComparable T>
BSTree<T>::BSTree() noexcept
: _root(nullptr), _size(0) {}

template <AssignCopyComparable T>
BSTree<T>::BSTree(const BSTree<T>& bstree)
: _root(nullptr), _size(0) {
    for (auto it = bstree.begin(); it != bstree.end(); ++it) {
        Add(*it);
    }
}

template <AssignCopyComparable T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T> &bstree) {
    if (this!= &bstree) {
        Clear();
        for (auto it = bstree.begin(); it!= bstree.end(); ++it) {
            Add(*it);
        }
    }
    return *this;
}

template <AssignCopyComparable T>
BSTree<T>::BSTree(BSTree<T> &&bstree) noexcept :
    _root(bstree._root), _size(bstree._size) {
    bstree._root = nullptr;
    bstree._size = 0;
}

template <AssignCopyComparable T>
BSTree<T>& BSTree<T>::operator=(BSTree<T> &&bstree) noexcept {
    if (this!= &bstree) {
        _root = bstree._root;
        _size = bstree._size;
        bstree._root = nullptr;
        bstree._size = 0;
    }
    return *this;
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T>::BSTree(std::initializer_list<U> list) {
    for (auto it = list.begin(); it!= list.end(); ++it) {
        Add(*it);
    }
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T> &BSTree<T>::operator=(std::initializer_list<U> list) {
    Clear();
    for (auto it = list.begin(); it!= list.end(); ++it) {
        Add(*it);
    }
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleForwardIterator<T> Iter>
BSTree<T>::BSTree(const Iter &begin, const Iter &end) {
    for (auto it = begin; it!= end; ++it) {
        Add(*it);
    }
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T>::BSTree(const C &container) {
    for (auto it = container.begin(); it!= container.end(); ++it) {
        Add(*it);
    }
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> &BSTree<T>::operator=(const C &container) {
    Clear();
    for (auto it = container.begin(); it!= container.end(); ++it) {
        Add(*it);
    }
    return *this;
}

// Итераторы
template <AssignCopyComparable T>
BSTree<T>::iterator BSTree<T>::begin() noexcept {
    return iterator(_root);
}


template <AssignCopyComparable T>
BSTree<T>::iterator BSTree<T>::end() noexcept {
    return iterator(_root, nullptr, _size);
}
template <AssignCopyComparable T>
BSTree<T>::const_iterator BSTree<T>::begin() const noexcept {
    return const_iterator(_root);
}

template <AssignCopyComparable T>
BSTree<T>::const_iterator BSTree<T>::end() const noexcept {
    return const_iterator(_root, nullptr, _size);
}

template <AssignCopyComparable T>
BSTree<T>::const_iterator BSTree<T>::cbegin() const noexcept {
    return const_iterator(_root);
}

template <AssignCopyComparable T>
BSTree<T>::const_iterator BSTree<T>::cend() const noexcept {
    return const_iterator(_root, nullptr, _size);
}

template <AssignCopyComparable T>
BSTree<T>::reverse_iterator BSTree<T>::rbegin() noexcept {
    return reverse_iterator(_root);
}

template <AssignCopyComparable T>
BSTree<T>::reverse_iterator BSTree<T>::rend() noexcept {
    return reverse_iterator(_root, nullptr, _size);
}

template <AssignCopyComparable T>
BSTree<T>::const_reverse_iterator BSTree<T>::rbegin() const noexcept {
    return const_reverse_iterator(_root);
}

template <AssignCopyComparable T>
BSTree<T>::const_reverse_iterator BSTree<T>::rend() const noexcept {
    return const_reverse_iterator(_root, nullptr, _size);
}

template <AssignCopyComparable T>
BSTree<T>::const_reverse_iterator BSTree<T>::crbegin() const noexcept {
    return const_reverse_iterator(_root);
}

template <AssignCopyComparable T>
BSTree<T>::const_reverse_iterator BSTree<T>::crend() const noexcept {
    return const_reverse_iterator(_root, nullptr, _size);
}


template <AssignCopyComparable T>
size_t BSTree<T>::size() const noexcept {
    return _size;
}


// Добавление элементов
template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
void BSTree<T>::Add(const U &data) {
    if (_root == nullptr) {
        _root = BSTree<T>::TreeNode::CreateNode(data, nullptr, nullptr);
        _size++;
        return;
    }
    auto node = _root;
    while (true) {
        if (data < *node->GetData()) {
            if (node->GetLeft() == nullptr) {
                node->SetLeft(BSTree<T>::TreeNode::CreateNode(data, nullptr, nullptr));
                _size++;
                return;
            }
            node = node->GetLeft();
        } else if (data > *node->GetData()) {
            if (node->GetRight() == nullptr) {
                node->SetRight(BSTree<T>::TreeNode::CreateNode(data, nullptr, nullptr));
                _size++;
                return;
            }
            node = node->GetRight();
        } else {
            return;
        }
    }
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T>& BSTree<T>::operator+=(const U &data) {
    Add(data);
    return *this;
}

template <AssignCopyComparable T>
void BSTree<T>::Clear() noexcept {
    _root = nullptr;
    _size = 0;
}


template <AssignCopyComparable T>
std::ostream& operator<<(std::ostream& os, const BSTree<T>& bstree) {
    os << "[";
    if (bstree.size() > 0) {
        auto it = bstree.begin();
        for (; it + 1 != bstree.end(); ++it) {
            os << *it << ", ";
        }
        os << *(it);
    }
    os << "]";
    return os;
}