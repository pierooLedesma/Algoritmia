//
// Created by lpier on 14/11/2025.
//

#ifndef PREGUNTA_2_FUNCIONES_HPP
#define PREGUNTA_2_FUNCIONES_HPP

#include "Utils.hpp"

void ordenar_lotes(char * lotes, int cantidad_lotes, int cantidad_productos);
void mergeSort(char * arreglo, int inicio, int final);
void merge(char * arreglo, int inicio, int centro, int final);
void funcion_de_clasificacion(char * lotes, int cantidad_lotes,
                              int cantidad_productos, double porcentaje_minimo);
int contar_caracteres(char * arreglo, char clave, int inicio, int final);
int encontrar_primera_aparicion(char * arreglo, char clave, int inicio, int final);
int encontrar_ultima_aparicion(char * arreglo, char clave, int inicio, int final);

#endif //PREGUNTA_2_FUNCIONES_HPP

