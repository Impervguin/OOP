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

        List<T>& operator=(const List<T> &list);
        List<T>& operator=(List<T> &&list);
    
    protected:
        void pushBack(std::shared_ptr<ListNode<T>> &node);
        void pushFront(std::shared_ptr<ListNode<T>> &node);
        std::shared_ptr<ListNode<T>> popBack();
        std::shared_ptr<ListNode<T>> popFront();
        void checkEmpty(size_t line) const;
};

#endif // LIST_H__
