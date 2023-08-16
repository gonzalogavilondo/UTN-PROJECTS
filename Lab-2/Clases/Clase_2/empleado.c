#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

stEmpleado CargarUnEmpleado(void)///cargamos un empleado x a los fines practicos (no lo pedimos)
{
    stEmpleado e;

    static int id=0;
    id++;
    e.id = id;
    strcpy(e.nombre,"Isabel");
    strcpy(e.apellido,"Vega");
    e.edad = 46;

    return e;
}

void muestraUnEmpleado(stEmpleado e)
{
    printf("\n ID:...........%d",e.id);
    printf("\n Apellido:.....%s",e.apellido);
    printf("\n Nombre:.......%s",e.nombre);
    printf("\n Edad:.........%d",e.edad);
    printf("\n ---------------------------------------");
}
