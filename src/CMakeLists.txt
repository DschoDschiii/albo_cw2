cmake_minimum_required(VERSION 3.10)
project(SD VERSION 1.0 LANGUAGES CXX)

message("Sub-dir included!")

set(PLAIN_SRCS ${PLAIN_SRCS}
    SD.cpp
)

add_executable(SD "SD.cpp")

find_package(SEAL 3.7 REQUIRED)
target_link_libraries(SD SEAL::seal keccak)


# include 
# /home/gorg/Code/TMP/Implementation/thirdparty/ciphers/pasta_3/seal/pasta_3_seal.cpp
# /home/gorg/Code/TMP/Implementation/thirdparty/thirdparty/SEAL/native/src/seal/seal.h
