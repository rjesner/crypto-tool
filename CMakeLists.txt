cmake_minimum_required(VERSION 3.25.1)
project(crypto-tool)

add_executable(crypto-tool
    cpp/src/main.cpp
    cpp/src/crypto/hashing.cpp)

include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/Rust)
ExternalProject_Add(
    rust_sdk
    DOWNLOAD_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND cargo build COMMAND cargo build --release
    BINARY_DIR "${CMAKE_SOURCE_DIR}/rust"
    INSTALL_COMMAND ""
    LOG_BUILD ON
)
add_dependencies(crypto-tool rust_sdk)

target_link_libraries(crypto-tool
    debug "${CMAKE_SOURCE_DIR}/rust/target/debug/librust_sdk.a"
    optimized "${CMAKE_SOURCE_DIR}/rust/target/release/librust_sdk.a"
#    ws2_32
#    userenv
#    advapi32
)

set_target_properties(crypto-tool PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)