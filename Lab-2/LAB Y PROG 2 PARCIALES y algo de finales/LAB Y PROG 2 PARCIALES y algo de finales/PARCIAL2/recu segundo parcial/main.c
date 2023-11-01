#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
 int idSector;
 char sector[30];///los sectores son (y estan escritos tal cual): "ropa","muebles","electro"
 int dni;
 char nombreYapellido[40];
 int ventasDiarias;

}stRegistroVendedor;


/*** ESTRUCTURAS DEL ARBOL */
typedef struct
{
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stVendedor;

typedef struct
{
    stVendedor vendedor;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
}nodoArbol;


/*** ESTRUCTURAS DEL ARREGLO */
typedef struct
{
    int idSector;
    char sector[30];
}stSector;

typedef struct
{
    stSector sector;
    nodoArbol* arbolVendedor;

}stCelda;

/* ------------------------------ */


/* FUNCONES PUNTO 1 */

/* FUNCIONES DE ARBOL */
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stVendedor v);
nodoArbol* insertarNodo(nodoArbol* arbol , nodoArbol* nuevoNodo);
void mostrarUnVendedor(stVendedor v);
void mostrarArbolInOrder(nodoArbol* arbol);

/* FUNCIONES DEL ARREGLO */
int buscarPosSector(stCelda arraySector[] , int validos , int idSector);
int agregarSector(stCelda arraySector[] , int validos ,  stSector sector);
int altaSector(stCelda arraySector[] , stSector sector , stVendedor vendedor , int validos);
stVendedor cargarUnVendedor(int dni , char nombreYape[] , int ventasDiarias);
stSector cargaUnSector(int idSector , char sector[]);
int pasarArchToAda(char nombreArchivo[] , stCelda arraySector[] , int validos , int dimension);

/* FUNCIONES PUNTO 2 */
void mostrarUnSector(stSector sec);
void mostrarAda(stCelda arraySector[] , int validos);

/* FIN FUNCONES PUNTO 1 */

/* FUNCIONES PUNTO 3 */
nodoArbol* buscarEmpleadoArbol(nodoArbol* arbol , int dni);
int buscarEmpleado(stCelda arraySector[] , int validos , nodoArbol* arbol , int dni , int idSector);

/* FUNCION PUNTO 4 */
int buscarSectorMaxVentasDiarias(stCelda arraySector[] , int validos ,  int idSector , int maxVentasDiarias);

/* FUNCION PUNTO 5 */
int sumarVentas(stCelda arraySector[] , int validos , int idSector):

int main()
{
    char archRegVendedor[] = {"archivoRegistrosVendedor.bin"};
    stCelda arraySector[50];
    int valVendedor = 0;

    valVendedor = pasarArchToAda(archRegVendedor , arraySector , valVendedor , 50);

    printf(" ARREGLO DE ARBOLES... \n\n");
    mostrarAda(arraySector , valVendedor);



    return 0;
}

/* -------------------------------------------- FUNCIONES PUNTO 1 -------------------------------------------- */

/* FUNCIONES DE ARBOL */
/* inicializa el arbol */
nodoArbol* inicArbol()
{
    return NULL;
}

/* crea un nodo arbol */
nodoArbol* crearNodoArbol(stVendedor v)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->vendedor = v;
    aux->izquierda = NULL;
    aux->derecha = NULL;

    return aux;
}

/* inserta un nodo */
nodoArbol* insertarNodo(nodoArbol* arbol , nodoArbol* nuevoNodo)
{
    if(arbol == NULL){
        arbol = nuevoNodo;
    }else{
        if(nuevoNodo->vendedor.dni < arbol->vendedor.dni){
            arbol->izquierda = insertarNodo(arbol->izquierda , nuevoNodo);
        }else{
            arbol->derecha = insertarNodo(arbol->derecha , nuevoNodo);
        }
    }

    return arbol;
}

/* muestra un vendedor */
void mostrarUnVendedor(stVendedor v)
{
    printf(" ------------------------ \n");
    printf(" DNI: %d \n" , v.dni);
    printf(" Nombre y apellido: %s \n" , v.nombreYapellido);
    printf(" Ventas diarias: %d \n" , v.ventasDiarias);
    printf(" ------------------------ \n\n");
}

/* muestra un arbol */
void mostrarArbolInOrder(nodoArbol* arbol)
{
    if(arbol != NULL){
        mostrarArbolInOrder(arbol->izquierda);
        mostrarUnVendedor(arbol->vendedor);
        mostrarArbolInOrder(arbol->derecha);
    }
}

/* agrega un sector en el arreglo */
int agregarSector(stCelda arraySector[] , int validos ,  stSector sector)
{
    arraySector[validos].sector = sector;
    arraySector[validos].arbolVendedor = inicArbol();
    validos++;

    return validos;
}

/* busca la posicion de un sector en el arreglo */
int buscarPosSector(stCelda arraySector[] , int validos , int idSector)
{
    int pos = -1;
    int i = 0;

    while((pos == -1) && (i<validos)){
        if(arraySector[i].sector.idSector == idSector){
            pos = i;
        }

        i++;
    }

    return pos;
}

/* funcion que carga los sectores en el array */
int altaSector(stCelda arraySector[] , stSector sector , stVendedor vendedor , int validos)
{
    nodoArbol* nuevoNodo = crearNodoArbol(vendedor);
    int pos = buscarPosSector(arraySector , validos , sector.idSector);

    if(pos == -1){
        validos = agregarSector(arraySector , validos , sector);
        pos = validos-1;
    }

    arraySector[pos].arbolVendedor = insertarNodo(arraySector[pos].arbolVendedor , nuevoNodo);

    return validos;
}

