#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "declaraciones.h"

/**
    10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
       quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo:

       Base 5 7 6 4 1 Tope
       Debe retornar el número: 14675
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
