// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>
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
    ComplexNumber result(-24.0, 120.0);
    ASSERT_EQ(result, num1);
}

TEST(Gurylev_Nikita_ComplexNumberTest, ComputationComparison) {
    ComplexNumber z(5.0, 10.0);
    ComplexNumber q(3.0, 5.0);
    ComplexNumber g(2.0, 3.0);
    ComplexNumber result1 = z * q + g;
    ComplexNumber num1(z.getRe(), z.getIm());
    ComplexNumber num2(q.getRe(), q.getIm());
    ComplexNumber num3(g.getRe(), g.getIm());
    ComplexNumber result2 = num1 * num2 + num3;
    ASSERT_EQ(result1, result2);
}
