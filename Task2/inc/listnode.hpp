#ifndef LISTNODE_HPP__
#define LISTNODE_HPP__

#include "list.h"

template <AssignCopyComparable T>
List<T>::ListNode::ListNode(const T &data, const std::shared_ptr<List<T>::ListNode> &next) : next(next), data(data) {}

template <AssignCopyComparable T>
void List<T>::ListNode::SetData(const T &data) {
    this->data = data;
}

template <AssignCopyComparable T>
void List<T>::ListNode::SetNext(const std::shared_ptr<List<T>::ListNode> &node) {
    next = node;
}

template <AssignCopyComparable T>
void List<T>::ListNode::SetNextNull() {
    next = nullptr;
}

template <AssignCopyComparable T>
template <typename... Args>
std::shared_ptr<typename List<T>::ListNode> List<T>::ListNode::CreateNode(Args&&... params) {
    struct tmp : List<T>::ListNode
    {
        tmp(Args&&... params) : List<T>::ListNode(std::forward<Args>(params)...) {};
    };
    return std::make_shared<tmp>(std::forward<Args>(params)...);
}


template <AssignCopyComparable T>
std::shared_ptr<T> List<T>::ListNode::GetData() {
    auto tmp_ptr = this->shared_from_this();

    return {tmp_ptr, &tmp_ptr->data}; 
}

template <AssignCopyComparable T>
std::shared_ptr<typename List<T>::ListNode> List<T>::ListNode::GetNext() {
    return next;
}


#endif // LISTNODE_HPP__
