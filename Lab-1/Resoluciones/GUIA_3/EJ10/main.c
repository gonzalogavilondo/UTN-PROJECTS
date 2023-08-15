#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "declaraciones.h"

/**
    10. Hacer una funci�n que reciba una pila con n�meros de un solo d�gito (es responsabilidad de
       quien usa el programa) y que transforme esos d�gitos en un n�mero decimal. Por ejemplo:

       Base 5 7 6 4 1 Tope
       Debe retornar el n�mero: 14675
**/

int main()
{
    Pila pila;
    int resultado = 0;

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

    ///Procesamiento principal
    resultado = pilaAdecimal(&pila);

    ///Mostramos el resultado
    printf("El numero decimal resultante es: %d\n", resultado);

    return 0;
}
