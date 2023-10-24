#include "Abtree.h"

void pruebaArbolBinario()
{

    int values[] = {15, 9, 6, 3, 4, 6, 2};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;
    btn *ultimo = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n\n\n", values[i]);
        ultimo = createBTN(values[i]);
        insertBTN(&root, ultimo);
    }

    printf("Arbol Binario \n");
    printBTN(root);

    printf("\nLa altura del arbol es: %d \n", height(root));
    if (isLeaf(root))
    {
        printf("La raiz es una hoja.\n");
    }
    else
    {
        printf("La raiz no es una hoja.\n");
    }

    if (isLeaf(ultimo))
    {
        printf("OK! el ultimo nodo es Hoja.\n");
    }
    else
    {
        printf("ERROR! el ultimo nodo debe ser una hoja.\n");
    }

    printf("\nRecorridos del arbol\n\n");
    printf("Inorden:   ");
    inorder(root);
    printf("\n\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n\n");

    printf("Preorder:  ");
    preorder(root);
    printf("\n\n");

}

void pruebaArbolBinarioDeBusqueda()
{

    int values[] = {20, 10, 15, 12, 11, 5, 9, 2, 25, 39, 22, 30};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;
    for (int i = 0; i < count; i++)
    {
        //printf("Agregando: %d\n", values[i]);
        if (!insertValueSBT(&root, values[i]))
        {
            printf("Error al insertar: %d \n", values[i]);
        };
    }

    printf("Arbol Binario de busqueda \n");
    printBTN(root);

    printf("Minimo valor: %d\n", getMinValueSBT(root));
    printf("Maximo valor: %d\n", getMaxValueSBT(root));

    for (int value = 0; value < 30; value += 5)
    {
        if (inSBT(root, value))
        {
            printf("Contiene: %d\n", value);
        }
        else
        {
            printf("No contiene: %d\n", value);
        }
    }

    ///Liberamos el arbol
    freeSBT(root);

}


void pruebaEliminaEnABB()
{

    int values[] = {20, 10, 15,  5, 25, 39, 22, 30, 26, 23, 24};
    int count = sizeof(values) / sizeof(int);

    btn *root1 = NULL;
    btn *root2 = NULL;
    btn *root3 = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n", values[i]);
        if (insertValueSBT(&root1, values[i]))
        {
            insertValueSBT(&root2, values[i]);
            insertValueSBT(&root3, values[i]);
        }
        else
        {
            printf("Duplicado: %d \n", values[i]);
        };
    }

    int nro_del = 25; // probar 20 y 25
    printf("Árbol Binario de búsqueda \n");
    printBTN(root1);

    if (removeValueSBT(&root1, nro_del))
    {
        printf("\n\nElimina el %d reemplazando rama derecha \n", nro_del);
        printBTN(root1);
    }

    if (removeValueSBTRep(&root2, nro_del))
    {
        printf("\n\nElimina el %d reemplazando Min o Max \n", nro_del);
        printBTN(root2);
    }

    if (removeValueSBTSmart(&root3, nro_del))
    {
        printf("\n\nElimina el %d reemplazo \"inteligente\" \n", nro_del);
        printBTN(root3);
    }

}

void pruebaArbolBinarioSt()
{
    int values[] = {15, 9, 6, 3, 4, 6, 2};
    int count = sizeof(values) / sizeof(int);

    btnSt *root = NULL;
    btnSt *ultimo = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n", values[i]);
        ultimo = createBTNSt(createPersona(values[i], "nombre"));
        insertBTNSt(&root, ultimo);
    }

    printf("Arbol Binario \n");
    printBTNSt(root);

    printf("\nLa altura del arbol es: %d \n", heightSt(root));
    if (isLeafSt(root))
    {
        printf("La raiz es una hoja.\n");
    }
    else
    {
        printf("La raiz no es una hoja.\n");
    }

    if (isLeafSt(ultimo))
    {
        printf("OK! el ultimo nodo es Hoja.\n");
    }
    else
    {
        printf("ERROR! el ultimo nodo debe ser una hoja.\n");
    }

    printf("\nRecorridos del arbol\n\n");
    printf("Inorden:   ");
    inorderSt(root);
    printf("\n\n");

    printf("Postorder: ");
    postorderSt(root);
    printf("\n\n");

    printf("Preorder:  ");
    preorderSt(root);
    printf("\n\n");
}

void pruebaArbolBinarioDeBusquedaSt()
{
    int values[] = {20, 10, 15, 12, 11, 5, 9, 2, 25, 39, 22, 30};
    int count = sizeof(values) / sizeof(int);

    btnSt *root = NULL;
    for (int i = 0; i < count; i++)
    {
        // printf("Agregando: %d\n", values[i]);
        if (!insertValueSBTSt(&root, createPersona(values[i], "nombre")))
        {
            printf("Error al insertar: %d \n", values[i]);
        };
    }

    printf("Arbol Binario de búsqueda \n");
    printBTNSt(root);

    printf("Minimo valor: %d\n", getMinValueSBTSt(root));
    printf("Maximo valor: %d\n", getMaxValueSBTSt(root));

    for (int value = 0; value < 30; value += 5)
    {
        if (inSBTSt(root, createPersona(value, "nombre")))
        {
            printf("Contiene: %d\n", value);
        }
        else
        {
            printf("No contiene: %d\n", value);
        }
    }

    // Liberamos el árbol
    freeSBTSt(root);
}

void pruebaEliminaEnABBSt()
{
    int values[] = {20, 10, 15, 5, 25, 39, 22, 30, 26, 23, 24};
    int count = sizeof(values) / sizeof(int);

    btnSt *root1 = NULL;
    btnSt *root2 = NULL;
    btnSt *root3 = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n", values[i]);
        if (insertValueSBTSt(&root1, createPersona(values[i], "nombre")))
        {
            insertValueSBTSt(&root2, createPersona(values[i], "nombre"));
            insertValueSBTSt(&root3, createPersona(values[i], "nombre"));
        }
        else
        {
            printf("Duplicado: %d \n", values[i]);
        };
    }

    int nro_del = 25; // probar 20 y 25
    printf("Árbol Binario de búsqueda \n");
    printBTNSt(root1);

    if (removeValueSBTSt(&root1, createPersona(nro_del, "nombre")))
    {
        printf("\n\nElimina el %d reemplazando rama derecha \n", nro_del);
        printBTNSt(root1);
    }

    if (removeValueSBTRepSt(&root2, createPersona(nro_del, "nombre")))
    {
        printf("\n\nElimina el %d reemplazando Min o Max \n", nro_del);
        printBTNSt(root2);
    }

    if (removeValueSBTSmartSt(&root3, createPersona(nro_del, "nombre")))
    {
        printf("\n\nElimina el %d reemplazo \"inteligente\" \n", nro_del);
        printBTNSt(root3);
    }
}





