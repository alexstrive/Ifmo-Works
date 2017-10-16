#include <stdio.h>
#include "utils.h"

const int LOW = -100;
const int HIGH = 100;
const int BIT_POSITION = 9;

int checkRange(int number, int lowestRange, int highestRange) {
    return (number >= lowestRange) && (number <= highestRange);
}

int getBitValue(int number, int position) {
    return (number >> position) & 1;
}

// Variant 9
int main() {
    // Task 1
    showTaskTitle();

    int numberInput;
    printf("Enter a number: ");
    scanf("%d", &numberInput);

    checkRange(numberInput, LOW, HIGH)
    ? printf("Number is in range\n")
    : printf("Number is not in range\n");

    // Task 2
    showTaskTitle();

    printf("Enter a number: ");
    scanf("%d", &numberInput);

    printf("Value of bit at %d position is %d", BIT_POSITION, getBitValue(numberInput, BIT_POSITION));

    return 0;
}