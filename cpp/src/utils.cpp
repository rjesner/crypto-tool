#include "utils.hpp"


std::vector<uint8_t> Utils::read_binary_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(fileSize);
    file.read(reinterpret_cast<char*>(buffer.data()), fileSize);

    if (!file) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return {};
    }

    return buffer;
}

std::string Utils::get_string_from_vector(const std::vector<uint8_t>& data) {
    if (data.size() == 0) {
        return "";
    }

    char buffer[2];
    std::ostringstream oss;
    for (size_t i = 0; i < data.size(); ++i) {
        std::sprintf(buffer, "%c", data[i]);
        oss << buffer;
    }
    return oss.str();
}

std::vector<uint8_t> Utils::get_vector_from_string(const std::string data) {
    if (data.empty()) {
        return {};
    }
    std::vector<uint8_t> buffer;
    for (char c : data) {
        buffer.push_back(static_cast<uint8_t>(c));
    }
    return buffer;
}