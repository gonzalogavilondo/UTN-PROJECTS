#include "declaraciones.h"

/**
    ReservarMemoria
    Parametros: validos que es la cantidad de elementos que va a tener el vector
    Se reserva memoria para un vector con la cantidad de elementos igual a validos
**/
int *ReservarMemoria(int validos)
{
    int *datos = NULL;
    //Reservo memoria para la cantidad de datos.
    datos = (int *)calloc(validos, sizeof(int));

    if(datos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }
    return datos;
}

/**
    InicializarVector
    Parametros: Vector y cantidad de elementos validos
    Inicializa todos los valores del vector en "-1"
**/
void InicializarVector(int *vector, int validos)
{
    for(int i = 0; i < validos; i++)
    {
        vector[i] = -1;
    }
}


/**
    CargarVector
    Parametros: Vector
    Carga un vector de manera dinamica, mientras se va asignando los elementos, al final se realloca la memoria
    para liberar lo no utilizado y devuelve la cantidad de elementos validos.
**/
int CargarVector(int *vector)
{
    int i   = 0,
        tam = MAXDIM;
    char tecla;

    do
    {
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVector(vector, i+1);
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &vector[i]);
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVector(vector, i+1);
        i++;
        if (i == MAXDIM)
        {
            // Si se llega al final del vector, se reserva más memoria.
            tam *= 2;
            vector = (int*)realloc(vector, tam * sizeof(int));
        }

        // Preguntar al usuario si desea seguir cargando elementos.
        printf("Desea seguir cargando elementos? Presione cualquier tecla para continuar o ESC para salir.\n");
        fflush(stdin);
        tecla = getch();
    } while (tecla != 27);

    // Redimensionar el vector para liberar el exceso de memoria.
    vector = (int*)realloc(vector, i * sizeof(int));
    system("cls || clear");

    return i;
}


/**
    CompletarVector
    Parametros: Vector, cantidad de columnas (elementos validos)
    Carga un vector pero pidiendole primero al usuario y reservando memoria de acuerdo
    a los elementos validos que va a tener el vector.
**/

void CompletarVector(int *vec, int cols)
{
    for(int j = 0; j < cols; j++)
    {
        printf("VECTOR\n\n");
        MostrarVector(vec, cols);
        printf("\nAsigne un valor al elemento [%i]: ", j+1);
        scanf("%i", &vec[j]);
        system("cls || clear");
    }
}

/**
    MostrarVector
    Parametros: vector y cantidad de elementos validos
    Muestra por pantalla un vector.
**/
void MostrarVector(int *vec, int cols)
{
    printf("|  ");
    for(int j = 0; j < cols; j++)
    {
        printf("%d  ", vec[j]);
    }
    printf("|\n\n");
}

/**
    MostrarDescendente
    Parametros: vector y cantidad de elementos validos
    Muestra por pantalla un vector pero impreso de manera descendente.
**/
void MostrarDescendente(int *vec, int cols)
{
    printf("|\t");
    for(int j = cols - 1; j >= 0; j--)
    {
        printf("%i\t", vec[j]);
    }
    printf("|\n\n");
}

/// ----------------------------------------------------------------------------------

/**
    ReservarMemoriaReales
    Parametros: validos que es la cantidad de elementos que va a tener el vector
    Se reserva memoria para un vector con la cantidad de elementos igual a validos
**/
float *ReservarMemoriaReales(int validos)
{
    float *datos = NULL;
    //Reservo memoria para la cantidad de datos.
    datos = (float *)calloc(validos, sizeof(float));

    if(datos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }
    return datos;
}

/**
    CargarVectorReales
    Parametros: Vector
    Carga un vector de manera dinamica, mientras se va asignando los elementos, al final se realloca la memoria
    para liberar lo no utilizado y devuelve la cantidad de elementos validos.
**/
int CargarVectorReales(float *vector)
{
    int i   = 0,
        tam = MAXDIM;
    char tecla;

    do
    {
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVectorReales(vector, i+1);
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%f", &vector[i]);
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVectorReales(vector, i+1);
        i++;
        if (i == MAXDIM)
        {
            // Si se llega al final del vector, se reserva más memoria.
            tam *= 2;
            vector = (float *)realloc(vector, tam * sizeof(float));
        }

        // Preguntar al usuario si desea seguir cargando elementos.
        printf("Desea seguir cargando elementos? Presione cualquier tecla para continuar o ESC para salir.\n");
        fflush(stdin);
        tecla = getch();
    } while (tecla != 27);

    // Redimensionar el vector para liberar el exceso de memoria.
    vector = (float*)realloc(vector, i * sizeof(float));
    system("cls || clear");

    return i;
}


