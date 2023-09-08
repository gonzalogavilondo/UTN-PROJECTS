#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define ARCHIVO "./archivos/personas.txt"
#define ARCHIVO_R "./archivos/personas_resultado.txt"

typedef struct
{
    char nombre[20];
    int  edad;
}persona;

void muestraPersona(persona);
void cargarPersona(persona **);



#endif // PERSONA_H_INCLUDED
