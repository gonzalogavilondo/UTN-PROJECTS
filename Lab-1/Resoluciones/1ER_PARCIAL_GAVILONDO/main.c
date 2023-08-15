#include "pila.h"
#define MAXDIM 30

///DECLARACIONES DE FUNCIONES
int ejercicio1(int *, Pila *);
void ejercicio2(int *, int);
void ejercicio3(Pila *);
void ejercicio4(Pila *);

///Funciones ej1
int IngresarVectorPila(int *, Pila *);
void MostrarVector(int *, int );

///Funcion copiar pila
void copiarPila(Pila *, Pila *);

///Funciones ej2
int buscarElementoEnVector(int *, int, int);

///Funciones ej3
int buscarMenorPilaYeliminar(Pila *);
void menoresPilaToArray(int *, Pila *);

///Funciones ej4
int pilaToArrayIntercalado(int *, Pila *);

int main()
{
    int vec [MAXDIM];
    int cntElementos = 0;

    Pila pila, copia;

    /// Inicializamos las pilas.
    inicpila(&pila);
    inicpila(&copia);

    ///EJ1
    cntElementos = ejercicio1(vec, &pila);

    ///Hacemos la copia de la pila del ej1 para usarla en ej4
    copiarPila(&copia, &pila);

    ///EJ2
    ejercicio2(vec, cntElementos);

    ///EJ3
    ejercicio3(&pila);

    ///EJ4
    ejercicio4(&copia);

    return 0;
}

/**
    Realizar una funcion en C que reciba un Arreglo y una Pila. La funcion debe permitir que el usuario del sistema ingrese tantos datos como desee y los almacenara de acuerdo al siguiente criterio:
    Si el dato es impar, lo cargara en el arreglo
    Si el dato es impar, y ademas multiplo de 3, lo cargara en la pila
    Si el dato es par, se le informara por pantalla al usuario que solo puede ingresar numeros impares.
    Tener en cuenta que los datos van al arreglo o a la pila no se guardan en los dos al mismo tiempo
**/

int ejercicio1(int *vec, Pila *pila)
{
    int cntElementos = 0;

    printf("\t--EJERCICIO 1--\n\n");

    ///Llamo a la funcion principal
    cntElementos = IngresarVectorPila(vec, pila);

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos la pila y el vector final
    printf("--VECTOR--\n\n");
    MostrarVector(vec, cntElementos);

    printf("--PILA--\n");
    mostrar(pila);

    return cntElementos;

}
int IngresarVectorPila(int *vec, Pila *pila)
{
    int valor = 0;
    int cntVector = 0;

    do
    {
        printf("Ingrese un valor (o presione '0' para salir): ");
        scanf("%d", &valor);
        if(valor % 2 != 0 && valor % 3 != 0)
        {
            vec[cntVector] = valor;
            cntVector++;
        }
        else if(valor % 2 != 0 && valor % 3 == 0)
        {
            apilar(pila, valor);
        }
        else
        {
            printf("El numero es par, solo se pueden ingresar numeros impares.\n");
        }

    } while (valor != 0);

    return cntVector;
}

void MostrarVector(int *vec, int cols)
{
    printf("|  ");
    for(int j = 0; j < cols; j++)
    {
        printf("%d  ", vec[j]);
    }
    printf("|\n\n");
}

void copiarPila(Pila *copia, Pila *pila)
{
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
    }

    ///Hago la copia en la pila final y dejo la pila como estaba antes
    while(!pilavacia(&aux))
    {
        apilar(copia, tope(&aux));
        apilar(pila, desapilar(&aux));
    }
}

/**
    Realizar una funcion que busque en el arreglo obtenido en el
    ejercicio 1 y devuelva si encuentra o no un numero a eleccion del usuario
    del sistema.
    El arreglo debera ser recorrido de atras hacia adelante.
**/
void ejercicio2(int *vec, int validos)
{
    int flag    = 0,
        dato    = 0;

    printf("\t--EJERCICIO 2--\n\n");

    printf("\nIngrese el dato a buscar: ");
    scanf("%d", &dato);

    flag = buscarElementoEnVector(vec, validos, dato);

    if(flag == 0)
    {
        printf("\nNo se encontro el elemento %d en el arreglo.\n", dato);
    }
    else
    {
        printf("\nEl elemento %d se encuentra en el arreglo.\n", dato);
    }

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");
}

