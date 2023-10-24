#ifndef ABTREE_H_INCLUDED
#define ABTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "listas.h"

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


#endif // ABTREE_H_INCLUDED
