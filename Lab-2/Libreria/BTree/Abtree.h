#ifndef ABTREE_H_INCLUDED
#define ABTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "listas.h"
#include "persona.h"

typedef struct btNode btn; //Declaración adelantada para que la estructura btNode pueda referenciarla.
typedef struct btNode
{
    int value;
    btn *left;
    btn *right;

} btn;

/************* FUNCIONES ÁRBOLES BINARIOS**************/

btn *createBTN(int value);
int isLeaf(btn *node);
int countBTN(btn *node);
int max(int a, int b);
int height(btn *node);
int insertBTN(btn **node, btn *newNode);
int insertValueBTN(btn **node, int value);
void inorder(btn *node);
void postorder(btn *node);
void preorder(btn *node);
int findValueBTN(btn *node, int dato);
int countLeafsBTN(btn *node, int countLeafs);
int countGrade1NodesBTN(btn *node);
int balanceFactor(btn *node);

/*********** FUNCIONES ÁRBOLES BINARIOS DE BÚSQUEDA ***********/

int insertNodeSBT(btn **node, btn *newNode);
int insertValueSBT(btn **node, int value);
btn **getMinNodeSBT(btn **node);
btn **getMaxNodeSBT(btn **node);
int getMinValueSBT(btn *node);
int getMaxValueSBT(btn *node);
btn **findNodeSBT(btn **node, int value);
btn *findSBTr(btn *node, int value);
btn *findSBTi(btn *node, int value);
btn *findSBTii(btn *node, int value);
int inSBT(btn *node, int value);
btn *removeNodeSBT(btn **node);
btn *removeNodeSBTRep(btn **node);
btn *removeNodeSBTSmart(btn **node);
int removeValueSBT(btn **node, int value);
int removeValueSBTRep(btn **node, int value);
int removeValueSBTSmart(btn **node, int value);
void freeSBT(btn *node);


/******************** ARBOLES CON LISTAS *************************/
nodo* tree2List(btn* node, nodo *list);

/******************** ADICIONALES *************************/

void printBTN(btn *tree);
int _printBTN(btn *tree, int is_left, int offset, int depth, char s[20][255]);

/******************** FUNCIONES DE PRUEBA *************************/
void pruebaArbolBinario();
void pruebaArbolBinarioDeBusqueda();
void pruebaEliminaEnABB();


/*******************************************************/
/************* FUNCIONES CON ESTRUCTURAS ***************/
/*******************************************************/

typedef struct btNodeSt btnSt;
typedef struct persona Persona;

// Función de comparación para estructuras Persona
int comparePersonas(Persona persona1, Persona persona2);

typedef struct btNodeSt
{
    persona data;
    btnSt *left;
    btnSt *right;
}btnsT;

/************* FUNCIONES ÁRBOLES BINARIOS**************/
btnSt *createBTNSt(persona data);
int isLeafSt(btnSt *node);
int countBTNSt(btnSt *node);
int maxSt(int a, int b);
int heightSt(btnSt *node);
int insertBTNSt(btnSt **node, btnSt *newNode);
int insertValueBTNSt(btnSt **node, persona data);
void inorderSt(btnSt *node);
void postorderSt(btnSt *node);
void preorderSt(btnSt *node);
int findValueBTNSt(btnSt *node, persona data);
int countLeafsBTNSt(btnSt *node, int countLeafs);
int countGrade1NodesBTNSt(btnSt *node);
int balanceFactorSt(btnSt *node);

/*********** FUNCIONES ÁRBOLES BINARIOS DE BÚSQUEDA ***********/
int insertNodeSBTSt(btnSt **node, btnSt *newNode);
int insertValueSBTSt(btnSt **node, persona data);
btnSt **getMinNodeSBTSt(btnSt **node);
btnSt **getMaxNodeSBTSt(btnSt **node);
int getMinValueSBTSt(btnSt *node);
int getMaxValueSBTSt(btnSt *node);
btnSt **findNodeSBTSt(btnSt **node, persona data);
btnSt *findSBTrSt(btnSt *node, persona data);
btnSt *findSBTiSt(btnSt *node, persona data);
btnSt *findSBTiiSt(btnSt *node, persona data);
int inSBTSt(btnSt *node, persona data);
btnSt *removeNodeSBTSt(btnSt **node);
btnSt *removeNodeSBTRepSt(btnSt **node);
btnSt *removeNodeSBTSmartSt(btnSt **node);
int removeValueSBTSt(btnSt **node, persona data);
int removeValueSBTRepSt(btnSt **node, persona data);
int removeValueSBTSmartSt(btnSt **node, persona data);
void freeSBTSt(btnSt *node);
int comparePersonasSt(persona persona1, persona persona2);

/******************** FUNCIONES DE PRUEBA *************************/
void pruebaArbolBinarioSt();
void pruebaArbolBinarioDeBusquedaSt();
void pruebaEliminaEnABBSt();

/******************** ADICIONALES *************************/

void printBTNSt(btnSt *tree);
void _printBTNStCompact(btnSt *tree, int level);

#endif // ABTREE_H_INCLUDED