int buscarElementoEnVector(int *vec, int validos, int dato)
{
    int flag = 0;
    for(int i = validos; i > 0 && flag != 1; i--)
    {
        if(vec[i] == dato)
        {
            flag = 1; //Si el flag es = 1, entonces se encontro el dato
        }
    }
    return flag;
}

/**
    A) Realizar una funcion auxiliar que busque el menor en la pila obtenida
    en el ejercicio 1 y lo elimine de la misma.

    B) Realizar una funcion principal que, utilizando la funcion auxiliar
    de buscar el menor, encuentre los CINCO elementos menores de la pila  y los
    pase de a uno a un nuevo arreglo, el cual debera quedar ordenado de menor
    a mayor.

**/
void ejercicio3(Pila *pila)
{
    int vec [MAXDIM];

    printf("\t--EJERCICIO 3--\n\n");

    ///Mostramos la pila y el vector final
    printf("--PILA--\n");
    mostrar(pila);

    ///Llamamos al a funcion de eliminar los 5 menores de la pila
    menoresPilaToArray(vec, pila);

    ///Mostramos el vector final y la pila despues de eliminar los 5 menores
    printf("--PILA DESPUES DE ELIMINAR LOS 5 MENORES--\n");
    mostrar(pila);
    printf("--VECTOR CON LOS 5 MENORES ORDENADOS--\n\n");
    MostrarVector(vec, 5); //Es 5 la cantidad de elementos porque son los primeros 5 elementos de la pila, esta en el enunciado

    ///Pausa y limpiado de pantalla
    system("pause");
    system("cls || clear");

}

int buscarMenorPilaYeliminar(Pila *pila)
{
    Pila pilaMenor, aux;

    int flagEncontrado = 0,
        valor          = 0,
        menorValor     = 0;

    ///Inicializamos todas las pilas
    inicpila(&pilaMenor);
    inicpila(&aux);

    while (!pilavacia(pila))
    {
        valor = desapilar(pila);
        if (!flagEncontrado || valor < tope(&pilaMenor))
        {
            if (flagEncontrado)
            {
                apilar(&aux, desapilar(&pilaMenor)); ///SIEMPRE ME VA A QUEDAR EL ULTIMO MENOR NADA MAS.
            }
            apilar(&pilaMenor, valor);
            menorValor = valor; //Es el valor que voy a retornar que va a ser el eliminado
            flagEncontrado = 1; //Flag que se encontro un nuevo valor menor.
        }
        else
        {
            apilar(&aux, valor);
        }
    }

    ///Volvemos a dejar la pila con todos sus valores menos el menor encontrado
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return menorValor;
}

void menoresPilaToArray(int *vec, Pila *pila)
{
    int valorEliminado = 0;

    for(int i = 0; i < 5; i++) //Buscar los primeros 5 elementos
    {
       valorEliminado = buscarMenorPilaYeliminar(pila);
       vec[i] = valorEliminado;
    }
}

/**
    Realizar una funcion que recorra la Pila obtenida en el ejercicio 1
    y pase a un nuevo arreglo todos los datos de acuerdo al siguiente criterio:
        -Solo deberan tenerse en cuenta dato de por medio (es decir: el 1º elemento de la
         Pila si, el 2º no, el 3º si, el 4º no y asi siguiendo hasta el final de la Pila)
        -Los datos no deben quedar eliminados de la Pila original.
**/
void ejercicio4(Pila *pila)
{
    int vec [MAXDIM];
    int cntElementos = 0;

    printf("\t--EJERCICIO 4--\n\n");

    printf("--PILA ORIGINAL--\n");
    mostrar(pila);

    ///Llamamos a la funcion principal que hace lo que pide el enunciado.
    cntElementos = pilaToArrayIntercalado(vec, pila);

    printf("--PILA DESPUES DE PASAR AL VECTOR--\n"); //DEBE QUEDAR IGUAL
    mostrar(pila);
    printf("--VECTOR RESULTANTE--\n");
    MostrarVector(vec, cntElementos);

}

int pilaToArrayIntercalado(int *vec, Pila *pila)
{
    int cntElementos = 0,
        contador     = 0;
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(pila))
    {
        if(contador % 2 == 0)
        {
            vec[cntElementos] = tope(pila);
            cntElementos++;
        }
        apilar(&aux, desapilar(pila));
        contador++;
    }

    ///Vuelvo a dejar la pila como antes
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cntElementos;
}
