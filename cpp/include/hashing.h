#ifndef _HASHING_H_

#include <string>
#include <vector>

#ifdef __cplusplus
    extern "C"  {
#endif

#include <cstddef>
#include <cstring>

char* calc_sha256(const char* input_str, size_t input_len);

#ifdef __cplusplus
    }
#endif

std::string calc_sha256(std::string input_str);

    #define _HASHING_H_
#endif