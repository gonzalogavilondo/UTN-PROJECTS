#include "declaraciones.h"

/**
    Sea una matriz de n�meros enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones
    correspondientes a un a�o entero. Las filas corresponden a los meses y las columnas a los d�as. Se pide:
    a. Hacer una funci�n para cargar la matriz de forma autom�tica.
    b. Hacer una funci�n que retorne el d�a de m�xima precipitaci�n para un mes determinado.
    c. Hacer una funci�n que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
    mes de a�o.
    d. Hacer la funci�n main con el men� correspondiente.
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
