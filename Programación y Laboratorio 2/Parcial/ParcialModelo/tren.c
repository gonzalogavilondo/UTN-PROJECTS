#include <stdio.h>
#include <stdlib.h>

#include "tren.h"
#include "vagon.h"

#define ESC 27
void cargaUnTren(tren arregloDeTrenes[]) {

    int resultado, peso;
    char opcion;

    do{
    system("cls");
    printf("\nQue tren desea cargar?");
    resultado = menuTrenes(); /// devuelve un entero (numero de tren)


    printf("\nIngrese el valor del cajon de %s: ", arregloDeTrenes[resultado].categoria);
    scanf("%d", &peso);
    /// Verificar Peso de la lista
    /// verificar que el resultado de la carga no sobrepase los 1400
    /// Si no pasa los 1400, carga el cajon
    /// si pasa los 1400 = printf No se puede cargar el cajon, el tren sobrepasaría su límite.

    ///repetir


    }while(opcion!=ESC);

}

int menuTrenes() {

    int nroTren;

    printf("\n\n1. Comestibles.");
    printf("\n2. Madera.");
    printf("\n3. Metal.");
    printf("\n4. Plastico.");
    printf("\n5. Vidrio.");

    scanf("%d", &nroTren);

    do{
        if(nroTren >= 0 && nroTren <= 5) {
            nroTren--;
        } else {
            printf("\n\nNumero de tren invalido.");
        }
    }while(nroTren < 0 || nroTren > 5);

    return nroTren;
}

/*
int verificarPeso(tren arregloDeTrenes[], int valor) {

    int resultadoPeso = 0;
    if (arregloDeTrenes[valor].listaVagones) {
        nodoVagon* seg = arregloDeTrenes[valor].listaVagones;
        while(seg){
            resultadoPeso = resultadoPeso + seg.pesoIngresado;
            seg = seg->sig;
        }
    }

    return resultadoPeso;
}*/
