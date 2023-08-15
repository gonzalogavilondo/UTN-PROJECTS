#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#include "arbol.h"
#include "lista.h"

#define ESC 27

nodoArbol* cicloCargaPersona(nodoArbol* a);

int main(){

    char opcion;
    int contador = 0;
    int altura, nodos;
    nodoArbol* arbolBinario;
    nodoArbol* arbolEncontrado;
    arbolBinario = inicArbol();
    arbolEncontrado = inicArbol();

    char nombre[] = "Maxi";

    nodoLista* listaSimple;
    listaSimple = inicLista();

    do{
        printf("\n1- Cargar.");
        printf("\n2- PreOrder, InOrder y PostOrder.");
        printf("\n3- Pasar de Arbol a Lista y mostrar la lista.");
        printf("\n4- Busca nodo en el arbol por legajo.");

        opcion = getch();
        switch(opcion){
        case 49:
            arbolBinario = cicloCargaPersona(arbolBinario);
            break;
        case 50:
            printf("\nPreOrder: \n");
            preOrder(arbolBinario);
            printf("\ninorder: \n");
            inOrder(arbolBinario);
            printf("\nPostOrder: \n");
            postOrder(arbolBinario);
            break;
        case 51:
            listaSimple = arbol2Lista(arbolBinario, listaSimple);
            muestraLista(listaSimple);
            break;
        case 52:
            arbolEncontrado = buscaLegajo(arbolBinario, 3);
            mostrarNodoArbol(arbolEncontrado);
            break;
        case 53:
            arbolEncontrado = buscaPorNombre(arbolBinario, nombre);
            mostrarNodoArbol(arbolEncontrado);
            break;
        case 54:
            altura = cuentaAltura(arbolBinario);
            printf("\nAltura: %d\n", altura);
        case 55:
            nodos = cuentaNodos(arbolBinario);
            printf("Cantidad de nodos del arbol: %d", nodos);
            break;
        case 56:
            muestraNodosTerminales(arbolBinario);
            contador = cuentaNodosTerminales(arbolBinario);
            printf("\nCantidad de nodos terminales: %d\n", contador);
            break;|
        case 57:
            arbolBinario = borrarNodo(arbolBinario, 4);
            preOrder(arbolBinario);
            break;
        default:
            printf("none");
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=27);


    return 0;
}

/***
* \brief Crea un dato del tipo persona.
* \return Retorna un dato tipo persona ya cargado.
*/
persona cargaPersona() {

    persona aux;

    printf("\nIngrese el numero de legajo: ");
    scanf(" %d", &aux.legajo);
    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\nIngrese la edad de %s: ", aux.nombre);
    scanf(" %d", &aux.edad);

    return aux;
}

/***
* \brief Ciclo de carga de datos tipo persona hacia un arbol binario.
* \param Recibe un arbol binario.
* \return Devuelve el arbol.
*/
nodoArbol* cicloCargaPersona(nodoArbol* ab) {

    int opcion;
    persona aCargar;

    do{
    aCargar = cargaPersona();
    ab = insertarPorLegajo(ab, crearNodoArbol(aCargar));

    printf("\nDesea ingresar otra persona? S/N.");
    opcion = getch();

    }while(opcion=='s');
    return ab;
}
