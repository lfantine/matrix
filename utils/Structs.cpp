#include "Structs.hpp"

#define SECURE_VECTOR_LENGHT if (vector.length() != _data.size()) {\
        throw std::invalid_argument("Vectors must have the same size");\
    }

/*  >---------------------- | Vector | ----------------------<  */

template <typename K>
const std::list<size_t> Vector<K>::getShape() const{
    std::list<size_t> shape;
    shape.push_back(1);
    shape.push_back(_data.size());
    return shape;
}

template <typename K>
size_t    Vector<K>::length() const {
    return _data.size();
}

template <typename K>
std::ostream& Vector<K>::print(std::ostream &os) const {
    os << "[";
    for (size_t i = 0; i < _data.size(); i++) {
        os << _data[i];
        if (i < _data.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename K>
Matrix<K> Vector<K>::reshape(size_t nRow, size_t nElementRow) const {
    if (nRow * nElementRow != _data.size()) {
        throw std::invalid_argument("Shape must be compatible with the size of the vector");
    }
    std::vector<std::vector<K>> data;
    size_t index = 0;
    for (size_t i = 0; i < nRow; i++) {
        std::vector<K> row;
        for (size_t j = 0; j < nElementRow; j++) {
            row.push_back(_data[index]);
            index++;
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K> Vector<K>::reshape(const std::list<size_t> &shape) const {
    if (shape.size() != 2) {
        throw std::invalid_argument("Shape must be a list of 2 elements");
    }
    size_t rows = shape.front();
    size_t cols = shape.back();
    if (rows * cols != _data.size()) {
        throw std::invalid_argument("Shape must be compatible with the size of the vector");
    }
    return reshape(rows, cols);
}

template <typename K>
Vector<K>& Vector<K>::add(const Vector<K> &vector) {
    if (vector.length() != _data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] += vector[i];
    }
    return *this;
}

template <typename K>
Vector<K>& Vector<K>::sub(const Vector<K> &vector) {
    if (vector.length() != _data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] -= vector[i];
    }
    return *this;
}

template <typename K>
Vector<K>& Vector<K>::scl(const K &scalar) {
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] *= scalar;
    }
    return *this;
}

template <typename K>
void    Vector<K>::add_with_fma(const Vector<K> &vector, const K &scalar) {
    if (vector.length() != _data.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] = std::fma(vector[i], scalar, _data[i]);
    }
}

template <typename K>
K   Vector<K>::dot(const Vector<K> &vector) const {
    SECURE_VECTOR_LENGHT
    if (vector.length() < 1) {
        throw std::invalid_argument("Vectors must have at least 1 element");
    }
    K  dot = _data[0] * vector[0];
    for (size_t i = 1; i < _data.size(); i++) {
        dot = std::fma(_data[i], vector[i], dot);
    }
    return dot;
}

template <typename K>
K   Vector<K>::dot(const Vector<K> &u, const Vector<K> &v) {
    return u.dot(v);
}

/*  >---------------------- | Matrix | ----------------------<  */

template <typename K>
const std::list<size_t> Matrix<K>::getShape() const {
    std::list<size_t> shape;
    shape.push_back(_data.size());
    if ( _data.size() > 0) {
        shape.push_back(_data[0].length());
    } else {
        shape.push_back(0);
    }
    return shape;
}

template <typename K>
size_t    Matrix<K>::length() const {
    return _data.size();
}

template <typename K>
std::ostream& Matrix<K>::print(std::ostream &os) const {
    os << "\n[\n";
    for (size_t i = 0; i < _data.size(); i++) {
        os << _data[i]; // Ici on utilise l'overload de l'opérateur << de la classe Vector
        if (i < _data.size() - 1) {
            os << ",\n";
        }
    }
    os << "\n]";
    return os;
}

template <typename K>
bool Matrix<K>::isSquare() const {
    return _data.size() == _data[0].length();
}

template <typename K>
Vector<K> Matrix<K>::flatten() const {
    std::vector<K> data;
    for (size_t i = 0; i < _data.size(); i++) {
        for (size_t j = 0; j < _data[i].length(); j++) {
            data.push_back(_data[i][j]);
        }
    }
    return Vector<K>(data);
}

template <typename K>
Matrix<K>& Matrix<K>::add(const Matrix<K> &matrix) {
    if (matrix.length() != _data.size()) {
        throw std::invalid_argument("Matrix must have the same number of rows");
    }
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] += matrix[i];
    }
    return *this;
}

template <typename K>
Matrix<K>& Matrix<K>::sub(const Matrix<K> &matrix) {
    if (matrix.length() != _data.size()) {
        throw std::invalid_argument("Matrix must have the same number of rows");
    }
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] -= matrix[i];
    }
    return *this;
}

template <typename K>
Matrix<K>& Matrix<K>::scl(const K &scalar) {
    for (size_t i = 0; i < _data.size(); i++) {
        _data[i] *= scalar;
    }
    return *this;
}

template <typename K>
void Matrix<K>::add_with_fma(const Matrix<K> &matrix, const K &scalar) {
    if (matrix.length() != _data.size()) {
        throw std::invalid_argument("Matrix must have the same size");
    }
    for (size_t i = 0; i < _data; i++) {
        _data[i].add_with_fma(matrix[i], scalar);
    }
}