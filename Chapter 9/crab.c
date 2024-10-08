#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to roll two dice and return their sum
int roll_dice(void) {
    int die1 = rand() % 6 + 1;  // Random number between 1 and 6
    int die2 = rand() % 6 + 1;  // Random number between 1 and 6
    return die1 + die2;
}

// Function to play a single game of craps
bool play_game(void) {
    int sum = roll_dice();
    printf("You rolled: %d\n", sum);

    if (sum == 7 || sum == 11) {
        printf("You win!\n");
        return true;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
        return false;
    } else {
        int point = sum;
        printf("Your point is %d\n", point);

        while (true) {
            sum = roll_dice();
            printf("You rolled: %d\n", sum);
            if (sum == point) {
                printf("You win!\n");
                return true;
            } else if (sum == 7) {
                printf("You lose!\n");
                return false;
            }
        }
    }
}

// Main function to play multiple games and track wins and losses
int main(void) {
    char play_again;
    int wins = 0, losses = 0;

    // Seed the random number generator
    srand((unsigned)time(NULL));

    do {
        if (play_game()) {
            wins++;
        } else {
            losses++;
        }

        // Ask the user if they want to play again
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    // Display the total number of wins and losses
    printf("Wins: %d  Losses: %d\n", wins, losses);

    return 0;
}
