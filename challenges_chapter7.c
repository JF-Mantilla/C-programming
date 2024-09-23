#include <stdio.h>
#include <ctype.h>

int exe1() {
    
    char phone_number[100];
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    // Loop through each character of the input
    for (int i = 0; phone_number[i] != '\0'; i++) {
        // Convert the letter to the corresponding digit
        if (isalpha(phone_number[i])) {
            switch (toupper(phone_number[i])) {
                case 'A': case 'B': case 'C':
                    phone_number[i] = '2';
                    break;
                case 'D': case 'E': case 'F':
                    phone_number[i] = '3';
                    break;
                case 'G': case 'H': case 'I':
                    phone_number[i] = '4';
                    break;
                case 'J': case 'K': case 'L':
                    phone_number[i] = '5';
                    break;
                case 'M': case 'N': case 'O':
                    phone_number[i] = '6';
                    break;
                case 'P': case 'R': case 'S':
                    phone_number[i] = '7';
                    break;
                case 'T': case 'U': case 'V':
                    phone_number[i] = '8';
                    break;
                case 'W': case 'X': case 'Y':
                    phone_number[i] = '9';
                    break;
                // Letters like Q and Z can be mapped to 7 and 9, respectively, 
                // or handle them as you see fit if they are expected in the input.
                default:
                    break;
            }
        }
    }

    printf("Numeric form: %s\n", phone_number);
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

int exe4(){

    int num, temp=0, op;
    printf("Enter a number ");
    scanf("%d",&num);

    do
    {
        op = num % 10;
        temp = temp * 10 + op;
        num /= 10;
    } while (num != 0);


    
    printf ("The reverse number is %d", temp);



}

int exe5(){
    int days, start;

    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf(" Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    // Print the header for the calendar
    printf("\n Sun Mon Tue Wed Thu Fri Sat\n");

        // Print leading spaces for the first week
    for (int i = 1; i < start; i++) {
        printf("    "); // Four spaces for each empty day
    }

    // Print the days of the month
    for (int day = 1; day <= days; day++) {
        printf("%4d", day); // Print the day with a width of 4 for proper alignment

        // Move to the next line after every Saturday (7th day of the week)
        if ((day + start - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    
}

// Function to calculate factorial of a number
long long factorial(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int exe6(){

    double epsilon;
    double e = 1.0; // Start with 1 (corresponding to 1/0!)
    int i = 1;      // Counter for the series terms
    double term;

    // Get user input for the value of epsilon
    printf("Enter a small number epsilon: ");
    scanf("%lf", &epsilon);

    // Calculate the series until the current term is less than epsilon
    do {
        term = 1.0 / factorial(i);  // Calculate current term
        e += term;                  // Add current term to the value of e
        i++;                        // Move to the next term in the series
    } while (term >= epsilon);      // Continue while the term is greater than or equal to epsilon

    // Print the result
    printf("The approximation of e is: %lf\n", e);

    return 0;
}

int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. Largest number \n");
        printf("2. Greates common divisor \n");
        printf("3. reduce fraction \n");
        printf("4. reverse number \n");
        printf("5. calendar \n");
        printf("6. aproximate e (euler) \n");
        printf("Enter option (1-5): \n");
        printf("Enter 7 to exit: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                exe1();
                break;
            
            case 2:
                exe2();
                break;

            case 3:
                exe3();
                break;

            case 4:
                exe4();
                break;

            case 5:
                exe5();
                break;

            case 6:
                exe6();
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