#include "declaraciones.h"

int main()
{
    int *vec    = NULL,
        *vecBin = NULL,
        *vecTxt = NULL;

    int cntElementos = 0,
        sizeBin      = 0,
        sizeTxt      = 0;

    ///Reservo memoria primero para un vector de dimension maxima
    vec = ReservarMemoria(MAXDIM);

    ///Cargo el vector de manera dinamica y devuelvo la cantidad de elementos
    cntElementos = CargarVector(vec);
    printf("\nVECTOR ORIGINAL\n\n");
    MostrarVector(vec, cntElementos);

    ///Guardo el vector en un archivo binario y txt
    Vector2ArchivoBin(vec, cntElementos, "vector.dat");
    Vector2ArchivoTxt(vec, cntElementos, "vector.txt");

    ///Levanto el archivo binario al vector
    sizeBin = ArchivoBin2Vector(&vecBin, "vector.dat");
    sizeTxt = ArchivoTxt2Vector(&vecTxt, "vector.txt");

    ///Mostramos los vectores
    printf("\nVECTOR BIN\n\n");
    MostrarVector(vecBin, sizeBin);

    printf("\nVECTOR TXT\n\n");
    MostrarVector(vecTxt, sizeTxt);

    ///Liberamos memoria:
    free(vec);
    free(vecBin);
    free(vecTxt);

    return 0;
}
