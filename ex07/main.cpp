
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test du 'Matrices -> Vector multiplication' : ", YELLOW + UNDERLINE) << std::endl;

    Matrix<f32> a({{1.f, 0.f},\
                    {0.f, 1.f}});
    Vector<f32> b({4.f, 2.f});

    std::cout << "Matrix a : " << a << std::endl;
    std::cout << "Vector b : " << b << std::endl;

    Vector<f32> result = a.mul_vec(b);
    
    std::cout << "result : " << result << std::endl;

    Matrix<f32> a2({{2.f, 0.f},\
                    {0.f, 2.f}});

    std::cout << "Matrix a2 : " << a2 << std::endl;
    std::cout << "Vector b2 : " << b << std::endl;

    Vector<f32> result2 = a2.mul_vec(b);

    std::cout << "result2 : " << result2 << std::endl;

    Matrix<f32> a3({{2.f, -2.f},\
                    {-2.f, 2.f}});

    std::cout << "Matrix a3 : " << a3 << std::endl;
    std::cout << "Vector b3 : " << b << std::endl;

    Vector<f32> result3 = a3.mul_vec(b);

    std::cout << "result3 : " << result3 << std::endl;

    std::cout << color("Test du 'Matrices -> Matrices multiplication' : ", YELLOW + UNDERLINE) << std::endl;

    std::cout << "result 1 : " << a.mul_mat(a) << std::endl;

    Matrix<f32> a4({{2.f, 1.f},\
                    {4.f, 2.f}});

    std::cout << "result 2 : " << a.mul_mat(a4) << std::endl;

    Matrix<f32> a5({{3.f, -5.f},\
                    {6.f, 8.f}});

    std::cout << "result 3 : " << a5.mul_mat(a4) << std::endl;

    return 0;
} 