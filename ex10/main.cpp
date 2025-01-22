
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'row-echelon form' : ", YELLOW + UNDERLINE) << std::endl;

    Matrix<f32> m({
        {1.f, 0.f, 0.f},
        {0.f, 1.f, 0.f},
        {0.f, 0.f, 1.f}
    });

    std::cout << "row-echelon form of m : \n" << m.row_echelon() << std::endl;

    Matrix<f32> m1({
        {1.f, 2.f},
        {3.f, 4.f},
    });

    std::cout << "\nrow-echelon form of m1 : \n" << m1.row_echelon() << std::endl;

    Matrix<f32> m2({
        {1.f, 2.f},
        {2.f, 4.f},
    });

    std::cout << "\nrow-echelon form of m1 : \n" << m2.row_echelon() << std::endl;

    Matrix<f32> m3({
        {8.f, 5.f, -2.f, 4.f, 28.f},
        {4.f, 2.5f, 20.f, 4.f, -4.f},
        {8.f, 5.f, 1.f, 4.f, 17.f}
    });

    std::cout << "\nrow-echelon form of m3 : \n" << m3.row_echelon() << std::endl;

    return 0;
}