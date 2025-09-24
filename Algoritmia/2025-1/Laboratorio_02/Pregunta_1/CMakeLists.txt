cmake_minimum_required(VERSION 4.0)
project(Pregunta_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta_1 main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Funciones.cpp
        BibliotecaLista/Funciones.hpp
        BibliotecaLista/Utils.hpp)
