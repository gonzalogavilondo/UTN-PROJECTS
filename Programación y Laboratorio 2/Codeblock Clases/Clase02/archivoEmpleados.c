#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "archivoEmpleados.h"

#define AR_EMPLEADOS "empleados.dat"
#define ESC 27

void muestraMenu(){
    system("cls");
    printf("\n\n\t\t Menu - Julio Missart - Comision 2");
    printf("\n\n\n");
    printf("\n1. Cargar empleados.");
    printf("\n2. Mostrar empleados.");
    printf("\n3. Buscar empleado especifico.");
}


/****************************//**
/* \brief Crea un empleado con intervencion del usuario.
/* \param ninguno.
/* \return Retorna un empleado.
/********************************/
stEmpleado cargaUnEmpleado(char archivoEmpleados[]){
    stEmpleado e;
    int existe;
    e.id = ultimoIdEmpleado(archivoEmpleados)+1;

    do{
        system("cls");
        printf("\t~Cargando un empleado.~\n\n");
        printf("\nID: %i", e.id);
        printf("\nDNI: ");
        fflush(stdin);
        gets(e.persona.dni);

        existe = existeDNIEmpleado(e.persona.dni, archivoEmpleados);
        if (existe == 1) {
        printf("\nEl empleado ya existe en nuestro sistema.\n");
        system("pause");
        }

    }while(existe);

    printf("\nNombre: ");
    fflush(stdin);
    gets(e.persona.nombre);

    printf("\nApellido: ");
    fflush(stdin);
    gets(e.persona.apellido);

    printf("\nCuit: ");
    fflush(stdin);
    gets(e.cuit);

    printf("\nE-Mail: ");
    fflush(stdin);
    gets(e.email);

    printf("\nDomicilio Particular: ");
    fflush(stdin);
    gets(e.domicilioParticular);

    printf("\nTelefono Fijo: ");
    fflush(stdin);
    gets(e.telefonoFijo);

    printf("\nTelefono Celular: ");
    fflush(stdin);
    gets(e.telefonoCel);

    printf("\nTipo de empleado: ");
    scanf(" %i", &e.idTipo);

    printf("\nSueldo: ");
    scanf(" %i", &e.sueldo);

    return e;
}

/*******************//**
/* \brief Ciclo de carga de empleados
/* \param recibe un arreglo con el nombre de archivo de empleados
/**********************/
void cargaEmpleados(char archivoEmpleados[]){
    stEmpleado e;
    char opcion;

    do{
        e = cargaUnEmpleado(archivoEmpleados);
        guardaEmpleadoArchivo(e, archivoEmpleados);

        printf("\nPresione ESC para salir. Presione cualquier tecla para continuar cargando empleados.");
        fflush(stdin);
        opcion=getch();
    }while(opcion!=ESC);

}

int ultimoIdEmpleado(char archivoEmpleados[]) {

    int ultimoId = -1;
    stEmpleado e;

    FILE *pArchEmpleados = fopen(archivoEmpleados, "rb");

    if(pArchEmpleados) {
            fseek(pArchEmpleados, sizeof(stEmpleado)*(-1), SEEK_END);
            if(fread(&e, sizeof(stEmpleado), 1, pArchEmpleados) > 0) {
                ultimoId = e.id;
            }
            fclose(pArchEmpleados);
    }

    return ultimoId;

}

int existeDNIEmpleado(char DNI[], char archivoEmpleados[]) {
    int flag = 0;
    stEmpleado e;
    FILE *pArchEmpleados = fopen(archivoEmpleados, "rb");

    if(pArchEmpleados) {
        while(flag == 0 && fread(&e, sizeof(stEmpleado), 1, pArchEmpleados) > 0) {
            if (strcmp(e.persona.dni, DNI) == 0) {
                flag = 1;
            }
        }
        fclose(pArchEmpleados);
    }

    return flag;
}

void guardaEmpleadoArchivo(stEmpleado e, char archivoEmpleados[]){
    FILE *pArchEmpleados = fopen(archivoEmpleados, "ab");

    if(pArchEmpleados) {
        fwrite(&e, sizeof(stEmpleado), 1, pArchEmpleados);
        fclose(pArchEmpleados);
    }
}

void muestraUnEmpleado(stEmpleado e){
    printf("\n----------------------------------------");
    printf("\nID del Empleado............: %i", e.id);
    printf("\nNombre.....................: %s", e.persona.nombre);
    printf("\nApellido...................: %s", e.persona.apellido);
    printf("\nDNI........................: %s", e.persona.dni);
    printf("\nCUIT.......................: %s", e.cuit);
    printf("\nEmail......................: %s", e.email);
    printf("\nDomicilio Particular.......: %s", e.domicilioParticular);
    printf("\nNumero de Telefono Fijo....: %s", e.telefonoFijo);
    printf("\nNumero de Telefono Celular.: %s", e.telefonoCel);
    printf("\nTipo de Empleado...........: %i", e.idTipo);
    printf("\nSueldo.....................: %i", e.sueldo);
    printf("\n----------------------------------------");
}

void muestraEmpleados(char archivoEmpleados[]){
    system("cls");
    FILE *pArchEmpleados = fopen(archivoEmpleados, "rb");
    stEmpleado e;
    if(pArchEmpleados) {
        while(fread(&e, sizeof(stEmpleado), 1, pArchEmpleados) > 0) {
            muestraUnEmpleado(e);
        }
        fclose(pArchEmpleados);
    }
    printf("\n");
    system("pause");
}

void buscaEmpleadoEspecifico(char archivoEmpleados[], int id, int cantEmpleados) {

    stEmpleado e;
    FILE *pArchEmpleados = fopen(archivoEmpleados, "rb");

    if (pArchEmpleados) {
            if (id <= cantEmpleados && id >= 0) {
            fseek(pArchEmpleados, sizeof(stEmpleado)*id, SEEK_SET);
            fread(&e, sizeof(stEmpleado), 1, pArchEmpleados);
            muestraUnEmpleado(e);
            fclose(pArchEmpleados);
            }
            else
            {
                printf("\nEl empleado no existe en nuestro sistema.\n");
            }
    }
    printf("\n");
}


int archivoEmpleados2Arreglo(char archivoEmpleados[], stEmpleado e[], int dim) {
    FILE *pArchEmpleados = fopen(archivoEmpleados, "rb");
    if(pArchEmpleados) {
        while(v < dim && fread(&e[v], sizeof(stEmpleado), 1, pArchEmpleados) > 0) {
            v++;
        }
        fclose(pArchEmpleados);
    }
    return v;
}
