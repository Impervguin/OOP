#pragma once
#include "basetreeiterator.h"
// #include "reversetreeiterator.h"
#include "concepts.h"
#include <memory>
#include <iterator>
#include <stack>

template <AssignCopyComparable T>
class BSTree;

template <AssignCopyComparable T>
class ConstReverseTreeIterator : public BaseTreeIterator<T> {
    friend class BSTree<T>;

    using nodeTree = typename BSTree<T>::TreeNode;

    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = size_t;
    using pointer = const std::shared_ptr<value_type>;
    using reference = const value_type&;

    // Конструкторы
    public:
        ConstReverseTreeIterator() = delete;

        ConstReverseTreeIterator(const ConstReverseTreeIterator<T>& other) noexcept;
        ConstReverseTreeIterator(ConstReverseTreeIterator<T>&& other) noexcept;
        ConstReverseTreeIterator &operator=(const ConstReverseTreeIterator<T>& other) noexcept;
        ConstReverseTreeIterator(const ConstReverseTreeIterator<T>&& other) noexcept;
        virtual ~ConstReverseTreeIterator() noexcept = default;
    protected:
        ConstReverseTreeIterator(std::shared_ptr<nodeTree> root) noexcept;
        ConstReverseTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept;
    
    public:

        // Разыменование
        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;


        // Перемещение
        ConstReverseTreeIterator<T> &operator++();
        ConstReverseTreeIterator<T> operator++(int);

        template <IncrementableandComparable U>
        ConstReverseTreeIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        ConstReverseTreeIterator<T> operator+(U steps);
        template <IncrementableandComparable U>
        const ConstReverseTreeIterator<T> operator+(U steps) const;

        ConstReverseTreeIterator<T> &operator--();
        ConstReverseTreeIterator<T> operator--(int);

        template <IncrementableandComparable U>
        ConstReverseTreeIterator<T> &operator-=(U steps);
        template <IncrementableandComparable U>
        ConstReverseTreeIterator<T> operator-(U steps);
        template <IncrementableandComparable U>
        const ConstReverseTreeIterator<T> operator-(U steps) const;
};


#include "constreversetreeiterator.hpp"