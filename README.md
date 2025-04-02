# Crypto Tool

Crypto Tool is a command-line tool made by the programmer Rodrigo Jesner to calculate the CRC32 and SHA256 of ROM and ISO files. It also has an option for AES128 calculation over files as a way to encrypt/decrypt them. The project is developed using Rust and C++.

## Plaforms

- Windows
- Linux

# Requisites

- CMake >= 3.25.1
- Rustc/Cargo >= 1.85.1

## Usage

```bash
$> ./crypto-tool --crc32 -f exampleFile.bin # Shows the CRC32 of the file
$> ./crypto-tool --sha256 -f exampleFile.bin # Shows the SHA256 of the file
$> ./crypto-tool --crc32 --sha256 -f exampleFile.bin # Shows both CRC32 and SHA256 of the file
$> ./crypto-tool --gaes128 # Generation of random AES128 key
$> ./crypto-tool --eaes128 c518cb5e31f8be76da0f60963a7f0b21 -f exampleFile.bin -o encryptedFile.bin # Encryption of file using AES128
$> ./crypto-tool --daes128 c518cb5e31f8be76da0f60963a7f0b21 -f encryptedFile.bin -o exampleFile.bin # The reverse of the above
```