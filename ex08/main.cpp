
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test de la  'Trace' : ", YELLOW + UNDERLINE) << std::endl;

    Matrix<f32> a({{1.f, 0.f},\
                    {0.f, 1.f}});

    std::cout << "Matrix a : " << a << std::endl;

    std::cout << "Trace de a : " << a.trace() << std::endl;

    Matrix<f32> a2({{2.f, -5.f, 0.f},\
                    {4.f, 3.f, 7.f},\
                    {-2.f, 3.f, 4.f}});

    std::cout << "Matrix a2 : " << a2 << std::endl;

    std::cout << "Trace de a2 : " << a2.trace() << std::endl;

     Matrix<f32> a3({{-2.f, -8.f, 4.f},\
                    {1.f, -23.f, 4.f},\
                    {0.f, 6.f, 4.f}});

    std::cout << "Matrix a3 : " << a3 << std::endl;

    std::cout << "Trace de a3 : " << a3.trace() << std::endl;

    return 0;
}