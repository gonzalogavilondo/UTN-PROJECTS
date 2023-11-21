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
    nodo *seg = lista;
    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
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
    int cntNodosBorrados = 0;
    nodo* aux = *lista;
    nodo* ante = NULL;

    while (aux != NULL)
    {
        if (entero == aux->dato)
        {
            if (ante == NULL)
            {
                *lista = aux->siguiente;
                free(aux);
                aux = *lista;
            }
            else
            {
                ante->siguiente = aux->siguiente;
                nodo *temp = aux;
                aux = aux->siguiente;
                free(temp);
            }
            cntNodosBorrados++;
        }
        else
        {
            ante = aux;
            aux = aux->siguiente;
        }
    }

    return cntNodosBorrados;
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

    if(lista_A != NULL)
    {
        lista_C = agregarAlFinal(lista_A, lista_C);
    }
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
    nodo *listaInvertida = NULL;
    nodo *aux;
    while(lista != NULL)
    {
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = NULL;

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
            aux = agregarAlFinal(crearNodo(lista->dato), aux);
        lista = lista->siguiente;
    }

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

nodoSt *crearNodoSt(stNotaAlumno dato)
{
    nodoSt * aux = (nodoSt*) malloc(sizeof(nodoSt));
    aux->dato = dato;
    aux->siguiente = NULL;
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
    nodoSt *seg = lista;
    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
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
    if(lista == NULL)
    {
        lista = nuevoNodoSt;
    }
    else
    {
        if(strcmp(nuevoNodoSt->dato.apeNom,lista->dato.apeNom)<0)
        {
            lista = agregarAlInicioSt(nuevoNodoSt, lista);
        }
        else
        {
            nodoSt * ante = lista;
            nodoSt * seg = lista->siguiente;
            while((seg != NULL)&&(strcmp(nuevoNodoSt->dato.apeNom,seg->dato.apeNom)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodoSt->siguiente = seg;
            ante->siguiente = nuevoNodoSt;
        }
    }
    return lista;
}

nodoSt* agregarOrdenadoNotaSt(nodoSt *nuevoNodoSt, nodoSt *lista)
{
    if(lista == NULL)
    {
        lista = nuevoNodoSt;
    }
    else
    {
        if(nuevoNodoSt->dato.nota < lista->dato.nota)
        {
            lista = agregarAlInicioSt(nuevoNodoSt, lista);
        }
        else
        {
            nodoSt *ante = lista;
            nodoSt *seg = lista->siguiente;
            while((seg != NULL)&&(nuevoNodoSt->dato.nota > seg->dato.nota))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodoSt->siguiente = seg;
            ante->siguiente = nuevoNodoSt;
        }
    }

    return lista;
}

nodoSt *borrarNodoSt(nodoSt * lista, char nombre[20])
{
    nodoSt * seg;
    nodoSt * ante;
    if((lista != NULL) && (strcmp(nombre, lista->dato.apeNom)==0 ))
    {
        nodoSt * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.apeNom)!=0 ))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
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
    nodoSt * seg;
    seg = lista;
    while ((seg != NULL) && (strcmp(nombre, seg->dato.apeNom)!= 0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodoSt* borrarListaSt(nodoSt *lista)
{
    nodoSt *proximo;
    nodoSt *seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
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
        if(lista_A->dato.nota < lista_B->dato.nota)
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
    if(lista_A != NULL)
    {
        lista_C = agregarAlFinalSt(lista_A, lista_C);
    }
    else if(lista_B != NULL)
    {
        lista_C = agregarAlFinalSt(lista_B, lista_C);
    }

    return lista_C;
}

nodoSt* crearListaOrdenadaSt(nodoSt *lista)
{
    srand(time(NULL));
    char continua = 's';
    while (continua=='s')
    {
        stNotaAlumno notaAlumno;
        strcpy(notaAlumno.apeNom,"Isabel");
        notaAlumno.nota = rand()%99+1;
        nodoSt *nuevoNodo = crearNodoSt(notaAlumno);
        mostrarUnNodoSt(nuevoNodo);

        lista = agregarOrdenadoNotaSt(nuevoNodo, lista);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &continua);
        printf("\n");
    }
    return lista;
}

nodoSt* invertirListaSt(nodoSt *lista)
{

    nodoSt *listaInvertida = NULL;
    nodoSt *aux;
    while(lista != NULL)
    {
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = NULL;

        listaInvertida = agregarAlInicioSt(aux, listaInvertida);
    }
    return listaInvertida;
}

void mostrarUnNodoSt(nodoSt *aux)
{
    if (aux != NULL)
    {
        printf("Nombre: %s\n", aux->dato.apeNom);
        printf("Legajo: %d\n", aux->dato.legajo);
        printf("Nota: %d\n", aux->dato.legajo);
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


int sumarNotasListaSt(nodoSt *lista)
{
    int suma = 0;
    nodoSt * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->dato.nota;
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

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }
    stNotaAlumno personaNueva;
    char continua = 's';
    while(continua == 's')
    {
        printf("Ingrese el legajo: \n");
        scanf("%d",&personaNueva.legajo);
        printf("Ingrese el nombre: \n");
        scanf("%s",personaNueva.apeNom);
        printf("Ingrese la nota: \n");
        scanf("%d",&personaNueva.nota);

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
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodoSt *actual = lista;
    while(actual != NULL)
    {
        fwrite(&(actual->dato), sizeof(stNotaAlumno), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodoSt* archivoBin2lista_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1); // Codigo de error
    }
    stNotaAlumno personaNueva;
    rewind(archivo);
    while(fread(&personaNueva, sizeof(stNotaAlumno), 1, archivo) > 0)
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

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    stNotaAlumno *personaNueva;
    char continua = 's';

    while (continua == 's')
    {
        cargarAlumno(&personaNueva);

        // Escribir en el archivo en formato de texto
        fprintf(archivo, "%d %s %d\n", personaNueva->legajo, personaNueva->apeNom, personaNueva->nota);

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

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    nodoSt *actual = lista;
    while (actual != NULL)
    {
        fprintf(archivo, "%d %s %d\n", actual->dato.legajo, actual->dato.apeNom, actual->dato.nota);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


nodoSt* archivoTxt2lista_struct(nodoSt *lista, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return NULL;  // Devolvemos NULL en caso de error
    }

    stNotaAlumno personaNueva;

    while (fscanf(archivo, "%d %s %d", &personaNueva.legajo, personaNueva.apeNom, &personaNueva.nota) == 3) //El 3 indica la cantidad de campos que tiene la estructura
    {
        lista = agregarAlFinalSt(crearNodoSt(personaNueva), lista);
    }

    fclose(archivo);
    return lista;
}



/// Suma notas de manera recursiva
int sumarNotasListaRecursivo(nodoSt* lista)
{
    int suma = 0;
    if(lista)
    {
        suma = lista->dato.nota + sumarNotasListaRecursivo(lista->siguiente);
    }
    return suma;
}
/// Suma notas de manera recursiva con un operador ternario
int sumarNotasListaRecursivoTernario(nodoSt* lista)
{
    return (lista)?lista->dato.nota + sumarNotasListaRecursivoTernario(lista->siguiente):0;
}

void mostrarUnNodo(nodoSt* aux)
{
   mostrarUnaNota(aux->dato);
}

void recorrerYmostrar(nodoSt* lista)
{
    nodoSt* aux=lista;
    while(aux!=NULL)
    {
        mostrarUnNodo(aux);
        puts("\n");
        aux = aux->siguiente;
    }
}
/// Cuenta la cantidad de alumnos de una lisa de manera recursiva con un operador ternario
int cuentaAlumnos(nodoSt* lista)
{
    return (lista) ? 1 + cuentaAlumnos(lista->siguiente) : 0;
}
