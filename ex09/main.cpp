
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Transposer' : ", YELLOW + UNDERLINE) << std::endl;

    vector_list data = {
        Vector<f32>({1, 2, 3}),
        Vector<f32>({4, 5, 6}),
        Vector<f32>({7, 8, 9})
    };

    Matrix<f32> matrix(data);

    std::cout << "Matrix : " << matrix << std::endl;

    Matrix<f32> transposed = matrix.transpose();

    std::cout << "Transposed : " << transposed << std::endl;

    return 0;
}