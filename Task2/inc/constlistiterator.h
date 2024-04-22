#ifndef CONSTLISTITERATOR_H__
#define CONSTLISTITERATOR_H__


#include <cstdlib>
#include <iterator>
#include <memory>
#include "listconcepts.h"

template <Comparable T>
class List;

template <Comparable T> 
class ConstListIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const std::shared_ptr<T>;
        using reference = const T&;

        // Конструкторы
        ConstListIterator(const ConstListIterator<T>& other) noexcept;
        ConstListIterator(ConstListIterator<T>&& other) noexcept;
        ConstListIterator<T> &operator=(const ConstListIterator<T>& other) noexcept;
        ConstListIterator<T> &operator=(ConstListIterator<T>&& other) noexcept;
    protected:
        ConstListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept;
    public:
        ~ConstListIterator() = default;

        // bool'ы
        bool IsValid() const;
        operator bool() const;

        bool operator==(const ConstListIterator<T>& other) const;
        bool operator!=(const ConstListIterator<T>& other) const;

        // Разыменование
        reference operator*() const;
        pointer operator->() const;

        // Перемещение
        ConstListIterator<T> &operator++();
        ConstListIterator<T> operator++(int);
        template <IncrementableandComparable U>
        ConstListIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        ConstListIterator<T> operator+(U steps);

        friend class List<T>;
    private:
        void checkValid(size_t line) const;
        const std::shared_ptr<typename List<T>::ListNode> getNode() const;

        std::weak_ptr<typename List<T>::ListNode> wptr;

};
#endif // CONSTLISTITERATOR_H__
