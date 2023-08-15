#include "registroArchivo.h"
#include "especialidad.h"
#include <string.h>
/// Se muestra un dato de tipo stRegistroMedico
void mostrarUnRegistro(stRegistroMedico r){
    printf("\n Id Registro.....................: %d",r.idRegistro);
    printf("\n Id Paciente.....................: %d",r.idPaciente);
    printf("\n Nombre paciente.................: %s",r.nombrePaciente);
    printf("\n Apellido paciente...............: %s",r.apellidoPaciente);
    printf("\n Diagnostico.....................: %s",r.diagnostico);
    printf("\n Fecha de Atencion...............: %s",r.fechaAtencion);
    printf("\n Id Especialidad.................: %d",r.idEspecialidad);
    printf("\n Especialidad medica.............: %s",r.especialidadMedica);
    printf("\n Nombre del medico...............: %s\n",r.nombreDoctor);

    printf("---------------------------------------------------------------------");
}


/// EJERCICIO 8
void especialidad2archivo(stEspecialidadMedica a[], char nombreEspecialidad[], int v) {
    stRegistroMedico aux;
    FILE *pArchivo = fopen(arRegistro, "ab");
    int i=0;
    int flag = 0;

    if(pArchivo) {
        while (i < v && flag == 0) {
            if(strcmp(a[i].especialidadMedica, nombreEspecialidad) == 0) {
                stPaciente* seg = a[i].listaPacientes;
                while(seg){
                    ///aux.idRegistro = buscaUltimoRegistro(arRegistro)+1;
                    aux.idPaciente = seg->idPaciente;
                    strcpy(aux.nombrePaciente, seg->nombrePaciente);
                    strcpy(aux.apellidoPaciente, seg->apellidoPaciente);
                    strcpy(aux.diagnostico, seg->diagnostico);
                    strcpy(aux.fechaAtencion, seg->fechaAtencion);
                    aux.idEspecialidad = a[i].idEspecialidad;
                    strcpy(aux.especialidadMedica, a[i].especialidadMedica);
                    strcpy(aux.nombreDoctor, seg->nombreDoctor);
                    seg=seg->sig;
                }
            }
            i++;
        }
    }

}
