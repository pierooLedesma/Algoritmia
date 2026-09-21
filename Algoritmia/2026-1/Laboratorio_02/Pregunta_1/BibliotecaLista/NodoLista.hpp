//Autor: PieroLG

#ifndef PREGUNTA_1_NODOLISTA_HPP
#define PREGUNTA_1_NODOLISTA_HPP

#include "ElementoLista.hpp"

struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista * siguiente;
};

#endif //PREGUNTA_1_NODOLISTA_HPP
