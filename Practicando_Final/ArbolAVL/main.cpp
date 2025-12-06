

#include "BibliotecaArbolAVL/Funciones.hpp"

int main() {
    // Verificación del recorrido y de la inserción en un árbol AVL.
    int dnis[]={72649318, 50823147, 81234567, 40987654, 65012345, 94561237, 30124598};
    int cant_dnis = sizeof(dnis)/sizeof(int);
    struct Nodo *arbolAVL = nullptr;
    for (int i = 0; i < cant_dnis; i++) arbolAVL = insertarAVL(arbolAVL,dnis[i]);
    mostrar_en_orden(arbolAVL);


    // Verificación de la mediana.
    double mediana = calcular_mediana(arbolAVL);
    cout << "\nLa mediana es " << mediana << endl;


    // Verificación de encontrar un nodo por su posición (OJO: ÍNDICE NO ES LO MISMO QUE POSICIÓN).
    int posicion = 1;
    cout << "\nEn la posicion " << posicion;
    struct Nodo *nodo_encontrado = buscarPorPosicion(arbolAVL, posicion);
    cout << " se encuentra el valor " << nodo_encontrado->valor;
    return 0;
}

