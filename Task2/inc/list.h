#ifndef LIST_H__
#define LIST_H__

#include "basecontainer.h"
#include "listnode.h"
#include "listiterator.h"
#include "constlistiterator.h"
#include <iostream>

template <typename T>
class List: public BaseContainer {
    protected:
        std::shared_ptr<ListNode<T>> head;
        std::shared_ptr<ListNode<T>> tail;    
    public:
        List();
        List(std::initializer_list<T> list);
        List(const List<T>& list);
        List(const ListIterator<T> &begin, const ListIterator<T> &end);
        List(size_t size, const T& data);
        List<T>(List<T>&& list);
        
        ~List() override;

        ListIterator<T> begin();
        ListIterator<T> end();
        ConstListIterator<T> cbegin() const;
        ConstListIterator<T> cend() const;

        void PushBack(const T &data);
        void PushBack(const List<T> &list);
        void PushBack(List<T> &&list);

        void PushFront(const T &data);
        void PushFront(const List<T> &list);
        void PushFront(List<T> &&list);

        
        T &PopBack();
        T &PopFront();
        T &GetFront();
        T &GetBack();
        const T &GetFront() const;
        const T &GetBack() const;


        T &Get(size_t index);
        T &Get(const ListIterator<T> &iterator);
        const T &Get(size_t index) const;
        const T &Get(const ListIterator<T> &iterator) const;
        const T &Get(const ConstListIterator<T> &iterator) const;
        T &operator[](size_t index);
        T &operator[](const ListIterator<T> &iterator);
        const T &operator[](size_t index) const;
        const T &operator[](const ListIterator<T> &iterator) const;
        const T &operator[](const ConstListIterator<T> &iterator) const;

        void Set(size_t index, const T &data);
        void Set(const ListIterator<T> &iterator, const T &data);
        
        void Remove(size_t index);
        void Remove(const ListIterator<T> &iterator);
        T &Pop(size_t index);
        T &Pop(const ListIterator<T> &iterator);
        // TODO:
        void Insert(size_t index, const T &data);
        void InsertAfter(const ListIterator<T> &it, const T &data);
        void InsertBefore(const ListIterator<T> &it, const T &data);

        void Clear();
        void Reverse();

        List<T>& operator=(const List<T> &list);
        List<T>& operator=(List<T> &&list);
    
    protected:
        void pushBack(std::shared_ptr<ListNode<T>> &node);
        void pushFront(std::shared_ptr<ListNode<T>> &node);
        std::shared_ptr<ListNode<T>> popBack();
        std::shared_ptr<ListNode<T>> popFront();
        std::shared_ptr<ListNode<T>> get(size_t index) const;
        std::shared_ptr<ListNode<T>> get(const ListIterator<T> &iterator) const;
        std::shared_ptr<ListNode<T>> get(const ConstListIterator<T> &iterator) const;
        std::shared_ptr<ListNode<T>> pop(size_t index);
        std::shared_ptr<ListNode<T>> pop(const ListIterator<T> &iterator);
        void insert(size_t index, std::shared_ptr<ListNode<T>> &node);
        void insertAfter(const ListIterator<T> &iterator, std::shared_ptr<ListNode<T>> &node);
        void insertBefore(const ListIterator<T> &iterator, std::shared_ptr<ListNode<T>> &node);
        void checkEmpty(size_t line) const;
};

#endif // LIST_H__
