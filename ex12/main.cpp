
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Inverse' : ", YELLOW + UNDERLINE) << std::endl;

    Matrix<f32> m0({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });

    std::cout << "Matrix : " << m0 << std::endl;

    std::cout << "Inverse : " << m0.inverse() << std::endl;

    Matrix<f32> m1({
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    });

    std::cout << "Matrix : " << m1 << std::endl;

    std::cout << "Inverse : " << m1.inverse() << std::endl;

    Matrix<f32> m2({
        {8, 5, -2},
        {4, 7, 20},
        {7, 6, 1}
    });

    std::cout << "Matrix : " << m2 << std::endl;

    std::cout << "Inverse : " << m2.inverse() << std::endl;

    return 0;
}