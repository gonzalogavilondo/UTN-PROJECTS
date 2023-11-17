#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define DIM 1000
#define ESC 27


/** STRUCTURES  */


typedef struct
{
    int  id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    unsigned long movil;
    int baja; /// 0 si está activo - 1 si está eliminado

} stCliente;

typedef struct
{
    int id;  /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumo;

/** ***************************************************         */


/** UTILITIES PROTOTYPE*/
int validaEmail(char email[]);
int buscaUltimoId();
int buscaPosicion(int id);
int existeCliente(int dni);
int arch2Arr(stCliente clientesArr[], int dimension);
void ordenarArrDni(stCliente clientes[], int validos);
void ordenarArrApellido(stCliente clientes[], int validos);
void mostrarArr(stCliente clientesArr[],int validos);
void buscarClienteEspecif();
int randomRango(int min, int max);

/** Sin organizar*/
stCliente buscaCliente(int dni);
int cuentaClientes();
int randomId(int cantClientes);
stCliente randomCliente(int cantClientes);
void crearMilConsumosArchivo();
void muestraConsumo(stConsumo consumo);
void mostrarConsumosArch();
void mostrarTodosConsumos();
void mostrarConsumosCliente();
int arch2ArrConsumo(stConsumo consumoArr[]);
void ordenarArrConsumosCliente(stConsumo consumoArr[], int validos);
void ordenarArrConsumosFecha(stConsumo consumoArr[], int validos);
void mostrarArrConsumo(stConsumo consumoArr[],int validos);
void listarConsumos();
void estadisticaConsumos();
int buscaConsumoID(int id);
void darDeBajaConsumo();
void modifBajaConsumo(stConsumo consumoBuscado);
stConsumo getConsumo(int id);
int buscaPosicionConsumo(int id);
void ordenarArrEmail();
int arch2ArrInactivos(stCliente clientesArr[], int dimension);
void modifConsumo(stConsumo consumo);
void modificarConsumo();
void acumConsumo(stConsumo consumo);
int verificaConsumo(stConsumo consumo);
void mostrarConsumoEspecifico();
/** *********** **/

/** MENUS **/
void muestraMenu();
void muestraMenuCliente();
void menuModificar();
void muestraMenuConsumo();
void menuMostrar();

/** ********* **/



/** MODIFICADORES **/
void modifMovil();
void modifApellido();
void darDeBaja();
void modifDNI();
void modifDomicilio();
void modifEmail();
void modifNombre();
/** MODIF UTILITIES **/
void modifBaja(stCliente cliente);
void cambiaApellido(stCliente cliente);
void cambiaMovil(stCliente cliente);
void cambiaDNI(stCliente cliente);
void cambiaDomicilio(stCliente cliente);
void cambiaEmail(stCliente cliente);
void cambiaNombre(stCliente cliente);
/** ************ **/


/** *********** **/


/** CLIENT FUNCTIONS PROTOTYPE */
stCliente cargarUnCliente();
void cargarClienteArchivo();
void guardarCliente(stCliente cliente);
void mostrarCliente(stCliente cliente);
void mostrarClientesArch();


/** ************* */


/** MAIN */
int main()
{
    char option;
    do
    {
        system("cls");
        muestraMenu();
        printf("\n\nIngrese una opcion. ESC para salir: ");
        option = getch();

        switch(option)
        {
        case 49:
            muestraMenuCliente();
            break;
        case 50:
            muestraMenuConsumo();
            break;
        case 51:
            estadisticaConsumos();
            break;

        }

        system("pause");


    }
    while(option != ESC);

    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nXX                                                                          XX");
    printf("\nXX   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMMMMMMMMssssssssssssssssssssssssssMMMMMMMMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMMMss'''                          '''ssMMMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMyy''                                    ''yyMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMyy''                                            ''yyMMMMMMMM   XX");
    printf("\nXX   MMMMMy''                                                    ''yMMMMM   XX");
    printf("\nXX   MMMy'                                                          'yMMM   XX");
    printf("\nXX   Mh'                                                              'hM   XX");
    printf("\nXX   -                                                                  -   XX");
    printf("\nXX                                                                          XX");
    printf("\nXX   ::                                                                ::   XX");
    printf("\nXX   MMhh.        ..hhhhhh..                      ..hhhhhh..        .hhMM   XX");
    printf("\nXX   MMMMMh   ..hhMMMMMMMMMMhh.                .hhMMMMMMMMMMhh..   hMMMMM   XX");
    printf("\nXX   ---MMM .hMMMMdd:::dMMMMMMMhh..        ..hhMMMMMMMd:::ddMMMMh. MMM---   XX");
    printf("\nXX   MMMMMM MMmm''      'mmMMMMMMMMyy.  .yyMMMMMMMMmm'      ''mmMM MMMMMM   XX");
    printf("\nXX   ---mMM ''             'mmMMMMMMMM  MMMMMMMMmm'             '' MMm---   XX");
    printf("\nXX   yyyym'    .              'mMMMMm'  'mMMMMm'              .    'myyyy   XX");
    printf("\nXX   mm''    .y'     ..yyyyy..  ''''      ''''  ..yyyyy..     'y.    ''mm   XX");
    printf("\nXX           MN    .sMMMMMMMMMss.   .    .   .ssMMMMMMMMMs.    NM           XX");
    printf("\nXX           N`    MMMMMMMMMMMMMN   M    M   NMMMMMMMMMMMMM    `N           XX");
    printf("\nXX            +  .sMNNNNNMMMMMN+   `N    N`   +NMMMMMNNNNNMs.  +            XX");
    printf("\nXX              o+++     ++++Mo    M      M    oM++++     +++o              XX");
    printf("\nXX                                oo      oo                                XX");
    printf("\nXX           oM                 oo          oo                 Mo           XX");
    printf("\nXX         oMMo                M              M                oMMo         XX");
    printf("\nXX       +MMMM                 s              s                 MMMM+       XX");
    printf("\nXX      +MMMMM+            +++NNNN+        +NNNN+++            +MMMMM+      XX");
    printf("\nXX     +MMMMMMM+       ++NNMMMMMMMMN+    +NMMMMMMMMNN++       +MMMMMMM+     XX");
    printf("\nXX     MMMMMMMMMNN+++NNMMMMMMMMMMMMMMNNNNMMMMMMMMMMMMMMNN+++NNMMMMMMMMM     XX");
    printf("\nXX     yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy     XX");
    printf("\nXX   m  yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy  m   XX");
    printf("\nXX   MMm yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy mMM   XX");
    printf("\nXX   MMMm .yyMMMMMMMMMMMMMMMM     MMMMMMMMMM     MMMMMMMMMMMMMMMMyy. mMMM   XX");
    printf("\nXX   MMMMd   ''''hhhhh       odddo          obbbo        hhhh''''   dMMMM   XX");
    printf("\nXX   MMMMMd             'hMMMMMMMMMMddddddMMMMMMMMMMh'             dMMMMM   XX");
    printf("\nXX   MMMMMMd              'hMMMMMMMMMMMMMMMMMMMMMMh'              dMMMMMM   XX");
    printf("\nXX   MMMMMMM-               ''ddMMMMMMMMMMMMMMdd''               -MMMMMMM   XX");
    printf("\nXX   MMMMMMMM                   '::dddddddd::'                   MMMMMMMM   XX");
    printf("\nXX   MMMMMMMM-                                                  -MMMMMMMM   XX");
    printf("\nXX   MMMMMMMMM                                                  MMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMy                                                yMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMy.                                            .yMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMy.                                        .yMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMy.                                    .yMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMMMs.                                .sMMMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMMMMMss.           ....           .ssMMMMMMMMMMMMMMMMMM   XX");
    printf("\nXX   MMMMMMMMMMMMMMMMMMMMNo         oNNNNo         oNMMMMMMMMMMMMMMMMMMMM   XX");
    printf("\nXX                                                                          XX");
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\n                                                                              ");
    printf("\n    .o88o.                               o8o                .                 ");
    printf("\n    888 `'                               `'              .o8                 ");
    printf("\n   o888oo   .oooo.o  .ooooo.   .ooooo.  oooo   .ooooo.  .o888oo oooo    ooo   ");
    printf("\n    888    d88(  '8 d88' `88b d88' `'Y8 `888  d88' `88b   888    `88.  .8'    ");
    printf("\n    888    `'Y88b.  888   888 888        888  888ooo888   888     `88..8'     ");
    printf("\n    888    o.  )88b 888   888 888   .o8  888  888    .o   888 .    `888'      ");
    printf("\n   o888o   8''888P' `Y8bod8P' `Y8bod8P' o888o `Y8bod8P'   '888'      d8'      ");
    printf("\n                                                                .o...P'       ");

    return 0;
}


/** ***************** */


/** UTILITIES         */

/*********************************************************************//**
*
* \brief Muestra el menu principal.
*
*
*
**************************************************************************/

void muestraMenu()
{
    printf("\n1) Menu cliente.");
    printf("\n2) Menu consumo.");
    printf("\n\n");

}

void muestraMenuCliente()
{
    char option;
    do
    {
        system("cls");
        printf("\n1)Dar de alta un cliente.");
        printf("\n2)Dar de baja un cliente.");
        printf("\n3)Modificar un cliente.");
        printf("\n4)Mostrar clientes.");
        printf("\n5)Mostrar clientes inactivos ordenados por email.");

        printf("\nIngrese una opcion. ESC para salir.            : ");
        option = getch();

        switch(option)
        {
        case 49:
            cargarClienteArchivo();
            break;
        case 50:
            darDeBaja();
            break;
        case 51:
            menuModificar();
            break;
        case 52:
            menuMostrar();
            break;
        case 53:
            ordenarArrEmail();
            system("pause");
            break;
        }
    }
    while(option!=ESC);


}

/*********************************************************************//**
*
* \brief Muestra el menu para modificar un cliente.
*
*
*
**************************************************************************/

void menuModificar()
{
    char option;
    do
    {
        system("cls");
        printf("\n1)Modificar nombre.");
        printf("\n2)Modificar apellido.");
        printf("\n3)Modificar DNI.");
        printf("\n4)Modificar email.");
        printf("\n5)Modificar domicilio.");
        printf("\n6)Modificar movil.");

        printf("\nIngrese una opcion. ESC para salir.            : ");
        option = getch();

        switch(option)
        {
        case 49:
            modifNombre();
            break;
        case 50:
            modifApellido();
            break;
        case 51:
            modifDNI();
            break;
        case 52:
            modifEmail();
            break;
        case 53:
            modifDomicilio();
            break;
        case 54:
            modifMovil();
            break;
        }
    system("pause");
    }
    while(option!=ESC);
}

/*********************************************************************//**
*
* \brief Muestra el menu que se utiliza para mostrar los datos cargados dependiendo de su ordenamiento..
*
*
*
**************************************************************************/

void menuMostrar()
{
    char option;
    int validos;

    stCliente clientesArr[DIM];

    validos = arch2Arr(clientesArr,DIM);

    do
    {
        system("cls");
        printf("\n1)Mostrar clientes ordenados por DNI.");
        printf("\n2)Mostrar clientes ordenados por apellido.");
        printf("\n3)Mostrar un cliente especifico.");
        option = getch();
        switch(option)
        {
        case 49:
            ordenarArrDni(clientesArr,validos);
            mostrarArr(clientesArr,validos);
            break;
        case 50:
            ordenarArrApellido(clientesArr,validos);
            mostrarArr(clientesArr,validos);
            break;
        case 51:
            buscarClienteEspecif();
            break;
        }
        printf("\n");
    system("pause");
    }
    while(option != ESC);
}

/*********************************************************************//**
*
* \brief Muestra el menu de consumos.
*
*
*
**************************************************************************/

void muestraMenuConsumo()
{

    char option;

    do
    {
        system("cls");
        printf("\n1 - Cargar 1000 consumos al azar.");
        printf("\n2 - Mostrar consumos de cliente especifico.");
        printf("\n3 - Mostrar todos los consumos.");
        printf("\n4 - Mostrar un consumo especifico.");
        printf("\n5 - Dar de baja un consumo.");
        printf("\n6 - Modificar Consumo.");
        printf("\n7 - Listar Consumos.");
        printf("\n8 - Estadisticas de Consumos");
        option = getch();
        switch(option)
        {
        case 49:
            crearMilConsumosArchivo();
            break;
        case 50:
            mostrarConsumosCliente();
            break;
        case 51:
            mostrarTodosConsumos();
            break;
        case 52:
            mostrarConsumoEspecifico();
            break;
        case 53:
            darDeBajaConsumo();
            break;
        case 54:
            modificarConsumo();;
            break;
        case 55:
            listarConsumos();
            break;
        case 56:
            estadisticaConsumos();
            break;
        }
        system("pause");
    }
    while(option!=ESC);
}

/*********************************************************************//**
*
* \brief Valida la direccion de email
* \param Recibe un arreglo de tipo char
*
*
**************************************************************************/
int validaEmail(char email[])
{
    int valid=strlen(email);
    int i=0;
    int flag=0;
    while(i<valid && flag == 0)
    {
        if(email[i]==64)
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

/*********************************************************************//**
*
* \brief Busca el ultimo id de clientes para realizar el autoincremental.
* \return Ultimo id cargado.
*
*
**************************************************************************/

int buscaUltimoId()
{
    stCliente cliente;
    int id = 0;
    FILE *pArchCliente=fopen("clientes.dat", "rb");
    if(pArchCliente)
    {
        fseek(pArchCliente, sizeof(stCliente)*-1,SEEK_END);
        if(fread(&cliente,sizeof(stCliente),1,pArchCliente) > 0)
        {
            id=cliente.id;
        }
        fclose(pArchCliente);
    }
    return id;
}

/*********************************************************************//**
*
* \brief Busca el ultimo id de consumos para realizar el autoincremental.
* \return Ultimo id cargado.
*
*
**************************************************************************/

int buscaUltimoIdConsumo()
{
    stConsumo consumo;
    int id=-1;
    FILE *pArchConsumo=fopen("consumos.dat", "rb");
    if(pArchConsumo)
    {
        fseek(pArchConsumo, sizeof(stConsumo)*-1,SEEK_END);
        if(fread(&consumo,sizeof(stConsumo),1,pArchConsumo) > 0)
        {
            id=consumo.id;
        }
        fclose(pArchConsumo);
    }
    return id;
}



/** ARCH TO ARRAY FUNCTION **/
/*********************************************************************//**
*
* \brief Pasa los datos del archivo clientes a un array.
* \return int clientesArray[]
*
*
**************************************************************************/

int arch2Arr(stCliente clientesArr[], int dimension)
{
    stCliente cliente;
    FILE *pArchClientes;
    int i=0;

    pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes)
    {
        while(fread(&cliente,sizeof(stCliente),1,pArchClientes) > 0)
        {
            if(cliente.baja == 0)
            {
                clientesArr[i] = cliente;
                i++;
            }
        }
    }

    return i;
}
/** ********************  **/

/**  ORDENAMIENTOS       **/
/*********************************************************************//**
*
* \brief Ordena los clientes con el metodo de selección los clientes por el dni.
*
*
*
**************************************************************************/

void ordenarArrDni(stCliente clientes[], int validos)
{
    stCliente aux;
    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(clientes[i].dni > clientes[j].dni)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}

/*********************************************************************//**
*
* \brief Ordena los clientes con el metodo de selección los clientes por el apellido.
*
*
*
**************************************************************************/

void ordenarArrApellido(stCliente clientes[], int validos)
{
    stCliente aux;
    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {

            if(strcmpi(clientes[i].apellido, clientes[j].apellido)== 1)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}

/*********************************************************************//**
*
* \brief Busca un cliente especifico para luego mostrarlo.
*
*
*
**************************************************************************/

void buscarClienteEspecif()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    mostrarCliente(clienteBuscado);

}

/** ******************** **/

/** MOSTRAR ARRAY DE CLIENTES **/

/*********************************************************************//**
*
* \brief Muestra el array de clientes.
*
*
*
**************************************************************************/

void mostrarArr(stCliente clientesArr[],int validos)
{
    for(int i = 0; i<validos; i++)
    {
        mostrarCliente(clientesArr[i]);
    }
}
/** ******************* **/

/** **************    */


/** CLIENT FUNCTIONS  */
/*********************************************************************//**
*
* \brief Carga un cliente de manera local.
* \return stCliente cliente[]
*
*
**************************************************************************/

stCliente cargarUnCliente()
{
    stCliente cliente;
    do
    {
        printf("\n Ingrese numero de cliente: ");
        fflush(stdin);
        scanf("%d",&cliente.nroCliente);
    }
    while(cliente.nroCliente < 0 || cliente.nroCliente > 9999999);
    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(cliente.nombre);
    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(cliente.apellido);
    printf(" Ingrese el DNI.....................: ");
    scanf(" %d", &cliente.dni);
    do
    {
        printf(" Ingrese el EMail...................: ");
        fflush(stdin);
        gets(cliente.email);
    }
    while(!validaEmail(cliente.email));
    printf(" Ingrese el Domicilio...................: ");
    fflush(stdin);
    gets(cliente.domicilio);
    printf(" Ingrese el Numero de celular...........: ");
    scanf(" %lu", &cliente.movil);
    cliente.baja=0;



    return cliente;
}
/*********************************************************************//**
*
* \brief Verifica que el numero de cliente no exista dentro del archivo.
* \param Recibe un numero de cliente como numero entero.
*
*
**************************************************************************/
int verificaNroCliente(int nro) {
    stCliente cliente;
    int flag = 0;
    FILE *pArchClientes = fopen("clientes.dat", "rb");

    if(pArchClientes) {
        while(flag == 0 && fread(&cliente, sizeof(stCliente), 1, pArchClientes) > 0) {
            if(cliente.nroCliente == nro) {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }
    return flag;
}

/*********************************************************************//**
*
* \brief Ciclo de carga de clientes.
*
*
*
**************************************************************************/

void cargarClienteArchivo()
{
    char opcion='s';
    stCliente cliente;
    int existe;
    int existeNro;
    while(opcion =='s')
    {
        system("cls");
        printf(" ~ ~ ~ CARGA DE CLIENTES ~ ~ ~");
        cliente = cargarUnCliente();
        existe = existeCliente(cliente.dni);
        existeNro = verificaNroCliente(cliente.nroCliente);
        if(existe == 0 && existeNro == 0)
        {
            cliente.id = buscaUltimoId()+1;
            guardarCliente(cliente);
        }
        else
        {
            printf("\nEl cliente no se cargo porque ya existe en nuestro sistema.");
        }

        printf("\nDesea ingresar otro cliente? (s/n) : ");
        scanf("%s",&opcion);

    };


}

/*********************************************************************//**
*
* \brief Carga los clientes al archivo clientes.dat
* \param stCliente cliente
*
*
**************************************************************************/
void guardarCliente(stCliente cliente)
{

    FILE *pArchCliente=fopen("clientes.dat", "ab");
    if(pArchCliente)
    {
        fwrite(&cliente,sizeof(stCliente),1,pArchCliente);
        fclose(pArchCliente);
    }
}

/*********************************************************************//**
*
* \brief Muestra todos los clientes cargados en archivo clientes.dat
*
*
*
**************************************************************************/

void mostrarClientesArch()
{
    stCliente cliente;
    FILE *pArchCliente=fopen("clientes.dat","rb");
    if(pArchCliente)
    {
        while(fread(&cliente,sizeof(stCliente),1,pArchCliente)>0)
        {
            mostrarCliente(cliente);
        }
        fclose(pArchCliente);
    }

}

/*********************************************************************//**
*
* \brief Muestra un cliente.
*
*
*
**************************************************************************/

void mostrarCliente(stCliente cliente)
{

    puts("\n------------------------------------------");
    printf("\nID Cliente: %d", cliente.id);
    printf("\nNro Cliente: %d",cliente.nroCliente);
    printf("\nNombre: %s",cliente.nombre);
    printf("\nApellido: %s",cliente.apellido);
    printf("\nDNI: %d",cliente.dni);
    printf("\nEmail: %s",cliente.email);
    printf("\nDomicilio: %s",cliente.domicilio);
    printf("\nMovil: %lu",cliente.movil);
    printf("\nBaja: %d",cliente.baja);
    puts("\n------------------------------------------");
}

/*********************************************************************//**
*
* \brief Verifica si existe un cliente.
* \param int dni
* \return int flag, 1 = existe , 0 no existe.
*
**************************************************************************/



int existeCliente(int dni)
{
    stCliente cliente;
    FILE *pArchiCliente;
    pArchiCliente = fopen("clientes.dat","rb");
    int flag = 0;
    if(pArchiCliente)
    {
        while(fread(&cliente,sizeof(stCliente),1,pArchiCliente))
        {
            if(cliente.dni == dni)
            {

                flag = 1;
            }
        }
        fclose(pArchiCliente);
    }
    return flag;
}

/*********************************************************************//**
*
* \brief Modififca la baja de un cliente.
* \param stCliente cliente
*
*
**************************************************************************/


void modifBaja(stCliente cliente)
{

    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        cliente.baja=1;
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief Busca la posición de un cliente específico.
* \param int id
* \return int pos, retorna la posición del mismo.
*
**************************************************************************/


int buscaPosicion(int id)
{
    stCliente cliente;
    int pos=0;
    int flag = 0;
    FILE *pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes)
    {
        while(flag==0 && fread(&cliente,sizeof(stCliente),1,pArchClientes)>0)
        {
            pos = pos +1;
            if(cliente.id == id)
            {
                flag=1;
            }
        }
    }
    pos = pos-1;
    return pos;
}

/*********************************************************************//**
*
* \brief Buscador de cliente
* \param int dni
* \return stCliente cliente
*
**************************************************************************/

stCliente buscaCliente(int dni)
{
    stCliente cliente;
    int flag =0;
    FILE *pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes)
    {
        while(flag==0 && fread(&cliente,sizeof(stCliente),1,pArchClientes)> 0)
        {
            if(cliente.dni == dni)
            {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }


    return cliente;
}

/*********************************************************************//**
*
* \brief Función que verifica si existe el cliente que se desea dar de baja, luego, lo modifica.
*
*
*
**************************************************************************/

void darDeBaja()
{
    stCliente clienteBuscado;
    int existe;
    int dni;
    printf("\n\nIngrese su dni:  ");
    scanf("%d",&dni);

    existe = existeCliente(dni);

    if(existe == 1){

    clienteBuscado = buscaCliente(dni);
    modifBaja(clienteBuscado);
}

}

/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia nombre.
*
*
*
**************************************************************************/

void modifNombre()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaNombre(clienteBuscado);
}

/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar
* \param stCliente cliente
*
*
**************************************************************************/

void cambiaNombre(stCliente cliente)
{

    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo nombre: ");
        fflush(stdin);
        gets(cliente.nombre);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia apellido.
*
*
*
**************************************************************************/

void modifApellido()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaApellido(clienteBuscado);
}

/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar el apellido
* \param stCliente cliente
*
*
**************************************************************************/

void cambiaApellido(stCliente cliente)
{
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo apellido: ");
        fflush(stdin);
        gets(cliente.apellido);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }

}

/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia dni.
*
*
*
**************************************************************************/

void modifDNI()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaDNI(clienteBuscado);
}

/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar el apellido
* \param stCliente cliente
*
*
**************************************************************************/

void cambiaDNI(stCliente cliente)
{
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo DNI: ");
        fflush(stdin);
        scanf(" %d", &cliente.dni);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia email.
*
*
*
**************************************************************************/
void modifEmail()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaEmail(clienteBuscado);
}

/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar el email
* \param stCliente cliente
*
*
**************************************************************************/

void cambiaEmail(stCliente cliente)
{
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Email: ");
        fflush(stdin);
        gets(cliente.email);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}


/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia domicilio.
*
*
*
**************************************************************************/
void modifDomicilio()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaDomicilio(clienteBuscado);
}

/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar el domicilio
* \param stCliente cliente
*
*
**************************************************************************/
void cambiaDomicilio(stCliente cliente)
{
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Domicilio: ");
        fflush(stdin);
        gets(cliente.domicilio);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}


/*********************************************************************//**
*
* \brief Busca un cliente, y si existe, llama a la funcion cambia movil.
*
*
*
**************************************************************************/
void modifMovil()
{
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaMovil(clienteBuscado);
}


/*********************************************************************//**
*
* \brief Recibe un cliente al que se debe modificar el movil
* \param stCliente cliente
*
*
**************************************************************************/
void cambiaMovil(stCliente cliente)
{
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Movil: ");
        fflush(stdin);
        scanf("%lu",&cliente.movil);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);
        fclose(pArchClientes);
    }
}


