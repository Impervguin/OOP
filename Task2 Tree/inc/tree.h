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

        void Add(T&& data);
        BSTree<T>& operator+=(T&& data);


        template <ConvertibleContainer<value_type> C>
        void Add(const C &container);
        template <ConvertibleContainer<value_type> C>
        BSTree<T>& operator+=(const C &container);
        
        void Add(BSTree<T> &&bstree) noexcept;
        BSTree<T>& operator+=(BSTree<T> &&bstree) noexcept;

        // Добавление с копированием
        template <Convertible<value_type> U>
        BSTree<T> CopyAdd(const U &data) const;
        template <Convertible<value_type> U>
        BSTree<T> operator+(const U &data) const;

        BSTree<T> CopyAdd(T&& data) const;
        BSTree<T> operator+(T&& data) const;


        template <ConvertibleContainer<value_type> C>
        BSTree<T> CopyAdd(const C &container) const;
        template <ConvertibleContainer<value_type> C>
        BSTree<T> operator+(const C &container) const;
        
        BSTree<T> CopyAdd(BSTree<T> &&bstree) const noexcept;
        BSTree<T> operator+(BSTree<T> &&bstree) const noexcept;

        // Поиск в дереве
        template <Convertible<value_type> U>
        bool Find(const U &data) const noexcept;

        template <ConvertibleContainer<value_type> C>
        bool Find(const C &container) const noexcept;

        // Удаление элементов
        template <Convertible<value_type> U>
        void Remove(const U &data) noexcept;
        template <Convertible<value_type> U>
        BSTree<T>& operator-=(const U &data) noexcept;

        template <ConvertibleContainer<value_type> C>
        void Remove(const C &container) noexcept;
        template <ConvertibleContainer<value_type> C>
        BSTree<T>& operator-=(const C &container) noexcept;

        // Удаление с копированием
        template <Convertible<value_type> U>
        BSTree<T> CopyRemove(const U &data) const;
        template <Convertible<value_type> U>
        BSTree<T> operator-(const U &data) const;

        template <ConvertibleContainer<value_type> C>
        BSTree<T> CopyRemove(const C &container) const;
        template <ConvertibleContainer<value_type> C>
        BSTree<T> operator-(const C &container) const;

        // Пересечение
        template <ConvertibleContainer<value_type> C>
        void Intersection(const C &container) noexcept;
        template <ConvertibleContainer<value_type> C>
        BSTree<T> &operator&=(const C &container) noexcept;
        
        template <ConvertibleContainer<value_type> C>
        BSTree<T> IntersectionCopy(const C &container) const;
        template <ConvertibleContainer<value_type> C>
        BSTree<T> operator&(const C &container) const;

        // Симметрическая Разность
        template <ConvertibleContainer<value_type> C>
        void SymmetricDifference(const C &container);
        template <ConvertibleContainer<value_type> C>
        BSTree<T> &operator^=(const C &container);

        template <ConvertibleContainer<value_type> C>
        BSTree<T> SymmetricDifferenceCopy(const C &container) const;
        template <ConvertibleContainer<value_type> C>
        BSTree<T> operator^(const C &container) const;

        void SymmetricDifference(BSTree<T> &&bstree) noexcept;
        BSTree<T> &operator^=(BSTree<T> &&bstree) noexcept;
        BSTree<T> SymmetricDifferenceCopy(BSTree<T> &&bstree) const noexcept;
        BSTree<T> operator^(BSTree<T> &&bstree) const noexcept;
        

        // Сравнение
        bool IsEqual(const BSTree<T> &bstree) const noexcept;
        bool IsNotEqual(const BSTree<T> &bstree) const noexcept;
        bool operator==(const BSTree<T> &bstree) const noexcept;
        bool operator!=(const BSTree<T> &bstree) const noexcept;



    protected:
        class TreeNode : public std::enable_shared_from_this<TreeNode>
        {
            public:
                TreeNode() = delete;
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
                TreeNode(const T &data);
                TreeNode(T&& data, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right);
                TreeNode(T&& data);
        };
    protected:
        std::shared_ptr<TreeNode> _root;
        size_t _size; 

        void add(std::shared_ptr<TreeNode> node) noexcept;
        void recursiveAdd(std::shared_ptr<TreeNode> root) noexcept;
        std::shared_ptr<TreeNode> find(const T &data) const noexcept;
        std::shared_ptr<TreeNode> remove(const T &data) noexcept;
        template <ConvertibleContainer<value_type> C>
        void intersection(const C &container) noexcept;
        template <ConvertibleContainer<value_type> C>
        void symmetricDifference(const C &container);
        void recursiveSymmetricDifference(std::shared_ptr<TreeNode> root);
        bool compare(const BSTree<T> &bstree) const noexcept;
};

template <AssignCopyComparable T>
std::ostream& operator<<(std::ostream& os, const BSTree<T>& bstree);

#include "treenode.hpp"
#include "tree.hpp"

