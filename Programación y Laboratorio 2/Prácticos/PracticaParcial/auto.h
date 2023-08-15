#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct {
   char patente[6];
   int valor;
   char marca[10];
} automovil;

typedef struct {
   automovil dato;
   struct nodoAuto * siguiente;
} nodoAuto;


nodoAuto* crearNodo (automovil auto1);
void agregarFinal(nodoAuto * * lista, nodoAuto * nuevo);
nodoAuto* buscarUltimoNodo(nodoAuto* lista);
automovil cargaUnAuto();
void cicloCargaAutos(char F[]);
void guardarAuto(automovil auto1, char F[]);
void muestraUnAuto(automovil auto1);
void mostrarAutosArchivo(char F[]);
nodoAuto* archivo2listaPD(char F[], nodoAuto* lista);
void mostrarLista(nodoAuto* lista);

#endif // AUTO_H_INCLUDED
