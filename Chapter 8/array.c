#include <stdio.h>

int main() {
    int arr[5][5];
    int row_sums[5] = {0};
    int col_sums[5] = {0};

    // Input the array elements
    for (int i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
            row_sums[i] += arr[i][j];  // Summing rows
            col_sums[j] += arr[i][j];  // Summing columns
        }
    }

    // Output row sums
    printf("Row totals: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", row_sums[i]);
    }
    printf("\n");

    // Output column sums
    printf("Column totals: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", col_sums[j]);
    }
    printf("\n");

    return 0;
}
