#ifndef LIST_H__
#define LIST_H__

#include "listnode.h"
#include "listiterator.h"
#include "constlistiterator.h"
#include "listconcepts.h"
#include <iostream>


template <typename T>
class List {  
    public:
        using value_type = T;
        using iterator = ListIterator<T>;
        using const_iterator = ConstListIterator<T>;
        using size_type = size_t;

        List() noexcept;
        explicit List(const List<T>& list) noexcept;
        List(List<T> &&list) noexcept;
        List(size_t size, const T& data) noexcept;
        List(std::initializer_list<T> list) noexcept;

        template <ForwardIterator Iter> requires Convertible<typename Iter::value_type, typename List<T>::value_type>
        List(const Iter &begin, const Iter &end) noexcept;

        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        explicit List(const C &container) noexcept;
        
        ~List() noexcept;

        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        void PushBack(const T &data);
        void PushBack(const List<T> &list);
        void PushBack(List<T> &&list);

        void PushFront(const T &data);
        void PushFront(const List<T> &list);
        void PushFront(List<T> &&list);

        T PopBack();
        T PopFront();
        T &GetFront();
        T &GetBack();
        const T &GetFront() const;
        const T &GetBack() const;


        T &Get(size_t index);
        T &Get(const ListIterator<T> &iterator);
        const T &Get(size_t index) const;
        const T &Get(const ConstListIterator<T> &iterator) const;
        T &operator[](size_t index);
        T &operator[](const ListIterator<T> &iterator);
        const T &operator[](size_t index) const;
        const T &operator[](const ConstListIterator<T> &iterator) const;

        void Set(size_t index, const T &data);
        void Set(const ListIterator<T> &iterator, const T &data);
        
        void Remove(size_t index);
        void Remove(const ListIterator<T> &iterator);
        T Pop(size_t index);
        T Pop(const ListIterator<T> &iterator);
        void Insert(size_t index, const T &data);
        void InsertAfter(const ListIterator<T> &it, const T &data);
        void InsertBefore(const ListIterator<T> &it, const T &data);

        void Clear();
        void Reverse();

        bool IsEmpty() const;
        size_t GetSize() const;
        size_t size() const noexcept;

        List<T>& operator=(const List<T> &list);
        List<T>& operator=(List<T> &&list);
        List<T>& operator+=(const List<T> &list);
        List<T>& operator+=(List<T> &&list);
        List<T>& operator+=(const T &data);
        List<T> operator+(const List<T> &list) const;
        List<T> operator+(List<T> &&list) const;
        List<T> operator+(const T &data) const;

        bool operator==(const List<T> &list) const;
        bool operator!=(const List<T> &list) const;
        bool operator<(const List<T> &list) const;
        bool operator>(const List<T> &list) const;
        bool operator<=(const List<T> &list) const;
        bool operator>=(const List<T> &list) const;

    protected:
        void pushBack(std::shared_ptr<ListNode<T>> &node);
        void pushFront(std::shared_ptr<ListNode<T>> &node);
        std::shared_ptr<ListNode<T>> popBack();
        std::shared_ptr<ListNode<T>> popFront();
        std::shared_ptr<ListNode<T>> get(size_t index);
        const std::shared_ptr<ListNode<T>> get(size_t index) const;
        std::shared_ptr<ListNode<T>> get(const ListIterator<T> &iterator);
        const std::shared_ptr<ListNode<T>> get(const ConstListIterator<T> &iterator) const;
        std::shared_ptr<ListNode<T>> pop(size_t index);
        std::shared_ptr<ListNode<T>> pop(const ListIterator<T> &iterator);
        void insert(size_t index, std::shared_ptr<ListNode<T>> &node);
        void insertAfter(const ListIterator<T> &iterator, std::shared_ptr<ListNode<T>> &node);
        void insertBefore(const ListIterator<T> &iterator, std::shared_ptr<ListNode<T>> &node);
        int cmpList(const List<T> &list) const;
        void checkEmpty(size_t line) const;
    
    protected:
        std::shared_ptr<ListNode<T>> head;
        std::shared_ptr<ListNode<T>> tail;
        size_t csize;  
};

#endif // LIST_H__
