cmake_minimum_required(VERSION 4.0)
project(ArbolAVL)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolAVL main.cpp
        BibliotecaArbolAVL/Nodo.hpp
        BibliotecaArbolAVL/Funciones.cpp
        BibliotecaArbolAVL/Funciones.hpp
        BibliotecaArbolAVL/Utils.hpp)
