#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA
{
    int dato;
    struct nodoA *izq;
    struct nodoA *der;
} nodoA;

typedef struct NodoLista
{
    int valor;
    struct NodoLista* siguiente;
} NodoLista;

nodoA* insertarEnArbol(nodoA* A, int dato) ;

nodoA* eliminarNodo(nodoA* A, int valorAEliminar);

nodoA* tomar_nodo_menor_valor (nodoA* arbolDeEnteros);

nodoA* eliminar_nodo_de_arbol (nodoA* arbolDeEnteros, int datoABorrar);

///======================================================================================

int main()
{
    nodoA* A = NULL;

    int datos[] = {5, 3, 7, 1, 4, 6, 9, 2, 8, 10};
    int cantNodos = sizeof(datos) / sizeof(datos[0]);

    for (int i = 0; i < cantNodos; i++)
    {
        A = insertarEnArbol(A, datos[i]);
    }

    printf("Arbol: \n");
    imprimirEnOrden(A);
    printf("\n\n");

    printf("Recorrido en PRE-ORDER\n");
    preorder(A);
    printf("\n\n");

    printf("Recorrido en IN-ORDER\n");
    inorder(A);
    printf("\n\n");

    printf("Recorrido en POS-ORDER\n");
    posorder(A);
    printf("\n\n");

    printf("Cantidad de nodos hoja: %d\n",contarNodosHoja(A));

    printf("Ingrese el dato a buscar: ");
    int dato;
    scanf("%d",&dato);

    ///opcion de busqueda 1
//    if(!buscarDato(A,dato))
//    {
//        printf("El dato NO esta en el arbol\n");
//    }
//    else
//    {
//        printf("El dato SI esta en el arbol\n");
//    }

    ///opcion de busqueda 2
    if(!buscarDato1(A,dato))
    {
        printf("El dato NO esta en el arbol\n");
    }
    else
    {
        printf("El dato SI esta en el arbol\n");
    }

    printf("Nodos de grado 1: %d\n",contarNodosGrado1(A));

    printf("Ingrese el nodo a eliminar: \n");
    int aEliminar;
    scanf("%d",&aEliminar);

    ///eliminarNodo(A, aEliminar);

    eliminar_nodo_de_arbol(A, aEliminar);
    imprimirEnOrden(A);


    return 0;
}

///======================================================================================

