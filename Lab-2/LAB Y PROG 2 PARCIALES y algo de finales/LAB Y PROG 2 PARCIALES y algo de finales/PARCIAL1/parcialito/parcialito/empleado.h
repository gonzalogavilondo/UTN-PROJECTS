#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct {
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
}stEmpleado;

stEmpleado crearEmpleado();
void mostrarEmpleado(stEmpleado e);


#endif // EMPLEADO_H_INCLUDED
