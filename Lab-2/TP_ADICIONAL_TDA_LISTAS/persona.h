#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define ARCHIVO "./archivos/personas.txt"
#define ARCHIVO_R "./archivos/personas_resultado.txt"

typedef struct
{
    char nombre[10];
    int  edad;
}persona;

void muestraPersona(persona);
void cargarPersona(persona **);
persona *arrays2Struct(persona *, int *, char *[], int);
persona *ReservarMemoriaStruct(int);


#endif // PERSONA_H_INCLUDED
