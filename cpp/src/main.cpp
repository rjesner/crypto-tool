#include <iostream>
#include <cstring>

extern "C" {
    char* concat_strings(const char* first_str, size_t first_len, const char* second_str, size_t second_len);
    size_t get_string_length(const char* input_str, size_t str_len);
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";

    size_t len1 = std::strlen(str1);
    size_t len2 = std::strlen(str2);

    char* concatenated_str = concat_strings(str1, len1, str2, len2);
    std::cout << "Concatenated string: " << concatenated_str << std::endl;

    size_t length = get_string_length(str1, len1);
    std::cout << "Length of first string: " << length << std::endl;

    delete[] concatenated_str;

    return 0;
}
