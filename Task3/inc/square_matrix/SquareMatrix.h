#pragma once
#include <cstddef>
#include <vector>
#include <memory>

template<typename T> 
class SquareMatrix {
        
    public:
        class SquareMatrixRow {
            friend class SquareMatrix;
            using value_type = T;
            using size_type = std::size_t;
            using iterator = typename std::vector<T>::iterator;
            using const_iterator = typename std::vector<T>::const_iterator;
            using reverse_iterator = typename std::vector<T>::reverse_iterator;
            using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;
            
            public:
                SquareMatrixRow(std::size_t size);
                SquareMatrixRow(std::size_t size, T value);
                SquareMatrixRow();
                SquareMatrixRow(const SquareMatrixRow& other);
                SquareMatrixRow(SquareMatrixRow&& other);

                ~SquareMatrixRow() = default;

                SquareMatrixRow& operator=(const SquareMatrixRow& other);
                SquareMatrixRow& operator=(SquareMatrixRow&& other);
                T& operator[](std::size_t index);
                T operator[](std::size_t index) const;

                iterator begin();
                iterator end();
                const_iterator begin() const;
                const_iterator end() const;
                const_iterator cbegin() const;
                const_iterator cend() const;
                reverse_iterator rbegin();
                reverse_iterator rend();
                const_reverse_iterator rbegin() const;
                const_reverse_iterator rend() const;
                const_reverse_iterator crbegin() const;
                const_reverse_iterator crend() const;
                std::size_t size() const;

            private:
                std::size_t _size;
                std::vector<T> _values;
                void add(T val);
                void resize(std::size_t inc, T val);

        };
        using value_type = typename std::shared_ptr<SquareMatrixRow>;
        using size_type = typename std::size_t;
        using iterator = typename std::vector<value_type>::iterator;
        using const_iterator = typename std::vector<value_type>::const_iterator;
        using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;


        SquareMatrix(std::size_t size);
        SquareMatrix();
        SquareMatrix(const SquareMatrix& other);
        SquareMatrix(SquareMatrix&& other);
        ~SquareMatrix() = default;

        SquareMatrix& operator=(const SquareMatrix& other);
        SquareMatrix& operator=(SquareMatrix&& other);

        SquareMatrixRow& operator[](std::size_t index);
        SquareMatrixRow operator[](std::size_t index) const;

        std::size_t size() const;
        std::vector<T> GetRow(std::size_t index) const;
        std::vector<T> GetColumn(std::size_t index) const;
        SquareMatrix &Expend(std::size_t inc, T value);
        SquareMatrix &Resize(std::size_t new_size, T value);

        SquareMatrix Multiply(const SquareMatrix &other) const;
        SquareMatrix Multiply(T other) const;
        SquareMatrix operator*(T other) const;
        SquareMatrix operator*(const SquareMatrix &other) const;
        SquareMatrix& operator*=(const SquareMatrix &other);
        SquareMatrix& operator*=(T other);

        std::vector<T> MultiplyLeft(const std::vector<T> &other) const;
        std::vector<T> MultiplyRight(const std::vector<T> &other) const;
        std::vector<T> operator*(const std::vector<T> &other) const;

        SquareMatrix Add(const SquareMatrix &other) const;
        SquareMatrix Add(T other) const;
        SquareMatrix operator+(T other) const;
        SquareMatrix operator+(const SquareMatrix &other) const;
        SquareMatrix& operator+=(const SquareMatrix &other);
        SquareMatrix& operator+=(T other);

        SquareMatrix Subtract(const SquareMatrix &other) const;
        SquareMatrix Subtract(T other) const;
        SquareMatrix operator-(T other) const;
        SquareMatrix operator-(const SquareMatrix &other) const;
        SquareMatrix& operator-=(const SquareMatrix &other);
        SquareMatrix& operator-=(T other);
        SquareMatrix& Transpose();


        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;


    private:
        std::size_t _size;
        std::vector<std::shared_ptr<SquareMatrixRow>> _rows;
};

#include "SquareMatrixRow.hpp"
#include "SquareMatrix.hpp"