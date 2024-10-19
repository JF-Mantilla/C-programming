#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

// Seven-segment representations for each digit (0-9)
const char segments[10][7] = {
    {'_', '|', '|', ' ', '|', '|', '_'},  // 0
    {' ', ' ', '|', ' ', ' ', '|', ' '},  // 1
    {'_', ' ', '|', '_', '|', ' ', '_'},  // 2
    {'_', ' ', '|', '_', ' ', '|', '_'},  // 3
    {' ', '|', '|', '_', ' ', '|', ' '},  // 4
    {'_', '|', ' ', '_', ' ', '|', '_'},  // 5
    {'_', '|', ' ', '_', '|', '|', '_'},  // 6
    {'_', ' ', '|', ' ', ' ', '|', ' '},  // 7
    {'_', '|', '|', '_', '|', '|', '_'},  // 8
    {'_', '|', '|', '_', ' ', '|', '_'}   // 9
};

// Array to store the digits for display
char digits[4][MAX_DIGITS * 4];

// Function prototypes
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
    char input[MAX_DIGITS + 1];
    int pos = 0;

    printf("Enter a number: ");
    scanf("%10s", input);  // Read at most 10 characters to prevent overflow

    clear_digits_array();

    // Process each character in the input
    for (int i = 0; input[i] != '\0' && pos < MAX_DIGITS; i++) {
        if (isdigit(input[i])) {  // Check if the character is a digit
            process_digit(input[i] - '0', pos);  // Convert char to int
            pos++;
        }
    }

    print_digits_array();

    return 0;
}

// Function to clear the digits array with blank characters
void clear_digits_array(void) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < MAX_DIGITS * 4; col++) {
            digits[row][col] = ' ';
        }
    }
}

// Function to store the seven-segment representation of a digit into the digits array
void process_digit(int digit, int position) {
    int offset = position * 4;  // Calculate the starting position in the array

    digits[0][offset + 1] = segments[digit][0];
    digits[1][offset] = segments[digit][1];
    digits[1][offset + 2] = segments[digit][2];
    digits[2][offset + 1] = segments[digit][3];
    digits[2][offset] = segments[digit][4];
    digits[2][offset + 2] = segments[digit][5];
    digits[3][offset + 1] = segments[digit][6];
}

// Function to display the rows of the digits array
void print_digits_array(void) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < MAX_DIGITS * 4; col++) {
            putchar(digits[row][col]);
        }
        putchar('\n');  // Move to the next row
    }
}
