/* finding the "smallest" and "largest" words in a series
 of user-input words. The program stops accepting input 
 when the user enters a four-letter word. */

 #include <stdio.h>
#include <string.h>

int main() {
    char word[21];              // Stores the current word (maximum 20 letters)
    char smallest_word[21];      // Stores the smallest word
    char largest_word[21];       // Stores the largest word

    printf("Enter word: ");
    scanf("%20s", word);

    // Initialize smallest and largest words with the first word entered
    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (strlen(word) != 4) {  // Continue until a word with 4 letters is entered
        if (strcmp(word, smallest_word) < 0) {
            strcpy(smallest_word, word);  // Update smallest word
        }
        if (strcmp(word, largest_word) > 0) {
            strcpy(largest_word, word);   // Update largest word
        }

        printf("Enter word: ");
        scanf("%20s", word);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
