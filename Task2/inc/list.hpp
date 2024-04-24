#ifndef LIST_HPP__
#define LIST_HPP__

#include <memory>
#include <iostream>
#include "list.h"


template <Comparable T>
List<T>::List() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <Comparable T>
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

template <Comparable T>
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

template <Comparable T>
List<T>::List(const List<T>& list) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = list.cbegin(); it!= list.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(T(*it), nullptr);
        pushBack(node);
    }
}

template <Comparable T>
List<T>::List(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}


template <Comparable T>
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

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T>::List(C &&container) {
    csize = 0;
    head = nullptr;
    tail = nullptr;
    for (auto it = container.begin(); it!= container.end(); ++it) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <Comparable T>
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

template <Comparable T>
List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    Clear();
    PushBack(list);
    return *this;
}

template <Comparable T>
List<T>& List<T>::operator=(List<T>&& list) noexcept {
    head = list.head;
    tail = list.tail;
    csize = list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
    return *this;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator=(const C &container) {
    Clear();
    PushBack(container);
    return *this;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator=(C &&container) {
    Clear();
    PushBack(std::move(container));
    return *this;
}

template <Comparable T>
List<T>::~List() = default;

template <Comparable T>
void List<T>::checkEmpty(size_t line) const {
    if (IsEmpty()) {
        time_t now = time(nullptr);
        throw PopEmptyException(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <Comparable T>
void List<T>::checkForeignIterator(const ListIterator<T> &iterator, size_t line) {
    auto it = begin();
    for (; it != end() && it != iterator; ++it);
    if (it == end()) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}
template <Comparable T>
void List<T>::checkForeignIterator(const ConstListIterator<T> &iterator, size_t line) const {
    auto it = cbegin();
    for (; it != cend() && it != iterator; ++it);
    if (it == end()) {
        time_t now = time(nullptr);
        throw UseOfForeignIterator(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}


template <Comparable T>
void List<T>::checkListRange(const ListIterator<T> &begin, const ListIterator<T> &end, size_t line) {
    checkForeignIterator(begin, line);
    checkForeignIterator(end, line);
    auto it = this->begin();
    for (; it != end && it != begin; ++it);
    if (it == end) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <Comparable T>
void List<T>::checkListRange(const ConstListIterator<T> &begin, const ConstListIterator<T> &end, size_t line) const {
    checkForeignIterator(begin, line);
    checkForeignIterator(end, line);
    auto it = this->cbegin();
    for (; it != end && it != begin; ++it);
    if (it == end) {
        time_t now = time(nullptr);
        throw InvalidListRange(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <Comparable T>
void List<T>::checkIndex(size_t index, size_t line) const {
    if (index >= size()) {
        time_t now = time(nullptr);
        throw IndexOutOfRangeException(ctime(&now), __FILE__, line, typeid(*this).name(), __FUNCTION__);
    }
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushBack(const U& data) {
    auto node = List<T>::ListNode::CreateNode(T(data), nullptr);
    pushBack(node);
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushBack(U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushBack(node);
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushBack(const C& container) {
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushBack(C &&container) {
    for (auto it = container.cbegin(); it!= container.cend(); it++) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        pushBack(node);
    }
}

template <Comparable T>
void List<T>::PushBack(List<T>&& list) noexcept {
    tail->SetNext(list.head);
    tail = list.tail;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator+=(const C& container) {
    PushBack(container);
    return *this;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> &List<T>::operator+=(C&& container) {
    PushBack(std::forward<C>(container));
    return *this;
}


template <Comparable T>
List<T> &List<T>::operator+=(List<T>&& list) noexcept {
    PushBack(std::forward<List<T>>(list));
    return *this;
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator+=(const U &data) {
    PushBack(T(data));
    return *this;
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> &List<T>::operator+=(U &&data) {
    PushBack(std::forward<T>(T(data)));
    return *this;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::operator+(const C& container) const {
    List<T> result(*this);
    result.PushBack(container);
    return result;
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
List<T> List<T>::operator+(C &&container) const {
    List<T> result(*this);
    result.PushBack(std::forward<C>(container));
    return result;
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::operator+(const U &data) const {
    List<T> result(*this);
    result.PushBack(T(data));
    return result;
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
List<T> List<T>::operator+(U &&data) const {
    List<T> result(*this);
    result.PushBack(std::forward<T>(T(data)));
    return result;
}

template <Comparable T>
List<T> List<T>::operator+(List<T>&& list) const {
    List<T> result(*this);
    result.PushBack(std::forward<List<T>>(list));
    list.head = nullptr;
    list.csize = 0;
    return result;
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushFront(const U& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushFront(node);
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::PushFront(U&& data) {
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    pushFront(node);
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushFront(const C& container) {
    List<T> newList(container);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::PushFront(C &&container) {
    List<T> newList(container);
    newList.PushBack(std::move(*this));
    *this = std::move(newList);
}

template <Comparable T>
void List<T>::PushFront(List<T>&& list) noexcept {
    list.tail->SetNext(head);
    head = list.head;
    csize += list.csize;
    list.head = nullptr;
    list.tail = nullptr;
    list.csize = 0;
}

template <Comparable T>
T List<T>::PopFront() {
    return *popFront()->GetData();
}

template <Comparable T>
T List<T>::PopBack() {
    return *popBack()->GetData();
}


template <Comparable T>
void List<T>::Remove(size_t index) {
    pop(index);
}

template <Comparable T>
void List<T>::Remove(const ListIterator<T> &it) {
   pop(it);
}

template <Comparable T>
void List<T>::Remove(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    checkListRange(begin, end, __LINE__);
    pop(begin, end);
}

template <Comparable T>
void List<T>::Remove(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    checkForeignIterator(begin, __LINE__);
    if (count == 0) {
        return;
    }
    
    auto it = this->begin();
    size_t i = 0;
    for (; it != begin; ++it, ++i);
    checkIndex(i + count - 1, __LINE__);

    for (size_t i = 0; i < count - 1; ++it, ++i);
    pop(begin, it);
}

template <Comparable T>
void List<T>::Remove(size_t index, size_t count) {
    checkEmpty(__LINE__);
    checkIndex(index, __LINE__);
    checkIndex(index + count - 1, __LINE__);
    if (count == 0) {
        return;
    }
    auto it = this->begin();
    for (size_t i = 0; i < index; ++it, ++i);
    auto begin = it;
    for (size_t i = 0; i < count - 1; ++it, ++i);
    pop(begin, it);
}

template <Comparable T>
T List<T>::Pop(size_t index) {
    return *pop(index)->GetData();
}

template <Comparable T>
T List<T>::Pop(const ListIterator<T> &it) {
    return *pop(it)->GetData();
}

template <Comparable T>
List<T> List<T>::Pop(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    checkListRange(begin, end, __LINE__);
    return pop(begin, end);
}

template <Comparable T>
List<T> List<T>::Pop(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    checkForeignIterator(begin, __LINE__);
    if (count == 0) {
        return List<T>();
    }
    
    auto it = this->begin();
    size_t i = 0;
    for (; it != begin; ++it, ++i);
    checkIndex(i + count - 1, __LINE__);

    for (size_t i = 0; i < count - 1; ++it, ++i);
    return pop(begin, it);
}

template <Comparable T>
List<T> List<T>::Pop(size_t index, size_t count) {
    checkEmpty(__LINE__);
    checkIndex(index, __LINE__);
    checkIndex(index + count - 1, __LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->begin();
    for (size_t i = 0; i < index; ++it, ++i);
    auto begin = it;
    for (size_t i = 0; i < count - 1; ++it, ++i);
    return pop(begin, it);
}

template <Comparable T>
List<T> List<T>::SubList(const ListIterator<T> &begin, const ListIterator<T> &end) {
    checkEmpty(__LINE__);
    checkListRange(begin, end, __LINE__);
    return subList(begin, end);
}

template <Comparable T>
List<T> List<T>::SubList(const ListIterator<T> &begin, size_t count) {
    checkEmpty(__LINE__);
    checkForeignIterator(begin, __LINE__);
    if (count == 0) {
        return List<T>();
    }
    
    auto it = this->begin();
    size_t i = 0;
    for (; it != begin; ++it, ++i);
    checkIndex(i + count - 1, __LINE__);

    for (size_t i = 0; i < count - 1; ++it, ++i);
    return subList(begin, it);
}

template <Comparable T>
List<T> List<T>::SubList(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const {
    checkEmpty(__LINE__);
    checkListRange(begin, end, __LINE__);
    return subList(begin, end);
}

template <Comparable T>
List<T> List<T>::SubList(const ConstListIterator<T> &begin, size_t count) const {
    checkEmpty(__LINE__);
    checkForeignIterator(begin, __LINE__);
    if (count == 0) {
        return List<T>();
    }
    
    auto it = this->cbegin();
    size_t i = 0;
    for (; it != begin; ++it, ++i);
    checkIndex(i + count - 1, __LINE__);

    for (size_t i = 0; i < count - 1; ++it, ++i);
    return subList(begin, it);
}


template <Comparable T>
List<T> List<T>::SubList(size_t index, size_t count) const {
    checkEmpty(__LINE__);
    checkIndex(index, __LINE__);
    checkIndex(index + count - 1, __LINE__);
    if (count == 0) {
        return List<T>();
    }
    auto it = this->cbegin();
    for (size_t i = 0; i < index; ++it, ++i);
    auto begin = it;
    for (size_t i = 0; i < count - 1; ++it, ++i);
    return subList(begin, it);
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(size_t index, const U& data) {
    if (index != size())
        checkIndex(index, __LINE__);
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(index, node);
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(size_t index, U&& data) {
    if (index != size())
        checkIndex(index, __LINE__);
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(index, node);
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(size_t index, const C& container) {
    if (index != size())
        checkIndex(index, __LINE__);

    if (index == 0)
    {
        PushFront(container);
        return;
    }
        
    auto iter = begin();
    for (size_t i = 0; i < index - 1; i++, ++iter);
    for (auto it = container.begin(); it != container.end(); ++it, ++iter) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        insert(iter, node);
    }
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(size_t index, C&& container) {
    if (index != size())
        checkIndex(index, __LINE__);

    if (index == 0)
    {   
        PushFront(container);
        return;
    }
        
    auto iter = begin();
    for (size_t i = 0; i < index - 1; i++, iter++);
    for (auto it = container.begin(); it != container.end(); ++it, ++iter) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*it)), nullptr);
        insert(iter, node);
    }
}

template <Comparable T>
void List<T>::Insert(size_t index, List<T>&& list) {
    if (index != size())
        checkIndex(index, __LINE__);
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

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(const ListIterator<T> &it, const U& data) {
    checkForeignIterator(it, __LINE__);
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(it, node);
}

template <Comparable T>
template <Convertible<typename List<T>::value_type> U>
void List<T>::Insert(const ListIterator<T> &it, U&& data) {
    checkForeignIterator(it, __LINE__);
    auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(data)), nullptr);
    insert(it, node);
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(const ListIterator<T> &it, const C& container) {
    checkForeignIterator(it, __LINE__);
    auto cit = it;
    for (auto iter = container.begin(); iter != container.end(); ++iter, ++cit) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*iter)), nullptr);
        insert(cit, node);
    }
}

template <Comparable T>
template <ConvertibleContainer<typename List<T>::value_type> C>
void List<T>::Insert(const ListIterator<T> &it, C&& container) {
    checkForeignIterator(it, __LINE__);
    auto cit = it;
    for (auto iter = container.begin(); iter != container.end(); ++iter, ++cit) {
        auto node = List<T>::ListNode::CreateNode(std::forward<T>(T(*iter)), nullptr);
        insert(cit, node);
    }
}

template <Comparable T>
void List<T>::Insert(const ListIterator<T> &it, List<T>&& list) {
    checkForeignIterator(it, __LINE__);
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

template <Comparable T>
void List<T>::Clear() noexcept {
    head = nullptr;
    tail = nullptr;
    csize = 0;
}

template <Comparable T>
void List<T>::Reverse() noexcept {
    List<T> newList;
    while (csize > 0) {
        auto node = popFront();
        newList.pushFront(node);
    }
    *this = std::move(newList);
}

template <Comparable T>
bool List<T>::IsEmpty() const noexcept {
    return csize == 0;
}

template <Comparable T>
size_t List<T>::GetSize() const noexcept {
    return csize;
}

template <Comparable T>
List<T>::size_type List<T>::size() const noexcept {
    return csize;
}

template <Comparable T>
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

template <Comparable T>
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

template <Comparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::popFront(void)  {
    csize--;
    auto node = head;
    head = head->GetNext();
    if (head == nullptr) {
        tail = nullptr;
    }
    return node;
}

template <Comparable T>
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

template <Comparable T>
const std::shared_ptr<typename List<T>::ListNode> List<T>::get(size_t index) const  {
    auto it = cbegin();
    for (size_t i = 0; i < index && it!= cend(); i++, it++);
    return it.getNode();
}

template <Comparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::get(size_t index)  {
    auto it = begin();
    for (size_t i = 0; i < index && it != end(); i++, it++);
    return it.getNode();
}

template <Comparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::pop(size_t index)  {
    if (index == 0) {
        return popFront();
    }
    if (index == size() - 1) {
        return popBack();
    }
    auto it = begin();
    for (size_t i = 0; i < index - 1 && it!= end(); i++, ++it);
    csize--;
    auto node = it.getNode()->GetNext();
    it.getNode()->SetNext(it.getNode()->GetNext()->GetNext());
    return node;
}



template <Comparable T>
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

template <Comparable T>
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

template <Comparable T>
List<T> List<T>::subList(const ListIterator<T>& begin, const ListIterator<T>& end) {
    return List<T>(begin, end + 1);
}

template <Comparable T>
List<T> List<T>::subList(const ConstListIterator<T>& begin, const ConstListIterator<T>& end) const {
    return List<T>(begin, end + 1);
}

template <Comparable T>
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

template <Comparable T>
void List<T>::insert(size_t index, std::shared_ptr<List<T>::ListNode> &node)  {
    if (index == size()) {
        pushBack(node);
        return;
    }
    if (index == 0) {
        pushFront(node);
        return;
    }
    auto nodeIt = get(index - 1);
    node->SetNext(nodeIt->GetNext());
    nodeIt->SetNext(node);
    csize++;
}

template <Comparable T>
ListIterator<T> List<T>::begin() noexcept {
    return ListIterator<T>(head);
}


template <Comparable T>
ListIterator<T> List<T>::end() noexcept {
    if (head == nullptr) {
        return ListIterator<T>(nullptr);
    }
    return ListIterator<T>(tail) + 1;
}

template <Comparable T>
ConstListIterator<T> List<T>::begin() const noexcept {
    return ConstListIterator<T>(head);
}


template <Comparable T>
ConstListIterator<T> List<T>::end() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}

template <Comparable T>
ConstListIterator<T> List<T>::cbegin() const noexcept {
    return ConstListIterator<T>(head);
}

template <Comparable T>
ConstListIterator<T> List<T>::cend() const noexcept {
    if (head == nullptr) {
        return ConstListIterator<T>(nullptr);
    }
    return ConstListIterator<T>(tail) + 1;
}

template <Comparable T>
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

template <Comparable T>
bool List<T>::operator==(const List<T> &list) const  {
    return cmpList(list) == 0;
}

template <Comparable T>
bool List<T>::operator!=(const List<T> &list) const  {
    return cmpList(list)!= 0;
}

template <Comparable T>
bool List<T>::operator<(const List<T> &list) const  {
    return cmpList(list) < 0;
}

template <Comparable T>
bool List<T>::operator>(const List<T> &list) const  {
    return cmpList(list) > 0;
}

template <Comparable T>
bool List<T>::operator<=(const List<T> &list) const  {
    return cmpList(list) <= 0;
}

template <Comparable T>
bool List<T>::operator>=(const List<T> &list) const  {
    return cmpList(list) >= 0;
}

template <Comparable T>
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
