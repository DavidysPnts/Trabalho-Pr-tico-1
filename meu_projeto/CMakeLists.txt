cmake_minimum_required(VERSION 3.14)
project(hotel_system VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Avisos de compilação
add_compile_options(-Wall -Wextra)

# Arquivos fonte
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(hotel_system ${SOURCES})
target_include_directories(hotel_system PRIVATE src)