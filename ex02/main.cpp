
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test de la 'Linear interpolation' : ", YELLOW + UNDERLINE) << std::endl;

    f32 a = 0.0f;
    f32 b = 1.0f;

    f32 result = lerp<f32>(a, b, 0);

    std::cout << "result : " << result << std::endl;

    result = lerp<f32>(a, b, 1);

    std::cout << "result : " << result << std::endl;

    result = lerp<f32>(a, b, 0.5f);

    std::cout << "result : " << result << std::endl;

    f32 a1 = 21.0f;
    f32 b1 = 42.0f;

    f32 result1 = lerp<f32>(a1, b1, 0.3f);

    std::cout << "result 1 : " << result1 << std::endl;

    Vector<f32> a2({2.f, 1.f});
    Vector<f32> b2({4.f, 2.f});

    Vector<f32> result2 = lerp(a2, b2, 0.3f);

    std::cout << "result 2 : " << result2<< std::endl;

    Matrix<f32> a3({{2.f, 1.f},\
                    {3.f, 4.f}});
    Matrix<f32> b3({{20.f, 10.f},\
                    {30.f, 40.f}});

    Matrix<f32> result3 = lerp(a3, b3, 0.5f);

    std::cout << "result 3 : " << result3<< std::endl;

    std::cout << yellow("\nTest when vector are not the same lenght : ") << std::endl;

    try {
        Vector<f32> v3({1.0f, 2.0f, 3.0f, 4.0f});

        std::cout << "shapes are " << a2.getShape() << " and " << v3.getShape() << std::endl;

        Vector<f32> result_v2 = lerp(a2, v3, 0.5f);

        std::cout << "result v2 : "; Utils::printVector(result_v2);
    } catch (const std::exception &e) {
        std::cerr << red(e.what()) << std::endl;
    }

    return 0;
}