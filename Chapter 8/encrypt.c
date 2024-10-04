#include <stdio.h>
#include <ctype.h>

void caesarCipher(char message[], int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        
        // Encrypt uppercase letters
        if (isupper(ch)) {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // Encrypt the message
    caesarCipher(message, shift);

    printf("Encrypted message: %s", message);
    
    return 0;
}
