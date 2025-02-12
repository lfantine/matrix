
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

#include <iomanip> // Pour std::setprecision et std::fixed
#include <cmath>

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {
    std::cout << std::setprecision(9);
    std::cout << color("Test de la  'norm' : ", YELLOW + UNDERLINE) << std::endl;

    Vector<f32>   u({1.f, 1.f, 1.f});

    std::cout << "norm(u) : " << u.norm() << " | " << u.norm_1() << " | " << u.norm_inf() << std::endl;

    Vector<f32>   u1({1.f, 2.f, 3.f});

    std::cout << "norm(u1) : " << u1.norm() << " | " << u1.norm_1() << " | " << u1.norm_inf() << std::endl;

    Vector<f32>   u2({-1.f, -2.f});

    std::cout << "norm(u2) : " << u2.norm() << " | " << u2.norm_1() << " | " << u2.norm_inf() << std::endl;

    std::cout << color("Test des en combinaisons : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "norm(u -> u1) : " << Vector<f32>::norm(u, u1) << " | " << Vector<f32>::norm_1(u1, u) << " | " << Vector<f32>::norm_inf(u1, u) << std::endl;

    return 0;
}