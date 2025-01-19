
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Cosine' : ", YELLOW + UNDERLINE) << std::endl;

    Vector<f32> u1({1.f, 0.f});
    Vector<f32> v1({1.f, 0.f});

    std::cout << " angle_cos 1 : " << angle_cos(u1, v1) << std::endl;

    Vector<f32> u2({1.f, 0.f});
    Vector<f32> v2({0.f, 1.f});

    std::cout << " angle_cos 2 : " << angle_cos(u2, v2) << std::endl;

    Vector<f32> u3({-1.f, 1.f});
    Vector<f32> v3({1.f, -1.f});

    std::cout << " angle_cos 3 : " << angle_cos(u3, v3) << std::endl;

    Vector<f32> u4({2.f, 1.f});
    Vector<f32> v4({4.f, 2.f});

    std::cout << " angle_cos 4 : " << angle_cos(u4, v4) << std::endl;

    Vector<f32> u5({1.f, 2.f, 3.f});
    Vector<f32> v5({4.f, 5.f, 6.f});

    std::cout << " angle_cos 5 : " << angle_cos(u5, v5) << std::endl;

    return 0;
}