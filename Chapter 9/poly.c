#include <stdio.h>

// Function to compute the value of the polynomial
double evaluate_polynomial(double x) {
    return 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
}

int main() {
    double x;
    
    // Ask the user to enter the value of x
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Calculate the value of the polynomial
    double result = evaluate_polynomial(x);

    // Display the result
    printf("The value of the polynomial is: %.2lf\n", result);

    return 0;
}
