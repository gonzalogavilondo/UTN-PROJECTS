#include "empleado.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


stEmpleado crearEmpleado(){
    stEmpleado e;
    puts("ingrese nombre:\n");
    fflush(stdin);
    gets(e.nombre);
    puts("ingrese apellido:\n");
    fflush(stdin);
    gets(e.apellido);
    puts("ingrese dni:\n");
    scanf("%d",&e.dni);
    puts("ingrese edad:\n");
    scanf("%d",&e.edad);
    return e;
}

void mostrarEmpleado(stEmpleado e){

printf("nombre: %s",e.nombre);
printf("    apellido: %s",e.apellido);
printf("    dni: %d",e.dni);
printf("    edad: %d  \n",e.edad);

}


