#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
int cantDestinosAereos;
char ciudadOrigen[30];
float costoPromedioAereo;
float tiempoPromedioAereo;
}destinosAereos;
typedef struct {
int cantDestinosFerro;;
char ciudadOrigen[30];
float costoPromedioFerro;
float tiempoPromedioFerro;
}destinosFerro;


typedef struct
{
char origen[30];
char destino[30];
char tipo[30];//”aereo”,“ferrocarril”
float costo;
int tiempoViaje;
}registroEnvios;

typedef struct nodoDestino
{
    char nombre[30];
    float costo;
    int tiempoViaje;
    struct nodoDestino* sig;
}nodoDestino;

typedef struct nodoOrigen
{
    char nombre[30];
    nodoDestino* destinosAereos;
    nodoDestino* destinosFerro;
    struct nodoOrigen* sig;
}nodoOrigen;
///////////1//////////
nodoOrigen *inicLista();
nodoOrigen *cargaLista(nodoOrigen *lista);
nodoOrigen *alta(nodoOrigen *lista,registroEnvios aux);
nodoOrigen *agregarNodoOrigen(nodoOrigen *lista,nodoOrigen *nuevo);
nodoOrigen *creaNodoOrigen(registroEnvios aux);
nodoDestino *creaNodoDestino(registroEnvios axu);
nodoOrigen *buscaNodoOrigen(nodoOrigen *lista,char nombre[]);
nodoOrigen *insertarRecursivo(nodoOrigen *lista, nodoOrigen *nuevo);
nodoDestino *agregarFinal(nodoDestino *lista,nodoDestino *nuevo);
/////////mostrar////
void mostrarLista(nodoOrigen *lista);

void mostrarListaDestino(nodoDestino *lista);
/////////////////2
void muestraPromedioVuelos(nodoOrigen *lista,char origen[]);
float promedioVuelos(nodoDestino *lista);
int sumaRecursivo(nodoDestino *lista);
int totalRecursivo(nodoDestino *lista);
void escribeArchivo(nodoOrigen *lista);
//////////////////3
destinosAereos cargadestinosAereos(nodoDestino *lista);
void escribeArchivo(nodoOrigen *lista);
destinosFerro cargadestinosFerro(nodoDestino *lista);
destinosAereos cargadestinosAereos(nodoDestino *lista);
float totalCosto(nodoDestino *lista);
/////////muestro los archivos chiquitos
void  archivitos();

