#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "auto.h"

#define archivoAutos "autos.dat"
#define ESC 27

int main()
{
    char opcion;
    nodoAuto* lista = inicLista();

    do{
        menu();
        opcion = getch();
        switch(opcion) {
            case 49:
                cicloCargaAutos(archivoAutos);
                break;
            case 50:
                mostrarAutosArchivo(archivoAutos);
                break;
            case 51:
                lista = archivo2listaPD(archivoAutos, lista);
                break;
            case 52:
                mostrarLista(lista);
                break;
        }
        system("pause");
    }while(opcion!=ESC);
    return 0;
}
