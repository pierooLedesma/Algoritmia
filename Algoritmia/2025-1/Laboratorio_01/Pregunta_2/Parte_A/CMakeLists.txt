cmake_minimum_required(VERSION 4.0)
project(Parte_A)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte_A main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.hpp
        Biblioteca/Recurso_de_Seguridad.hpp
        Biblioteca/Utils.hpp)
