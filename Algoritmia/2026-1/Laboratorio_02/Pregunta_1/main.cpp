//Autor: PieroLG

#include <iostream>
#include "BibliotecaBarajas/funcionesBarajas.hpp"
#include "BibliotecaLista/funcionesLista.hpp"
using namespace std;

int main() {
    Baraja baraja;

    crear_baraja(baraja);
    cout << "----------------------------" << endl;
    cout << "BARAJA ORIGINAL" << endl;
    cout << "----------------------------" << endl;
    imprimir(baraja);

    barajar(baraja);
    cout << endl << "----------------------------" << endl;
    cout << "BARAJADO" << endl;
    cout << "----------------------------" << endl;
    imprimir(baraja);

    destruir(baraja);
    cout << endl << "----------------------------" << endl;
    cout << "LIBERAR MEMORIA" << endl;
    cout << "----------------------------" << endl;
    imprimir(baraja);

    return 0;
}