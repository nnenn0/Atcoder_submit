//#include <gtest/gtest.h>
#include "answer.hpp"

int main() {
    using namespace AtCoder;

    answer(123);

    answer("string");

    answer(std::string("str"));

    std::array<std::string, 3> arr_s{"first", "second", "third"};
    answer(arr_s);

    std::vector<int> vec{11, 13, 17, 19, 22};
    answer(vec);

    answer(std::vector<int>{1, 2, 3});

    answer(std::vector<int>{1, 2, 3}, std::vector<int>{1, 2, 3});

    std::vector<double> vec_d {1.5, 2.0, 4.5};
    answer(vec_d);

    answer(123, vec, vec_d, vec);

    std::vector<std::vector<int>> table{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    answer(table);

    std::array<std::array<std::string, 3>, 2> table_a{"str", "ing", "str"};
    table_a.at(1) = {"test", "str", "ing"};
    answer(table_a);

    std::vector<std::vector<std::string>> vec_s;
    vec_s.push_back(std::vector<std::string>{"str", "str", "str"});
    answer(vec_s);
}