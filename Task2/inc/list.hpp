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

template <typename T>
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

template <typename T>
List<T>::List(const List<T>& list) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

template <typename T>
List<T>::List(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}


template <typename T>
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

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T>::List(C &&container) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = container.begin(); it!= container.end(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <typename T>
template <ConvertibleForwardIterator<typename List<T>::value_type> Iter>
List<T>::List(const Iter &begin, const Iter &end) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = begin; it!= end; it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
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
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushBack(const U& data) {
    auto node = List<T>::ListNode::CreateNode(T(data), nullptr);
    pushBack(node);
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushBack(U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushBack(node);
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushBack(const C& container) {
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushBack(C &&container) {
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <typename T>
void List<T>::PushBack(List<T>&& list) noexcept {
    tail->SetNext(list.head);
    tail = list.tail;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushFront(const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushFront(node);
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushFront(U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushFront(node);
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushFront(const C& container) {
    List<T> newList(container);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushFront(C &&container) {
    List<T> newList(container);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <typename T>
void List<T>::PushFront(List<T>&& list) noexcept {
    list.tail->SetNext(head);
    head = list.head;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <typename T>
T List<T>::PopFront() {
    return *popFront()->GetData();
}

template <typename T>
T List<T>::PopBack() {
    return *popBack()->GetData();
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
void List<T>::Remove(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    auto it = this->begin();
    for (; it != this->end() && it != begin && it != end; ++it);
    if (it == this->end() || it == end) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (; it != this->end() && it != end; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    pop(begin, end);
}

template <typename T>
void List<T>::Remove(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return;
    }
    auto it = this->begin();
    for (; it != this->end() && it != begin; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    pop(begin, it);
}

template <typename T>
void List<T>::Remove(size_t index, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return;
    }
    auto it = this->begin();
    for (size_t i = 0; it != this->end() && i < index; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto begin = it;
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    pop(begin, it);
}

template <typename T>
T List<T>::Pop(size_t index) {
    return *pop(index)->GetData();
}

template <typename T>
T List<T>::Pop(const ListIterator<T> &it) {
    return *pop(it)->GetData();
}

template <typename T>
List<T> List<T>::Pop(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    auto it = this->begin();
    for (; it != this->end() && it != begin && it != end; ++it);
    if (it == this->end() || it == end) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (; it != this->end() && it != end; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return pop(begin, end);
}

template <typename T>
List<T> List<T>::Pop(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->begin();
    for (; it != this->end() && it != begin; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return pop(begin, it);
}

template <typename T>
List<T> List<T>::Pop(size_t index, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->begin();
    for (size_t i = 0; it != this->end() && i < index; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto begin = it;
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return pop(begin, it);
}

template <typename T>
List<T> List<T>::SubList(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    auto it = this->begin();
    for (; it != this->end() && it != begin && it != end; ++it);
    if (it == this->end() || it == end) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (; it != this->end() && it != end; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return subList(begin, end);
}

template <typename T>
List<T> List<T>::SubList(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->begin();
    for (; it != this->end() && it != begin; ++it);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return subList(begin, it);
}

template <typename T>
List<T> List<T>::SubList(size_t index, size_t count) {
    checkEmpty(__LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->begin();
    for (size_t i = 0; it != this->end() && i < index; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    auto begin = it;
    for (size_t i = 0; it != this->end() && i < count - 1; ++it, ++i);
    if (it == this->end()) {
        time_t now = time(nullptr);
        throw OutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return subList(begin, it);
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(size_t index, const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(index, node);
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(size_t index, U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(index, node);
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(size_t index, const C& container) {
    for (auto it = container.begin(); it != container.end(); ++it, ++index) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        insert(index, node);
    }
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(size_t index, C&& container) {
    for (auto it = container.begin(); it != container.end(); ++it, ++index) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        insert(index, node);
    }
}

template <typename T>
void List<T>::Insert(size_t index, List<T>&& list) {
    if (index == 0) {
        PushFront(std::forward<List<T>>(list));
    } else if (index == list.size()) {
        PushBack(std::forward<List<T>>(list));
    } else {
        auto node = get(index - 1);
        list.tail->SetNext(node->GetNext());
        node->SetNext(list.head);
    }
    list.Clear();
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(const ListIterator<T> &it, const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insertAfter(it, node);
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(const ListIterator<T> &it, U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insertAfter(it, node);
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(const ListIterator<T> &it, const C& container) {
    auto iter = begin();
    for (; iter != end() && iter != it; ++iter);
    if (iter == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (iter + 1 == end()) {
        PushBack(container);
        return;
    }
    auto nowNode = iter.getNode();
    for (auto iter = container.begin(); iter != container.end(); ++iter, nowNode = nowNode->GetNext()) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*iter)), nowNode->GetNext());
        nowNode->SetNext(node);
    }
    csize += container.size();
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(const ListIterator<T> &it, C&& container) {
    auto iter = begin();
    for (; iter != end() && iter != it; ++iter);
    if (iter == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (iter + 1 == end()) {
        PushBack(std::forward<C>(container));
        return;
    }
    auto nowNode = iter.getNode();
    for (auto iter = container.begin(); iter != container.end(); ++iter, nowNode = nowNode->GetNext()) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*iter)), nowNode->GetNext());
        nowNode->SetNext(node);
    }
    csize += container.size();
}

template <typename T>
void List<T>::Insert(const ListIterator<T> &it, List<T>&& list) {
    
    auto iter = begin();
    for (; iter != end() && iter != it; ++iter);
    if (iter == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    if (iter + 1 == end()) {
        PushBack(std::forward<List<T>>(list));
        return;
    }
    auto nowNode = iter.getNode();
    list.tail->SetNext(nowNode->GetNext());
    nowNode->SetNext(list.head);
    csize += list.size();
    list.Clear();
}

template <typename T>
void List<T>::Clear() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <typename T>
void List<T>::Reverse() noexcept {
    List<T> newList;
    while (csize > 0) {
        auto node = popFront();
        newList.pushFront(node);
    }
    *this = std::move(newList);
}

template <typename T>
bool List<T>::IsEmpty() const noexcept {
    return csize == 0;
}

template <typename T>
size_t List<T>::GetSize() const noexcept {
    return csize;
}

template <typename T>
List<T>::size_type List<T>::size() const noexcept {
    return csize;
}

template <typename T>
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

template <typename T>
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
    for (; it != end() && it != iterator; it++);
    if (it == end()) {
        time_t now = time(nullptr);
        throw InvalidIteratorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return it.getNode();
}

template <typename T>
const std::shared_ptr<typename List<T>::ListNode> List<T>::get(const ConstListIterator<T>& iterator) const {
    auto it = cbegin();
    for (; it != cend() && it != iterator; it++);
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
List<T> List<T>::pop(const ListIterator<T>& begin, const ListIterator<T>& end) {
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

template <typename T>
List<T> List<T>::subList(const ListIterator<T>& begin, const ListIterator<T>& end) {
    return List<T>(begin, end + 1);
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
ConstListIterator<T> List<T>::begin() const noexcept {
    return ConstListIterator<T>(head);
}


template <typename T>
ConstListIterator<T> List<T>::end() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
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
    Clear();
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
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator=(const C &container) {
    Clear();
    PushBack(container);
    return *this;
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator=(C &&container) {
    Clear();
    PushBack(std::move(container));
    return *this;
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator+=(const C& container) {
    PushBack(container);
    return *this;
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator+=(C&& container) {
    PushBack(std::move(container));
    return *this;
}


template <typename T>
List<T> &List<T>::operator+=(List<T>&& list) noexcept {
    PushBack(std::move(list));
    return *this;
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator+=(const U &data) {
    PushBack(T(data));
    return *this;
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator+=(U &&data) {
    PushBack(std::move(T(data)));
    return *this;
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::operator+(const C& container) const {
    List<T> result(*this);
    result.PushBack(container);
    return result;
}

template <typename T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::operator+(C &&container) const {
    List<T> result(*this);
    result.PushBack(std::move(container));
    return result;
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::operator+(const U &data) const {
    List<T> result(*this);
    result.PushBack(T(data));
    return result;
}

template <typename T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::operator+(U &&data) const {
    List<T> result(*this);
    result.PushBack(std::move(T(data)));
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

template <typename T, typename U>
requires Convertible<U, typename List<T>::value_type>
List<T> operator+(const U& data, const List<T> &list) {
    List<T> result(list);
    result.PushFront(T(data));
    return result;
}

template <typename T, typename U>
requires Convertible<U, typename List<T>::value_type>
List<T> operator+(U&& data, const List<T> &list) {
    List<T> result(list);
    result.PushFront(T(data));
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

#endif // LIST_H__
