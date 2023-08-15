#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 15;
    for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                printf("GenIT");
            } else if (i % 3 == 0) {
                printf("Gen");
            } else if (i % 5 == 0) {
                printf("IT");
            } else {
                printf("%d", i);
            }
        printf("\n");
    }


    return 0;
}
