#ifndef LISTITERATOR_H__
#define LISTITERATOR_H__


#include <cstdlib>
#include <iterator>
#include <memory>
#include "listconcepts.h"

template <typename T>
class List;

template <typename T>
class ListIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        ListIterator(const ListIterator<T>& other);

        ~ListIterator() = default;

        bool IsValid() const;
        bool operatorbool() const;
        bool operator==(const ListIterator<T>& other) const;
        bool operator!=(const ListIterator<T>& other) const;

        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;

        ListIterator<T> &operator++();
        ListIterator<T> operator++(int);
        ListIterator<T> &operator+=(int steps);
        ListIterator<T> operator+(int steps) const;
        ListIterator<T> operator=(const ListIterator<T>& other);

        friend class List<T>;
    private:
        void checkValid(size_t line) const;
        std::shared_ptr<typename List<T>::ListNode> getNode() const;
        ListIterator(const std::shared_ptr<typename List<T>::ListNode>& node);
        
        std::weak_ptr<typename List<T>::ListNode> wptr;
        
};

#endif // LISTITERATOR_H__
