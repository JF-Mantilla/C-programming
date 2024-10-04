#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    char grid[SIZE][SIZE];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Up, Down, Left, Right
    int current_row = 0, current_col = 0;
    char letter = 'A';

    // Initialize grid with '.'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Set the seed for random number generation
    srand((unsigned) time(NULL));

    // Starting point
    grid[current_row][current_col] = letter;

    while (letter < 'Z') {
        int valid_move = 0;
        int attempts = 0;

        // Try to move in random directions up to 4 times
        while (!valid_move && attempts < 4) {
            int direction = rand() % 4;
            int new_row = current_row + directions[direction][0];
            int new_col = current_col + directions[direction][1];

            // Check if the new position is within bounds and not yet visited
            if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && grid[new_row][new_col] == '.') {
                current_row = new_row;
                current_col = new_col;
                letter++;
                grid[current_row][current_col] = letter;
                valid_move = 1;
            } else {
                attempts++;
            }
        }

        // If no valid move was found after 4 attempts, terminate the walk
        if (!valid_move) {
            break;
        }
    }

    // Print the final grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}