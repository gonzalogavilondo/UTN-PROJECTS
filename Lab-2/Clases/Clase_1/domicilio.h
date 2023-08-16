#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

/// declaramos estructuras y encabezados de las funciones



///Archivos .h: Sirven para los prototipados
///y la declaracion de estructuras para
///que en el resto del programa puedan
///tener la referencia
///Por eso se hace el #include de los .h
typedef struct
{
    int id;
    char calleNombre[25];
    char calleNumero[6];
    char localidad[25];
    char cpos[6];
    char provincia[25];
}stDomicilio;

void muestraDomicilio(stDomicilio d);
stDomicilio getDomicilio();///genera un domicilio x que se usa solo para prueba
void domicilioToString(stDomicilio d,char s[]);///el string lo paso como parametro
char * domicilioToStringConPuntero(stDomicilio d);///el string se "genera" desde la funcion y se devuelve su puntero


#endif // DOMICILIO_H_INCLUDED
