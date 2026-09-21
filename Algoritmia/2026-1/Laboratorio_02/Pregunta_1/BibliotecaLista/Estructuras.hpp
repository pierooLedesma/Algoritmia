//Autor: PieroLG

#ifndef PREGUNTA_1_ESTRUCTURAS_HPP
#define PREGUNTA_1_ESTRUCTURAS_HPP

// Cada carta debe representarse como:

struct Carta {
    int numero;   // Para números del 1 a 13
    char palo;    // 'C', 'D', 'T', 'E'
};

// La baraja es una lista enlazada con:

struct NodoBaraja {
    Carta carta;
    NodoBaraja* siguiente;
};

struct Baraja {
    NodoBaraja *inicio;
    NodoBaraja *fin;
    int longitud;
};

#endif //PREGUNTA_1_ESTRUCTURAS_HPP
