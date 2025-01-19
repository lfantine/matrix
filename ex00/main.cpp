
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"


int main() {

    std::cout << color("Test de l'addition de vecteurs : ", YELLOW + UNDERLINE) << std::endl;

    Vector<f32> vector1({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
    Vector<f32> vector2({10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f});

    std::cout << "Vector 1 : " << vector1 << std::endl;
    std::cout << "Vector 2 : " << vector2 << std::endl;

    vector1.add(vector2);

    std::cout << "Vector 1 + Vector 2 : " << vector1 << std::endl;

    std::cout << color("Test de l'addition de matrices : ", YELLOW + UNDERLINE) << std::endl;

    matrixType init_data1 = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};
    matrixType init_data2 = {{10.0f, 20.0f, 30.0f}, {40.0f, 50.0f, 60.0f}, {70.0f, 80.0f, 90.0f}};

    Matrix<f32> matrix1(init_data1);
    Matrix<f32> matrix2(init_data2);

    std::cout << "Matrix 1 : " << matrix1 << std::endl;
    std::cout << "Matrix 2 : " << matrix2 << std::endl;

    matrix1.add(matrix2);

    std::cout << "Matrix 1 + Matrix 2 : " << matrix1 << std::endl;

    std::cout << color("Test de la soustraction de vecteurs : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "Vector 1 : " << vector1 << std::endl;
    std::cout << "Vector 2 : " << vector2 << std::endl;

    vector1.sub(vector2);

    std::cout << "Vector 1 - Vector 2 : " << vector1 << std::endl;

    std::cout << color("Test de la soustraction de matrices : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "Matrix 1 : " << matrix1 << std::endl;
    std::cout << "Matrix 2 : " << matrix2 << std::endl;

    matrix1.sub(matrix2);

    std::cout << "Matrix 1 - Matrix 2 : " << matrix1 << std::endl;

    std::cout << color("Test de la multiplication par un scalaire de vecteurs : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "Vector 1 : " << vector1 << std::endl;

    vector1.scl(2.0f);

    std::cout << "Vector 1 * 2 : " << vector1 << std::endl;

    std::cout << color("Test de la multiplication par un scalaire de matrices : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "Matrix 1 : " << matrix1 << std::endl;

    matrix1.scl(2.0f);

    std::cout << "Matrix 1 * 2 : " << matrix1 << std::endl;

    return 0;
}