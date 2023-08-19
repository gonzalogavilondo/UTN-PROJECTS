#include "declaraciones.h"
void cargarMatriz(int matriz[][31], int filas, int columnas)
{
    // Código para cargar la matriz de forma automática (puedes modificarlo)
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand() % 100; // Valores aleatorios entre 0 y 99
        }
    }
}

int diaMaximaPrecipitacion(int matriz[][31], int mes, int columnas)
{
    int maximo = matriz[mes - 1][0];
    int diaMaximo = 1;
    for (int i = 1; i < columnas; i++)
    {
        if (matriz[mes - 1][i] > maximo)
        {
            maximo = matriz[mes - 1][i];
            diaMaximo = i + 1;
        }
    }
    return diaMaximo;
}

void cargarMaximosPorMes(int matriz[][31], int filas, int columnas, int maximos[])
{
    for (int i = 0; i < filas; i++)
    {
        maximos[i] = diaMaximaPrecipitacion(matriz, i + 1, columnas);
    }
}


void imprimirVector(int vec[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("Mes %d: Dia %d\n", i + 1, vec[i]);
    }
}
