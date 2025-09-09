cmake_minimum_required(VERSION 4.0)
project(Parte_B)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_B main.cpp
        Biblioteca/Utils.hpp
        Biblioteca/Recurso_de_Seguridad.hpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.hpp)
