#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "declaraciones.h"

/**
    9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
       una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
       funciones, y la función que calcula el promedio invoca a las otras 3
**/

int main()
{
    Pila pila;
    float resultado = 0.0;

    /// Inicializamos las pilas.
    inicpila(&pila);

    /// Cargamos una pila de forma ordenada como pide el enunciado.
    printf("CARGUE LA PILA: \n");
    cargarPila(&pila);

    ///Pausa y limpiar pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila.
    printf("--PILA--\n");
    mostrar(&pila);

    ///Llamamos a la funcion que llama a las demas y calcula el promedio
    resultado = promedioElementosPila(&pila);

    ///Mostramos el resultado
    printf("\nEl promedio de la pila es: %.2f \n", resultado);

    return 0;
}
