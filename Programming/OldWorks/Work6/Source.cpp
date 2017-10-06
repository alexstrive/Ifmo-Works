#include <stdio.h>
#include <cstdlib>

#define ARRAY_LENGTH 5

void pause()
{
	printf("\nPlease enter any key to exit...\n");
	getchar();
	getchar();
}

void show_title(const int task_number)
{
	printf("--- Task %d ---\n", task_number);
}

void print_new_line()
{
	printf("\n");
}

void show_array(const int* arr, const int arr_length)
{
	printf("Array values: ");
	for (int i = 0; i < arr_length; ++i)
	{
		printf("%i ", *(arr + i));
	}
	printf("\n");
}

void read_array(const int* arr, const int arr_length)
{
	printf("Enter array values: ");
	for (int i = 0; i < arr_length; ++i)
	{
		scanf("%d", &arr[i]);
	}
}

// Variant 9
int main()
{
	// Task 1
	show_title(1);
	int *array_first = new int[ARRAY_LENGTH];

	read_array(array_first, ARRAY_LENGTH);
	show_array(array_first, ARRAY_LENGTH);

	print_new_line();

	// Task 2
	show_title(2);
	int *array_second = (int*) malloc(sizeof(int) * ARRAY_LENGTH);

	read_array(array_second, ARRAY_LENGTH);
	show_array(array_second, ARRAY_LENGTH);

	pause();
	return 0;
}