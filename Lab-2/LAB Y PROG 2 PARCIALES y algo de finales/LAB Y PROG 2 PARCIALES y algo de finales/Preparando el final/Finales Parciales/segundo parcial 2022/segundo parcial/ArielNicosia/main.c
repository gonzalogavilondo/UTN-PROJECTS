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


typedef struct nodoArbol
{
    stVendedor vendedor;
    stSector   sector;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;




typedef struct{


nodoArbol *arbolVendedores;

}arregloArbol;




////////estructuras arbol
struct nodoArbol * inicArbol();
struct nodoArbol * crearNodoArbol(stRegistroVendedor auxRegistro);
struct nodoArbol * insertar(struct nodoArbol * arbol,struct nodoArbol *dato);



///////////1////////////////
struct nodoArbol *cargaDatos(struct nodoArbol * arbol,arregloArbol arreglo[],char nombreArch[],int *total);
/////////////2////////
void mostrarInorden(struct nodoArbol * arbol);
////////////3/////////////
int buscar(struct nodoArbol *arbol,int dni);
///////////////4//////////
void  buscarSector(arregloArbol arreglo[],int ventasTot,int idSec,int total);


////////5
int mayorVentas(arregloArbol arreglo[],int sector,int total);



int mejorSector(arregloArbol arreglo[],int total);

///////////////6///////////
 void    porcentajes(arregloArbol arreglo[],int total,int idSec);




/////////////
int main()
{
    int dni,ventasTot,idSec;
    char nombreArch[]="archivoRegistrosVendedor.bin";
    int total=0;
    arregloArbol  arreglo[300];
    struct nodoArbol *arbol=inicArbol();
    arbol=cargaDatos(arbol,arreglo,nombreArch,&total);
    mostrarInorden(arbol);
    printf("ingrese un dni para buscar empleado y ventas\n");
    scanf("%i",&dni);
    if(buscar(arbol,dni)==0)
        printf("\n------no se encontro al vendedor-----------\n");

    printf("ingrese el total de ventas a superar \n");
    scanf("%i",&ventasTot);
    printf("ingrese el id del sector \n");
    scanf("%i",&idSec);
    buscarSector(arreglo,ventasTot,idSec,total);
    printf("\n");
    printf("\n ---------------------\n");
    printf("\n el sector con mas ventas es %i \n",mejorSector(arreglo,total));
    printf("\n");
    printf("\n ---------------------\n");
    printf("ingrese un sector 1-2-3 para analizar sus ventas y las totales \n");
    scanf("%i",&idSec);
    porcentajes(arreglo,total,idSec);
    printf("\n");
    printf("\n ---------------------\n");
    return 0;
}




//////////////////Funciones///////////////






struct nodoArbol * inicArbol()
{
    return NULL;
}

struct nodoArbol * crearNodoArbol(stRegistroVendedor auxRegistro)
{
    struct nodoArbol * aux = (struct nodoArbol*) malloc(sizeof (struct nodoArbol));

    aux->vendedor.dni=auxRegistro.dni;
    aux->vendedor.ventasDiarias=auxRegistro.ventasDiarias;
    strcpy(aux->vendedor.nombreYapellido,auxRegistro.nombreYapellido);

    aux->sector.idSector=auxRegistro.idSector;
    strcpy(aux->sector.sector,auxRegistro.sector);



    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

struct nodoArbol * insertar(struct nodoArbol * arbol,struct nodoArbol *dato)
{
    if(arbol==NULL)
        arbol = dato;
    else

    {
        if(dato->vendedor.dni>arbol->vendedor.dni)
        arbol->der = insertar(arbol->der, dato);
        else
        arbol->izq = insertar(arbol->izq, dato);
    }
    return arbol;
}



///////////////
struct nodoArbol *cargaDatos(struct nodoArbol * arbol,arregloArbol arreglo[],char nombreArch[],int *total){

/// no estoy seguro si entendi bien pero el arreglo contiene un nodo del arbol, y en el arbol cargo todos los datos
// entre las dos estructuras la de vendedor y sector
    FILE* archivo=fopen(nombreArch,"rb");
    stRegistroVendedor   auxRegistro;
     struct nodoArbol *auxNodo;
    int tot=0;
    arregloArbol auxArreglo;
    if(fread(&auxRegistro,sizeof(stRegistroVendedor),1,archivo)>0){


         while(!feof(archivo))
        {


            auxNodo=crearNodoArbol(auxRegistro);
            auxArreglo.arbolVendedores=auxNodo;
            arbol=insertar(arbol,auxNodo);
            arreglo[tot]=auxArreglo;
            tot++;
            fread(&auxRegistro,sizeof(stRegistroVendedor),1,archivo);
        }
    }
    else{
        printf("Error al abrir archivo");
    }
 *total=tot;
fclose(archivo);
return arbol;
}
////////////////////2
void mostrarInorden(struct nodoArbol * arbol)
{
  if(arbol != NULL)
  {
   mostrarInorden(arbol->izq);
   printf("|Dni:%i   idSector:%i sector :%s Nombre:%s ,Ventas:%i|\n",arbol->vendedor.dni,arbol->sector.idSector,arbol->sector.sector,arbol->vendedor.nombreYapellido,arbol->vendedor.ventasDiarias);
   mostrarInorden(arbol->der);
  }
}

/////////      3 //////


int buscar(struct nodoArbol* arbol, int dato)
{

    int rta=0;
    if(arbol!=NULL)
    {
        if(dato==arbol->vendedor.dni){
           rta=1;
            printf("----------Empleado encontrado-----------\n");
            printf("Nombre empleado:%s  ventas :%i\n",arbol->vendedor.nombreYapellido,arbol->vendedor.ventasDiarias);
        }

        else
        {
             if(dato>arbol->vendedor.dni)
              rta=buscar(arbol->der,dato);
             else
                rta=buscar(arbol->izq,dato);
        }
    }
    return rta;


  //aca podria en vez de retornar 1,retornar la cantidad de ventas, pero queria informar el nombre del empleado
  //con sus ventas para que quede mas lindo
}

////////////////////4////////////////////////////
void  buscarSector(arregloArbol arreglo[],int ventasTot,int idSec,int total){


    int contador=0;
    printf("\n \n \n ");
    printf("--------------Los Vendedores son-------------\n");
    for(int i=0;i<total;i++){
        if(arreglo[i].arbolVendedores->sector.idSector==idSec)
            if(arreglo[i].arbolVendedores->vendedor.ventasDiarias>ventasTot){
                contador++;
                printf("Nombre:%s ,ventas :%i\n",arreglo[i].arbolVendedores->vendedor.nombreYapellido,arreglo[i].arbolVendedores->vendedor.ventasDiarias);
            }
    }
            if(contador==0){
            printf("no se encontraron vendedores que superen dichas ventas en el sector \n");
        }
    ///aca me confunde un poco el enunciado cuando dice usar la funcion del ejercicio uno, yo solo cargue datos en el punto uno
    // asi que me parecio mejor hacer un void para recorre e informar con mas precision cuales fueron los vendedores que superaron dicha venta y la cantidad

}

/////////////////        5//////////////
int mayorVentas(arregloArbol arreglo[],int sector,int total){
    int acumulador=0;



    for(int i=0;i<total;i++)
        if(arreglo[i].arbolVendedores->sector.idSector==sector)
            acumulador=acumulador+arreglo[i].arbolVendedores->vendedor.ventasDiarias;






return acumulador;
}


int mejorSector(arregloArbol arreglo[],int total){

    int mejorSec;
    int mejorVentas=0;
    int auxVentas;

    for(int i=1;i<=3;i++){
        auxVentas=mayorVentas(arreglo,i,total);
        if(auxVentas>mejorVentas){
            mejorVentas=auxVentas;
            mejorSec=i;
        }


       // printf("total ventas: %i  , sector :%i\n",mayorVentas(arreglo,i,total),i); esta para ver si suma bien las ventas por sector
      // si borro esta linea puedo ver como salieron los sectores en ventas, es para mi
    }



return mejorSec;
}



/////////////////////////////////Porcentaje sector        6/ ////////////


 void    porcentajes(arregloArbol arreglo[],int total,int idSec){


 int totalVentas=0,totalSector=0;
    float porcentaje;

    for(int i=1;i<=3;i++){
        totalVentas=totalVentas+mayorVentas(arreglo,i,total);
        if(i==idSec){
            totalSector=mayorVentas(arreglo,i,total);
            }

    }
    porcentaje=(totalSector*100)*1.0/totalVentas; //no me acordaba como hacer el cast para pasar a float y lo multiplique por 1.0
    printf("\n en total se vendio %i entre todos los sectores, y el sector %i, vendio un total de:%i \n",totalVentas,idSec,totalSector);
    printf("que representa un total de %2.2f de las ventas",porcentaje);




 }

