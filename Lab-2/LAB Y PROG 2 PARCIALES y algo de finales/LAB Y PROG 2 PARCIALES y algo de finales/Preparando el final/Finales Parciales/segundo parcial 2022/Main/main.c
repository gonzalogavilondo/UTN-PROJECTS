#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct{
    int idSector;
    char sector[30];///los sectores son (y están escritos tal cual): "ropa","muebles","electro"
    int dni;
    char nombreYapellido[40];
    int ventasDiarias;
}stRegistroVendedor;

typedef struct{
    int idSector;
    char sector[30];
}stSector;


typedef struct{
    int dni;
    char nombreYapellido [40];
    int ventasDiarias;
}stVendedor;


typedef struct nodoArbol{
   stVendedor dato;
   struct nodoArbol *izq;
   struct nodoArbol *der;
}nodoArbol;

typedef struct{
    stSector dato;
    nodoArbol *arbol;
}arreglo;
////////////////////////1//////////////////////
int cargaArreglo(arreglo arreglo[],int dimension);
int alta(arreglo arreglo[],int validos,stRegistroVendedor aux);
int buscaPosicion(arreglo arreglo[],int validos,stRegistroVendedor aux);
int agregaSector(arreglo arreglo[],int validos,stRegistroVendedor aux);
nodoArbol *crearNodorbol(stRegistroVendedor aux);
stVendedor cargarNodoArbol(stRegistroVendedor aux);
nodoArbol *inicArbol();
nodoArbol *insertarNodo(nodoArbol *arbol, nodoArbol *nuevo);
/////2////
void mostrarArreglo(arreglo arreglo[],int validos);
void mostrarArbolInorder(nodoArbol *arbol);
void mostrarVendedor(stVendedor aux);
////////////3//////////
void     buscaEmpleado(arreglo arreglo[],int validos,int dni);
stVendedor buscaVendedor(nodoArbol *arbol,int dni);
////////////////4////////
void   ventasAsuperar(arreglo arreglo[],int validos,int sector,int ventas);
int cuentaVendedores(nodoArbol *arbol,int ventas);
/////////////////////5/////////////////////
void mayorSector(arreglo arreglo[],int validos,int sector);

int totalVentasSector(nodoArbol *arbol,int rta);

int main()
{
    int dimension=50;
    int dni;
    int ventas;
    int sector;
    arreglo  arreglo[dimension];
    int validos=cargaArreglo(arreglo,dimension);
    ////2////
    mostrarArreglo(arreglo,validos);
    ///3
    printf("\n\nIngrese el numero de dni del empleado para buscar sus ventas diarias\n");
    scanf("%i",&dni);
    buscaEmpleado(arreglo,validos,dni);
    ////////4/////////
    printf("\n ingrese el sector a buscar  1-ropa ,2- muebles, 3-electro\n");
    scanf("%i",&sector);
    printf("\n Ingrese el monto de ventas a superar para informar cuantos vendedores la superan \n");
    scanf("%i",&ventas);
    ventasAsuperar(arreglo,validos,sector,ventas);
    //////////////5//////////////////////
    printf("\n ingrese el sector a buscar  las mayores ventas  1-ropa ,2- muebles, 3-electro\n");
    scanf("%i",&sector);
    mayorSector(arreglo,validos,sector);
    return 0;
}
/////////////////////1/////////
int cargaArreglo(arreglo arreglo[],int dimension){

    int validos=0;
    FILE *arch=fopen("archivoRegistrosVendedor.bin","rb");

    stRegistroVendedor aux;
    while( fread(&aux,sizeof(stRegistroVendedor),1,arch)>0 && validos <dimension ){
        validos=alta(arreglo,validos,aux);


    }
    printf("\nlos validos son %i\n",validos);
    fclose(arch);
return validos;

}
int alta(arreglo arreglo[],int validos,stRegistroVendedor aux){

    int pos;
    pos=buscaPosicion(arreglo,validos,aux);
    if (pos==-1){
         validos=agregaSector(arreglo,validos,aux);
        pos=validos-1;
    }
    nodoArbol *nuevo=crearNodorbol(aux);
    arreglo[pos].arbol=insertarNodo(arreglo[pos].arbol,nuevo);
    return validos;
}
int buscaPosicion(arreglo arreglo[],int validos,stRegistroVendedor aux){

    int i;
    int pos=-1;

       while(i<validos && pos==-1){

            if(arreglo[i].dato.idSector==aux.idSector)
                pos=i;
        i++;
        }

return pos;
}
int agregaSector(arreglo arreglo[],int validos,stRegistroVendedor aux){

    arreglo[validos].dato.idSector=aux.idSector;
    strcpy(arreglo[validos].dato.sector,aux.sector);
    arreglo[validos].arbol=inicArbol();
    validos++;


return validos;
}
nodoArbol *inicArbol(){
    return NULL;

}
nodoArbol *crearNodorbol(stRegistroVendedor aux){

    nodoArbol *nodo=malloc(sizeof(nodoArbol));

    nodo->dato=cargarNodoArbol(aux);
    nodo->der=NULL;
    nodo->izq=NULL;

return nodo;
}
stVendedor cargarNodoArbol(stRegistroVendedor aux){

     stVendedor nuevo;
     nuevo.dni=aux.dni;
     nuevo.ventasDiarias=aux.ventasDiarias;
     strcpy(nuevo.nombreYapellido,aux.nombreYapellido);

return nuevo;
}
nodoArbol *insertarNodo(nodoArbol *arbol,nodoArbol *nuevo){

 if(!arbol){
    arbol=nuevo;
  }
  else{
     if ( arbol->dato.dni<nuevo->dato.dni )
        arbol->der=insertarNodo(arbol->der,nuevo);
     else
        arbol->izq=insertarNodo(arbol->izq,nuevo);
  }
  return arbol;


}
/////////////////////2/////////////
void mostrarArreglo(arreglo arreglo[],int validos){

    int i=0;
    while(i<validos){
        printf("\n\n Sector id= %i  Nombre del sector= %s",arreglo[i].dato.idSector,arreglo[i].dato.sector);
        mostrarArbolInorder(arreglo[i].arbol);
        i++;
    }
}
void mostrarArbolInorder(nodoArbol *arbol){

 if(arbol){
        mostrarArbolInorder(arbol->izq);
        mostrarVendedor(arbol->dato);
        mostrarArbolInorder(arbol->der);
 }

}
void mostrarVendedor(stVendedor aux){

    printf("\n DNI= %i ,NombreYapellido= %s ,VentasDiarias = %i ",aux.dni,aux.nombreYapellido,aux.ventasDiarias);


}
/////////////////////3////////////////
void     buscaEmpleado(arreglo arreglo[],int validos,int dni){

    stVendedor vendedor;
    int encontrado=0;
    int i=0;
    while(i<validos && encontrado==0){
         vendedor=buscaVendedor(arreglo[i].arbol,dni);
         if(vendedor.dni==dni)
            encontrado=1;
    i++;
    }

    if(encontrado==1){
            printf("\n DNI= %i ,NombreYapellido= %s ,VentasDiarias = %i ",vendedor.dni,vendedor.nombreYapellido,vendedor.ventasDiarias);
    }
    else{
        printf("\n no se encontro al vendedor");
    }

}
stVendedor buscaVendedor(nodoArbol *arbol,int dni){

    stVendedor aux;
     if(arbol){
        if(arbol->dato.dni==dni){
            printf("lo encontre");
            aux.dni=arbol->dato.dni;
            strcpy(aux.nombreYapellido,arbol->dato.nombreYapellido);
            aux.ventasDiarias=arbol->dato.ventasDiarias;
        }
        else{
            if ( arbol->dato.dni>dni )
                aux=buscaVendedor(arbol->der,dni);
            else
                aux=buscaVendedor(arbol->izq,dni);
        }
     }
  return aux;
}
///////////////////////////4////////////////

