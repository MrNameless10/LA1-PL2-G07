cmake_minimum_required(VERSION 3.15)
project(LA1_PL2_G07 C)

set(CMAKE_C_STANDARD 99)

add_executable(LA1_PL2_G07 main.c "camada de dados.c" "camada de dados.h" "camada de interface.c" "camada de interface.h" "logica de programa.c" "logica de programa.h")