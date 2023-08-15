#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"

/**
    InicializarMatriz
    Parametros: Filas, columnas y la matriz
    Inicializa la matriz con todos sus valores en 0.
**/
void InicializarMatriz(int filas, int columnas, float **matriz)
{
    float limpiar[20][20] = {{0.0}};

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = limpiar[i][j];
        }
    }
}


/**
    ReservarMemoria
    Parametros: filas y columnas
    Se reserva memoria dependiendo la cantidad de filas y columnas de una matriz.
**/
float **ReservarMemoria(int fils, int cols)
{
    //Reservo memoria para las "filas" que seria el primer puntero(puntero a puntero).
    float **matriz = NULL;
    matriz = (float **)calloc(fils, sizeof(float *));
    if(matriz == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    //Reservo memoria para las "columnas" que seria el segundo puntero.
    for(int i = 0; i < fils; i++)
    {
        matriz[i] = (float *)calloc(cols, sizeof(float));
        if((matriz[i]) == NULL)
        {
            printf("No se ha podido reservar espacio en memoria.\n");
            exit(2);
        }
    }

    //No pongo el else, donde diria que si se asigno memoria correctamente, cuando no aparece nada, doy por hecho que reservo una m

    return matriz;
}


/**
    CargarFilasColumnas
    Parametros: Cantidad de filas y cantidad de columnas a cargar
    Se le pide al usuario el numero de filas y de columnas y los guarda
**/
void CargarFilasColumnas(int *filas, int *columnas)
{
    printf("Digite el numero de filas: ");
    scanf("%i", filas);
    printf("Digite el numero de columnas: ");
    scanf("%i", columnas);
    system("pause");
    system("cls || clear");

}

/**
    MostrarMatriz
    Parametros: Numero de filas, numero de columnas y la matriz
    Muestra la matriz por pantalla
**/
void MostrarMatriz (int filas, int columnas, float **matriz)
{
    for (int i = 0; i < filas; i++)
    {
        printf("|\t");
        for (int j = 0; j < columnas; j++)
        {
           printf("%.2f \t", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    puts("\n");
}


/**
    CompletarMatriz
    Parametros: Cantidad de filas, columnas, una matriz y el nombre de la matriz
    Interfaz para ir completando la matriz y que el usuario pueda ir viendo los datos
    ingresados.
**/
void CompletarMatriz(int filas, int columnas, float **matriz, char nombreMatriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ %c: \n\n", nombreMatriz);
            MostrarMatriz(filas, columnas, matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}


/**
    CondicionOpcion
    Parametros: opcion, filas y columnas de dos matrices
    Es la condicion que se utiliza para distintas operaciones, por ejemplo que
    -Si vamos a sumar o restar tengan la misma cantidad de filas y columnas.
    -Si vamos a multiplicar, tenemos que digitar las columnas de la matriz B y automaticamente las filas
    de la matriz b seran igual a la cantidad de columnas de la matriz A.

**/
void CondicionOpcion(int opcion, int *filas1, int *columnas1, int *filas2, int *columnas2)
{
    if((opcion == 1) || (opcion == 2))
    {
        *filas2 = *filas1;
        *columnas2 = *columnas1;
    }
    else
    {
        if(opcion == 3)
        {
            printf("Digite las columnas de la matriz 'B': ");
            scanf("%i", columnas2);
            *filas2 = *columnas1;
        }
        else
        {
            if(opcion == 5)
            {
                *filas1 = *columnas1;
            }
        }
    }
}
