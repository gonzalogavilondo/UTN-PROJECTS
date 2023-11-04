#include "especie.h"

/// busca posicion
int buscaPosEspecie(stCeldaEspecie ada[], stEspecie e, int validos)
{
    int rta = -1;
    int i = 0;
    while((i < validos) && (rta == -1))
    {
        if(strcmp(ada[i].e.especie, e.especie)==0){
            rta=i;
        }
        i++;
    }
    return rta;
}

/// agrega stCeldaEspecie
int agregar(stCeldaEspecie ada[], stEspecie e, int validos)
{
    ada[validos].e = e;
    ada[validos].arbolDeAnimales = inicArbol();
    validos++;
    return validos;
}

/// alta en el adA
int alta (stCeldaEspecie ada[], stEspecie e, stAnimal a, int validos)
{
    nodoArbol* aux = crearNodoArbol(a);
    int pos = buscaPosEspecie(ada,e,validos);
    if(pos == -1)
    {
        validos = agregar(ada, e, validos);
        pos = validos - 1;
    }
    ada[pos].arbolDeAnimales = insertar(ada[pos].arbolDeAnimales, aux);
    return validos;
}

/// Lee el archivo y carga el arreglo de ARBOLES
int archivo2ada(stCeldaEspecie ada[], int validos, int dim)
{
    FILE* arch=fopen(arRegistro, "rb");
    if(arch)
    {
        stRegistroArchivo rg;
        stEspecie e;
        stAnimal a;
        while((fread(&rg,sizeof(stRegistroArchivo), 1, arch) > 0) && (validos<=dim))
        {
            e.idEspecie=rg.idEspecie;
            strcpy(e.especie,rg.especie);
            a.cantidad = rg.cant;
            strcpy(a.nombreAnimal,rg.animal);
            a.habitat = rg.habitat;
            validos = alta(ada,e,a,validos);
        }
        fclose(arch);
    }
    return validos;
}

/// Muestra el arreglo de arboles
void mostrarADA(stCeldaEspecie ada[], int validos)
{
    printf("\nMostrando el arreglo de especies: \n");
    int i=0;
    while(i < validos)
    {
        printf("\nEspecie %2d: %s",ada[i].e.idEspecie, ada[i].e.especie);
        printf("\nArbol de animales..........: %6d", sumarCantNodosArbol(ada[i].arbolDeAnimales));
        printf("\nCantidad total de animales.: %6d\n", sumarCantAnimalesArbol(ada[i].arbolDeAnimales));
        replicante('_',50);
        inorder(ada[i].arbolDeAnimales);
        i++;
    }
}

/// Recorre el arreglo de arboles y guarda los animales en archivos separados por especie
void guardarEspecies(stCeldaEspecie ada[],int validos)
{
    char arEspecie[20];
    for(int i = 0; i < validos; i++)
    {
        arEspecie[0] = '\0';                      /// Genero el nombre del archivo con el nombre de la especie
        strcat(arEspecie,ada[i].e.especie);
        strcat(arEspecie,".dat");

        FILE* pArch = fopen(arEspecie,"wb");
        if(pArch)
        {
            guardarArbol(pArch,ada[i].arbolDeAnimales);
            fclose(pArch);
        }
    }
}
/// Guardo los datos del arbol correspondiente a cada especie
void guardarArbol(FILE* pf, nodoArbol* arbol)
{
    if(arbol)
    {
        guardarArbol(pf, arbol->izq);
        fwrite(&arbol->dato, sizeof(stAnimal), 1, pf);
        guardarArbol(pf, arbol->der);
    }
}

/// Se recorre el archivo y usando la funcion mostrarUnAnimal() se muestran los datos del archivo
void mostrarAnimales(char archivo[])
{
    stAnimal a;
    FILE* pArchRegistro = fopen(archivo,"rb");
    if(pArchRegistro)
    {
        while(fread(&a, sizeof(stAnimal), 1, pArchRegistro) > 0)
        {
            mostrarUnAnimal(a);
        }
    }
}
