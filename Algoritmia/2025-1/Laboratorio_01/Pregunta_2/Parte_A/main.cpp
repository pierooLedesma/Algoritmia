

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Domingo 7 de septiembre del 2025
 */

#include "Biblioteca/Funciones.hpp"

int main() {
    int presupuesto;
    presupuesto = ingresar_presupuesto_del_usuario();

    struct Recurso_de_Seguridad recursos[MAX_RECURSOS] {
        {50, {-1, -1, -1}},
        {40, {-1, -1, -1}},
        {80, {-1, -1, -1}},
        {70, {0, -1, -1}},
        {85, {0, -1, -1}},
        {140, {0, 1, -1}},
        {55, {1, -1, -1}},
        {130, {1, 2, -1}},
        {30, {-1, -1, -1}},
        {150, {0, 1, 4}}
    };

    procesarCombinaciones(presupuesto, recursos);

    return 0;
}