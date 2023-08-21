#include "algoritmos.h"

/**
    PosicionMenorElemento
    Parametros: Un arreglo y la cantidad de elementos
    Devuelve la posicion del menor elemento del arreglo.
**/
int PosicionMenorElemento(int *arreglo, int validos)
{
    int menorElemento = arreglo[0];
    int posicionMenor = 0;

    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i] < menorElemento)
        {
            menorElemento = arreglo[i];
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

/// --------------------------------------------------------------------

/**
    PosicionMenorDesdePosicionInicial
    Parametros: Un arreglo, la cantidad de elementos y una posicion inicial
    Devuelve la posicion del menor elemento del arreglo desde una posicion.
**/
int PosicionMenorDesdePosicionInicial(int *arreglo, int validos, int posicionInicial)
{
    int menorElemento = arreglo[posicionInicial];
    int posicionMenor = posicionInicial;

    for (int i = posicionInicial; i < validos; i++)
    {
        if (arreglo[i] < menorElemento)
        {
            menorElemento = arreglo[i];
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

/// --------------------------------------------------------------------

/**
    PosicionMayorElemento
    Parametros: Un arreglo, la cantidad de elementos
    Devuelve la posicion del mayor elemento del arreglo.
**/
int PosicionMayorElemento(int *arreglo, int validos)
{
    int mayorElemento = arreglo[0];
    int posicionMayor = 0;

    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i] > mayorElemento)
        {
            mayorElemento = arreglo[i];
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

/// --------------------------------------------------------------------

/**
    PosicionMayorDesdePosicionInicial
    Parametros: Un arreglo, la cantidad de elementos y una posicion inicial
    Devuelve la posicion del mayor elemento del arreglo desde una posicion.
**/
int PosicionMayorDesdePosicionInicial(int *arreglo, int validos, int posicionInicial)
{
    int mayorElemento = arreglo[posicionInicial];
    int posicionMayor = posicionInicial;

    for (int i = posicionInicial; i < validos; i++)
    {
        if (arreglo[i] > mayorElemento)
        {
            mayorElemento = arreglo[i];
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

/// --------------------------------------------------------------------

/**
    IntercambiarValores
    Parametros: Dos variables por referencia
    Intercambia sus valores
**/

void IntercambiarValores(int *primerValor, int *segundoValor)
{
    int auxiliar;

    auxiliar = *primerValor;
    *primerValor = *segundoValor;
    *segundoValor = auxiliar;
}

/// --------------------------------------------------------------------

/**
    OrdenarPorSeleccion
    Parametros: Un arreglo y la cantidad de elementos
    Ordena el arreglo por el metodo de seleccion
**/
void OrdenarPorSeleccion(int *arreglo, int validos)
{
    int posicionMenor = 0;

    for(int i = 0; i < validos - 1; i++)
    {
        /// Guardo la posicion del menor elemento a partir de la posicion i
        posicionMenor = PosicionMenorDesdePosicionInicial(arreglo, validos, i);

        /// Intercambio los valores
        IntercambiarValores(&arreglo[posicionMenor], &arreglo[i]);
    }
}

/// --------------------------------------------------------------------

/**
    OrdenarPorInsercion
    Parametros: Un arreglo y la cantidad de elementos
    Ordena el arreglo por el metodo de insercion
**/
void OrdenarPorInsercion(int *arreglo, int validos)
{
    int i = 0;
    while(i < validos)
    {
        InsertarOrdenado(arreglo, i, arreglo[i]);
        i++;
    }
}

/// --------------------------------------------------------------------

/**
    InsertarOrdenado
    Parametros: Un arreglo, la cantidad de elementos y el dato a insertar
    Inserta un elemento en un arreglo ordenado de manera ordenada y devuelve
    la cantidad de elementos validos.
**/
int InsertarOrdenado(int *arreglo, int validos, int dato)
{
    int i = validos - 1;

    ///Recorro desde el ultimo al primero
    while(i >= 0 && dato < arreglo[i])
    {
        ///muevo cada elemento un lugar a la derecha
        arreglo[i + 1] = arreglo[i];
        i--;
    }

    arreglo[i + 1] = dato;

    validos += 1;

    return validos;
}

/// --------------------------------------------------------------------

/**
    EstaEnVector
    Parametros: Letra a buscar, vector y tamaño del vector
    Busca si un elemento enviado por parametro se encuentra en el vector.
    Devuelve 1 si esta
    Devuelve 0 si no esta
**/
int EstaEnVector(char c, char *vector, int validos)
{
    for(int i = 0; i < validos; i++)
    {
        if(c == vector[i])
        {
            return 1;
        }
    }
    return 0;
}

/**
    InsertarOrdenadoString
    Parametros: Arreglo de caracteres, cantidad de elementos y el dato a insertar
    Inserta en el vector de manera ordenada el dato enviado por parametro y devuelve
    la cantidad de elementos validos
**/
int InsertarOrdenadoString(char *vector, int validos, char dato)
{
    int i, j;
    for(i = 0; i < validos && dato > vector[i]; i++)
    {
        // Buscar el índice donde se debe insertar el nuevo elemento
    }
    for(j = validos - 1; j >= i; j--)
    {
        // Desplazar los elementos mayores hacia la derecha
        vector[j+1] = vector[j];
    }
    vector[i] = dato; // Insertar el nuevo elemento en su posición correcta
    validos += 1;

    return validos;
}
