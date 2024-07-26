#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to find the closest integer with a whole number square root
int closestInteger(int num) {
    int closest_lower_root = sqrt(num); // Calculate the closest lower square root
    int closest_higher_root = closest_lower_root + 1; // Calculate the closest higher square root

    // Compare the squared differences and return the closest integer with a whole number square root
    if (abs(num - closest_lower_root * closest_lower_root) <= abs(num - closest_higher_root * closest_higher_root)) {
        return closest_lower_root * closest_lower_root;
    } else {
        return closest_higher_root * closest_higher_root;
    }
}

int main() {
    int input;

    // Loop to prompt user for input until a positive integer is entered
    while (1) {
        printf("Enter a positive integer: ");
        scanf("%d", &input);

        if (input <= 0) {
            printf("Please enter a positive integer.\n");
        } else {
            break;
        }
    }

    // Find and print the closest integer with a whole number square root
    int closest_integer = closestInteger(input);
    printf("The closest integer with a whole number square root to %d is %d.\n", input, closest_integer);

    return 0;
}
