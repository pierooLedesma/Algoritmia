

#include <iostream>
#include "Bibliotecas/Pila.hpp"
#include "Bibliotecas/FuncionesPila.hpp"
#include "Bibliotecas/Hanoi.hpp"

using namespace std;

int main() {
    struct Pila A{}, B{}, C{};
    construir(A);
    construir(B);
    construir(C);

    int n_discos = 4;
    for (int d = n_discos; d >= 1; --d) {
        ElementoPila e{d};
        apilar(A, e);
    }

    cout << "Estado inicial:\n";
    cout << "A=";
    imprimir(A);
    cout << "  B=";
    imprimir(B);
    cout << "  C=";
    imprimir(C);
    cout << '\n';

    int n_pasos = 0;
    /*
    jugando_al_hanoi(n_discos, A, B, C, n_pasos);

    cout << "Estado Final:\n";
    cout << "A=";
    imprimir(A);
    cout << "  B=";
    imprimir(B);
    cout << "  C=";
    imprimir(C);
    cout << '\n';
    cout << "Pasos: " << n_pasos << endl;
    */
    struct Pila D;
    construir(D);
    jugando_al_hanoi_con_4(n_discos, A, B, C, D, n_pasos);
    cout << "Estado Final:\n";
    cout << "A=";
    imprimir(A);
    cout << "  B=";
    imprimir(B);
    cout << "  C=";
    imprimir(C);
    cout << "  D=";
    imprimir(D);
    cout << '\n';
    return 0;
}