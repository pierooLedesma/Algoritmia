//
// Created by lpier on 10/10/2025.
//
#include <iostream>
#include <stdexcept>
#include "Pila.hpp"
#include "FuncionesPila.hpp"
#include "Hanoi.hpp"
using namespace std;

void mover_tope(struct Pila &desde, struct Pila &hasta) {
    ElementoPila e = desapilar(desde);
    if (!esPilaVacia(hasta)) {
        ElementoPila t = cima(hasta);
        if (e.numero > t.numero) {
            // revertir y reportar
            apilar(desde, e);
            throw runtime_error("Movimiento invalido: disco mayor sobre menor.");
        }
    }
    apilar(hasta, e);
}

void jugando_al_hanoi(int n_discos, struct Pila &pilaInicial,
                      struct Pila &pilaPivote, struct Pila &pilaDestino, int &pasos) {
    if (n_discos == 0) return;
    jugando_al_hanoi(n_discos-1, pilaInicial, pilaDestino, pilaPivote, pasos);
    mover_tope(pilaInicial, pilaDestino);
    ++pasos;
    jugando_al_hanoi(n_discos-1, pilaPivote, pilaInicial, pilaDestino, pasos);
}


void jugando_al_hanoi_con_4(int n_discos, struct Pila &pilaInicial, struct Pila &pilaPivote,
                            struct Pila &pilaAuxiliar, struct Pila &pilaDestino, int &pasos) {
    jugando_al_hanoi(n_discos -1, pilaInicial, pilaPivote, pilaAuxiliar, pasos);
    mover_tope(pilaInicial, pilaDestino);
    pasos++;
    jugando_al_hanoi(n_discos -1, pilaAuxiliar, pilaPivote, pilaDestino, pasos);
}

