#include <stdio.h>

int exe1() {
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check the number of digits using if-else statements
    if (number >= 0 && number <= 9) {
        printf("The number %d has 1 digit\n", number);
    }
    else if (number >= 10 && number <= 99) {
        printf("The number %d has 2 digits\n", number);
    }
    else if (number >= 100 && number <= 999) {
        printf("The number %d has 3 digits\n", number);
    }
    else if (number >= 1000 && number <= 9999) {
        printf("The number %d has 4 digits\n", number);
    }
    else {
        printf("The number has more than 4 digits or is negative\n");
    }

    return 0;
}

int exe2() {
    int hour, minute;

    // Input the 24-hour time
    printf("Enter a 24-hour time (HH:MM): ");
    scanf("%d:%d", &hour, &minute);

    // Convert 24-hour time to 12-hour format
    if (hour == 0) {
        printf("Equivalent 12-hour time: %d:%02d AM\n", 12, minute);
    } 
    else if (hour == 12) {
        printf("Equivalent 12-hour time: %d:%02d PM\n", 12, minute);
    } 
    else if (hour > 12) {
        printf("Equivalent 12-hour time: %d:%02d PM\n", hour - 12, minute);
    } 
    else {
        printf("Equivalent 12-hour time: %d:%02d AM\n", hour, minute);
    }

    return 0;
}

int exe3() {
    int speed;

    // Input speed
    printf("Enter speed (in knots) ");
    scanf("%d", &speed);


    if (speed < 1) {
        printf("Calm");
    } 
    else if (speed >= 1 && speed <= 3) {
        printf("Light air");
    }
    else if (speed >= 4 && speed <= 27) {
        printf("Breeze");
    }
    else if (speed >= 28 && speed <= 47) {
        printf("Breeze");
    }
    else if (speed >= 48 && speed <= 63) {
        printf("Breeze");
    }
    else {
        printf("Hurricane");
    }

    return 0;
}

int exe4(){

    printf("Enter four integers: ");
    int d1,d2,d3,d4;
    scanf("%d %d %d %d",&d1,&d2,&d3,&d4);


    int smallest,largest;

    largest = d1;
    smallest = d1;

    // Finding the largest number
    if(d2 > largest) largest = d2;
    if(d3 > largest) largest = d3;
    if(d4 > largest) largest = d4;

    // Finding the largest number
    if(d2 < smallest) smallest = d2;
    if(d3 < smallest) smallest = d3;
    if(d4 < smallest) smallest = d4;

    printf("Largest: %d \n",largest);
    printf("Smallest: %d \n",smallest);

    return 0;
}

int exe5(){

    printf("Enter a date: ");
    int d1,m1,y1;
    scanf("%d/%d/%d",&d1,&m1,&y1);

    printf("Enter another date: ");
    int d2,m2,y2;
    scanf("%d/%d/%d",&d2,&m2,&y2);

    int flag=0; // 0 indicates that 1st date is earliest/ 1 2nd is earliest 

    if(y1==y2){
        if (m1 == m2)
        {
            if (d1 > d2)
            {
                flag = 1; // if d1 > d2 indicates that d2 is earliest
            }

            else if (d1 == d2)
            {
                flag = 2; //the same day
            }
            
        }

        else if (d1 > d2)
        {
            flag = 1;
        }   
    }
    else if (y1 > y2){
        flag = 1;
    }


    switch (flag)
    {
    case 0:
        printf("%2d/%2d/%4d is earlier than %2d/%2d/%4d", d1,m1,y1,d2,m2,y2);
        break;
    
    case 1:
        printf("%2d/%2d/%4d is earlier than %2d/%2d/%4d", d2,m2,y2,d1,m1,y1);
        break;

    case 2:
        printf("Both are the same date");
        break; 

    default:
        break;
    }
    return 0;
}


int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. number of digits \n");
        printf("2. 24 h to 12 h\n");
        printf("3. wind speed \n");
        printf("4. largest / smallest \n");
        printf("5. date earlier \n");
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