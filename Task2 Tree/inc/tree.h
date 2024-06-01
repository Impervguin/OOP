#pragma once
#include "treeiterator.h"
#include "consttreeiterator.h"
#include "reversetreeiterator.h"
#include "constreversetreeiterator.h"
#include "concepts.h"
#include "basecontainer.h"
#include <iostream>


template <AssignCopyComparable T>
class BSTree : public BaseContainer {
    friend class BaseTreeIterator<T>;
    friend class TreeIterator<T>;
    friend class ConstTreeIterator<T>;
    friend class ReverseTreeIterator<T>;
    friend class ConstReverseTreeIterator<T>;
    public:
        using value_type = T;
        using size_type = size_t;
        using iterator =  TreeIterator<T>;
        using const_iterator = ConstTreeIterator<T>;
        using reverse_iterator = ReverseTreeIterator<T>;
        using const_reverse_iterator = ConstReverseTreeIterator<T>;

        // Конструкторы
        BSTree() noexcept;
        explicit BSTree(const BSTree<T>& bstree);
        BSTree<T>& operator=(const BSTree<T> &bstree);

        BSTree(BSTree<T> &&bstree) noexcept;
        BSTree<T>& operator=(BSTree<T> &&bstree) noexcept;
        

        template <Convertible<value_type> U>
        explicit BSTree(std::initializer_list<U> list);
        
        template <Convertible<value_type> U>
        BSTree<T> &operator=(std::initializer_list<U> list);

        template <ConvertibleForwardIterator<T> Iter>
        BSTree(const Iter &begin, const Iter &end);

        template <ConvertibleContainer<value_type> C>
        explicit BSTree(const C &container);
        template <ConvertibleContainer<value_type> C>
        BSTree<T> &operator=(const C &container);
        
        ~BSTree() = default;

        // Итераторы
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        reverse_iterator rbegin() noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator rbegin() const noexcept;
        const_reverse_iterator rend() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;
        

        virtual size_t size() const noexcept;



        void Clear() noexcept;


        // Добавление элементов
        template <Convertible<value_type> U>
        void Add(const U &data);
        template <Convertible<value_type> U>
        BSTree<T>& operator+=(const U &data);





    protected:
        class TreeNode : public std::enable_shared_from_this<TreeNode>
        {
            public:
                TreeNode() = delete;
                TreeNode(const T &data) = delete;
                TreeNode(T &&data) = delete;
                ~TreeNode() = default;

                template <typename... Args>
                static std::shared_ptr<TreeNode> CreateNode(Args&&... params);

                void SetLeft(const std::shared_ptr<TreeNode> node);
                void SetRight(const std::shared_ptr<TreeNode> node);
                void SetData(const T &data);
                void SetLeftNull();
                void SetRightNull();

                std::shared_ptr<TreeNode> GetLeft();
                std::shared_ptr<TreeNode> GetRight();
                std::shared_ptr<T> GetData();
            
            protected:
                T _data;
                std::shared_ptr<TreeNode> _left;
                std::shared_ptr<TreeNode> _right;
                TreeNode(const T &data, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right);
        };
    protected:
        std::shared_ptr<TreeNode> _root;
        size_t _size;  
};

template <AssignCopyComparable T>
std::ostream& operator<<(std::ostream& os, const BSTree<T>& bstree);

#include "treenode.hpp"
#include "tree.hpp"

