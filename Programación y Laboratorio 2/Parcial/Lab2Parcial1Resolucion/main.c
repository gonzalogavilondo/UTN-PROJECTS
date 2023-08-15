#include <stdio.h>
#include <stdlib.h>

int main()
{


    return 0;
}

int sumaEdadesRecursiva(nodo* lista){
    int rta=0;
    if(lista){
        if(atoi(lista->dato.edad)%2 == 0 && lista->dato.edad > 17) {
            rta=1+sumaEdadesRecursiva(lista->siguiente);
        } else {
            rta = sumaEdadesRecursiva(lista->siguiente);
        }
    }

    return rta;
}

stPersona buscaMenorRecursivo(nodo* lista)
{
    stPersona menor;

    if(!lista->siguiente){
        menor = lista->dato;
    } else {
        menor = buscaMenorRecursivo(lista->siguiente);
        if(lista->dato.edad < menor.edad){
            menor = lista->dato;
        }
    }

    return menor;
}

void lista2fila(nodo* lista, Fila* fila, char x) {
    nodo* seg = lista;

    if(seg) {
        while(seg){
            if(seg->dato.apellido[0] == x) {
                agregar(fila, seg->dato);
            }
            seg = seg->siguiente;
        }
    }
}

int cantPersonasPorEdad (nodo* lista, int edad) {
    int total = 0;

    if (lista){
        if(lista->dato.edad > edad){
            total = 1 + cantPersonasPorEdad(lista->siguiente);
        } else {
            total = cantPersonasPorEdad(lista->siguiente);
        }
    }
    return total;
}

/// Necesita una lista con datos!.
float porcentajeEdades(nodo* lista, int edad) {
    return (float) cantPersonasPorEdad(lista,edad) * 100 / cantPersonasPorEdad(lista, 0);
}
