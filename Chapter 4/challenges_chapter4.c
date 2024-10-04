#include <stdio.h>

int main() {
    int num, reversed = 0, original, remainder;

    // Ask the user to enter a number
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Store the original number
    original = num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10; // Get the last digit
        reversed = reversed * 10 + remainder; // Append it to the reversed number
        num /= 10; // Remove the last digit
    }

    // Output the reversed number
    printf("The reverse of %d is %d\n", original, reversed);

    return 0;
}