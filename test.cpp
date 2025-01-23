#include <iostream>
#include "utils/Structs.hpp"
#include "utils/Utils.hpp"

int main() {

    Vector<f32> vector({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
    std::vector<std::vector<f32>> init_data = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};
    Matrix<f32> matrix(init_data);


    std::cout << color("\nTest des differents fonctions utils : ", CYAN + UNDERLINE) << std::endl;

    std::cout << "Vector : " << vector << std::endl;
    std::cout << "Matrix : " << matrix << std::endl;

    std::cout << " Vector length : " << vector.length() << std::endl;
    std::cout << " Matrix length : " << matrix.length() << std::endl;

    std::cout << " Vector shape : " << vector.getShape() << std::endl;
    std::cout << " Matrix shape : " << matrix.getShape() << std::endl;

    std::cout << " Vector print : "; vector.print() << std::endl;
    std::cout << " Matrix print : "; matrix.print() << std::endl;

    std::cout << " Vector reshape : " << vector.reshape(2, 3) << std::endl;
    std::cout << " Matrix reshape : " << matrix.flatten() << std::endl;

    return 0;
}