int main()
{
     char origen[50];
     nodoOrigen *lista=inicLista();
     lista=cargaLista(lista);
     mostrarLista(lista);
     printf("\n\n\n");
     printf("Ingrese un nombre de origen para mostrar el promedio de los tiempos de viajes aereos\n");
     fflush(stdin);

     gets(origen);
     muestraPromedioVuelos(lista,origen);
     escribeArchivo(lista);
     archivitos();

    return 0;
}
//////////////1///////////
nodoOrigen *inicLista(){
    return NULL;
}
////
nodoOrigen *cargaLista(nodoOrigen *lista){

    FILE *arch=fopen("registroEnvios.bin","rb");
    registroEnvios aux;
    int i=0;
    if(fread(&aux,sizeof(registroEnvios),1,arch)>0)
    {
       while(!feof(arch))
        {
          i++;
          printf("Origen:%s ,Destino: %s ,Tipo:%s ,Costo :%2.2f, TiempoViaje:%i\n",aux.origen,aux.destino,aux.tipo,aux.costo,aux.tiempoViaje);
          lista=alta(lista,aux);
          fread(&aux,sizeof(registroEnvios),1,arch);
        }
    }
    fclose(arch);
    printf("\n en total hay %i \n",i);
return lista;
}
//////
nodoOrigen *alta(nodoOrigen *lista,registroEnvios aux){

    nodoOrigen *encontrado=buscaNodoOrigen(lista,aux.origen);
    nodoDestino *des=creaNodoDestino(aux);
    if(  encontrado==NULL){
         nodoOrigen *ori=creaNodoOrigen(aux);

        if(  strcmp(aux.tipo,"aereo")==0){
            ori->destinosAereos=agregarFinal(ori->destinosAereos,des);
        }
        else{
          ori->destinosFerro=agregarFinal(ori->destinosFerro,des);

        }
        lista=insertarRecursivo(lista,ori);

    }
    else{
        if(  strcmp(aux.tipo,"aereo")==0){
            encontrado->destinosAereos=agregarFinal(encontrado->destinosAereos,des);
        }
        else{
          encontrado->destinosFerro=agregarFinal(encontrado->destinosFerro,des);
        }
    }
return lista;
}
nodoOrigen *buscaNodoOrigen(nodoOrigen *lista,char aux[]){

    nodoOrigen *seg = lista;
    nodoOrigen *encontrado = NULL;

    while(seg!=NULL && encontrado==NULL){

        if( strcmp(seg->nombre,aux)==0)
            encontrado=seg;


        seg=seg->sig;

    }


return encontrado;

}
nodoOrigen *insertarRecursivo(nodoOrigen *lista, nodoOrigen *nuevo){
    if(!lista){
        lista = nuevo;
    }else if(strcmpi(nuevo->nombre, lista->nombre) < 0){
        nuevo->sig = lista;
        lista = nuevo;
    }else{
        lista->sig = insertarRecursivo(lista->sig, nuevo);
    }
    return lista;
}



/////
nodoOrigen *creaNodoOrigen(registroEnvios aux){

    nodoOrigen  *ori=(nodoOrigen*)malloc(sizeof(nodoOrigen));
    strcpy(ori->nombre,aux.origen);
    ori->destinosAereos=NULL;
    ori->destinosFerro=NULL;
    ori->sig=NULL;

return ori;
}
nodoDestino *creaNodoDestino(registroEnvios aux){

        nodoDestino * des = (nodoDestino*)malloc(sizeof(nodoDestino));
        strcpy(des->nombre,aux.destino);
        des->costo=aux.costo;
        des->tiempoViaje=aux.tiempoViaje;
        des->sig=NULL;


return des;
}
nodoDestino *agregarFinal(nodoDestino *lista,nodoDestino *nuevo){


    if(lista==NULL){
        lista=nuevo;
    }
    else{
        lista->sig=agregarFinal(lista->sig,nuevo);
    }

return lista;

}
///////////////////MOSTRAR LISTAS/////////////
void mostrarLista(nodoOrigen *lista){


    if (lista!=NULL){
        printf("\n ------Lista  %s ------\n",lista->nombre);
        printf("lista Ferrocarril\n ");
        mostrarListaDestino(lista->destinosFerro);
        printf("Lista Aereo\n");
        mostrarListaDestino(lista->destinosAereos);
        mostrarLista(lista->sig);
    }
}


void mostrarListaDestino(nodoDestino *lista){

    if(lista!=NULL){
        printf("Nombre:%s ,Costo: %2.2f ,TiempoViaje:%i \n",lista->nombre,lista->costo,lista->tiempoViaje);
        mostrarListaDestino(lista->sig);
    }
}
/////////2///

void muestraPromedioVuelos(nodoOrigen *lista,char origen[]){


    nodoOrigen *ori=buscaNodoOrigen(lista,origen);

    if(ori==NULL){
        printf("\n No se encontro la ciudad de origen\n");
    }
    else{
            int suma=sumaRecursivo(ori->destinosAereos);
            int total=totalRecursivo(ori->destinosAereos);
            printf("el total es %i  y la suma es %i \n",total,suma);
            if(total!=0)
                printf("El tiempo de vuelo promedio de la ciudad de orgigen %s es :%2.2f",origen,(float)suma/total);
            else
                printf("no hay vuelos aereos en la ciudad %s\n",origen);
    }
}
int sumaRecursivo(nodoDestino *lista){

    float rta=0;

    if(lista!=NULL){
        rta=lista->tiempoViaje+sumaRecursivo(lista->sig);
    }

return rta;

}

