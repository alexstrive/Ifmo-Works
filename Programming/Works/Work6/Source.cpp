#include <stdio.h>
#include <stdlib.h>

void pause()
{
	printf("\nPlease enter any key to exit... \n");
	getchar();
}

void show_array(const int* arr, const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		printf("%i ", *(arr + i));
	}
	printf("\n");
}

// Variant 9
int main()
{
//	int *arr = (int*) malloc(4 * sizeof(int));
//
//	// Task 1
//	show_array(arr, 5);
//
//	free(arr);

	pause();
	return 0;
}