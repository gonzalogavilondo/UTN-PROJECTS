#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct{

    int idSucursal;
    char nombreSucursal[25];
    char nombreProducto[25];
    char deporte[25];
    int stockProducto;
}stRegistro;                ///esto es lo que esta en el archivo

typedef struct{
    int idSucursal;
    char nombreSucursal[25];         //esto va al arreglo
}stSucursal;

typedef struct{
    char nombreProducto[25];          //esto va en el arbol
    char deporte[25];
    int stockProducto;
}stProducto;

typedef struct {
    stProducto dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;             //el arbol
}nodoArbol;

typedef struct{
    stSucursal sucursal;
    nodoArbol *arbolProductos;      //el arreglo
}celda;

//////////////1//////////////
int pasarArchivoToADA(celda arreglo[],int  dimension);
int alta(celda arreglo[],int validos, stRegistro aux);
int agregarSucursal (celda arreglo[],int validos, int idSucursal, char sucursal[]);
int buscarPosicion(celda arreglo[],int validos, int idSucursal);
nodoArbol *crearNodoArbol(stRegistro aux);
stProducto cargarDatoArbol (stRegistro aux);
nodoArbol *insertarNodo(nodoArbol  *arbol, nodoArbol *nuevo);
nodoArbol  *inicArbol();
////////////////////2////////////////////

void mostrarProducto(stProducto aux);
void inorder(nodoArbol *arbol);
void mostrarADA (celda arreglo[],int validos );
///////////////3/////////////////////
int buscaProducto(celda arreglo[],int validos,char nombreProducto[], char deporte[]);
void productoEncontrado(celda arreglo[],int validos,char nombreProducto[], char deporte[]);
int  buscaArbolProducto(nodoArbol *arbol,char nombreProducto[],char deporte[] );
////////////////4//////////////
void cantidadMenor(celda arreglo[],int validos, char deporte[]);
int cantidadStock(nodoArbol *arbol ,char deporte[]);
//////////////////5/////////////////////
void sumaStocks(celda arreglo[],int validos,int  sucursalElegida);
int stockTotal(nodoArbol *arbol);
void informaPorcentaje(int sucursalStock, int stockTotalSucursales);



int main()
{
    int dimension=50;
    celda  arreglo[dimension];
    char deporte[25];
    char nombreProducto[25];
    int sucursal;
    ////1/////
    int validos=pasarArchivoToADA(arreglo,dimension);
    ///2///
    mostrarADA(arreglo,validos);
    ///3///
    printf("ingrese el nombre del producto\n");
    fflush(stdin);
    scanf("%s",nombreProducto);
    printf("ingrese el nombre del deporte \n");
    fflush(stdin);
    scanf("%s",deporte);
    productoEncontrado(arreglo,validos,nombreProducto,deporte);
    ////4
    printf("\n Ingrese el nombre del deporte para buscar sucursal con menor stock\n");
    fflush(stdin);
    scanf("%s",deporte);
    cantidadMenor(arreglo,validos,deporte);

   ////5////
    printf("ingrese una sucursal para calcular cantidad de productos y su porcentaje sobre el total de productos \n");
    scanf("%i",&sucursal);
    sumaStocks(arreglo,validos,sucursal);


    return 0;
}
///////////1///////////////////////1//////////////////////
int pasarArchivoToADA(celda arreglo[],int  dimension){

    int validos=0;
    FILE *buf=fopen("archivoRegistrosIndumentaria.bin","rb");
    stRegistro aux;

    if(buf){
        while(fread(&aux,sizeof(stRegistro),1,buf)>0 && validos <dimension){
            validos=alta(arreglo,validos,aux);

        }
        fclose(buf);

    }
    else{
        printf("Error al abrir el archivo \n");
    }


return validos;
}

int alta(celda arreglo[],int validos, stRegistro aux){

    int pos=buscarPosicion(arreglo,validos,aux.idSucursal);

    if(pos==-1){
        validos=agregarSucursal(arreglo,validos,aux.idSucursal, aux.nombreSucursal);
        pos=validos-1;
    }
    nodoArbol *nuevo=crearNodoArbol(aux);
    arreglo[pos].arbolProductos=insertarNodo(arreglo[pos].arbolProductos,nuevo);

    return validos;
}



int buscarPosicion(celda arreglo[],int validos, int idSucursal){//1

    int pos=-1;
    int i=0;


    while(i<validos && pos==-1){

        if(arreglo[i].sucursal.idSucursal==idSucursal)
            pos=i;
        i++;
    }
return pos;
}

int agregarSucursal (celda arreglo[],int validos, int idSucursal, char sucursal[]){//1

    arreglo[validos].sucursal.idSucursal=idSucursal;
    strcpy(arreglo[validos].sucursal.nombreSucursal,sucursal);
    arreglo[validos].arbolProductos=inicArbol();
    validos++;
    return validos;
}
nodoArbol  *inicArbol(){

    return NULL;
}

nodoArbol *crearNodoArbol(stRegistro aux){//1

    nodoArbol *nuevo=malloc(sizeof(nodoArbol));

    nuevo->dato=cargarDatoArbol(aux);
    nuevo->izq= NULL;
    nuevo->der=NULL;

    return nuevo;
}
stProducto cargarDatoArbol (stRegistro aux){//1

    stProducto nuevo;

    strcpy(nuevo.nombreProducto,aux.nombreProducto);
    strcpy(nuevo.deporte,aux.deporte);
    nuevo.stockProducto=aux.stockProducto;

    return nuevo;
}
nodoArbol *insertarNodo(nodoArbol  *arbol, nodoArbol *nuevo){//1

  if(!arbol){
    arbol=nuevo;
  }
  else{
     if ( ((strcmp(arbol->dato.nombreProducto,nuevo->dato.nombreProducto))>0) || (((strcmp(arbol->dato.nombreProducto,nuevo->dato.nombreProducto)) == 0) && strcmp(arbol->dato.deporte,nuevo->dato.deporte) >  0) )
        arbol->der=insertarNodo(arbol->der,nuevo);
     else
        arbol->izq=insertarNodo(arbol->izq,nuevo);
  }
  return arbol;
}
/*ejercicio 2*/

