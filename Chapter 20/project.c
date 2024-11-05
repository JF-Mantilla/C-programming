#include <stdio.h>

// Define a union to hold both a float and a bit-field structure
union FloatConverter {
    float f;  // To store the float value
    struct {
        unsigned int fraction : 23;  // 23 bits for the fraction
        unsigned int exponent : 8;   // 8 bits for the exponent
        unsigned int sign : 1;       // 1 bit for the sign
    } parts;
};

int main() {
    union FloatConverter fc;

    // Set up the fields to represent -2.0
    fc.parts.sign = 1;        // Sign bit = 1 for negative
    fc.parts.exponent = 128;  // Exponent = 128 (bias 127 + 1)
    fc.parts.fraction = 0;    // Fraction = 0 (no fractional part)

    // Print the float value stored in the union
    printf("The float value is: %f\n", fc.f);

    return 0;
}
