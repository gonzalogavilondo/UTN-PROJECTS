#include "declaraciones.h"

/**
*   Ejercicio 1
**/
int archivo2ADA(celda arreglo[], int dimension)
{
    int validos = 0;
    FILE *buf = fopen("registroMedico.dat", "rb");

    stRegistroMedico aux;

    if(buf)
    {
        while(fread(&aux, sizeof(stRegistroMedico), 1, buf) > 0 && validos < dimension)
        {
            validos = alta(arreglo, validos, aux);
        }
        fclose(buf);
    }

    return validos;
}

int alta(celda arreglo[], int validos, stRegistroMedico aux)
{
    int pos = buscarPosicion(arreglo, validos, aux.idEspecialidad);

    if(pos == -1)
    {
        validos = agregarEspecialidad(arreglo, validos, aux.idEspecialidad, aux.especialidadMedica, aux.diagnostico, aux.fechaAtencion, aux.nombreDoctor);
        pos = validos - 1;
    }
    nodoArbol *nuevo = crearNodoArbol(aux);
    arreglo[pos].arbolEspecialidades = insertarNodo(arreglo[pos].arbolEspecialidades, nuevo);

    return validos;
}

nodoArbol* crearNodoArbol(stRegistroMedico aux)
{
    nodoArbol *nuevo = malloc(sizeof(nodoArbol));

    nuevo->dato = cargarDatoArbol(aux);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

stPaciente cargarDatoArbol(stRegistroMedico aux)
{
    stPaciente nuevo;

    nuevo.idPaciente = aux.idPaciente;
    strcpy(nuevo.nombrePaciente, aux.nombrePaciente);
    strcpy(nuevo.apellidoPaciente, aux.apellidoPaciente);

    return nuevo;
}

int buscarPosicion(celda arreglo[], int validos, int idEspecialidad)
{
    int pos = -1;
    int i = 0;

    while(i < validos && pos == -1)
    {
        if(arreglo[i].especialidad.idEspecialidad == idEspecialidad)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarEspecialidad(celda arreglo[], int validos, int idEspecialidad, char especialidadMedica[], char diagnostico[], char fechaAtencion[], char nombreDoctor[])
{
    arreglo[validos].especialidad.idEspecialidad = idEspecialidad;
    strcpy(arreglo[validos].especialidad.especialidadMedica, especialidadMedica);
    strcpy(arreglo[validos].especialidad.diagnostico, diagnostico);
    strcpy(arreglo[validos].especialidad.fechaAtencion, fechaAtencion);
    strcpy(arreglo[validos].especialidad.nombreDoctor, nombreDoctor);
    arreglo[validos].arbolEspecialidades = inicArbol();
    validos++;

    return validos;
}

nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *insertarNodo(nodoArbol *arbol, nodoArbol *nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.nombrePaciente, arbol->dato.nombrePaciente) > 0)
        {
            arbol->der = insertarNodo(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarNodo(arbol->izq, nuevo);
        }
    }

    return arbol;
}

/**
*   Ejercicio 2
**/
void mostrarADA(celda arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("------------------------------------\n");
        printf("Especialidad %s (ID %i)\nDiagnostico: %s\nFecha Atencion: %s\nNombreDoctor: %s\n", arreglo[i].especialidad.especialidadMedica, arreglo[i].especialidad.idEspecialidad, arreglo[i].especialidad.diagnostico, arreglo[i].especialidad.fechaAtencion, arreglo[i].especialidad.nombreDoctor );
        printf("------------------------------------\n");
        printf("------------------------------------\n");
        inorder(arreglo[i].arbolEspecialidades);
    }
}

void inorder(nodoArbol *arbol)
{
    if(arbol)
    {
        inorder(arbol->izq);
        mostrarPaciente(arbol->dato);
        inorder(arbol->der);
    }
}

