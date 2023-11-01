#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* Nueva librería necesaria para la funcion srand */
#include <windows.h>

typedef struct{

 int numero;


}valores;

typedef struct nodo{

  valores dato;
  struct nodo* siguiente ;
}nodo;

nodo *eliminarPorValor(nodo *lista);///202

nodo *cargaNumeros(nodo *lista); //linea 38
nodo *agregarFinal(nodo *lista,nodo *aux);///61
nodo *buscarUltimo(nodo * lista);///86
nodo *crearNodo (valores dato);//72
void mostrarIzquieraDerecha(nodo *lista);////96
void mostrarDerechaIzquierda(nodo *lista);////114
int cantidadNodos(nodo *lista); ///125
nodo *eliminarNodo(nodo *lista);//152
int main()
{

    nodo *lista=NULL;

    lista=cargaNumeros(lista);
    mostrarIzquieraDerecha(lista);
    printf("Lista de derecha a izquierda");
    mostrarDerechaIzquierda(lista);
    printf("\n \n la lista tiene un total de %i nodos \n",cantidadNodos(lista));
    Sleep(3000);
    system("cls");
    lista=eliminarNodo(lista);
    mostrarIzquieraDerecha(lista);
    Sleep(3000);
    system("cls");
    lista=eliminarPorValor(lista);
    mostrarIzquieraDerecha(lista);

    return 0;
}



nodo *cargaNumeros(nodo *lista){

    char control;

    valores aux;
    srand(time(NULL)); //Generamos numero aleatorio en base al tiempo
    printf("\n desea agregar otro numero a la lista ? s-n \n");
    fflush(stdin);
    scanf("%c",&control);
    fflush(stdin);

    while (control=='s'){
        aux.numero=rand() % 100; //Le indicamos que el numero será entre 0-100

        printf("\n el numero al azar es %i \n",aux.numero);
        fflush(stdin);
        lista=agregarFinal(lista,crearNodo(aux));
        printf("\n desea agregar otro numero a la lista ? s-n \n");
        scanf("%c",&control);





     }
  return lista;


}
//////////////////////////////////////////////////////////
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo) {
    if(lista == NULL) {
    lista = nuevoNodo;
    } else {
    nodo * ultimo = buscarUltimo(lista);
    ultimo->siguiente = nuevoNodo;
    }
return lista;
}
//////////////////////////////////////////////////////////////
nodo * crearNodo (valores dato) {
    //crea un puntero de tipo nodo
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    //asigna valores a sus campos de información
    aux->dato = dato;
    //asigna valor NULL al campo que contiene la dirección de memoria del
    //siguiente nodo
    aux->siguiente = NULL;
    //retorna la dirección de memoria del nuevo nodo, que deberá ser  asignada a una variable de tipo "puntero a nodo".
return aux;
}

//////////////
nodo * buscarUltimo(nodo * lista) {
    nodo * seg = lista;
    if(seg != NULL)
    while(seg->siguiente != NULL) {
    seg = seg->siguiente;
    }
    return seg;
}

///////////////////
void mostrarIzquieraDerecha(nodo *lista){
    nodo *auxNodo;
    auxNodo=lista;
    printf("Lista de izquierda a derecha");
    while(auxNodo!=NULL)
    {
        printf("  %i ", auxNodo->dato.numero);
        auxNodo=auxNodo->siguiente;
    }

printf("\n");
}
////////////////////////////
void mostrarDerechaIzquierda(nodo *lista){


    if(lista!=NULL){
       mostrarDerechaIzquierda(lista->siguiente);
        printf(" % i ",lista->dato.numero );
    }

}


////
int cantidadNodos(nodo *lista){


 int contador=0;

  while(lista!=NULL){
        contador++;
        lista=lista->siguiente;
  }

return contador;


}
///////////////////////////
nodo *eliminarNodo(nodo *lista){



   nodo  * anterior;
   nodo  * actual;

  int lugar,total=cantidadNodos(lista);
  printf("\n \n  En total hay %i nodos \n",total);
  printf("\n y los elementos de la lista son \n");
  mostrarIzquieraDerecha(lista);
  lugar=300;
  if(total==0)
    return lista;
  while( !((1<=lugar)&&(lugar<=total))){
    printf("\n Que nodo desea elimnar entre 1(izquierda) y %i (derecha) \n",total);
    scanf("%i",&lugar);

  }

  if((lista!=NULL) && (lugar==1)){
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux);
     }
  else{
        actual=lista;
        for(int i=1;i<lugar;i++){

            anterior = actual; //adelanto una posición la variable ante.
            actual = actual->siguiente; //avanzo al siguiente nodo.

        }
        //en este punto tengo en la variable ante la dirección de
        //memoria del nodo anterior al buscado, y en la variable seg,
        //la dirección de memoria del nodo que quiero borrar.

        if(actual!=NULL) {
            anterior->siguiente = actual->siguiente;
            //salteo el nodo que quiero eliminar.
            free(actual);
            //elimino el nodo.
        }
    }


return lista;

}
//////////////////////////////
nodo *eliminarPorValor(nodo *lista){
    nodo *anterior=NULL;
    nodo *actual;
    mostrarIzquieraDerecha(lista);
    int valor;
    printf("ingrese un valor para elimar los nodos mayores a ese valor \n ");
    scanf("%i",&valor);






        actual=lista;
        while(actual!=NULL){
            if (actual->dato.numero<valor){

                    if(anterior==NULL){

                        anterior=actual;
                        anterior->siguiente=NULL;
                    }
                    else{
                     nodo *aux=actual;
                     aux->siguiente=anterior;
                     anterior=aux;
                     free(aux);
                    }

                }

                actual=actual->siguiente;

        }


        printf("\n esta es la lista creada con anteior \n");
        mostrarIzquieraDerecha(anterior);
 return lista;
}
