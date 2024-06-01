#pragma once
#include "basetreeiterator.h"
#include "concepts.h"
#include <memory>
#include <iterator>
#include <stack>

template <AssignCopyComparable T>
class BSTree;

template <AssignCopyComparable T>
class ConstReverseTreeIterator;

template <AssignCopyComparable T>
class ReverseTreeIterator : public BaseTreeIterator<T> {
    friend class BSTree<T>;
    friend class ConstReverseTreeIterator<T>;

    using nodeTree = typename BSTree<T>::TreeNode;

    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = size_t;
    using pointer = std::shared_ptr<value_type>;
    using reference = value_type&;

    // Конструкторы
    public:
        ReverseTreeIterator() = delete;
        ReverseTreeIterator(const ReverseTreeIterator<T>& other) noexcept;
        ReverseTreeIterator(ReverseTreeIterator<T>&& other) noexcept;
        ReverseTreeIterator &operator=(const ReverseTreeIterator<T>& other) noexcept;
        ReverseTreeIterator(const ReverseTreeIterator<T>&& other) noexcept;
        virtual ~ReverseTreeIterator() noexcept = default;
    protected:
        ReverseTreeIterator(std::shared_ptr<nodeTree> root) noexcept;
        ReverseTreeIterator(std::shared_ptr<nodeTree> root, std::shared_ptr<nodeTree> current, size_t index) noexcept;
    
    public:

        // Разыменование
        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;


        // Перемещение
        ReverseTreeIterator<T> &operator++();
        ReverseTreeIterator<T> operator++(int);

        template <IncrementableandComparable U>
        ReverseTreeIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        ReverseTreeIterator<T> operator+(U steps);
        template <IncrementableandComparable U>
        const ReverseTreeIterator<T> operator+(U steps) const;

        ReverseTreeIterator<T> &operator--();
        ReverseTreeIterator<T> operator--(int);

        template <IncrementableandComparable U>
        ReverseTreeIterator<T> &operator-=(U steps);
        template <IncrementableandComparable U>
        ReverseTreeIterator<T> operator-(U steps);
        template <IncrementableandComparable U>
        const ReverseTreeIterator<T> operator-(U steps) const;
};


#include "reversetreeiterator.hpp"