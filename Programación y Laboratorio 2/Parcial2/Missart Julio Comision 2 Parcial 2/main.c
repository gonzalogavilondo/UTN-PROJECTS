#include <stdio.h>
#include <stdlib.h>
#include "registroArchivo.h"
#include "especialidad.h"
#include "paciente.h"
#include <conio.h>

#define DIM 10
#define ESC 27

void menu();

int main()
{
    stEspecialidadMedica arregloEspecialidades[DIM];
    char nombreSpec[30];
    int vEspecialidad = 0;
    char opcion;
    int result;
    do {
        system("cls");
        menu();
        fflush(stdin);
        opcion = getch();
        switch(opcion) {
            case 49:
                vEspecialidad = cargarEspecialidad(arregloEspecialidades, vEspecialidad, DIM);
                break;
            case 50:
                system("cls");
                muestraEstructura(arregloEspecialidades, vEspecialidad);
                printf("\n");
                system("pause");
                break;
            case 51:
                printf("\nIngrese el nombre de la especialidad a buscar: ");
                gets(nombreSpec);
                result = buscaEspecialidadMedica(arregloEspecialidades, vEspecialidad, nombreSpec);
                if(result == 1) {
                    printf("\nEXISTE.\n");
                    } else {
                    printf("\nNO EXISTE.\n");
                }
                system("pause");
                break;
        }

    }while(opcion!=ESC);

    return 0;
}

void menu() {
    printf("\n1. Cargar una especialidad nueva.");
    printf("\n2. Mostrar todas las especialidades con sus listas de pacientes.");
    printf("\n3. Buscar si una especialidad existe.");
}
