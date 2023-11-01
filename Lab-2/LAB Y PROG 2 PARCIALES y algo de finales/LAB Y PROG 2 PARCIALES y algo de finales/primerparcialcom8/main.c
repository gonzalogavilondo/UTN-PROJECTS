#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[20];
    int edad;
    char genero;
} stPersona;

typedef struct nodo
{
   stPersona datos;
   struct nodo*  siguiente;

}nodo;


///Ejercicio 1
nodo* crearNodo(stPersona datos);
nodo* agregarPpio(nodo* lista,nodo* nuevo);
nodo * agregarEnOrden (char nombreArch[]);
void muestraLista(nodo* lista);
void mostrarPersona(nodo* persona);

///Ejercicio 2
int sumaRecursiva(nodo* lista);

///Ejercicio 3
nodo* buscaMenor(nodo* lista);

///Ejercicio 4
void cargarArchivo(char nombreArch[],char inicial,nodo* lista);
void muestraArchivo(char nombreArch[]);

///Ejercicio 5
int cuentaMayoresRecursivo(int edad, nodo* lista);


int menu();

int main()
{
    int seleccion=0,sum=0,num=0,acum=0;
    nodo* lista1=NULL;
    nodo* persona;
    char letra;
    char nombreArchivo[]="personas.dat";
    do
    {
        seleccion=menu();
        switch(seleccion)
        {
        case 1:
            system("cls");
            lista1=agregarEnOrden(nombreArchivo);
            muestraLista(lista1);
            system("PAUSE");
        break;
        case 2:
            system("cls");
            sum=sumaRecursiva(lista1);
            printf("La suma de las edad de todos es : %d",sum);
            system("PAUSE");
        break;
        case 3:
            system("cls");
            persona=buscaMenor(lista1);
            mostrarPersona(persona);
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("\n Ingrese una inicial.\n");
            fflush(stdin);
            scanf("%c",&letra);
            fflush(stdin);
            cargarArchivo("NombresIgualInicial.dat",letra,lista1);
            muestraArchivo("NombresIgualInicial.dat");
            system("PAUSE");
        break;
        case 5:
            system("cls");
            printf("\n Ingrese una edad:\n");
            scanf("%d",&num);
            acum=cuentaMayoresRecursivo(num,lista1);
            printf("La cantidad de mayores a la edad indicada son: %d", acum);
            system("PAUSE");
        break;
        case 6:
            system("cls");

            system("PAUSE");
        break;
        }
    } while(seleccion!=0);
    return 0;
}




int menu()
{
    int input;

    system("cls");
    printf("\n 1-Ejercicio 1.\n");
    printf("\n 2-Ejercicio 2.\n");
    printf("\n 3-Ejercicio 3.\n");
    printf("\n 4-Ejercicio 4.\n");
    printf("\n 5-Ejercicio 5.\n");
    printf("\n 6-Ejercicio 6.\n");
    scanf("%d",&input);

    return input;
}



///Ejercicio 1

nodo* crearNodo(stPersona datos)
{
    nodo* nuevoNodo=(nodo*) malloc(sizeof(nodo));
    nuevoNodo->datos=datos;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

nodo* agregarPpio(nodo* lista,nodo* nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

nodo* agregarEnOrden (char nombreArch[])
{
    nodo* lista=NULL;
    nodo* ante;
    nodo* seguidor;
    stPersona persona;
    FILE* pArchivo=fopen(nombreArch,"rb");

    if(fread(&persona,sizeof(stPersona),1,pArchivo)>0)

        while(!feof(pArchivo))
        {
            nodo* nuevoNodo=crearNodo(persona);
            if(lista== NULL)
                lista= nuevoNodo;
            else
            {

                if(strcmp(nuevoNodo->datos.apellido,lista->datos.apellido)<0)
                    lista = agregarPpio(lista,nuevoNodo);
                else
                {
                    ante=lista;
                    seguidor=lista->siguiente;
                    while((seguidor != NULL) && (strcmp(nuevoNodo->datos.apellido,seguidor->datos.apellido) >= 0))
                    {
                        ante = seguidor;
                        seguidor = seguidor->siguiente;
                    }
                    nuevoNodo->siguiente = seguidor;
                    ante->siguiente = nuevoNodo;
                }

        }
            fread(&persona,sizeof(stPersona),1,pArchivo);
        }

    fclose(pArchivo);
    return lista;
}


void muestraLista(nodo* lista)
{
    if(lista!=NULL)
    {
      mostrarPersona(lista);
      muestraLista(lista->siguiente);
    }


}


///Ejericio 2

int sumaRecursiva(nodo* lista)
{
    int suma;
    if(lista==NULL)
        suma=0;
    else
        suma=lista->datos.edad+sumaRecursiva(lista->siguiente);
    return suma;
}

///Ejercicio 3

nodo* buscaMenor(nodo* lista)
{
    nodo* aux=lista;

    if(lista==NULL)
       aux=NULL;
    else
    {
        if(aux->siguiente!=NULL)
          aux=buscaMenor(lista->siguiente);
        else
           return lista;
        if(lista->datos.edad < aux->datos.edad)
           aux=lista;
    }
    return aux;
}

void mostrarPersona(nodo* persona)
{
    printf("\n---------------------\n");
    printf("id:       %d\n", persona->datos.id);
    printf("Nombre:   %s\n", persona->datos.nombre);
    printf("Apellido: %s\n", persona->datos.apellido);
    printf("DNI:      %s\n", persona->datos.dni);
    printf("Edad:     %d\n", persona->datos.edad);
    printf("Genero:   %c\n", persona->datos.genero);
    printf("\n---------------------\n");

}


///Ejercicio 4

void cargarArchivo(char nombreArch[],char inicial,nodo* lista)
{
    FILE* pArchivo=fopen(nombreArch,"wb+");
    nodo* aux=lista;

    while(aux!=NULL)
    {
        if(inicial==aux->datos.apellido[0])
        {
            fwrite(&aux->datos,sizeof(stPersona),1,pArchivo);
        }
        aux=aux->siguiente;
    }
    fclose(pArchivo);
}

void muestraArchivo(char nombreArch[])
{
    stPersona persona;

    FILE* pArchivo=fopen(nombreArch,"rb");
    if(fread(&persona,sizeof(stPersona),1,pArchivo))
    {
        while(!feof(pArchivo))
        {
            printf("\n---------------------\n");
            printf("id:       %d\n", persona.id);
            printf("Nombre:   %s\n", persona.nombre);
            printf("Apellido: %s\n", persona.apellido);
            printf("DNI:      %s\n", persona.dni);
            printf("Edad:     %d\n", persona.edad);
            printf("Genero:   %c\n", persona.genero);
            printf("\n---------------------\n");
            fread(&persona,sizeof(stPersona),1,pArchivo);
        }
    }
    fclose(pArchivo);
}

///Ejercicio 5

int cuentaMayoresRecursivo(int edad, nodo* lista)
{
  int contador=0;
  nodo* aux=lista;

  if(lista!=NULL)///vuelta
  {
        if(aux->siguiente!=NULL)
            contador=cuentaMayoresRecursivo(edad,lista->siguiente);
        if(lista->datos.edad > edad)
            contador=contador+1;
  }
  /*
    if(lista!=NULL)
    {
       if(lista->dato.edad > edad)
            contador=1+cuentaMayoresRecursivo(edad,lista->siguiente);
       else
        contador=cuentaMayoresRecursivo(edad,lista->siguiente);
    }





   */
  return contador;
}
