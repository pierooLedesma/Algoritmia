

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Sábado 6 de septiembre del 2025.
 */

#include "Biblioteca/Funciones.hpp"

int main() {
    int tablas[MAX_TABLAS] = {150, 100, 80, 50, 120, 10};
    int discos[MAX_DISCOS] = {250, 200, 200};
    int la_mejor_solucion[MAX_TABLAS]{};
    int indice_mejor_disco, velocidad_mas_grande_de_las_minimas_velocidades;

    calcular_la_solucion_optima(MAX_DISCOS, MAX_TABLAS, tablas, discos,
                                la_mejor_solucion, indice_mejor_disco,
                                velocidad_mas_grande_de_las_minimas_velocidades);
    imprimir_solucion_optima(la_mejor_solucion, MAX_DISCOS, MAX_TABLAS,
                             velocidad_mas_grande_de_las_minimas_velocidades, indice_mejor_disco);
    return 0;
}

