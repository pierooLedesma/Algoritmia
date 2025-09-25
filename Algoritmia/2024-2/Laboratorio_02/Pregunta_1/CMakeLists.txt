cmake_minimum_required(VERSION 4.0)
project(Pregunta_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta_1 main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h)
