
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Rank' : ", YELLOW + UNDERLINE) << std::endl;
    
    Matrix<f32> m0({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });

    std::cout << "Matrix : " << m0 << std::endl;

    std::cout << "Rank : " << m0.rank() << std::endl;

    Matrix<f32> m1({
        {1, 2, 0, 0},
        {2, 4, 0, 0},
        {-1, 2, 1, 1}
    });

    std::cout << "Matrix : " << m1 << std::endl;

    std::cout << "Rank : " << m1.rank() << std::endl;

    Matrix<f32> m2({
        {8, 5, -2},
        {4, 7, 20},
        {7, 6, 1},
        {21, 18, 7}
    });

    std::cout << "Matrix : " << m2 << std::endl;

    std::cout << "Rank : " << m2.rank() << std::endl;

    return 0;
}