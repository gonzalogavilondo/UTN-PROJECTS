#include "declaraciones.h"

int archivo2ADA(arreglo, dimension)
{
    int validos = 0;
    FILE *buf = fopen("archivoRegistrosVendedor.bin", "rb");

    stRegistroVendedor aux;

    if(buf)
    {
        while(fread(&aux, sizeof(stRegistroVendedor), 1, buf) > 0 && validos < dimension)
        {
            validos = alta(arreglo, validos, aux);
        }
        fclose(buf);
    }
}
