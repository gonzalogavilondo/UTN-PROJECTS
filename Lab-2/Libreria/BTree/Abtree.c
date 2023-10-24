#include "Abtree.h"

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: �rbol binario.
 * BTN - binary tree node: nodo de �rbol binario.
 * SBT - Search Binary Tree: ABB - �rbol binario de b�squeda.
 * AVL - AVL Tree: �rbol AVL.
 * root: nodo ra�z del �rbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un �rbol.
 */

/**************************************************************/
/*                     �RBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un valor entero
 */

btn *createBTN(int value)
{
    btn *n = (btn *)malloc(sizeof(btn));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */

int isLeaf(btn *node)
{
    int result = 0;

    if(node == NULL)
    {
        result = 0;
    }
    else if(node->left == NULL && node->right == NULL)
    {
        result = 1;
    }

    return result;
}

/**
 * Cuenta la cantidad de nodos de un �rbol binario.
 */

int countBTN(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = 1 + countBTN(node->left) + countBTN(node->right);
    }
    return result;
}

/**
 * Devuelve el valor m�ximo entre 2 enteros.
 * Funci�n auxiliar utilizada en height.
 */

int max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * Devuelve la altura de un BTN
 * Calcula la altura solo cuando el atributo heigth del nodo es -1.
 */

int height(btn *node)
{
    int result = -1;
    if (node != NULL)
    {
        result = max(height(node->left), height(node->right)) + 1;
    }
    return result;
}

/**
 * Agrega un nodo en un �rbol binario con el siguiente criterio:
 * - Si el sub�rbol es nulo se agrega ah�,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */

int insertBTN(btn **node, btn *newNode)
{
    if (node == NULL) return 0;  // error
    if (newNode == NULL) return 1;

    int result = 0;
    if (*node == NULL)
    {
        *node = newNode;
        result = 1;
    }
    else
    {
        if((countBTN((*node)->left) - countBTN((*node)->right)) > 0)
        {
            result = insertBTN(&((*node)->right), newNode);
        }
        else
        {
            result = insertBTN(&((*node)->left), newNode);
        }
    }
    return result;
}

/**
 * Agrega un valor a un BT con el criterio:
 * - Si el sub�rbol es nulo se agrega ah�,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */

int insertValueBTN(btn **node, int value)
{
    btn *newNode = createBTN(value);
    int result = insertBTN(node, newNode);
    if (!result)
    {
        printf("Duplicado: %d\n\n", (*node)->value);
        free(newNode);
    }
    return result;
}

/**
 * Imprime los valores de un BT en inorden
 */

void inorder(btn *node)
{
    if(node != NULL)
    {
        inorder(node->left); //Atravieza el sub-arbol izquierdo
        printf("%d ", node->value); //Visita la raiz
        inorder(node->right); //Atraviesa el sub-arbol derecho
    }
}

/**
 * Imprime los valores de un BT en postorder
 */

void postorder(btn *node)
{
    if(node != NULL)
    {
        postorder(node->left); //Atraviesa el sub-arbol izquierdo
        postorder(node->right); //Atraviesa el sub-arbol derecho
        printf("%d ", node->value); //Visita la raiz
    }

}

/**
 * Imprime los valores de un BT en preorder
 */

void preorder(btn *node)
{
    if(node != NULL)
    {
        printf("%d ", node->value); //Visita la raiz
        preorder(node->left); //Atraviesa el sub-arbol izquierdo
        preorder(node->right); //Atraviesa el sub-arbol derecho
    }

}

/**
 * Busca un el valor dentro de un nodo de un BT
 * Devuelve:
 *  1 Si se encontr�
 *  0 Si no se encontr�
 */
int findValueBTN(btn *node, int dato)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->value == dato)
    {
        return 1;
    }

    if (findValueBTN(node->left, dato) || findValueBTN(node->right, dato))
    {
        return 1;
    }

    return 0; ///No estaba en el actual ni en ninguno de los sub-arboles...
}


/**
 * Contar nodos hojas de un BT
 * Devuelve:
 *  La cantidad de nodos hojas de un arbol binario
 */
int countLeafsBTN(btn *node, int countLeafs)
{
    if(node == NULL)
    {
        return countLeafs;
    }
    else
    {
        countLeafs = countLeafsBTN(node->left, countLeafs);
        countLeafs = countLeafsBTN(node->right, countLeafs);
        if(node->right == NULL && node->left == NULL)
        {
            countLeafs++;
        }
    }
    return countLeafs;
}

/**
 * Contar nodos hojas de un BT
 * Devuelve:
 *  La cantidad de nodos de grado 1 de un arbol binario
 */
int countGrade1NodesBTN(btn *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int cnt = 0;

    if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))
        //if ((node->left == NULL) && (node->right == NULL))
    {
        cnt += 1;
    }

    cnt += countGrade1NodesBTN(node->left);
    cnt += countGrade1NodesBTN(node->right);

    return cnt;
}

