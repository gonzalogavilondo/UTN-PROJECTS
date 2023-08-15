#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "listas.h"
#include "persona.h"
#include "filas.h"

typedef struct {
    stPersona dato;
    struct nodo* siguiente;
} nodo;

nodo* inicLista();
nodo* archivo2lista(nodo* lista, char archivo[]);
nodo* crearNodo(stPersona persona);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlInicio(nodo* nuevo, nodo* lista);
nodo* agregarAlFinal(nodo* nuevo, nodo* lista);
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo);
nodo* agregarEnOrden(nodo* lista, nodo* nuevo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
void muestaListaRecursiva(nodo* lista);
int sumaListaRecursiva(nodo* lista);
int sumaListaRecursivaPro(nodo* lista);
int sumaListaRecursivaSuperPro();
nodo* archivo2ListaOrdenado(nodo* lista, char archivo[]);
nodo* borrarLista(nodo* lista);
nodo* borrarNodoPorBusqueda(nodo* lista, char apellido[]);
nodo* eliminarUltimoNodo(nodo* lista);
nodo* eliminarPrimerNodo(nodo* lista);
int cuentaLista(nodo* lista);
stPersona verPrimero(nodo* lista);
stPersona buscaMenorRecursiva(nodo* lista);
void lista2fila(nodo* lista, Fila* fila, char x);
int cantPersonasPorEdad (nodo* lista, int edad2);
float porcentListaSegunEdad(nodo* lista, int edad);

void agregarFinal(nodo** lista, nodo * nuevo);
void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo);
nodo* archivo2listaPD(char F[], nodo* lista);
void buscarUltimoPD(nodo** lista);

#endif // LISTAS_H_INCLUDED
