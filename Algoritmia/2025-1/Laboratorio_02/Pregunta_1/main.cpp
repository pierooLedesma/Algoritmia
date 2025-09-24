

// Archivo: main.cpp
// Autor:   PieroLG
// Fecha:   Martes 23 de septiembre del 2025

#include "BibliotecaLista/Funciones.hpp"

int main() {
    struct Lista listaDeCuadrigas;

    construir(listaDeCuadrigas);
    ingreso_de_datos(listaDeCuadrigas, "Data/datos.txt");
    cout << "Lista inicial:" << endl;
    imprimir(listaDeCuadrigas);

    cout << endl << endl;

    ordenar_la_lista(listaDeCuadrigas);
    cout << "Lista final:" << endl;
    imprimir(listaDeCuadrigas);
    return 0;
}