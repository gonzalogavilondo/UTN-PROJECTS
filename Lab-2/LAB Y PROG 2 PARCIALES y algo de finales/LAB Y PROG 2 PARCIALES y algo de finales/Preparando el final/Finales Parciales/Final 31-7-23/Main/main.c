#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int idSucursal;
    char nombreSucursal[25];
    char nombreDisfraz[25];
    char generoDisfraz[25];
    int stockDisfraz;
}stRegistroDisfraz;


typedef struct{
    int idSucursal;
     char nombreSucursal[25];
}stSucursal;

typedef struct{
    char nombreDisfraz[25];
    char generoDisfraz[25];
    int stockDisfraz;
}stDisfraz;


 typedef struct nodo{
  stDisfraz dato;
  struct nodo* sig;

 }nodo;

typedef struct nodo2{
    stSucursal dato;
    struct nodo *listaS;
    struct nodo2 *sig;
    struct nodo2 *ante;
}nodo2;



typedef struct nodoArbol{

     stRegistroDisfraz  dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;

}nodoArbol;








//////////////////1
nodo  *inicLista();
nodo2 *inicLista2();

nodo *crearNodo(stRegistroDisfraz  datos);
nodo2 *creanodo2(stRegistroDisfraz datos);

nodo2 * buscarUltimoDobleRecursivo (nodo2 * lista);
nodo2 *agregarNodo2(nodo2 *lista,nodo2 *nuevo);




nodo *agregarNodo(nodo *lista,nodo *nuevo);



nodo2 *alta(nodo2 *lista);
nodo2 *buscaNodo2(nodo2 *lista,nodo2 *nodoDoble);

nodo2 *cargaNodos(nodo2 *lista,stRegistroDisfraz aux);



////2
void mostrarLista(nodo2 *lista);
void mostrarListita(nodo *lista);




//3
nodoArbol *inicArbol();
nodoArbol *crearNodoarbol(stRegistroDisfraz aux);
nodoArbol *insertarNodo(nodoArbol *arbol,nodoArbol *nuevo);


nodoArbol *cargaArbol(nodo2 *lista,nodoArbol *arbol);


///4
void mostrarInfo(stRegistroDisfraz aux);


void mostrarArbolInorder(nodoArbol *arbol);




////5
nodoArbol *buscaDisfraz(nodoArbol *arbol,stRegistroDisfraz aux);
void buscaArbol(nodoArbol *arbol);


int main()
{
    nodo2 *lista=inicLista2();
    lista=alta(lista);
    printf("\n-------Muestro la lista---------\n");
    mostrarLista(lista);
    nodoArbol *arbol=inicArbol();
    arbol=cargaArbol(lista,arbol);
    printf("\n-------Muestro el arbol---------\n");
    mostrarArbolInorder(arbol);
    buscaArbol(arbol);
    return 0;
}

////////////1
nodo  *inicLista(){
    return NULL;
}
nodo2 *inicLista2(){//1
    return NULL;
}



nodo *crearNodo(stRegistroDisfraz  datos){//1

    nodo *aux=(nodo*)malloc(sizeof(nodo));
    aux->dato.stockDisfraz=datos.stockDisfraz;
    strcpy(aux->dato.generoDisfraz,datos.generoDisfraz);
    strcpy(aux->dato.nombreDisfraz,datos.nombreDisfraz );
    aux->sig=inicLista();

return aux;
}



nodo2 *crearNodo2(stRegistroDisfraz datos){//1

    nodo2 *aux=(nodo2*)malloc(sizeof(nodo2));
    aux->dato.idSucursal=datos.idSucursal;
    strcpy(aux->dato.nombreSucursal,datos.nombreSucursal);
    aux->sig=inicLista2();
    aux->ante=inicLista2();
    aux->listaS=inicLista();
return aux;
}





