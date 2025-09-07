

/*
 * Archivo Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Sábado 6 de septiembre del 2025.
 */


#ifndef PREGUNTA_1_FUNCIONES_HPP
#define PREGUNTA_1_FUNCIONES_HPP

#include "Utils.hpp"

void cargarCombinacion(int numero, int base, int *combinaciones);
void calcular_la_solucion_optima(int cant_discos, int cant_tablas, int *tablas, int *discos,
                                 int *la_mejor_solucion, int &indice_mejor_disco,
                                 int &velocidad_mas_grande_de_las_minimas_velocidades);
void imprimir_solucion_optima(const int *la_mejor_solucion, const int cant_discos, const int cant_tablas,
                              const int velocidad_mas_grande_de_las_minimas_velocidades,
                              const int indice_mejor_disco);
void titulo_del_cuadro();
void elaborar_lineas();

#endif //PREGUNTA_1_FUNCIONES_HPP