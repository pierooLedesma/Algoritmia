cmake_minimum_required(VERSION 4.0)
project(MergeSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(MergeSort main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp)
