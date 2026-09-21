//Autor: PieroLG

#include <ctime>
#include <cstdlib>
#include "funcionesBarajas.hpp"
#include "../BibliotecaLista/funcionesLista.hpp"
using namespace std;

void insertar_cartas_de_un_tipo(char tipoCarta, Baraja &baraja) {
    Carta carta;
    carta.palo = tipoCarta;
    for (int num_carta = 1; num_carta <= 13; num_carta++) {
        carta.numero = num_carta;
        insertarAlFinal(baraja, carta);
    }
}


void crear_baraja(Baraja &baraja) {
    construir(baraja);

    insertar_cartas_de_un_tipo('C', baraja);
    insertar_cartas_de_un_tipo('D', baraja);
    insertar_cartas_de_un_tipo('T', baraja);
    insertar_cartas_de_un_tipo('E', baraja);
}


NodoBaraja* extraer_en_posicion(Baraja &baraja, int posicion) {
    struct NodoBaraja * recorrido = baraja.inicio;
    struct NodoBaraja * ultimo = nullptr;

    for (int i = 0; i < posicion; i++) {
        ultimo = recorrido;
        if (recorrido != nullptr) recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr)
            baraja.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        if (recorrido->siguiente == nullptr) baraja.fin = ultimo;
        baraja.longitud--;
        return recorrido;
    }
    return nullptr;
}



void barajar(Baraja &baraja) {

    // Recorrer las 52 cartas de la baraja.
    // En cada iteración se extrae una carta de una posición aleatoria
    // de la parte que todavía no ha sido seleccionada.
    for (int i = 0; i < 52; i++) {

        // Inicializar la semilla del generador de números aleatorios.
        srand(time(nullptr));


        // Generar una posición aleatoria dentro del rango de cartas
        // que aún no han sido extraídas. El rango disminuye en cada
        // iteración porque las cartas pendientes se reducen después de cada extracción.
        int pos = rand() % (52 - i);


        // En la última iteración solo queda una carta disponible,
        // por lo que su posición necesariamente debe ser 0.
        if (i==51) pos=0;

        NodoBaraja* nodoExtraido = extraer_en_posicion(baraja, pos);
        if (nodoExtraido != nullptr) {
            Carta cartaExtraida;
            cartaExtraida.numero = nodoExtraido->carta.numero;
            cartaExtraida.palo = nodoExtraido->carta.palo;

            delete nodoExtraido;

            insertarAlFinal(baraja, cartaExtraida);
        }
    }
}



// Modificado de la biblioteca "BibliotecaLista"
void destruir(Baraja &baraja) {

    // Puntero que apunta al inicio de la TAD
    struct NodoBaraja * recorrido = baraja.inicio;

    while (recorrido != nullptr) {
        // "NodoLista" auxiliar que va servir para eliminar los "NodoListas"
        struct NodoBaraja * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }

    // La lista queda vacía
    baraja.inicio = nullptr;
    baraja.fin = nullptr;
    baraja.longitud = 0;
}