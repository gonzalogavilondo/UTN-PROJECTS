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

//    for(int i = 0; i < 2; i++)
//    {
//        muestraUnEmpleado(pE.e[i]); ///PREGUNTAR! YO CUANDO DESAPILO NO PIERDO LA REFERENCIA, SINO QUE LOS VALIDOS AL SER 0 NO HACE EL RECORRIDO, ENTONCES PARECIERA QUE SE PERDIO LA REFERENCIA PERO NO
//    }                               ///HACER LA PRUEBA COMENTANDO EN LA FUNCION mostrarPilaEmpleados EL ULTIMO WHILE

    ///Guardar la pila en un archivo
    guardarPilaEnArchivo(&pE);

    return 0;
}
