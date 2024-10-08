#include <stdio.h>

// Recursive function to compute x^n
double power(double x, int n) {
    if (n == 0) {
        return 1;  // Base case: x^0 = 1
    } else if (n % 2 == 0) {
        double halfPower = power(x, n / 2);
        return halfPower * halfPower;  // If n is even, use (x^(n/2))^2
    } else {
        return x * power(x, n - 1);  // If n is odd, use x * x^(n-1)
    }
}

int main() {
    double x;
    int n;
    
    // Ask the user to enter values of x and n
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate x^n using the recursive power function
    double result = power(x, n);

    // Display the result
    printf("The value of %.2lf^%d is: %.2lf\n", x, n, result);

    return 0;
}
