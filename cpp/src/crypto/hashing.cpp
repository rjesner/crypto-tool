#include "crypto/hashing.hpp"

std::vector<uint8_t> Hashing::calc_sha256(std::vector<uint8_t> input_array) {
    char* str = reinterpret_cast<char *>(&input_array[0]);
    size_t len = input_array.size();

    char* sha256 = ::calc_sha256(str, len);
    std::vector<uint8_t> result(sha256, sha256 + strlen(sha256));
    delete[] sha256;

    return result;
}
