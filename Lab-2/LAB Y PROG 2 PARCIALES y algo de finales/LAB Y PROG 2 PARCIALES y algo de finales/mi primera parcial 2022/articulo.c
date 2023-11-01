#include "articulo.h"

stArticulo cargarUnArticulo(){
    stArticulo a;

    printf("\n Codigo...........................: ");
    scanf("%d",&a.codigo);
    printf("\n Rubro (1 a 4)....................: ");
    scanf("%d",&a.rubro);
    fflush(stdin);
    printf("\n Marca............................: ");
    gets(a.marca);
    fflush(stdin);
    printf("\n Modelo...........................: ");
    gets(a.modelo);
    fflush(stdin);
    printf("\n Precio...........................: ");
    scanf("%f",&a.precio);

    return a;
}

void strRubro(int rubro,char strR[30]){
    switch (rubro){
        case 1:
            strcpy(strR,"Televisores");
            break;
        case 2:
            strcpy(strR,"Lavarropas");
            break;
        case 3:
            strcpy(strR,"Cocinas");
            break;
        case 4:
            strcpy(strR,"Calefactores");
            break;
    }
}

void mostrarUnArticulo(stArticulo a){
    char strR[30];
    strRubro(a.rubro,strR);
    printf("\n Id..............................: %d",a.id);
    printf("\n Codigo..........................: %d",a.codigo);
    printf("\n Rubro...........................: %d - %s",a.rubro, strR);
    printf("\n Marca...........................: %s",a.marca);
    printf("\n Modelo..........................: %s",a.modelo);
    printf("\n Precio..........................: %.2f\n",a.precio);

    printf("______________________________________________________________");
}
