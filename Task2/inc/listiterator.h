#ifndef LISTITERATOR_H__
#define LISTITERATOR_H__

#include <cstdlib>
#include <iterator>
#include <memory.h>
#include "listnode.h"

template <typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T>
{
    public:
        ListIterator();
        ListIterator(const ListIterator<T>& other);
        ListIterator(const std::shared_ptr<ListNode<T>>& node);

        ~ListIterator() = default;

        bool IsValid() const;
        bool operator==(const ListIterator<T>& other) const;
        bool operator!=(const ListIterator<T>& other) const;

        T &operator*();
        const T &operator*() const;
        T *operator->();
        const T *operator->() const;

        ListIterator<T> &operator++();
        ListIterator<T> operator++(int);
        ListIterator<T> &operator+=(int steps);
        ListIterator<T> operator+(int steps) const;
        ListIterator<T> operator=(const ListIterator<T>& other);
    private:
        void checkValid(size_t line) const;
        std::weak_ptr<ListNode<T>> wptr;
};

#endif // LISTITERATOR_H__
