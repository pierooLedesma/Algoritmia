//
// Created by lpier on 5/12/2025.
//

#include "Funciones.hpp"

int calcular_altura(struct Nodo *arbolAVL) {
    if (arbolAVL == nullptr) return 0;
    return arbolAVL->altura;
}

int factor_balance(struct Nodo *arbolAVL) {
    if (arbolAVL == nullptr) return 0;
    int altura_izquierda, altura_derecha;
    altura_izquierda = calcular_altura(arbolAVL->izquierda);
    altura_derecha = calcular_altura(arbolAVL->derecha);
    return altura_izquierda - altura_derecha;
}

struct Nodo * rotar(struct Nodo *& nodo, bool izquierda) {
    struct Nodo *nuevaRaiz;
    struct Nodo *subarbolMovido;

    if (izquierda) {
        // Rotar hacia la izquierda.
        nuevaRaiz = nodo->derecha;
        subarbolMovido = nuevaRaiz->izquierda;
        nuevaRaiz->izquierda = nodo;
        nodo->derecha = subarbolMovido;
    } else {
        // Rotar hacia la derecha.
        nuevaRaiz = nodo->izquierda;
        subarbolMovido = nuevaRaiz->derecha;
        nuevaRaiz->derecha = nodo;
        nodo->izquierda = subarbolMovido;
    }

    // Actualizar alturas.
    nodo->altura = 1 + max(calcular_altura(nodo->izquierda), calcular_altura(nodo->derecha));
    nuevaRaiz->altura = 1 + max(calcular_altura(nuevaRaiz->izquierda), calcular_altura(nuevaRaiz->derecha));
    return nuevaRaiz;
}



struct Nodo * insertarAVL(struct Nodo *& arbolAVL, int clave) {
    // En caso sea el primer nodo a insertar del AVL.
    if (arbolAVL == nullptr) {
        arbolAVL = new Nodo;
        arbolAVL->valor = clave;
        arbolAVL->izquierda = nullptr;
        arbolAVL->derecha = nullptr;
        arbolAVL->altura = 1;
        return arbolAVL;
    }

    // Inserción de ABB normal
    if (clave < arbolAVL->valor) arbolAVL->izquierda = insertarAVL(arbolAVL->izquierda, clave);
    else if (clave > arbolAVL->valor) arbolAVL->derecha = insertarAVL(arbolAVL->derecha, clave);
    else return arbolAVL; // Las claves son iguales, por lo que no se inserta duplicados.


    // 1) Actualizar altura del nodo actual
    arbolAVL->altura = 1 + max(calcular_altura(arbolAVL->izquierda), calcular_altura(arbolAVL->derecha));


    // 2) Calcular el factor de balance
    int fb = factor_balance(arbolAVL);


    // Revisar los 4 casos

    // Caso 1: Caso LL (el subárbol izquierdo está pesado, entonces rotación derecha)
    if (fb > 1 and clave < arbolAVL->izquierda->valor) return rotar(arbolAVL, false);

    // Caso 2: Caso RR (el subárbol derecho está pesado, entonces rotación izquierda)
    if (fb < -1 and clave > arbolAVL->derecha->valor) return rotar(arbolAVL, true);

    // Caso 3: Caso LR (Rotar a la izquierda el hijo izquierdo y rotar a la derecha el nodo actual)
    if (fb > 1 and clave > arbolAVL->izquierda->valor) {
        arbolAVL->izquierda = rotar(arbolAVL->izquierda, true);
        return rotar(arbolAVL, false);
    }

    // Caso 4: Caso RL (Rotar a la derecha el hijo derecho y rotar a la izquierda el nodo actual)
    if (fb < -1 and clave < arbolAVL->derecha->valor) {
        arbolAVL->derecha = rotar(arbolAVL->derecha, false);
        return rotar(arbolAVL, true);
    }

    return arbolAVL;
}



int contar_nodos(struct Nodo *arbolAVL) {
    if (arbolAVL == nullptr) return 0;
    return 1 + contar_nodos(arbolAVL->izquierda) + contar_nodos(arbolAVL->derecha);
}


double calcular_mediana(struct Nodo *arbolAVL) {
    int cantidad_nodos = contar_nodos(arbolAVL);
    if (cantidad_nodos == 0) return 0;
    int posicion = cantidad_nodos/2 + 1;
    if (cantidad_nodos % 2 == 0) {
        int posicion_anterior = posicion - 1;
        struct Nodo * nodo_1 = buscarPorPosicion(arbolAVL, posicion);
        struct Nodo * nodo_2 = buscarPorPosicion(arbolAVL, posicion_anterior);
        return nodo_1->valor + nodo_2->valor;
    } else {
        // La cantidad de nodos es impar.
        struct Nodo * nodo = buscarPorPosicion(arbolAVL, posicion);
        return (double)nodo->valor;
    }
}


