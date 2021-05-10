// Copyright 2021 Gurylev Nikita

#include <gtest/gtest.h>

#include <string>

#include "include/romanumber.h"

TEST(Test_Roma_Number, Create_Roma_Number) {
    ASSERT_NO_THROW(RomaNumber a);
}

TEST(Test_Roma_Number, Correct_Create_Empty_Roma_Number) {
    RomaNumber a;
    ASSERT_EQ(0, a.getArabic());
    ASSERT_EQ("", a.getRoma());
}

TEST(Test_Roma_Number, Create_With_Arab) {
    ASSERT_NO_THROW(RomaNumber a(55));
}

TEST(Test_Roma_Number, Cant_Create_With_Big_Arab) {
    ASSERT_ANY_THROW(RomaNumber a(10000));
}

TEST(Test_Roma_Number, Cant_Create_With_Negative_Number) {
    ASSERT_ANY_THROW(RomaNumber a(-3));
}

TEST(Test_Roma_Number, Correct_Convert_Arab) {
    RomaNumber s;
    s.arabToRoma(3);
    ASSERT_EQ(3, s.getArabic());
    ASSERT_EQ("III", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab2) {
    RomaNumber s;
    s.arabToRoma(49);
    ASSERT_EQ(49, s.getArabic());
    ASSERT_EQ("XLIX", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab3) {
    RomaNumber s;
    s.arabToRoma(978);
    ASSERT_EQ(978, s.getArabic());
    ASSERT_EQ("CMLXXVIII", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Arab4) {
    RomaNumber s;
    s.arabToRoma(2395);
    ASSERT_EQ(2395, s.getArabic());
    ASSERT_EQ("MMCCCXCV", s.getRoma());
}

TEST(Test_Roma_Number, Cant_Convert_Too_Big_Arab) {
    RomaNumber s;
    ASSERT_ANY_THROW(s.arabToRoma(4001));
}

TEST(Test_Roma_Number, Can_Create_With_String) {
    ASSERT_NO_THROW(RomaNumber a("XX"));
}

TEST(Test_Roma_Number, Correct_Create_With_String) {
    std::string r = "VIII";
    RomaNumber a(r);
    ASSERT_EQ("VIII", a.getRoma());
    ASSERT_EQ(8, a.getArabic());
}

TEST(Test_Roma_Number, Correct_Convert_Roma1) {
    RomaNumber s;
    s.romaToArab("I");
    ASSERT_EQ(1, s.getArabic());
    ASSERT_EQ("I", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma2) {
    RomaNumber s;
    s.romaToArab("V");
    ASSERT_EQ(5, s.getArabic());
    ASSERT_EQ("V", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma3) {
    RomaNumber s;
    s.romaToArab("X");
    ASSERT_EQ(10, s.getArabic());
    ASSERT_EQ("X", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma4) {
    RomaNumber s;
    s.romaToArab("L");
    ASSERT_EQ(50, s.getArabic());
    ASSERT_EQ("L", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma5) {
    RomaNumber s;
    s.romaToArab("C");
    ASSERT_EQ(100, s.getArabic());
    ASSERT_EQ("C", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma6) {
    RomaNumber s;
    s.romaToArab("D");
    ASSERT_EQ(500, s.getArabic());
    ASSERT_EQ("D", s.getRoma());
}

TEST(Test_Roma_Number, Correct_Convert_Roma7) {
    RomaNumber s;
    s.romaToArab("M");
    ASSERT_EQ(1000, s.getArabic());
    ASSERT_EQ("M", s.getRoma());
}

TEST(Test_Roma_Number, Cant_Create_With_Wrong_String) {
    std::string r = "AX";
    ASSERT_ANY_THROW(RomaNumber a(r));
}
