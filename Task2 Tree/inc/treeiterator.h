#pragma once
#include "basetreeiterator.h"
#include "concepts.h"
#include <memory>
#include <iterator>
#include <stack>

template <AssignCopyComparable T>
class BSTree;

template <AssignCopyComparable T>
class ConstTreeIterator;

template <AssignCopyComparable T>
class TreeIterator : public BaseTreeIterator<T> {
    friend class BSTree<T>;
    friend class ConstTreeIterator<T>;

    using nodeTree = typename BSTree<T>::TreeNode;

    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = size_t;
    using pointer = std::shared_ptr<value_type>;
    using reference = value_type&;

    // Конструкторы
    public:
        TreeIterator() = delete;
        TreeIterator(const TreeIterator<T>& other) noexcept;
        TreeIterator(TreeIterator<T>&& other) noexcept;
        TreeIterator &operator=(const TreeIterator<T>& other) noexcept;
        TreeIterator(const TreeIterator<T>&& other) noexcept;
        virtual ~TreeIterator() noexcept = default;
    protected:
        TreeIterator(std::shared_ptr<nodeTree> root) noexcept;
        TreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept;
    
    public:

        // Разыменование
        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;


        // Перемещение
        TreeIterator<T> &operator++();
        TreeIterator<T> operator++(int);

        template <IncrementableandComparable U>
        TreeIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        TreeIterator<T> operator+(U steps);
        template <IncrementableandComparable U>
        const TreeIterator<T> operator+(U steps) const;

        TreeIterator<T> &operator--();
        TreeIterator<T> operator--(int);

        template <IncrementableandComparable U>
        TreeIterator<T> &operator-=(U steps);
        template <IncrementableandComparable U>
        TreeIterator<T> operator-(U steps);
        template <IncrementableandComparable U>
        const TreeIterator<T> operator-(U steps) const;
};


#include "treeiterator.hpp"