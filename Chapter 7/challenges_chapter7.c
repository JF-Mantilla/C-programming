#include <stdio.h>
#include <ctype.h>

int exe1() {
    
    char phone_number[100];
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    // Loop through each character of the input
    for (int i = 0; phone_number[i] != '\0'; i++) {
        // Convert the letter to the corresponding digit
        if (isalpha(phone_number[i])) {
            switch (toupper(phone_number[i])) {
                case 'A': case 'B': case 'C':
                    phone_number[i] = '2';
                    break;
                case 'D': case 'E': case 'F':
                    phone_number[i] = '3';
                    break;
                case 'G': case 'H': case 'I':
                    phone_number[i] = '4';
                    break;
                case 'J': case 'K': case 'L':
                    phone_number[i] = '5';
                    break;
                case 'M': case 'N': case 'O':
                    phone_number[i] = '6';
                    break;
                case 'P': case 'R': case 'S':
                    phone_number[i] = '7';
                    break;
                case 'T': case 'U': case 'V':
                    phone_number[i] = '8';
                    break;
                case 'W': case 'X': case 'Y':
                    phone_number[i] = '9';
                    break;
                // Letters like Q and Z can be mapped to 7 and 9, respectively, 
                // or handle them as you see fit if they are expected in the input.
                default:
                    break;
            }
        }
    }

    printf("Numeric form: %s\n", phone_number);
    return 0;
}

int exe2(){ 
    /* Value of a word in Scrabble */
    
    int values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int total_value = 0;
    char word[100];  // Array to hold the input word

    // Prompt the user to enter a word
    printf("Enter a word: ");
    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = toupper(word[i]);  //Convert to Upper
        if (ch >= 'A' && ch <= 'Z') {
            total_value += values[ch - 'A'];  // add the value
        }
    }

    // print
    printf("Scrabble Value: %d\n",total_value);

    return 0;
}

void reduce_fraction(int numerator, int denominator) {
    int a = numerator;
    int b = denominator;

    // Calculate the GCD using the Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Reduce the fraction using the GCD
    numerator /= a;
    denominator /= a;

    // Output the reduced fraction
    printf("In lowest terms: %d/%d\n", numerator, denominator);
}

int exe3(){

    char sentence[200];  // Array to store the input sentence
    int vowel_count = 0;  // Vowel counter

    // Ask the user to input a sentence
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);  // Read until a newline is encountered

    // Count vowels in the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = toupper(sentence[i]);  // Convert to uppercase to simplify
        
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowel_count++;  // Increment the counter if it's a vowel
        }
    }

    // Display the result
    printf("Your sentence contains %d vowels.\n", vowel_count);

    return 0;
}

int exe4(){

    char input[100], first_name[50], last_name[50];
    int i = 0, j = 0;

    // Get user input
    printf("Enter a first and last name: ");
    fgets(input, sizeof(input), stdin);

    // Remove leading spaces
    while (isspace(input[i])) {
        i++;
    }

    // Extract the first name
    while (!isspace(input[i]) && input[i] != '\0') {
        first_name[j++] = input[i++];
    }
    first_name[j] = '\0'; // Terminate first name string

    // Skip spaces between first and last name
    while (isspace(input[i])) {
        i++;
    }

    // Extract the last name
    j = 0;
    while (!isspace(input[i]) && input[i] != '\0' && input[i] != '\n') {
        last_name[j++] = input[i++];
    }
    last_name[j] = '\0'; // Terminate last name string

    // Print the formatted output: Last name, first initial.
    printf("%s, %c.\n", last_name, first_name[0]);



}



int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. Largest number \n");
        printf("2. Scrabble word value \n");
        printf("3. number of vowels in a sentence \n");
        printf("4. format name \n");

        printf("Enter 7 to exit: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                exe1();
                break;
            
            case 2:
                exe2();
                break;

            case 3:
                exe3();
                break;

            case 4:
                exe4();
                break;

            default:
                printf("Try Again.\n");
                break;  
        }
        // Clarity
        printf("\n");

    } while (opcion != 7);
    printf("bye bye.\n");

    return 0;
}