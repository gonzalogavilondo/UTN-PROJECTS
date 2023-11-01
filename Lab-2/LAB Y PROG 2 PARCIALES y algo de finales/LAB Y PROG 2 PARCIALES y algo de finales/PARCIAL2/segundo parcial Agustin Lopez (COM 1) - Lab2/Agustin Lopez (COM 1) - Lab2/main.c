#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>
#define cajones "cajones.bin"

typedef struct
{
    char categoria[20];
    float peso;
} Cajon;

typedef struct
{
    float pesoIngresado;
} vagon;

typedef struct
{
    vagon v;
    struct nodo *sig;
} nodo;

typedef struct
{
    int nroTren; //id
    char categoria[20];
    nodo *listaVagones;
} tren;

void crearArchivo();
void MostrarArchivo();
nodo * crearNodo(vagon Dato);
nodo * inicLista();
tren crearTren(Cajon unCajon);
vagon crearVagon(float Peso);
void cargarArregloTren(tren unTren[]);
nodo * agregarFinal(nodo * lista,nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
void mostrarTren(tren unTren[],int dimension);
void mostrarLista(nodo * lista);

int main()
{
    tren unTren[5];
    int dimension=5;

    srand(time(NULL));

    crearArchivo();

    MostrarArchivo();

    cargarArregloTren(unTren);

    mostrarTren(unTren,dimension);

    return 0;
}

//================================================================================ CREAR ARCHIVO =================================================================================//

void crearArchivo()
{
    int num=0;
    Cajon unCajon;

    FILE * arch = fopen(cajones,"ab");

    if(arch!=NULL)
    {
        for(int i=0; i<25; i++)
        {
            num = rand()%250+1;

            unCajon.peso=(float)num;

            if(i<5)
            {
                strcpy(unCajon.categoria,"Comestible");
            }
            else
            {
                if((i>=5)&&(i<10))
                {
                    strcpy(unCajon.categoria,"Madera");
                }
                else
                {
                    if((i>=10)&&(i<15))
                    {
                        strcpy(unCajon.categoria,"Metal");
                    }
                    else
                    {
                        if((i>=15)&&(i<20))
                        {
                            strcpy(unCajon.categoria,"Plastico");
                        }
                        else
                        {
                            strcpy(unCajon.categoria,"Vidrio");
                        }
                    }
                }
            }

            fwrite(&unCajon,sizeof(Cajon),1,arch);
        }
    }
    else
    {
        printf("\n\nERROR AL ABRIR EL ARCHIVO.\n\n");
    }
    fclose(arch);
}

//================================================================================ MOSTRAR ARCHIVO ===============================================================================//

void MostrarArchivo()
{
    Cajon Aux;

    FILE * arch = fopen(cajones,"rb");

    if(arch!=NULL)
    {
        while(fread(&Aux,sizeof(Cajon),1,arch)>0)
        {
            printf("\nCategoria: ");
            puts(Aux.categoria);
            printf("\nPeso: %f",Aux.peso);
        }
    }
}

//================================================================================= CREAR NODO ===================================================================================//

nodo * crearNodo(vagon Dato)
{
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));

    nuevoNodo->v=Dato;
    nuevoNodo->sig=NULL;

    return nuevoNodo;
}

//================================================================================ INICIAR LISTA =================================================================================//

nodo * inicLista()
{
    return NULL;
}

//================================================================================= CREAR TREN ===================================================================================//

tren crearTren(Cajon unCajon)
{
    tren Aux;
    int id=0;

    printf("\nIngrese ID tren: ");
    scanf("%d",&id);

    strcpy(Aux.categoria,unCajon.categoria);
    Aux.nroTren=id;

    Aux.listaVagones = inicLista();

    return Aux;
}

//================================================================================ CREAR VAGON ===================================================================================//

vagon crearVagon(float Peso)
{
    vagon Aux;

    Aux.pesoIngresado=Peso;

    return Aux;
}

//================================================================================ CARGA ARREGLO =================================================================================//

void cargarArregloTren(tren unTren[])
{
    Cajon unCajon;
    vagon unVagon;

    int i=0,j=0,resta=0;
    nodo * nuevoNodo;

    FILE * arch = fopen(cajones,"rb");

    if(arch!=NULL)
    {
        for(i=0; i<5; i++)
        {
            while(j<5)
            {
                fread(&unCajon,sizeof(Cajon),1,arch);

                if(j==0)
                {
                    unTren[i] = crearTren(unCajon);
                }

                if(unCajon.peso>200)
                {
                    resta = 200 - unVagon.pesoIngresado;
                    unVagon.pesoIngresado=200;
                    nuevoNodo = crearNodo(unVagon);

                    unTren[i].listaVagones = agregarFinal(unTren->listaVagones,nuevoNodo);

                    unVagon.pesoIngresado=resta;
                    nuevoNodo = crearNodo(unVagon);

                    unTren[i].listaVagones = agregarFinal(unTren->listaVagones,nuevoNodo);
                }
                else
                {
                    unVagon = crearVagon(unCajon.peso);
                    nuevoNodo = crearNodo(unVagon);
                    unTren[i].listaVagones = agregarFinal(unTren->listaVagones,nuevoNodo);
                }
                j++;
            }
            j=0;
        }
    }
    else
    {
        printf("\n\nERROR AL ABRIR EL ARCHIVO.\n\n");
    }

    fclose(arch);
}

//============================================================================= AGREGAR FINAL LISTA ==============================================================================//

nodo * agregarFinal(nodo * lista,nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->sig=nuevoNodo;
    }
    return lista;
}

//============================================================================= BUSCAR ULTIMO LISTA ==============================================================================//

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg=lista;

    if(seg!=NULL)
    {
        while(seg->sig!=NULL)
        {
            seg = seg->sig;
        }
    }

    return seg;
}

//================================================================================ MOSTRAR TREN ==================================================================================//

void mostrarTren(tren unTren[],int dimension)
{
    for(int i=0; i<dimension; i++)
    {
        printf("\n\n============================\n\n");
        printf("ID Tren: %d",unTren[i].nroTren);
        printf("\nCategoria: ");
        puts(unTren[i].categoria);
        mostrarLista(unTren[i].listaVagones);
        printf("\n\n============================\n\n");
    }
}

//================================================================================ MOSTRAR LISTA =================================================================================//

void mostrarLista(nodo * lista)
{
    nodo * seg = lista;

    while(seg!=NULL)
    {
        printf("\nPeso: %.2f\n",seg->v.pesoIngresado);

        seg = seg->sig;
    }
}
