#ifndef LIST_HPP__
#define LIST_HPP__

#include <memory>
#include <iostream>
#include "list.h"


template <AssignCopyComparable T>
List<T>::List() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T>::List(std::initializer_list<U> list) {
    head = nullptr;
    tail = nullptr;
    csize = 0;
    for (auto it = list.begin(); it!= list.end(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T>::List(size_t size, const U& data) {
    // csize = size;
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < size; i++) {
        auto node = List<T>::ListNode::CreateNode(data, nullptr);
        pushBack(node);
    }
}

template <AssignCopyComparable T>
List<T>::List(const List<T>& list) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

template <AssignCopyComparable T>
List<T>::List(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}


template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T>::List(const C &container) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

// template <AssignCopyComparable T>
// template <ConvertibleContainer<typename List<T>::value_type> C>
// List<T>::List(C &&container) {
//     csize = 0;
//     head = nullptr;
//     tail = nullptr;
//     for (auto it = container.begin(); it!= container.end(); ++it) {
//         auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
//         pushBack(node);
//     }
// }

template <AssignCopyComparable T>
template <ConvertibleForwardIterator<typename List<T>::value_type> Iter>
List<T>::List(const Iter &begin, const Iter &end) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = begin; it!= end; ++it) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

template <AssignCopyComparable T>
List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    Clear();
    PushBack(list);
    return *this;
}

