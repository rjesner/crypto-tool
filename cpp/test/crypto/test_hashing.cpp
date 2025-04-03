#include "gtest/gtest.h"
#include "crypto/hashing.hpp"
#include "utils.hpp"
#include <string>

TEST(CalcSha256Test, ValidInput) {
    std::string input = "Hello, world!";
    std::string expected_output = "315f5bdb76d078c43b8ac0064e4a0164612b1fce77c869345bfc94c75894edd3";
    Hashing hashing;
    Utils utils;
    std::string actual_output = utils.get_string_from_vector(hashing.calc_sha256(utils.get_vector_from_string(input)));
    EXPECT_EQ(expected_output, actual_output);
}

TEST(CalcSha256Test, EmptyInput) {
    std::string input = "";
    std::string expected_output = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
    Hashing hashing;
    Utils utils;
    std::string actual_output = utils.get_string_from_vector(hashing.calc_sha256(utils.get_vector_from_string(input)));
    EXPECT_EQ(expected_output, actual_output);
}

TEST(CalcSha256Test, SingleCharacterInput) {
    std::string input = "a";
    std::string expected_output = "ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb";
    Hashing hashing;
    Utils utils;
    std::string actual_output = utils.get_string_from_vector(hashing.calc_sha256(utils.get_vector_from_string(input)));
    EXPECT_EQ(expected_output, actual_output);
}

TEST(CalcSha256Test, LongInput) {
    std::string input = "The quick brown fox jumps over the lazy dog";
    std::string expected_output = "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592";
    Hashing hashing;
    Utils utils;
    std::string actual_output = utils.get_string_from_vector(hashing.calc_sha256(utils.get_vector_from_string(input)));
    EXPECT_EQ(expected_output, actual_output);
}

TEST(CalcSha256Test, SpecialCharacters) {
    std::string input = "12345!@#$%^&*()_+";
    std::string expected_output = "64c3b9259089e0713502c4ab0ba42bb1ab29ede04411e8a37d3e372fb29c6f00";
    Hashing hashing;
    Utils utils;
    std::string actual_output = utils.get_string_from_vector(hashing.calc_sha256(utils.get_vector_from_string(input)));
    EXPECT_EQ(expected_output, actual_output);
}