#include <iostream>
#include <cstring>
#include "CLI/CLI11.hpp"
#include "crypto/hashing.hpp"
#include "utils.hpp"
#include <string>
#include <memory>

int main(int argc, char **argv) {
    CLI::App app("Crypto-Tool by Rodrigo Jesner");

    std::string file;
    std::string output_file;
    std::string encryption_key;
    std::string decryption_key;
    bool crc32_flag = false;
    bool sha256_flag = false;
    bool aes128_gen_flag = false;

    app.add_option("-f,--file", file, "Input file");
    app.add_flag("--crc32", crc32_flag, "Compute CRC32 of the file");
    app.add_flag("--sha256", sha256_flag, "Compute SHA256 of the file");
    app.add_flag("--gaes128", aes128_gen_flag, "Generate a random AES128 key");
    app.add_option("--eaes128", encryption_key, "AES128 key for encryption (hex string)");
    app.add_option("--daes128", decryption_key, "AES128 key for decryption (hex string)");
    app.add_option("-o,--output", output_file, "Output file");

    CLI11_PARSE(app, argc, argv);

    if (argc == 1) {
        std::cout << app.help("");
        return 1;
    }

    try {
        if(crc32_flag || sha256_flag) {
            if (crc32_flag) {
                if (file.empty()) {
                    std::cerr << "File required for CRC32 computation\n";
                    return 1;
                }
            }

            if (sha256_flag) {
                if (file.empty()) {
                    std::cerr << "File required for SHA256 computation\n";
                    return 0;
                }
                std::cout << "[SHA256 of File named " << file << "]" << std::endl;
                Utils utils;
                std::vector<uint8_t> file_content = utils.read_binary_file(file);
                Hashing hashing;

                std::cout << utils.get_string_from_vector(hashing.calc_sha256(file_content)) << std::endl;
            }
        }
        else if(aes128_gen_flag) {
            std::cout << "Generated AES128 Key: " << "Teste" << std::endl;
            return 1;
        }
        else if (!encryption_key.empty()) {
            if (file.empty() || output_file.empty()) {
                std::cerr << "File and output file required for encryption\n";
                return 1;
            }
            std::cout << "[AES Encryption]" << std::endl;
            std::cout << "Key: " << encryption_key << std::endl;
            std::cout << "File: " << file << std::endl;
            std::cout << "Output file: " << output_file  << std::endl;
        }
        else if (!decryption_key.empty()) {
            if (file.empty() || output_file.empty()) {
                std::cerr << "File and output file required for decryption\n";
                return 1;
            }
            std::cout << "[AES Decryption]" << std::endl;
            std::cout << "Key: " << decryption_key << std::endl;
            std::cout << "File: " << file << std::endl;
            std::cout << "Output file: " << decryption_key << std::endl;
        } else {
            std::cout << app.help("");
            return 1;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}