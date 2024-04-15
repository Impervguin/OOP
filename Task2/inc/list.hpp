#ifndef LIST_HPP__
#define LIST_HPP__

#include <memory>
#include <iostream>
#include "list.h"

template <typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
List<T>::List(std::initializer_list<T> list) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (auto it = list.begin(); it!= list.end(); it++) {
        auto node = std::make_shared<ListNode<T>>(*it);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(size_t size, const T& data) {
    size = size;
    head = std::make_shared<ListNode<T>>(data);
    tail = head;
    for (int i = 1; i < size; i++) {
        auto node = std::make_shared<ListNode<T>>(data);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(const List<T>& list) {
    size = list.GetSize();
    head = nullptr;
    tail = nullptr;
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = std::make_shared<ListNode<T>>(*it);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(const ListIterator<T> &begin, const ListIterator<T> &end) {
    auto tmp = head;
    head = nullptr;
    tail = nullptr;
    size = 0;
    for (auto it = begin + 1; it != end; it++) {
        auto node = std::make_shared<ListNode<T>>(*it);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(List<T>&& list) {
    head = list.head;
    tail = list.tail;
    size = list.size;
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

template <typename T>
List<T>::~List() = default;

template <typename T>
void List<T>::checkEmpty(size_t line) const {
    if (IsEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <typename T>
void List<T>::PushBack(const T& data) {
    auto node = std::make_shared<ListNode<T>>(data);
    pushBack(node);
}

template <typename T>
void List<T>::PushBack(const List<T>& list) {
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = std::make_shared<ListNode<T>>(*it);
        pushBack(node);
    }
}

template <typename T>
void List<T>::PushBack(List<T>&& list) {
    tail->SetNext(list.head);
    tail = list.tail;
    size += list.size;
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

template <typename T>
void List<T>::PushFront(const T& data) {
    auto node = std::make_shared<ListNode<T>>(data);
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
    size += list.size;
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

template <typename T>
T &List<T>::PopFront() {
    return popFront()->GetData();
}

template <typename T>
T &List<T>::PopBack() {
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
const T &List<T>::Get(const ListIterator<T> &it) const {
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
const T &List<T>::operator[](const ListIterator<T> &it) const {
    return get(it)->GetData();
}

template <typename T>
const T &List<T>::operator[](const ConstListIterator<T> &it) const {
    return get(it)->GetData();
}


template <typename T>
void List<T>::pushBack(std::shared_ptr<ListNode<T>> &node) {
    node->SetNext(nullptr);
    size++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    tail->SetNext(node);
    tail = node;
}

template <typename T>
void List<T>::pushFront(std::shared_ptr<ListNode<T>> &node) {
    node->SetNext(head);
    size++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }
    head = node;
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::popFront(void) {
    checkEmpty(__LINE__);
    size--;
    auto node = head;
    head = head->GetNext();
    return node;
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::popBack(void) {
    checkEmpty(__LINE__);
    if (head == tail) {
        auto node = head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return node;
    }
    auto node = head;
    while (node->GetNext()!= tail) {
        node = node->GetNext();
    }
    node->SetNext(nullptr);
    std::swap(node, tail);
    return node;
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::get(size_t index) const {
    if (index >= size) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto node = head;
    for (size_t i = 0; i < index; i++) {
        node = node->GetNext();
    }
    return node;
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::get(const ListIterator<T>& iterator) const {
    auto node = head;
    for (; node != nullptr; node = node->GetNext()) {
        if (ListIterator<T>(node) == iterator) {
            return node;
        }
    }
    time_t now = time(nullptr);
    throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    return nullptr;
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::get(const ConstListIterator<T>& iterator) const {
    auto node = head;
    for (; node != nullptr; node = node->GetNext()) {
        if (ConstListIterator<T>(node) == iterator) {
            return node;
        }
    }
    time_t now = time(nullptr);
    throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    return nullptr;
}

template <typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator<T>(head);
}


template <typename T>
ListIterator<T> List<T>::end() {
    if (head == nullptr) {
        return ListIterator<T>(nullptr);
    }
    return ListIterator<T>(tail) + 1;
}

template <typename T>
ConstListIterator<T> List<T>::cbegin() const {
    return ConstListIterator<T>(head);
}

template <typename T>
ConstListIterator<T> List<T>::cend() const {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}


template <typename T>
List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
    PushBack(list);
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& list) {
    head = list.head;
    tail = list.tail;
    size = list.size;
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
    return *this;
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
