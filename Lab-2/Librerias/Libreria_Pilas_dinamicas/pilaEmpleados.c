#include "pilaEmpleados.h"


/**
    iniciaPilaEmpleados
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Inicializa el arreglo de empleados con una dimension de 10 y elementos validos en 0 ademas
    de reservar espacio en memoria
**/
void iniciaPilaEmpleados(pilaEmpleados *pE)
{
    ///inicializo la pila, es decir, la estoy creando!!!

    ///cuando se tiene un punt (*pe) a una struct, nos referimos a los campos de esa struct, usando "->"
    pE->dim = 10; /// ej: a lo que apunta pe, en su dato dim, le cargo 10

    ///Inicializamos el arreglo en 0
    pE->v = 0;

    ///La propiedad e de la pila apuntara
    ///a un espacio de memoria RESERVADO
    pE->e = (stEmpleado *) malloc (sizeof (stEmpleado) * pE->dim);///creo arreglo de empleados de forma dinamica (nunca use [])
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    apilarEmpleado
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados) y un empleado
    Apila un empleado en la "pila" que en realidad es un arreglo de empleados.
**/
void apilarEmpleado(pilaEmpleados *pE, stEmpleado e)
{
    if (pE->v == pE->dim)///si la pila esta llena
    {
        pE->dim = pE->dim * 2 ;///duplico (por ejemplo) la dimension de la pila
        pE->e = (stEmpleado *)realloc(pE->e, sizeof (stEmpleado) * pE->dim); ///y ahora si, duplico el arreglo de empleados
        ///acabo de REDIMENSIONAR el arreglo, usando REALLOC:(que quiero redimensionar, tamaño nuevo)
    }
    pE->e [pE->v] = e; ///recordar que "e" es un arreglo: asigno a la pos validos,
                    ///el empleado recibido por parametro
    pE->v++;///incremento los validos
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    desapilarEmpleado
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Desapila un empleado en la "pila" que en realidad es un arreglo de empleados.
    Lo que hace es quitar la referencia al ultimo valor que se encuentra en el arreglo, fijarse
    que corre la referencia un lugar atras de los validos, asi se pierde la referencia al ultimo lugar,
    y eso el sistema lo interpreta automaticamente como basura.
**/
stEmpleado desapilarEmpleado(pilaEmpleados * pE)
{
    stEmpleado e; ///empleado a "devolver"

    e = pE->e [pE->v - 1];///al empleado que voy a devolver, le asigo el ultimo cargado en el arreglo (v-1)
    pE->v --;///decremento los validos, debido a que acabo de quitar un empleado

    return e;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    topeEmpleado
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Devuelve el ultimo valor ingresado (en este caso una estructura, que es el empleado)
**/
stEmpleado topeEmpleado(pilaEmpleados *pE)
{
    stEmpleado e;

    e = pE->e [pE->v - 1];///al empleado que voy a devolver, le asigo el ultimo cargado (v-1)

    return e;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    pilaVaciaEmpleados
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Devuelve el ultimo valor ingresado (en este caso una estructura, que es el empleado)
**/
int pilaVaciaEmpleados(pilaEmpleados * pE)
{
    return (pE->v == 0) ? 1 : 0; ///use operador ternario (condicion, accion verdadera, accion falsa)
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    mostrarPilaEmpleados
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Muestra la pila sin perder datos.
**/
void mostrarPilaEmpleados(pilaEmpleados *pE)
{
    ///Es una estructura creada por el programador
    pilaEmpleados pEaux;

    ///Inicializamos la pila para cargarle datos
    iniciaPilaEmpleados(&pEaux);

    while(!pilaVaciaEmpleados(pE))
    {
        muestraUnEmpleado(topeEmpleado(pE));
        apilarEmpleado(&pEaux, desapilarEmpleado(pE));
    }

    ///Vuelvo a recuperar los datos de la pila original
    while(!pilaVaciaEmpleados(&pEaux))
    {
        apilarEmpleado(pE, desapilarEmpleado(&pEaux));
    }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    cargarPilaEmpleados
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Carga una cantidad de empleados en una pila.
**/
void cargarPilaEmpleados(pilaEmpleados *pE)
{
    int cntEmpleados = 0;

    printf("Ingrese la cantidad de empleados a cargar: ");
    scanf("%d", &cntEmpleados);
    fflush(stdin);

    for(int i = 0; i < cntEmpleados; i++)
    {
        apilarEmpleado(pE, cargarUnEmpleado());
    }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

/**
    guardarPilaEnArchivo
    Parametros: Tipo de datos pilaEmpleados que es una estructura, que contiene
    un puntero a la estructura de empleados (es decir, simula un arreglo de empleados)
    Guardar en un archivo de texto la pila cargada.
**/

void guardarPilaEnArchivo(pilaEmpleados *pE)
{
    char *empleadoStr = NULL;
    empleadoStr = (char*)malloc(sizeof(char) * 200);

    ///Es una estructura creada por el programador
    pilaEmpleados pEaux;

    ///Inicializamos la pila para cargarle datos
    iniciaPilaEmpleados(&pEaux);

    ///Creo y abro el archivo en modo escritura
    FILE* archivo = fopen("archivo.txt", "w");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    while(!pilaVaciaEmpleados(pE))
    {
        empleadoStr = empleadoToStr(topeEmpleado(pE));
        fprintf(archivo, "%s\n", empleadoStr);
        apilarEmpleado(&pEaux, desapilarEmpleado(pE));
    }

    ///Vuelvo a recuperar los datos de la pila original
    while(!pilaVaciaEmpleados(&pEaux))
    {
        apilarEmpleado(pE, desapilarEmpleado(&pEaux));
    }

    fclose(archivo);
    free(empleadoStr);

}
