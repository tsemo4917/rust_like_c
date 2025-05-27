cmake_minimum_required(VERSION 3.5.0)
project(rust_like_c VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

add_executable(rust_like_c src/main.c)

include(CTest)
enable_testing()

