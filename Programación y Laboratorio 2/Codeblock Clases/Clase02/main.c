#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "archivoEmpleados.h"

#define AR_EMPLEADOS "empleados.dat"

#define ESC 27
#define DIM_EMP 150


stEmpleado arrEmpleados[DIM_EMP];
int vEmp = 0;

int main()
{

    char opcion;
    int id;
    int cantEmpleados;

    do{
        muestraMenu();
        opcion=getch();

        switch(opcion) {
        case 49:
            cargaEmpleados(AR_EMPLEADOS);
            break;
        case 50:
            muestraEmpleados(AR_EMPLEADOS);
            break;
        case 51:
            system("cls");
            cantEmpleados = ultimoIdEmpleado(AR_EMPLEADOS);
            printf("Ingrese el ID del empleado: ");
            scanf("%i", &id);
            buscaEmpleadoEspecifico(AR_EMPLEADOS, id, cantEmpleados);
            system("pause");
            break;
        }

    }while(opcion!=ESC);

    return 0;
}

