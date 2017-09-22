#include <stdio.h>

const int array_rows = 2;
const int array_cols = 2;

void pause()
{
	printf("\nPlease enter any key to exit... \n");
	getchar();
}

void show_array(const int arr[], const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

void show_matrix(int matrix[2][2])
{
	for (int i = 0; i < array_rows; i++ )
	{
		show_array(matrix[i], array_cols);
	}
}

void production(int matrix_a[2][2], int matrix_b[2][2], int matrix_out[2][2])
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			for (int g = 0; g < 2; g++)
			{
				matrix_out[row][col] += matrix_a[row][g] * matrix_b[g][col];
			}
		}
	}
}

// Variant 9
int main()
{
	// Task 1
	int arr[7] = {123, 123, 123, 123, 456, 321, 1};
	const int array_length = sizeof(arr) / sizeof(int);
	printf("Defined array: ");
	show_array(arr, array_length);

	// Task 2
	int matrix_a[2][2] = {
		{1, 2},
		{3, 4}
	};

	int matrix_b[2][2] = {
		{1, 0},
		{0, 2}
	};

	int matrix_c[2][2] = {
		{0, 0},
		{0, 0}
	};
	production(matrix_a, matrix_b, matrix_c);
	printf("\nProducted matrix: \n");
	show_matrix(matrix_c);

	pause();

	return 0;
}
