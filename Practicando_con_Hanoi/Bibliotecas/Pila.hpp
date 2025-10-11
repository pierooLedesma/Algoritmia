//
// Created by lpier on 10/10/2025.
//

#ifndef DUDUDU_HANOI_PILA_HPP
#define DUDUDU_HANOI_PILA_HPP

struct ElementoPila {
    int numero;   // representa el tamaño del disco
};

struct NodoPila {
    ElementoPila elemento;
    NodoPila* siguiente;
};

struct Pila {
    NodoPila* inicio; // tope de la pila
};

#endif //DUDUDU_HANOI_PILA_HPP