///Crear Nodo
nodoA* crearnodoArbol(int dato)
{
    nodoA* nuevo= (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
}

/// Función para insertar un nodo en el arbol
nodoA* insertarEnArbol(nodoA* A, int dato)
{
    if (A == NULL)
    {
        return crearnodoArbol(dato);
    }

    if (dato < A->dato)
    {
        A->izq = insertarEnArbol(A->izq, dato);
    }
    else if (dato > A->dato)
    {
        A->der = insertarEnArbol(A->der, dato);
    }

    return A;
}

///recorrido pre-order
void preorder(nodoA* A)
{
    if (A)
    {
        printf("%d ",A->dato);
        preorder(A->izq);
        preorder(A->der);
    }
}

///recorrido in-order
void inorder(nodoA* A)
{
    if (A)
    {
        inorder(A->izq);
        printf("%d ",A->dato);
        inorder(A->der);
    }
}

///recorrido pos-order
void posorder(nodoA* A)
{
    if (A)
    {
        posorder(A->izq);
        posorder(A->der);
        printf("%d ",A->dato);
    }
}

///buscar dato
int buscarDato(nodoA* A, int dato)
{
    int enc=0;
    if (A)
    {
        if (A->dato != dato)
        {
            enc = buscarDato(A->izq,dato);
            if (!enc)
            {
                enc=buscarDato(A->der,dato);
            }
        }
        else
            enc=1;
    }
    return enc;
}

///buscar dato - opcion 2
int buscarDato1( nodoA* A, int dato)
{
    if (A == NULL)
    {
        return 0;
    }

    if (A->dato == dato)
    {
        return 1;
    }

    if (buscarDato1(A->izq, dato) || buscarDato1(A->der, dato))
    {
        return 1;
    }

    return 0;///no estaba en el actual ni en ninguno de los sub-arboles...
}

/// Contar nodos hoja
int contarNodosHoja(nodoA* A)
{
    if (A == NULL)
    {
        return 0;
    }

    ///nodo hoja...
    if (A->izq == NULL && A->der == NULL)
    {
        return 1;
    }

    int hojasIzquierda = contarNodosHoja(A->izq);
    int hojasDerecha = contarNodosHoja(A->der);

    /// Sumamos las hojas encontradas en los subárboles izquierdo y derecho
    return hojasIzquierda + hojasDerecha;
}

int contarNodosHoja2(nodoA * A, int contador_hojas)
{
    if(A == NULL)
    {
        return contador_hojas;
    }
    else
    {
        contador_hojas = contarNodosHoja2(A->izq, contador_hojas);
        contador_hojas = contarNodosHoja2(A->der, contador_hojas);
        if(A->der == NULL && A->izq == NULL)
        {
            contador_hojas++;
        }
    }
    return contador_hojas;
}



int contarNodosGrado1(nodoA* A)
{
    if (A == NULL)
    {
        return 0;
    }

    int contador = 0;

    if ((A->izq != NULL && A->der == NULL) || (A->izq == NULL && A->der != NULL))
        //if ((A->izq == NULL) && (A->der == NULL))
    {
        contador += 1;
    }

    contador += contarNodosGrado1(A->izq);
    contador += contarNodosGrado1(A->der);

    return contador;
}

///funcion para insertar nodos
nodoA* insertarNodo(nodoA* A, int valor)
{
    if (A == NULL)
    {
        nodoA* nuevoNodo = (nodoA*)malloc(sizeof(nodoA));
        nuevoNodo->dato = valor;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }

    /// Si el valor es menor que el valor del nodo actual, insertar en el subarbol izquierdo
    if (valor < A->dato)
    {
        A->izq = insertarNodo(A->izq, valor);
    }
    /// Si el valor es mayor que el valor del nodo actual, insertar en el subarbol derecho
    else if (valor > A->dato)
    {
        A->der = insertarNodo(A->der, valor);
    }

    /// Si el valor ya está presente, no hacer nada!!! (no se permiten duplicados)

    return A;
}


///funcion para mostar un arbol
void imprimirEnOrden(nodoA* A)
{
    if (A != NULL)
    {
        imprimirEnOrden(A->izq);
        printf("%d ", A->dato);
        imprimirEnOrden(A->der);
    }
}

/// Función para insertar un nodo al final de la lista
NodoLista* insertarAlFinal( NodoLista* lista, int valor)
{
    NodoLista* nuevoNodo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL)
    {
        return nuevoNodo;
    }

    NodoLista* actual = lista;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    return lista;
}

/// Fcion. principal para copiar el arbol a la lista
NodoLista* copiarArbolALista(nodoA* A, NodoLista* lista)
{
    if (A != NULL)
    {
        lista = insertarAlFinal(lista, A->dato);

        lista = copiarArbolALista(A->izq, lista);
        lista = copiarArbolALista(A->der, lista);
    }
    return lista;
}

/// Función para buscar un nodo por "dato" en el árbol de forma recursiva
nodoA* buscarNodoPorDato(nodoA* A, int dato)
{
    if (A == NULL || A->dato == dato)
    {
        return A;
    }

    if (dato < A->dato)
    {
        return buscarNodoPorDato(A->izq, dato);
    }
    else
    {
        return buscarNodoPorDato(A->der, dato);
    }
}

///funcion/nes para eliminar un nodo

nodoA* encontrarMinimo(nodoA* A)
{
    while (A->izq != NULL)
    {
        A = A->izq;
    }
    return A;
}

