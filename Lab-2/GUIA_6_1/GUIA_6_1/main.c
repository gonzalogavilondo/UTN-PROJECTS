#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "materias.h"


int main()
{
    //stCelda* adl = (stCelda*) malloc(sizeof(stCelda)*cuentaRegistros(arRegistro,sizeof(stRegistroArchivo)));
    stCelda adl[20];
    int validos = 0;
    int dim = 20;
   // generaArchivoRandom(100);
   // mostrarRegistros(arRegistro);
    printf("\nPasando de archivo a ADL\n");
    validos  = archivo2adl(adl, validos, dim);
    mostrarADL(adl, validos);
    guardarAprobDesaprob(adl,validos);
    printf("\n <<< Archivo de Aprobados >>> \n");
    printf("\n Total: %d \n", cuentaRegistros(arRegAprob, sizeof(stRegistroArchivo)));
    mostrarRegistros(arRegAprob);
    printf("\n <<< Archivo de Desaprobados >>> \n");
    printf("\n Total: %d \n", cuentaRegistros(arRegDesAp, sizeof(stRegistroArchivo)));
    mostrarRegistros(arRegDesAp);

    return 0;
}
