#pragma once

#include <iostream>

#include "Structs.hpp"
#include "Colors.hpp"
#include <list>
#include <vector>

// for the Fused multiply-add (FMA) function I need to import cmath
#include <cmath>

// function is accessible with fma(a, b, c) with a * b + c 


// ----------------------------------------------------------------

class Utils
{
    public:

        // Methods
        static void printVector(const Vector<f32> &vector);
        static void printMatrix(const Matrix<f32> &matrix);

    private:
        Utils(); // priavte constructor to ensure that the class is not instanciated
        ~Utils() {}; // Destructor
        /* data */
};

// overload utils

std::ostream& operator<<(std::ostream &os, const std::list<size_t> &list) {
    os << "(";
    for (auto it = list.begin(); it != list.end(); it++) {
        os << *it;
        if (std::next(it) != list.end()) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

// EX01

template <typename K>
Vector<K>   linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs);
template <typename K>
Vector<K>   linear_combination_fma(const std::vector<Vector<K>> &u, const std::vector<K> &coefs);


// EX02

template <typename K>
K   lerp(const K &a, const K &b, const f32 &t);

template <typename K>
K   lerp_fma(const K &a, const K &b, const f32 &t);

// EX04

template <typename T>
T   abs(const T& v);

// EX05

template <typename K>
f32     angle_cos(const Vector<K> &u, const Vector<K> &v);


// EX06 

template <typename K>
Vector<K>   cross_product(const Vector<K> &u, const Vector<K> &v);


// EX14    Projection matrice

Matrix<f32> projection(const f32 &fov, const f32 &ratio, const f32 &near, const f32 &far);

// ----------------------------------------------------------------

#include "Utils.cpp"