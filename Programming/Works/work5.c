#include <stdio.h>

// Predefined number of rows and columns
const int rows = 2;
const int cols = 2;

void showArray(const int array[], const int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void showMatrix(int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++ )
    {
        showArray(matrix[i], cols);
    }
    printf("\n");
}

/**
 * Calculate product of two matrix rows x cols
 */
void matrixProduct(int matrixLeft[rows][cols], int matrixRight[rows][cols], int matrixOut[rows][cols])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            for (int i = 0; i < 2; i++)
            {
                matrixOut[row][col] += matrixLeft[row][i] * matrixRight[i][col];
            }
        }
    }
}

// Variant 9
int main()
{
    // Task 1
    int array[7] = {123, 123, 123, 123, 456, 321, 1};
    const int arrayLength = sizeof(array) / sizeof(int);
    printf("Defined array: ");
    showArray(array, arrayLength);

    // Task 2
    int matrixA[rows][cols] = {
            {1, 2},
            {3, 4}
    };

    int matrixB[rows][cols] = {
            {1, 0},
            {0, 2}
    };

    int matrixC[rows][cols] = {
            {0, 0},
            {0, 0}
    };

    matrixProduct(matrixA, matrixB, matrixC);
    printf("\nProducted matrix: \n");
    showMatrix(matrixC);

    return 0;
}