/**
 * Devuelve el Factor de Equilibrio (o Factor de Balanceo) de un BTN
 */

int balanceFactor(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = height(node->left) - height(node->right);
    }
    return result;
}

/**************************************************************/
/*             �RBOLES BINARIOS DE B�SQUEDA                   */
/**************************************************************/

/**
 * Agrega un nodo a un �rbol binario de b�squeda (SBT)
 * (no agrega valores repetidos)
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a insertar
 *          *newNode: puntero al nodo que se va a insertar en el SBT
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int insertNodeSBT(btn **node, btn *newNode)
{
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;
    if ((*node) == NULL)
    {
        *node = newNode;
        return 1;
    }
    else
    {
        if (newNode->value < (*node)->value)
        {
            // si el nuevo es menor inserta a izquierda
            return insertNodeSBT(&((*node)->left), newNode);
        }
        else if((newNode->value > (*node)->value))
        {
            // si el nuevo es mayor a la derecha
            return insertNodeSBT(&((*node)->right), newNode);
        }
        else
        {
            return 0;
        }
    }
}

/**
 * Agrega un valor a un �rbol binario de b�squeda (SBT)
 * (no agrega valores repetidos)
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a insertar
 *          value: el valor a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int insertValueSBT(btn **node, int value)
{
    btn *newNode = createBTN(value);
    int result = insertNodeSBT(node, newNode);
    if (!result)
    {
        printf("Duplicado: %d\n\n", (*node)->value);
        free(newNode);
    }
    return result;
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor m�nimo de un
 * SBT.
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a buscar
 */
btn **getMinNodeSBT(btn **node)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    if (((*node)->left) != NULL)
    {
        return getMinNodeSBT(&(*node)->left);
    }
    else
    {
        return node;
    }
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor m�ximo de un
 * SBT.
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a buscar
 */

btn **getMaxNodeSBT(btn **node)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    if (((*node)->right) != NULL)
    {
        return getMaxNodeSBT(&(*node)->right);
    }
    else
    {
        return node;
    }
}

/**
 * Devuelve el valor m�nimo de un SBT
 */

int getMinValueSBT(btn *node)
{
    if (node == NULL) return -1;
    btn **r = getMinNodeSBT(&node);
    return (*r)->value;
}

/**
 * Devuelve el valor m�ximo de un SBT
 */

int getMaxValueSBT(btn *node)
{
    if (node == NULL) return -1;
    btn **r = getMaxNodeSBT(&node);
    return (*r)->value;
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor solicitado de
 * un SBT.
 * Par�metros:
 *          value: el valor que se busca en el SBT.
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a buscar.
 */

btn **findNodeSBT(btn **node, int value)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return NULL;  // []->nodo

    if ((*node)->value == value)
    {
        return node;
    }
    else if ((*node)->value > value)
    {
        return findNodeSBT(&((*node)->left), value);
    }
    else
    {
        return findNodeSBT(&((*node)->right), value);
    }
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versi�n recursiva)
 * Par�metros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-�rbol donde se
 * va a buscar.
 */

btn *findSBTr(btn *node, int value)
{
    if(node == NULL || node->value == value)
    {
        return node;
    }
    else if(value < node->value)
    {
        return findSBTr(node->left, value);
    }
    else
    {
        return findSBTr(node->right, value);
    }

}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versi�n iterativa)
 * Par�metros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-�rbol donde se
 * va a buscar.
 */

