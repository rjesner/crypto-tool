cmake_minimum_required(VERSION 3.25.1)
project(crypto-tool)

enable_testing()

add_executable(crypto-tool
    "${CMAKE_SOURCE_DIR}/cpp/src/utils.cpp"
    "${CMAKE_SOURCE_DIR}/cpp/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/cpp/src/crypto/hashing.cpp")
add_executable(test_runner
    "${CMAKE_SOURCE_DIR}/cpp/src/utils.cpp"
    "${CMAKE_SOURCE_DIR}/cpp/src/crypto/hashing.cpp"
    "${CMAKE_SOURCE_DIR}/cpp/test/test_main.cpp"
    "${CMAKE_SOURCE_DIR}/cpp/test/crypto/test_hashing.cpp")

target_include_directories(crypto-tool PUBLIC cpp/include)
target_include_directories(test_runner PUBLIC cpp/include)

target_compile_options(crypto-tool PUBLIC "-std=c++14")
target_compile_options(test_runner PUBLIC "-std=c++14")

add_test(NAME crypto-tests COMMAND test_runner)

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
)
target_link_libraries(test_runner
    debug "${CMAKE_SOURCE_DIR}/rust/target/debug/librust_sdk.a"
    optimized "${CMAKE_SOURCE_DIR}/rust/target/release/librust_sdk.a"
    "${CMAKE_SOURCE_DIR}/cpp/lib/crypto/libgtest.a"
    "${CMAKE_SOURCE_DIR}/cpp/lib/crypto/libgmock.a"
)

set_target_properties(crypto-tool PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)