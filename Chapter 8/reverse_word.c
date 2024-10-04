#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWords(char *sentence) {
    int length = strlen(sentence);
    char reversed[101];  // Assuming input won't exceed 100 characters
    int word_start = length, word_end = length;
    int rev_index = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isspace(sentence[i]) || ispunct(sentence[i]) || i == 0) {
            if (i == 0) word_start = i;
            else word_start = i + 1;

            for (int j = word_start; j < word_end; j++) {
                reversed[rev_index++] = sentence[j];
            }

            if (isspace(sentence[i])) reversed[rev_index++] = ' ';
            else if (ispunct(sentence[i])) reversed[rev_index++] = sentence[i];

            word_end = i;
        }
    }

    reversed[rev_index] = '\0'; // Null-terminate the string
    printf("Reversed sentence: %s\n", reversed);
}

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    reverseWords(sentence);

    return 0;
}
