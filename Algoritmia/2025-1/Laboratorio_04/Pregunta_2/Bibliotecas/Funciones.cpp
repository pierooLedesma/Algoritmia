//
// Created by lpier on 14/11/2025.
//

#include "Funciones.hpp"


/*******************************************************************************************/
/*****************  Funciones para el ordenamiento del arreglo "lotes" *********************/
/*******************************************************************************************/


// El ordenamiento tiene de complejidad M*N*log(N).
void ordenar_lotes(char * lotes, int cantidad_lotes, int cantidad_productos) {
    for (int indice = 0; indice < cantidad_lotes; indice++) { // El recorrido de los lotes es O(M).
        int indice_inicial = indice * cantidad_productos;
        int indice_final = indice * cantidad_productos + cantidad_productos - 1;
        mergeSort(lotes, indice_inicial, indice_final); // Complejidad N*log(N)
    }
}


// El "mergeSort" tiene complejidad N*log(N).
void mergeSort(char * arreglo, int inicio, int final) {
    // Caso base
    if (inicio == final) return;

    // Centro
    int centro = (inicio + final) / 2;
    mergeSort(arreglo, inicio, centro);
    mergeSort(arreglo, centro + 1, final);
    merge(arreglo, inicio, centro, final);
}


// El "merge" tiene de complejidad O(N).
void merge(char * arreglo, int inicio, int centro, int final) {
    int tamano = final - inicio + 1;
    char temporal[tamano];

    // Copiar los datos del arreglo en temporal.
    for (int i = 0; i < tamano; i++) temporal[i] = arreglo[inicio + i];

    int izquierda = 0;
    int derecha = centro - inicio + 1;
    for (int indice = 0; indice < tamano; indice++) {
        if (derecha <= final - inicio) // Verificar derecha
            if (izquierda <= centro - inicio) // Verificar izquierda
                if (temporal[izquierda] < temporal[derecha])
                    arreglo[indice + inicio] = temporal[derecha++];
                else
                    arreglo[indice + inicio] = temporal[izquierda++];
            else
                arreglo[indice + inicio] = temporal[derecha++];
        else
            arreglo[indice + inicio] = temporal[izquierda++];
    }
}




/*******************************************************************************************/
/******************  Funciones para la clasificación de los "lotes" ************************/
/*******************************************************************************************/

// La complejidad es O(M*log(N))
void funcion_de_clasificacion(char * lotes, int cantidad_lotes,
                              int cantidad_productos, double porcentaje_minimo) {
    int indice_inicial, indice_final, tamano_real_lote, cantidad_productos_correctos, contar_ceros;
    for (int indice = 0; indice < cantidad_lotes; indice++) { // El recorrido de los lotes es O(M).
        cout << "Lote " << indice + 1 << ": ";
        indice_inicial = indice * cantidad_productos;
        indice_final = indice * cantidad_productos + cantidad_productos - 1;

        cantidad_productos_correctos = contar_caracteres(lotes, 'C', indice_inicial, indice_final); // O(log(N))
        contar_ceros = contar_caracteres(lotes, '0', indice_inicial, indice_final); // O(log(N))
        tamano_real_lote = indice_final - contar_ceros - indice_inicial + 1;

        cout << cantidad_productos_correctos << "  ";
        double porcentaje_lote = (double) cantidad_productos_correctos / tamano_real_lote;
        if (porcentaje_lote >= porcentaje_minimo) {
            cout << "Aprobado" << endl;
        } else {
            cout << "Rechazado" << endl;
        }
    }
}


// La complejidad es O(log(N))
int contar_caracteres(char * arreglo, char clave, int inicio, int final) {
    if (inicio > final) return 0;

    int primera = encontrar_primera_aparicion(arreglo, clave, inicio, final); // O(log(N))

    if (primera == -1) return 0; // No se encontró la clave

    int ultima = encontrar_ultima_aparicion(arreglo, clave, inicio, final); // O(log(N))

    return ultima - primera + 1;
}



// Se realiza una búsqueda binaria para encontrar la primera aparición de la "clave". Es O(log(N)).
int encontrar_primera_aparicion(char * arreglo, char clave, int inicio, int final) {
    if (inicio > final) return -1;

    int centro = (inicio + final) / 2;

    if (arreglo[centro] == clave) {
        // Verificar si es la primera aparición
        int izquierda = encontrar_primera_aparicion(arreglo, clave, inicio, centro - 1);
        return (izquierda == -1) ? centro : izquierda;
    }
    else if (arreglo[centro] > clave) {
        return encontrar_primera_aparicion(arreglo, clave, centro + 1, final);
    }
    else {
        return encontrar_primera_aparicion(arreglo, clave, inicio, centro - 1);
    }
}



// Se realiza una búsqueda binaria para encontrar la última aparición de la "clave". Es O(log(N)).
int encontrar_ultima_aparicion(char * arreglo, char clave, int inicio, int final) {
    if (inicio > final) return -1;

    int centro = (inicio + final) / 2;

    if (arreglo[centro] == clave) {
        // Verificar si es la última aparición
        int derecha = encontrar_ultima_aparicion(arreglo, clave, centro + 1, final);
        return (derecha == -1) ? centro : derecha;
    }
    else if (arreglo[centro] > clave) {
        return encontrar_ultima_aparicion(arreglo, clave, centro + 1, final);
    }
    else {
        return encontrar_ultima_aparicion(arreglo, clave, inicio, centro - 1);
    }
}


