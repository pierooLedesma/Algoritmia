#include "Bibliotecas/Funciones.hpp"

int main() {
    // Búsqueda Binaria
    int arreglo[] = {90, 65, 7, 305, 120, 110, 8};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "Arreglo inicial" << endl;
    imprime(arreglo, longitud);

    // Ordenar el arreglo con complejidad nlog(n)
    cout << endl << "Ordenar el arreglo usando MergeSort complejidad nlog(n)" << endl;
    mergeSort(arreglo, 0, longitud - 1);
    imprime(arreglo, longitud);

    cout << endl << "Busqueda binaria" << endl;
    int clave = 110;
    cout << "Buscar: " << clave << endl;

    int indice = busquedaBinaria(arreglo, clave, 0, longitud - 1);
    if (indice != -1) {
        cout << "ENCONTRADO" << endl;
    } else {
        cout << "NO ENCONTRADO" << endl;
    }
    return 0;
}

// Enlace para probar el ordenamiento del MergeSort:
// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/

