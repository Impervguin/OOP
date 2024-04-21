#ifndef LISTNODE_HPP__
#define LISTNODE_HPP__

#include "list.h"

template <typename  T>
List<T>::ListNode::ListNode(const T &data) {
    this->data = data;
    this->next = nullptr;
}

template <typename  T>
List<T>::ListNode::ListNode(T &&data) {
    this->data = data;
}

template <typename  T>
List<T>::ListNode::ListNode(const T &data, const std::shared_ptr<List<T>::ListNode> &next) {
    this->data = data;
    this->next = next;
}

template <typename  T>
List<T>::ListNode::ListNode(const List<T>::ListNode &node) {
    this->data = node.data;
    this->next = node.next;
}

template <typename  T>
void List<T>::ListNode::SetData(const T &data) {
    this->data = data;
}

template <typename  T>
void List<T>::ListNode::SetNext(const std::shared_ptr<List<T>::ListNode> &node) {
    this->next = node;
}

template <typename  T>
void List<T>::ListNode::SetNextNull() {
    this->next = nullptr;
}   

template <typename  T>
T &List<T>::ListNode::GetData() {
    return this->data;
}

template <typename  T>
std::shared_ptr<typename List<T>::ListNode> List<T>::ListNode::GetNext() const {
    return this->next;
}

#endif // LISTNODE_HPP__
