#ifndef CONSTLISTITERATOR_H__
#define CONSTLISTITERATOR_H__

#include <cstdlib>
#include <iterator>
#include <memory>
#include "listnode.h"

template <typename T>
class List;

template <typename T>
class ConstListIterator : public std::iterator<std::output_iterator_tag, T>
{
    public:
        ConstListIterator();
        ConstListIterator(const ConstListIterator<T>& other);
        ConstListIterator(const std::shared_ptr<ListNode<T>>& node);

        ~ConstListIterator() = default;

        bool IsValid() const;
        bool operator==(const ConstListIterator<T>& other) const;
        bool operator!=(const ConstListIterator<T>& other) const;

        const T &operator*() const;
        const T *operator->() const;

        ConstListIterator<T> &operator++();
        ConstListIterator<T> operator++(int);
        ConstListIterator<T> &operator+=(int steps);
        ConstListIterator<T> operator+(int steps);
        ConstListIterator<T> operator=(const ConstListIterator<T> &other);

        friend class List<T>;
    private:
        std::weak_ptr<ListNode<T>> wptr;
        void checkValid(size_t line) const;
        std::shared_ptr<ListNode<T>> getNode() const;

};
#endif // CONSTLISTITERATOR_H__
