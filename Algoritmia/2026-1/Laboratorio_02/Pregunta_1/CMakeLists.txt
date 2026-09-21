cmake_minimum_required(VERSION 4.2)
project(Pregunta_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta_1 main.cpp
        BibliotecaLista/ElementoLista.hpp
        BibliotecaLista/Estructuras.hpp
        BibliotecaLista/NodoLista.hpp
        BibliotecaLista/Lista.hpp
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.hpp
        BibliotecaBarajas/funcionesBarajas.cpp
        BibliotecaBarajas/funcionesBarajas.hpp)