void     ventasAsuperar(arreglo arreglo[],int validos,int sector,int ventas){

    int encontrado=-1;
    stRegistroVendedor aux;
    aux.idSector=sector;
    encontrado=buscaPosicion(arreglo,validos,aux);

    if (encontrado!=-1){
        printf("\nencontre el sector");
        int conteo=cuentaVendedores(arreglo[encontrado].arbol,ventas);
        printf("\n en total hay %i vendedores que superan  los %i ",conteo,ventas);
    }
    else
        printf("\n no encontre el sector");



}

int cuentaVendedores(nodoArbol *arbol,int ventas){

    int rta=0;
    if(arbol){
        if(arbol->dato.ventasDiarias>ventas){
            printf("\n %i %s ",arbol->dato.ventasDiarias,arbol->dato.nombreYapellido);
            rta++;
        }
        rta=rta+cuentaVendedores(arbol->der,ventas);
        rta=rta+cuentaVendedores(arbol->izq,ventas);

           }

 return rta;
}

//////////////////////////5//////////////////////////
void mayorSector(arreglo arreglo[],int validos,int sector){


    int totalS=0;
    int mayorS=0;
    int mejorS=0;
    for(int i=0;i<validos;i++){
            if(arreglo[i].dato.idSector==sector){
                 totalS=totalVentasSector(arreglo[i].arbol,0);
                printf("\n Las ventas del sector %i  %s  es de %i\n\n\n",sector,arreglo[i].dato.sector,totalS);

            }
    }

    for(int i=0;i<validos;i++){

        totalS=totalVentasSector(arreglo[i].arbol,0);
        printf("\n Las ventas del sector con id  %i  %s  es de %i\n",i+1,arreglo[i].dato.sector,totalS);
        if(totalS>mayorS){
            mayorS=totalS;
            mejorS=i+1;
        }
    }
    printf("\n\n el sector que hizo mas ventas es %i %s con %i\n\n",mejorS,arreglo[mejorS].dato.sector,mayorS);






}

int totalVentasSector(nodoArbol *arbol,int rta){



    if(arbol){
        rta=rta+arbol->dato.ventasDiarias+ totalVentasSector(arbol->der,rta)+totalVentasSector(arbol->izq,rta);

    }

    return rta;

}



















