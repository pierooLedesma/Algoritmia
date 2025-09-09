

/*
 * Archivo: Funciones.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Domingo 7 de septiembre del 2025
 */


#include "Funciones.hpp"


// Módulo en que el usuario ingresa el presupuesto para los recursos de seguridad.
int ingresar_presupuesto_del_usuario() {
    int presupuesto;

    cout << "Ingrese el presupuesto (en miles de soles): ";
    cin >> presupuesto;

    cin.get(); // Lectura del cambio de línea que realiza el usuario.

    return presupuesto;
}




// Módulo que almacena en cada índice del arreglo "combinaciones" consecutivamente
// cada dígito de la representación de un número (en decimal) a cierta base.
void cargar_combinaciones(int numero, int base, int *combinaciones) {
    int k=0;
    while (numero > 0) {
        combinaciones[k++] = numero % base; // Guardar el resto en el índice "i" del arreglo.
        numero /= base; // Reducir el número dividiendo por la base.
    }
}





// Módulo que procesa todas las combinaciones posibles de los recursos de seguridad
// y muestra aquellas cuyo costo esté dentro del rango permitido (80% a 100% del presupuesto).
// Además, valida las dependencias entre recursos si existieran.
void procesarCombinaciones(const int presupuesto, const struct Recurso_de_Seguridad *recursos) {

    // Calcular los límites inferior y superior del costo permitido.
    int limite_inferior = presupuesto*0.80;  // 80% del presupuesto.
    int limite_superior = presupuesto;       // 100% del presupuesto.


    // Mostrar el rango de costo permitido.
    cout << "Combinaciones validas (Costo entre " << limite_inferior;
    cout << " y " << limite_superior << " miles):" << endl;


    // Variables que manejan el total de combinaciones y el conteo de combinaciones válidas.
    int combinaciones, contador_combinaciones_validas = 0;


    // El número total de combinaciones posibles es 2^MAX_RECURSOS.
    combinaciones = pow(2, MAX_RECURSOS);


    // Recorrer todas las combinaciones posibles (Aplicación de Fuerza Bruta).
    for (int iteracion = 0; iteracion < combinaciones; iteracion++) {

        // Arreglo que representa si un recurso está seleccionado (1) o no (0).
        int combinaciones[MAX_RECURSOS]{};


        // Cargar la combinación correspondiente a la iteración actual.
        // La función convierte el número "iteracion" en una representación
        // binaria (en este caso) que indica qué recursos están incluidos.
        cargar_combinaciones(iteracion, 2, combinaciones);


        int costo_total = 0; // Variable que acumula el costo de los recursos seleccionados.
        bool combinacion_valida = true; // Bandera para verificar dependencias.


        // Recorrer cada recurso.
        for (int i=0; i<MAX_RECURSOS; i++) {
            if (combinaciones[i]) { // Si el recurso está seleccionado

                // Verificar que sus implementaciones requeridas también estén seleccionadas.
                for (int k=0; k<3; k++) {
                    if (recursos[i].implementaciones[k] != -1 and
                        not combinaciones[recursos[i].implementaciones[k]]) {
                        // Si falta una implementación requerida, la combinación no es válida.
                        combinacion_valida = false;
                        break;
                    }
                }
                // Sumar el costo del recurso seleccionado.
                costo_total += recursos[i].costo;
            }
        }

        // Si la combinación es válida y el costo total está dentro del rango permitido.
        if (combinacion_valida and costo_total <= limite_superior and costo_total >= limite_inferior) {
            // Imprimir la combinación y su costo total.
            imprimir_combinacion(iteracion, combinaciones, MAX_RECURSOS, costo_total);
            contador_combinaciones_validas++;
        }
    }

    // Si no se encontró ninguna combinación válida.
    if (contador_combinaciones_validas == 0)
        cout << "No se encontraron combinaciones que cumplan con lo solicitado." << endl;
}




// Módulo que realiza la impresión de una combinación válida.
void imprimir_combinacion(const int iteracion, const int *combinaciones,
                          const int cant_recursos, const int costo_total) {
    cout << "Combinacion " << iteracion << ": Recursos: ";
    for (int indice = 0; indice < cant_recursos; indice++) {
        if (combinaciones[indice]) cout << 'R' << indice + 1 << ' ';
    }
    cout << "| Costo: " << costo_total << " miles" << endl;
}



