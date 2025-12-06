//
// Created by lpier on 5/12/2025.
//

#ifndef ARBOLAVL_NODO_HPP
#define ARBOLAVL_NODO_HPP

struct Nodo {
    int valor;
    int altura;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

#endif //ARBOLAVL_NODO_HPP

