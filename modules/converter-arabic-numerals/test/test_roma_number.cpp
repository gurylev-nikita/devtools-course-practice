// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>
#include <string>
#include "include/romanumber.h"

TEST(Test_Roma_Number, test1) {
    ASSERT_NO_THROW(RomaNumber a);
}

TEST(Test_Roma_Number, test2) {
    RomaNumber a;
    EXPECT_EQ(0, a.GetArabic());
    EXPECT_EQ("", a.GetRoma());
}

TEST(Test_Roma_Number, test3) {
    ASSERT_NO_THROW(RomaNumber a(90));
}

TEST(Test_Roma_Number, test4) {
    ASSERT_ANY_THROW(RomaNumber a(5000));
}

TEST(Test_Roma_Number, test5) {
    ASSERT_ANY_THROW(RomaNumber a(-3));
}

TEST(Test_Roma_Number, test6) {
    RomaNumber s;
    s.ArabToRoma(3);
    EXPECT_EQ(3, s.GetArabic());
    EXPECT_EQ("III", s.GetRoma());
}

TEST(Test_Roma_Number, test7) {
    RomaNumber s;
    s.ArabToRoma(49);
    EXPECT_EQ(49, s.GetArabic());
    EXPECT_EQ("XLIX", s.GetRoma());
}

TEST(Test_Roma_Number, test8) {
    RomaNumber s;
    s.ArabToRoma(978);
    EXPECT_EQ(978, s.GetArabic());
    EXPECT_EQ("CMLXXVIII", s.GetRoma());
}

TEST(Test_Roma_Number, test9) {
    RomaNumber s;
    s.ArabToRoma(2395);
    EXPECT_EQ(2395, s.GetArabic());
    EXPECT_EQ("MMCCCXCV", s.GetRoma());
}

TEST(Test_Roma_Number, test10) {
    RomaNumber s;
    ASSERT_ANY_THROW(s.ArabToRoma(4001));
}

TEST(Test_Roma_Number, test11) {
    ASSERT_NO_THROW(RomaNumber a("XX"));
}

TEST(Test_Roma_Number, test12) {
    std::string r = "VIII";
    RomaNumber a(r);
    EXPECT_EQ("VIII", a.GetRoma());
    EXPECT_EQ(8, a.GetArabic());
}

TEST(Test_Roma_Number, test13) {
    RomaNumber s;
    s.RomaToArab("D");
    EXPECT_EQ(500, s.GetArabic());
    EXPECT_EQ("D", s.GetRoma());
}

TEST(Test_Roma_Number, test14) {
    RomaNumber a1, a2;
    for (int i = 0; i < 4000; ++i) {
        a1.ArabToRoma(i);
        a2.RomaToArab(a1.GetRoma());
        EXPECT_EQ(i, a2.GetArabic());
    }
}

TEST(Test_Roma_Number, test15) {
    std::string r = "AX";
    ASSERT_ANY_THROW(RomaNumber a(r));
}
