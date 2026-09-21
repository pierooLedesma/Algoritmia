//Autor: PieroLG

#include <iostream>
#define N 10
using namespace std;


// Complejidad O(n)
int buscarCandidato(int regGenetico[N][N], int i, int previo, bool puede_ser_cero) {
    // Caso base: se llega al final de la columna.
    if (i >= N) return previo != -1 ? previo : (puede_ser_cero ? 0 : -1); // si hubieron ceros en esta columna, se descarta al canario 0

    int v_candidato = regGenetico[i][0];

    // Este canario recibió aporte genetico, entonces se descarta.
    if (v_candidato != 0)
        return buscarCandidato(regGenetico, i+1, previo, puede_ser_cero);

    // No hay un candidato previo, nos llevamos este canario por defecto.
    if (previo == -1)
        return buscarCandidato(regGenetico, i+1, i, false);


    // Si este canario es candidato, entonces compite por el puesto con el previo.
    // El canario ancestral debió darle aporte genético al resto, pero no haber recibido de ninguno.
    if (regGenetico[previo][i] != 0 and regGenetico[i][previo] == 0)
        return buscarCandidato(regGenetico, i+1, i, false);

    if (regGenetico[previo][i] == 0 and regGenetico[i][previo] != 0)
        return buscarCandidato(regGenetico, i+1, previo, false);

    // Ninguno cumple con los requisitos, ambos quedan descartados.
    return buscarCandidato(regGenetico, i+1, -1, false);
}




// Evalúa si es el canario ancestral tomando en cuenta si da aporte genético
// a todos, pero no recibe de ninguno. Complejidad: O(2n)
int evaluarCandidato(int regGenetico[N][N], int candidato, char eje=0, int i=0) {

    // Caso base: se terminó de evaluar el eje horizontal o vertical.
    if (i >= N) return eje != 'h' ? 1 : 0;

    // Solo se ejecuta la primera vez que se llama a la función.
    if (eje == 0) {
        int fila = 0 + evaluarCandidato(regGenetico, candidato, 'h'),
            columna = 1 * evaluarCandidato(regGenetico, candidato, 'v');

        return (fila == 100 and columna != 0) ? candidato : -1;
    }

    // Suma horizontal
    if (eje == 'h')
        return regGenetico[candidato][i] + evaluarCandidato(regGenetico, candidato, 'h', i+1);

    // Producto vertical
    return regGenetico[i][candidato] * evaluarCandidato(regGenetico, candidato, 'v', i+1);
}



// Complejidad: " O(n + 2n) = O(3n) " aproximadamente es "O(n)" cuando 'n' es muy grande
int buscarCanarioAncestral(int regGenetico[N][N]) {

    int candidato = buscarCandidato(regGenetico, 0, -1, true); // O(n)

    return evaluarCandidato(regGenetico, candidato); // O(2n)
}



int main() {
    int regGenetico[N][N] = {
        {100, 0, 50, 40, 30, 20, 30, 0, 80, 0},
        {50, 100, 0, 40, 30, 20, 20, 0, 10, 25},
        {80, 30, 100, 40, 30, 0, 30, 20, 10, 60},
        {50, 0, 0, 100, 30, 0, 50, 30, 30, 90},
        {50, 10, 10, 10, 100, 0, 10, 50, 10, 50},
        {20, 0, 0, 0, 0, 100, 90, 20, 40, 20},
        {0, 0, 0, 0, 0, 0, 100, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 50, 100, 50, 20},
        {20, 0, 0, 40, 0, 0, 90, 0, 100, 10},
        {0, 10, 0, 0, 0, 0, 10, 0, 60, 100},
    },
    canarioAncestral = buscarCanarioAncestral(regGenetico);


    cout << "Canario ancestral: ";
    (canarioAncestral != -1 ? cout << canarioAncestral : cout << "no hallado") << endl;

    return 0;
}
