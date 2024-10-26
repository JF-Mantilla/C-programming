#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

int main(void) {
    char msg[MAX_LENGTH + 1];

    printf("Enter a message: ");
    fgets(msg, MAX_LENGTH, stdin);

    // Pointers for start and end
    char *start = msg;
    char *end = msg + strlen(msg) - 1;

    // Move the start pointer to the first letter
    while (start < end && !isalpha(*start)) {
        start++;
    }

    // Move the end pointer to the last letter
    while (end > start && !isalpha(*end)) {
        end--;
    }

    // Check if it's a palindrome
    int isPalindrome = 1; // Flag to indicate if the message is a palindrome

    while (start < end) {
        // Compare letters (case-insensitive)
        if (tolower(*start) != tolower(*end)) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
        start++; // Move start pointer forward
        end--;   // Move end pointer backward

        // Skip non-letter characters if any
        while (start < end && !isalpha(*start)) {
            start++;
        }
        while (end > start && !isalpha(*end)) {
            end--;
        }
    }

    if (isPalindrome) {
        printf("The message is a palindrome.\n");
    } else {
        printf("The message is not a palindrome.\n");
    }

    return 0;
}
