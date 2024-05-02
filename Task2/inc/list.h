#ifndef LIST_H__
#define LIST_H__

#include "listiterator.h"
#include "constlistiterator.h"
#include "listconcepts.h"
#include "basecontainer.h"
#include <iostream>

template <AssignCopyComparable T>
class List : public BaseContainer {  
    public:
        using value_type = T;
        using iterator = ListIterator<T>;
        using const_iterator = ConstListIterator<T>;
        using size_type = size_t;

        friend class ListIterator<T>;
        friend class ConstListIterator<T>;
        friend class BaseListIterator<T>;

        // Конструкторы
        List() noexcept;
        explicit List(const List<T>& list);
        List<T>& operator=(const List<T> &list);

        List(List<T> &&list) noexcept;
        List<T>& operator=(List<T> &&list) noexcept;
        
        template <Convertible<value_type> U>
        List(size_t size, const U& data);

        template <Convertible<value_type> U>
        explicit List(std::initializer_list<U> list);
        
        template <Convertible<value_type> U>
        List<T> &operator=(std::initializer_list<U> list);

        template <ConvertibleForwardIterator<T> Iter>
        List(const Iter &begin, const Iter &end);

        template <ConvertibleContainer<value_type> C>
        explicit List(const C &container);
        template <ConvertibleContainer<value_type> C>
        List<T> &operator=(const C &container);
        
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

        void PushBack(T &&data);
        List<T>& operator+=(T &&data);

        template <ConvertibleContainer<value_type> C>
        void PushBack(const C &container);
        template <ConvertibleContainer<value_type> C>
        List<T>& operator+=(const C &container);
        
        void PushBack(List<T> &&list) noexcept;
        List<T>& operator+=(List<T> &&list) noexcept;

        // Методы сложения
        List<T> AddList(List<T> &&list) const;
        template <ConvertibleContainer<value_type> C>
        List<T> AddList(const C &container) const;
        template <Convertible<value_type> U>
        List<T> AddList(const U &data) const;
        List<T> AddList(T &&data) const;


        List<T> operator+(List<T> &&list) const;
        template <ConvertibleContainer<value_type> C>
        List<T> operator+(const C &container) const;
        template <Convertible<value_type> U>
        List<T> operator+(const U &data) const;
        List<T> operator+(T &&data) const;


        // Вставка в начало
        template <Convertible<value_type> U>
        void PushFront(const U &data);
        void PushFront(T &&data);
        template <ConvertibleContainer<value_type> C>
        void PushFront(const C &container);
        void PushFront(List<T> &&list) noexcept;

        // Вставка внутрь списка
        void Insert(const ListIterator<T> &it, T &&data);
        template <Convertible<value_type> U>
        void Insert(const ListIterator<T> &it, const U &data);
        template <ConvertibleContainer<value_type> C>
        void Insert(const ListIterator<T> &it, const C &container);
        void Insert(const ListIterator<T> &it, List<T> &&list);

        // Удаление элементов возвратом значения
        T PopBack();
        T PopFront();
        T Pop(const ListIterator<T> &iterator);
        List<T> Pop(const ListIterator<T> &begin, const ListIterator<T> &end);

        // Удаление элементов
        void Remove(const ListIterator<T> &iterator);
        void Remove(const ListIterator<T> &begin, const ListIterator<T> &end);

        // Взятие подсписка
        List<T> SubList(const ListIterator<T> &begin, const ListIterator<T> &end);
        List<T> SubList(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const;
    
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
        // Внутренние методы(Без проверок)

        // Методы вставок
        void pushBack(std::shared_ptr<ListNode> &node) noexcept;
        void pushFront(std::shared_ptr<ListNode> &node) noexcept;
        void insert(const ListIterator<T> &iterator, std::shared_ptr<ListNode> &node);
        
        // Методы удаления
        std::shared_ptr<ListNode> popBack();
        std::shared_ptr<ListNode> popFront();
        std::shared_ptr<ListNode> pop(const ListIterator<T> &iterator);
        List<T> pop(const ListIterator<T> &begin, const ListIterator<T> &end);

        // Метод взятия подсписка
        List<T> subList(const ListIterator<T> &begin, const ListIterator<T> &end);
        List<T> subList(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const;


        // Внутренний метод сравнения
        int cmpList(const List<T> &list) const;


        // Проверки с exceptions
        bool checkEmpty() const noexcept;
        bool checkForeignIterator(const ListIterator<T> &iterator) noexcept;
        bool checkForeignIterator(const ConstListIterator<T> &iterator) const noexcept;
        bool checkListRange(const ListIterator<T> &begin, const ListIterator<T> &end) noexcept;
        bool checkListRange(const ConstListIterator<T> &begin, const ConstListIterator<T> &end) const noexcept;
    
    protected:
        std::shared_ptr<ListNode> head;
        std::shared_ptr<ListNode> tail;
        // size_t csize;
        
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list);

template <typename T, Convertible<T> U>
List<T> operator+(const U& data, const List<T> &list);
template <typename T, Convertible<T> U>
List<T> operator+(U&& data, const List<T> &list);

#include "list.hpp"
#include "listnode.hpp"
#include "baselistiterator.hpp"
#include "listiterator.hpp"
#include "constlistiterator.hpp"


#endif // LIST_H__
