/* Display the current date and time in three formats */

#include <stdio.h>
#include <time.h>

int main(void){
    time_t current = time(NULL);
    struct tm *ptr;
    char date_time[21];
    int hour;
    char am_or_pm;

    /* Print date and time in default format */
    puts(ctime(&current));

    /* Print date and time, using strftime to format */
    strftime(date_time, sizeof(date_time),
            "%m-%d-%Y  %I:%M%p\n", localtime(&current));
        
    puts(date_time);

    /* Print date and time, using printf to format */
    ptr = localtime(&current);
    hour = ptr->tm_hour;
    if (hour <= 11)
        am_or_pm = 'a';
    else{
        am_or_pm = 'p';
        hour -= 12;
    }
    if (hour == 0)
        hour = 12;
    
    printf("%.2d-%.2d-%.2d %2d:%.2d%cm\n", ptr-> tm_mon + 1,
    ptr->tm_mday, ptr->tm_year + 1900, hour, ptr->tm_min, am_or_pm);

    return 0;
           
    
}