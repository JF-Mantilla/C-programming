#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    // Loop through command-line arguments and convert to integers
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);  // Convert argument to integer and add to sum
    }

    printf("Total: %d\n", sum);
    return 0;
}