/**
    CompletarVectorReales
    Parametros: Vector, cantidad de columnas (elementos validos)
    Carga un vector pero pidiendole primero al usuario y reservando memoria de acuerdo
    a los elementos validos que va a tener el vector.
**/

void CompletarVectorReales(float *vec, int cols)
{
    for(int j = 0; j < cols; j++)
    {
        printf("VECTOR\n\n");
        MostrarVectorReales(vec, cols);
        printf("\nAsigne un valor al elemento [%d]: ", j+1);
        scanf("%f", &vec[j]);
        system("cls || clear");
    }
}

/**
    MostrarVector
    Parametros: vector y cantidad de elementos validos
    Muestra por pantalla un vector.
**/
void MostrarVectorReales(float *vec, int cols)
{
    printf("|  ");
    for(int j = 0; j < cols; j++)
    {
        printf("%.2f  ", vec[j]);
    }
    printf("|\n\n");
}

/**
    MostrarDescendente
    Parametros: vector y cantidad de elementos validos
    Muestra por pantalla un vector pero impreso de manera descendente.
**/
void MostrarDescendenteReales(float *vec, int cols)
{
    printf("|  ");
    for(int j = cols - 1; j >= 0; j--)
    {
        printf("%.2f  ", vec[j]);
    }
    printf("|\n\n");
}


/// ----------------------------------------------------------------------------------

/**
    ReservarMemoria
    Parametros: validos que es la cantidad de elementos que va a tener el vector
    Se reserva memoria para un vector con la cantidad de elementos igual a validos
**/
char *ReservarMemoriaString(int validos)
{
    char *datos = NULL;
    //Reservo memoria para la cantidad de datos.
    datos = (char *)calloc(validos, sizeof(char));

    if(datos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }
    return datos;
}

/**
    CargarVector
    Parametros: Vector
    Carga un vector de manera dinamica, mientras se va asignando los elementos, al final se realloca la memoria
    para liberar lo no utilizado y devuelve la cantidad de elementos validos.
**/
int CargarVectorString(char *vector)
{
    int i   = 0,
        tam = MAXDIM;
    char tecla;

    do
    {
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVectorString(vector, i+1);
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%c", &vector[i]);
        system("cls || clear");
        printf("VECTOR\n\n");
        MostrarVectorString(vector, i+1);
        i++;
        if (i == MAXDIM)
        {
            // Si se llega al final del vector, se reserva más memoria.
            tam *= 2;
            vector = (char*)realloc(vector, tam * sizeof(char));
        }

        // Preguntar al usuario si desea seguir cargando elementos.
        printf("Desea seguir cargando elementos? Presione cualquier tecla para continuar o ESC para salir.\n");
        fflush(stdin);
        tecla = getch();
    } while (tecla != 27);

    // Redimensionar el vector para liberar el exceso de memoria.
    vector = (char*)realloc(vector, i * sizeof(char));
    system("cls || clear");

    return i;
}


/**
    CompletarVector
    Parametros: Vector, cantidad de columnas (elementos validos)
    Carga un vector pero pidiendole primero al usuario y reservando memoria de acuerdo
    a los elementos validos que va a tener el vector.
**/

void CompletarVectorString(char *vec, int cols)
{
    for(int j = 0; j < cols; j++)
    {
        printf("VECTOR\n\n");
        MostrarVectorString(vec, cols);
        printf("\nAsigne un valor al elemento [%i]: ", j+1);
        scanf("%c", &vec[j]);
        system("cls || clear");
    }
}

/**
    MostrarVector
    Parametros: vector y cantidad de elementos validos
    Muestra por pantalla un vector.
**/
void MostrarVectorString(char *vec, int cols)
{
    printf("|  ");
    for(int j = 0; j < cols; j++)
    {
        printf("%c  ", vec[j]);
    }
    printf("|\n\n");
}


int EliminarElemento(int arreglo[], int validos, int valor)
{
    int encontrado = 0;
    int pos = -1;
    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i] == valor)
        {
            encontrado = 1;
            pos = i;
            break;
        }
    }
    if (encontrado)
    {
        for (int i = pos; i < validos - 1; i++)
        {
            arreglo[i] = arreglo[i + 1];
        }
    }
    return encontrado;
}
