#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idSocio;
    char nya[50];
    int ultimaCuotaPaga; //1 a 12
    float valorCuota;
    int edad;
    int idDeporte;
    char nombreDeporte[50];
}stClub;

typedef struct{
    int idSocio;
    char nya[50];
    int ultimaCuotaPaga; //1 a 12
    float valorCuota;
    int edad;
}stSocio;

typedef struct{
    int idDeporte;
    char nombreDeporte[50];
}stDeporte;


typedef struct nodo{
    stSocio  socio;
    struct nodo * sig;                  //lista secundaria
}nodo;

typedef struct nodo2{
    stDeporte deporte;      ///lista principal
    struct nodo *socios;
    struct nodo2* sig;
    struct nodo2* ante;
}nodo2;
///////////////////1////////
nodo  *inicLista();
nodo2 *inicLista2();

nodo *crearNodo(stClub datos);
nodo2 *crearNodo2(stClub datos);




nodo2 * buscarUltimoDobleRecursivo (nodo2 * lista) ;
nodo2 *agregarNodo2(nodo2 *lista,nodo2 *nuevo);
nodo *agregarNodo(nodo *lista,nodo *nuevo);


nodo2 *cargaNodos(nodo2 *lista,stClub aux);

nodo2 *alta(nodo2 *lista);

nodo2 *buscaNodo2(nodo2 *lista,nodo2 *nodoDoble);
void mostrarLista(nodo2 *lista);
void mostrarListita(nodo *lista);
nodo2 *creaUsuario(nodo2 *lista);

void masSocios(nodo2 *lista);
int cuentaSocios(nodo *lista);

void crearArchivos(nodo2 *lista);

int cargaArreglo(nodo2  *lista,int dimension, int validos,stClub arreglo[] );

void muestraArreglo(stClub arreglo[],int  validos);
int listitaArreglo(nodo *lista,stClub arreglo[],int validos,int dimension,int mes, stClub aux);
int main()
{
    nodo2  *lista=inicLista2();
    lista=alta(lista);
    mostrarLista(lista);
    int dimension=50;
    stClub arreglo[dimension];
    int validos=0;
   // lista=creaUsuario(lista);
    //mostrarLista(lista);
   // masSocios(lista);
   //crearArchivos(lista);
   validos=cargaArreglo(lista,dimension,validos,arreglo);
    muestraArreglo(arreglo,validos);
    return 0;
}



/////////
nodo  *inicLista(){
    return NULL;
}
nodo2 *inicLista2(){
    return NULL;
}

nodo *crearNodo(stClub datos){

    nodo *aux=(nodo*)malloc(sizeof(nodo));
    aux->sig=NULL;
    aux->socio.edad=datos.edad;
    aux->socio.idSocio=datos.idSocio;
    strcpy(aux->socio.nya,datos.nya);
    aux->socio.ultimaCuotaPaga=datos.ultimaCuotaPaga;
    aux->socio.valorCuota=datos.valorCuota;
return aux;
}

nodo2 *crearNodo2(stClub datos){

    nodo2 *aux=(nodo2*)malloc(sizeof(nodo2));
    aux->ante=inicLista2();
    aux->sig=NULL;
    aux->socios=inicLista();
    aux->deporte.idDeporte=datos.idDeporte;
    strcpy(aux->deporte.nombreDeporte,datos.nombreDeporte);
return aux;
}

/////////////
nodo2 * buscarUltimoDobleRecursivo (nodo2 * lista) {
    nodo2 * rta;
    if (lista==NULL)
        rta=NULL;
    else
        if(lista->sig==NULL)
            rta=lista;
        else
            rta=buscarUltimoDobleRecursivo(lista->sig);
return rta;
}

/////////////
nodo2 *agregarNodo2(nodo2 *lista,nodo2 *nuevo){

    if(lista == NULL) {
        lista = nuevo;
    } else {
        nodo2 * ultimo = buscarUltimoDobleRecursivo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }
return lista;
}



nodo *agregarNodo(nodo *lista,nodo *nuevo){

    if(lista==NULL){
        lista=nuevo;
    }
     else{
        if ( strcmp(lista->socio.nya,nuevo->socio.nya)>0 ){
            nuevo->sig=lista;
            lista=nuevo;
        }
        else{
            lista->sig=agregarNodo(lista->sig,nuevo);
        }
    }
return lista;
}



nodo2 *alta(nodo2 *lista){

    FILE *arch=fopen("registroClub.dat","rb");
    stClub aux;
    if(arch!=NULL){
        while( (fread(&aux,sizeof(stClub),1,arch)>0 )){

                printf("\nNombre deporte :%s  , Nombre  :%s               idSOCIO:%i",aux.nombreDeporte,aux.nya,aux.idSocio);

           lista=cargaNodos(lista,aux);


        }
    }
    else
        printf("\n Error al abrir el archivo\n");

return lista;
}


nodo2 *cargaNodos(nodo2 *lista,stClub aux){

    nodo2* nodoDoble=crearNodo2(aux);
    nodo *nodito=crearNodo(aux);

    nodo2 *pos=buscaNodo2(lista,nodoDoble);


    if(pos==NULL){

        nodoDoble->socios=agregarNodo(nodoDoble->socios,nodito);
        lista=agregarNodo2(lista,nodoDoble);
    }
    else{
         pos->socios=agregarNodo(pos->socios,nodito);
    }
return lista;
}




nodo2 *buscaNodo2(nodo2 *lista,nodo2 *nodoDoble){

    nodo2 *rta;
    if(lista==NULL)
        rta=NULL;
    else{
            if(  strcmp(lista->deporte.nombreDeporte,nodoDoble->deporte.nombreDeporte)==0)
                rta=lista;
            else{
                rta=buscaNodo2(lista->sig,nodoDoble);
            }
    }
return rta;
}



