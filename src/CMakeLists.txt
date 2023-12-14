cmake_minimum_required(VERSION 3.10)
project(SD VERSION 1.0 LANGUAGES CXX)

add_executable(SD)

target_sources(SD
    PRIVATE
        SD.cpp
)

find_package(SEAL 3.7 REQUIRED)
target_link_libraries(SD SEAL::seal keccak)
