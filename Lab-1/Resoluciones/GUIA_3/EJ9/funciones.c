#include "declaraciones.h"

/**
    Para insertar un elemento en una pila ordenada de menor a mayor sin utilizar variables enteras adicionales,
    se puede utilizar una pila auxiliar para desapilar los elementos de la pila original que son mayores que el
    elemento a insertar y apilarlos en la pila auxiliar. Luego, se apila el nuevo elemento en la pila original y
    se desapilan los elementos de la pila auxiliar y se apilan de nuevo en la pila original. De esta manera, se
    garantiza que la pila esté ordenada de menor a mayor después de la inserción del nuevo elemento.
**/

void cargarPila(Pila *p)
{
    char control = '0';
    int num = 0;
    do
    {
        printf("Ingrese numeros a la pila o 0 para terminar: ");
        fflush(stdin);
        scanf("%d", &num);
        if(num != 0)
        {
            apilar(p, num);
        }
        else
        {
            printf("Desea agregar el '0' a la pila? <SI/NO> <S/CUALQ. OTRA LETRA> ");
            fflush(stdin);
            scanf("%c", &control);
            if(control == 'S' || control == 's')
            {
                apilar(p, num);
                num = 1; //Cambio el numero para que se siga agregando valores
            }
        }

    }while (num != 0 );
}

void insertarEnOrden(Pila *pila, int dato)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pila) && tope(pila) > dato)
    {
        apilar(&aux, desapilar(pila));
    }
    apilar(pila, dato);

    while (!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}

void pasarPila(Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

int menorPila(Pila *pila)
{
    Pila pilaMenor, aux;
    int flagEncontrado = 0,
        valor          = 0;

    ///Inicializamos todas las pilas
    inicpila(&pilaMenor);
    inicpila(&aux);

    while (!pilavacia(pila))
    {
        valor = desapilar(pila);
        if (!flagEncontrado || valor < tope(&pilaMenor))
        {
            if (flagEncontrado)
            {
                apilar(&aux, desapilar(&pilaMenor));
            }
            apilar(&pilaMenor, valor);
            flagEncontrado = 1; //Flag que se encontro un nuevo valor menor.
        }
        else
        {
            apilar(&aux, valor);
        }
    }

    ///Volvemos a dejar la pila con todos sus valores menos el menor encontrado
    pasarPila(&aux, pila);

    ///Asigno el menor valor de la pila que va a quedar en el tope a valor.
    valor = desapilar(&pilaMenor);

    return valor;
}

void ordenamientoPorSeleccion(Pila *origen, Pila *destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, menorPila(origen));
    }
}

int longitudPila(Pila *pila)
{
    Pila aux;
    inicpila(&aux);

    int cnt = 0;
    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cnt++;
    }

    ///Volvemos a poner la pila original como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cnt;
}

int sumarElementosPila(Pila *pila)
{
    ///Definimos e inicializamos pilas
    Pila aux;
    int sumatoria = 0;

    inicpila(&aux);

    ///Recorro la pila sumando sus elementos
    while(!pilavacia(pila))
    {
        sumatoria += tope(pila);
        apilar(&aux, desapilar(pila));
    }

    ///Uso aux para dejar la pila como estaba antes
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return sumatoria;
}

float calcularPromedioPila(int suma, int cantidad)
{
    return suma/cantidad;
}

float promedioElementosPila(Pila *pila)
{
    int cntElementos  = 0,
        sumaElementos = 0;

    float promedio = 0.0;

    cntElementos = longitudPila(pila);
    sumaElementos = sumarElementosPila(pila);
    promedio = calcularPromedioPila(sumaElementos, cntElementos);

    return promedio;
}
