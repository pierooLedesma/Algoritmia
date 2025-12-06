//
// Created by lpier on 5/12/2025.
//

#ifndef ARBOLAVL_FUNCIONES_HPP
#define ARBOLAVL_FUNCIONES_HPP

#include "Utils.hpp"
#include "Nodo.hpp"

int calcular_altura(struct Nodo *arbolAVL);
int factor_balance(struct Nodo *arbolAVL);
struct Nodo * rotar(struct Nodo *arbolAVL);
struct Nodo * insertarAVL(struct Nodo *& arbolAVL, int clave);
int contar_nodos(struct Nodo *arbolAVL);
double calcular_mediana(struct Nodo *arbolAVL);
struct Nodo * buscarPorPosicion(struct Nodo *arbolAVL, int &posicion);

void mostrar_en_orden(struct Nodo *arbolAVL);
void imprimir_nodo(struct Nodo *nodo);
bool esNodoVacio(struct Nodo *nodo);

#endif //ARBOLAVL_FUNCIONES_HPP

