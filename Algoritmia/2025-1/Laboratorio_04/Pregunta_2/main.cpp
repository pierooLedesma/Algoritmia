

#include "Bibliotecas/Funciones.hpp"


int main() {
    char lotes[48] = {
        'F', 'F', 'F', 'C', 'C', 'F', '0', '0',
        'C', 'F', 'C', 'C', 'C', 'F', 'C', 'F',
        'F', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
        'C', 'C', 'C', 'C', 'C', 'F', 'C', '0',
        'C', 'F', 'F', 'F', 'F', 'C', '0', '0',
        'C', 'C', 'F', 'C', 'F', 'C', 'C', '0'
    };
    int cantidad_lotes = 6; // El valor de 'M'
    int cantidad_productos = 8; // El valor de 'N'
    double porcentaje_minimo = 0.7; // El valor de 'P'
    ordenar_lotes(lotes, cantidad_lotes, cantidad_productos);
    funcion_de_clasificacion(lotes, cantidad_lotes, cantidad_productos, porcentaje_minimo);
    return 0;
}

