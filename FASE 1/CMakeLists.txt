cmake_minimum_required(VERSION 3.19)
project(ProjetoFinal C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetoFinal main.c lib-utf8.c aux_.c)

add_compile_options(-Wall -Wextra)