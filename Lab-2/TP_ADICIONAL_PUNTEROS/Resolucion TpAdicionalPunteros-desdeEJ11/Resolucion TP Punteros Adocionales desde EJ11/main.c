#include <stdio.h>
#include <stdlib.h>

int *crearArregloDinamico(int dim);
char *duplicarCadena(const char *str) ;
int *clonarArregloDinamico(int *arre, int dim) ;
char *crearCadenaDinamica(const char *str) ;

void swap(int **a, int **b) ;
void printArray(int **arrPtr, int size);

int main()
{
///1.	Crear Arreglo Dinámico: Crea un arreglo dinámico de enteros y devuelve un puntero a él.
    /*    int n = 5;
        int *ptr = crearArregloDinamico(n);
        for (int i = 0; i < n; i++) {
            ptr[i] = i * 2;
            printf("%d ", ptr[i]);
        }
        free(ptr);
        printf("\n");
    */

///2.	Duplicar Cadena: Duplica una cadena y devuelve un puntero a la nueva cadena.
    /*    char original[] = "Hola, esto es una cadena de prueba.";
        printf("Original: %s\n",original);
        char *copia = duplicarCadena(original);
        printf("Copia: %s\n", copia);
        free(copia);
    */

///3.Clonar Arreglo Dinámico: Clona un arreglo dinámico de enteros y devuelve un puntero al nuevo arreglo.
    /*    int numeros[] = {2, 4, 6, 8, 10};
        int dim = sizeof(numeros) / sizeof(numeros[0]);
        int *copia = clonarArregloDinamico(numeros, dim);
        printf("Arreglo Clonado: \n");
        for (int i = 0; i < dim; i++) {
            printf("%d ", copia[i]);
        }
        printf("\n");
        free(copia);
    */

///4. Crear Cadena Dinámica: Crea una cadena dinámica y devuelve un puntero a ella.
    /*    char texto[] = "Esta es una cadena dinamica.";
        char *cadena = crearCadenaDinamica(texto);
        printf("Cadena: %s\n", cadena);
        free(cadena);
    */

///===================================== PUNTEROS DOBLES ======================================

///1.	// Ejercicio 1: Función para intercambiar dos valores usando punteros dobles
    /*    int num1 = 5, num2 = 10;
        int *ptr1 = &num1, *ptr2 = &num2;
        printf("Ejercicio 1: Intercambio de valores usando punteros dobles\n");
        printf("Antes del intercambio: num1 = %d, num2 = %d\n", *ptr1, *ptr2);
        swap(&ptr1, &ptr2);
        printf("Después del intercambio: num1 = %d, num2 = %d\n", *ptr1, *ptr2);
    */

///2.	// Ejercicio 2: Uso de punteros dobles para acceder a un arreglo
/*    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr;
    int i;
    printf("\nEjercicio 2: Acceso a un arreglo usando punteros dobles\n");
    for (i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("Elemento %d: %d\n", i, *(*(&arrPtr) + i));
/// &arrPtr: obtenemos la dirección de memoria del puntero arrPtr. Esto es un puntero a un puntero a un entero (int **)
/// *(&arrPtr): al usar * (referencia, nos da el puntero original arrPtr (un puntero a un entero int *))
/// *(*(&arrPtr) + i): accedo a los elementos del arreglo a traves de i (iniciada en 0)
    }
*/

///3.	// Ejercicio 3: Pasar un arreglo a una función y mostrarlo, usando punteros dobles
/*    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr;
    printf("\nEjercicio 3: Pasar un arreglo a una función y mostrarlo usando punteros dobles\n");
    printArray(&arrPtr, sizeof(arr) / sizeof(int));
*/

    return 0;
}

///1.	Crear Arreglo Dinámico: Crea un arreglo dinámico de enteros y devuelve un puntero a él.
int *crearArregloDinamico(int dim)
{
    int *arre = (int *)malloc(dim * sizeof(int));
    return arre;
}

///2.	Duplicar Cadena: Duplica una cadena y devuelve un puntero a la nueva cadena.
char *duplicarCadena(const char *str)
{
    char *duplicado = (char *)malloc((strlen(str) + 1) * sizeof(char)); ///el "+1" esta p/q/se incluya el "\0" tambien
    strcpy(duplicado, str);
    return duplicado;
}

///3.Clonar Arreglo Dinámico: Clona un arreglo dinámico de enteros y devuelve un puntero al nuevo arreglo.
int *clonarArregloDinamico(int *arre, int dim)
{
    int *clon = (int *)malloc(dim * sizeof(int));
    for (int i = 0; i < dim; i++)
    {
        clon[i] = arre[i];
    }
    return clon;
}

///4. Crear Cadena Dinámica: Crea una cadena dinámica y devuelve un puntero a ella.
char *crearCadenaDinamica(const char *str)
{
    char *cadena = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(cadena, str);
    return cadena;
}


///===================================== PUNTEROS DOBLES ======================================

///1.	// Ejercicio 1: Función para intercambiar dos valores usando punteros dobles
void swap(int **a, int **b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

///3.	// Ejercicio 3: Pasar un arreglo a una función e imprimir usando punteros dobles
void printArray(int **arrPtr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Elemento %d: %d\n", i, *(*arrPtr + i));
    }
}



///==========================================================================================================================
///ejercicio de practica: cargamos un arreglo y cuando se llene, se redimensiona
/*
/// VERSION 1 (interviene el usuario)
int main()
{
    int initialSize = 3;
    int *array = (int *)malloc(initialSize * sizeof(int));
    int cant_nros = 0;
    int numero;
    char opcion;

    do
    {
        if (cant_nros == initialSize)
        {
            initialSize *= 2;
            array = (int *)realloc(array, initialSize * sizeof(int));
            printf("Arreglo redimensionado a tamaño %d.\n", initialSize);
        }

        printf("Ingrese un número: ");
        scanf("%d", &numero);

        array[cant_nros++] = numero;

        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &opcion);

    }while (opcion == 's' || opcion == 'S');

    printf("Elementos ingresados:\n");
    for (int i = 0; i < cant_nros; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}

/// VERSION 2: NO INTERVIENE EL USUARIO (no corta tampoco, solo para ver que funciona el redimensionado)
int main() {
    int size = 5;
    int *array = (int *)malloc(size * sizeof(int));
    int cant_nros = 0;

    printf("Ingrese %d elementos:\n", size);

    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
        cant_nros++;

        if (cant_nros == size) {
            size *= 2;
            array = (int *)realloc(array, size * sizeof(int));
            printf("Arreglo redimensionado a tamaño %d.\n", size);
        }
    }
    printf("Elementos ingresados:\n");
    for (int i = 0; i < cant_nros; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
*/
