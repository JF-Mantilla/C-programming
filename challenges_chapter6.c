#include <stdio.h>

int exe1() {
    float num, largest_number = -1;

    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);

        if (num <= 0) {
            break;  // Stop if the user enters 0 or a negative number
        }

        if (num > largest_number) {
            largest_number = num;
        }
    }

    if (largest_number > 0) {
        printf("The largest number entered was %.2f\n", largest_number);
    } else {
        printf("No non-negative numbers were entered.\n");
    }

    return 0;
}

int exe2(){ 

    int m, n;

    //input
    printf("write two integers: ");
    scanf("%d %d", &m, &n);

    // Euclid's algoithm
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }

    // print
    printf("the GCD is: %d\n", m);

    return 0;
}

void reduce_fraction(int numerator, int denominator) {
    int a = numerator;
    int b = denominator;

    // Calculate the GCD using the Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Reduce the fraction using the GCD
    numerator /= a;
    denominator /= a;

    // Output the reduced fraction
    printf("In lowest terms: %d/%d\n", numerator, denominator);
}

int exe3(){
    
    int numerator, denominator;

    // Ask the user for the fraction
    printf("Enter a fraction (numerator/denominator): ");
    scanf("%d/%d", &numerator, &denominator);

    // Call the function to reduce and print the fraction
    reduce_fraction(numerator, denominator);
}

int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. Largest number \n");
        printf("2. Greates common divisor \n");
        printf("3. reduce fraction \n");
        printf("4. largest / smallest \n");
        printf("5. date earlier \n");
        printf("Enter option (1-5): \n");
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