#include "declaraciones.h"

/**
*   Ejercicio 1
**/

listaCeldas* archivo2LDA()
{
    listaCeldas *lista = NULL;
    FILE *buf = fopen(ARCHIVO_VENDEDORES, "rb");

    stRegistroVendedor aux;

    if (buf)
    {
        while (fread(&aux, sizeof(stRegistroVendedor), 1, buf) > 0)
        {
            lista = altaEnLista(lista, aux);
        }
        fclose(buf);
    }

    return lista;
}
listaCeldas* altaEnLista(listaCeldas *lista, stRegistroVendedor aux)
{
    int pos = buscarPosicionEnLista(lista, aux.idSector);

    if (pos == -1)
    {
        // Si no se encuentra el sector, agregar uno nuevo al final de la lista
        listaCeldas *nuevaCelda = malloc(sizeof(listaCeldas));
        if (nuevaCelda)
        {
            nuevaCelda->sector.idSector = aux.idSector;
            strcpy(nuevaCelda->sector.sector, aux.sector);
            nuevaCelda->arbolVendedores = inicArbol();
            nuevaCelda->siguiente = NULL;  // La nueva celda será el último elemento

            // Agregar al final de la lista usando las funciones proporcionadas
            lista = agregarFinal(lista, nuevaCelda);
        }
        else
        {
            // Manejo de error: no se pudo asignar memoria para la nueva celda
            printf("\nNo se pudo asignar memoria para la nueva celda.\n");
            return lista;
        }
    }

    nodoArbol *nuevo = crearNodoArbol(aux);
    listaCeldas *celdaActual = lista;
    for (int i = 0; i < pos; i++)
    {
        celdaActual = celdaActual->siguiente;
    }

    celdaActual->arbolVendedores = insertarNodo(celdaActual->arbolVendedores, nuevo);

    return lista;
}


listaCeldas* agregarFinal(listaCeldas* lista, listaCeldas* nuevaCelda)
{
    if (lista == NULL)
    {
        lista = nuevaCelda;
    }
    else
    {
        listaCeldas* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevaCelda;
    }
    return lista;
}

listaCeldas* buscarUltimo(listaCeldas* lista)
{
    listaCeldas* seg = lista;
    if (seg)
    {
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}


int buscarPosicionEnLista(listaCeldas *lista, int idSector)
{
    int pos = -1;
    int i = 0;
    listaCeldas *seg = lista;

    while (seg && pos == -1)
    {
        if (seg->sector.idSector == idSector)
        {
            pos = i;
        }

        seg = seg->siguiente;
        i++;
    }

    return pos;
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
void mostrarLDA(listaCeldas *lista)
{
    while (lista)
    {
        printf("------------------------------------\n");
        printf("Sector %s (ID %i)\n", lista->sector.sector, lista->sector.idSector);
        printf("------------------------------------\n");
        printf("------------------------------------\n");
        inorder(lista->arbolVendedores);
        lista = lista->siguiente;
    }
}

void inorder(nodoArbol *arbol)
{
    if (arbol)
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
nodoArbol *buscarVendedorLista(listaCeldas *lista, int dni)
{
    nodoArbol *busc = NULL;

    while (lista && !busc)
    {
        busc = buscarVendedorArbol(lista->arbolVendedores, dni);
        lista = lista->siguiente;
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

int cantidadVendedoresSuperiores(listaCeldas *lista, int idSector, int ventas)
{
    int cantidad = 0;

    listaCeldas *celdaActual = lista;
    while (celdaActual)
    {
        if (celdaActual->sector.idSector == idSector)
        {
            cantidad = cantidadVendedoresSuperioresSector(celdaActual->arbolVendedores, ventas);
            break;
        }
        celdaActual = celdaActual->siguiente;
    }

    return cantidad;
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

    if (arbol)
    {
        cnt += cantidadVendedoresSuperioresSector(arbol->izq, ventas);
        cnt += cantidadVendedoresSuperioresSector(arbol->der, ventas);

        if (arbol->dato.ventasDiarias > ventas)
        {
            cnt++;
        }
    }

    return cnt;
}


/**
*   Ejercicio 5
**/

int sectorMasVentas(listaCeldas *lista)
{
    int idSector = 0,
        ventas = 0,
        mayor = 0;

    while (lista)
    {
        ventas = sumarVentasSector(lista->arbolVendedores);
        if (ventas > mayor)
        {
            mayor = ventas;
            idSector = lista->sector.idSector;
        }
        lista = lista->siguiente;
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

float porcentajeVentas(listaCeldas *lista, int idSector)
{
    int ventasSector = 0;
    int ventasTotales = 0;

    while (lista)
    {
        if (lista->sector.idSector == idSector)
        {
            ventasSector = sumarVentasSector(lista->arbolVendedores);
        }
        ventasTotales += sumarVentasSector(lista->arbolVendedores);

        lista = lista->siguiente;
    }

    if (ventasTotales > 0)
    {
        return (float)(ventasSector * 100) / ventasTotales;
    }
    else
    {
        return -1;
    }
}

int calcularVentasTotalesLista(listaCeldas *lista)
{
    int total = 0;

    while (lista)
    {
        total += sumarVentasSector(lista->arbolVendedores);
        lista = lista->siguiente;
    }

    return total;
}

void liberarListaCeldas(listaCeldas *lista)
{
    while (lista)
    {
        nodoArbol *arbolActual = lista->arbolVendedores;
        while (arbolActual)
        {
            nodoArbol *siguiente = arbolActual->der;
            free(arbolActual);
            arbolActual = siguiente;
        }

        listaCeldas *siguienteLista = lista->siguiente;
        free(lista);
        lista = siguienteLista;
    }
}

void lda2archivo(listaCeldas *lista)
{
    FILE *archivo = fopen("backup.bin", "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    stSector sector;
    while (fread(&sector, sizeof(stSector), 1, archivo) > 0)
    {
        listaCeldas nuevaCelda;
        nuevaCelda.sector = sector;
        nuevaCelda.arbolVendedores = leerArbolDesdeArchivo(archivo);
        nuevaCelda.siguiente = lista;
        lista = &nuevaCelda;
    }

    fclose(archivo);

    // Mostrar la lista para verificar que se haya cargado correctamente
    mostrarLDA(lista);
}

nodoArbol* leerArbolDesdeArchivo(FILE *archivo)
{
    nodoArbol *arbol = NULL;
    stVendedor vendedor;

    while (fread(&vendedor, sizeof(stVendedor), 1, archivo) > 0)
    {
        nodoArbol *nuevo = malloc(sizeof(nodoArbol));
        nuevo->dato = vendedor;
        nuevo->izq = leerArbolDesdeArchivo(archivo);
        nuevo->der = leerArbolDesdeArchivo(archivo);

        arbol = insertarNodo(arbol, nuevo);
    }

    return arbol;
}


