
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


int main(){
    //exe1();
    //exe2();
    //exe3();
    exe4();

    return 0;
}