#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "empleado.h"


int main()
{
    nodo * lista = iniclista();
    lista = agregarAlPrincipio(lista,crearNodo(crearEmpleado()));
    lista = agregarAlPrincipio(lista,crearNodo(crearEmpleado()));
    lista = agregarAlPrincipio(lista,crearNodo(crearEmpleado()));
    mostrarListaRecu(lista);


    return 0;
}