void mostrarADA (celda arreglo[],int validos ){//2

    int i=0;

    while(i<validos){
        printf("----------------------------------------------------\n");
        printf("Sucursal %s (ID %i) \n", arreglo[i].sucursal.nombreSucursal,arreglo[i].sucursal.idSucursal);
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
        inorder(arreglo[i].arbolProductos);
        i++;

    }

}
void inorder(nodoArbol *arbol){//2

    if(arbol){
        inorder(arbol->izq);
        mostrarProducto(arbol->dato);
        inorder(arbol->der);
    }
}
void mostrarProducto(stProducto aux){//2

    printf("NOMBRE Del Producto: %s\n",aux.nombreProducto);
    printf("NOMBRE Del Deporte: %s\n",aux.deporte);
    printf("STOCK Del Producto: %i\n",aux.stockProducto);
    printf("-----------------------\n");
}

///////// *Ejercicio 3 */////

int  buscaProducto(celda arreglo[],int validos,char nombreProducto[], char deporte[]){//3


    int i=0;
    int busc=-1;

    while(i<validos && busc==-1){
        busc=buscaArbolProducto(arreglo[i].arbolProductos,nombreProducto,deporte);
        if(busc==1){
            busc=i;
        }
        i++;

    }
return busc;
}

int  buscaArbolProducto(nodoArbol *arbol,char nombreProducto[],char deporte[] ){//3


    int  busc=-1;
    if(arbol && busc==-1){
        if ( (((strcmp(arbol->dato.nombreProducto,nombreProducto)) == 0) && strcmp(arbol->dato.deporte,deporte) ==  0) )
            busc=1;
        else{
            if (strcmp(arbol->dato.nombreProducto,nombreProducto) >0)
                busc=buscaArbolProducto(arbol->der,nombreProducto,deporte);
            else
                busc=buscaArbolProducto(arbol->izq,nombreProducto,deporte);
        }
    }


return busc;

}


void productoEncontrado(celda arreglo[],int validos,char nombreProducto[], char deporte[]){//3

    int encontrado=buscaProducto(arreglo,validos,nombreProducto,deporte);


    if (encontrado!=-1){
        printf("Se encontro el producto  %s   del deporte %s\n",nombreProducto,deporte);
        printf("En la sucursal %s  con el ID : %i  \n",arreglo[encontrado].sucursal.nombreSucursal,arreglo[encontrado].sucursal.idSucursal);
        inorder(arreglo[encontrado].arbolProductos);
    }


}
/////////////*Ejercicio 4*/
void cantidadMenor(celda arreglo[],int validos, char deporte[]){//4



        int i=0;
        int stock;
        int menorSucursalStock=5000;
        int menorIdSucursal;
        char menorNombreSucursal[40];

        while(i<validos){

            stock=cantidadStock(arreglo[i].arbolProductos,deporte);

            if(stock<menorSucursalStock && stock!=0){

                menorSucursalStock=stock;
                menorIdSucursal=arreglo[i].sucursal.idSucursal;
                strcpy(menorNombreSucursal,arreglo[i].sucursal.nombreSucursal);

            }
            i++;
        }


    printf("\n\n en la sucursal NOMBRE :%s  con el ID :%i se encontro el menor stock del deporte %s, y fue de :%i \n",menorNombreSucursal,menorIdSucursal,deporte,menorSucursalStock);

}

int cantidadStock(nodoArbol *arbol ,char deporte[]){//4


    int rta=0;

    if(arbol==NULL){
        rta=0;
    }
    else  {
        if( strcmp(arbol->dato.deporte,deporte) ==  0)
            rta=arbol->dato.stockProducto+cantidadStock(arbol->izq,deporte) +cantidadStock(arbol->der, deporte);
        else
            rta=cantidadStock(arbol->izq,deporte) +cantidadStock(arbol->der, deporte);
    }
return rta;
}
///////////////////5///////////////////////////


void sumaStocks(celda arreglo[],int validos,int  sucursalElegida){///5


  int  sucursalStock=0;

  int  stockTotalSucursales=0;
  int i=0;

  while(i<validos){

     if(arreglo[i].sucursal.idSucursal==sucursalElegida)
            sucursalStock=stockTotal(arreglo[i].arbolProductos);

     stockTotalSucursales=stockTotalSucursales+stockTotal(arreglo[i].arbolProductos);
     i++;
  }



   informaPorcentaje(sucursalStock,stockTotalSucursales);



}




int stockTotal(nodoArbol *arbol){///5

  int   stock=0;


  if(arbol){
        stock=arbol->dato.stockProducto+stockTotal(arbol->der)+stockTotal(arbol->izq);
    }
  return stock;
}

void informaPorcentaje(int sucursalStock, int stockTotalSucursales){//5

    float total;
    if( sucursalStock!=0){
            printf("En la sucursal hay %i de productos y entre todas la sucursales hay un total de %i productos",sucursalStock,stockTotalSucursales);
            total=((sucursalStock*0.1)*100)/(stockTotalSucursales*0.1);
            printf("\n Los productos de la sucursal elegida representan un %2.2f porciento de los productos",total);
    }
    else{
        printf("Error no se encontro la sucursal!");
    }


}
