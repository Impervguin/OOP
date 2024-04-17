#ifndef LIST_HPP__
#define LIST_HPP__

#include <memory>
#include <iostream>
#include "list.h"


template <typename T>
List<T>::List() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <typename T>
List<T>::List(std::initializer_list<T> list) noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
    for (auto it = list.begin(); it!= list.end(); it++) {
        auto node = std::make_shared<List<T>::ListNode>(*it);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(size_t size, const T& data) noexcept {
    // csize = size;
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < size; i++) {
        auto node = std::make_shared<List<T>::ListNode>(data);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(const List<T>& list) noexcept {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = std::make_shared<List<T>::ListNode>(*it);
        pushBack(node);
    }
}

// template <typename T>
// List<T>::List(const ListIterator<T> &begin, const ListIterator<T> &end) {
//     auto tmp = head;
//     head = nullptr;
//     tail = nullptr;
//     csize = 0;
//     for (auto it = begin + 1; it != end; it++) {
//         auto node = std::make_shared<List<T>::ListNode>(*it);
//         pushBack(node);
//     }
// }

template <typename T>
List<T>::List(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

// template <typename T>
// template <typename U> requires Convertible<U, T>
// List<T>::List(List<U> &list) {
//     csize = list.GetSize();
//     head = nullptr;
//     tail = nullptr;
//     for (auto it = list.cbegin(); it!= list.cend(); it++) {
//         auto node = std::make_shared<List<T>::ListNode>(T(*it));
//         pushBack(node);
//     }
// }

template <typename T>
template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
List<T>::List(const C &container) noexcept {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = std::make_shared<List<T>::ListNode>(T(*it));
        pushBack(node);
    }
}

template <typename T>
template <ForwardIterator Iter> requires Convertible<typename Iter::value_type, typename List<T>::value_type>
List<T>::List(const Iter &begin, const Iter &end) noexcept {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = begin; it!= end; it++) {
        auto node = std::make_shared<List<T>::ListNode>(T(*it));
        pushBack(node);
    }
}

template <typename T>
List<T>::~List() noexcept = default;

