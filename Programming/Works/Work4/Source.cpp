#include <stdio.h>

#define LOW -100
#define HIGH 100
#define BIT_POSITION 9

void pause()
{
	printf("\nPlease enter any key to exit... \n");
	getchar();
	getchar();
}

int check_range(int number, int lowest_range, int highest_range)
{
	return (number >= lowest_range) && (number <= highest_range);
}

int get_bit_value(int number, int position)
{
	return (number >> position) & 1;
}

// Variant 9
int main()
{
	// task 1
	int numberInput;
	printf("Enter a number: ");
	scanf_s("%d", &numberInput);
	check_range(numberInput, LOW, HIGH) ? printf("Number is in range\n") : printf("Number is not in range\n");
	
	// task 2
	printf("Enter a number: ");
	scanf_s("%d", &numberInput);
	printf("Value of bit at %d position is %d", BIT_POSITION, get_bit_value(numberInput, BIT_POSITION));

	pause();
	return 0;
}