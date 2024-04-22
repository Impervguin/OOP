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

        // Конструкторы
        List() noexcept;
        explicit List(const List<T>& list);
        List<T>& operator=(const List<T> &list);
        List(List<T> &&list) noexcept;
        List<T>& operator=(List<T> &&list);
        
        template <Convertible<value_type> U>
        List(size_t size, const U& data);

        template <Convertible<value_type> U>
        List(std::initializer_list<U> list);

        template <ConvertibleForwardIterator<T> Iter>
        List(const Iter &begin, const Iter &end);

        template <ConvertibleContainer<value_type> C>
        explicit List(const C &container);
        template <ConvertibleContainer<value_type> C>
        List<T> &operator=(const C &container);
        
        template <ConvertibleContainer<value_type> C>
        List(C &&container);
        template <ConvertibleContainer<value_type> C>
        List<T> &operator=(C &&container);
        
        ~List();

        // Итераторы
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        // Методы связанные с размером
        bool IsEmpty() const noexcept;
        size_t GetSize() const noexcept;
        size_type size() const noexcept;

        // Вставка в конец
        template <Convertible<value_type> U>
        void PushBack(const U &data);
        template <Convertible<value_type> U>
        List<T>& operator+=(const U &data);

        template <Convertible<value_type> U>
        void PushBack(U &&data);
        template <Convertible<value_type> U>
        List<T>& operator+=(U &&data);

        template <ConvertibleContainer<value_type> C>
        void PushBack(const C &container);
        template <ConvertibleContainer<value_type> C>
        List<T>& operator+=(const C &container);
        
        template <ConvertibleContainer<value_type> C>
        void PushBack(C &&container);
        template <ConvertibleContainer<value_type> C>
        List<T>& operator+=(C &&container);
        
        void PushBack(List<T> &&list) noexcept;
        List<T>& operator+=(List<T> &&list) noexcept;

        // Методы сложения
        List<T> operator+(List<T> &&list) const;
        template <ConvertibleContainer<value_type> C>
        List<T> operator+(const C &container) const;
        template <ConvertibleContainer<value_type> C>
        List<T> operator+(C &&container) const;
        template <Convertible<value_type> U>
        List<T> operator+(const U &data) const;
        template <Convertible<value_type> U>
        List<T> operator+(U &&data) const;


        // Вставка в начало
        template <Convertible<value_type> U>
        void PushFront(const U &data);
        template <Convertible<value_type> U>
        void PushFront(U &&data);
        template <ConvertibleContainer<value_type> C>
        void PushFront(const C &container);
        template <ConvertibleContainer<value_type> C>
        void PushFront(C &&container);
        void PushFront(List<T> &&list) noexcept;

        // Вставка внутрь списка
        template <Convertible<value_type> U>
        void Insert(size_t index, const U &data);
        template <Convertible<value_type> U>
        void Insert(size_t index, U &&data);
        template <ConvertibleContainer<value_type> C>
        void Insert(size_t index, const C &container);
        template <ConvertibleContainer<value_type> C>
        void Insert(size_t index, C &&container);
        void Insert(size_t index, List<T> &&list);

        template <Convertible<value_type> U>
        void Insert(const ListIterator<T> &it, U &&data);
        template <Convertible<value_type> U>
        void Insert(const ListIterator<T> &it, const U &data);
        template <ConvertibleContainer<value_type> C>
        void Insert(const ListIterator<T> &it, const C &container);
        template <ConvertibleContainer<value_type> C>
        void Insert(const ListIterator<T> &it, C &&container);
        void Insert(const ListIterator<T> &it, List<T> &&list);

        // Удаление элементов возвратом значения
        T PopBack();
        T PopFront();
        T Pop(size_t index);
        T Pop(const ListIterator<T> &iterator);
        List<T> Pop(const ListIterator<T> &begin, const ListIterator<T> &end);
        List<T> Pop(const ListIterator<T> &begin, size_t count);
        List<T> Pop(size_t index, size_t count);

        // Удаление элементов
        void Remove(size_t index);
        void Remove(const ListIterator<T> &iterator);
        void Remove(const ListIterator<T> &begin, const ListIterator<T> &end);
        void Remove(const ListIterator<T> &begin, size_t count);
        void Remove(size_t index, size_t count);

        // Взятие подсписка
        List<T> SubList(const ListIterator<T> &begin, const ListIterator<T> &end);
        List<T> SubList(const ListIterator<T> &begin, size_t count);
        List<T> SubList(size_t index, size_t count);
    
        // Методы работы со списками целиком
        void Clear() noexcept;
        void Reverse() noexcept;

        // Методы сравнения
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
        List<T> pop(const ListIterator<T> &begin, const ListIterator<T> &end);
        List<T> subList(const ListIterator<T> &begin, const ListIterator<T> &end);
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
