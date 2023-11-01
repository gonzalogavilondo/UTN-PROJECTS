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

typedef struct {
    stVendedor dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;


typedef struct{
    stSector sector;
    nodoArbol *arbolVendedores;
}celda;


/////////////////////////////
int pasarArchivoToADA(celda arreglo[],int  dimension);
int alta(celda arreglo[],int validos, stRegistroVendedor aux);
nodoArbol *crearNodoArbol(stRegistroVendedor aux);
stVendedor cargarDatoArbol (stRegistroVendedor aux);
int buscarPosicion(celda arreglo[],int validos, int idSector);
int agregarSector (celda arreglo[],int validos, int idSector, char sector[]);
nodoArbol *insertarNodo(nodoArbol *arbol, nodoArbol *nuevo);
nodoArbol  *inicArbol();


/////////////////////////////
int main()
{
    printf("Hello world!\n");
    return 0;
}




/**ejercicio 1**/
int pasarArchivoToADA(celda arreglo[],int  dimension){

    int validos=0;
    FILE *buf=fopen("archivoRegistroVendedor.bin","rb");
    stRegistroVendedor aux;

    if(buf){
        while(fread(&aux,sizeof(stRegistroVendedor),1,buf)>0 && validos <dimension){
            validos=alta(arreglo,validos,aux);

        }
        fclose(buf);

    }
    else{
        printf("Error al abrir el archivo \n");
    }


return validos;
}


int alta(celda arreglo[],int validos, stRegistroVendedor aux){

    int pos=buscarPosicion(arreglo,validos,aux.idSector);

    if(pos==-1){
        validos=agregarSector(arreglo,validos,aux.idSector, aux.sector);
        pos=validos-1;

    }
    nodoArbol *nuevo=crearNodoArbol(aux);
    arreglo[pos].arbolVendedores=insertarNodo(arreglo[pos].arbolVendedores,nuevo);

    return validos;
}


nodoArbol *crearNodoArbol(stRegistroVendedor aux){

    nodoArbol *nuevo=malloc(sizeof(nodoArbol));

    nuevo->dato=cargarDatoArbol(aux);
    nuevo->izq= NULL;
    nuevo->der=NULL;

    return nuevo;
}

stVendedor cargarDatoArbol (stRegistroVendedor aux){

    stVendedor nuevo;
    nuevo.dni=aux.dni;
    strcpy(nuevo.nombreYapellido,aux.nombreYapellido);
    nuevo.ventasDiarias=aux.ventasDiarias;

    return nuevo;
}

int buscarPosicion(celda arreglo[],int validos, int idSector){

    int pos=-1;
    int i=0;


    while(i<validos && pos==-1){

        if(arreglo[i].sector.idSector==idSector)
            pos=i;
        i++;
    }
return pos;
}

int agregarSector (celda arreglo[],int validos, int idSector, char sector[]){

    arreglo[validos].sector.idSector=idSector;
    strcpy(arreglo[validos].sector.sector,sector);
    arreglo[validos].arbolVendedores=inicArbol();

    return validos;
}
nodoArbol  *inicArbol(){

    return NULL;
}

nodoArbol *insertarNodo(nodoArbol  *arbol, nodoArbol *nuevo){

  if(!arbol){
    arbol=nuevo;
  }
  else{
     if (nuevo->dato.dni> arbol->dato.dni)
        arbol->der=insertarNodo(arbol->der,nuevo);
     else
        arbol->izq=insertarNodo(arbol->izq,nuevo);
  }
  return arbol;
}

/*ejercicio 2*/

void mostrarADA (celda arreglo[],int validos ){

    int i=0;

    while(i<validos){
        printf("----------------------------------------------------\n");
        printf("Sector %s (ID %i) \n", arreglo[i].sector.sector,arreglo[i].sector.idSector);
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
        inorder(arreglo[i].arbolVendedores);
        i++;

    }

}
void inorder(nodoArbol *arbol){

    if(arbol){
        inorder(arbol->izq);
        mostrarVendedor(arbol->dato);
        inorder(arbol->der);
    }
}
void mostrarVendedor(stVendedor aux){
    printf("DNI: %i\n",aux.dni);
    printf("NOMBRE Y APELLIDO: %s\n",aux.nombreYapellido);
    printf("Ventas Diarias : $%i \n",aux.ventasDiarias);
    printf("-----------------------\n");
}

///////// *Ejercicio 3 */////

nodoArbol *buscaVendedorArreglo(celda arreglo[],int validos,int dni){


    int i=0;
    nodoArbol *busc=NULL;

    while(i<validos && !busc){
        busc=buscaVendedorArbol(arreglo[i].arbolVendedores,dni);
        i++

    }
return busc;
}

nodoArbol *buscaVendedorArbol(nodoArbol *arbol, int dni){


    nodoArbol *busc=null;

    if(arbol){
        if(dni==arbol->dato.dni)
            busc=arbol;
        else{
            if (dni>arbol->dato.dni)
                busc=buscaVendedorArbol(arbol->der,dni);
            else
                busc=buscaVendedorArbol(arbol->izq,dni);
        }
    }


return busc;

}


/////////////*Ejercicio 4*/
int cantidadVendedoresSuperiores(celda arreglo[],int validos, int idSector, int ventas){

    int pos=buscarPosicion(arreglo,validos,idSector);

    if(pos!=-1){
        int cantidad= cantidadVendedoresSUperioresSector(arreglo[pos].arbolVendedores,ventas);
        return cantidad;
    }
    else
        return -1;
}
////esta es otra version posible
int cantidadVendedoresSuperioresSector2(nodoArbol *arbol ,int ventas){


    int rta=0;

    if(arbol==NULL){
        rta=0;
    }
    else  {
        if(arbol->dato.ventasDiarias>ventas)
            rta=1+cantidadVendedoresSuperioresSector2(arbol->izq,ventas) +cantidadVendedoresSuperioresSector2(arbol->der, ventas);
        else
            rta=cantidadVendedoresSuperioresSector2(arbol->izq,ventas) +cantidadVendedoresSuperioresSector2(arbol->der, ventas);
    }
return rta;
}

int cantidadVendedoresSuperioresSector(nodoArbol *arbol,int ventas){

 int cantidad=0;

     if(arbol){

        if(arbol->dato.ventasDiarias>ventas){
            cantidad++
            cantidad+=cantidadVendedoresSuperioresSector(arbol->izq,ventas);
            cantidad+=cantidadVendedoresSuperioresSector(arbol->der,ventas);
            }
     }
  return cantidad;
 }







