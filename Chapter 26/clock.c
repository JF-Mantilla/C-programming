#include <stdio.h>
#include <time.h>

int main(void){

    clock_t start_clock = clock();

    // Some processing here
    for (int i = 0; i < 99999999; i++); // Example loop for delay

    clock_t end_clock = clock();
    double time_spent = (double)(end_clock - start_clock) / CLOCKS_PER_SEC;

    printf("Processor time used: %g sec.\n", time_spent);

    return 0;
}
