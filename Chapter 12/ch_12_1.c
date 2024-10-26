#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

int main(void) {
    char msg[MAX_LENGTH + 1];

    printf("Enter a message: ");
    fgets(msg, MAX_LENGTH, stdin);

    // Define a pointer to traverse the array
    char *ptr = msg + strlen(msg) - 1; // Initialize the pointer to the last character

    printf("Reversal is: ");

    // Print in reverse using the pointer
    while (ptr >= msg) { // While the pointer is not before the start of the array
        printf("%c", *ptr);
        ptr--; // Move the pointer backwards
    }

    return 0;
}