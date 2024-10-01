#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void average_word_length() {
    char sentence[200];
    int i, word_count = 0, letter_count = 0;

    // Get the input sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Iterate through the sentence
    for (i = 0; sentence[i] != '\0'; i++) {
        if (!isspace(sentence[i])) {
            letter_count++;  // Count letters (including punctuation)
        }
        if ((i > 0 && !isspace(sentence[i - 1]) && isspace(sentence[i])) || (sentence[i+1] == '\0' && !isspace(sentence[i]))) {
            word_count++;  // Count words when transition happens
        }
    }

    // Calculate the average word length
    double average = (double)letter_count / word_count;

    // Print the result with one decimal place
    printf("Average word length: %.1f\n", average);
}

void newton_sqrt() {
    double x, y = 1.0, precision = 0.00001;
    
    // Get the input number
    printf("Enter a positive number: ");
    scanf("%lf", &x);

    // Perform Newton's method iterations
    double y_next;
    do {
        y_next = (y + x / y) / 2.0;
        if (fabs(y_next - y) < precision) {
            break;
        }
        y = y_next;
    } while (1);

    // Print the result
    printf("Square root: %.5f\n", y_next);
}

int main() {
    average_word_length();
    printf("\n");
    printf("\n");
    newton_sqrt();

    return 0;
}