
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Dot product' : ", YELLOW + UNDERLINE) << std::endl;

    f32 dot = Vector<f32>::dot(Vector<f32>({0.f, 0.f}), Vector<f32>({1.f, 1.f}));

    std::cout << "Dot product is " << dot << std::endl;

    dot = Vector<f32>::dot(Vector<f32>({1.f, 1.f}), Vector<f32>({1.f, 1.f}));

    std::cout << "Dot product is " << dot << std::endl;

    dot = Vector<f32>::dot(Vector<f32>({-1.f, 6.f}), Vector<f32>({3.f, 2.f}));

    std::cout << "Dot product is " << dot << std::endl;

    return 0;
}