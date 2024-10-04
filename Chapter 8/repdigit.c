/* Checks numbers for repeated digits*/

#include <stdbool.h>
#include <stdio.h>

int main(void){

    int digit_seen[10] = {0};

    int digit;

    long n;

    printf("Enter a number (0 for exit): ");

    scanf("%ld",&n);

    while (n>0){
        digit = n%10;
        digit_seen[digit] += 1;

        n /= 10;

        if (n == 0)
        {
            printf("0 1 2 3 4 5 6 7 8 9 \n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", digit_seen[i]);  // Imprime cada elemento
            }
            printf("\n\n");
            printf("Enter a number (0 for exit): ");
            scanf("%ld",&n);

            //Reset array
            for (int i = 0; i < 10; i++) {
                digit_seen[i] = 0;
            }
        }


    }

    printf("Bye Bye");

    return 0;

    
}