template <AssignCopyComparable T>
List<T>& List<T>::operator=(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator=(const C &container) {
    Clear();
    PushBack(container);
    return *this;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator=(std::initializer_list<U> list) {
    Clear();
    for (auto it = list.begin(); it!= list.end(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
    return *this;
}

template <AssignCopyComparable T>
List<T>::~List() = default;

template <AssignCopyComparable T>
bool List<T>::checkEmpty() const noexcept {
    return !IsEmpty();
}

template <AssignCopyComparable T>
bool List<T>::checkForeignIterator(const ListIterator<T> &iterator) noexcept {
    auto it = begin();
    for (; it != end() && it != iterator; ++it);
    return it != end();
}
template <AssignCopyComparable T>
bool List<T>::checkForeignIterator(const ConstListIterator<T> &iterator) const noexcept {
    auto it = cbegin();
    for (; it != cend() && it != iterator; ++it);
    return it != cend();
}

template <AssignCopyComparable T>
bool List<T>::checkListRange(const ListIterator<T> &begin, const ListIterator<T> &end) noexcept {
    auto it = this->begin();
    for (; it != end && it != begin && it != this->end(); ++it);
    if (it == this->end() || it == end)
        return false;
    for (; it != end && it != this->end(); ++it);
    return it != this->end();
}

template <AssignCopyComparable T>
bool List<T>::checkListRange(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const noexcept {
    auto it = this->cbegin();
    for (; it != end && it != begin && it != this->cend(); ++it);
    if (it == this->cend() || it == end)
        return false;
    for (; it != end && it != this->cend(); ++it);
    return it != this->cend();
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushBack(const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushBack(node);
}

template <AssignCopyComparable T>
void List<T>::PushBack(T&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(data), nullptr);
    pushBack(node);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushBack(const C& container) {
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <AssignCopyComparable T>
void List<T>::PushBack(List<T>&& list) noexcept {
    tail->SetNext(list.head);
    tail = list.tail;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator+=(const C& container) {
    PushBack(container);
    return *this;
}


template <AssignCopyComparable T>
List<T> &List<T>::operator+=(List<T>&& list) noexcept {
    PushBack(std::forward<List<T>>(list));
    return *this;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator+=(const U &data) {
    PushBack(std::forward<T>(T(data)));
    return *this;
}

template <AssignCopyComparable T>
List<T> &List<T>::operator+=(T &&data) {
    PushBack(std::forward<T>(data));
    return *this;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::AddList(const C& container) const {
    List<T> result(*this);
    result.PushBack(container);
    return result;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::AddList(const U &data) const {
    List<T> result(*this);
    result.PushBack(std::forward<T>(T(data)));
    return result;
}

template <AssignCopyComparable T>
List<T> List<T>::AddList(T &&data) const {
    List<T> result(*this);
    result.PushBack(std::forward<T>(data));
    return result;
}

template <AssignCopyComparable T>
List<T> List<T>::AddList(List<T>&& list) const {
    List<T> result(*this);
    result.PushBack(std::forward<List<T>>(list));
    list.head = nullptr;
    list.csize = 0;
    return result;
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::operator+(const C& container) const {
    List<T> result(*this);
    result.PushBack(container);
    return result;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::operator+(const U &data) const {
    List<T> result(*this);
    result.PushBack(std::forward<T>(T(data)));
    return result;
}

template <AssignCopyComparable T>
List<T> List<T>::operator+(T &&data) const {
    List<T> result(*this);
    result.PushBack(std::forward<T>(data));
    return result;
}

template <AssignCopyComparable T>
List<T> List<T>::operator+(List<T>&& list) const {
    List<T> result(*this);
    result.PushBack(std::forward<List<T>>(list));
    list.head = nullptr;
    list.csize = 0;
    return result;
}

template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushFront(const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushFront(node);
}

template <AssignCopyComparable T>
void List<T>::PushFront(T&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(data), nullptr);
    pushFront(node);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushFront(const C& container) {
    List<T> newList(container);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <AssignCopyComparable T>
void List<T>::PushFront(List<T>&& list) noexcept {
    list.tail->SetNext(head);
    head = list.head;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <AssignCopyComparable T>
T List<T>::PopFront() {
    return *popFront()->GetData();
}

template <AssignCopyComparable T>
T List<T>::PopBack() {
    return *popBack()->GetData();
}


template <AssignCopyComparable T>
void List<T>::Remove(const ListIterator<T> &it) {
   pop(it);
}

template <AssignCopyComparable T>
void List<T>::Remove(const ListIterator<T> &begin, const ListIterator<T> &end) {
    if (!checkEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (!checkListRange(begin, end)) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    pop(begin, end);
}

template <AssignCopyComparable T>
T List<T>::Pop(const ListIterator<T> &it) {
    return *pop(it)->GetData();
}

template <AssignCopyComparable T>
List<T> List<T>::Pop(const ListIterator<T> &begin, const ListIterator<T> &end) {
    if (!checkEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (!checkListRange(begin, end)) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return pop(begin, end);
}


template <AssignCopyComparable T>
List<T> List<T>::SubList(const ListIterator<T> &begin, const ListIterator<T> &end) {
    if (!checkEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (!checkListRange(begin, end)) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return subList(begin, end);
}


template <AssignCopyComparable T>
List<T> List<T>::SubList(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const {
    if (!checkEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (!checkListRange(begin, end)) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return subList(begin, end);
}


template <AssignCopyComparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(const ListIterator<T> &it, const U& data) {
    if (!checkForeignIterator(it)) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(it, node);
}

template <AssignCopyComparable T>
void List<T>::Insert(const ListIterator<T> &it, T&& data) {
    if (!checkForeignIterator(it)) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(data), nullptr);
    insert(it, node);
}

template <AssignCopyComparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(const ListIterator<T> &it, const C& container) {
    if (!checkForeignIterator(it)) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto cit = it;
    for (auto iter = container.begin(); iter != container.end(); ++iter, ++cit) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*iter)), nullptr);
        insert(cit, node);
    }
}

template <AssignCopyComparable T>
void List<T>::Insert(const ListIterator<T> &it, List<T>&& list) {
    if (!checkForeignIterator(it)) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (it + 1 == end()) {
        PushBack(std::forward<List<T>>(list));
        return;
    }
    auto nowNode = it.getNode();
    list.tail->SetNext(nowNode->GetNext());
    nowNode->SetNext(list.head);
    csize += list.size();
    list.Clear();
}

template <AssignCopyComparable T>
void List<T>::Clear() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <AssignCopyComparable T>
void List<T>::Reverse() noexcept {
    List<T> newList;
    while (csize > 0) {
        auto node = popFront();
        newList.pushFront(node);
    }
    *this = std::move(newList);
}

template <AssignCopyComparable T>
bool List<T>::IsEmpty() const noexcept {
    return csize == 0;
}

template <AssignCopyComparable T>
size_t List<T>::GetSize() const noexcept {
    return csize;
}

template <AssignCopyComparable T>
List<T>::size_type List<T>::size() const noexcept {
    return csize;
}

template <AssignCopyComparable T>
void List<T>::pushBack(std::shared_ptr<List<T>::ListNode> &node) noexcept {
    node->SetNext(nullptr);
    csize++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    tail->SetNext(node);
    tail = node;
}

template <AssignCopyComparable T>
void List<T>::pushFront(std::shared_ptr<List<T>::ListNode> &node) noexcept {
    node->SetNext(head);
    csize++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    head = node;
}

template <AssignCopyComparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::popFront(void)  {
    csize--;
    auto node = head;
    head = head->GetNext();
    if (head == nullptr) {
        tail = nullptr;
    }
    return node;
}

template <AssignCopyComparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::popBack(void)  {
    if (head == tail) {
        auto node = head;
        head = nullptr;
        tail = nullptr;
        csize = 0;
        return node;
    }
    auto node = head;
    while (node->GetNext() != tail) {
        node = node->GetNext();
    }
    node->SetNext(nullptr);
    std::swap(node, tail);
    csize--;
    return node;
}



template <AssignCopyComparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::pop(const ListIterator<T>& iterator)  {
    if (iterator == begin()) 
    {
        return popFront();
    }
    auto it = begin();
    for (; it!= end() && it + 1 != iterator; ++it);
    if (it + 1 == end())
    {
        return popBack();
    }
    csize--;
    auto node = it.getNode()->GetNext();
    it.getNode()->SetNext(it.getNode()->GetNext()->GetNext());
    return node;
}

template <AssignCopyComparable T>
List<T> List<T>::pop(const ListIterator<T>& begin, const ListIterator<T>& end)  {
    size_t count = distance(begin, end) + 1;
    List<T> newList;
    newList.head = begin.getNode();
    newList.tail = end.getNode();
    newList.csize = count;
    if (this->begin() == begin) {
        head = end.getNode()->GetNext();
        if (!head) {
            tail = nullptr;
        }
    } else {
        auto preBegin = this->begin();
        for (;preBegin + 1 != begin; ++preBegin);
        if (ListIterator<T>(tail) == end) {
            tail = preBegin.getNode();
            tail->SetNext(nullptr);
        } else {
            preBegin.getNode()->SetNext(end.getNode()->GetNext());
        }
    }
    end.getNode()->SetNext(nullptr);
    csize -= count;
    return newList;
}

template <AssignCopyComparable T>
List<T> List<T>::subList(const ListIterator<T>& begin, const ListIterator<T>& end) {
    return List<T>(begin, end + 1);
}

template <AssignCopyComparable T>
List<T> List<T>::subList(const ConstListIterator<T>& begin, const ConstListIterator<T>& end) const {
    return List<T>(begin, end + 1);
}

template <AssignCopyComparable T>
void List<T>::insert(const ListIterator<T>& iterator, std::shared_ptr<List<T>::ListNode> &node)  {
    if (iterator + 1 == end()) {
        pushBack(node);
        return;
    }
    auto nodeIt = iterator.getNode();
    node->SetNext(nodeIt->GetNext());
    nodeIt->SetNext(node);
    csize++;
}

template <AssignCopyComparable T>
ListIterator<T> List<T>::begin() noexcept {
    return ListIterator<T>(head);
}


template <AssignCopyComparable T>
ListIterator<T> List<T>::end() noexcept {
    if (head == nullptr) {
        return ListIterator<T>(nullptr);
    }
    return ListIterator<T>(tail) + 1;
}

template <AssignCopyComparable T>
ConstListIterator<T> List<T>::begin() const noexcept {
    return ConstListIterator<T>(head);
}


template <AssignCopyComparable T>
ConstListIterator<T> List<T>::end() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}

template <AssignCopyComparable T>
ConstListIterator<T> List<T>::cbegin() const noexcept {
    return ConstListIterator<T>(head);
}

template <AssignCopyComparable T>
ConstListIterator<T> List<T>::cend() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}

template <AssignCopyComparable T>
int List<T>::cmpList(const List<T> &other) const {
    auto cit1 = cbegin();
    auto cit2 = other.cbegin();
    for (;cit1 != cend() && cit2!= other.cend(); ++cit1, ++cit2)
    {
        if (*cit1 < *cit2) {
            return -1;
        }
        if (*cit1 > *cit2) {
            return 1;
        }
    }
    if (csize > other.GetSize())
        return 1;
    if (csize < other.GetSize())
        return -1;
    return 0;
}


template <typename T, Convertible<T> U>
List<T> operator+(const U& data, const List<T> &list) {
    List<T> result(list);
    result.PushFront(T(data));
    return result;
}

template <typename T, Convertible<T> U>
List<T> operator+(U&& data, const List<T> &list) {
    List<T> result(list);
    result.PushFront(T(data));
    return result;
}

template <AssignCopyComparable T>
bool List<T>::operator==(const List<T> &list) const  {
    return cmpList(list) == 0;
}

template <AssignCopyComparable T>
bool List<T>::operator!=(const List<T> &list) const  {
    return cmpList(list)!= 0;
}

template <AssignCopyComparable T>
bool List<T>::operator<(const List<T> &list) const  {
    return cmpList(list) < 0;
}

template <AssignCopyComparable T>
bool List<T>::operator>(const List<T> &list) const  {
    return cmpList(list) > 0;
}

template <AssignCopyComparable T>
bool List<T>::operator<=(const List<T> &list) const  {
    return cmpList(list) <= 0;
}

template <AssignCopyComparable T>
bool List<T>::operator>=(const List<T> &list) const  {
    return cmpList(list) >= 0;
}

template <AssignCopyComparable T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    os << "{";
    auto a = list.cbegin();
    if (a != list.cend()) {
        os << *a;
        a++;
    }
    for (; a != list.cend(); a++) {
        os << ", " << *a;
    }
    os << "}";
    os << "(" << list.size() << ")";
    return os;
}

#endif // LIST_H__
