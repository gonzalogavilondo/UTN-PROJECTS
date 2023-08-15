#include "pila.h"

void inicpila(P_Pila p)
{
       int *aux;
       aux = (int *)malloc(50*sizeof(int));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

int tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

void cargarPila(P_Pila p)
{
    char control = '0';
    int num = 0;
    do
    {
        printf("Ingrese numeros a la pila o 0 para terminar: ");
        fflush(stdin);
        scanf("%d", &num);
        if(num != 0)
        {
            apilar(p, num);
        }
        else
        {
            printf("Desea agregar el '0' a la pila? <SI/NO> <S/CUALQ. OTRA LETRA> ");
            fflush(stdin);
            scanf("%c", &control);
            if(control == 'S' || control == 's')
            {
                apilar(p, num);
                num = 1; //Cambio el numero para que se siga agregando valores
            }
        }

    }while (num != 0 );
}
