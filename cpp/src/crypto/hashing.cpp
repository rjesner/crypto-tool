#include "../../include/hashing.h"

std::string calc_sha256(std::string input_str) {
    const char* str = input_str.c_str();
    size_t len = strlen(str);

    char* sha256 = calc_sha256(str, len);
    std::string result = std::string(sha256);
    delete[] sha256;

    return result;
}