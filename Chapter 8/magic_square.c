#include <stdio.h>

void generateMagicSquare(int n) {
    int magicSquare[99][99];
    
    // Initialize the magic square with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int num = 1;  // Start with 1
    int i = 0, j = n / 2;  // Start in the middle of the first row

    while (num <= n * n) {
        magicSquare[i][j] = num;
        num++;

        int new_i = (i - 1 + n) % n;  // Move one row up, wrapping around
        int new_j = (j + 1) % n;      // Move one column to the right, wrapping around

        // If the new cell is already filled, move directly below the current cell
        if (magicSquare[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    // Print the magic square
    printf("Magic Square of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input for the size of the magic square
    do {
        printf("Enter the size of the magic square (odd number between 1 and 99): ");
        scanf("%d", &n);
    } while (n < 1 || n > 99 || n % 2 == 0);  // Ensure n is odd and within range

    generateMagicSquare(n);

    return 0;
}
