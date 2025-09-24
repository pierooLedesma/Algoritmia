

// Archivo: Funciones.cpp
// Autor:   PieroLG
// Fecha:   Martes 23 de septiembre del 2025

#include "Funciones.hpp"


// Módulo que apertura un archivo de lectura sin usar el constructor.
void aperturar_archivo_lectura(const char* nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que ingresa datos de un archivo CSV.
void ingreso_de_datos(struct Lista &listaTAD, const char* nombre_archivo) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);
    while (true) {
        struct ElementoLista cuadriga;
        leer_una_cuadriga(cuadriga, input);
        if (input.eof()) break; // Fin del archivo.
        insertarAlFinal(listaTAD, cuadriga);
    }
}


// Módulo que lee una cuadriga (datos del problema).
void leer_una_cuadriga(struct ElementoLista &cuadriga, ifstream &input) {
    int id;
    input >> id;
    if (input.eof()) return; // No hay más datos a leer en el archivo CSV.
    cuadriga.id = id;
    input.get(); // Lectura de la coma
    input.getline(cuadriga.nombre, 20, ',');
    input.getline(cuadriga.equipo, 15, '\n');
}



// Módulo que ordena la lista de cuadrigas separando primero los nodos con ID par,
// y luego los nodos con ID impar. Al final, los une en una sola lista.
void ordenar_la_lista(struct Lista &listaDeCuadrigas) {
    struct NodoLista *parInicio;     // Apunta al inicio de la sublista de pares.
    struct NodoLista *parFinal;      // Apunta al último nodo de la sublista de pares.
    bool primer_par = true;          // Bandera para detectar el primer nodo par.
    bool primer_impar = true;        // Bandera para detectar el primer nodo impar.
    struct NodoLista *imparInicio;   // Apunta al inicio de la sublista de impares.
    struct NodoLista *imparFinal;    // Apunta al último nodo de la sublista de impares.
    struct NodoLista *recorrido = listaDeCuadrigas.inicio; // Puntero para recorrer la lista original.

    // Recorrer toda la lista nodo por nodo
    while (recorrido) {
        if (recorrido->elemento.id % 2 == 0) {
            // Si el ID es par, se inserta en la sublista de pares
            comprobar_pares_de_punteros(parInicio, parFinal, recorrido, primer_par);
        } else {
            // Si el ID es impar, se inserta en la sublista de impares
            comprobar_pares_de_punteros(imparInicio, imparFinal, recorrido, primer_impar);
        }
        recorrido = recorrido->siguiente; // Avanzar al siguiente nodo
    }

    // Conectar el final de la lista de pares con el inicio de la lista de impares
    parFinal->siguiente = imparInicio;

    // El último nodo impar debe apuntar a NULL
    imparFinal->siguiente = nullptr;

    // El inicio de la lista general pasa a ser el inicio de la sublista de pares
    listaDeCuadrigas.inicio = parInicio;
}




// Módulo auxiliar que ayuda a enlazar nodos dentro de la sublista correspondiente.
// Mantiene punteros al inicio y final de cada sublista (pares o impares).
void comprobar_pares_de_punteros(struct NodoLista *&ptr_inicio, struct NodoLista *&ptr_final,
                                 struct NodoLista *recorrido, bool &es_el_primero) {
    if (es_el_primero) {             // Caso especial: primer nodo de la sublista
        ptr_inicio = recorrido;      // Se define el inicio
        ptr_final = ptr_inicio;      // También el final apunta al mismo
        es_el_primero = false;       // Ya no es el primer nodo
    } else {                         // Caso general: ya hay elementos en la sublista
        ptr_final->siguiente = recorrido; // Se enlaza al final actual
        ptr_final = recorrido;            // Se actualiza el final
    }
}


