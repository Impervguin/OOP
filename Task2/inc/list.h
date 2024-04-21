#ifndef LIST_H__
#define LIST_H__

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

        friend class ListIterator<T>;
        friend class ConstListIterator<T>;

        List() noexcept;
        explicit List(const List<T>& list);
        List(List<T> &&list) noexcept;
        
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List(size_t size, const U& data);

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List(std::initializer_list<U> list);

        template <ForwardIterator Iter> requires Convertible<typename Iter::value_type, typename List<T>::value_type>
        List(const Iter &begin, const Iter &end);

        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        explicit List(const C &container);
        
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List(C &&container);
        
        ~List();

        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void PushBack(const U &data);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void PushBack(U &&data);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        void PushBack(const C &container);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        void PushBack(C &&container);
        void PushBack(List<T> &&list) noexcept;

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void PushFront(const U &data);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void PushFront(U &&data);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        void PushFront(const C &container);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        void PushFront(C &&container);
        void PushFront(List<T> &&list) noexcept;

        T PopBack();
        T PopFront();

        void Remove(size_t index);
        void Remove(const ListIterator<T> &iterator);
        T Pop(size_t index);
        T Pop(const ListIterator<T> &iterator);

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void Insert(size_t index, const U &data);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void InsertAfter(const ListIterator<T> &it, const U &data);

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void Insert(size_t index, U &&data);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        void InsertAfter(const ListIterator<T> &it, U &&data);

        void Clear() noexcept;
        void Reverse() noexcept;

        bool IsEmpty() const noexcept;
        size_t GetSize() const noexcept;
        size_type size() const noexcept;
        
        List<T>& operator=(const List<T> &list);
        List<T>& operator=(List<T> &&list);

        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T> &operator=(const C &container);

        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T> &operator=(C &&container);

        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List<T> &operator=(std::initializer_list<U> list);

        List<T>& operator+=(List<T> &&list);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T>& operator+=(const C &container);
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T>& operator+=(C &&container);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List<T>& operator+=(const U &data);
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List<T>& operator+=(U &&data);

        List<T> operator+(List<T> &&list) const;
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T> operator+(const C &container) const;
        template <Container C> requires Convertible<typename C::value_type, typename List<T>::value_type>
        List<T> operator+(C &&container) const;
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List<T> operator+(const U &data) const;
        template <typename U> requires Convertible<U, typename List<T>::value_type>
        List<T> operator+(U &&data) const;


        bool operator==(const List<T> &list) const;
        bool operator!=(const List<T> &list) const;
        bool operator<(const List<T> &list) const;
        bool operator>(const List<T> &list) const;
        bool operator<=(const List<T> &list) const;
        bool operator>=(const List<T> &list) const;

    protected:
        class ListNode : public std::enable_shared_from_this<ListNode>
        {
            public:
                ListNode() = delete;
                ListNode(const T &data) = delete;
                ListNode(T &&data) = delete;
                ~ListNode() = default;

                template <typename... Args>
                static std::shared_ptr<ListNode> CreateNode(Args&&... params);

                void SetNext(const std::shared_ptr<ListNode> &node);
                void SetData(const T &data);
                void SetNextNull();

                std::shared_ptr<ListNode> GetNext();
                std::shared_ptr<T> GetData();
            
            protected:
                T data;
                std::shared_ptr<ListNode> next;
                ListNode(const T &data, const std::shared_ptr<ListNode> &next);
        };  

    protected:
        void pushBack(std::shared_ptr<ListNode> &node) noexcept;
        void pushFront(std::shared_ptr<ListNode> &node) noexcept;
        std::shared_ptr<ListNode> popBack();
        std::shared_ptr<ListNode> popFront();
        std::shared_ptr<ListNode> get(size_t index);
        const std::shared_ptr<ListNode> get(size_t index) const;
        std::shared_ptr<ListNode> get(const ListIterator<T> &iterator);
        const std::shared_ptr<ListNode> get(const ConstListIterator<T> &iterator) const;
        std::shared_ptr<ListNode> pop(size_t index);
        std::shared_ptr<ListNode> pop(const ListIterator<T> &iterator);
        void insert(size_t index, std::shared_ptr<ListNode> &node);
        void insertAfter(const ListIterator<T> &iterator, std::shared_ptr<ListNode> &node);
        void insertBefore(const ListIterator<T> &iterator, std::shared_ptr<ListNode> &node);
        int cmpList(const List<T> &list) const;
        void checkEmpty(size_t line) const;
    
    protected:
        std::shared_ptr<ListNode> head;
        std::shared_ptr<ListNode> tail;
        size_t csize;
        
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list);

template <typename T, typename U>
requires Convertible<U, typename List<T>::value_type>
List<T> operator+(const U& data, const List<T> &list);
template <typename T, typename U>
requires Convertible<U, typename List<T>::value_type>
List<T> operator+(U&& data, const List<T> &list);

#endif // LIST_H__
