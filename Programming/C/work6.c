#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

const int ARRAY_LENGTH = 5;

// Variant 9
int main() {
    // Task 1
    showTaskTitle();

    int *firstArray, bufferArray[ARRAY_LENGTH];
    firstArray = bufferArray;

    readArray(firstArray, ARRAY_LENGTH);
    showArray(firstArray, ARRAY_LENGTH);

    // Task 2
    showTaskTitle();

    int *secondArray = (int *) malloc(sizeof(int) * ARRAY_LENGTH);

    readArray(secondArray, ARRAY_LENGTH);
    showArray(secondArray, ARRAY_LENGTH);

    return 0;
}