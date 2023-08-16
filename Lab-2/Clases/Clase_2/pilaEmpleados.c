#include <stdio.h>
#include <stdlib.h>

#include "pilaEmpleados.h"
#include <malloc.h>


void iniciaPilaEmpleados(pilaEmpleados *pe)
{
    ///inicializo la pila, es decir, la estoy creando!!!

    ///cuando se tiene un punt (*pe) a una struct, nos referimos a los campos de esa struct, usando "->"
    pe->dim = 10; /// ej: a lo que apunta pe, en su dato dim, le cargo 10

    ///Inicializamos el arreglo en 0
    pe->v = 0;

    ///La propiedad e de la pila apuntara
    ///a un espacio de memoria RESERVADO
    pe->e = (stEmpleado *) malloc (sizeof (stEmpleado) * pe->dim);///creo arreglo de empleados de forma dinamica (nunca use [])
}

void apilarEmpleado(pilaEmpleados *pe, stEmpleado e)
{
    if (pe->v == pe->dim)///si la pila esta llena
    {
        pe->dim = pe->dim * 2 ;///duplico (por ejemplo) la dimension de la pila
        pe->e = (stEmpleado *)realloc(pe->e, sizeof (stEmpleado) * pe->dim); ///y ahora si, duplico el arreglo de empleados
        ///acabo de REDIMENSIONAR el arreglo, usando REALLOC:(que quiero redimensionar, tamaño nuevo)
    }
    pe->e [pe->v] = e; ///recordar que "e" es un arreglo: asigno a la pos validos,
                    ///el empleado recibido por parametro
    pe->v++;///incremento los validos
}

stEmpleado desapilarEmpleado(pilaEmpleados * pe)
{
    stEmpleado e; ///empleado a "devolver"

    e = pe->e [pe->v - 1];///al empleado que voy a devolver, le asigo el ultimo cargado en el arreglo (v-1)
    pe->v --;///decremento los validos, debido a que acabo de quitar un empleado

    return e;
}

stEmpleado topeEmpleado(pilaEmpleados *pe)
{
    stEmpleado e;

    e = pe->e [pe->v - 1];///al empleado que voy a devolver, le asigo el ultimo cargado (v-1)

    return e;
}


int pilaVaciaEmpleados (pilaEmpleados * emps)
{
    int vacia;

    if (emps->v == 0)
        {
        vacia = 1;
        }
    else
        {
        vacia = 0;
        }

    return vacia;
}
///
int pilaVaciaEmpleadosTernario(pilaEmpleados * pe)
{
    return (pe->v == 0) ? 1 : 0; ///use operador ternario (condicion, accion verdadera, accion falsa)
}



