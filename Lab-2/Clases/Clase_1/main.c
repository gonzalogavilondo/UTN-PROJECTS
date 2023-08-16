#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h" ///incluyo la libreria definida por nosotros


int main()
{
    stDomicilio domicilio;
    char s[100];
    char *string2=(char *)malloc(200);///creo puntero para que reciba la dir de mem que retorna domicilioToStringConPuntero
    ///realloc(string2,300);///redimensiona el espacio de memoria
    domicilio = getDomicilio(); ///genero un reg de prueba, de tipo stdomicilio
    muestraDomicilio(domicilio);///muestro con id=1 (para verificar static id)

    domicilio = getDomicilio();///genero un reg de prueba, de tipo stdomicilio
    muestraDomicilio(domicilio);///muestro con id=2 (para verificar static id)

    domicilio = getDomicilio();///genero un reg de prueba, de tipo stdomicilio
    domicilioToString(domicilio,s);///notar que la fcion NO devuelve un string p/pantalla, sino que lo carga en una var (s)
    printf("DOMICILIO: %s\n",s); ///muestro domicilio como 1 solo string

    string2 = domicilioToStringConPuntero(domicilio);///guardo dir de mem con el string creado en domicilioToStringConPuntero
    printf("DOMICILIO 2: %s\n",string2); ///muestro domicilio2 a traves de un puntero

    free(string2); ///libero puntero
    printf("DOMICILIO 2: %s\n",string2); ///muestro domicilio2 vacio (c/basura) ya que acabo de liberar el puntero

    return 0;
}