///////////mostrar///
void mostrarLista(nodo2 *lista){

        nodo2 *seg=lista;

        if(seg!=NULL){
                while(seg!=NULL){
                    printf("\n\n----Deporte :%s  ---\n\n",seg->deporte.nombreDeporte);
                     mostrarListita(seg->socios);
                    seg=seg->sig;
                }

        }
        else{
            printf("\n No se cargo la lista \n");
        }
}
void mostrarListita(nodo *lista){

    if(lista!=NULL){
       printf("\n Nombre:%s   Edad:%i Ultima cuota  :%i          IDSOCIO :%i",lista->socio.nya,lista->socio.edad,lista->socio.ultimaCuotaPaga,lista->socio.idSocio);
       mostrarListita(lista->sig);
    }
}



nodo2 *creaUsuario(nodo2 *lista){

    stClub  persona;

    char seguir='s';

    printf("\n desea agregar una persona al club ? s-si   otra cosa no\n");
    fflush(stdin);
    scanf("%c",&seguir);
   while(seguir=='s'){
     printf("\n Ingrese nombre y apellido \n");
     fflush(stdin);
     gets(persona.nya);
     printf("\n Ingrese edad \n");
     fflush(stdin);
     scanf("%i",&persona.edad);
     printf("\n Ingrese la ultima cuota 1---12\n");
     scanf("%i",&persona.ultimaCuotaPaga);
     while( seguir=='s'){
         printf("\n ingrese nombre del deporte\n");
         fflush(stdin);
         gets(persona.nombreDeporte);
         lista=cargaNodos(lista,persona);
         printf(" \n desea seguir  agregando deportes  s  --- n \n");
         fflush(stdin);
         scanf("%c",&seguir);
    }
   }
return lista;
}



void masSocios(nodo2 *lista){

    int mayor=0,total=0;
    nodo2 *pos;
    nodo2 *seg=lista;

    while( seg!=NULL){

        total=cuentaSocios(seg->socios);
        printf("\n\n\n DEPORTE :%s Cantidad Socios :%i",seg->deporte.nombreDeporte,total);
        if(total>mayor){
            pos=seg;
            mayor=total;
        }
    seg=seg->sig;
    }
    printf("\n \n -----El deporte que tiene mas socios es %s --------\n",pos->deporte.nombreDeporte);
    printf("\n con un total de %i socios \n",mayor);
    mostrarListita(pos->socios);


}

int cuentaSocios(nodo *lista){
    int rta=0;

    if(lista!=NULL){
        rta=1+cuentaSocios(lista->sig);

    }

return rta;

}


void crearArchivos(nodo2 *lista){

    FILE  *archDeporte=fopen("deportes.bin","ab");
    FILE  *archSocio=fopen("Socios.bin","ab");
    stDeporte auxD;
    stSocio auxS;
    nodo2 *seg=lista;
    if(seg!=NULL){
        while(seg!=NULL){
            auxD=seg->deporte;
            fwrite(&auxD,sizeof(stDeporte),1,archDeporte);
            while(seg->socios!=NULL){
                auxS=seg->socios->socio;
                fwrite(&auxS,sizeof(stSocio),1,archSocio);
                seg->socios=seg->socios->sig;

               }
            seg=seg->sig;
        }
    }
    else{
        printf("\n error al abrir el archivo\n");
    }
    fclose(archDeporte);
    fclose(archSocio);
}


int cargaArreglo(nodo2  *lista,int dimension,int validos,stClub arreglo[]){

    nodo2 *seg=lista;
    stClub  aux;
    int mes;
    printf("\n Ingrese el nombre del deporte  \n");
    fflush(stdin);
    gets(aux.nombreDeporte);




    printf("\n Ingrese el mes  1....12\n");
    scanf("%i",&mes);
    nodo2 * nodoDoble=crearNodo2(aux);
    if(seg!=NULL){
        nodo2 *pos=buscaNodo2(seg,nodoDoble);
       /* while(pos->socios!=NULL && validos<dimension){

               if(pos->socios->socio.ultimaCuotaPaga<aux.ultimaCuotaPaga){
                aux.edad=pos->socios->socio.edad;
                strcpy(aux.nya,pos->socios->socio.nya);
                aux.ultimaCuotaPaga=pos->socios->socio.ultimaCuotaPaga;

                arreglo[validos]=aux;
                validos++;
               }

            pos->socios=pos->socios->sig;
        }*/
        validos=listitaArreglo(pos->socios,arreglo,validos,dimension,mes, aux);
    }
    else{
        printf("\n Errorrrrrrrrrrrrrrrr");
    }
    printf("\n Los validos son %i \n ",validos);

return validos;
}




void muestraArreglo(stClub arreglo[],int  validos){


    printf("\n Nombre del deporte  %s\n",arreglo[0].nombreDeporte);
    for(int i=0;i<validos;i++){
        printf("\n Nombre y apellido %s       ultima cuota %i",arreglo[i].nya,arreglo[i].ultimaCuotaPaga);
    }


}







int listitaArreglo(nodo *lista,stClub arreglo[],int validos,int dimension,int mes,stClub aux){

    nodo* seg=lista;

    while(seg!=NULL){
            if(seg->socio.ultimaCuotaPaga>mes){
               strcpy(aux.nya,seg->socio.nya);
               aux.edad=seg->socio.edad;
               aux.idSocio=seg->socio.idSocio;
               aux.ultimaCuotaPaga=seg->socio.ultimaCuotaPaga;
               aux.valorCuota=seg->socio.valorCuota;
               arreglo[validos]=aux;
               validos++;
            }

        seg=seg->sig;
    }




return validos;

}


















































































