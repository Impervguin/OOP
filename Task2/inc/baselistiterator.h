#ifndef BASELISTITERATOR_H__
#define BASELISTITERATOR_H__

#include <cstdlib>
#include <iterator>
#include <memory>
#include "listconcepts.h"

template <Comparable T>
class List;

template <Comparable T>
class BaseListIterator {
    public:
        virtual ~BaseListIterator() = default;

        bool IsValid() const;
        operator bool() const;

        bool operator==(const BaseListIterator<T>& other) const;
        bool operator!=(const BaseListIterator<T>& other) const;

        friend class List<T>;
    protected:
        void checkValid(size_t line) const;
        std::shared_ptr<typename List<T>::ListNode> getNode() const;
        std::weak_ptr<typename List<T>::ListNode> wptr;
};

#endif // BASELISTITERATOR_H__