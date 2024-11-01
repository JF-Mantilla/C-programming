#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100  // Maximum number of words to store
#define MAX_LENGTH 20  // Maximum length of each word

// Function to read a line of input from the user
int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';  // Null-terminate the string
    return i;  // Return the length of the string
}

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *words[MAX_WORDS];  // Array of pointers to store each word
    int count = 0;  // Counter for the number of words entered
    char temp[MAX_LENGTH + 1];  // Temporary storage for each word

    printf("Enter words (press Enter on an empty line to stop):\n");
    
    // Loop to read words from the user
    while (1) {
        printf("Enter word: ");
        
        // Read a line of input and store it in `temp`
        if (read_line(temp, MAX_LENGTH) == 0)  // Stop if the input is empty
            break;

        // Allocate memory for the word and copy it to the array
        words[count] = malloc(strlen(temp) + 1);
        if (words[count] == NULL) {  // Check for memory allocation failure
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(words[count], temp);  // Copy the word to the allocated memory
        count++;
    }

    // Sort the array of words using qsort
    qsort(words, count, sizeof(char *), compare);

    // Print the words in sorted order
    printf("In sorted order: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
        free(words[i]);  // Free the allocated memory for each word
    }
    printf("\n");

    return 0;
}