nodo2 * buscarUltimoDobleRecursivo (nodo2 * lista) {//1
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
nodo2 *agregarNodo2(nodo2 *lista,nodo2 *nuevo){//1

    if(lista == NULL) {
        lista = nuevo;
    } else {
        nodo2 * ultimo = buscarUltimoDobleRecursivo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }
return lista;
}


nodo *agregarNodo(nodo *lista,nodo *nuevo){//1

    if(lista==NULL){
        lista=nuevo;
    }
     else{
        if ( strcmp(lista->dato.nombreDisfraz,nuevo->dato.nombreDisfraz)<0  ||  (strcmp(lista->dato.nombreDisfraz,nuevo->dato.nombreDisfraz)==0 && strcmp(lista->dato.generoDisfraz,nuevo->dato.generoDisfraz)<0)){
            nuevo->sig=lista;
            lista=nuevo;
        }
        else{
            lista->sig=agregarNodo(lista->sig,nuevo);
        }
    }
return lista;

}


nodo2 *alta(nodo2 *lista){//1

    FILE *arch=fopen("archivoRegistrosDisfraces.bin","rb");
    stRegistroDisfraz aux;
    if(arch!=NULL){
        while( (fread(&aux,sizeof(stRegistroDisfraz),1,arch)>0 )){


           lista=cargaNodos(lista,aux);

        }
    }
    else
        printf("\n Error al abrir el archivo\n");
    fclose(arch);
return lista;
}


nodo2 *cargaNodos(nodo2 *lista,stRegistroDisfraz aux){//1

    nodo2* nodoDoble=crearNodo2(aux);
    nodo *nodito=crearNodo(aux);

    nodo2 *pos=buscaNodo2(lista,nodoDoble);


    if(pos==NULL){

        nodoDoble->listaS=agregarNodo(nodoDoble->listaS,nodito);
        lista=agregarNodo2(lista,nodoDoble);
    }
    else{
         pos->listaS=agregarNodo(pos->listaS,nodito);
    }
return lista;
}





nodo2 *buscaNodo2(nodo2 *lista,nodo2 *nodoDoble){//1

    nodo2 *rta;
    if(lista==NULL)
        rta=NULL;
    else{
            if(  strcmp(lista->dato.nombreSucursal,nodoDoble->dato.nombreSucursal)==0)
                rta=lista;
            else{
                rta=buscaNodo2(lista->sig,nodoDoble);
            }
    }
return rta;

}



void mostrarLista(nodo2 *lista){//2



        if(lista!=NULL){

            mostrarLista(lista->sig);
            puts ("\n************************************** SUCURSAL ****************************************\n");
            printf ("Id de la Sucursal..: %i ",lista->dato.idSucursal);
            printf("Nombre de la Sucursal:..:%s \n", lista->dato.nombreSucursal);
            puts ("\n");
            mostrarListita(lista->listaS);

        }

}
void mostrarListita(nodo *lista){//2

    if(lista!=NULL){
    printf("\nNombre del disfraz..: %s  ", lista->dato. nombreDisfraz);
    printf("Genero al que pertenece..: %s  ", lista->dato. generoDisfraz);
    printf("Stock del disfraz..: %d \n", lista->dato. stockDisfraz);

       mostrarListita(lista->sig);
    }
}


/////////////3



nodoArbol *inicArbol(){
    return NULL;

}
nodoArbol *crearNodoarbol(stRegistroDisfraz aux){//3

    nodoArbol *nodo=malloc(sizeof(nodoArbol));

    nodo->dato=aux;
    nodo->der=NULL;
    nodo->izq=NULL;

return nodo;
}



nodoArbol *insertarNodo(nodoArbol *arbol,nodoArbol *nuevo){///4

 if(!arbol){
    arbol=nuevo;
  }
  else{
     if (  strcmp(arbol->dato.nombreDisfraz,nuevo->dato.nombreDisfraz)<0  ||   (  strcmp(arbol->dato.nombreDisfraz,nuevo->dato.nombreDisfraz)==0  &&   strcmp(arbol->dato.generoDisfraz,nuevo->dato.generoDisfraz)<0    ) )
            //en esta condicion veo  primero  si tienen distinto nombre o si tienen el mismo nombre pero cambian en genero y lo ordeno por el genero
        arbol->der=insertarNodo(arbol->der,nuevo);
     else
        arbol->izq=insertarNodo(arbol->izq,nuevo);
  }
  return arbol;

}



////4
void mostrarArbolInorder(nodoArbol *arbol){//4

 if(arbol){
        mostrarArbolInorder(arbol->izq);
        mostrarInfo(arbol->dato);
        mostrarArbolInorder(arbol->der);
 }


}
void mostrarInfo(stRegistroDisfraz aux){//4

    printf("\n Nombre Local :%s        Nombre Disfraz :%s           Stock :%i             genero :%s ",aux.nombreSucursal,aux.nombreDisfraz,aux.stockDisfraz,aux.generoDisfraz);


}
nodoArbol *cargaArbol(nodo2 *lista,nodoArbol *arbol){//4

    stRegistroDisfraz aux;
    nodo2 *seg=lista;
    while(seg!=NULL){
        aux.idSucursal=seg->dato.idSucursal;
        strcpy(aux.nombreSucursal,seg->dato.nombreSucursal);
        while(seg->listaS!=NULL){
            aux.stockDisfraz=seg->listaS->dato.stockDisfraz;
            strcpy(aux.nombreDisfraz,seg->listaS->dato.nombreDisfraz);
            strcpy(aux.generoDisfraz,seg->listaS->dato.generoDisfraz);
            arbol=insertarNodo(arbol,crearNodoarbol(aux));
            seg->listaS=seg->listaS->sig;
        }

        seg=seg->sig;
    }



return arbol;
}




//////////5
void buscaArbol(nodoArbol *arbol){

    stRegistroDisfraz aux;
    nodoArbol *nodoArbol;
    printf("\n Ingrese el nombre del disfraz\n");
    gets(aux.nombreDisfraz);
    printf("\n Ingrese el genero \n");
    gets(aux.generoDisfraz);


    nodoArbol=buscaDisfraz(arbol,aux);

    if(nodoArbol==NULL)
        printf("\n No se encontro el disfraz");
    else{
        printf("\n El disfraz :%s del genero :%s  esta en el local de :%s y hay un stock de :%i",nodoArbol->dato.nombreDisfraz,nodoArbol->dato.generoDisfraz,nodoArbol->dato.nombreSucursal,nodoArbol->dato.stockDisfraz);
    }
}

nodoArbol* buscaDisfraz(nodoArbol *arbol,stRegistroDisfraz aux){///5

    nodoArbol *nodo=NULL;

    if(arbol!=NULL){

        if(       strcmp(arbol->dato.nombreDisfraz,aux.nombreDisfraz)==0 && strcmp(arbol->dato.generoDisfraz,aux.generoDisfraz)==0                              ){
            nodo=arbol;
        }
        else{
            if(  strcmp(arbol->dato.nombreDisfraz,aux.nombreDisfraz)>0)
                arbol=buscaDisfraz(arbol->der,aux);
            else
                arbol=buscaDisfraz(arbol->izq,aux);
        }

    }




return nodo;


}
