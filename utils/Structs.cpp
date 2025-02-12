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
        _data[i] = fma(vector[i], scalar, _data[i]);
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
        dot = fma(_data[i], vector[i], dot);
    }
    return dot;
}

template <typename K>
K   Vector<K>::dot(const Vector<K> &u, const Vector<K> &v) {
    return u.dot(v);
}

template <typename K>
f32 Vector<K>::norm() const {
    if (_data.size() < 1) {
        throw std::invalid_argument("Vector must have at least 1 element");
    }
    f32 r = 0;
    for (size_t i = 0; i < this->length(); i++) {
        //r += pow(this->operator[](i), 2);    // here i can put *this[i] cos i consider the start of my vector is at the base of my plan
        r = fma(this->operator[](i), this->operator[](i), r);
    }
    return pow(r, 0.5f);
}

template <typename K>
f32 Vector<K>::norm_1() const {
    if (_data.size() < 1) {
        throw std::invalid_argument("Vector must have at least 1 element");
    }
    f32 r = 0;
    for (size_t i = 0; i < this->length(); i++) {
        //r += this->operator[](i) < 0 ? this->operator[](i) * -1 : this->operator[](i);  // same 
        r = fma(this->operator[](i), this->operator[](i) < 0 ? -1 : 1, r);
    }
    return r;
}

template <typename K>
f32 Vector<K>::norm_inf() const {
    if (_data.size() < 1) {
        throw std::invalid_argument("Vector must have at least 1 element");
    }
    f32 r = abs(_data[0]);
    for (size_t i = 1; i < _data.size(); i++) {
        r = std::max(r, static_cast<f32>(abs(_data[i])));
    }
    return r;
}

template <typename K>
f32 Vector<K>::norm(const Vector<K> &v) {
    return v.norm();
}

