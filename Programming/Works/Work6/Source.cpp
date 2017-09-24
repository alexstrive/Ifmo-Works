#include <stdio.h>
#include <cstdlib>

void pause()
{
	printf("\nPlease enter any key to exit...\n");
	getchar();
	getchar();
}

void print_title(const int task_number)
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

void input_array(const int* arr, const int arr_length)
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
	print_title(1);
	int *arr_a = new int[4];

	input_array(arr_a, 4);
	show_array(arr_a, 4);

	print_new_line();

	// Task 2
	print_title(2);
	int *arr_b = (int*) malloc(sizeof(int) * 4);

	input_array(arr_b, 4);
	show_array(arr_b, 4);

	pause();
	return 0;
}