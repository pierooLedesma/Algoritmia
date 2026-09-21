//Autor: PieroLG

#ifndef PREGUNTA_1_FUNCIONESLISTA_HPP
#define PREGUNTA_1_FUNCIONESLISTA_HPP

void construir(struct Baraja & listaTAD);
bool esListaVacia(const struct Baraja & listaTAD);
void insertarAlInicio(struct Baraja & listaTAD, const struct Carta & elemento);
void insertarAlFinal(struct Baraja & listaTAD, const struct Carta & elemento);
struct NodoBaraja * obtenerUltimoNodo(const struct Baraja & listaTAD);
void insertarEnOrden(struct Baraja & listaTAD, const struct Carta & elemento);
void eliminaNodo(struct Baraja & listaTAD, const struct Carta & elemento);
void destruir(struct Lista & listaTAD) ;
void imprimir(const struct Baraja & listaTAD);

#endif //PREGUNTA_1_FUNCIONESLISTA_HPP
