//
// Created by lpier on 13/11/2025.
//

#include "Funciones.hpp"


/*
 * Merge Sort divide el arreglo en mitades recursivamente y
 * luego fusiona (merge) cada mitad ordenada.
 * Por eso tiene dos fases principales:
 * Dividir (Divide) -> Partir el arreglo por la mitad hasta que quede de tamaño 1.
 * Combinar (Merge) -> Juntar las mitades ordenadas.
 *
 * El costo:
 * 2 * T(n/2) -> porque se llama recursivamente a Merge Sort sobre las dos mitades.
 * O(n) -> porque la función "merge()" combina los resultados en tiempo lineal.
 * Como en cada paso divides el arreglo a la mitad, el número de niveles es:
 * log2(n) -> log(n)
 * El costo total = costo por nivel * cantidad de niveles:
 * T(n) = O(n)*log(n) -> O(nlog(n))
 */
void mergeSort(int * arreglo, int inicio, int fin) {
    // Caso base
    if (inicio == fin) return;

    // Centro
    int centro = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, centro); // izquierda arreglo
    mergeSort(arreglo, centro + 1, fin); // derecha arreglo
    merge(arreglo, inicio, centro, fin); // juntar todo
}


void merge(int * arreglo, int inicio, int centro, int fin) {
    // Complejidad: O(n) en tiempo y O(n) en espacio adicional.
    int tamano = fin - inicio + 1;
    int temporal[tamano];

    // Se copian los elementos de "arreglo" en el arreglo "temporal".
    for (int  i = 0; i < tamano; i++) {
        temporal[i] = arreglo[inicio + i];
    }

    // Los bordes del arreglo que se trabajará.
    int izquierda = 0;
    int derecha = centro - inicio + 1;

    for (int indice = 0; indice < tamano; indice++) {
        if (derecha <= fin - inicio) // Verifica derecha
            if (izquierda <= centro - inicio) // Verifica izquierda
                // Para ordenarlo de forma descendente: if (temporal[izquierda] < temporal[derecha])
                // Para ordenarlo de forma ascendente: if (temporal[izquierda] > temporal[derecha])
                if (temporal[izquierda] > temporal[derecha])
                    arreglo[inicio + indice] = temporal[derecha++];
                else
                    arreglo[inicio + indice] = temporal[izquierda++];
            else
                arreglo[inicio + indice] = temporal[derecha++];
        else
            arreglo[inicio + indice] = temporal[izquierda++];
    }
}


int busquedaBinaria(int * arreglo, int clave, int inicio, int fin) {
    // Caso base
    if (inicio > fin) return -1;

    int centro = (inicio + fin) / 2;
    if (arreglo[centro] == clave) return centro;

    // Si el arreglo está ordenado ascendentemente:
    else if (arreglo[centro] < clave) return busquedaBinaria(arreglo, clave, centro + 1, fin);
    // Si el arreglo está ordenado descendentemente:
    // else if (arreglo[centro] > clave) return busquedaBinaria(arreglo, clave, centro + 1, fin);

    else return busquedaBinaria(arreglo, clave, inicio, centro - 1);
}


void imprime(int * arreglo, int longitud) {
    for (int i=0; i<longitud; i++) cout << arreglo[i] << ' ';
    cout << endl;
}

