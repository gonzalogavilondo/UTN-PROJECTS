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

    ///Cargo empleados especificando la cantidad.
    cargarPilaEmpleados(&pE);

    ///Una pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Muestro la pila
    mostrarPilaEmpleados(&pE);

    ///Guardar la pila en un archivo
    guardarPilaEnArchivo(&pE);

    return 0;
}
