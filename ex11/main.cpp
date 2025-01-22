
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Determinant' : ", YELLOW + UNDERLINE) << std::endl;

    Matrix<f32> m1({
        {1, -1},
        {-1, 1}
    });

    std::cout << "Matrix 2 : " << m1 << std::endl;

    std::cout << "Determinant : " << m1.determinant() << std::endl;    

    Matrix<f32> m2({
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    });

    std::cout << "Matrix 2 : " << m2 << std::endl;

    std::cout << "Determinant : " << m2.determinant() << std::endl;

    Matrix<f32> m3({
        {8, 5, -2},
        {4, 7, 20},
        {7, 6, 1}
    });

    std::cout << "Matrix 3 : " << m3 << std::endl;

    std::cout << "Determinant : " << m3.determinant() << std::endl;
    
    Matrix<f32> m4({
        {8, 5, -2, 4},
        {4, 2.5, 20, 4},
        {8, 5, 1, 4},
        {28, -4, 17, 1}
    });

    std::cout << "Matrix 4 : " << m4 << std::endl;

    std::cout << "Determinant : " << m4.determinant() << std::endl;


    return 0;
}