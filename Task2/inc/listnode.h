#ifndef LISTNODE_H__
#define LISTNODE_H__

#include <memory>

template <typename  T>
class ListNode 
{
    private:
        T data;
        std::shared_ptr<ListNode<T>> next;
    
    public:
        ListNode(const T &data);
        ListNode(const T &data, const std::shared_ptr<ListNode<T>> &next);
        ListNode(const T &data, const ListNode<T> &next);
        ListNode(const std::shared_ptr<ListNode<T>> &node);
        ListNode(const ListNode<T> &node);
        ListNode();
        ~ListNode() = default;

        void SetNext(const std::shared_ptr<ListNode<T>> &node);
        void SetNext(const ListNode<T> &node);
        void SetData(const T &data);
        void SetNextNull();

        T &GetData();
        const T &GetData() const;
        std::shared_ptr<ListNode<T>> GetNext() const;
        // const std::shared_ptr<ListNode<T>> &GetNext() const;

        bool operator==(const ListNode<T> &node) const;
        bool operator!=(const ListNode<T> &node) const;
};

#endif // LISTNODE_H__