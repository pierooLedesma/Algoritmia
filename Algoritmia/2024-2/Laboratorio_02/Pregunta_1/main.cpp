

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha Miércoles 24 de septiembre del 2025
 */

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;


// Módulo que compara si un "lider" puede ser considerado superior
// respecto a otro efectivo según las reglas del enunciado:
//
// - El líder debe tener grado mayor que el otro.
// - Si los grados son iguales, se usa el tiempo como desempate:
//   el líder debe tener mayor tiempo que el otro.
//
bool cumpleCondicion(const ElementoPila &lider, const ElementoPila &otro) {
    // Si el grado del líder es estrictamente mayor, devuelve "true".
    if (lider.grado > otro.grado) return true;

    // Si los grados son iguales, entonces comparamos tiempos.
    // Solo se devuelve "true" si el tiempo del líder es estrictamente mayor.
    // (Si el tiempo es igual tampoco se considera superior).
    if (lider.grado == otro.grado && lider.tiempo > otro.tiempo) return true;

    // En cualquier otro caso (grado menor, o mismo grado y tiempo menor/igual)
    // no cumple la condición de superioridad del líder.
    return false;
}




// ******* Función recursiva para extender el grupo a partir de un líder *********
/*
 Parámetros:
  - lider: el efectivo que será el primer elemento del grupo.
  - efectivos[]: arreglo con todos los efectivos (orden de registro).
  - siguiente: índice del siguiente candidato a evaluar (consecutivo al líder).
  - n_efectivos: tamaño del arreglo.
  - auxiliar: pila auxiliar que se usa para apilar los efectivos que van formando
              la extensión del grupo (se usa como estructura temporal).

 Valor devuelto:
  - Un entero con la "cantidad de agrupaciones adicionales" que se forman
    extendiendo desde el líder (no incluye la agrupación trivial {lider}).
*/
int extenderGrupoRecursivo(const ElementoPila &lider, ElementoPila efectivos[],
                           int siguiente, int n_efectivos, Pila &auxiliar) {
    // Caso base 1: si ya no quedan candidatos (índice fuera de rango),
    // no hay más extensiones posibles, entonces 0 agrupaciones nuevas.
    if (siguiente >= n_efectivos) return 0;

    // Si el candidato en "siguiente" cumple la condición respecto al líder...
    if (cumpleCondicion(lider, efectivos[siguiente])) {
        // 1) Se apila en la pila auxiliar: representa que se añadió
        //    temporalmente a la extensión actual del grupo.
        apilar(auxiliar, efectivos[siguiente]);

        /* 2) cada vez que se apila a un efectivo, se forma una nueva agregación válida,
              por eso se está contando 1 + lo que resulte de intentar agregar al siguiente
              consecutivo (llamada recursiva). */
        int cuenta = 1 + extenderGrupoRecursivo(lider, efectivos, siguiente + 1, n_efectivos, auxiliar);

        /* 3) Al retornar de la recursión, desapilar el elemento
              que se apiló antes de regresar. Esto deja la pila "auxiliar" en el
              mismo estado en que estaba al entrar en esta llamada. */
        desapilar(auxiliar);

        // Devolver el número total de agrupaciones encontradas partiendo de aquí.
        return cuenta;
    } else {
        // Si el candidato "siguiente" NO cumple la condición respecto al líder,
        // no se puede extender más el grupo. Esto implica detener la recursión.
        return 0;
    }
}





/****************************************************************************************/
/**** Función que recorre los líderes de "efectivos" y suma todas las agrupaciones ******/
/****************************************************************************************/
int contarGrupos(ElementoPila efectivos[], int n_efectivos) {
    int total = 0;

    // Pila auxiliar requerida por el enunciado (se construye vacía).
    Pila auxiliar;
    construir(auxiliar);

    // Recorrer cada efectivo como posible líder (un único bucle sobre "n_efectivos").
    for (int i = 0; i < n_efectivos; i++) {
        // 1. Cada efectivo siempre forma la agrupación trivial {i} -> contar 1.
        total++; // cuenta {i}

        // 2. Guardar el líder en una variable para pasarla a la recursión.
        ElementoPila lider = efectivos[i];

        /* 3. En lugar de usar un bucle anidado (for j = i+1 .. n),
              llamar a la función recursiva que extiende el grupo.
              La recursión se encarga de avanzar por consecutivos hasta que
              la condición deje de cumplirse o se acaben los efectivos. */
        total += extenderGrupoRecursivo(lider, efectivos, i + 1, n_efectivos, auxiliar);

        // Nota: La función recursiva hace su propio apilar/desapilar, así que
        // al volver aquí la pila auxiliar queda limpia (el mismo estado como al entrar).
    }

    return total;
}




int main() {
    int n_efectivos = 3;
    ElementoPila efectivos[3] = {
        {3, 1},
        {2, 1},
        {2, 4},
    };
    int total_agrupaciones = contarGrupos(efectivos, n_efectivos);
    cout << "Se pueden formar " << total_agrupaciones << " agrupaciones." << endl;
    return 0;
}





/*
 * Este fue el primer módulo que se me ocurrió de "contarGrupos", pero se usa
 * iteraciones anidadas donde ambas recorren los "n" datos (n_efectivos).
 * Descarto este módulo por lo mencionado anteriormente.
int contarGrupos(ElementoPila arr[], int n_efectivos) {
    int total = 0;
    Pila auxiliar;
    construir(auxiliar);

    for (int i = 0; i < n_efectivos; i++) {
        // Caso trivial: un solo efectivo
        total++;

        ElementoPila lider = arr[i];

        // Extender grupo con pila auxiliar
        for (int j = i+1; j < n_efectivos; j++) {
            if (cumpleCondicion(lider, arr[j])) {
                apilar(auxiliar, arr[j]);
                total++; // Formar un nuevo grupo válido cada vez que se agrega.
            } else {
                // Si ya no cumple, entonces salir del bucle.
                break;
            }
        }

        // Limpiar pila auxiliar antes de pasar a la siguiente iteración "i"
        while (!esPilaVacia(auxiliar)) {
            desapilar(auxiliar);
        }
    }
    return total;
} */



