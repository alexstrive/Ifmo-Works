/**
 * Util functions for make work more easier
 */

#ifndef WORKS_UTILS_H
#define WORKS_UTILS_H

/**
 * Number of current task.
 * Do not use it besides this file!
 */
int _taskNumber = 1;


/**
 * Show default task title.
 * Task number changes automatically.
 */
void showTaskTitle() {
    printf("--- Task %d ---\n", _taskNumber++);
}

/**
 * Print all elements of array through whitespace.
 *
 * @param array
 * @param arrayLength
 */
void showArray(const int *array, const int arrayLength) {
    printf("Array values: ");

    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

/**
 * Read elements of array.
 *
 * @param array
 * @param arrayLength
 */
void readArray(int *array, const int arrayLength) {
    printf("Enter array values: ");

    for (int i = 0; i < arrayLength; ++i) {
        scanf("%d", array + i);
    }
}

#endif //WORKS_UTILS_H
