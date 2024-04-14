#ifndef CONSTLISTITERATOR_H__
#define CONSTLISTITERATOR_H__

#include <iterator>
#include <memory>
#include "listnode.h"

template <typename T>
class ConstListIterator : public std::iterator<std::output_iterator_tag, T>
{
    public:
        ConstListIterator();
        ConstListIterator(const ConstListIterator<T>& other);
        ConstListIterator(const std::shared_ptr<ListNode<T>>& node);

        ~ConstListIterator() = default;


        bool operator==(const ConstListIterator<T>& other) const;
        bool operator!=(const ConstListIterator<T>& other) const;

        const T &operator*() const;
        const T *operator->() const;

        ConstListIterator<T> &operator++();
        ConstListIterator<T> operator++(int);
        ConstListIterator<T> &operator+=(int steps);
        ConstListIterator<T> operator+(int steps);
        ConstListIterator<T> operator=(const ConstListIterator<T> &other);
    private:
        std::weak_ptr<ListNode<T>> wptr;

};
#endif // CONSTLISTITERATOR_H__
