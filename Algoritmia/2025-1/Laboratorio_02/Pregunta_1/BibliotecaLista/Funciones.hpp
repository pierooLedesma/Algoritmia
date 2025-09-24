

// Archivo: Funciones.hpp
// Autor:   PieroLG
// Fecha:   Martes 23 de septiembre del 2025

#ifndef PREGUNTA_1_FUNCIONES_HPP
#define PREGUNTA_1_FUNCIONES_HPP

#include "funcionesLista.h"

void ingreso_de_datos(struct Lista &listaTAD, const char* nombre_archivo);
void aperturar_archivo_lectura(const char* nombre_archivo, ifstream &input);
void leer_una_cuadriga(struct ElementoLista &cuadriga, ifstream &input);
void ordenar_la_lista(struct Lista &listaDeCuadrigas);
void comprobar_pares_de_punteros(struct NodoLista *&ptr_inicio, struct NodoLista *&ptr_final,
                                 struct NodoLista *recorrido, bool &es_el_primero);

#endif //PREGUNTA_1_FUNCIONES_HPP