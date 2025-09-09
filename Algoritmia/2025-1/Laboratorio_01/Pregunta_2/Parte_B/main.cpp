

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Lunes 8 de septiembre del 2025
 */

#include "Biblioteca/Funciones.hpp"

int main() {
    int presupuesto, seguridad_minima;
    ingresar_presupuesto_y_seguridad_minima_del_usuario(presupuesto, seguridad_minima);

    struct Recurso_de_Seguridad recursos[MAX_RECURSOS] {
        {50, {-1, -1, -1}, 120},
        {40, {-1, -1, -1}, 110},
        {80, {-1, -1, -1}, 140},
        {70, {0, -1, -1}, 130},
        {85, {0, -1, -1}, 160},
        {140, {0, 1, -1}, 250},
        {55, {1, -1, -1}, 100},
        {130, {1, 2, -1}, 240},
        {30, {-1, -1, -1}, 90},
        {150, {0, 1, 4}, 300}
    };

    procesarCombinaciones(presupuesto, seguridad_minima, recursos);

    return 0;
}

