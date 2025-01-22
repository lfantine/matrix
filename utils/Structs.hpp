#pragma once

#include <iostream>
#include <vector>
#include <list>

using f32 = float; // Define a float type in 32 bytes to sync with the subject f32 in RUST
using u32 = uint32_t; // Define a unsigned int type in 32 bytes to sync with the subject u32 in RUST
using matrixType = std::vector<std::vector<f32>>;

/*                                      📒 Informations 📒


    -> Shape in memory : 
        - The shape of a vector is defined by the number of elements it has.
        - The shape of a matrix is defined by the number of rows and columns it has.
        + The shape of a tensor is defined by the number of dimensions it has and the number of elements in each dimension.
        
    -> Storage order :
        - I choose to use col-order storage, 
        which means that the elements of the matrix are stored column by column ( a Vector is a column of my matrix ).

    -> Data type :
        - K is a template parameter that represents the data type of the elements in the matrix.
            => here is it used for f32 but can be used with own complexe number type.


*/

template <typename K>
class Matrix;

/*
    struct Vector::<K> {
        // ...
    }
 */

template <typename K>
class Vector {
    public :
        // Constructor
        Vector(const std::vector<K> &data) : _data(data) {};
        Vector(const Vector<K> &vector) : _data(vector._data) {};
        ~Vector() {};

        // utils
        size_t length() const;

        // Methods
        const std::list<size_t> getShape() const;
        std::ostream& print(std::ostream &os = std::cout) const;
        Matrix<K> reshape(size_t nRow, size_t nElementRow) const;
        Matrix<K> reshape(const std::list<size_t> &shape) const;



        // --- ex00 basics ---
        Vector<K>& add(const Vector<K> &vector);
        Vector<K>& sub(const Vector<K> &vector);
        Vector<K>& scl(const K &scalar);

        // --- ex01 linear combination ---

        // oui j'aurais pu juste enlever les const sur l'operateur [] mais je prefere utiliser une method
        void add_with_fma(const Vector<K> &vector, const K &scalar);


        // --- ex03 Dot Product ---

        K dot(const Vector<K> &vector) const;
        static K dot(const Vector<K> &u, const Vector<K> &v);

        // --- ex03 Norm ---

        f32 norm() const;
        f32 norm_1() const;
        f32 norm_inf() const;

        static f32 norm(const Vector<K> &v);
        static f32 norm(const Vector<K> &u, const Vector<K> &v);
        static f32 norm_1(const Vector<K> &v);
        static f32 norm_1(const Vector<K> &u, const Vector<K> &v);
        static f32 norm_inf(const Vector<K> &v);
        static f32 norm_inf(const Vector<K> &u, const Vector<K> &v);


        // ex10 

        void    set(const size_t &index, const K v) {
            if (index < _data.size()) {
                _data[index] = v;
            }
        }

        // Operators overload

        const K& operator[](size_t index) const {
            return _data[index];
        }
        
        Vector<K> operator+(const Vector<K> &vector) const {
            Vector<K> result(*this);
            return result.add(vector);
        }

        Vector<K>& operator+=(const Vector<K> &vector) {
            return this->add(vector);
        }

        Vector<K> operator-(const Vector<K> &vector) const {
            Vector<K> result(*this);
            return result.sub(vector);
        }

        Vector<K>& operator-=(const Vector<K> &vector) {
            return this->sub(vector);
        }

        Vector<K> operator*(const K &scalar) const {
            Vector<K> result(*this);
            return result.scl(scalar);
        }

        Vector<K>& operator*=(const K &scalar) {
            return this->scl(scalar);
        }

    private :
        // Data
        std::vector<K> _data;
};

// => Operator << pour faire un overload avec cout qui va afficher le vecteur
template <typename K>
std::ostream& operator<<(std::ostream &os, const Vector<K> &vector) {
    return vector.print(os);
}

/*
    struct Matrix::<K> {
        // ...
    }
 */

template <typename K>
class Matrix {
    public :
        // Constructor
        Matrix(const std::vector<std::vector<K>> &data) {
            // so the data is stored in column order but from row input
            for (size_t i = 0; i < data[0].size(); i++) {
                std::vector<K> vec;
                for (size_t j = 0; j < data.size(); j++) {
                    vec.push_back(data[j][i]);
                }
                _data.push_back(Vector<K>(vec));
            }
        };
        Matrix(const std::vector<Vector<K>> &data) : _data(data) {};
        Matrix(const Matrix<K> &matrix) : _data(matrix._data) {};
        ~Matrix() {};

        // utils
        size_t length() const;

        // Methods
        const std::list<size_t> getShape() const;
        std::ostream& print(std::ostream &os = std::cout) const;
        bool isSquare() const;
        Vector<K> flatten() const;

        // Ex00
        Matrix<K>& add(const Matrix<K> &matrix);
        Matrix<K>& sub(const Matrix<K> &matrix);
        Matrix<K>& scl(const K &scalar);

        //Ex02

        void add_with_fma(const Matrix<K> &matrix, const K &scalar);

        // Ex07

        Vector<K>   mul_vec(const Vector<K> &v);
        Matrix<K>   mul_mat(const Matrix<K> &m);

        static Vector<K>    mul_vec(const Matrix<K> &m, const Vector<K> &v);
        static Matrix<K>    mul_mat(const Matrix<K> &a, const Matrix<K> &b);

        // Ex08

        K   trace() const;

        // Ex09
        
        Matrix<K> transpose() const;

        // Ex10

        Matrix<K>   row_echelon() const;

        // Operators overload

        const Vector<K>& operator[](size_t index) const {
            return _data[index];
        }

        Matrix<K> operator+(const Matrix<K> &matrix) const {
            Matrix<K> result(*this);
            return result.add(matrix);
        }

        Matrix<K>& operator+=(const Matrix<K> &matrix) {
            return this->add(matrix);
        }

        Matrix<K> operator-(const Matrix<K> &matrix) const {
            Matrix<K> result(*this);
            return result.sub(matrix);
        }

        Matrix<K>& operator-=(const Matrix<K> &matrix) {
            return this->sub(matrix);
        }

        Matrix<K> operator*(const K &scalar) const {
            Matrix<K> result(*this);
            return result.scl(scalar);
        }

        Vector<K> operator*(const Vector<K> &vector) const {
            return Matrix<K>::mul_vec(*this, vector);
        }

        Matrix<K> operator*(const Matrix<K> &matrix) const {
            return Matrix<K>::mul_mat(*this, matrix);
        }

        Matrix<K>& operator*=(const K &scalar) {
            return this->scl(scalar);
        }

    private :
        // Data
        std::vector<Vector<K>> _data;
};

// => Operator << pour faire un overload avec cout qui va afficher la Matrice
template <typename K>
std::ostream& operator<<(std::ostream &os, const Matrix<K> &matrix) {
    return matrix.print(os);
}

#include "Structs.cpp"