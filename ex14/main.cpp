
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Projection matrice' : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << projection(1.5708, 1, 1.f, 1000.f) << std::endl;

    return 0;
}