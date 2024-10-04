#include <stdio.h>

int main(void) {
    int a[10], i;

    int length = (int)(sizeof(a) / sizeof(a[0]));  // Calcula el tamaño del array dinámicamente

    printf("Enter %d numbers: ", length);
    for(i = 0; i < length; i++)
        scanf("%d", &a[i]);

    printf("In reverse order:");
    for (i = length - 1; i >= 0; i--)
        printf(" %d", a[i]);

    printf("\n");

    return 0;
}