/* carga un vendedor */
stVendedor cargarUnVendedor(int dni , char nombreYape[] , int ventasDiarias)
{
    stVendedor aux;

    aux.dni = dni;
    strcpy(aux.nombreYapellido , nombreYape);
    aux.ventasDiarias = ventasDiarias;

    return aux;
}

/* carga un sector */
stSector cargaUnSector(int idSector , char sector[])
{
    stSector auxSector;

    auxSector.idSector = idSector;
    strcpy(auxSector.sector , sector);

    return auxSector;
}

/* pasa los datos del archivo al array de arboles */
int pasarArchToAda(char nombreArchivo[] , stCelda arraySector[] , int validos , int dimension)
{
    stRegistroVendedor aux;
    FILE* pArchivo = fopen(nombreArchivo , "rb");
    stSector sec;
    stVendedor ven;

    if(pArchivo != NULL){
        while((fread(&aux , sizeof(stRegistroVendedor) , 1 , pArchivo) > 0) && (validos < dimension)){
            sec = cargaUnSector(aux.idSector , aux.sector);
            ven = cargarUnVendedor(aux.dni , aux.nombreYapellido , aux.ventasDiarias);
            validos = altaSector(arraySector , sec , ven , validos);
        }
        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return validos;
}

/* PUNTO 2 */

/* muestra un sector */
void mostrarUnSector(stSector sec)
{
    printf(" **************** \n");
    printf(" ID Sector: %d \n" , sec.idSector);
    printf(" Sector: %s \n" , sec.sector);
    printf(" **************** \n\n");
}

/* muestra el arreglo de arboles */
void mostrarAda(stCelda arraySector[] , int validos)
{
    int i;

    for(i=0 ; i<validos ; i++){
        mostrarUnSector(arraySector[i].sector);
        mostrarArbolInOrder(arraySector[i].arbolVendedor);
    }
}

/* ------------------------------------------- FIN FUNCIONES PUNTO 1 -------------------------------------------- */

/* PUNTO 3 */

/* busca un empleado en el arbol */
nodoArbol* buscarEmpleadoArbol(nodoArbol* arbol , int dni)
{
    nodoArbol* encontrado = NULL;

    if(arbol != NULL){
        if(arbol->vendedor.dni == dni){
            encontrado = arbol;
        }else{
            if(dni < arbol->vendedor.dni){
                arbol->izquierda = buscarEmpleadoPorID(arbol->izquierda , dni);
            }else{
                arbol->derecha = buscarEmpleadoPorID(arbol->derecha , dni);
            }
        }
    }

    return encontrado;
}

/* retorna las ventas diaras  */
int buscarEmpleado(stCelda arraySector[] , int validos , nodoArbol* arbol , int dni , int idSector)
{
    int ventasDiariasEmpleado = 0;
    int pos = buscarPosSector(arraySector , validos , idSector);
    nodoArbol* encontrado = buscarEmpleadoPorID(arbol , dni);

    if(pos != -1){
        encontrado = buscarEmpleadoArbol(arbol , dni);

        if(encontrado != NULL){
             ventasDiariasEmpleado = encontrado->vendedor.ventasDiarias;
        }else{
            printf(" El empleado no existe. \n\n");
        }
    }

    return ventasDiariasEmpleado;
}


/* FIN PUNTO 3 */

/* PUNTO 4 */

int buscarSectorMaxVentasDiarias(stCelda arraySector[] , int validos ,  int idSector , int maxVentasDiarias)
{
    int pos = buscarPosSector(arraySector , validos , idSector);
    int rta = 0;

    if(pos != -1){
        if(arraySector[pos].arbolVendedor != NULL){
            if(arraySector[pos].arbolVendedor->vendedor.ventasDiarias > maxVentasDiarias){
                rta = 1 + arraySector[pos].arbolVendedor->izquierda + arraySector[pos].arbolVendedor->derecha;
            }else{
                rta = arraySector[pos].arbolVendedor->izquierda + arraySector[pos].arbolVendedor->derecha;
            }
        }
    }else{
        printf(" El sector no existe. \n\n");
    }

    return rta;
}

/* FIN PUNTO 4 */

/* PUNTO 5 */

int sumarVentas(stCelda arraySector[] , int validos , int idSector)
{
    int rta = 0;
    int pos = buscarPosSector(arraySector , validos , idSector);

    if(pos != -1){
        if(arraySector[pos].arbolVendedor != NULL){
            rta = arraySector[pos].arbolVendedor->vendedor.ventasDiarias + arraySector[pos].arbolVendedor->izquierda + arraySector[pos].arbolVendedor->derecha;
        }else{
            rta = arraySector[pos].arbolVendedor->izquierda + arraySector[pos].arbolVendedor->derecha;
        }
    }

    return rta;
}

stSector mayorSector(stCelda arraySector[] , int validos , int ventasDiarias)
{
    int mayorVenta;
    int i;

    for(i= 0 ; i<validos ; i++){
        if(arraySector[i].arbolVendedor != NULL){
            mayorVenta = mayor(arraySector[i].arbolVendedor->izquierda.vendedor.ventasDiarias , arraySector[i].arbolVendedor->derecha.vendedor.ventasDiarias);
        }
    }

    return mayorVenta;
}

int mayor(int num1 , int num2)
{
    int mayorNum = 0;

    if(num1 > num2){
        mayor = num1;
    }else{
        mayor = num2;
    }

    return mayorNum;
}

/* FIN PUNTO 5 */
