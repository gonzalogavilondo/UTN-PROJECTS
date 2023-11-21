#include "materias.h"
#include "registroArchivo.h"

/**
* Busca posicion
*/

int buscaPosMateria(stCelda adl[], stMateria m, int validos)
{
    int rta = -1;
    int i = 0;
    while((i < validos) && (rta == -1))
    {
        if(strcmp(adl[i].m.materia, m.materia) == 0)
        {
     ///   if(adl[i].m.idMateria == m.idMateria){
            rta = i;
        }
        i++;
    }
    return rta;
}

/**
* Agrega stCelda
*/
int agregar(stCelda adl[], stMateria m, int validos)
{
    adl[validos].m = m;
    adl[validos].listaDeNotas = inicListaSt();
    validos++;

    return validos;
}

/**
* Alta en el adl
*/
int alta (stCelda adl[], stMateria m, stNotaAlumno n, int validos)
{
    nodoSt* aux = crearNodoSt(n);
    int pos = buscaPosMateria(adl, m, validos);
    if(pos == -1)
    {
        validos = agregar(adl, m, validos);
        pos = validos - 1;
    }
    adl[pos].listaDeNotas = agregarAlFinalSt(adl[pos].listaDeNotas, aux);

    return validos;
}

/**
* Lee el archivo y carga el arreglo de listas
*/
int archivo2adl(stCelda adl[], int validos, int dim)
{
    FILE* archivo = fopen(arRegistro, "rb");
    if(archivo)
    {
        stRegistroArchivo rg;
        stMateria m;
        stNotaAlumno n;
        while( (fread(&rg, sizeof(stRegistroArchivo), 1, archivo) > 0) && (validos < dim) )
        {
            m.idMateria = rg.idMateria;
            strcpy(m.materia, rg.materia);
            n.legajo = rg.legajo;
            strcpy(n.apeNom, rg.apeNom);
            n.nota = rg.nota;
            validos = alta(adl, m, n, validos);
        }
        fclose(archivo);
    }
    return validos;
}

/**
* Muestra el arreglo de listas
*/
void mostrarADL(stCelda adl[], int validos)
{
    printf("\nMostrando el arreglo de listas: \n");
    int cnt = 0;
    while(cnt < validos)
    {
        printf("\n\nMateria %d: %s",adl[cnt].m.idMateria, adl[cnt].m.materia);
        printf("\nListado de alumnos: %d\n",cuentaAlumnos(adl[cnt].listaDeNotas));
        replicante('-', 50);
        recorrerYmostrar(adl[cnt].listaDeNotas);
        cnt++;
    }
}

/**
* Recorre el arreglo de listas y guarda los aprobado en el archivo de aprobados
* y los desaprobados en el de desaprobados
*/
void guardarAprobDesaprob(stCelda adl[], int validos)
{
    stRegistroArchivo r;
    for(int i = 0; i < validos; i++)
    {
        r.idMateria = adl[i].m.idMateria;
        strcpy(r.materia,adl[i].m.materia);

        nodoSt *seg = adl[i].listaDeNotas;

        while(seg)
        {
            r.legajo = seg->dato.legajo;
            r.nota = seg->dato.nota;
            strcpy(r.apeNom,seg->dato.apeNom);

            if(seg->dato.nota >= 6)
            {
                guardaRegistroArchivo(arRegAprob, r);
            }
            else
            {
                guardaRegistroArchivo(arRegDesAp, r);
            }
            seg = seg->siguiente;
        }
    }
}