btn *findSBTi(btn *node, int value)
{
    while ((node != NULL) && (node->value != value))
    {
        if (node->value > value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versi�n iterativa en reducida)
 * Par�metros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-�rbol donde se
 * va a buscar.
 */

btn *findSBTii(btn *node, int value)
{
    while ((node != NULL) && (node->value != value))
    {
        node = (node->value > value) ? node->left : node->right;
    }
    return node;
}

/**
 * Devuelve 1 si un valor se encuentra en el �rbol, o 0 si no se encuentra
 */

int inSBT(btn *node, int value)
{
    node = findSBTr(node, value);
    return (node != NULL) ? 1 : 0;
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por su rama Derecha y agregando
 * la rama Izquierda a la rama derecha.
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a eliminar.
 */

btn *removeNodeSBT(btn **node)
{
    if(!node)
    {
        return NULL;
    }
    if(!(*node))
    {
        return NULL;
    }

    btn *aux = *node;
    insertNodeSBT(&(aux->right), aux->left); //A mi rama derecha, le voy a insertar mi rama izquierda
    *node = aux->right;
    aux->right = NULL;
    aux->left = NULL;

    return aux;
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por el m�ximo de su rama
 * izquierda, o en su defecto por el m�nimo de su rama derecha.
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a eliminar.
 */

btn *removeNodeSBTRep(btn **node)
{
    btn *temp = NULL;

    if (!node) return NULL;
    if (!(*node)) return NULL;
    else if((*node)->left == NULL) // Un solo hijo, a la derecha
    {
        temp = *node;
        (*node) = (*node)->right; // Coloca el hijo de la derecha en lugar del nodo
        free(temp);
    }
    else if ((*node)->right == NULL) // Un solo hijo, a la izquierda
    {
        temp = *node;
        (*node) = (*node)->left; // Coloca hijo de la izquierda en lugar del nodo
        free(temp);
    }
    else if((*node)->left != NULL && (*node)->right!= NULL) // Dos hijos
    {
        temp = (*node)->right; // hijo de la derecha
        while (temp->left != NULL) // busca el menor valor del arbol a la derecha
        {
            temp = temp->left;
        }
        temp->left = (*node)->left; // Inserta sub-arbol de la izquierda
        temp = (*node);
        (*node) = (*node)->right; // Coloca nodo de la derecha en lugar del nodo
        free(temp);
    }

    return (*node);
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por
 * 1) el m�ximo de su rama izquierda, si la rama izquierda es igual o m�s alta
 * que la derecha.
 * 2) el m�nimo de su rama derecha, si la rama derecha es m�s
 * alta que la izquierda.
 * Par�metros:
 *          **node: debe ser la direcci�n de memoria (en la estructura del padre
 * o la ra�z) que donde se encuentra el puntero al nodo del sub�rbol donde se
 * va a eliminar.
 */

btn *removeNodeSBTSmart(btn **node)
{
    if (!node) return NULL;
    if (!(*node)) return NULL;

    btn **aux;
    if((height((*node)->left) - height((*node)->right)) >= 0)
    {
        aux = getMaxNodeSBT(&((*node)->left));
    }
    else
    {
        aux = getMinNodeSBT(&((*node)->right));
    }

    btn *result = *node;         // Resguarda el nodo que ser� eliminado.
    *node = removeNodeSBT(aux);  // Reemplaza el nodo con el resultado de la
                                 // eliminaci�n del auxiliar.
    if (*node != NULL)
    {
        // Si no era una hoja
        // Se vincula el nodo reemplazado con los hijos del auxiliar.
        (*node)->left = result->left;
        (*node)->right = result->right;
    }
    // Importante! se desvincula el auxiliar de sus hijos.
    result->left = NULL;
    result->right = NULL;
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa m�todo de reemplazo por el hijo derecho.
 * Devuelve 1 si pudo eliminarlo,
 * Devuelve 0 si no pudo
 */

int removeValueSBT(btn **node, int value)
{
    btn *deleted = removeNodeSBT(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa m�todo de reemplazo del m�ximo de la rama izquierda o m�nimo de la rama
 * derecha. Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */

int removeValueSBTRep(btn **node, int value)
{
    btn *deleted = removeNodeSBTRep(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa m�todo de reemplazo del m�ximo de la rama izquierda o m�nimo de la rama
 * seg�n cual sea m�s alto.
 * Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */

int removeValueSBTSmart(btn **node, int value)
{
    btn *deleted = removeNodeSBTSmart(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}
/**
 * Funci�n para liberar la memoria de un �rbol binario de b�squeda (SBT)
 */

void freeSBT(btn *node)
{
    if (node == NULL)
    {
        return;
    }
    freeSBT(node->left);
    freeSBT(node->right);
    free(node);
}

/**************************************************************/
/*                  ARBOLES CON LISTAS                        */
/**************************************************************/
/// Fcion. principal para copiar el arbol a la lista
nodo* tree2List(btn* node, nodo *list)
{
    if (node != NULL)
    {
        list = agregarAlFinal(list, crearNodo(node->value));

        list = tree2List(node->left, list);
        list = tree2List(node->right, list);
    }
    return list;
}



/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un �rbol.
 */

int _printBTN(btn *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[200];
    int width = 5;

    if (!tree) return 0;
    // sprintf(b, "(%03d)", tree->value);
     sprintf(b, "(%03d)bf:%d ", tree->value, balanceFactor(tree));
    // sprintf(b, "(%03d)bf:%d h:%d", tree->value, balanceFactor(tree),
    // height(tree));

    int left = _printBTN(tree->left, 1, offset, depth + 1, s);
    int right = _printBTN(tree->right, 0, offset + left + width, depth + 1, s);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++)
    {
        s[2 * depth][offset + left + i] = b[i];
    }

    if (depth && is_left)
    {
        for (int i = 0; i < width + right; i++)
        {
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';
        }

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    }
    else if (depth && !is_left)
    {
        for (int i = 0; i < left + width; i++)
        {
            s[2 * depth - 1][offset - width / 2 + i] = '-';
        }

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

/**
 * Dibuja un �rbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */

void printBTN(btn *tree)
{
    char s[20][255];
    for (int i = 0; i < height(tree)*3; i++)
    {
        sprintf(s[i], "%80s", " ");
    }
    _printBTN(tree, 0, 0, 0, s);

    puts("\n");
    for (int i = 0; i < height(tree)*3; i++)
    {
        printf("%s\n", s[i]);
    }
}
