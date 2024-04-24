#ifndef BASELISTITERATOR_H__
#define BASELISTITERATOR_H__

#include <cstdlib>
#include <iterator>
#include <memory>
#include "listconcepts.h"

template <AssignCopyComparable T>
class List;

template <AssignCopyComparable T>
class BaseListIterator {
    public:
        virtual ~BaseListIterator() = 0;
        bool IsValid() const noexcept;
        operator bool() const noexcept;

        bool operator==(const BaseListIterator<T>& other) const noexcept;
        bool operator!=(const BaseListIterator<T>& other) const noexcept;

        friend class List<T>;
    protected:
        void checkValid(size_t line) const;
        std::shared_ptr<typename List<T>::ListNode> getNode() const;
        std::weak_ptr<typename List<T>::ListNode> wptr;
};

#endif // BASELISTITERATOR_H__
