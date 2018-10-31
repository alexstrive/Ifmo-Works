#include <stdio.h>
#include "utils.h"

void inputFloatNumber() {
    float floatNumber;

    printf("Enter a float number: ");
    scanf("%f", &floatNumber);
    printf("You entered: %f \n", floatNumber);
}

void inputIntNumber() {
    int intNumber;

    printf("Enter a int number: ");
    scanf("%i", &intNumber);
    printf("You entered: %i \n", intNumber);
}

int main() {
    // Task 1
    showTaskTitle();

    inputFloatNumber();

    // Task 2
    showTaskTitle();

    inputIntNumber();

    return 0;
}