void mostrarPaciente(stPaciente aux)
{
    printf("ID: %d\n", aux.idPaciente);
    printf("Nombre y apellido: %s %s\n", aux.nombrePaciente, aux.apellidoPaciente);
    printf("--------------------------------------------------\n");
}
//
///**
//* Ejercicio 3
//**/
//nodoArbol *buscarVendedorArreglo(celda arreglo[], int validos, int dni)
//{
//    int i = 0;
//    nodoArbol *busc = NULL;
//
//    while(i < validos && !busc)
//    {
//        busc = buscarVendedorArbol(arreglo[i].arbolVendedores, dni);
//        i++;
//    }
//
//    return busc;
//}
//
//nodoArbol *buscarVendedorArbol(nodoArbol *arbol, int dni)
//{
//    nodoArbol *busc = NULL;
//
//    if(arbol)
//    {
//        if(dni == arbol->dato.dni)
//        {
//            busc = arbol;
//        }
//        else
//        {
//            if(dni > arbol->dato.dni)
//            {
//                busc = buscarVendedorArbol(arbol->der, dni);
//            }
//            else
//            {
//                busc = buscarVendedorArbol(arbol->izq, dni);
//            }
//        }
//    }
//    return busc;
//}
//
///**
//* Ejercicio 4
//**/
//
//int cantidadVendedoresSuperiores(celda arreglo[], int validos, int idSector, int ventas)
//{
//    int pos = buscarPosicion(arreglo, validos, idSector);
//
//    if(pos != -1)
//    {
//        int cantidad = cantidadVendedoresSuperioresSector(arreglo[pos].arbolVendedores, ventas);
//        return cantidad;
//    }
//    else
//    {
//        return -1;
//    }
//}
//
//int cantidadVendedoresSuperioresSector2(nodoArbol *arbol, int ventas)
//{
//    int rta = 0;
//
//    if(arbol == NULL)
//    {
//        rta = 0;
//    }
//    else
//    {
//        if(arbol->dato.ventasDiarias > ventas)
//        {
//            rta = 1 + cantidadVendedoresSuperioresSector2(arbol->izq, ventas) + cantidadVendedoresSuperioresSector2(arbol->der, ventas);
//        }
//        else
//        {
//            rta = cantidadVendedoresSuperioresSector2(arbol->izq, ventas) + cantidadVendedoresSuperioresSector2(arbol->der, ventas);
//        }
//    }
//
//    return rta;
//}
//
//int cantidadVendedoresSuperioresSector(nodoArbol *arbol, int ventas)
//{
//    int cnt = 0;
//
//    if(arbol)
//    {
//        if(arbol->dato.ventasDiarias > ventas)
//        {
//            cnt++;
//        }
//        cnt += cantidadVendedoresSuperioresSector(arbol->izq, ventas);
//        cnt += cantidadVendedoresSuperioresSector(arbol->der, ventas);
//    }
//
//    return cnt;
//}
//
///**
//*   Ejercicio 5
//**/
//
//int sectorMasVentas(celda arreglo[], int validos)
//{
//    int idSector = 0,
//          ventas = 0,
//           mayor = 0,
//               i = 0;
//
//    while(i < validos)
//    {
//        ventas = sumarVentasSector(arreglo[i].arbolVendedores);
//        if(ventas > mayor)
//        {
//            mayor = ventas;
//            idSector = arreglo[i].sector.idSector;
//        }
//        i++;
//    }
//
//    return idSector;
//}
//
//int sumarVentasSector(nodoArbol *arbol)
//{
//    int ventas = 0;
//
//    if(arbol)
//    {
//        ventas += arbol->dato.ventasDiarias;
//        ventas += sumarVentasSector(arbol->izq);
//        ventas += sumarVentasSector(arbol->der);
//    }
//
//    return ventas;
//}
//
//int sumarValoresArbol(nodoArbol *arbol)
//{
//    int rta;
//
//    if(arbol == NULL)
//    {
//        rta = 0;
//    }
//    else
//    {
//        rta = arbol->dato.ventasDiarias + sumarValoresArbol(arbol->izq) + sumarValoresArbol(arbol->der);
//    }
//
//    return rta;
//}
//
///**
//*   Ejercicio 6
//**/
//
//float porcentajeVentas(celda arreglo[], int validos, int idSector)
//{
//    int pos = buscarPosicion(arreglo, validos, idSector);
//
//    if(pos != -1)
//    {
//        int ventasSector = sumarVentasSector(arreglo[pos].arbolVendedores);
//        int ventasTotales = calcularVentasTotales(arreglo, validos);
//        float porcentaje = (float) (ventasSector * 100) / ventasTotales;
//
//        return porcentaje;
//    }
//    else
//    {
//        return -1;
//    }
//}
//
//int calcularVentasTotales(celda arreglo[], int validos)
//{
//    int total = 0;
//
//    for(int i = 0; i < validos; i++)
//    {
//        total += sumarVentasSector(arreglo[i].arbolVendedores);
//    }
//
//    return total;
//}
