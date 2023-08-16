#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDE

#define LONGMAX 25

typedef struct
{
    int id;
    char nombre[25];
    char apellido[25];
    int edad;

}stEmpleado;

stEmpleado cargarUnEmpleado();
void muestraUnEmpleado(stEmpleado);
char *empleadoToStr(stEmpleado);



#endif // EMPLEADO_H_INCLUDED
