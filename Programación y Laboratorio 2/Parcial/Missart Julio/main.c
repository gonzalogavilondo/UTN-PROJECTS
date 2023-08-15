#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#include "persona.h"
#include "listas.h"
#include "filas.h"

#define ESC 27
#define AR_PERSONAS "personas.dat"


int main()
{

    nodo* lista;
    lista = inicLista();
    int edades = 0;
    int total, cant, cant2;
    int edad = 40;
    stPersona aux;
    char letra;
    letra = 'G';
    float porcentaje;

    Fila* fila;
    inicFila(&fila);


    lista = archivo2lista(lista, AR_PERSONAS);
    muestraLista(lista);

    system("pause");

    //cant2 = cantPersonas(lista);
    edades = sumaListaRecursivaPro(lista);
    //printf("\nCant Personsa: %d", cant2);
    printf("\nSuma de edades recursiva: %d\n", edades);

    system("pause");
    printf("\nMENOR EN LA LISTA\n");
    aux = buscaMenorRecursiva(lista);
    muestraUnaPersona(aux);
    system("pause");
/*
    porcentaje = porcentListaSegunEdad(lista, 20);
    printf("Porcentaje, edad 20: %.2f\n\n", porcentaje);
    system("pause");*/

    total = mayoresEdad(lista, 0);
    printf("Total de personas mayor a 0: %d\n\n", total);
    system("pause");

    printf("\n\nMostrando Fila con letra apellidos que inicien con letra %c\n\n", letra);
    lista2fila(lista, fila, letra);
    //muestraFila(&fila);

    system("pause");

    return 0;
}


