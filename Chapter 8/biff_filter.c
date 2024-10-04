#include <stdio.h>
#include <ctype.h>  // to use toupper()

#define EXCLAMATION_MARKS 10  // 

int main(void) {
    char message[100];  // Array for storage msg
    char ch;
    int i = 0;

    printf("Enter a message: ");
    
    // Read the message
    while ((ch = getchar()) != '\n' && i < sizeof(message) - 1) {
        message[i] = ch;
        i++;
    }
    message[i] = '\0';  // null char

    printf("In BIFF-speak: ");
    
    // apply rules of BIFF-speak
    for (i = 0; message[i] != '\0'; i++) {
        ch = toupper(message[i]);  // Convertir a mayúsculas

        // sustitute
        switch (ch) {
            case 'A': ch = '4'; break;
            case 'B': ch = '8'; break;
            case 'E': ch = '3'; break;
            case 'I': ch = '1'; break;
            case 'O': ch = '0'; break;
            case 'S': ch = '5'; break;
        }

        // print
        putchar(ch);
    }

    // add marks
    for (i = 0; i < EXCLAMATION_MARKS; i++) {
        putchar('!');
    }

    printf("\n");

    return 0;
}
