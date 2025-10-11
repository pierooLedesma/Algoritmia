//
// Created by lpier on 10/10/2025.
//

#ifndef DUDUDU_HANOI_HANOI_HPP
#define DUDUDU_HANOI_HANOI_HPP

void mover_tope(struct Pila &desde, struct Pila &hasta);
void jugando_al_hanoi(int n_discos, struct Pila &pilaInicial,
                      struct Pila &pilaPivote, struct Pila &pilaDestino, int &pasos);
void jugando_al_hanoi_con_4(int n_discos, struct Pila &pilaInicial, struct Pila &pilaPivote,
                            struct Pila &pilaAuxiliar, struct Pila &pilaDestino, int &pasos);

#endif //DUDUDU_HANOI_HANOI_HPP