nodoA* eliminarNodo(nodoA* A, int valorAEliminar)
{
    if (A == NULL)
    {
        return NULL;
    }

    /// Buscar el nodo que se desea eliminar en el subárbol izquierdo o derecho
    if (valorAEliminar < A->dato)
    {
        A->izq = eliminarNodo(A->izq, valorAEliminar);
    }
    else if (valorAEliminar > A->dato)
    {
        A->der = eliminarNodo(A->der, valorAEliminar);
    }
    else
    {
        /// el nodo a eliminar ha sido encontrado (NO FUE NI MENOR NI MAYOR)
        /// Caso 1: Nodo sin hijos o un solo hijo (los mas sencillos)
        if (A->izq == NULL)
        {
            nodoA* temp = A->der;
            free(A);
            return temp;
        }
        else if (A->der == NULL)
        {
            nodoA* temp = A->izq;
            free(A);
            return temp;
        }

        /// Caso 2: Nodo con dos hijos
        /// Encontrar el sucesor inmediato (nodo más a la izquierda en el subárbol derecho)
        nodoA* temp = encontrarMinimo(A->der);///funcion complementaria...

        /// Copiar el valor del sucesor inmediato al nodo actual
        A->dato = temp->dato;

        /// Eliminar el sucesor inmediato
        A->der = eliminarNodo(A->der, temp->dato);
    }

    return A;
}

///funcion para calcular la altura del arbol
int calcularAltura(nodoA* A)
{
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        int alturaIzquierda = calcularAltura(A->izq);
        int alturaDerecha = calcularAltura(A->der);

        if (alturaIzquierda > alturaDerecha)
        {
            return alturaIzquierda + 1;
        }
        else
        {
            return alturaDerecha + 1;
        }
    }
}

/// Función para calcular la cantidad de nodos
int calcularCantidadNodos(nodoA* A)
{
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        int nodosIzquierda = calcularCantidadNodos(A->izq);
        int nodosDerecha = calcularCantidadNodos(A->der);

        return nodosIzquierda + nodosDerecha + 1;
    }
}

/// Función para calcular la cantidad de hojas
int calcularCantidadHojas(nodoA* A)
{
    if (A == NULL)
    {
        return 0;
    }
    else if (A->izq == NULL && A->der == NULL)
    {
        ///el nodo actual es una hoja
        return 1;
    }
    else
    {
        int hojasIzquierda = calcularCantidadHojas(A->izq);
        int hojasDerecha = calcularCantidadHojas(A->der);

        return hojasIzquierda + hojasDerecha;
    }
}


/*
*
* Retorna el nodo de mayor valor (el nodo que esta mas a la derecha).
*
*/

nodoA* tomar_nodo_mayor_valor (nodoA* arbolDeEnteros)
{
    nodoA* mayorValor = NULL;

    if (arbolDeEnteros)
        {
        mayorValor = tomar_nodo_mayor_valor(arbolDeEnteros->der);

        if (!mayorValor)
            {
            mayorValor = arbolDeEnteros;
            }
        }

    return mayorValor;
}


/*
*
* Retorna el nodo de menor valor (el nodo que esta mas a la izquierda).
*
*/

nodoA* tomar_nodo_menor_valor (nodoA* arbolDeEnteros)
{
    nodoA* menorValor = NULL;

    if (arbolDeEnteros)
        {
        menorValor = tomar_nodo_menor_valor(arbolDeEnteros->der);

        if (!menorValor)
            {
            menorValor = arbolDeEnteros;
            }
        }

    return menorValor;
}

