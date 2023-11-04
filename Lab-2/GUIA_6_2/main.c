#include "especie.h"

int main()
{
    srand(time(NULL));

    stCeldaEspecie ada[4];
    int validos=0;
    int dim = 4;
    //generaArchivoRandom(40);
    mostrarRegistros(arRegistro);
    printf("\nPasando de archivo a ADA\n");
    validos  = archivo2ada(ada,validos,dim);
    mostrarADA(ada, validos);
    guardarEspecies(ada, validos);

    printf("\n <<< Archivo de Mamiferos >>> \n");
    mostrarAnimales("Mamifero.dat");

    printf("\n <<< Archivo de Aves >>> \n");
    mostrarAnimales("Ave.dat");

    printf("\n <<< Archivo de Reptiles >>> \n");
    mostrarAnimales("Reptil.dat");

    printf("\n <<< Archivo de Peces >>> \n");
    mostrarAnimales("Pez.dat");

    return 0;
}
