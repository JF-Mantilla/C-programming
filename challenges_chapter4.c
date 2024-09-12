#include <stdio.h>

void exe1(){

    int number, tens, ones;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    // Extract the tens and ones place
    tens = number / 10;  // Tens place digit
    ones = number % 10;  // Ones place digit

    // Print the reversed digits
    printf("The reversal is: %d%d\n", ones, tens);
}

int main(){
    int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. reverse number \n");
        printf("Enter option (1-6): \n");
        printf("Enter 7 to exit: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                exe1();
                break;
            
            case 2:
                //exe2();
                break;

            case 3:
                //exe3();
                break;

            case 4:
                //exe4();
                break;

            case 5:
                //exe5();
                break;

            default:
                printf("Try Again.\n");
                break;  
        }
        // Clarity
        printf("\n");

    } while (opcion != 7);
    printf("bye bye.\n");

    return 0;
}