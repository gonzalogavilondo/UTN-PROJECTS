#include <stdio.h>
#include <stdlib.h>

#include "pilaEmpleados.h"



int main()
{
    ///Es una estructura creada por el programador
    pilaEmpleados pe;
    ///Inicializamos la pila para cargarle datos
    iniciaPilaEmpleados(&pe);


    /**
    ///MUESTRO UN EMPLEADO
    stEmpleado emp;

    emp = CargarUnEmpleado();

    apilarEmpleado(&pe,emp);

    if (!pilaVaciaEmpleados(&pe))
    {
        muestraUnEmpleado(topeEmpleado(&pe));
    }

    */

    ///MUESTRO UNA PILA CON 50 EMPLEADOS (SE TUBO QUE REDIMENSIONAR PORQUE NOS PASAMOS DE LOS 10 DE DIM)
    for (int i=0;i<100;i++)
    {
        apilarEmpleado(&pe, CargarUnEmpleado());
    }

    while(! pilaVaciaEmpleados (&pe))
    {
        muestraUnEmpleado(desapilarEmpleado(&pe));
    }

    printf("Hello world!\n");



    return 0;
}

///armar funcion que muestre una pila sin perderla y otra que cargue empleados y otra que reciba la pila
///y guarde los elementos en un archivo


