#pragma once
#include "tree.h"


template <AssignCopyComparable T>
template <typename... Args>
std::shared_ptr<typename BSTree<T>::TreeNode> BSTree<T>::TreeNode::CreateNode(Args&&... params) {
    struct tmp : BSTree<T>::TreeNode
    {
        tmp(Args&&... params) : BSTree<T>::TreeNode(std::forward<Args>(params)...) {};
    };
    return std::make_shared<tmp>(std::forward<Args>(params)...);
}

template <AssignCopyComparable T>
BSTree<T>::TreeNode::TreeNode(const T &data, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right)
: _data(data), _left(left), _right(right) {};

template <AssignCopyComparable T>
BSTree<T>::TreeNode::TreeNode(T &&data, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right)
: _data(data), _left(left), _right(right) {};

template <AssignCopyComparable T>
BSTree<T>::TreeNode::TreeNode(const T &data)
: _data(data), _left(nullptr), _right(nullptr) {};

template <AssignCopyComparable T>
BSTree<T>::TreeNode::TreeNode(T &&data)
: _data(data), _left(nullptr), _right(nullptr) {};

template <AssignCopyComparable T>
void BSTree<T>::TreeNode::SetLeft(const std::shared_ptr<TreeNode> node) {
    _left = node;
}
template <AssignCopyComparable T>
void BSTree<T>::TreeNode::SetRight(const std::shared_ptr<TreeNode> node) {
    _right = node;
}

template <AssignCopyComparable T>
void BSTree<T>::TreeNode::SetData(const T &data) {
    _data = data;
}

template <AssignCopyComparable T>
void BSTree<T>::TreeNode::SetLeftNull() {
    _left = nullptr;
}

template <AssignCopyComparable T>
void BSTree<T>::TreeNode::SetRightNull() {
    _right = nullptr;
}

template <AssignCopyComparable T>
std::shared_ptr<typename BSTree<T>::TreeNode> BSTree<T>::TreeNode::GetLeft() {
    return _left;
}

template <AssignCopyComparable T>
std::shared_ptr<typename BSTree<T>::TreeNode> BSTree<T>::TreeNode::GetRight() {
    return _right;
}

template <AssignCopyComparable T>
std::shared_ptr<T> BSTree<T>::TreeNode::GetData() {
    auto tmp_ptr = this->shared_from_this();

    return {tmp_ptr, &tmp_ptr->_data}; 
}