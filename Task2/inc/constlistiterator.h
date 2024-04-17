#ifndef CONSTLISTITERATOR_H__
#define CONSTLISTITERATOR_H__

#include <cstdlib>
#include <iterator>
#include <memory>
#include <concepts>

#include "listnode.h"

template <typename T>
class List;

template <typename T>
class ConstListIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        ConstListIterator(const ConstListIterator<T>& other) noexcept;
        
        ~ConstListIterator() = default;

        bool IsValid() const;
        bool operator==(const ConstListIterator<T>& other) const;
        bool operator!=(const ConstListIterator<T>& other) const;

        reference operator*() const;
        pointer operator->() const;

        ConstListIterator<T> &operator++();
        ConstListIterator<T> operator++(int);
        ConstListIterator<T> &operator+=(int steps);
        ConstListIterator<T> operator+(int steps);
        ConstListIterator<T> operator=(const ConstListIterator<T> &other);

        friend class List<T>;
    private:
        void checkValid(size_t line) const;
        const std::shared_ptr<ListNode<T>> getNode() const;
        ConstListIterator(const std::shared_ptr<ListNode<T>>& node) noexcept;

        std::weak_ptr<ListNode<T>> wptr;

};
#endif // CONSTLISTITERATOR_H__
