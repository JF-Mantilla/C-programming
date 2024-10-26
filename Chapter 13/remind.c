/* Print a one-month reminder list*/

// Libraries
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* Max number of reminders */
#define MSG_LEN 60

// Prototypes
int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        if (scanf("%d", &day) != 1) { // Check if scanf successfully read an integer
            printf("Invalid input. Please enter a valid day.\n");
            // Clear the input buffer
            while (getchar() != '\n'); // Discard invalid input
            continue; // Restart the loop
        }

        if (day == 0) break;

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        // Find the correct position to insert the reminder
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0) break;
        
        // Shift reminders down
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        // Insert new reminder
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    // Print reminders
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n) {
    /* Read the input and save in an array */
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
