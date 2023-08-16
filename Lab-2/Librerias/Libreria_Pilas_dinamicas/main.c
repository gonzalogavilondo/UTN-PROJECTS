#include "pilaEmpleados.h"

/**
    Armar funcion que muestre una pila sin perderla, otra que cargue empleados y otra que reciba la pila
    y guarde los elementos en un archivo
**/

int main()
{
    ///Es una estructura creada por el programador
    pilaEmpleados pE;

    ///Inicializamos la pila para cargarle datos
    iniciaPilaEmpleados(&pE);


    ///MUESTRO UNA PILA CON 30 EMPLEADOS (SE TUBO QUE REDIMENSIONAR PORQUE NOS PASAMOS DE LOS 10 DE DIM)
    for (int i = 0; i < 5; i++)
    {
        apilarEmpleado(&pE, cargarUnEmpleado());
    }

    mostrarPilaEmpleados(&pE);

    return 0;
}
