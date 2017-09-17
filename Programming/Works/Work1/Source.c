#include <stdio.h>

void input_float_number()
{
	float float_number;

	printf("Enter a float number: ");
	scanf("%f", &float_number);
	printf("You entered: %f \n", float_number);
}

void input_int_number()
{
	int int_number;

	printf("Enter a int number: ");
	scanf("%i", &int_number);
	printf("You entered: %i \n", int_number);
}

void pause()
{
	printf("Pause");
	getchar();
	getchar();
}

int main()
{
	input_float_number();
	input_int_number();

	pause();

	return 0;
}