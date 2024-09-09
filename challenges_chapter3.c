
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


int main(){
    exe1();

    return 0;
}