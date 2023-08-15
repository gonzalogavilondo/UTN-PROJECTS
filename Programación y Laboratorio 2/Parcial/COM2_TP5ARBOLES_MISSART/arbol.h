#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct {
     int legajo;
     char nombre[20];
     int edad;
} persona;

typedef struct nodoArbol {
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
} nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(persona dato);
nodoArbol* insertarPorLegajo(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarNodoArbol(nodoArbol* nodo);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);
void muestraNodosTerminales(nodoArbol* arbol);
int cuentaNodosTerminales(nodoArbol* arbol);
nodoArbol* buscaLegajo(nodoArbol* arbol, int datoLegajo);
int cuentaNodos(nodoArbol* arbol);
nodoArbol* buscaPorNombre(nodoArbol* arbol, char datoNombre[]);
int cuentaAltura(nodoArbol* arbol);
nodoArbol* encuentraMenorIzq(nodoArbol* arbol);
//nodoArbol* buscaLegajo(nodoArbol* arbol, int datoLegajo);

#endif // ARBOL_H_INCLUDED
