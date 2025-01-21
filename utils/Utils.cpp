#include "Utils.hpp"

void Utils::printVector(const Vector<f32> &vector) {
    std::cout << vector << std::endl;
}

void Utils::printMatrix(const Matrix<f32> &matrix) {
    std::cout << matrix << std::endl;
}


// EX01

template <typename K>
Vector<K>   linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs) {
    if (u.size() != coefs.size()) {
        // le resultat est censé return undefined mais pas de undefined en cpp donc je thorw une erreur
        throw std::invalid_argument("The number of vectors and coefficients must be the same");
    }
    Vector<K> result(u.front());
    result.scl(coefs.front());

    const size_t vecSizeRef = result.length();
    auto it = u.begin() + 1; // itérateur sur les vecteurs
    auto it2 = coefs.begin() + 1; // itérateur sur les coefficients

    for (; it != u.end(); it++, it2++) {
        if (vecSizeRef != it->length()) {
            throw std::invalid_argument("All vectors must have the same size.");
        }
        result.add(*it * *it2);
    }
    return result;
}


template <typename K>
Vector<K>   linear_combination_fma(const std::vector<Vector<K>> &u, const std::vector<K> &coefs) {
    if (u.size() != coefs.size()) {
        // le resultat est censé return undefined mais pas de undefined en cpp donc je thorw une erreur
        throw std::invalid_argument("The number of vectors and coefficients must be the same");
    }

    Vector<K> result(u.front());
    result.scl(coefs.front());

    const size_t vecSizeRef = result.length();
    auto it = u.begin() + 1; // itérateur sur les vecteurs
    auto it2 = coefs.begin() + 1; // itérateur sur les coefficients

    for (; it != u.end(); it++, it2++) {
        if (vecSizeRef != it->length()) {
            throw std::invalid_argument("All vectors must have the same size.");
        }
        result.add_with_fma(*it, *it2);
    }
    return result;
}


// EX02

template <typename K>
K   lerp(const K &a, const K &b, const f32 &t) {
    return a + (b - a) * t;
}


// EX04
template <typename T>
T   abs(const T& v) {
    return v > 0 ? v : v * -1;
}


// EX05
template <typename K>
f32     angle_cos(const Vector<K> &u, const Vector<K> &v) {
    if (u.length() != v.length()) {
        throw std::invalid_argument("Vectors must have the same size");
    }
    if (u.length() < 1) {
        throw std::invalid_argument("Vectors must have at least 1 element");
    }
    return Vector<f32>::dot(u, v) / (Vector<f32>::norm(u) * Vector<f32>::norm(v));
}

// EX06

template <typename K>
Vector<K>   cross_product(const Vector<K> &u, const Vector<K> &v) {
    if (u.length() != 3 || v.length() != 3) {
        throw std::invalid_argument("Vectors must have 3 elements");
    }
    return Vector<K>({
        std::fma(u[1], v[2], -(v[1] * u[2])),
        std::fma(u[2], v[0], -(v[2] * u[0])),
        std::fma(u[0], v[1], - (v[0] * u[1]))
    });
}