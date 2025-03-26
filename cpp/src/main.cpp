#include <iostream>
#include <cstring>

#include "../include/hashing.h"

int main(void) {
    std::string message = "Hello World!";
    std::cout << "SHA256: " << calc_sha256(message) << std::endl;
    return 0;
}
