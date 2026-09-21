//Autor: PieroLG

#include <iostream>
#include <iomanip>
#include "funcionesLista.hpp"
#include "Estructuras.hpp"
using namespace std;

void construir(struct Baraja & listaTAD) {
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
    listaTAD.fin = nullptr;
}

bool esListaVacia(const struct Baraja & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Baraja & listaTAD, const struct Carta & elemento) {

    struct NodoBaraja * nuevo;
    nuevo = new struct NodoBaraja;
    nuevo->carta = elemento;
    nuevo->siguiente = listaTAD.inicio;
    listaTAD.inicio = nuevo;
    if (listaTAD.longitud == 0) listaTAD.fin = nuevo;
    listaTAD.longitud++;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarAlFinal(struct Baraja & listaTAD, const struct Carta & elemento) {

    struct NodoBaraja * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoBaraja * nuevo;
    nuevo = new struct NodoBaraja;
    nuevo->carta = elemento;
    nuevo->siguiente = nullptr;

    if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->siguiente = nuevo;
    listaTAD.fin = nuevo;
    listaTAD.longitud++;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoBaraja * obtenerUltimoNodo(const struct Baraja & listaTAD) {
    struct NodoBaraja * ultimo = nullptr;
    struct NodoBaraja* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarEnOrden(struct Baraja & listaTAD, const struct Carta & elemento) {

    struct NodoBaraja *nuevo, *recorrido = listaTAD.inicio, * anterior = nullptr;
    nuevo = new struct NodoBaraja;
    nuevo->carta = elemento;
    while(recorrido){
        if(recorrido->carta.numero > elemento.numero) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if(anterior == nullptr) listaTAD.inicio = nuevo;
    else anterior->siguiente = nuevo;
    if (recorrido == nullptr) listaTAD.fin = nuevo;
    listaTAD.longitud++;
}

void eliminaNodo(struct Baraja & listaTAD, const struct Carta & elemento) {
    struct NodoBaraja * ultimo = nullptr;
    struct NodoBaraja * recorrido = listaTAD.inicio;

    while ((recorrido != nullptr) and (recorrido->carta.numero != elemento.numero) and (recorrido->carta.palo != elemento.palo)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr)
            listaTAD.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        if (recorrido->siguiente == nullptr) listaTAD.fin = ultimo;
        delete recorrido;
    }
    listaTAD.longitud--;
}

/*void destruir(struct Lista & listaTAD) {
    struct NodoBaraja * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        struct NodoBaraja * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    listaTAD.inicio = nullptr;
    listaTAD.fin = nullptr;
    listaTAD.longitud = 0;
}*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Baraja & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "BARAJA VACIA" << endl;
    } else {
        struct NodoBaraja * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        //cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << " ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->carta.numero << recorrido->carta.palo;
            recorrido = recorrido->siguiente;
        }
        cout << endl;
    }
}