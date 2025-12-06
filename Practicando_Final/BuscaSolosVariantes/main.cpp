#include <iostream>
using namespace std;

int buscar_tres(int *arr, int inicio, int fin) {
    if (inicio > fin)
        return -1;  // No encontrado

    int medio = (inicio + fin) / 2;

    // Ajustar medio al inicio de un grupo
    medio -= (medio % 4);

    // Si el grupo está dentro del límite
    if (medio + 3 <= fin) {
        // Caso 1: el grupo del medio tiene 3 repeticiones → encontrado
        if (arr[medio] == arr[medio + 1] and arr[medio] == arr[medio + 2]
            and arr[medio] != arr[medio + 3]) {
            return arr[medio];
        }
        // Caso 2: tiene 4 repeticiones → seguimos al lado derecho
        if (arr[medio] == arr[medio + 3]) {
            return buscar_tres(arr, medio + 4, fin);
        } else {
            // Caso contrario → está a la izquierda
            return buscar_tres(arr, inicio, medio - 1);
        }
    }
}


int busca_solo_variante(int *arr, int inicio, int fin) {
    if (inicio > fin) return -1; // No se encontró un valor único
    int medio = (inicio + fin) / 2;
    medio -= medio%2;
    if (medio + 1 <= fin) {
        if (arr[medio] != arr[medio + 1]) return arr[medio];
        if (arr[medio] == arr[medio + 1]) return busca_solo_variante(arr, medio + 1, fin);

    }
}


int buscar_solo(int *arr_p1, int inicio, int fin) {
    //Caso Base: Inicio == Fin, encontramos con el elemento unico
    if (inicio == fin) return arr_p1[inicio];

    int medio = (inicio + fin) / 2;

    // Asegurar que "medio" sea par para comparar con su siguiente
    if (medio % 2 == 1) medio--;

    // Si el par esta completo
    if (arr_p1[medio] == arr_p1[medio + 1])
        return buscar_solo(arr_p1, medio + 2, fin); // Asumiendo que en la parte izq solo hay pares
    else
        return buscar_solo(arr_p1, inicio, medio); // Asumiendo que en la parte derecha solo hay pares
}


int main() {
    // Para el caso de un busca solo:
    int arreglo_1[] = {1,1,2,2,3,4,4};
    int indice_1 = buscar_solo(arreglo_1,0, 7);
    cout << "Valor que se repite una vez: " << indice_1 << endl << endl;

    // Para el caso de un busca tres:
    int arreglo_2[] = {1,1,1,1,2,2,2,2,3,3,3,4,4,4,4};
    int cant = sizeof(arreglo_2) / sizeof(int);
    int indice_2 = buscar_solo(arreglo_2,0, cant);
    cout << "Valor que se repite tres veces: " << indice_2;
    return 0;
}