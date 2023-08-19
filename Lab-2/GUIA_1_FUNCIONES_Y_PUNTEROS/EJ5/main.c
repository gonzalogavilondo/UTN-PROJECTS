#include "declaraciones.h"

/**
    Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones
    correspondientes a un año entero. Las filas corresponden a los meses y las columnas a los días. Se pide:
    a. Hacer una función para cargar la matriz de forma automática.
    b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
    c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
    mes de año.
    d. Hacer la función main con el menú correspondiente.
**/

int main()
{
    const int filas = 12;
    const int columnas = 31;
    int matriz[filas][columnas];
    int maximosPorMes[filas];

    ///Funcion para cargar matriz random
    cargarMatriz(matriz, filas, columnas);

    ///Almacenamos en un vector con las maximas precipitaciones por mes
    cargarMaximosPorMes(matriz, filas, columnas, maximosPorMes);

    ///Imprimimos el resultado
    imprimirVector(maximosPorMes, filas);

    printf("Dias de maxima precipitacion por mes:\n");

    return 0;
}
