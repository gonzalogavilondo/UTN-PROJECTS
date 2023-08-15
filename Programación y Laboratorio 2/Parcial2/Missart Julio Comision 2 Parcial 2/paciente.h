#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct stPaciente{
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char nombreDoctor[30];
    char diagnostico[100];
    char fechaAtencion[11];
    struct stPaciente * sig;
}stPaciente;

stPaciente * inicLista();
void mostrarListaPacientes(stPaciente* lista);
void muestraNodoPaciente(stPaciente* paciente);

#endif // PACIENTE_H_INCLUDED