template <typename K>
f32 Vector<K>::norm(const Vector<K> &u, const Vector<K> &v) {
    if (u.length() != v.length()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    if (u.length() < 1) {
        throw std::invalid_argument("Vectors must have at least 1 element");
    }
    f32 r = 0;
    for (size_t i = 0; i < u.length(); i++) {
        //r += pow((v[i] - u[i]), 2);    // here i can put *this[i] cos i consider the start of my vector is at the base of my plan
        r = fma((v[i] - u[i]), (v[i] - u[i]), r);
    }
    return pow(r, 0.5f);
}

template <typename K>
f32 Vector<K>::norm_1(const Vector<K> &v) {
    return v.norm_1();
}

template <typename K>
f32 Vector<K>::norm_1(const Vector<K> &u, const Vector<K> &v) {
    if (u.length() != v.length()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    if (u.length() < 1) {
        throw std::invalid_argument("Vectors must have at least 1 element");
    }
    f32 r = 0;
    for (size_t i = 0; i < u.length(); i++) {
        //f32 t = (v[i] - u[i]); 
        //r += t < 0 ? t * -1 : t;
        r = fma((v[i] - u[i]), (v[i] - u[i]) < 0 ? -1 : 1, r);
    }
    return r;
}

template <typename K>
f32 Vector<K>::norm_inf(const Vector<K> &v) {
    return v.norm_inf();
}

template <typename K>
f32 Vector<K>::norm_inf(const Vector<K> &u, const Vector<K> &v) {
    if (u.length() != v.length()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    if (u.length() < 1) {
        throw std::invalid_argument("Vectors must have at least 1 element");
    }
    f32 r = abs(v[0] - u[0]);
    for (size_t i = 1; i < u.length(); i++) {
        r = std::max(r, static_cast<f32>(abs(v[i] - u[i])));
    }
    return r;
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
    if (_data.size() > 0) {
        for (size_t i = 0; i < _data[0].length(); i++) {
            os << "[";
            for (size_t j = 0; j < _data.size(); j++) {
                os << _data[j][i];
                if (j < _data.size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            if (i < _data[0].length() - 1) {
                os << "\n";
            }
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

template <typename K>
Vector<K>  Matrix<K>::mul_vec(const Vector<K> &v) {
    if (_data.size() <= 0 || v.length() != _data[0].length()) {
        throw std::invalid_argument("Vector must have the same size as the vectors in the matrix");
    }
    Vector<K> result(_data[0] * v[0]); // _data[0] correspond a [a,c] et v[0] correspond a x donc ici on fait a[0]*x
    for (size_t i = 1; i < _data.size(); i++) {  // j'ai plus qu'a l'additioner avec le reste des valeurs soit [b,d] * y sur i
        result.add_with_fma(_data[i], v[i]);
    }
    return result;
}

template <typename K>
Matrix<K>  Matrix<K>::mul_mat(const Matrix<K> &m) {
    if (_data.size() <= 0 || m.length() != _data[0].length()) {
        throw std::invalid_argument("Matrix must have the same size as the vectors in the matrix");
    }
    std::vector<Vector<K>> result;
    for (size_t i = 0; i < m.length(); i++) {
        result.push_back(this->mul_vec(m[i]));  // je fais la mul_vec masi pour chaque vecteur de la matrice m pour former result
    }
    return Matrix<K>(result);
}

template <typename K>
Vector<K>   Matrix<K>::mul_vec(const Matrix<K> &m, const Vector<K> &v) {
    return m.mul_vec(v);
}

template <typename K>
Matrix<K>    Matrix<K>::mul_mat(const Matrix<K> &a, const Matrix<K> &b) {
    return a.mul_mat(b);
}

template <typename K>
K   Matrix<K>::trace() const {
    if (!isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }
    K trace = _data[0][0];
    for (size_t i = 1; i < _data.size(); i++) {
        trace += _data[i][i];
    }
    return trace;
}

template <typename K>
Matrix<K>   Matrix<K>::transpose() const {
    std::vector<Vector<K>> data;
    for (size_t i = 0; i < _data[0].length(); i++) {
        std::vector<K> vec;
        for (size_t j = 0; j < _data.size(); j++) {
            vec.push_back(_data[j][i]);
        }
        data.push_back(Vector<K>(vec));
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K>   Matrix<K>::row_echelon() const {
    /*
        Cette fonction ne gere pas le cas ou les pivot ne sont pas dans le bon ordre en fonction des ligne 
        Ce cas echeant il faut inverser les lignes pour trouver le bon positionement SI ET SI la matrice est reversible
    */
    if (_data.size() <= 0) {
        throw std::invalid_argument("Matrix must have at least an element");
    }
    
    Matrix<K>   mCopy(*this);

    for (size_t i = 0; i < mCopy._data[0].length(); i++) {
        // passage des lignes une par une 

        for (size_t j = 0; j < mCopy._data.size(); j++) {
            // passage de chaque element dans une ligne

            if (mCopy._data[j][i] != 0) {
                // pivot found for line !
                // pivot is :  mCopy._data[j][i]

                // modif de la ligne
                const K saveV0 = mCopy._data[j][i];
                for (size_t j1 = 0; j1 < mCopy._data.size(); j1++) {
                    mCopy._data[j1].set(i, mCopy._data[j1][i] * (1 / saveV0));
                }

                // changement des lignes inferieur
                for (size_t i1 = 0; i1 < mCopy._data[0].length(); i1++) {
                    // Ici ca passe dans toutes les lignes superieur ET inferieures  ( row-echelon form  reducted / simplified )
                    if (i1 == i || mCopy._data[j][i1] == 0) continue; // si la valeur en dessous du pivot est 0 pas besoin de toucher a la ligne
                    const K saveValue = mCopy._data[j][i1];
                    for (size_t j1 = 0; j1 < mCopy._data.size(); j1++) {
                        // Acces a toutes les valeurs des lignes inferieures
                        const K k = mCopy._data[j1][i1] - ( mCopy._data[j1][i] * saveValue);
                        mCopy._data[j1].set(i1, k);
                    }
                }
                break;
            }
            // si pas de pivot trouver rien a changer
        }
    }

    return mCopy;
}

template <typename K>
const Matrix<K> getMinorMatrixForDeterminant(const Matrix<K> &m, size_t row, size_t col) {
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < m.length(); i++) {
        if (i == row) {
            continue;
        }
        std::vector<K> vec;
        for (size_t j = 0; j < m[i].length(); j++) {
            if (j == col) {
                continue;
            }
            vec.push_back(m[j][i]);
        }
        data.push_back(vec);
    }
    return Matrix<K>(data);
}

template <typename K>
const K   Matrix<K>::determinant() const {
    if (!isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }
    if (_data.size() == 1) {
        return _data[0][0];
    }
    if (_data.size() == 2) {
        return _data[0][0] * _data[1][1] - _data[0][1] * _data[1][0];
    }


    K det = 0;
    for (size_t i = 0; i < _data.size(); i++) {
        K sign = i % 2 == 0 ? 1 : -1;
        det += sign * _data[0][i] * getMinorMatrixForDeterminant(*this, i, 0).determinant();
    }
    return det;
}

// ex12

template <typename K>
Matrix<K>   Matrix<K>::inverse() const {
    if (!isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }
    K det = determinant();
    if (det == 0) {
        throw std::invalid_argument("Matrix must be reversible");
    }

    Matrix<K>   mCopy(*this);

    size_t n = mCopy.length();
    for (size_t i = 0; i < n; i++) {
        std::vector<K> vec;
        for (size_t j = 0; j < n; j++) {
            vec.push_back(i == j ? 1 : 0);
        }
        mCopy._data.push_back(Vector<K>(vec));
    }

    mCopy = mCopy.row_echelon();

    std::vector<std::vector<K>> data;

    for (size_t i = 0; i < n; i++) {
        std::vector<K> vec;
        for (size_t j = n; j < mCopy.length(); j++) {
            vec.push_back(mCopy[j][i]);
        }
        data.push_back(vec);
    }

    return Matrix<K>(data);
}

template <typename K>
usize   Matrix<K>::rank() const {
    Matrix<K>   mCopy(*this);
    mCopy = mCopy.row_echelon();
    mCopy = mCopy.transpose(); // coz my vector are columns and not rows ( and it need to check with rows )
    usize rank = 0;
    for (size_t i = 0; i < mCopy.length(); i++) {
        if (mCopy[i].norm_inf() != 0) {
            rank++;
        }
    }
    return rank;
}