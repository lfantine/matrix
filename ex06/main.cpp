
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'cross product' : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "Test 1 : " << cross_product(Vector<f32>({0.f, 0.f, 1.f}), Vector<f32>({1.f, 0.f, 0.f})) << std::endl;

    std::cout << "Test 2 : " << cross_product(Vector<f32>({1.f, 2.f, 3.f}), Vector<f32>({4.f, 5.f, 6.f})) << std::endl;

    std::cout << "Test 3 : " << cross_product(Vector<f32>({4.f, 2.f, -3.f}), Vector<f32>({-2.f, -5.f, 16.f})) << std::endl;

    return 0;
}