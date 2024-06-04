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
BSTree<T>::BSTree(std::initializer_list<U> list)
: _root(nullptr), _size(0) {
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
BSTree<T>::BSTree(const Iter &begin, const Iter &end)
: _root(nullptr), _size(0) {
    for (auto it = begin; it!= end; ++it) {
        Add(*it);
    }
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T>::BSTree(const C &container)
: _root(nullptr), _size(0) {
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
    auto node = BSTree<T>::TreeNode::CreateNode(data);
    add(node);
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T>& BSTree<T>::operator+=(const U &data) {
    Add(data);
    return *this;
}

template <AssignCopyComparable T>
void BSTree<T>::Add(T&& data) {
    auto node = BSTree<T>::TreeNode::CreateNode(std::forward<T>(data));
    add(node);
}

template <AssignCopyComparable T>
BSTree<T>& BSTree<T>::operator+=(T&& data) {
    Add(std::forward<T>(data));
    return (*this);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::Add(const C &container) {
    for (auto it = container.begin(); it != container.end(); it++) {
        auto node = BSTree<T>::TreeNode::CreateNode(*it);
        add(node);
    }
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T>& BSTree<T>::operator+=(const C &container) {
    Add(container);
    return (*this);
}

template <AssignCopyComparable T>
void BSTree<T>::Add(BSTree<T> &&bstree) noexcept {
    recursiveAdd(bstree._root);
    bstree.Clear();
}

template <AssignCopyComparable T>
BSTree<T>& BSTree<T>::operator+=(BSTree<T> &&bstree) noexcept {
    recursiveAdd(bstree._root);
    bstree.Clear();
    return *this;
}

// Добавление с копированием
template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T> BSTree<T>::CopyAdd(const U &data) const {
    BSTree<T> copy(*this);
    copy.Add(data);
    return copy;
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T> BSTree<T>::operator+(const U &data) const {
    return CopyAdd(data);
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::CopyAdd(T&& data) const {
    BSTree<T> copy(*this);
    copy.Add(data);
    return copy;
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::operator+(T&& data) const {
    return CopyAdd(data);
}


template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::CopyAdd(const C &container) const {
    BSTree<T> copy(*this);
    copy.Add(container);
    return copy;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::operator+(const C &container) const {
    return CopyAdd(container);
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::CopyAdd(BSTree<T> &&bstree) const noexcept {
    BSTree<T> copy(*this);
    copy.Add(std::forward<BSTree<T> >(bstree));
    return copy;
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::operator+(BSTree<T> &&bstree) const noexcept {
    return CopyAdd(std::forward<BSTree<T> >(bstree));
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
bool BSTree<T>::Find(const U &data) const noexcept {
    T dataT = data;
    return find(dataT) != nullptr;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
bool BSTree<T>::Find(const C &container) const noexcept {
    for (auto it = container.begin(); it!= container.end(); it++) {
        T dataT = *it;
        if (find(dataT) == nullptr) {
            return false;
        }
    }
    return true;
}

// Удаление элементов

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
void BSTree<T>::Remove(const U &data) noexcept {
    T dataT = data;
    remove(dataT);
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T>& BSTree<T>::operator-=(const U &data) noexcept {
    Remove(data);
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::Remove(const C &container) noexcept {
    for (auto it = container.begin(); it!= container.end(); it++) {
        T dataT = *it;
        remove(dataT);
    }
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T>& BSTree<T>::operator-=(const C &container) noexcept {
    Remove(container);
    return *this;
}

// Удаление с копированием
template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T> BSTree<T>::CopyRemove(const U &data) const {
    BSTree<T> copy(*this);
    copy.Remove(data);
    return copy;
}

template <AssignCopyComparable T>
template <Convertible<typename BSTree<T>::value_type> U>
BSTree<T> BSTree<T>::operator-(const U &data) const {
    return CopyRemove(data);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::CopyRemove(const C &container) const {
    BSTree<T> copy(*this);
    copy.Remove(container);
    return copy;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::operator-(const C &container) const {
    return CopyRemove(container);
}

// Пересечение
template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::Intersection(const C &container) noexcept {
    intersection(container);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> &BSTree<T>::operator&=(const C &container) noexcept {
    Intersection(container);
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::IntersectionCopy(const C &container) const {
    BSTree<T> copy(*this);
    copy.Intersection(container);
    return copy;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::operator&(const C &container) const {
    return IntersectionCopy(container);
}

// Симметрическая Разность
template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::SymmetricDifference(const C &container) {
    symmetricDifference(container);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> &BSTree<T>::operator^=(const C &container) {
    SymmetricDifference(container);
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::SymmetricDifferenceCopy(const C &container) const {
    BSTree<T> copy(*this);
    copy.SymmetricDifference(container);
    return copy;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
BSTree<T> BSTree<T>::operator^(const C &container) const {
    return SymmetricDifferenceCopy(container);
}

template <AssignCopyComparable T>
void BSTree<T>::SymmetricDifference(BSTree<T> &&bstree) noexcept {
    recursiveSymmetricDifference(bstree._root);
    bstree.Clear();
}

template <AssignCopyComparable T>
BSTree<T> &BSTree<T>::operator^=(BSTree<T> &&bstree) noexcept {
    SymmetricDifference(std::forward<BSTree<T>>(bstree));
    return *this;
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::SymmetricDifferenceCopy(BSTree<T> &&bstree) const noexcept {
    BSTree<T> copy(*this);
    copy.SymmetricDifference(std::forward<BSTree<T>>(bstree));
    return copy;
}

template <AssignCopyComparable T>
BSTree<T> BSTree<T>::operator^(BSTree<T> &&bstree) const noexcept {
    return SymmetricDifferenceCopy(std::forward<BSTree<T>>(bstree));
}

template <AssignCopyComparable T>
bool BSTree<T>::IsEqual(const BSTree<T> &bstree) const noexcept {
    return compare(bstree);
}

template <AssignCopyComparable T>
bool BSTree<T>::IsNotEqual(const BSTree<T> &bstree) const noexcept {
    return !IsEqual(bstree);
}

template <AssignCopyComparable T>
bool BSTree<T>::operator==(const BSTree<T> &bstree) const noexcept {
    return IsEqual(bstree);
}

template <AssignCopyComparable T>
bool BSTree<T>::operator!=(const BSTree<T> &bstree) const noexcept {
    return IsNotEqual(bstree);
}


template <AssignCopyComparable T>
void BSTree<T>::Clear() noexcept {
    _root = nullptr;
    _size = 0;
}

template <AssignCopyComparable T>
void BSTree<T>::add(std::shared_ptr<BSTree<T>::TreeNode> node) noexcept {
    if (_root == nullptr) {
        _root = node;
        _size++;
        return;
    }

    auto now = _root;
    while (true) {
        if (*node->GetData() < *now->GetData()) {
            if (now->GetLeft() == nullptr) {
                now->SetLeft(node);
                _size++;
                return;
            }
            now = now->GetLeft();
        } else if (*node->GetData() > *now->GetData()) {
            if (now->GetRight() == nullptr) {
                now->SetRight(node);
                _size++;
                return;
            }
            now = now->GetRight();
        } else {
            return;
        }
    }
}

template <AssignCopyComparable T>
void BSTree<T>::recursiveAdd(std::shared_ptr<typename BSTree<T>::TreeNode> root) noexcept {
    if (root == nullptr) {
        return;
    }

    auto left = root->GetLeft();
    auto right = root->GetRight();
    root->SetLeftNull();
    root->SetRightNull();

    add(root);
    recursiveAdd(left);
    recursiveAdd(right);
}


template <AssignCopyComparable T>
std::shared_ptr<typename BSTree<T>::TreeNode> BSTree<T>::find(const T &data) const noexcept {
    auto now = _root;
    while (now != nullptr) {
        if (data < *now->GetData()) {
            now = now->GetLeft();
        } else if (data > *now->GetData()) {
            now = now->GetRight();
        } else {
            break;
        }
    }
    return now;
}
template <AssignCopyComparable T>
std::shared_ptr<typename BSTree<T>::TreeNode> BSTree<T>::remove(const T &data) noexcept {
    auto now = _root;
    while (now != nullptr && *now->GetData() != data) {
        if (now->GetLeft() != nullptr && *now->GetLeft()->GetData() == data) {
            auto tmp = now->GetLeft();
            now->SetLeftNull();
            now = tmp;
            break;
        } else if (now->GetRight() != nullptr && *now->GetRight()->GetData() == data) {
            auto tmp = now->GetRight();
            now->SetRightNull();
            now = tmp;
            break;
        }

        if (data < *now->GetData()) {
            now = now->GetLeft();
        } else {
            now = now->GetRight();
        }
    }
    if (now == nullptr) {
        return now;
    }

    auto left = now->GetLeft();
    auto right = now->GetRight();
    now->SetLeftNull();
    now->SetRightNull();
    if (now == _root) {
        _root = nullptr;
    }
    _size--;
    if (left != nullptr) {
        _size--;
        add(left);
    }
    if (right != nullptr) {
        _size--;
        add(right);
    }
    return now;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::intersection(const C &container) noexcept {
    BSTree<T> tmp;
    for (auto it = container.begin(); it!= container.end(); it++) {
        auto node = remove(*it);
        if (node!= nullptr) {
            tmp.add(node);
        }
    }
    *this = std::move(tmp);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename BSTree<T>::value_type> C>
void BSTree<T>::symmetricDifference(const C &container) {
    BSTree<T> tmp;
    for (auto it = container.begin(); it!= container.end(); it++) {
        auto node = remove(*it);
        if (node == nullptr) {
            tmp.Add(*it);
        }
    }
    tmp.recursiveAdd(_root);
    Clear();
    *this = std::move(tmp);
}

template <AssignCopyComparable T>
void BSTree<T>::recursiveSymmetricDifference(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return;
    }

    auto left = root->GetLeft();
    auto right = root->GetRight();
    root->SetLeftNull();
    root->SetRigthNull();
    if (remove(*root->GetData()) == nullptr) {
        add(root);
    }

    recursiveSymmetricDifference(left);
    recursiveSymmetricDifference(right);
}

template <AssignCopyComparable T>
bool BSTree<T>::compare(const BSTree<T> &bstree) const noexcept {
    if (size()!= bstree.size()) {
        return false;
    }
    auto it1 = begin();
    auto it2 = bstree.begin();
    for (; it1!= end(); ++it1, ++it2) {
        if (*it1!= *it2) {
            return false;
        }
    }
    return true;
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