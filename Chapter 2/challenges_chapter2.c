#include <stdio.h>

#define PI 3.14159265358979323846

int displaychecksym(){
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");
    return 0;
}

// Function to calculate base^power
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double vol_sphere(){

    double radius;

    printf("Enter radius of sphere: ");
    scanf("%lf", &radius);
   
   double r3 = power(radius,3);
   double v = (4.0f/3.0f) * PI * r3;
   printf("Volume of a sphere with radius is %.2lf\n", v);

   return v;
}

float tax_added(){

    float amount;

    printf("Enter dollar-cents amount: ");
    scanf("%f", &amount);

    float tax5 = amount * 1.05f;

    printf("with tax added: $ %.2f\n",tax5);

}

double poly(){

    double x_value;

    printf("Enter x_value: ");
    scanf("%lf", &x_value);

    double x5 = power(x_value,5);
    double x4 = power(x_value,4);
    double x3 = power(x_value,3);
    double x2 = power(x_value,2);

    double result = 3*x5 + 2*x4 -5*x3 - x2 + 7*x_value - 6;
    
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for the value of %.2lf = %.2lf", x_value, result);

    return result;

}

void calculate_change(){
 
    int dollars, cents;
    double amount;

    printf("Enter dollar-cents amount: ");
    scanf("%lf", &amount);

    // Convert the amount to cents to avoid precision issues with floating-point arithmetic
    int total_cents = (int)(amount * 100);

    // Bills
    int bill_100 = total_cents / 10000;
    total_cents %= 10000;

    int bill_50 = total_cents / 5000;
    total_cents %= 5000;

    int bill_20 = total_cents / 2000;
    total_cents %= 2000;

    int bill_10 = total_cents / 1000;
    total_cents %= 1000;

    int bill_5 = total_cents / 500;
    total_cents %= 500;

    // coins
    int coin_2 = total_cents / 200;
    total_cents %= 200;

    int coin_1 = total_cents / 100;
    total_cents %= 100;

    int coin_25 = total_cents / 25;
    total_cents %= 25;

    int coin_10 = total_cents / 10;
    total_cents %= 10;

    int coin_5 = total_cents / 5;
    total_cents %= 5;

    int coin_1cent = total_cents;

    // Mostrar la cantidad de billetes y monedas
    if (bill_100) printf("100 CAD bills: %d\n", bill_100);
    if (bill_50) printf("50 CAD bills: %d\n", bill_50);
    if (bill_20) printf("20 CAD bills: %d\n", bill_20);
    if (bill_10) printf("10 CAD bills: %d\n", bill_10);
    if (bill_5) printf("5 CAD bills: %d\n", bill_5);
    if (coin_2) printf("2 CAD coins: %d\n", coin_2);
    if (coin_1) printf("1 CAD coins: %d\n", coin_1);
    if (coin_25) printf("25 cent coins: %d\n", coin_25);
    if (coin_10) printf("10 cent coins: %d\n", coin_10);
    if (coin_5) printf("5 cent coins: %d\n", coin_5);
    if (coin_1cent) printf("1 cent coins: %d\n", coin_1cent);
}

int loan_payment(){

    // Variable declarations
    double loan_amount;
    double annual_interest_rate;
    double monthly_payment;
    double monthly_interest_rate;
    double balance;
    double interest;

    printf("Enter amount of loan: ");
    scanf("%lf", &loan_amount);
    printf("Enter annual interest rate: ");
    scanf("%lf", &annual_interest_rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &monthly_payment);

    // Convert annual interest rate to a monthly rate
    monthly_interest_rate = annual_interest_rate / 100 / 12;

    // Initialize the balance with the loan amount
    balance = loan_amount;

    // After the first payment
    interest = balance * monthly_interest_rate;
    balance = balance - monthly_payment + interest;
    printf("Balance remaining after first payment: $%.2f\n", balance);

    // After the second payment
    interest = balance * monthly_interest_rate;
    balance = balance - monthly_payment + interest;
    printf("Balance remaining after second payment: $%.2f\n", balance);

    // After the third payment
    interest = balance * monthly_interest_rate;
    balance = balance - monthly_payment + interest;
    printf("Balance remaining after third payment: $%.2f\n", balance);

    return 0;
}

int main(void){

int opcion;

    do {
        // Show Menu
        printf("Select:\n");
        printf("1. Display check symbol \n");
        printf("2. Calculate the sphere volume give the radius\n");
        printf("3. calculate tax 5 to an amount\n");
        printf("4. calcualte the value of a polynomial given X \n");
        printf("5. calculate how to pay an amount in CAD currency \n");
        printf("6. calculate loan payment \n");
        printf("7. Exit \n");
        printf("Enter option (1-7): ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                displaychecksym();
                break;
            
            case 2:
                vol_sphere();
                break;

            case 3:
                tax_added();
                break;

            case 4:
                poly();
                break;

            case 5:
                calculate_change();
                break;
    
            case 6:
                loan_payment();
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