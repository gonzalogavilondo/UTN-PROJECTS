#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"
#include "declaraciones_menu.h"

int main()
{
    int opcion = 0;
    int opcion2 = 0;
    int fils1 = 0;
    int cols1 = 0;
    int fils2 = 0;
    int cols2 = 0;
    char a = 'A';
    char b = 'B';
    float **A = NULL;
    float **B = NULL;
    float **C = NULL;

    do
    {
        opcion = Menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 7)
        {
            CargarFilasColumnas(&fils1, &cols1);
            CondicionOpcion(opcion, &fils1, &cols1, &fils2, &cols2);
            A = ReservarMemoria(fils1,cols1);
            B = ReservarMemoria(fils2,cols2);
            system("cls || clear");
            if((opcion == 1) || (opcion == 2) || (opcion == 3))
            {
                C = ReservarMemoria(fils1, cols2);
                CompletarMatriz(fils1, cols1, A, a);
                CompletarMatriz(fils2, cols2, B, b);
                printf("-MATRIZ A-\n\n");
                MostrarMatriz(fils1, cols1, A);
                printf("\n-MATRIZ B-\n\n");
                MostrarMatriz(fils2, cols2, B);
                OpcionProceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                printf("\n-MATRIZ RESULTANTE-\n\n");
                MostrarMatriz(fils1, cols2, C);
                //Liberamos memoria de C
                for(int i = 0; i < fils1; i++)
                {
                    free(C[i]);
                }

                free(C);
            }
            else
            {
                if(opcion == 6)
                {
                    C = ReservarMemoria(cols1, fils1);
                    CompletarMatriz(fils1, cols1, A, a);
                    printf("-MATRIZ-\n\n");
                    MostrarMatriz(fils1, cols1, A);
                    OpcionProceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    MostrarMatriz(cols1, fils1, C);
                    //Liberamos memoria de C
                    for(int i = 0; i < cols1; i++)
                    {
                        free(C[i]);
                    }

                    free(C);
                }
                else
                {
                    C = ReservarMemoria(fils1, cols1);
                    CompletarMatriz(fils1, cols1, A, a);
                    printf("-MATRIZ-\n\n");
                    MostrarMatriz(fils1, cols1, A);
                    OpcionProceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    MostrarMatriz(fils1, cols1, C);
                    //Liberamos memoria de C
                    for(int i = 0; i < fils1; i++)
                    {
                        free(C[i]);
                    }

                    free(C);
                }
            }
            opcion2 = 0;
            //Libero memoria de A y B

            for(int i = 0; i < fils1; i++)
            {
                free(A[i]);
            }
            for(int i = 0; i < fils2; i++)
            {
                free(B[i]);
            }

            free(A);
            free(B);
        }
        else
        {
            opcion2 = OpcionSalida();
        }
        system("pause");

    }while(opcion2 == 0);

    return 0;
}
