cmake_minimum_required(VERSION 4.0)
project(DuDuDu_Hanoi)

set(CMAKE_CXX_STANDARD 20)

add_executable(DuDuDu_Hanoi main.cpp
        Bibliotecas/FuncionesPila.hpp
        Bibliotecas/Pila.hpp
        Bibliotecas/Pila.cpp
        Bibliotecas/Hanoi.cpp
        Bibliotecas/Hanoi.hpp)
