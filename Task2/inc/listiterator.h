#ifndef LISTITERATOR_H__
#define LISTITERATOR_H__


#include <cstdlib>
#include <iterator>
#include <memory>
#include "listconcepts.h"

template <Comparable T>
class List;

template <Comparable T>
class ListIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = std::shared_ptr<T>;
        using reference = T&;

        // Конструкторы
        ListIterator(const ListIterator<T>& other) noexcept;
        ListIterator(ListIterator<T>&& other) noexcept;
        ListIterator<T> &operator=(const ListIterator<T>& other) noexcept;
        ListIterator<T> &operator=(ListIterator<T>&& other) noexcept;
        
    protected:
        ListIterator(const std::shared_ptr<typename List<T>::ListNode>& node) noexcept;
    
    public:
        ~ListIterator() = default;

        // bool'ы
        bool IsValid() const;
        operator bool() const;

        bool operator==(const ListIterator<T>& other) const;
        bool operator!=(const ListIterator<T>& other) const;

        // Разыменование
        reference operator*();
        const reference operator*() const;
        pointer operator->();
        const pointer operator->() const;


        // Перемещение
        ListIterator<T> &operator++();
        ListIterator<T> operator++(int);

        template <IncrementableandComparable U>
        ListIterator<T> &operator+=(U steps);
        template <IncrementableandComparable U>
        ListIterator<T> operator+(U steps);
        template <IncrementableandComparable U>
        const ListIterator<T> operator+(U steps) const;
        

        friend class List<T>;
    protected:
        void checkValid(size_t line) const;
        std::shared_ptr<typename List<T>::ListNode> getNode() const;

        std::weak_ptr<typename List<T>::ListNode> wptr;
        
};

#endif // LISTITERATOR_H__
