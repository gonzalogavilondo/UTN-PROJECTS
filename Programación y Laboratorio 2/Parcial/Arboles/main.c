#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {50, 25, 75, 12, 62, 37, 87, 6, 31, 1, 51, 38, 36, 36, 39, 61, 63, 86, 89};
    int vA = sizeof(a)/sizeof(int);
    printf("\nSizeof a - %d - sizeof int - %d - validos - %d\n" sizeof(a), sizeof(int), vA);

    return 0;
}
