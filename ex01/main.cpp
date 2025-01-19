
#include <iostream>

#include "../utils/Structs.hpp"
#include "../utils/Utils.hpp"

using vector_list = std::vector<Vector<f32>>;
using coef_list = std::vector<f32>;

int main() {

    std::cout << color("Test de la 'Linear combination' : ", YELLOW + UNDERLINE) << std::endl;

    Vector<f32> e1({1.0f, 0.0f, 0.0f});
    Vector<f32> e2({0.0f, 1.0f, 0.0f});
    Vector<f32> e3({0.0f, 0.0f, 1.0f});

    vector_list v_e({e1, e2, e3});
    coef_list c_e({10.0f, -2.0f, 0.5f});

    // Vector<f32> result_e = linear_combination<f32>(v_e, c_e);
    //Vector<f32> result_e = linear_combination<f32>(vector_list({e1, e2, e3}), coef_list({10.0f, -2.0f, 0.5f}));
    Vector<f32> result_e = linear_combination_fma<f32>(vector_list({e1, e2, e3}), coef_list({10.0f, -2.0f, 0.5f}));

    std::cout << "result e : "; Utils::printVector(result_e);

    Vector<f32> v1({1.0f, 2.0f, 3.0f});
    Vector<f32> v2({0.0f, 10.0f, -100.0f});

    vector_list v_v({v1, v2});
    coef_list c_v({10.0f, -2.0f});

    Vector<f32> result_v = linear_combination<f32>(v_v, c_v);
    //Vector<f32> result_v = linear_combination<f32>(vector_list({v1, v2}), coef_list({10.0f, -2.0f}));
    // Vector<f32> result_v = linear_combination_fma<f32>(vector_list({v1, v2}), coef_list({10.0f, -2.0f}));

    std::cout << "result v : "; Utils::printVector(result_v);


    std::cout << yellow("\nTest when vector are not the same lenght : ") << std::endl;

    try {
        Vector<f32> v3({1.0f, 2.0f, 3.0f, 4.0f});
        vector_list v_v2({v1, v3});
        coef_list c_v2({10.0f, -2.0f});

        std::cout << "shapes are " << v1.getShape() << " and " << v3.getShape() << std::endl;

        Vector<f32> result_v2 = linear_combination_fma<f32>(v_v2, c_v2);
        // Vector<f32> result_v2 = linear_combination<f32>(vector_list({v1, v3}), coef_list({10.0f, -2.0f}));

        std::cout << "result v2 : "; Utils::printVector(result_v2);
    } catch (const std::exception &e) {
        std::cerr << red(e.what()) << std::endl;
    }

    std::cout << yellow("\nTest when length of vetor array and length of coef array are not the same lenght : ") << std::endl;

    try {
        vector_list v_v3({v1, v2});
        coef_list c_v3({10.0f, -2.0f, 0.5f});

        std::cout << "there are 2 vectors and 3 coefs " << std::endl;

        Vector<f32> result_v3 = linear_combination_fma<f32>(v_v3, c_v3);
        // Vector<f32> result_v3 = linear_combination<f32>(vector_list({v1, v2}), coef_list({10.0f, -2.0f, 0.5f}));

        std::cout << "result v3 : "; Utils::printVector(result_v3);
    } catch (const std::exception &e) {
        std::cerr << red(e.what()) << std::endl;
    }


    return 0;
}