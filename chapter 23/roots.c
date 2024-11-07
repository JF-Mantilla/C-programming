#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // Prompt the user for input
    printf("Enter the coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Check if the discriminant is non-negative
    if (discriminant >= 0) {
        // Calculate both roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        // Print the roots
        printf("The roots are: %.2lf and %.2lf\n", root1, root2);
    } else {
        // If discriminant is negative, print a message
        printf("The roots are complex (no real solutions).\n");
    }

    return 0;
}
