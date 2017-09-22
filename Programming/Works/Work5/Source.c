
#include <stdio.h>

#define ARRAY_LENGTH 7
#define MATRIX_ROW_COL 2

int arr[ARRAY_LENGTH] = { 123, 123, 123, 123, 456, 321, 1};

int matrixFirst[MATRIX_ROW_COL][MATRIX_ROW_COL] = {
	{1, 2},
	{3, 4}
};

int matrixSecond[MATRIX_ROW_COL][MATRIX_ROW_COL] = {
	{1, 0},
	{0, 1}
};

void display_array(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf_s("%d ", arr[i]);
	}
}

int* production_matrix(int matrixFirst[], int matrixSecond[])
{
	int matrixResult[MATRIX_ROW_COL][MATRIX_ROW_COL];

	for (int i = 0; i < MATRIX_ROW_COL; ++i)
	{
		for (int j = 0; j < MATRIX_ROW_COL; ++j)
		{
			matrixResult[i][j] = 0;
		}
	}

	return matrixResult;
}

void pause()
{
	printf("\nPlease enter any key to exit... \n");
	getchar();
	getchar();
}

int main()
{
	// task 1
	display_array(arr, ARRAY_LENGTH);

	// task 2
	production_matrix(matrixFirst, matrixSecond);
	
	pause();
	return 0;
}