template <typename T>
void List<T>::checkEmpty(size_t line) const {
    if (IsEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <typename T>
void List<T>::PushBack(const T& data) {
    auto node = std::make_shared<List<T>::ListNode>(data);
    pushBack(node);
}

template <typename T>
void List<T>::PushBack(const List<T>& list) {
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = std::make_shared<List<T>::ListNode>(*it);
        pushBack(node);
    }
}

template <typename T>
void List<T>::PushBack(List<T>&& list) {
    tail->SetNext(list.head);
    tail = list.tail;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <typename T>
void List<T>::PushFront(const T& data) {
    auto node = std::make_shared<List<T>::ListNode>(data);
    pushFront(node);
}

template <typename T>
void List<T>::PushFront(const List<T>& list) {
    List<T> newList(list);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <typename T>
void List<T>::PushFront(List<T>&& list) {
    list.tail->SetNext(head);
    head = list.head;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <typename T>
T List<T>::PopFront() {
    return popFront()->GetData();
}

template <typename T>
T List<T>::PopBack() {
    return popBack()->GetData();
}

template <typename T>
T &List<T>::GetFront() {
    checkEmpty(__LINE__);
    return head->GetData();
}

template <typename T>
const T &List<T>::GetFront() const {
    checkEmpty(__LINE__);
    return head->GetData();
}

template <typename T>
T &List<T>::GetBack() {
    checkEmpty(__LINE__);
    return tail->GetData();
}

template <typename T>
const T &List<T>::GetBack() const {
    checkEmpty(__LINE__);
    return tail->GetData();
}

template <typename T>
T &List<T>::Get(size_t index) {
    return get(index)->GetData();
}

template <typename T>
const T &List<T>::Get(size_t index) const {
    return get(index)->GetData();
}

template <typename T>
T &List<T>::Get(const ListIterator<T> &it) {
    return get(it)->GetData();
}

template <typename T>
const T &List<T>::Get(const ConstListIterator<T> &it) const {
    return get(it)->GetData();
}

template <typename T>
T &List<T>::operator[](size_t index) {
    return get(index)->GetData();
}

template <typename T>
const T &List<T>::operator[](size_t index) const {
    return get(index)->GetData();
}

template <typename T>
T &List<T>::operator[](const ListIterator<T> &it) {
    return get(it)->GetData();
}

template <typename T>
const T &List<T>::operator[](const ConstListIterator<T> &it) const {
    return get(it)->GetData();
}

template <typename T>
void List<T>::Set(size_t index, const T& data) {
    get(index)->SetData(data);
}

template <typename T>
void List<T>::Set(const ListIterator<T> &it, const T& data) {
    get(it)->SetData(data);
}

template <typename T>
void List<T>::Remove(size_t index) {
    pop(index);
}

template <typename T>
void List<T>::Remove(const ListIterator<T> &it) {
   pop(it);
}

template <typename T>
T List<T>::Pop(size_t index) {
    return pop(index)->GetData();
}

template <typename T>
T List<T>::Pop(const ListIterator<T> &it) {
    return pop(it)->GetData();
}

template <typename T>
void List<T>::Insert(size_t index, const T& data) {
    auto node = std::make_shared<List<T>::ListNode>(data);
    insert(index, node);
}

template <typename T>
void List<T>::InsertAfter(const ListIterator<T> &it, const T& data) {
    auto node = std::make_shared<List<T>::ListNode>(data);
    insertAfter(it, node);
}

template <typename T>
void List<T>::InsertBefore(const ListIterator<T> &it, const T& data) {
    auto node = std::make_shared<List<T>::ListNode>(data);
    insertBefore(it, node);
}

template <typename T>
void List<T>::Clear() {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <typename T>
void List<T>::Reverse() {
    List<T> newList;
    while (csize > 0) {
        auto node = popFront();
        newList.pushFront(node);
    }
    *this = std::move(newList);
}

template <typename T>
bool List<T>::IsEmpty() const {
    return csize == 0;
}

template <typename T>
size_t List<T>::GetSize() const {
    return csize;
}

template <typename T>
size_t List<T>::size() const noexcept {
    return csize;
}


template <typename T>
void List<T>::pushBack(std::shared_ptr<List<T>::ListNode> &node) {
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

template <typename T>
void List<T>::pushFront(std::shared_ptr<List<T>::ListNode> &node) {
    node->SetNext(head);
    csize++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    head = node;
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::popFront(void) {
    checkEmpty(__LINE__);
    csize--;
    auto node = head;
    head = head->GetNext();
    if (head == nullptr) {
        tail = nullptr;
    }
    return node;
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::popBack(void) {
    checkEmpty(__LINE__);
    if (head == tail) {
        auto node = head;
        head = nullptr;
        tail = nullptr;
        csize = 0;
        return node;
    }
    auto node = head;
    while (node->GetNext()!= tail) {
        node = node->GetNext();
    }
    node->SetNext(nullptr);
    std::swap(node, tail);
    csize--;
    return node;
}

template <typename T>
const std::shared_ptr<typename List<T>::ListNode> List<T>::get(size_t index) const {
    if (index >= csize) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    auto it = cbegin();
    for (size_t i = 0; i < index && it!= cend(); i++, it++);
    if (it == cend()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return it.getNode();
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::get(size_t index) {
    if (index >= csize) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    
    auto it = begin();
    for (size_t i = 0; i < index && it != end(); i++, it++);
    if (it == end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return it.getNode();
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::get(const ListIterator<T>& iterator) {
    auto it = begin();
    for (; it != end() & it != iterator; it++);
    if (it == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return it.getNode();
}

template <typename T>
const std::shared_ptr<typename List<T>::ListNode> List<T>::get(const ConstListIterator<T>& iterator) const {
    auto it = cbegin();
    for (; it != cend() & it != iterator; it++);
    if (it == cend()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return it.getNode();
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::pop(size_t index) {
    checkEmpty(__LINE__);
    if (index == 0) {
        return popFront();
    }
    if (index == csize - 1) {
        return popBack();
    }
    if (index >= csize) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto it = begin();
    for (size_t i = 0; i < index - 1 && it!= end(); i++, ++it);
    if (it == end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    csize--;
    auto node = it.getNode()->GetNext();
    it.getNode()->SetNext(it.getNode()->GetNext()->GetNext());
    return node;
}

template <typename T>
std::shared_ptr<typename List<T>::ListNode> List<T>::pop(const ListIterator<T>& iterator) {
    checkEmpty(__LINE__);
    if (iterator == begin()) 
    {
        return popFront();
    }
    auto it = begin();
    for (; it!= end() && it + 1 != iterator; ++it);
    if (it == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (it + 1 == end())
    {
        return popBack();
    }
    csize--;
    auto node = it.getNode()->GetNext();
    it.getNode()->SetNext(it.getNode()->GetNext()->GetNext());
    return node;
}

template <typename T>
void List<T>::insert(size_t index, std::shared_ptr<List<T>::ListNode> &node) {
    if (index == 0) {
        pushFront(node);
        return;
    }
    if (index == csize) {
        pushBack(node);
        return;
    }
    auto prev = get(index - 1);
    node->SetNext(prev->GetNext());
    prev->SetNext(node);
    csize++;
 }

 template <typename T>
void List<T>::insertAfter(const ListIterator<T>& iterator, std::shared_ptr<List<T>::ListNode> &node) {
    if (iterator + 1 == end()) {
        pushBack(node);
        return;
    }
    auto nodeIt = get(iterator);
    node->SetNext(nodeIt->GetNext());
    nodeIt->SetNext(node);
    csize++;
}

template <typename T>
void List<T>::insertBefore(const ListIterator<T>& iterator, std::shared_ptr<List<T>::ListNode> &node) {
    if (iterator == begin()) {
        pushFront(node);
        return;
    }
    auto it = begin();
    for (; it != end() && it + 1 != iterator; ++it);
    if (it == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    csize++;
    node->SetNext(it.getNode()->GetNext());
    it.getNode()->SetNext(node);
}

template <typename T>
ListIterator<T> List<T>::begin() noexcept {
    return ListIterator<T>(head);
}


template <typename T>
ListIterator<T> List<T>::end() noexcept {
    if (head == nullptr) {
        return ListIterator<T>(nullptr);
    }
    return ListIterator<T>(tail) + 1;
}

template <typename T>
ConstListIterator<T> List<T>::cbegin() const noexcept {
    return ConstListIterator<T>(head);
}

template <typename T>
ConstListIterator<T> List<T>::cend() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}

template <typename T>
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


template <typename T>
List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    head = nullptr;
    tail = nullptr;
    csize = 0;
    PushBack(list);
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& list) {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const List<T>& list) {
    PushBack(list);
    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(List<T>&& list) {
    PushBack(std::move(list));
    return *this;
}

template <typename T>
List<T> &List<T>::operator+=(const T &data) {
    PushBack(data);
    return *this;
}

template <typename T>
List<T> List<T>::operator+(const List<T>& list) const {
    List<T> result(*this);
    result.PushBack(list);
    return result;
}

template <typename T>
List<T> List<T>::operator+(List<T>&& list) const {
    List<T> result(*this);
    result.PushBack(std::move(list));
    list.head = nullptr;
    list.csize = 0;
    return result;
}

template <typename T>
List<T> List<T>::operator+(const T &data) const {
    List<T> result(*this);
    result.PushBack(data);
    return result;
}

template <typename T>
bool List<T>::operator==(const List<T> &list) const {
    return cmpList(list) == 0;
}


template <typename T>
bool List<T>::operator!=(const List<T> &list) const {
    return cmpList(list)!= 0;
}

template <typename T>
bool List<T>::operator<(const List<T> &list) const {
    return cmpList(list) < 0;
}

template <typename T>
bool List<T>::operator>(const List<T> &list) const {
    return cmpList(list) > 0;
}

template <typename T>
bool List<T>::operator<=(const List<T> &list) const {
    return cmpList(list) <= 0;
}

template <typename T>
bool List<T>::operator>=(const List<T> &list) const {
    return cmpList(list) >= 0;
}


template <typename T>
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
    return os;
}

#endif // LIST_HPP__
