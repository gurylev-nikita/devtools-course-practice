// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>

#include <tuple>

#include <cmath>

#include "include/complex_number.h"

TEST(Gurylev_Nikita_ComplexNumberTest, EqualityCheck) {
    double re = 1.0;
    double im = 2.0;

    ComplexNumber z(re, im);
    ComplexNumber result = (z * z) / z;

    ASSERT_DOUBLE_EQ(1.0, result.getRe());
    ASSERT_DOUBLE_EQ(2.0, result.getIm());
}

TEST(Gurylev_Nikita_ComplexNumberTest, ArithmeticOperation) {
    ComplexNumber z(8.0, 9.0);
    ComplexNumber q(4.0, 3.0);

    ComplexNumber num1 = (z + q) * (z - q);
    ComplexNumber num2 = (z + q) * (z - q);
    ComplexNumber result(-24.0, 120.0);

    ASSERT_EQ(result, num1);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
Gurylev_Nikita_ComplexNumberTest_Param;
TEST_P(Gurylev_Nikita_ComplexNumberTest_Param, ComparisonOperation) {
    ComplexNumber num1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    ComplexNumber num2(std::get<2>(GetParam()), std::get<3>(GetParam()));

    ComplexNumber result1 = ((num2 * num1) / num1);
    ComplexNumber result2 = ((result1 / num2) * num1);

    ASSERT_EQ(result2, num1);
}

INSTANTIATE_TEST_CASE_P(/**/, Gurylev_Nikita_ComplexNumberTest_Param,
    testing::Values(
        std::make_tuple(2.0, 6.0, 6.0, 15.0),
        std::make_tuple(2.0, 4.0, 0.0, 5.0),
        std::make_tuple(2.0, 3.0, 15.0, 7.0),
        std::make_tuple(10.0, 5.0, 3.0, 8.0)));
