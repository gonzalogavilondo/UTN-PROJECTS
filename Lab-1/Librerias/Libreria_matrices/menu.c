#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

/**
    Menu
    Parametros: No tiene
    Muestra todas las opciones disponibles del menu
**/
int Menu(void)
{
    int opcion = 0;

    do
    {
        system("cls || clear");
        printf("\t||MENU DE OPERACIONES CON MATRICES||\t\n\n");
        printf("1) SUMA.\n");
        printf("2) RESTA.\n");
        printf("3) MULTIPLICACION.\n");
        printf("4) DIVISION POR ESCALAR.\n");
        printf("5) MULTIPLICACION DE FILAS.\n");
        printf("6) TRASPUESTA.\n");
        printf("7) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 7)
        {
            printf("Opcion invalida.\n");
            system("pause");
        }


    }while(opcion < 1 || opcion > 7);


    return opcion;
}

/**
    OpcionProceso
    Parametros: opcion elegida, filas y columnas de ambas matrices con su matriz resultante.
**/
void OpcionProceso(int op, int fils1, int cols1, int fils2, int cols2, float **A, float **B, float **C)
{
    switch(op)
    {
        case 1:
            SumarMatrices(fils1, cols1, A, B, C);
            break;

        case 2:
            RestarMatrices(fils1, cols1, A, B, C);
            break;

        case 3:
            MultiplicarMatrices(fils1, cols1, fils2, cols2, A, B, C);
            break;

        case 4:
            DivisionEscalar(fils1, cols1, A, C);
            break;

        case 5:
            MultiplicarFilasMatriz(fils1, cols1, A, C);
            break;

        case 6:
            TraspuestaMatriz(fils1, cols1, A, C);
            break;
    }
}

/**
    OpcionSalida
    Parametros: No tiene
    Consulta al usuario si desea salir o si quiere continuar
**/
int OpcionSalida(void)
{
    int si_no = 0;

    do
    {
        system("cls || clear");
        printf("%cSeguro desea salir? <Si = 1 / No = 0>: ", 168); //El 168 es el signo de interrogacion en ASCII
        scanf("%i", &si_no);

        switch(si_no)
        {
            case 0:
                printf("Has decidido volver al menu.\n");
                break;

            case 1:
                printf("Has decidido salir del programa.\n");
                break;

            default:
                printf("Opcion invalida.\n");
                system("pause");
        }

    }while(si_no < 0 || si_no > 1);

    return si_no;
}
