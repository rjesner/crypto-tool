#ifndef _HASHING_H_

#include <string>
#include <vector>

#ifdef __cplusplus
    extern "C"  {
#endif

#include <cstddef>
#include <cstring>
#include <cstdint>

char* calc_sha256(const char* input_str, size_t input_len);

#ifdef __cplusplus
    }
#endif

class Hashing {
    public:

    std::vector<uint8_t> calc_sha256(std::vector<uint8_t> input_array);
};

    #define _HASHING_H_
#endif