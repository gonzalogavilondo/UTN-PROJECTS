#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h" ///incluyo librerias necesarias y en especial, la que contiene los encabezados de las fciones

/// implementamos codificacion de las funciones declaradas en el .h

void muestraDomicilio(stDomicilio d)
{
    printf("\n Id: %d",d.id);
    printf("\n Calle: %s",d.calleNombre);
    printf("\n Nro: %s",d.calleNumero);
    printf("\n Localidad: %s",d.localidad);
    printf("\n Codigo Postal: %s",d.cpos);
    printf("\n Provincia: %s",d.provincia);
    printf("\n -------------------------------\n");
}

stDomicilio getDomicilio()
{
    stDomicilio d;
    static int id = 0;
    id++;
    d.id = id;
    strcpy(d.calleNombre,"Constitucion");
    strcpy(d.calleNumero,"1100");
    strcpy(d.localidad,"Mar del Plata");
    strcpy(d.cpos,"7600");
    strcpy(d.provincia,"Bs As");

    return(d);
}

void domicilioToString(stDomicilio d,char s[])
{
    ///notar que la fcion NO devuelve un string con printf, sino que lo guarda en una var (s en este caso)
    s = sprintf(s,"Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Pcia: %s",d.calleNombre,d.calleNumero,d.localidad,d.cpos,d.provincia);
}

char * domicilioToStringConPuntero(stDomicilio d) ///no necesito recibir un string p/retornar(cocatenado), recibo solo el dom.
{
    char *s = (char *)malloc(sizeof(char)*200); ///creo un puntero llamado "s" (string) y le reservo espacio de memoria
    ///todo el string que se armo, se guarda en el espacio de memoria(no variable) "s"
    sprintf(s,"Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Pcia: %s",d.calleNombre,d.calleNumero,d.localidad,d.cpos,d.provincia);
    return s;///se retorna la dir de memoria (el puntero)
}

