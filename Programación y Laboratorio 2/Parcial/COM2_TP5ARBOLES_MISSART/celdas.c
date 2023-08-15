typedef struct {
    stEspecialidad especialidad;
    nodoLista* listaPacientes;
} stCelda;

int agregarEspecialidad(stCelda a[],int validos,stEspecialidad especialidad)   ///PUNTO 2 – Realizar una función que agregue una nueva especialidad médica.
{
    ADL[validos].especialidad = especialidad;
    ADL[validos].listaPacientes = inicLista();
    validos++;
    return validos;
}

int buscarPosEspecialidad(stCelda a[], int validos, stEspecialidad especialidad){
    int rta = -1;
    int i = 0;
    while( i < validos && rta == -1)
    {
        if(strcmp(ADL[i].especialidad.especialidadMedica, especialidad.especialidadMedica) == 0)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}


int agregartodo(stCelda a[], int v, stEspecialidad especialidad)
{
 nodo *aux = crearnodo(especialidad);

 int i = buscarPosEspecialidad(a, v, especialidad);
 if (i == -1)
    {
    stCelda celda;
    celda.listaPacientes    =inicLista();
    v = agregarEspecialidad(a, v, especialidad)
    i = cant – 1;
    }
 a[i].lista = agregarppio(a[i].lista, aux);
 return cant;
}