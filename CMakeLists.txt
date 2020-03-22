cmake_minimum_required(VERSION 3.15)
project(LA1_PL2_G07 C)

set(CMAKE_C_STANDARD 99)

add_executable(LA1_PL2_G07 main.c "dados.c" "dados.h" "interface.c" "interface.h" "logica.c" "logica.h")