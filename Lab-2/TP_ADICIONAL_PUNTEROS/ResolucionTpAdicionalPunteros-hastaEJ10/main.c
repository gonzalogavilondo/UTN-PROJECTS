#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

///EJ 1
void intercambiar(int *a, int *b) ;
///EJ 2
int sumaArreglo(int *arre, int dim);
///EJ 3
void convertirMayusculas(char *str);
///EJ 4
void eliminarPares(int *arre, int *dim);
///EJ 5
int contarVocales(char *str);
///EJ 6
void copiarCadena(char *dest, const char *src);
///EJ 7
void encontrarMinimoMaximo(int *arre, int dim, int *min, int *max);
///EJ 8
void concatenarCadenas(char *dest, const char *src);
///EJ 9
int buscarCaracter(const char *str, char c);



int main()
{
    ///EJ1
    printf("EJERCICIO 1\n ");
    int x = 5, y = 10;
    intercambiar (&x, &y);
    printf("x: %d, y: %d\n", x, y);

    ///EJ 2
    printf("EJERCICIO 2\n ");
    int numeros[] = {1, 2, 3, 4, 5};
    int dim = sizeof(numeros) / sizeof(numeros[0]);
    printf("Suma: %d\n", sumaArreglo(numeros, dim));

    ///EJ3
    printf("EJERCICIO 3\n ");
    char cadena[] = "hola mundo";
    convertirMayusculas(cadena);
    printf("Cadena en mayusculas: %s\n", cadena);

    ///EJ4
    printf("EJERCICIO 4\n ");
    int numeros1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dim1 = sizeof(numeros) / sizeof(numeros1[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < dim1; i++) {
        printf("%d ", numeros1[i]);
    }
    printf("\n");

    eliminarPares(numeros, &dim1);

    printf("Arreglo después de eliminar los pares:\n");
    for (int i = 0; i < dim1; i++) {
        printf("%d ", numeros1[i]);
    }
    printf("\n");

    ///EJ5
    printf("EJERCICIO 5\n ");
    int numeros2[] = {1, 2, 3, 4, 5};
    int dim2 = sizeof(numeros2) / sizeof(numeros2[0]);
    invertirArreglo(numeros2, dim2);
    for (int i = 0; i < dim2; i++) {
        printf("%d ", numeros2[i]);
    }
    printf("\n");

    ///EJ6
    printf("EJERCICIO 6\n ");
    char cadena1[] = "Hola, esto es una cadena de prueba.";
    printf("Numero de vocales: %d\n", contarVocales(cadena1));

    ///EJ7
    printf("EJERCICIO 7\n ");
    char origen[] = "Hola, esto es una cadena de prueba.";
    char destino[100];
    copiarCadena(destino, origen);
    printf("Destino: %s\n", destino);

    ///EJ8
    printf("EJERCICIO 8\n ");
    int numeros3[] = {34, 12, 56, 89, 7, 23};
    int dim3 = sizeof(numeros3) / sizeof(numeros3[0]);
    int min, max;
    encontrarMinimoMaximo(numeros3, dim3, &min, &max);
    printf("Minimo: %d, Maximo: %d\n", min, max);

    ///EJ9
    printf("EJERCICIO 9\n ");
    char cadena3[] = "Hola ";
    char cadena4[] = "esto es una cadena de prueba.";
    char resultado[100];
    concatenarCadenas(resultado, cadena3);
    concatenarCadenas(resultado, cadena4);
    printf("Resultado: %s\n", resultado);

    ///EJ10
    printf("EJERCICIO 10\n ");
    char cadena5[] = "Hola, esto es una cadena de prueba.";
    char caracter = 'e';
    if (buscarCaracter(cadena5, caracter)) {
        printf("El caracter '%c' esta presente en la cadena.\n", caracter);
    } else {
        printf("El caracter '%c' no esta presente en la cadena.\n", caracter);
    }


    return 0;
}

/// 1. Intercambiar Valores: Escribe un programa que intercambie los valores de dos variables utilizando punteros.

void intercambiar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

///2. Suma de Elementos: Calcula la suma de los elementos de un arreglo usando punteros.

int sumaArreglo(int *arre, int dim) {
    int suma = 0;
    for (int i = 0; i < dim; i++) {
        suma += *arre;
        arre++;
    }
    return suma;

/*Tener en cuenta:
Cada elemento en un arreglo de enteros tiene su propia dirección de memoria.
Cuando defines un puntero que apunta a un arreglo de enteros, el puntero apuntará al primer elemento del arreglo (índice 0). Sin embargo, a través de la aritmética de punteros, puedes acceder a los otros elementos del arreglo también.
Ejemplo:

int main() {
    int arreglo[5] = {10, 20, 30, 40, 50};
    int *puntero = arreglo;  // El puntero apunta al primer elemento del arreglo

    printf("Elemento 0: %d\n", *puntero);  // Imprime el valor del primer elemento
    printf("Elemento 1: %d\n", *(puntero + 1));  // Accede al segundo elemento a través de la aritmética de punteros

    return 0;
}
*/
}


///3. Cadena en Mayúsculas: Convierte una cadena de caracteres a mayúsculas utilizando punteros.
void convertirMayusculas(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

///4. Eliminar Números Pares: Elimina los números pares de un arreglo utilizando punteros.
void eliminarPares(int *arr, int *dim) {
    int *p = arr; /// Puntero para recorrer el arreglo
    int newSize = 0; /// Nuevo tamaño del arreglo después de eliminar los pares

    /// Recorremos el arreglo original para contar los elementos impares y ajustar el tamaño
    for (int i = 0; i < *dim; i++) {
        if (*p % 2 != 0) {
            arr[newSize] = *p; /// Sobrescribimos el arreglo original con elementos impares
            newSize++; /// Incrementamos el nuevo tamaño
        }
        p++;
    }

    *dim = newSize; /// Actualizamos el tamaño del arreglo
}

///5. Invertir Arreglo: Invierte un arreglo utilizando punteros.
void invertirArreglo(int *arr, int dim) {
    int *inicio = arr;
    int *fin = arr + dim - 1;
    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

///6. Contar Vocales: Cuenta el número de vocales en una cadena utilizando punteros.

int contarVocales(char *str) {
    int count = 0;
    while (*str) {
        char c = tolower(*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

///7. Copiar Cadena: Copia una cadena en otra utilizando punteros.
void copiarCadena(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

///8. Encontrar Mínimo y Máximo: Encuentra el valor mínimo y máximo en un arreglo utilizando punteros.
void encontrarMinimoMaximo(int *arre, int dim, int *min, int *max) {
    *min = *max = *arre;
    for (int i = 1; i < dim; i++) {
        if (*arre < *min) {
            *min = *arre;
        }
        if (*arre > *max) {
            *max = *arre;
        }
        arre++;
    }
}

///9. Concatenar Cadenas: Concatena dos cadenas utilizando punteros.
void concatenarCadenas(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

///10. Buscar Carácter: Busca un carácter en una cadena utilizando punteros.
int buscarCaracter(const char *str, char c) {
    while (*str) {
        if (*str == c) {
            return 1;
        }
        str++;
    }
    return 0;
}
