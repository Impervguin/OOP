#pragma once
#include "basetreeiterator.h"
#include "treeiterator.h"
#include "concepts.h"
#include <memory>
#include <iterator>
#include <stack>

template <AssignCopyComparable T>
class BSTree;

template <AssignCopyComparable T>
class ConstTreeIterator : public BaseTreeIterator<T> {
    friend class BSTree<T>;
    using nodeTree = typename BSTree<T>::TreeNode;

    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = size_t;
    using pointer = const std::shared_ptr<value_type>;
    using reference = const value_type&;

    // Конструкторы
    public:
        ConstTreeIterator() = delete;
        ConstTreeIterator(const TreeIterator<T>& other) noexcept;
        ConstTreeIterator(TreeIterator<T>&& other) noexcept;
        ConstTreeIterator &operator=(const TreeIterator<T>& other) noexcept;
        ConstTreeIterator(const TreeIterator<T>&& other) noexcept;


        ConstTreeIterator(const ConstTreeIterator<T>& other) noexcept;
        ConstTreeIterator(ConstTreeIterator<T>&& other) noexcept;
        ConstTreeIterator &operator=(const ConstTreeIterator<T>& other) noexcept;
        ConstTreeIterator(const ConstTreeIterator<T>&& other) noexcept;
        
        virtual ~ConstTreeIterator() noexcept = default;
    protected:
        ConstTreeIterator(std::shared_ptr<nodeTree> root) noexcept;
        ConstTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept;
    
    public:

        // Разыменование
        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;


        // Перемещение
        ConstTreeIterator<T> &operator++();
        ConstTreeIterator<T> operator++(int);

        template <IncrementableandComparable U>
        ConstTreeIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        ConstTreeIterator<T> operator+(U steps);
        template <IncrementableandComparable U>
        const ConstTreeIterator<T> operator+(U steps) const;

        ConstTreeIterator<T> &operator--();
        ConstTreeIterator<T> operator--(int);

        template <IncrementableandComparable U>
        ConstTreeIterator<T> &operator-=(U steps);
        template <IncrementableandComparable U>
        ConstTreeIterator<T> operator-(U steps);
        template <IncrementableandComparable U>
        const ConstTreeIterator<T> operator-(U steps) const;
};


#include "consttreeiterator.hpp"