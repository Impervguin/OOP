#include "SquareMatrix.h"
#include "matrixexception.h"

template <typename T>
SquareMatrix<T>::SquareMatrixRow::SquareMatrixRow() : _size(0), _values(std::vector<T>()) {}

template <typename T>
SquareMatrix<T>::SquareMatrixRow::SquareMatrixRow(size_t size) : _size(size), _values(std::vector<T>(size, 0)) {}

template <typename T>
SquareMatrix<T>::SquareMatrixRow::SquareMatrixRow(size_t size, T value) : _size(size), _values(std::vector<T>(size, value)) {}

template <typename T>
SquareMatrix<T>::SquareMatrixRow::SquareMatrixRow(const SquareMatrixRow &other) : _size(other._size), _values(std::vector<T>(other._size, 0)) {
    for (size_t i = 0; i < _size; ++i) {
        _values[i] = other._values[i];
    }
}

template <typename T>
SquareMatrix<T>::SquareMatrixRow::SquareMatrixRow(SquareMatrixRow &&other) : _size(other._size), _values(std::move(other._values)) {}

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow &SquareMatrix<T>::SquareMatrixRow::operator=(const SquareMatrixRow &other) {
    _size = other._size;
    _values = std::vector<T>(other._size, 0);
    for (size_t i = 0; i < _size; ++i) {
        _values[i] = other._values[i];
    }
    return *this;
}

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow &SquareMatrix<T>::SquareMatrixRow::operator=(SquareMatrixRow && other) {
    _size = other._size;
    _values = std::move(other._values);
    return *this;
}

template <typename T>
T& SquareMatrix<T>::SquareMatrixRow::operator[](std::size_t index) {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixRowOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return _values[index];
}

template <typename T>
T SquareMatrix<T>::SquareMatrixRow::operator[](std::size_t index) const {
    if (_size <= index) {
        time_t now = time(nullptr);
        throw MatrixRowOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return _values[index];
}

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::iterator SquareMatrix<T>::SquareMatrixRow::begin() { return _values.begin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::iterator SquareMatrix<T>::SquareMatrixRow::end() { return _values.end(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_iterator SquareMatrix<T>::SquareMatrixRow::begin() const { return _values.begin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_iterator SquareMatrix<T>::SquareMatrixRow::end() const { return _values.end(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_iterator SquareMatrix<T>::SquareMatrixRow::cbegin() const { return _values.cbegin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_iterator SquareMatrix<T>::SquareMatrixRow::cend() const { return _values.cend(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::reverse_iterator SquareMatrix<T>::SquareMatrixRow::rbegin() { return _values.rbegin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::reverse_iterator SquareMatrix<T>::SquareMatrixRow::rend() { return _values.rend(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_reverse_iterator SquareMatrix<T>::SquareMatrixRow::rbegin() const { return _values.rbegin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_reverse_iterator SquareMatrix<T>::SquareMatrixRow::rend() const { return _values.rend(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_reverse_iterator SquareMatrix<T>::SquareMatrixRow::crbegin() const { return _values.crbegin(); }

template <typename T>
typename SquareMatrix<T>::SquareMatrixRow::const_reverse_iterator SquareMatrix<T>::SquareMatrixRow::crend() const { return _values.crend(); }

template <typename T>
size_t SquareMatrix<T>::SquareMatrixRow::size() const { return _size; }

template <typename T>
void SquareMatrix<T>::SquareMatrixRow::add(T value) { _values.push_back(value); _size++; }

template <typename T>
void SquareMatrix<T>::SquareMatrixRow::resize(std::size_t size, T val) {
    if (_size < size) {
        for (size_t i = _size; i < size; ++i) {
            _values.push_back(val);
        }
        
    } else {
        _values.resize(size);
    }
    _size = size;
}