/*
*
* Elimina el nodo de un arbol binario
*
*/
nodoA* eliminar_nodo_de_arbol (nodoA* arbolDeEnteros, int datoABorrar)
{
    /*
    *
    * Si existen datos en el arbol, realizo los pasos, sino no me interesa
    * hacer nada. En caso de que este arbol no tenga datos, retornara su
    * contenido, que es: NULL (un arbol vacio apunta hacia la nada).
    *
    */
    if (arbolDeEnteros)
        {
        /**
        *
        * Si el dato del arbol, es igual al dato que queremos eliminar,
        * estamos en el nodo del arbol que va a ser eliminado.
        *
        */
        if (arbolDeEnteros->dato == datoABorrar)
            {
            /*
            *
            * Si el arbol tiene hijo izquierdo, el mas adecuado para reemplazarlo es
            * el nodo mas derecho de su hijo izquierdo (el de mayor valor de su hijo izquierdo).
            *
            */
            if (arbolDeEnteros->izq)
                {
                /*
                *
                * Guardo el nodo que quiero eliminar para utilizar free().
                *
                */
                nodoA* basura = tomar_nodo_mayor_valor(arbolDeEnteros->izq);

                /*
                *
                * Hago la llamada recursiva para su nodo derecho y
                * asi no perder el restode sus hijos.
                *
                */
                arbolDeEnteros->der = eliminar_nodo_de_arbol(arbolDeEnteros->der, basura->dato);

                /*
                *
                * Libero la memoria del nodo que quiero borrar.
                *
                */
                free(basura);
                }
            /*
            *
            * Sino ocurren otros 2 casos.
            *
            */
            else
                {
                /*
                *
                * Si el arbol, tiene hijo derecho, debera reemplazar ese nodo
                * con el nodo mas izquierdo de su hijo derecho
                *
                */
                if (arbolDeEnteros->der)
                    {
                    /**
                    *
                    * Guardo el nodo que quiero eliminar para utilizar free().
                    *
                    */
                    nodoA* basura = tomar_nodo_menor_valor(arbolDeEnteros->der);

                    /*
                    *
                    * Hago la llamada recursiva para su nodo
                    * izquierdo y no perder el resto de sus hijos.
                    *
                    */
                    arbolDeEnteros->der = eliminar_nodo_de_arbol(arbolDeEnteros->der, arbolDeEnteros->dato);

                    /*
                    *
                    * Libero la memoria del nodo que quiero eliminar.
                    *
                    */
                    free(basura);
                    }
                /*
                *
                * Si no tiene hijo derecho ni izquierdo, es un nodo hoja
                *
                */
                else
                    {
                    /*
                    *
                    * Libero la memoria de ese nodo que recibi por parametro
                    * ya que el nodo que quiero eliminar es una hojita (no tiene hijos :D).
                    *
                    */
                    free(arbolDeEnteros);

                    /*
                    *
                    * Le asigno NULL al arbol para
                    * retornarlo en la anterior llamada.
                    *
                    */
                    arbolDeEnteros = NULL;
                    }
                }
            }
        /*
        *
        * Si el dato que quiero eliminar no es igual, tengo 2 opciones
        *
        */
        else
            {
            /*
            *
            * Si el dato que quiero eliminar, es mayor al dato del nodo actual
            *
            */
            if (datoABorrar > arbolDeEnteros->dato)
                {
                /*
                *
                * Debo buscar por la rama derecha, devolviendo
                * esta rama modificada y asignandosela a la misma.
                *
                */
                arbolDeEnteros->der = eliminar_nodo_de_arbol(arbolDeEnteros->der, datoABorrar);
                }
            /*
            *
            * Si el dato que quiero eliminar, es menor al dato del nodo actual
            *
            */
            else
                {
                /*
                *
                * Debo buscar por la rama izquierda, devolviento
                * esta rama modificada y asignandosela a la misma.
                *
                */
                arbolDeEnteros->izq = eliminar_nodo_de_arbol(arbolDeEnteros->izq, datoABorrar);
                }
            }
        }


    /*
    *
    * Retorno el arbol con el nodo eliminado, al terminar cada llamada recursiva,
    * retornara el nodo padre con todo el arbol modificado "¡ :O !
    *
    */
    return arbolDeEnteros;
}