int totalRecursivo(nodoDestino *lista){

    float rta=0;

    if(lista!=NULL){
        rta=1+totalRecursivo(lista->sig);
    }

return rta;
}
/////////////////////3
void escribeArchivo(nodoOrigen *lista){

    nodoOrigen *seg;

    FILE *archAereo=fopen("destinosAereos.bin","ab");
    FILE *archFerro=fopen("destinosFerro.bin","ab");

    destinosAereos auxAE;
    destinosFerro auxFE;
    while(seg!=NULL){

            auxAE=cargadestinosAereos(seg->destinosAereos);
            strcpy(auxAE.ciudadOrigen,seg->nombre);
            auxFE=cargadestinosFerro(seg->destinosFerro);
            strcpy(auxFE.ciudadOrigen,seg->nombre);
            fwrite(&auxAE,sizeof(destinosAereos),1,archAereo);
            fwrite(&auxFE,sizeof(destinosFerro),1,archFerro);

        seg=seg->sig;
    }
    fclose(archAereo);
    fclose(archFerro);
}
destinosAereos cargadestinosAereos(nodoDestino *lista){

    destinosAereos aux;
    aux.cantDestinosAereos=totalRecursivo(lista);
    aux.costoPromedioAereo=totalCosto(lista)/totalRecursivo(lista);
    aux.tiempoPromedioAereo=(float)sumaRecursivo(lista)/totalRecursivo(lista);

return aux;
}

float totalCosto(nodoDestino *lista){

    float rta=0;

    if(lista!=NULL){
        rta=lista->costo+totalCosto(lista->sig);
    }

return rta;
}
destinosFerro cargadestinosFerro(nodoDestino *lista){

    destinosFerro aux;
    aux.cantDestinosFerro=totalRecursivo(lista);
    aux.costoPromedioFerro=totalCosto(lista)/aux.cantDestinosFerro;
    aux.tiempoPromedioFerro=(float)totalRecursivo(lista)/aux.cantDestinosFerro;

return aux;
}

/////////////muestro archivos chicos
void archivitos(){




FILE *archa=fopen("destinosAereos.bin","rb");
FILE *archb=fopen("destinosFerro.bin","rb");

    destinosAereos auxA;
    destinosFerro auxF;

    printf("\n \n destinos Aereos \n");
    if(fread(&auxA,sizeof(destinosAereos),1,archa)>0)
    {
       while(!feof(archa))
        {

          printf("Cantidad de destinos %i Origen %s  costoP %2.2f  tiempoP %2.2f \n",auxA.cantDestinosAereos,auxA.ciudadOrigen,auxA.costoPromedioAereo,auxA.tiempoPromedioAereo);

        fread(&auxA,sizeof(destinosAereos),1,archa);
        }
    }
    fclose(archa);

    printf("\n \n destinos Ferro\n");

     if(fread(&auxF,sizeof(destinosFerro),1,archb)>0)
    {
       while(!feof(archb))
        {

          printf("Cantidad de destinos %i Origen %s  costoP %2.2f  tiempoP %2.2f \n",auxF.cantDestinosFerro,auxF.ciudadOrigen,auxF.costoPromedioFerro,auxF.tiempoPromedioFerro);

        fread(&auxF,sizeof(destinosFerro),1,archb);
        }
    }

    fclose(archb);


}





eliminar de lisa simple



nodo *borrarNodoR(nodo *lista,int dato){


    nodo* aBorrar=NULL;

    if(lista!=NULL){
       if(lista->dato==dato){
        aBorrar=lista;
        lista=lista->sig;
        free(aBorrar);
       }
    else{
        lista->sig=borrarNodoR(lista->sig,dato);
    }


    return lista;






}
