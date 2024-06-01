#pragma once
#include "concepts.h"
#include <memory>
#include <stack>

template <AssignCopyComparable T>
class BSTree;

template <AssignCopyComparable T>
class BaseTreeIterator {
    friend class BSTree<T>;
    using nodeTree = typename BSTree<T>::TreeNode;

    public:
        BaseTreeIterator() = delete;
        virtual ~BaseTreeIterator() = 0;
    
    protected:
        BaseTreeIterator(std::shared_ptr<nodeTree> root) noexcept;
        BaseTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept;
        BaseTreeIterator(std::weak_ptr<nodeTree> root, std::weak_ptr<nodeTree> current, size_t index) noexcept;
    
    public:
        operator bool() const noexcept;
        bool operator<=>(const BaseTreeIterator<T>& other) const noexcept;


    protected:
        std::weak_ptr<nodeTree> _root;
        std::weak_ptr<nodeTree> _current;
        size_t _index;
        std::stack<std::weak_ptr<nodeTree>> _stackNext;
        std::stack<std::weak_ptr<nodeTree>> _stackPrev;
};

#include "basetreeiterator.hpp"