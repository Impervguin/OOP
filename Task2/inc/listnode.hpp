#ifndef LISTNODE_HPP__
#define LISTNODE_HPP__

#include <listnode.h>

template <typename  T>
ListNode<T>::ListNode() {
    this->next = nullptr;
}

template <typename  T>
ListNode<T>::ListNode(const T &data) {
    this->data = data;
    this->next = nullptr;
}

template <typename  T>
ListNode<T>::ListNode(const T &data, const std::shared_ptr<ListNode<T>> &next) {
    this->data = data;
    this->next = next;
}
template <typename  T>
ListNode<T>::ListNode(const T &data, const ListNode<T> &next) {
    std::shared_ptr<ListNode<T>> temp = std::make_shared<ListNode<T>>(next);
    this->data = data;
    this->next = temp;
}

template <typename  T>
ListNode<T>::ListNode(const std::shared_ptr<ListNode<T>> &node) {
    this->data = node->data;
    this->next = node->next;
}

template <typename  T>
ListNode<T>::ListNode(const ListNode<T> &node) {
    this->data = node.data;
    this->next = node.next;
}

template <typename  T>
void ListNode<T>::SetData(const T &data) {
    this->data = data;
}

template <typename  T>
void ListNode<T>::SetNext(const std::shared_ptr<ListNode<T>> &node) {
    this->next = node;
}

template <typename  T>
void ListNode<T>::SetNextNull() {
    this->next = nullptr;
}   

template <typename  T>
void ListNode<T>::SetNext(const ListNode<T> &node) {
    std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(node);
    this->next = tmp;
}

template <typename  T>
T &ListNode<T>::GetData() {
    return this->data;
}

template <typename  T>
std::shared_ptr<ListNode<T>> ListNode<T>::GetNext() const {
    return this->next;
}

#endif // LISTNODE_HPP__
