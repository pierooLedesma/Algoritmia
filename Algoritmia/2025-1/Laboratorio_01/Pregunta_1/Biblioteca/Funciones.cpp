

/*
 * Archivo: Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Sábado 6 de septiembre del 2025.
 */


#include "Funciones.hpp"


// Módulo que almacena en cada índice del arreglo "combinaciones" consecutivamente
// cada dígito de la representación de un número (en decimal) a cierta base.
void cargarCombinacion(int numero, int base, int *combinaciones) {
    for (int i=0; i<base; i++) combinaciones[i] = 0; // Inicializar el arreglo.
    int i=0;
    while (numero > 0) {
        combinaciones[i++] = numero % base; // Guardar el resto en el índice "i" del arreglo.
        numero /= base; // Reducir el número dividiendo por la base.
    }
}




// Módulo que calcula la solución óptima.
void calcular_la_solucion_optima(
    int cant_discos,  // Número de discos disponibles.
    int cant_tablas,  // Número de tablas a asignar.
    int *tablas,      // Arreglo con las velocidades (IOPs) de cada tabla.
    int *discos,      // Arreglo con la velocidad (IOPs) de cada disco.
    int *la_mejor_solucion,   // Arreglo para guardar la mejor asignación (índice de disco para cada tabla).
    int &indice_mejor_disco,  // Índice del disco con la menor velocidad final en la mejor solución.
    int &velocidad_mas_grande_de_las_minimas_velocidades  // El valor del "mejor mínimo" (en velocidades).
    ) {

    // Se inicializa a "-1", porque se desea maximizar el mínimo
    // (cualquier valor encontrado será mayor que "-1" al inicio).
    velocidad_mas_grande_de_las_minimas_velocidades = -1;


    // Cada tabla puede ir a cualquiera de los "cant_discos" discos.
    // Calcular la cantidad de combinaciones posibles:  cant_discos ^ cant_tablas
    int cant_combinaciones = pow(cant_discos, cant_tablas);




    // Recorrer todas las combinaciones posibles (aplicación de Fuerza Bruta).
    for (int iteracion = 0; iteracion < cant_combinaciones; iteracion++) {


        /***************************************************************************/
        /********************* Generar la combinación actual ***********************/
        /***************************************************************************/

        int combinaciones[cant_tablas]; // " combinaciones[i] " indica en qué disco se asigna la tabla "i".

        // Convierte el número "iteracion" a base "cant_discos" y lo guarda en "combinaciones[]".
        // Por ejemplo, iteracion = 5, se convierte el número 5 a la base 3 (cant_discos).
        cargarCombinacion(iteracion, cant_discos, combinaciones);






        /***************************************************************************/
        /*************** Copiar las velocidades originales de los discos ***********/
        /***************************************************************************/

        // Se trabaja sobre una copia para no modificar el arreglo original "discos".
        int copia_discos[cant_discos];
        for (int i=0; i<cant_discos; i++) copia_discos[i] = discos[i];





        /***************************************************************************/
        /********************  Asignar las tablas a los discos  ********************/
        /***************************************************************************/

        bool es_negativo = false; // Bandera que indica si algún disco se quedó sin capacidad.

        // Se recorre hasta el número "cant_tablas", porque se recorrerá todo el arreglo "combinaciones[]".
        for (int i=0; i<cant_tablas; i++) {

            // Se resta la velocidad que necesita cada tabla en el disco asignado.
            copia_discos[combinaciones[i]] -= tablas[i];

            if (copia_discos[combinaciones[i]] < 0) {
                // Si algún disco queda negativo (sin capacidad suficiente), entonces
                // se asigna la variable "es_negativo" a "true" y se descarta esta combinación.
                es_negativo = true;
                break;
            }
        }


        // Si hay algún disco negativo, entonces continuar con la siguiente
        // combinación (regresar al "for" inicial y trabajar con la siguiente iteración).
        if (es_negativo) continue;






        /***************************************************************************/
        /********* Calcular el disco más lento después de esta asignación **********/
        /***************************************************************************/

        int minima_velocidad_disco = 999; // Inicialización de la velocidad del peor disco en esta combinación.
        int indice_disco; // Índice del disco que es el más lento
                          // (Disco 1: índice 0; Disco 2: índice 1; Disco 3: índice 2).

        // Calcular el disco más lento después de la asignación dada anteriormente.
        for (int indice=0; indice < cant_discos; indice++) {
            if (copia_discos[indice] < minima_velocidad_disco) {
                minima_velocidad_disco = copia_discos[indice];
                indice_disco = indice;
            }
        }





        /*******************************************************************************/
        /****** Actualizar la mejor solución si se encuentra una combinación mejor *****/
        /*******************************************************************************/

        // Criterio: Si el mínimo actual es mayor que el mejor mínimo encontrado antes,
        //           entonces se actualiza la mejor combinación.
        if (minima_velocidad_disco > velocidad_mas_grande_de_las_minimas_velocidades) {
            for (int i=0; i<cant_tablas; i++) la_mejor_solucion[i] = combinaciones[i];
            velocidad_mas_grande_de_las_minimas_velocidades = minima_velocidad_disco;
            indice_mejor_disco = indice_disco;
        }
    }
}






// Módulo que imprime la solución óptima.
void imprimir_solucion_optima(const int *la_mejor_solucion, const int cant_discos, const int cant_tablas,
                              const int velocidad_mas_grande_de_las_minimas_velocidades,
                              const int indice_mejor_disco) {
    titulo_del_cuadro();
    for (int i=0; i<cant_discos; i++) {
        cout << '|' << setw(3) << i+1 << setw(9) << "| ";
        int contador_de_numeros = 0;
        for (int k=0; k<cant_tablas; k++) {
            if (la_mejor_solucion[k] == i) {
                cout << k+1 << ' ';
                contador_de_numeros++;
            }
        }
        cout << setw(11 -  2 * contador_de_numeros) << '|' << endl;
        elaborar_lineas();
    }
    cout << endl;
    cout << "Esta solucion tiene una velocidad minima de grupo de ";
    cout << velocidad_mas_grande_de_las_minimas_velocidades << " IOPs que se da en el disco ";
    cout << indice_mejor_disco + 1 << '.' << endl;
}




// Módulo que imprime el título del cuadro de la solución óptima.
void titulo_del_cuadro() {
    cout << endl;
    cout << "La solucion optima: " << endl << endl;
    elaborar_lineas();
    cout << "| Disco" << setw(12) << "| Tablas" << setw(5) << '|' << endl;
    elaborar_lineas();
}



// Módulo que elabora las líneas del cuadro.
void elaborar_lineas() {
    for (int i=0; i<24; i++) cout.put('-');
    cout << endl;
}

