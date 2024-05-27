#include "SquareMatrix.h"
#include "matrixexception.h"
#include "iostream"

template<typename T>
SquareMatrix<T>::SquareMatrix(std::size_t size) : _size(size) {
    _rows = std::vector<std::shared_ptr<SquareMatrix::SquareMatrixRow>>(_size, nullptr);
    for (std::size_t i = 0; i < _size; ++i) {
        _rows[i] = std::make_shared<SquareMatrix::SquareMatrixRow>(size);
    }
}

template<typename T>
SquareMatrix<T>::SquareMatrix() : _size(0), _rows(std::vector<std::shared_ptr<SquareMatrix::SquareMatrixRow>>()) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& other) : _size(other._size) {
    _rows = std::vector<std::shared_ptr<SquareMatrix<T>::SquareMatrixRow>>(_size, nullptr);
    for (std::size_t i = 0; i < _size; ++i) {
        _rows[i] = std::make_shared<SquareMatrix<T>::SquareMatrixRow>(*other._rows[i]);
    }
}

template<typename T>
SquareMatrix<T>::SquareMatrix(SquareMatrix<T>&& other) {
    _size = other._size;
    _rows = std::move(other._rows);
    other._size = 0;
    other._rows = std::vector<std::shared_ptr<SquareMatrix<T>::SquareMatrixRow>>();
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix<T>& other) {
    _size = other._size;
    _rows = std::vector<std::shared_ptr<SquareMatrix::SquareMatrixRow>>(_size, nullptr);
    for (std::size_t i = 0; i < _size; ++i) {
        _rows[i] = std::make_shared<SquareMatrix::SquareMatrixRow>(*other._rows[i]);
    }
    return *this;
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(SquareMatrix<T>&& other) {
    _size = other._size;
    _rows = std::move(other._rows);
    other._size = 0;
    other._rows = std::vector<std::shared_ptr<SquareMatrix<T>::SquareMatrixRow>>();
    return *this;
}

template<typename T>
typename SquareMatrix<T>::SquareMatrixRow& SquareMatrix<T>::operator[](std::size_t index) {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return *_rows[index];
}

template<typename T>
typename SquareMatrix<T>::SquareMatrixRow SquareMatrix<T>::operator[](std::size_t index) const {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return *_rows[index];
}

template<typename T>
std::size_t SquareMatrix<T>::size() const {
    return _size;
}

template<typename T>
std::vector<T> SquareMatrix<T>::GetRow(std::size_t index) const {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    std::vector<T> arr(_size);
    for (std::size_t i = 0; i < _size; ++i) {
        arr[i] = (*this)[index][i];
    }
    return arr;
}

template<typename T>
std::vector<T> SquareMatrix<T>::GetColumn(std::size_t index) const {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    std::vector<T> arr(_size);
    for (std::size_t i = 0; i < _size; ++i) {
        arr[i] = (*this)[index][i];
    }
    return arr;
}

template<typename T>
SquareMatrix<T> &SquareMatrix<T>::Expend(std::size_t inc, T value) {
    for (std::size_t i = 0; i < inc; i++) {
        _rows.push_back(std::make_shared<SquareMatrix<T>::SquareMatrixRow>(_size + inc, value));
    }
    for (std::size_t i = 0; i < _size; i++) {
        (*this)[i].resize(_size + inc, value);
    }
    _size += inc;
    return *this;
}

template<typename T>
SquareMatrix<T> &SquareMatrix<T>::Resize(std::size_t new_size, T value) {
    if (new_size < _size) {
        for (std::size_t i = new_size; i < _size; i++) {
            _rows.pop_back();
        }
        for (std::size_t i = 0; i < new_size; i++) {
            (*this)[i].resize(new_size, value);
        }
    } else if (new_size > _size) {
        Expend(new_size - _size, value);
    }
    _size = new_size;
    return *this;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Multiply(const SquareMatrix<T> &other) const {
    if (_size!= other._size) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    SquareMatrix result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            for (std::size_t k = 0; k < _size; k++) {
                result[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Multiply(T other) const {
    SquareMatrix result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i][j] = (*this)[i][j] * other;
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(T other) const {
    return Multiply(other);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix<T> &other) const {
    return Multiply(other);
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator*=(const SquareMatrix<T> &other) {
    return *this = std::move(Multiply(other));
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator*=(T other) {
    return *this = std::move(Multiply(other));
}

template<typename T>
std::vector<T> SquareMatrix<T>::MultiplyLeft(const std::vector<T> &other) const {
    if (_size!= other.size()) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    std::vector<T> result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i] += (*this)[j][i] * other[j];
        }
    }
    return result;
}

template<typename T>
std::vector<T> SquareMatrix<T>::MultiplyRight(const std::vector<T> &other) const {
    if (_size!= other.size()) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    std::vector<T> result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i] += (*this)[i][j] * other[j];
        }
    }
    return result;
}

template<typename T>
std::vector<T> SquareMatrix<T>::operator*(const std::vector<T> &other) const {
    return MultiplyRight(other);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Add(const SquareMatrix<T> &other) const {
    if (_size!= other._size) {
        time_t now = time(nullptr);
        throw MatrixAddSizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    SquareMatrix<T> result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i][j] = (*this)[i][j] + other[i][j];
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Add(T other) const {
    SquareMatrix<T> result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i][j] = (*this)[i][j] + other;
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(T other) const {
    return Add(other);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix<T> &other) const {
    return Add(other);
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator+=(const SquareMatrix<T> &other) {
    return *this = std::move(Add(other));
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator+=(T other) {
    return *this = std::move(Add(other));
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Subtract(const SquareMatrix<T> &other) const {
    if (_size!= other._size) {
        time_t now = time(nullptr);
        throw MatrixAddSizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    SquareMatrix result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i][j] = (*this)[i][j] - other[i][j];
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::Subtract(T other) const {
    SquareMatrix result(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            result[i][j] = (*this)[i][j] - other;
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(T other) const {
    return Subtract(other);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(const SquareMatrix<T> &other) const {
    return Subtract(other);
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator-=(const SquareMatrix<T> &other) {
    return *this = std::move(Subtract(other));
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator-=(T other) {
    return *this = std::move(Subtract(other));
}

template<typename T>
SquareMatrix<T>& SquareMatrix<T>::Transpose() {
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            T tmp = (*this)[i][j];
            (*this)[i][j] = (*this)[j][i];
            (*this)[j][i] = tmp;
        }
    }
    return *this;
}

template<typename T>
typename SquareMatrix<T>::iterator SquareMatrix<T>::begin() {
    return _rows.begin();
}

template<typename T>
typename SquareMatrix<T>::iterator SquareMatrix<T>::end() {
    return _rows.end();
}

template<typename T>
typename SquareMatrix<T>::const_iterator SquareMatrix<T>::begin() const {
    return _rows.cbegin();
}

template<typename T>
typename SquareMatrix<T>::const_iterator SquareMatrix<T>::end() const {
    return _rows.cend();
}

template<typename T>
typename SquareMatrix<T>::const_iterator SquareMatrix<T>::cbegin() const {
    return _rows.cbegin();
}

template<typename T>
typename SquareMatrix<T>::const_iterator SquareMatrix<T>::cend() const {
    return _rows.cend();
}

template<typename T>
typename SquareMatrix<T>::reverse_iterator SquareMatrix<T>::rbegin() {
    return _rows.rbegin();
}

template<typename T>
typename SquareMatrix<T>::reverse_iterator SquareMatrix<T>::rend() {
    return _rows.rend();
}

template<typename T>
typename SquareMatrix<T>::const_reverse_iterator SquareMatrix<T>::rbegin() const {
    return _rows.crbegin();
}

template<typename T>
typename SquareMatrix<T>::const_reverse_iterator SquareMatrix<T>::rend() const {
    return _rows.crend();
}

template<typename T>
typename SquareMatrix<T>::const_reverse_iterator SquareMatrix<T>::crbegin() const {
    return _rows.crbegin();
}

template<typename T>
typename SquareMatrix<T>::const_reverse_iterator SquareMatrix<T>::crend() const {
    return _rows.crend();
}