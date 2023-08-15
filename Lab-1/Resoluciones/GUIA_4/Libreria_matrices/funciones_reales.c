#include "declaraciones_funciones_reales.h"

/**
    SumarMatrices
    Parametros: Cantidad de filas y columnas y tres matrices
    Suma dos matrices y guarda el resultado en la tercera matriz.
**/
void SumarMatrices(int filas, int columnas, float **matriz_1, float **matriz_2, float **matriz_3)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = (matriz_1[i][j] + matriz_2[i][j]);
        }
    }
}

/**
    RestarMatrices
    Parametros: Cantidad de filas y columnas y tres matrices
    Resta dos matrices y guarda el resultado en la tercera matriz.
**/
void RestarMatrices(int filas, int columnas, float **matriz_1, float **matriz_2, float **matriz_3)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = (matriz_1[i][j] - matriz_2[i][j]) ;
        }
    }
}

/**
    MultiplicarMatrices
    Parametros: Cantidad de filas y columnas de ambas matrices y tres matrices
    Multiplica dos matrices y guarda el resultado en la tercera matriz.
**/
void MultiplicarMatrices(int filas1, int columnas1, int filas2, int columnas2, float **matriz_1, float **matriz_2, float **matriz_3)
{
    for (int i = 0; i < filas1; i++)
    {
        for (int j = 0; j < columnas2; j++)
        {
            matriz_3[i][j] = MultiplicacionEscalarMatrices(i, j, filas2, matriz_1, matriz_2) ;
        }
    }

}

/**
    MultiplicacionEscalarMatrices
    Parametros: Cantidad de filas, columnas y total de elementos y dos matrices
    Multiplica por escalar ambas matrices y retorna el resultado.
**/
float MultiplicacionEscalarMatrices(int i, int j, int elementos, float **matriz_1, float **matriz_2)
{
    float res = 0.0;

    for (int k = 0; k < elementos; k++)
    {
        res  += matriz_1[i][k]*matriz_2[k][j];
    }
    return res;
}

/**
    MultiplicarFilasMatriz
    Parametros: Cantidad de filas, columnas y dos matrices
    Multiplica las filas de ambas matrices.
**/
void MultiplicarFilasMatriz(int filas, int columnas, float **matriz_1, float **matriz_2)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[i][j] = MultiplicacionEscalarMatriz(i, j, filas, matriz_1);
        }
    }

}

/**
    MultiplicacionEscalarMatriz
    Parametros: Cantidad de filas, columnas, elementos y una matriz
    Multiplica escalarmente una matriz.
**/
float MultiplicacionEscalarMatriz(int i, int j, int elementos, float **matriz)
{
    float res = 0.0;

    for (int k = 0; k < elementos; k++)
    {
        res  += matriz[i][k]*matriz[j][k]; //Si quiero calcular la multiplicacion de columnas, cambio hasta que k < columnas y tengo que pasar como parametro columnas.
    }
    return res;
}


/**
    DivisionEscalar
    Parametros: Cantidad de filas, columna y dos matrices
    Divide escalarmente una matriz y guarda el resultado en la segunda matriz.
**/
void DivisionEscalar(int filas, int columnas, float **matriz_1, float **matriz_2)
{
    float escalar = 0.0;
    printf("Ingrese un escalar: ");
    scanf("%f", &escalar);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[i][j] = (matriz_1[i][j] / escalar);
        }
    }
}


/**
    TraspuestaMatriz
    Parametros: Cantidad de filas, columna y dos matrices
    Traspone una matriz y guarda el resultado en la segunda matriz.
**/
void TraspuestaMatriz(int filas, int columnas, float **matriz_1, float **matriz_2)
{
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            matriz_2[i][j] = matriz_1[j][i];
        }
    }
}
