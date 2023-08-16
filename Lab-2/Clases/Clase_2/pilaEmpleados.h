#ifndef PILAEMPLEADOS_H_INCLUDED
#define PILAEMPLEADOS_H_INCLUDED

#include "empleado.h"

typedef struct
{
    stEmpleado * e;///mas adelante voy a crear un arreglo de manera dinamica, por eso uso puntero (y no defino tamaño ahora)
    int dim;      ///es decir que genero un puntero que apunte a una dir donde habra datos de tipo stEmpleado. Puede ser 1
    int v;        ///solo reg o varios(arreglo). Por esto tambien, no creo el arreglo de la manera clasica,(usando los [])
}pilaEmpleados;


void iniciaPilaEmpleados(pilaEmpleados *pe);///luego voy a dimensionar una pila, por eso uso 1 puntero
void apilarEmpleado(pilaEmpleados *pe, stEmpleado e);
stEmpleado desapilarEmpleado(pilaEmpleados *pe);
stEmpleado topeEmpleado(pilaEmpleados *pe);
int pilaVaciaEmpleados(pilaEmpleados *pe);


#endif // PILAEMPLEADOS_H_INCLUDED
