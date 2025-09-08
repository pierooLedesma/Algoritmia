

/*
 * Archivo: Funciones.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Domingo 7 de septiembre del 2025
 */

#ifndef PARTE_A_FUNCIONES_HPP
#define PARTE_A_FUNCIONES_HPP

#include "Utils.hpp"

int ingresar_presupuesto_del_usuario();
void cargar_combinaciones(int numero, int base, int *combinaciones);
void procesarCombinaciones(const int presupuesto, const struct Recurso_de_Seguridad *recursos);
void imprimir_combinacion(const int iteracion, const int *combinaciones,
                          const int cant_recursos, const int costo_total);

#endif //PARTE_A_FUNCIONES_HPP