/*********************************************************************//**
*
* \brief Cuenta la cantidad de clientes cargados.
* \return int cantClientes.
*
*
**************************************************************************/
int cuentaClientes()   /// Devuelve la cantidad de clientes cargados.
{
    stCliente cliente;
    int cantClientes = 0;
    FILE *pArchClientes = fopen("clientes.dat", "rb");
    if(pArchClientes)
    {
        while(fread(&cliente,sizeof(stCliente),1,pArchClientes)>0)
        {
            cantClientes = cantClientes + 1;
        }
        fclose(pArchClientes);
    }
    return cantClientes;
}


/*********************************************************************//**
*
* \brief Devuelve una ID random de cliente. (De 0 a cantClientes).
* \param int cantClientes
* \return int cliente (id)
*
**************************************************************************/
int randomId(int cantClientes)
{

    int cliente = rand() % cantClientes;
    return cliente;
}


/*********************************************************************//**
*
* \brief Devuelve un cliente en base a la funcion randomId.
* \param int cantClientes
* \return stCliente cliente
*
**************************************************************************/
stCliente randomCliente(int cantClientes)
{

    stCliente cliente;
    int id = randomId(cantClientes);
    int flag = 0;

    FILE *pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes)
    {
        while(flag == 0 && fread(&cliente,sizeof(stCliente),1,pArchClientes)> 0)
        {
            if(id == cliente.id)
            {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }
    return cliente;
}




/*********************************************************************//**
*
* \brief Genera consumo en un cliente.
* \param stCliente cliente
* \return stConsumo consumo
*
**************************************************************************/
stConsumo generaConsumo(stCliente cliente)
{

    stConsumo consumo;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentAnio;
    int currentDia;
    int currentMes;

    currentAnio = tm.tm_year + 1900;
    currentDia = tm.tm_mday;
    currentMes = tm.tm_mon +1;

    consumo.idCliente = cliente.nroCliente;
    consumo.anio = randomRango( 1995,  currentAnio+1);
    if(consumo.anio == currentAnio)
    {
        consumo.mes = randomRango(1,currentMes);
    }
    else
    {
        consumo.mes = randomRango(1,13);
    }

    if(consumo.mes == 2)
    {
        if(consumo.anio == currentAnio)
        {
            consumo.dia = randomRango(1,currentDia);
        }
        else
        {
            consumo.dia = randomRango(1,28);
        }
    }
    else if(consumo.mes == 4 || consumo.mes == 6 || consumo.mes == 9 || consumo.mes==11)
    {
        if(consumo.anio == currentAnio)
        {
            consumo.dia = randomRango(1,currentDia);
        }
        else
        {
            consumo.dia = randomRango(1,30);
        }
    }
    else
    {
        if(consumo.anio == currentAnio)
        {
            consumo.dia = randomRango(1,currentDia);
        }
        else
        {
            consumo.dia = randomRango(1,31);
        }
    }

    consumo.datosConsumidos = rand()%250;
    consumo.baja = 0;

    return consumo;
}

int verificaConsumo(stConsumo consumo) {
    stConsumo aux;
    FILE *pArchConsumo = fopen("consumos.dat", "rb");
    int flag = 0;

    if (pArchConsumo) {
        while(flag == 0 && fread(&aux, sizeof(stConsumo), 1, pArchConsumo) > 0) {
            if (aux.anio == consumo.anio && aux.mes == consumo.mes && aux.dia == consumo.dia && aux.idCliente == consumo.idCliente) {
                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }
   return flag;
}

void acumConsumo(stConsumo consumo) {
    stConsumo aux;
    int flag = 0;
    FILE *pArchConsumo = fopen("consumos.dat", "r+b");
    if (pArchConsumo) {
        while(flag == 0 && fread(&aux, sizeof(stConsumo), 1, pArchConsumo) > 0) {
            if (aux.anio == consumo.anio && aux.mes == consumo.mes && aux.dia == consumo.dia && aux.idCliente == consumo.idCliente) {
                fseek(pArchConsumo, sizeof(stConsumo)*(-1), SEEK_CUR);
                consumo.datosConsumidos = consumo.datosConsumidos + aux.datosConsumidos;
                fwrite(&consumo, sizeof(stConsumo), 1, pArchConsumo);
                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }

}

/*********************************************************************//**
*
* \brief Genera mil consumos en los clientes.
*
*
*
**************************************************************************/
void crearMilConsumosArchivo()
{

    stCliente cliente;
    stConsumo aux;
    stConsumo consumo;
    int flag = 0;
    int existe = 0;
    int cantClientes = 0;
    cantClientes = cuentaClientes();


    printf("\n\nPor favor, espere mientras se crean los consumos.\n");

    for (int i = 0; i < 1000; i++)
    {
        cliente = randomCliente(cantClientes);
        consumo = generaConsumo(cliente); /// Crea un consumo nuevo random
        existe = verificaConsumo(consumo); /// verifica si ya hay uno con esa fecha
        if (existe == 1) {
            acumConsumo(consumo);
        }
        else {
        consumo.id = buscaUltimoIdConsumo()+1;
        FILE *pArchConsumo = fopen("consumos.dat", "ab");
        fwrite(&consumo, sizeof(stConsumo), 1, pArchConsumo);
        fclose(pArchConsumo);
        }
    }
    printf("\nCarga de datos finalizada. ");
}

/*********************************************************************//**
*
* \brief Muestra un consumo.
* \param stCliente consumo
*
*
**************************************************************************/
void muestraConsumo(stConsumo consumo)
{

    puts("\n------------------------------------------");
    printf("\nID Consumo: %d", consumo.id);
    printf("\nID Cliente: %d", consumo.idCliente);
    printf("\nAnio: %d",consumo.anio);
    printf("\nMes: %d",consumo.mes);
    printf("\nDia: %d",consumo.dia);
    printf("\nDatos consumidos: %d",consumo.datosConsumidos);
    printf("\nBaja: %d",consumo.baja);
    puts("\n------------------------------------------");
}

/*********************************************************************//**
*
* \brief Muestra los consumos de un cliente.
* \param Recibe un cliente.
*
*
**************************************************************************/

void mostrarConsumos(stCliente cliente)
{
    stConsumo consumo;
    FILE *pArchConsumo=fopen("consumos.dat","rb");
    if(pArchConsumo)
    {
        while(fread(&consumo,sizeof(stConsumo),1,pArchConsumo)>0)
        {
            if (consumo.idCliente == cliente.nroCliente)
            {
                muestraConsumo(consumo);
            }
        }
        fclose(pArchConsumo);
    }
}

/*********************************************************************//**
*
* \brief Muestra consumo de un cliente específico.
*
*
*
**************************************************************************/
void mostrarConsumosCliente()
{
    int dni;
    int existe;
    stCliente cliente;
    printf("\nIngrese el dni del cliente que quiere ver: \n");
    scanf(" %d", &dni);

    existe = existeCliente(dni);
    if (existe == 1) {
    cliente = buscaCliente(dni);

    printf("\n ********* CLIENTE *********");
    mostrarCliente(cliente);
    printf("\n ********* CONSUMOS *********");
    mostrarConsumos(cliente);
    }
    else{
        printf("\nEl cliente no existe.\n");
    }

}


/*********************************************************************//**
*
* \brief Muestra todos los consumos.
*
*
*
**************************************************************************/

void mostrarTodosConsumos()
{
    stConsumo consumo;
    FILE *pArchConsumo=fopen("consumos.dat","rb");
    if(pArchConsumo)
    {
        while(fread(&consumo,sizeof(stConsumo),1,pArchConsumo)>0)
        {
            muestraConsumo(consumo);
        }
        fclose(pArchConsumo);
    }

}


/** **************    */
/*********************************************************************//**
*
* \brief Busca un consumo especifico segun la fecha.
* \param Recibe el anio en forma de numero entero.
* \param Recibe el mes en forma de entero.
* \param Recibe el dia en forma de entero.
*
**************************************************************************/
void buscarConsumo(int anio, int mes, int dia)
{
    FILE *pArchConsumo = fopen("consumos.dat", "rb");
    stConsumo consumo;

    int flag =0;
    if(pArchConsumo)
    {
        while(flag == 0 && fread(&consumo, sizeof(stConsumo), 1, pArchConsumo) >0 )
        {
            if(consumo.anio == anio && consumo.mes == mes && consumo.dia == dia)
            {
                muestraConsumo(consumo);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("Ese consumo no existe.");
        }
        fclose(pArchConsumo);
    }


}

/*********************************************************************//**
*
* \brief Recibe la fecha para luego llamar a la funcion que busca un consumo especifico.
*
*
*
**************************************************************************/
void mostrarConsumoEspecifico()
{
    int anio;
    int dia;
    int mes;

    printf("\nIngrese anio: ");
    fflush(stdin);
    scanf("%d",&anio);

    printf("\nIngrese mes: ");
    fflush(stdin);
    scanf("%d",&mes);

    printf("\nIngrese dia: ");
    fflush(stdin);
    scanf("%d",&dia);

    buscarConsumo(anio,mes,dia);

}



/*********************************************************************//**
*
* \brief Genera un numero al azar entre un mínimo y un máximo.
* \param Recibe un numero entero.
* \param Recibe un numero entero.
*
**************************************************************************/
int randomRango(int min, int max)
{
    return rand()%(max-min)+min;
}

int arch2ArrConsumo(stConsumo consumoArr[])
{
    stConsumo consumo;
    FILE *pArchConsumo = fopen("consumos.dat", "rb");
    int i=0;

    if(pArchConsumo)
    {
        while(fread(&consumo,sizeof(stConsumo),1,pArchConsumo) > 0)
        {
            consumoArr[i] = consumo;
            i++;
        }
        fclose(pArchConsumo);
    }


    return i;
}

/*********************************************************************//**
*
* \brief Ordena un arreglo de consumos por ID de cliente.
* \param Recibe un arreglo de tipo stConsumo.
* \param Recibe los validos del arreglo.
*
**************************************************************************/
void ordenarArrConsumosCliente(stConsumo consumoArr[], int validos)
{
    stConsumo aux;

    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(consumoArr[i].idCliente > consumoArr[j].idCliente)
            {
                aux = consumoArr[i];
                consumoArr[i] = consumoArr[j];
                consumoArr[j] = aux;
            }
        }
    }
}
/*********************************************************************//**
*
* \brief Ordena un arreglo de consumos segun sus fechas.
* \param Recibe un arreglo de tipo stConsumo.
* \param Recibe sus validos.
*
**************************************************************************/
void ordenarArrConsumosFecha(stConsumo consumoArr[], int validos)
{
    stConsumo aux;

    /// Ordenación por año.
    for(int i = 0; i < validos; i++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(consumoArr[i].anio > consumoArr[j].anio)
            {
                aux = consumoArr[i];
                consumoArr[i] = consumoArr[j];
                consumoArr[j] = aux;
            }
        }
    }

    /// Ordenación por mes
    for(int i = 0; i < validos; i++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(consumoArr[i].anio == consumoArr[j].anio && consumoArr[i].mes > consumoArr[j].mes)
            {
                aux = consumoArr[i];
                consumoArr[i] = consumoArr[j];
                consumoArr[j] = aux;
            }
        }
    }

    /// Ordenación por día
    for(int i = 0; i < validos; i++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(consumoArr[i].anio == consumoArr[j].anio && consumoArr[i].mes == consumoArr[j].mes && consumoArr[i].dia > consumoArr[j].dia)
            {
                aux = consumoArr[i];
                consumoArr[i] = consumoArr[j];
                consumoArr[j] = aux;
            }
        }
    }



}

/*********************************************************************//**
*
* \brief Muestra un arreglo de consumos.
* \param Recibe un arreglo de tipo stConsumo.
* \param Recibe sus validos.
*
**************************************************************************/
void mostrarArrConsumo(stConsumo consumoArr[],int validos)
{
    for(int i = 0; i<validos; i++)
    {
        muestraConsumo(consumoArr[i]);
    }
}


/*********************************************************************//**
*
* \brief Invoca el menu de listados de consumos.
*
*
*
**************************************************************************/
void listarConsumos()
{
    system("cls");
    char option;
    int validos;
    stConsumo consumoArr[10000];

    validos = arch2ArrConsumo(consumoArr);

    printf("\n1. Listar consumos por cliente.");
    printf("\n2. Listar consumos por fecha.");
    option = getch();

    switch(option)
    {
    case 49:
        ordenarArrConsumosCliente(consumoArr, validos);
        mostrarArrConsumo(consumoArr, validos);
        break;
    case 50:
        ordenarArrConsumosFecha(consumoArr, validos);
        mostrarArrConsumo(consumoArr, validos);
        break;
    }
}


/*********************************************************************//**
*
* \brief Muestra las estadísticas de los consumos.
*
*
*
**************************************************************************/
void estadisticaConsumos()
{

    FILE *pArchConsumo = fopen("consumos.dat", "rb");
    stConsumo consumo;
    int consumosArr[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int mayorConsumo = 0;
    int mesMayorConsumo = 0;
    system("cls");
    printf("~~~ Total de consumos por mes en los ultimos anios ~~~\n\n");
    if (pArchConsumo)
    {
        while (fread(&consumo, sizeof(stConsumo), 1, pArchConsumo) > 0)
        {
            consumosArr[consumo.mes - 1] = consumosArr[consumo.mes - 1] + consumo.datosConsumidos;
        }
    }


    for (int i = 0; i < 12; i++)
    {
        if (consumosArr[i] > mayorConsumo) {
            mayorConsumo = consumosArr[i];
            mesMayorConsumo = i;
        }
        if(i == 0)
        {
            printf("\nDatos consumidos en Enero......: %d MB", consumosArr[i]);
        }
        if(i == 1)
        {
            printf("\nDatos consumidos en Febrero....: %d MB", consumosArr[i]);
        }
        if(i == 2)
        {
            printf("\nDatos consumidos en Marzo......: %d MB", consumosArr[i]);
        }
        if (i == 3)
        {
            printf("\nDatos consumidos en Abril......: %d  MB", consumosArr[i]);
        }
        if (i == 4)
        {
            printf("\nDatos consumidos en Mayo.......: %d MB", consumosArr[i]);
        }
        if (i == 5)
        {
            printf("\nDatos consumidos en Junio......: %d MB", consumosArr[i]);
        }
        if (i == 6)
        {
            printf("\nDatos consumidos en Julio......: %d MB", consumosArr[i]);
        }
        if (i == 7)
        {
            printf("\nDatos consumidos en Agosto.....: %d MB", consumosArr[i]);
        }
        if (i == 8)
        {
            printf("\nDatos consumidos en Septiembre.: %d MB", consumosArr[i]);
        }
        if (i == 9)
        {
            printf("\nDatos consumidos en Octubre....: %d MB", consumosArr[i]);
        }
        if (i == 10)
        {
            printf("\nDatos consumidos en Noviembre..: %d MB", consumosArr[i]);
        }
        if (i == 11)
        {
            printf("\nDatos consumidos en Diciembre..: %d MB", consumosArr[i]);
        }
    }
    printf("\n\n");
    if (mesMayorConsumo == 0) {
        char mes[] = "Enero";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 1) {
        char mes[] = "Febrero";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 2) {
        char mes[] = "Marzo";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 3) {
        char mes[] = "Abril";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 4) {
        char mes[] = "Mayo";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 5) {
        char mes[] = "Junio";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 6) {
        char mes[] = "Julio";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 7) {
        char mes[] = "Agosto";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 8) {
        char mes[] = "Septiembre";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 9) {
        char mes[] = "Octubre";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 10) {
        char mes[] = "Noviembre";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }
    if (mesMayorConsumo == 11) {
        char mes[] = "Diciembre";
        printf("\nSegun las estadisticas se efectua un mayor consumo de datos durante el mes de %s.\n", mes);
    }


}

/*********************************************************************//**
*
* \brief  Funcion que se encarga de llamar a las funciones que dan de baja el consumo en caso de que exista.
*
*
*
**************************************************************************/

void darDeBajaConsumo()
{
    stConsumo consumoBuscado;
    int existe;
    int idConsumo;

    printf("\n\t\t ~ SISTEMA DE BAJA DE CONSUMO ~ ");
    printf("\nIngrese id del consumo a dar de baja: ");
    scanf("%d",&idConsumo);

    existe = buscaConsumoID(idConsumo);
    if(existe == 1 )
    {
        consumoBuscado = getConsumo(idConsumo);
        modifBajaConsumo(consumoBuscado);
    }

}

/*********************************************************************//**
*
* \brief Busca un consumo por id
* \return int flag (1 existe , 0 no existe).
* \param int id (id de consumo a buscar)
*
**************************************************************************/

int buscaConsumoID(int id)
{
    FILE *pArchConsumo = fopen("consumos.dat","rb");
    stConsumo consumo;
    int flag = 0;

    if(pArchConsumo)
    {
        while(flag == 0 && fread(&consumo, sizeof(stConsumo),1,pArchConsumo) > 0)
        {
            if(consumo.id == id)
            {

                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }

    return flag;
}

/*********************************************************************//**
*
* \brief Busca consumo a modificar y lo retorna.
* \return stConsumo consumo
* \param int id
*
**************************************************************************/

stConsumo getConsumo(int id)
{
    stConsumo consumo;
    int flag =0;
    FILE *pArchConsumo = fopen("consumos.dat","rb");
    if(pArchConsumo)
    {
        while(flag==0 && fread(&consumo,sizeof(stConsumo),1,pArchConsumo)> 0)
        {
            if(consumo.id == id)
            {
                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }


    return consumo;
}

/*********************************************************************//**
*
* \brief Modifica la baja del consumo pasado por parametro.
* \param stConsumo consumoBuscado
*
*
**************************************************************************/

void modifBajaConsumo(stConsumo consumoBuscado)
{
    FILE *pArchConsumo = fopen("consumos.dat","r+b");
    int pos;
    pos = 0;
    pos = buscaPosicionConsumo(consumoBuscado.id);

    if(pArchConsumo)
    {
        fseek(pArchConsumo, sizeof(stConsumo)*pos, SEEK_SET);
        consumoBuscado.baja=1;
        fwrite(&consumoBuscado, sizeof(stConsumo), 1, pArchConsumo);

        fclose(pArchConsumo);
    }
}

/*********************************************************************//**
*
* \brief Busca la posicion del consumo que se desea modificar.
* \return int pos
* \param int id
*
**************************************************************************/
int buscaPosicionConsumo(int id)
{
    stConsumo consumo;
    int pos=0;
    int flag = 0;
    FILE *pArchConsumo = fopen("consumos.dat","rb");
    if(pArchConsumo)
    {
        while(flag==0 && fread(&consumo,sizeof(stConsumo),1,pArchConsumo)>0)
        {
            pos = pos +1;
            if(consumo.id == id)
            {
                flag=1;
            }
        }
        fclose(pArchConsumo);
    }
    return pos-1;
}

void ordenarArrEmail()
{
    int validos = 0;
    stCliente aux;
    stCliente clientesArr[DIM];
    system("cls");
    validos = arch2ArrInactivos(clientesArr, DIM);

    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(strcmpi(clientesArr[i].email, clientesArr[j].email)== 1)
            {
                aux = clientesArr[i];
                clientesArr[i] = clientesArr[j];
                clientesArr[j] = aux;
            }
        }
    }

    mostrarArr(clientesArr, validos);
}

/*********************************************************************//**
*
* \brief Carga un arreglo de clientes inactivos
* \param arreglo tipo stCliente
* \param int dimension
*
**************************************************************************/
int arch2ArrInactivos(stCliente clientesArr[], int dimension)
{
    stCliente cliente;
    FILE *pArchClientes;
    int i=0;

    pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes)
    {
        while(fread(&cliente,sizeof(stCliente),1,pArchClientes) > 0)
        {
            if(cliente.baja == 1)
            {
                clientesArr[i] = cliente;
                i++;
            }
        }
        fclose(pArchClientes);
    }

    return i;
}


/*********************************************************************//**
*
* \brief Modifica un consumo
*
*
*
**************************************************************************/
void modificarConsumo(){
    stConsumo consumoBuscado;
    int existe;
    int idConsumo;

    printf("\n\t\t ~ CAMBIAR CONSUMO DE CLIENTE ~ ");
    printf("\nIngrese id del consumo que quiere modificar: ");
    scanf("%d",&idConsumo);

    existe = buscaConsumoID(idConsumo);
    if(existe == 1 ){
        consumoBuscado = getConsumo(idConsumo);
        modifConsumo(consumoBuscado);
   }

}

/*********************************************************************//**
*
* \brief Modifica un consumo y lo guarda en el archivo.
*
*
*
**************************************************************************/
void modifConsumo(stConsumo consumo){
    int pos=0;
    pos = buscaPosicionConsumo(consumo.id);
    FILE *pArchConsumo = fopen("consumos.dat", "r+b");
    if(pArchConsumo){
        fseek(pArchConsumo, sizeof(stConsumo)*pos, SEEK_SET);
        printf("\nIngrese la nueva canitdad de datos consumidos: ");
        fflush(stdin);
        scanf("%d",&consumo.datosConsumidos);
        fwrite(&consumo, sizeof(stConsumo), 1, pArchConsumo);
        fclose(pArchConsumo);
    }
}
