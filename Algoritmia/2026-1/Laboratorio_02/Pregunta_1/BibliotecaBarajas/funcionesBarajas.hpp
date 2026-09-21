//Autor: PieroLG

#ifndef PREGUNTA_1_FUNCIONESBARAJAS_HPP
#define PREGUNTA_1_FUNCIONESBARAJAS_HPP

#include "../BibliotecaLista/Estructuras.hpp"

void crear_baraja(Baraja &baraja);
NodoBaraja* extraer_en_posicion(Baraja &baraja, int posicion);
void barajar(Baraja &baraja);
void destruir(Baraja &baraja);

#endif //PREGUNTA_1_FUNCIONESBARAJAS_HPP
