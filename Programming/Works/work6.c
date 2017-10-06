#include <stdio.h>
#include <stdlib.h>

const int arrayLength = 5;

void showTitle(const int task_number) {
    printf("--- Task %d ---\n", task_number);
}

void printNewLine() {
    printf("\n");
}

void showArray(const int *arr, const int arr_length) {
    printf("Array values: ");

    for (int i = 0; i < arr_length; ++i) {
        printf("%d ", *(arr + i));
    }

    printf("\n");
}

void readArray(int *array, const int arr_length) {
    printf("Enter array values: ");

    for (int i = 0; i < arr_length; ++i) {
        scanf("%d", array + i);
    }
}

// Variant 9
int main()
{
    // Task 1
    showTitle(1);
    int *arrayFirst[arrayLength];

    readArray(arrayFirst, arrayLength);
    showArray(arrayFirst, arrayLength);

    printNewLine();

    // Task 2
    showTitle(2);
    int *arraySecond = (int*) malloc(sizeof(int) * arrayLength);

    readArray(arraySecond, arrayLength);
    showArray(arraySecond, arrayLength);

    return 0;
}