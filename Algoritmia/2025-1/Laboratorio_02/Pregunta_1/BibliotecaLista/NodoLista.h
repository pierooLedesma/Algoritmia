//Fecha:  sábado 06 Setiembre 2025
//Autor: Ana Roncal

#ifndef PREGUNTA_1_NODOLISTA_H
#define PREGUNTA_1_NODOLISTA_H
#include "ElementoLista.h"
struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista * siguiente;
};
#endif //PREGUNTA_1_NODOLISTA_H