struct Nodo* buscarPorPosicion(struct Nodo *arbolAVL, int &posicion) {
    if (arbolAVL == nullptr) return nullptr;

    // Buscar en la izquierda
    struct Nodo* izq = buscarPorPosicion(arbolAVL->izquierda, posicion);
    if (izq != nullptr) return izq;

    // Contar el nodo actual
    posicion--;
    if (posicion == 0) return arbolAVL;

    // Buscar en la derecha
    return buscarPorPosicion(arbolAVL->derecha, posicion);
}



struct Nodo * eliminarNodoAVL(struct Nodo * arbolAVL, int clave) {
    if (arbolAVL == nullptr) return nullptr;
    // Eliminación de un árbol ABB -> buscar la posición a eliminar
    if (arbolAVL->valor > clave) {
        arbolAVL->izquierda = eliminarNodoAVL(arbolAVL->izquierda, clave);
    } else if (arbolAVL->valor < clave) {
        arbolAVL->derecha = eliminarNodoAVL(arbolAVL->derecha, clave);
    } else {
        struct Nodo * auxiliar;
        // No tiene hijos
        if (arbolAVL->derecha == nullptr and arbolAVL->izquierda == nullptr) {
            delete arbolAVL;
            return nullptr;
        }

        // Tiene solo hijo derecho
        if (arbolAVL->derecha != nullptr and arbolAVL->izquierda == nullptr) {
            auxiliar = arbolAVL->derecha;
            delete arbolAVL;
            return auxiliar;
        }

        // Tiene solo hijo izquierdo
        if (arbolAVL->izquierda != nullptr and arbolAVL->derecha == nullptr) {
            auxiliar = arbolAVL->izquierda;
            delete arbolAVL;
            return auxiliar;
        }

        // Tiene dos hijos
        auxiliar = minimoArbol(arbolAVL->derecha); // Mínimo nodo
        arbolAVL->valor = auxiliar->valor;
        arbolAVL->derecha = eliminarNodoAVL(arbolAVL->derecha, auxiliar->valor);
    }


    // Recalcular la altura
    arbolAVL->altura = 1 + max(calcular_altura(arbolAVL->izquierda), calcular_altura(arbolAVL->derecha));

    // Calcular el factor de balance
    int fb = factor_balance(arbolAVL);


    // Realizar el balanceo verificando los 4 casos

    // Caso 1: LL (Subárbol izquierdo está "pesado", entonces rotar hacia la derecha)
    if (fb > 1 and factor_balance(arbolAVL->izquierda) >= 0) {
        return rotar(arbolAVL, false);
    }

    // Caso 2: RR (Subárbol derecho está "pesado", entonces rotar hacia la izquierda)
    if (fb < -1 and factor_balance(arbolAVL->derecha) <= 0) {
        return rotar(arbolAVL, true);
    }

    // Caso 3: LR (Rotar a la izquierda el hijo izquierdo y rotar hacia la derecha el nodo actual)
    if (fb > 1 and factor_balance(arbolAVL->izquierda) < 0) {
        arbolAVL->izquierda = rotar(arbolAVL->izquierda, true);
        return rotar(arbolAVL, false);
    }

    // Caso 4: RL (Rotar a la derecha el hijo derecho y rotar hacia la izquierda el nodo actual)
    if (fb < -1 and factor_balance(arbolAVL->derecha) > 0) {
        arbolAVL->derecha = rotar(arbolAVL->derecha, false);
        return rotar(arbolAVL, true);
    }

    return arbolAVL;
}



/*****************************************************************************/
// Funciones recicladas de las funciones de un árbol ABB que está en paideia.
/*****************************************************************************/

void mostrar_en_orden(struct Nodo *arbolAVL) {
    if (not esNodoVacio(arbolAVL)) {
        mostrar_en_orden(arbolAVL->izquierda);
        imprimir_nodo(arbolAVL);
        mostrar_en_orden(arbolAVL->derecha);
    }
}

void imprimir_nodo(struct Nodo *nodo) {
    cout << nodo->valor << "(h:" << nodo->altura << ") ";
}

bool esNodoVacio(struct Nodo *nodo) {
    return nodo == nullptr;
}

struct Nodo * minimoArbol(struct Nodo *arbolAVL) {
    if (esNodoVacio(arbolAVL)) return arbolAVL;
    if (esNodoVacio(arbolAVL->izquierda)) return arbolAVL;
    return minimoArbol(arbolAVL->izquierda);
}
