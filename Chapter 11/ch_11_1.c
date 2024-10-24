
#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    // Calculate the number of $20 bills
    *twenties = dollars / 20;
    dollars %= 20;

    // Calculate the number of $10 bills
    *tens = dollars / 10;
    dollars %= 10;

    // Calculate the number of $5 bills
    *fives = dollars / 5;
    dollars %= 5;

    // Calculate the number of $1 bills
    *ones = dollars;
}

int main() {
    int dollars;
    int twenties, tens, fives, ones;

    // Input the dollar amount
    printf("Enter the dollar amount: ");
    scanf("%d", &dollars);

    // Call the function to calculate the bills
    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    // Output the result
    printf("Twenties: %d\n", twenties);
    printf("Tens: %d\n", tens);
    printf("Fives: %d\n", fives);
    printf("Ones: %d\n", ones);

    return 0;
}
