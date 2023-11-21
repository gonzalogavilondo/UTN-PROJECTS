#include "declaraciones.h"

/**
*   Ejercicio 1
**/
int archivo2ADA(celda arreglo[])
{
    int validos = 0;
    FILE *buf = fopen("archivoRegistrosVendedor.bin", "rb");

    stRegistroVendedor aux;

    if(buf)
    {
        while(fread(&aux, sizeof(stRegistroVendedor), 1, buf) > 0 && validos < MAXDIM)
        {
            validos = alta(arreglo, validos, aux);
        }
        fclose(buf);
    }

    return validos;
}

int alta(celda arreglo[], int validos, stRegistroVendedor aux)
{
    int pos = buscarPosicion(arreglo, validos, aux.idSector);

    if(pos == -1)
    {
        validos = agregarSector(arreglo, validos, aux.idSector, aux.sector);
        pos = validos - 1;
    }
    nodoArbol *nuevo = crearNodoArbol(aux);
    arreglo[pos].arbolVendedores = insertarNodo(arreglo[pos].arbolVendedores, nuevo);

    return validos;
}

nodoArbol* crearNodoArbol(stRegistroVendedor aux)
{
    nodoArbol *nuevo = malloc(sizeof(nodoArbol));

    nuevo->dato = cargarDatoArbol(aux);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

stVendedor cargarDatoArbol(stRegistroVendedor aux)
{
    stVendedor nuevo;

    nuevo.dni = aux.dni;
    strcpy(nuevo.nombreYapellido, aux.nombreYapellido);
    nuevo.ventasDiarias = aux.ventasDiarias;

    return nuevo;
}

int buscarPosicion(celda arreglo[], int validos, int idSector)
{
    int pos = -1;
    int i = 0;

    while(i < validos && pos == -1)
    {
        if(arreglo[i].sector.idSector == idSector)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarSector(celda arreglo[], int validos, int idSector, char sector[])
{
    arreglo[validos].sector.idSector = idSector;
    strcpy(arreglo[validos].sector.sector, sector);
    arreglo[validos].arbolVendedores = inicArbol();
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
        if(nuevo->dato.dni > arbol->dato.dni)
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
        printf("Sector %s (ID %i)\n", arreglo[i].sector.sector, arreglo[i].sector.idSector);
        printf("------------------------------------\n");
        printf("------------------------------------\n");
        inorder(arreglo[i].arbolVendedores);
    }
}

void inorder(nodoArbol *arbol) //Muestro los pacientes en orden de acuerdo al nombre y apellido
{
    if(arbol)
    {
        inorder(arbol->izq);
        mostrarVendedor(arbol->dato);
        inorder(arbol->der);
    }
}

void mostrarVendedor(stVendedor aux)
{
    printf("DNI: %d\n", aux.dni);
    printf("Nombre y apellido: %s\n", aux.nombreYapellido);
    printf("Ventas diarias: %d\n", aux.ventasDiarias);
    printf("--------------------------------------------------\n");
}

/**
* Ejercicio 3
**/
nodoArbol *buscarVendedorArreglo(celda arreglo[], int validos, int dni)
{
    int i = 0;
    nodoArbol *busc = NULL;

    while(i < validos && !busc)
    {
        busc = buscarVendedorArbol(arreglo[i].arbolVendedores, dni);
        i++;
    }

    return busc;
}

nodoArbol *buscarVendedorArbol(nodoArbol *arbol, int dni)
{
    nodoArbol *busc = NULL;

    if(arbol)
    {
        if(dni == arbol->dato.dni)
        {
            busc = arbol;
        }
        else
        {
            if(dni > arbol->dato.dni)
            {
                busc = buscarVendedorArbol(arbol->der, dni);
            }
            else
            {
                busc = buscarVendedorArbol(arbol->izq, dni);
            }
        }
    }
    return busc;
}

/**
* Ejercicio 4
**/

int cantidadVendedoresSuperiores(celda arreglo[], int validos, int idSector, int ventas)
{
    int pos = buscarPosicion(arreglo, validos, idSector);

    if(pos != -1)
    {
        int cantidad = cantidadVendedoresSuperioresSector(arreglo[pos].arbolVendedores, ventas);
        return cantidad;
    }
    else
    {
        return -1;
    }
}

int cantidadVendedoresSuperioresSector2(nodoArbol *arbol, int ventas)
{
    int rta = 0;

    if(arbol == NULL)
    {
        rta = 0;
    }
    else
    {
        if(arbol->dato.ventasDiarias > ventas)
        {
            rta = 1 + cantidadVendedoresSuperioresSector2(arbol->izq, ventas) + cantidadVendedoresSuperioresSector2(arbol->der, ventas);
        }
        else
        {
            rta = cantidadVendedoresSuperioresSector2(arbol->izq, ventas) + cantidadVendedoresSuperioresSector2(arbol->der, ventas);
        }
    }

    return rta;
}

int cantidadVendedoresSuperioresSector(nodoArbol *arbol, int ventas)
{
    int cnt = 0;

    if(arbol)
    {
        if(arbol->dato.ventasDiarias > ventas)
        {
            cnt++;
        }
        cnt += cantidadVendedoresSuperioresSector(arbol->izq, ventas);
        cnt += cantidadVendedoresSuperioresSector(arbol->der, ventas);
    }

    return cnt;
}

/**
*   Ejercicio 5
**/

int sectorMasVentas(celda arreglo[], int validos)
{
    int idSector = 0,
          ventas = 0,
           mayor = 0,
               i = 0;

    while(i < validos)
    {
        ventas = sumarVentasSector(arreglo[i].arbolVendedores);
        if(ventas > mayor)
        {
            mayor = ventas;
            idSector = arreglo[i].sector.idSector;
        }
        i++;
    }

    return idSector;
}

int sumarVentasSector(nodoArbol *arbol)
{
    int ventas = 0;

    if(arbol)
    {
        ventas += arbol->dato.ventasDiarias;
        ventas += sumarVentasSector(arbol->izq);
        ventas += sumarVentasSector(arbol->der);
    }

    return ventas;
}

int sumarValoresArbol(nodoArbol *arbol)
{
    int rta;

    if(arbol == NULL)
    {
        rta = 0;
    }
    else
    {
        rta = arbol->dato.ventasDiarias + sumarValoresArbol(arbol->izq) + sumarValoresArbol(arbol->der);
    }

    return rta;
}

/**
*   Ejercicio 6
**/

float porcentajeVentas(celda arreglo[], int validos, int idSector)
{
    int pos = buscarPosicion(arreglo, validos, idSector);

    if(pos != -1)
    {
        int ventasSector = sumarVentasSector(arreglo[pos].arbolVendedores);
        int ventasTotales = calcularVentasTotales(arreglo, validos);
        float porcentaje = (float) (ventasSector * 100) / ventasTotales;

        return porcentaje;
    }
    else
    {
        return -1;
    }
}

int calcularVentasTotales(celda arreglo[], int validos)
{
    int total = 0;

    for(int i = 0; i < validos; i++)
    {
        total += sumarVentasSector(arreglo[i].arbolVendedores);
    }

    return total;
}
