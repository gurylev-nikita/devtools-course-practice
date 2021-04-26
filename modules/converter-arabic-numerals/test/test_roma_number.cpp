// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>

#include <string>

#include "include/romanumber.h"

TEST(Test_Roma_Number, Create_Roma_Number) {
    ASSERT_NO_THROW(RomaNumber a);
}

TEST(Test_Roma_Number, Correct_Create_Empty_Roma_Number) {
    RomaNumber a;
    ASSERT_EQ(0, a.GetArabic());
    ASSERT_EQ("", a.GetRoma());
}

TEST(Test_Roma_Number, Create_With_Arab) {
    ASSERT_NO_THROW(RomaNumber a(90));
}

TEST(Test_Roma_Number, Cant_Create_With_Big_Arab) {
    ASSERT_ANY_THROW(RomaNumber a(5000));
}

TEST(Test_Roma_Number, Cant_Create_With_Negative_Number) {
    ASSERT_ANY_THROW(RomaNumber a(-3));
}

TEST(Test_Roma_Number, Correct_Convert_Arab) {
    RomaNumber s;
    s.ArabToRoma(3);
    ASSERT_EQ(3, s.GetArabic());
    ASSERT_EQ("III", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab2) {
    RomaNumber s;
    s.ArabToRoma(49);
    ASSERT_EQ(49, s.GetArabic());
    ASSERT_EQ("XLIX", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab3) {
    RomaNumber s;
    s.ArabToRoma(978);
    ASSERT_EQ(978, s.GetArabic());
    ASSERT_EQ("CMLXXVIII", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab4) {
    RomaNumber s;
    s.ArabToRoma(2395);
    ASSERT_EQ(2395, s.GetArabic());
    ASSERT_EQ("MMCCCXCV", s.GetRoma());
}

TEST(Test_Roma_Number, Cant_Convert_Too_Big_Arab) {
    RomaNumber s;
    ASSERT_ANY_THROW(s.ArabToRoma(4001));
}

TEST(Test_Roma_Number, Can_Create_With_String) {
    ASSERT_NO_THROW(RomaNumber a("XX"));
}

TEST(Test_Roma_Number, Correct_Create_With_String) {
    std::string r = "VIII";
    RomaNumber a(r);
    ASSERT_EQ("VIII", a.GetRoma());
    ASSERT_EQ(8, a.GetArabic());
}

TEST(Test_Roma_Number, Correct_Convert_Roma) {
    RomaNumber s;
    s.RomaToArab("D");
    ASSERT_EQ(500, s.GetArabic());
    ASSERT_EQ("D", s.GetRoma());
}

TEST(Test_Roma_Number, Correct_Convert_All_Arab) {
    RomaNumber a1, a2;
    for (int i = 0; i < 4000; ++i) {
        a1.ArabToRoma(i);
        a2.RomaToArab(a1.GetRoma());
        ASSERT_EQ(i, a2.GetArabic());
    }
}

TEST(Test_Roma_Number, Cant_Create_With_Wrong_String) {
    std::string r = "AX";
    ASSERT_ANY_THROW(RomaNumber a(r));
}
