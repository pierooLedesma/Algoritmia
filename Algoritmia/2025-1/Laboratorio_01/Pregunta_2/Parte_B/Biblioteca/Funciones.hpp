

/*
 * Archivo: Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Lunes 8 de septiembre del 2025
 */

#ifndef PARTE_B_FUNCIONES_HPP
#define PARTE_B_FUNCIONES_HPP

#include "Utils.hpp"

void ingresar_presupuesto_y_seguridad_minima_del_usuario(int &presupuesto, int &seguridad_minima);
void cargar_combinaciones(int numero, int base, int *combinaciones);
void procesarCombinaciones(const int presupuesto, const int seguridad_minima,
                           const struct Recurso_de_Seguridad *recursos);
void imprimir_combinacion(const int iteracion, const int *combinaciones, const int cant_recursos,
                          const int costo_total, const int seguridad_total);

#endif //PARTE_B_FUNCIONES_HPP