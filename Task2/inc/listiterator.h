#ifndef LISTITERATOR_H__
#define LISTITERATOR_H__

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


        bool operator==(const ListIterator<T>& other) const;
        bool operator!=(const ListIterator<T>& other) const;

        T &operator*();
        const T &operator*() const;
        T *operator->();
        const T *operator->() const;

        ListIterator<T> &operator++();
        ListIterator<T> operator++(int);
    private:
        std::weak_ptr<ListNode<T>> wptr;
};

#endif // LISTITERATOR_H__
