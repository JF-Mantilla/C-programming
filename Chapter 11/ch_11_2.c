#include <stdio.h>
#include <stdlib.h>

int convert_to_minutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    // Flight departure times in minutes since midnight
    int dep_times[] = {480, 583, 679, 767, 840, 945, 1140, 1305}; // 8:00, 9:43, 11:19, 12:47, 2:00, 3:45, 7:00, 9:45
    int arr_times[] = {616, 712, 811, 900, 968, 1075, 1180, 1438}; // Corresponding arrival times

    int closest_flight = 0;
    int min_diff = abs(desired_time - dep_times[0]);

    // Find the closest departure time
    for (int i = 1; i < 8; i++) {
        int diff = abs(desired_time - dep_times[i]);
        if (diff < min_diff) {
            min_diff = diff;
            closest_flight = i;
        }
    }

    // Store the closest departure and arrival times
    *departure_time = dep_times[closest_flight];
    *arrival_time = arr_times[closest_flight];
}

int main() {
    int hours, minutes;
    int desired_time, departure_time, arrival_time;

    // Input from user
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    // Convert input time to minutes since midnight
    desired_time = convert_to_minutes(hours, minutes);

    // Find the closest flight
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    // Output the closest flight details
    printf("Closest departure time is %d:%02d, arriving at %d:%02d.\n",
           departure_time / 60, departure_time % 60,
           arrival_time / 60, arrival_time % 60);

    return 0;
}
