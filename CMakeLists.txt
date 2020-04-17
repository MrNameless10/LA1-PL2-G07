cmake_minimum_required(VERSION 3.15)
project(LA1_PL2_G07 C)

set(CMAKE_C_STANDARD 99)

add_executable(LA1_PL2_G07 main.c main.c dados.c dados.h logica.c logica.h interface.c listas.c listas.h)

target_link_libraries(LA1_PL2_G07 m)