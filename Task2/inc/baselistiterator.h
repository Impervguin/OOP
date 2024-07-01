#pragma once

#include <cstdlib>
#include <iterator>
#include <memory>
#include "concepts.h"
#include "exceptions.h"

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
        std::shared_ptr<typename List<T>::ListNode> getNode() const;
        std::weak_ptr<typename List<T>::ListNode> wptr;
};

#endif // BASELISTITERATOR_H__
