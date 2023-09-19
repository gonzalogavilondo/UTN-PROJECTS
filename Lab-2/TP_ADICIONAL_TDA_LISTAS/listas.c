#include "listas.h"

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS
**/

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(int entero)
{
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = entero;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo* agregarAlInicio(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodo* buscaUltimoLista(nodo *lista)
{
    nodo *seg = lista; ///seg es seguidor
    if(seg != NULL) ///Lista esta vacia?
    {
        while(seg->siguiente != NULL) ///Recorro la lista
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodo* agregarAlFinal(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo *ultimo = buscaUltimoLista(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}


nodo *agregarOrdenado(nodo *nuevo, nodo *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(nuevo->dato < lista->dato)
        {
            lista = agregarAlInicio(nuevo, lista);
        }
        else
        {
            nodo *ante = lista;
            nodo *aux = lista;
            while(aux && nuevo->dato > aux->dato)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = aux;
        }
    }

    return lista;
}

nodo* borrarNodo(int entero, nodo *lista)
{
    nodo* aux;
    nodo* ante;
    if ((lista != NULL) && (entero == lista->dato))
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        aux = lista;
        while((aux != NULL) && (entero != aux->dato))
        {
            ante = aux;
            aux = aux->siguiente;
        }

        if(aux != NULL)
        {
            ante->siguiente = aux->siguiente;
            free(aux);
        }
    }
    return lista;
}

int borrarNodosRepetidos(int entero, nodo **lista)
{
    int cntNodosBorrados = 0; ///Inicializa el contador de nodos borrados a 0.
    nodo* aux = *lista; ///Crea un puntero auxiliar que apunte al inicio de la lista.
    nodo* ante = NULL; ///Inicializa un puntero anterior a NULL.

    while (aux != NULL) ///Itera mientras no se llegue al final de la lista.
    {
        if (entero == aux->dato) ///Comprueba si el valor del nodo actual es igual al valor buscado.
        {
            if (ante == NULL) ///Si el nodo a borrar es el primer nodo de la lista.
            {
                *lista = aux->siguiente; ///Actualiza el puntero al inicio de la lista.
                free(aux); ///Libera la memoria del nodo a borrar.
                aux = *lista; ///Avanza el puntero auxiliar al siguiente nodo.
            }
            else
            {
                ante->siguiente = aux->siguiente; ///Conecta el nodo anterior con el siguiente.
                nodo *temp = aux; ///Crea un puntero temporal para el nodo a borrar.
                aux = aux->siguiente; ///Avanza el puntero auxiliar al siguiente nodo.
                free(temp); ///Libera la memoria del nodo a borrar.
            }
            cntNodosBorrados++; ///Incrementa el contador de nodos borrados.
        }
        else
        {
            ante = aux; ///Avanza el puntero anterior al nodo actual.
            aux = aux->siguiente; ///Avanza el puntero auxiliar al siguiente nodo.
        }
    }

    return cntNodosBorrados; ///Devuelve la cantidad total de nodos borrados.
}

nodo* borrarPrimerNodo(nodo *lista)
{
    nodo *aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

nodo* borrarUltimoNodo(nodo *lista)
{
    nodo *aux;
    nodo *ante;
    if(lista != NULL)
    {
        if(lista->siguiente == NULL)
        {
            aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            aux = lista;
            while(aux->siguiente != NULL)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            free(aux);
            ante->siguiente = NULL;
        }
    }
    return lista;
}

nodo* buscarNodo(int dato, nodo *lista)
{
    nodo *seg = lista;

    while ((seg != NULL) && (seg->dato != dato))
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodo* borrarLista(nodo *lista)
{
    nodo *proximo;
    nodo *seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo *intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo *aux;

    while((lista_A != NULL) && (lista_B != NULL))
    {
        if(lista_A->dato < lista_B->dato)
        {
            aux = lista_A;
            lista_A = lista_A->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(aux, lista_C);
        }
        else
        {
            aux = lista_B;
            lista_B = lista_B->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinal(aux, lista_C);
        }
    }

    ///Si quedara algo en la lista A
    if(lista_A != NULL)
    {
        lista_C = agregarAlFinal(lista_A, lista_C);
    }
    ///Si quedara algo en la lista B
    else if(lista_B != NULL)
    {
        lista_C = agregarAlFinal(lista_B, lista_C);
    }

    return lista_C;
}

nodo* listaRandomOrdenado(nodo *lista, int cntElementos)
{
    int cnt = 0;

    if(lista == NULL)
    {
        while (cnt < cntElementos)
        {
            lista = agregarOrdenado(crearNodo(rand() % 99), lista);
            cnt++;
        }
    }
    return lista;
}

nodo* listaRandom50(nodo *lista, int cntElementos)
{
    int cnt = 0;

    if(lista == NULL)
    {
        if(cntElementos >= 50)
        {
            while (cnt < cntElementos)
            {
                lista = agregarAlFinal(crearNodo(rand() % 99), lista);
                cnt++;
            }
        }
        else
        {
            printf("La cantidad de elementos es insuficiente, debe haber al menos 50 en la lista\n");
        }

    }
    return lista;
}

nodo* invertirLista(nodo *lista)
{
    /// la idea es extraer el primero de la lista original
    /// y luego agregarlo al principio de la nueva lista
    /// retornamos el puntero al inicio de la nueva lista
    /// para pisar la referencia del main

    nodo *listaInvertida = NULL;
    nodo *aux;
    while(lista != NULL)
    {
        /// extraemos el primero (se puede modularizar)
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = NULL;

        /// lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarAlInicio(aux, listaInvertida);
    }
    return listaInvertida;
}

void mostrarListaEnteros(nodo *lista)
{
    nodo *aux = lista;
    printf("| ");
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
    printf("|\n");
}

int lista2array(nodo *lista, int **vec)
{
    int cnt = 0;
    while(lista != NULL)
    {
        AgregarAlFinalVec(vec, cnt, lista->dato);
        cnt++;
        lista = lista->siguiente;
    }
    return cnt;
}

int recorrerLista(nodo *lista, int **vec)
{
    nodo *aux = inicLista();

    int cnt    = 0;

    while(lista != NULL)
    {
        if(((lista->dato) % 2) == 0)
        {
           AgregarAlFinalVec(vec, cnt, lista->dato);
           cnt++;
        }
        else
        {
            aux = agregarAlFinal(crearNodo(lista->dato), aux); //Cargo en una lista auxiliar todos los impares
        }
        lista = lista->siguiente;
    }

    ///Agrego todos los impares al archivo de texto
    lista2archivoTxt_int(aux, "Impares.txt");

    return cnt;
}


/*****************************************************************************************************
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS
******************************************************************************************************/

/**
    ENTEROS: ARCHIVOS BINARIOS ***********************************************************************
**/

void generaArchivoBin_int(char archivo[])
{
    FILE *pArchEnteros = fopen(archivo, "wb");

    srand(time(0));

    if(pArchEnteros)
    {
        for (int i = 0; i < 10; i++)
        {
            int random = rand()%100;
            fwrite(&random, sizeof(int), 1, pArchEnteros);
        }
        fclose(pArchEnteros);
    }
}

void muestraArchivoBin_int(char archivo[])
{
    FILE *pArchEnteros = fopen(archivo, "rb");
    int aux;

    if(pArchEnteros)
    {
        while(fread(&aux, sizeof(int), 1, pArchEnteros) > 0)
        {
            printf(" %d -", aux);
        }
        fclose(pArchEnteros);
    }
    printf("\n");
}

nodo* archivoBin2lista_int(nodo *lista, char archivo[])
{
    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if(pArch)
    {
        while(fread(&entero, sizeof(int), 1, pArch) > 0)
        {
            lista = agregarAlFinal(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

void lista2archivoBin_int(nodo* lista, char archivo[])
{
    FILE* pArch = fopen(archivo, "wb");

    if(pArch)
    {
        while(lista)
        {
            fwrite(&(lista->dato), sizeof(int), 1, pArch);
            lista = lista->siguiente;
        }
        fclose(pArch);
    }
}

nodo* archivoBin2listaOrdenado_int(nodo *lista, char archivo[])
{
    FILE *pArch = fopen(archivo, "rb");
    int entero;

    if(pArch)
    {
        while(fread(&entero, sizeof(int), 1, pArch) > 0)
        {
            lista = agregarOrdenado(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}

/**
    ENTEROS: ARCHIVOS TXT ***********************************************************************
**/

void generaArchivoTxt_int(char archivo[])
{
    FILE *pArchEnteros = fopen(archivo, "w");

    srand(time(0));

    if (pArchEnteros)
    {
        for (int i = 0; i < 10; i++)
        {
            int random = rand() % 100;
            fprintf(pArchEnteros, "%d\n", random);
        }
        fclose(pArchEnteros);
    }
}

void lista2archivoTxt_int(nodo *lista, char archivo[])
{
    FILE* pArch = fopen(archivo, "w");

    if(pArch)
    {
        while(lista)
        {
            fprintf(pArch, "%d\n", lista->dato);
            lista = lista->siguiente;
        }
        fclose(pArch);
    }
}

nodo* archivoTxt2lista_int(nodo *lista, char archivo[])
{
    FILE* pArch = fopen(archivo, "r");
    int entero;

    if(pArch)
    {
        while(fscanf(pArch, "%d", &entero) != EOF)
        {
            lista = agregarAlFinal(crearNodo(entero), lista);
        }
        fclose(pArch);
    }
    return lista;
}


/**************************************************************************************************************************************************/
/*****
    LISTAS CON ESTRUCTURAS
*****/

#include "listas.h"

/**
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS
**/

nodoSt *inicListaSt()
{
    return NULL;
}

nodoSt * crearNodoSt(persona dato)
{
    ///crea un puntero de tipo nodoSt
    nodoSt * aux = (nodoSt*) malloc(sizeof(nodoSt));
    ///asigna valores a sus campos de información
    aux->dato = dato;
    ///asigna valor NULL al campo que contiene la dirección de memoria del
    ///siguiente nodoSt
    aux->siguiente = NULL;
    ///retorna la dirección de memoria del nuevo nodoSt, que deberá ser
    ///asignada a una variable de tipo "puntero a nodoSt".
    return aux;
}

nodoSt* agregarAlInicioSt(nodoSt *nuevo, nodoSt *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodoSt* buscaUltimoListaSt(nodoSt *lista)
{
    nodoSt *seg = lista; ///seg es seguidor
    if(seg != NULL) ///Lista esta vacia?
    {
        while(seg->siguiente != NULL) ///Recorro la lista
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodoSt* agregarAlFinalSt(nodoSt *nuevo, nodoSt *lista)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoSt *ultimo = buscaUltimoListaSt(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}


nodoSt* agregarOrdenadoSt(nodoSt *nuevoNodoSt, nodoSt *lista)
{
    /// agrega un nuevo nodoSt a la lista manteniendo el orden.
    ///si la lista está vacía agrego el primer elemento.
    if(lista == NULL)
    {
        lista = nuevoNodoSt;
    }
    else
    {
        ///si el nuevo elemento es menor que el primero de la lista,
        ///agrego al principio
        if(strcmp(nuevoNodoSt->dato.nombre,lista->dato.nombre)<0)
        {
            lista = agregarAlInicioSt(nuevoNodoSt, lista);
        }
        else
        {
            ///busco el lugar en donde insertar el nuevo elemento.
            ///necesito mantener la dirección de memoria del nodoSt anterior
            ///al nodoSt que tiene un nombre mayor al del nuevo nodoSt.
            nodoSt * ante = lista;
            nodoSt * seg = lista->siguiente;
            while((seg != NULL)&&(strcmp(nuevoNodoSt->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ///inserto el nuevo nodoSt en el lugar indicado.
            nuevoNodoSt->siguiente = seg;
            ante->siguiente = nuevoNodoSt;
        }
    }
    return lista;
}

nodoSt* agregarOrdenadoEdadSt(nodoSt *nuevoNodoSt, nodoSt *lista)
{
    /// agrega un nuevo nodoSt a la lista manteniendo el orden con respecto a la edad.
    ///si la lista está vacía agrego el primer elemento.
    if(lista == NULL)
    {
        ///printf("es el primero...\n");
        lista = nuevoNodoSt;
    }
    else
    {
        ///si el nuevo elemento es menor que el primero de la lista,
        ///agrego al principio
        if(nuevoNodoSt->dato.edad < lista->dato.edad)
        {
            ///printf("agrego al pcio...\n");
            lista = agregarAlInicioSt(nuevoNodoSt, lista);
        }
        else
        {
            ///printf("agrego en el medio/final...\n");
            ///busco el lugar en donde insertar el nuevo elemento.
            ///necesito mantener la dirección de memoria del nodoSt anterior
            ///al nodoSt que tiene un nombre mayor al del nuevo nodoSt.
            nodoSt *ante = lista;
            nodoSt *seg = lista->siguiente;
            while((seg != NULL)&&(nuevoNodoSt->dato.edad > seg->dato.edad))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ///inserto el nuevo nodoSt en el lugar indicado.
            nuevoNodoSt->siguiente = seg;
            ante->siguiente = nuevoNodoSt;
        }
    }

    return lista;
}

nodoSt *borrarNodoStSt(nodoSt * lista, char nombre[20])
{
    nodoSt * seg;
    nodoSt * ante; ///apunta al nodoSt anterior que seg.
    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 ))///encontre el nodoSt...
    {
        nodoSt * aux = lista;
        lista = lista->siguiente; ///salteo el primer nodoSt.
        free(aux); ///elimino el primer nodoSt.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 ))///mientras no lo encuentre...
        {
            ante = seg; ///adelanto una posición la variable ante.
            seg = seg->siguiente; ///avanzo al siguiente nodoSt.
        }
        ///en este punto tengo en la variable "ante" la dirección de
        ///memoria del nodoSt anterior al buscado, y en la variable "seg",
        ///la dirección de memoria del nodoSt que quiero borrar.
        if(seg!=NULL)///corto porque lo encontro
        {
            ante->siguiente = seg->siguiente;///salteo el nodoSt que quiero eliminar.
            free(seg);///elimino el nodoSt.
        }
    }
    return lista;
}


nodoSt* borrarPrimerNodoSt(nodoSt *lista)
{
    nodoSt *aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

nodoSt* borrarUltimoNodoSt(nodoSt *lista)
{
    nodoSt *aux;
    nodoSt *ante;
    if(lista != NULL)
    {
        if(lista->siguiente == NULL)
        {
            aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            aux = lista;
            while(aux->siguiente != NULL)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            free(aux);
            ante->siguiente = NULL;
        }
    }
    return lista;
}

nodoSt *buscarNodoSt(nodoSt *lista, char nombre[20])
{
    ///busca un nodoSt por nombre y retorna su posición de memoria
    ///si no lo encuentra retorna NULL.
    nodoSt * seg; ///apunta al nodoSt de la lista que está siendo procesado
    seg = lista; ///con esto evito cambiar el valor de la variable
    ///lista, que contiene un puntero al primer nodoSt de la
    ///lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
    {
        ///busco mientras me quede lista por recorrer y no haya encontrado el nombre
        seg=seg->siguiente; ///avanzo hacia el siguiente nodoSt.
    }
    ///en este punto puede haber fallado alguna de las dos condiciones
    ///del while. si falla la primera es debido a que no encontró lo
    ///que buscaba (seg es NULL), si falla la segunda es debido a que se
    ///encontró el nodoSt buscado.
    return seg;
}

nodoSt* borrarListaSt(nodoSt *lista)
{
    nodoSt *proximo;
    nodoSt *seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente; ///tomo la dir del siguiente.
        free(seg); ///borro el actual.
        seg = proximo; ///actualizo el actual con la dir del siguiente, para avanzar.
    }
    return seg; ///retorna NULL a la variable lista del main()
}

void borrarListaRecurSt(nodoSt* lista)
{
    if(lista)
    {
        borrarListaRecurSt(lista->siguiente);
        free(lista);
    }
}

nodoSt *intercalarListasSt(nodoSt *lista_A, nodoSt *lista_B, nodoSt *lista_C)
{
    nodoSt *aux;

    while((lista_A != NULL) && (lista_B != NULL))
    {
        if(lista_A->dato.edad < lista_B->dato.edad)
        {
            aux = lista_A;
            lista_A = lista_A->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinalSt(aux, lista_C);
        }
        else
        {
            aux = lista_B;
            lista_B = lista_B->siguiente;
            aux->siguiente = NULL;
            lista_C = agregarAlFinalSt(aux, lista_C);
        }
    }

    ///Si quedara algo en la lista A
    if(lista_A != NULL)
    {
        lista_C = agregarAlFinalSt(lista_A, lista_C);
    }
    ///Si quedara algo en la lista B
    else if(lista_B != NULL)
    {
        lista_C = agregarAlFinalSt(lista_B, lista_C);
    }

    return lista_C;
}

nodoSt* crearListaOrdenadaSt(nodoSt *lista)
{
    srand(time(NULL));
    char continua = 's';///para saber si continua o no...
    while (continua=='s')
    {
        ///esto debe hacerse bien, ahora cargo personas "a mano"...
        persona unaPersona;
        strcpy(unaPersona.nombre,"Isabel");
        unaPersona.edad = rand()%99+1;

        ///genero un nodoSt nuevo con la persona creada anteriormente
        nodoSt *nuevoNodo = crearNodoSt(unaPersona);
        mostrarUnNodoSt(nuevoNodo);

        ///voy insertando en la lista de manera ordenada segun la edad de la persona
        lista = agregarOrdenadoEdadSt(nuevoNodo, lista);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continua);
        printf("\n");
    }
    return lista;
}

nodoSt* invertirListaSt(nodoSt *lista)
{
    /// la idea es extraer el primero de la lista original
    /// y luego agregarlo al principio de la nueva lista
    /// retornamos el puntero al inicio de la nueva lista
    /// para pisar la referencia del main

    nodoSt *listaInvertida = NULL;
    nodoSt *aux;
    while(lista != NULL)
    {
        /// extraemos el primero (se puede modularizar)
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = NULL;

        /// lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarAlInicioSt(aux, listaInvertida);
    }
    return listaInvertida;
}

void mostrarUnNodoSt(nodoSt *aux)
{
    if (aux != NULL)
    {
        printf("Nombre: %s\n", aux->dato.nombre);
        printf("Edad: %d\n", aux->dato.edad);
    }
    else
    {
        printf("NodoSt no válido.\n");
    }
}

void mostrarListaStruct(nodoSt *lista)
{
    nodoSt * aux = lista;
    while(aux != NULL)
    {
        mostrarUnNodoSt(aux);
        aux = aux->siguiente;
    }
}

void recorrerYmostrarRecursivaSt(nodoSt *lista)
{
    if(lista != NULL)
    {
        mostrarUnNodoSt(lista);
        recorrerYmostrarRecursivaSt(lista->siguiente);
    }
}


int sumarEdadesListaSt(nodoSt *lista)
{
    ///recorro la lista y sumo las edades de los socios.
    int suma = 0;
    nodoSt * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->dato.edad;
        seg = seg->siguiente;
    }
    return suma;
}

/*****************************************************************************************************
    FUNCIONES BASICAS PARA EL MANEJO DE LISTAS CON ARCHIVOS
******************************************************************************************************/

/**
    ENTEROS: ARCHIVOS BINARIOS ***********************************************************************
**/

void generaArchivoBin_struct(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }
    persona personaNueva;
    char continua = 's';
    while(continua == 's')
    {
        ///MODULARIZAR LA CARGA DE UNA PERSONA...
        printf("Ingrese el nombre: \n");
        scanf("%s",personaNueva.nombre);
        printf("Ingrese la edad: \n");
        scanf("%d",&personaNueva.edad);

        fwrite(&personaNueva,sizeof(personaNueva),1,archivo);

        printf("Ingrese otro nombre (s/n): \n");
        fflush(stdin);
        scanf("%c",&continua);
    }

    /// Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados en el archivo '%s'.\n", nombreArchivo);
}

void lista2archivoBin_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodoSt *actual = lista;
    while(actual != NULL)
    {
        fwrite(&(actual->dato), sizeof(persona), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodoSt* archivoBin2lista_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1); // Codigo de error
    }
    persona personaNueva;
    rewind(archivo);
    while(fread(&personaNueva, sizeof(persona), 1, archivo) > 0)
    {
        lista = agregarAlFinalSt(crearNodoSt(personaNueva), lista);
    }
    fclose(archivo);
    return lista;
}

/**
    ENTEROS: ARCHIVOS TXT ***********************************************************************
**/

void generaArchivoTxt_struct(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    persona *personaNueva;
    char continua = 's';

    while (continua == 's')
    {
        cargarPersona(&personaNueva);

        // Escribir en el archivo en formato de texto
        fprintf(archivo, "%s %d\n", personaNueva->nombre, personaNueva->edad);

        printf("Ingrese otro nombre (s/n): \n");
        fflush(stdin);
        scanf(" %c", &continua);  // Nota: se agrega un espacio antes de %c para ignorar los espacios en blanco

        // Si el usuario no ingresa 's', el bucle se detiene
        if (continua != 's')
            break;
    }

    /// Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados en el archivo '%s'.\n", nombreArchivo);
}

void lista2archivoTxt_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodoSt *actual = lista;
    while (actual != NULL)
    {
        fprintf(archivo, "%s %d\n", actual->dato.nombre, actual->dato.edad);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodoSt* archivoTxt2lista_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");

    /// Veo si se pudo abrir el archivo
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return NULL;  // Devolvemos NULL en caso de error
    }

    persona personaNueva;

    while (fscanf(archivo, "%s %d", personaNueva.nombre, &personaNueva.edad) == 2) //El 2 indica la cantidad de campos que tiene la estructura "persona"
    {
        lista = agregarAlFinalSt(crearNodoSt(personaNueva), lista);
    }

    fclose(archivo);
    return lista;
}
