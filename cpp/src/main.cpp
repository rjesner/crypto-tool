#include <iostream>
#include <cstring>

extern "C" {
    char* calc_sha256(const char* input_str, size_t input_len);
}

int main(void) {
    const char* str = "Hello World!";
    size_t len = std::strlen(str);

    char* sha256 = calc_sha256(str, len);
    std::cout << "SHA256: " << sha256 << std::endl;

    delete[] sha256;

    return 0;
}
