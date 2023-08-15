#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED

typedef struct{
        char apellido[30];
        char nombre[30];
        char dni[10];
    }stPersona;

        typedef struct{
        int id;
        stPersona persona;
        char cuit[15];
        char email[90];
        char domicilioParticular[50];
        char telefonoFijo[15];
        char telefonoCel[15];
        int idTipo;
        int sueldo;
    }stEmpleado;

    stEmpleado cargaUnEmpleado(char archivoEmpleados[]);
    void muestraUnEmpleado(stEmpleado e);
    void cargaEmpleados(char archivoEmpleados[]);
    int ultimoIdEmpleado(char archivoEmpleados[]);
    int existeDNIEmpleado(char DNI[], char archivoEmpleados[]);
    void guardaEmpleadoArchivo(stEmpleado e, char archivoEmpleados[]);
    void muestraEmpleados(char archivoEmpleados[]);
    void buscaEmpleadoEspecifico(char archivoEmpleados[], int id, int cantEmpleados);
    void muestraMenu();
    int archivoEmpleados2Arreglo(char archivoEmpleados[], stEmpleado e[], int dim);
#endif // ARCHIVOEMPLEADOS_H_INCLUDED
