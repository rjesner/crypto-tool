#ifndef _UTILS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

class Utils {
    public:
    
    std::vector<uint8_t> read_binary_file(const std::string& filename);
    std::string get_string_from_vector(const std::vector<uint8_t>& data);
    std::vector<uint8_t> get_vector_from_string(const std::string data);
};

    #define _UTILS_H_
#endif