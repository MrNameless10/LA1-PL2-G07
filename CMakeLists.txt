cmake_minimum_required(VERSION 3.15)
project(LAProjeto C)

set(CMAKE_C_STANDARD 99)

add_executable(LAProjeto main.c "camada de dados.c" "camada de dados.h" "logica de programa.c" "logica de programa.h" "camada de interface.c" "camada de interface.h")