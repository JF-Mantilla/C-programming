
/* Challenges for the chapter 3 of Formating Inputs and outputs*/

// Some outputs

#include <stdio.h>

void exe1(){
    /* Enter a date form and answer in another format */
    int day, year, month;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    // Output the date in yyyymmdd format
    printf("You entered the date: %04d%02d%02d\n", year, month, day);

}

void exe2(){
    /* format product information entered by user */
    int day, year, month, item;
    float price;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    // Output the date in yyyymmdd format
    printf("Enter # of item: ");
    scanf("%d",&item);

    printf("Enter unit price: ");
    scanf("%f", &price);

        // Print formatted output
    printf("\nItem\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");

    // Left justify item and date, right justify unit price
    printf("%-d\t\t$%7.2f\t%02d/%02d/%d\n", item, price, month, day, year);

}

void exe3(){
    int num1, num2, num3, num4, num5;

    printf("Enter ISBN:  ");
    scanf("%d-%d-%d-%d-%d", &num1, &num2, &num3, &num4, &num5);

    printf("GS1 prefix: %d \n", num1);
    printf("Group identifier: %d \n", num2);
    printf("Publisher code: %d \n", num3);
    printf("Item number: %d \n", num4);
    printf("Check digit: %d \n", num5);
}

void exe4(){
    int num1,num2,num3;

    printf("Enter phone number (xxx) xxx-xxxx:  ");
    scanf("(%d) %d-%d", &num1, &num2, &num3);
    printf("You entered %d.%d.%d\n",num1,num2,num3);

}

int exe5() {
    int grid[4][4];  // 4x4 grid for storing the numbers
    int rowSum[4] = {0}, colSum[4] = {0};
    int diagSum1 = 0, diagSum2 = 0;

    // Ask user to input 16 numbers
    printf("Enter the numbers from 1 to 16 in any order:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Display the grid and calculate sums
    printf("The 4x4 grid is:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", grid[i][j]);
            rowSum[i] += grid[i][j];  // Calculate row sums
            colSum[j] += grid[i][j];  // Calculate column sums
            if (i == j) {
                diagSum1 += grid[i][j];  // Calculate main diagonal sum
            }
            if (i + j == 3) {
                diagSum2 += grid[i][j];  // Calculate opposite diagonal sum
            }
        }
        printf("\n");
    }

    // Display row sums
    printf("\nRow sums: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", rowSum[i]);
    }

    // Display column sums
    printf("\nColumn sums: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", colSum[i]);
    }

    // Display diagonal sums
    printf("\nDiagonal sums: %d %d\n", diagSum1, diagSum2);
}


int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. date form \n");
        printf("2. format product information\n");
        printf("3. ISBN break down\n");
        printf("4. display phone number \n");
        printf("5. magic square \n");
        printf("Enter option (1-5): \n");
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

            case 5:
                exe5();
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